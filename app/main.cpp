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

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <vector>

#include <iterator>

using namespace std;

vector<string> line;

const string trim( string text ) {
    static const char whitespace[] = " \n\t\v\r\f";
    text.erase( 0, text.find_first_not_of( whitespace ) );
    return text.erase( text.find_last_not_of( whitespace ) + 1U );
}

const vector<string> wrapText( string text, const size_t &width ) {
    vector<string> lines;
    string::size_type spacePos;
    
    while ( !text.empty() ) {
        spacePos = text.rfind( ' ', width );
        
        if ( spacePos == string::npos || text.size() <= width ) {
            lines.push_back( text );
            break;
        } else {
            lines.push_back( text.substr( 0, spacePos + 1 ) );
            text.erase( 0, spacePos + 1 );
        }
    }
    return lines;
}

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
                    tag.push_back( trim( buffer ) );
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
    
    tag.push_back( trim( buffer ) );
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
    
    for(std::vector<string>::iterator it = tag.begin(); it != tag.end(); ++it) {
        start += *it + " ";
    }

    if ( startTag.find( "/>" ) != string::npos && start.find( "/>" ) == string::npos ) {
        start = trim( start ) + "/>";
    } else if ( start.find( ">" ) == string::npos ) {
        start = trim( start ) + ">";
    }
    return trim( start );
}

void load( const string &filename ) {
    ifstream file;
    string fileline;
    
    file.open( filename.c_str() );
    if ( file ) {
        while( getline( file, fileline ) ) {
            string text;
            
            size_t startpos;
            size_t endpos;
            size_t pos;
            
            while ( !fileline.empty() ) {
                startpos = fileline.find( "<" );
                endpos = fileline.find( ">" );
                pos = fileline.size();
                
                if ( startpos != string::npos ) {
                    if ( startpos == 0 ) {
                        if ( endpos != string::npos ) {
                            pos = endpos + 1;
                        }
                    } else {
                        pos = startpos;
                    }
                }
                
                text = trim( fileline.substr( 0, pos ) );
                fileline.erase( 0, pos );
                if ( !text.empty() ) {
                    
                    // concatenate text (pcdata) into a single line.
                    if ( text.find( "<" ) == string::npos && text.find( ">" ) == string::npos && !line.empty() && line.back().find( "<" ) == string::npos && line.back().find( ">" ) == string::npos ) {
                        line.back() += " " + text;
                    } else {
                        
                        // wrap all text (pcdata) to 80 columns.
                        if ( !line.empty() && line.back().find( "<" ) == string::npos && line.back().find( ">" ) == string::npos ) {
                            vector<string> buffer = wrapText( line.back(), 80 );
                            line.pop_back();
                            line.insert( line.end(), buffer.begin(), buffer.end() );
                        } else if ( !line.empty() && line.back().find( "<" ) != string::npos && line.back().find( "</" ) == string::npos ) {
                            line.back() = sortAttribute( line.back() );  // Sort here? 
                        }
                        
                        line.push_back( text );
                    }
                }
                
            }
        }
        file.close();
    }
}

void saveAs( const string &filename ) {
    ofstream file( filename.c_str() );
    ostream_iterator<string> output_iterator( file, "\n" );
    copy( line.begin(), line.end() - 1, output_iterator );
    file << line.back();
    file.close();
}

void indentSgml() {
    int indentNumber = 0;
    vector<string> endTags;
    
    for ( int index = line.size() - 1; index >= 0; --index ) {
        if ( line.at( index ).find( "</" ) != string::npos ) {
            line.at( index ) = string( indentNumber++, '\t' ) + line.at( index );
            endTags.push_back( line.at( index ).substr( 1 + indentNumber, line.at( index ).size() - indentNumber - 2 ) );
        } else {
            if( line.at( index ).find( "<" + endTags.back() ) != string::npos ) {
                line.at( index ) = string( --indentNumber, '\t' ) + line.at( index );
                if( endTags.size() > 1 )
                endTags.pop_back();
            } else {
                line.at( index ) = string( indentNumber, '\t' ) + line.at( index );
            }
        }
    }
}

int main( int argc, char* argv[] ) {
    load( argv[1] );
    indentSgml();
    saveAs( argv[2] );
}

// g++ main.cpp -o bellosgml.exe -Os -static
// strip bellosgml.exe
