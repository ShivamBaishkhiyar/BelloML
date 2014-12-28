/*--------------------------------------------------------------------------
    DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
    
    File: main.cpp
    Version: 1.0.0
    Copyright: (C) 2013 by Enzo Roberto Verlato
    Contact: enzover@ig.com.br
    All rights reserved.
    
----------------------------------------------------------------------------
    This file is part of the BelloSGML project.
    
    This file may be used under the terms of the GNU General Public
    License version 2.0 as published by the Free Software Foundation
    and appearing in the file LICENSE.GPL2 included in the packaging of
    this file.
    
    This file is provided "AS IS" in the hope that it will be useful,
    but WITHOUT ANY WARRANTY OF ANY KIND, INCLUDING THE WARRANTIES OF DESIGN;
    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
    PARTICULAR PURPOSE. See the GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software Foundation,
    Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
--------------------------------------------------------------------------*/

#include <Parser.h>
#include <charseq.h>

#include <fstream>
#include <vector>
#include <string>
#include <iterator>

#include <iostream>
#include <sstream>


#include <sstream>
#include <algorithm>

using namespace util;

namespace {
    using std::vector;
    using std::ifstream;
    using std::ofstream;
    using std::istream_iterator;
    using std::ostream_iterator;
    
    using namespace util;
    
    vector<string> line;
    string indentSymbol( "\t" );
    
    const string sortAttribute( string startTag ) {
        if ( ( startTag.find( "<?" ) != string::npos || startTag.find( "<!" ) != string::npos ) ) {
            return startTag;
        }
        
        unsigned counter = 3;
        char lastChar = '\0';
        string buffer;
        vector<string> tag;
        
        for ( unsigned index = 0; index < startTag.length(); ++index ) {
            
            switch ( startTag.at( index ) ) {
                case ' ':
                    if ( counter == 3 ) {
                        counter = 0;
                        lastChar = '\0';
                        trim( buffer );
                        tag.push_back( buffer );
                        buffer.clear();
                    }
                    break;
                
                case '=':
                    ++counter;
                    break;
                
                case '"':
                case '\'':
                    if ( lastChar == '\0' || lastChar == startTag.at( index ) ) {
                        ++counter;
                        lastChar = startTag.at( index );
                    }
                    break;
            }
            buffer += startTag.at( index );
        }
        
        trim( buffer );
        tag.push_back( buffer );
        string start = tag.front() + " ";
        tag.erase( tag.begin() );
        if ( !tag.empty() ) {
            if ( tag.back().find( "/>" ) != string::npos ) {
                tag.back() = tag.back().substr( 0, tag.back().size() - 2 );
            } else {
                tag.back() = tag.back().substr( 0, tag.back().size() - 1 );
            }
        }
        sort( tag.begin(), tag.end() );
        
        for( std::vector<string>::iterator it = tag.begin(); it != tag.end(); ++it ) {
            start += *it + " ";
        }
        
        trim( start );
        if ( startTag.find( "/>" ) != string::npos && start.find( "/>" ) == string::npos ) {
            start += "/>";
        } else if ( start.find( ">" ) == string::npos ) {
            start += ">";
        }
        return start;
    }
    
    const bool isGreaterthansignAtEOL( string &line ) {
        static string buffer;
        if ( !line.empty() ) {
            if ( *line.rbegin() != '>' ) {
                buffer.append( " " + line );
            } else {
                line = buffer.append( " " + line );
                buffer.clear();
                return true;
            }
        }
        return false;
    }
    
    const string parsingLine( string &line ) {
        string text;
        size_t spos, epos, pos;
        
        spos = line.find( "<" );
        epos = line.find( ">" );
        pos = line.size();
        
        if ( spos != string::npos ) {
            if ( spos == 0 ) {
                if ( epos != string::npos ) {
                    pos = epos + 1;
                }
            } else {
                pos = spos;
            }
        }
        text = line.substr( 0, pos );
        line.erase( 0, pos );
        return text;
    }
    
    string operator*( const string& text, unsigned int repeat ) {
        std::stringstream out;
        while ( repeat-- ) {
            out << text;
        }
        return out.str();
    }
}

Parser::Parser() {
    
}

void Parser::load( const string &filename ) const {
    try {
        string line;
        string buffer;
        ifstream file;
        file.exceptions( ifstream::failbit | ifstream::badbit );
        file.open( filename.c_str() );
        
        while( !file.eof() && getline( file, line ) ) {
            trim( line );
            if ( isGreaterthansignAtEOL( line ) ) {
                string text;
                while ( !line.empty() ) {
                    text = parsingLine( line );
                    trim( text );
                    if ( !text.empty() ) {
                        
                        // concatenate text (pcdata) into a single line.
                        if ( text.find( "<" ) == string::npos && text.find( ">" ) == string::npos && !::line.empty() && ::line.back().find( "<" ) == string::npos && ::line.back().find( ">" ) == string::npos ) {
                            ::line.back() += " " + text;
                        } else {
                            
                            // wrap all text (pcdata) to 80 columns.
                            if ( !::line.empty() && ::line.back().find( "<" ) == string::npos && ::line.back().find( ">" ) == string::npos ) {
                                vector<string> buffer = wrapText( ::line.back(), 80 );
                                ::line.pop_back();
                                ::line.insert( ::line.end(), buffer.begin(), buffer.end() );
                            } else if ( !::line.empty() && ::line.back().find( "<" ) != string::npos && ::line.back().find( "</" ) == string::npos ) {
                                ::line.back() = sortAttribute( ::line.back() );  // Sort here? 
                            }
                            ::line.push_back( text );
                        }
                    }
                    
                }
            }
        }
        file.close();
    } catch( ifstream::failure e ) {
        throw string( "Input file could not be read." );
    }
}

void Parser::saveAs( const string &filename ) const {
    try {
        ofstream file;
        file.exceptions ( ifstream::failbit | ifstream::badbit );
        file.open( filename.c_str() );
        ostream_iterator<string> output_iterator( file, "\n" );
        copy( line.begin(), line.end() - 1, output_iterator );
        file << line.back();
        file.close();
    } catch ( ofstream::failure e ) {
        throw string( "Output file could not be write." );
    }
}

void Parser::indent() const {
    int indentNumber = 0;
    vector<string> endTags;
    string buffer;
    
    for ( int index = line.size() - 1; index >= 0; --index ) {
        if ( line.at( index ).find( "</" ) != string::npos ) {
            line.at( index ) = string( indentSymbol ) * indentNumber++ + line.at( index );
            buffer = line.at( index );
            trim( buffer );
            endTags.push_back( buffer.substr( 2, buffer.size() - 3 ));
        } else {
            if( line.at( index ).find( "<" + endTags.back() ) != string::npos && line.at( index ).find( "/>" ) == string::npos ) {
                line.at( index ) = string( indentSymbol ) * --indentNumber + line.at( index );
                if( endTags.size() > 1 )
                endTags.pop_back();
            } else {
                line.at( index ) = string( indentSymbol ) * indentNumber + line.at( index );
            }
        }
    }
}

void Parser::setTab( const signed int &width ) const {
    if ( width > 0 ) {
        indentSymbol = string( " " ) * ( width > 8 ? 8 : width );
    }
}