/*--------------------------------------------------------------------------
    DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
    
    File: Sgml.cpp
    Version: 1.0.0
    Copyright: (C) 2013 by Enzo Roberto Verlato
    Contact: enzover@ig.com.br
    All rights reserved.
    
----------------------------------------------------------------------------
    This file is part of the Sgml Class.
    
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

#include <Sgml.h>

#include <iostream>
#include <fstream>
#include <streambuf>
#include <vector>
#include <stdexcept>

#include <boost/regex.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/algorithm/string.hpp>

namespace {
    using namespace std;
    using namespace boost;
    
    string filename;
    string content;
    vector<string> lines;
    
    void removeLinebreaks();
    void replaceAnyNumberSpacesWithSingleSpace();
    void replaceAllTabsWithSingleSpace();
    const vector<string> wrapText( string text, const size_t &width );
    const string getComment();
    const string getElement();
    const string getText();
    void sgmlNormalize();
    void indentSgml();
    void beautify();
    
    
    void removeLinebreaks() {
        // Unix \n - Windows \r\n - MacOSX \r
        string newtext = "";
        regex expression("\n|\r\n|\r");
        content = regex_replace( content, expression, newtext );
    }
    
    void replaceAnyNumberSpacesWithSingleSpace() {
        using namespace lambda;
        string buffer;
        unique_copy( content.begin(), content.end(), back_inserter( buffer ), _1 == ' ' && _2 == ' ' );
        content = buffer;
    }
    
    void replaceAllTabsWithSingleSpace() {
        replace_all( content, "\t", " " );
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
    
    const string getComment() {
        size_t endPos = content.rfind( "-->" );
        if ( endPos == content.size() - 3 ) {
            size_t startPos = content.rfind( "<!--" );
            if ( startPos != string::npos ) {
                string buffer = content.substr( startPos, content.size() );
                content.erase( startPos, content.size() );
                return buffer;
            } else {
                throw runtime_error( "Error: bad formed XML file1." );
            }
        }
        return "";
    }
    
    const string getElement() {
        size_t endPos = content.find_last_of( ">" );
        if ( endPos == content.size() - 1 ) {
            size_t startPos = content.find_last_of( "<" );
            // cout << content.substr( startPos, content.size() ) << endl;
            if ( startPos != string::npos ) {
                string buffer = content.substr( startPos, content.size() );
                content.erase( startPos, content.size() );
                return buffer;
            } else {
                throw runtime_error( "Error: bad formed XML file2." );
            }
        }
        return "";
    }
    
    const string getText() {
        size_t startPos = content.find_last_of( ">" );
        if ( startPos < content.size() - 1 ) {
            string buffer = content.substr( startPos + 1, content.size() );
            trim( buffer );
            content.erase( startPos + 1, content.size() );
            return buffer;
        }
        return "";
    }
    
    void sgmlNormalize() {
        string buffer;
        vector<string> vctText;
        
        while ( !content.empty() ) {
            cout << content.size() << endl;
            trim( content );
            vctText.clear();
            
            buffer = getComment();
            if ( !buffer.empty() ) {
                vctText = wrapText( buffer, 80 );
                lines.insert( lines.begin(), vctText.begin(), vctText.end() );
            } else {
                buffer = getElement();
                if ( !buffer.empty() ) {
                    lines.insert( lines.begin(), buffer );
                } else {
                    buffer = getText();
                    vctText = wrapText( buffer, 80 );
                    lines.insert( lines.begin(), vctText.begin(), vctText.end() );
                }
            }
        }
    }

    void indentSgml() {
        int indentNumber = 0;
        vector<string> endTags;
        
        const string pattern = "</(.*)>";
        regex regexPattern( pattern, regex::extended );
        smatch what;
        
        for ( int index = lines.size() - 1; index >= 0; --index ) {
            if ( regex_match( lines.at( index ), what, regexPattern ) ) {
                lines.at( index ) = string( indentNumber++, '\t' ) + lines.at( index );
                endTags.push_back( what[1] );
            } else {
                if( lines.at( index ).find( "<" + endTags.back() ) != string::npos ) {
                    lines.at( index ) = string( --indentNumber, '\t' ) + lines.at( index );
                    if( endTags.size() > 1 )
                    endTags.pop_back();
                } else {
                    lines.at( index ) = string( indentNumber, '\t' ) + lines.at( index );
                }
            }
        }
    }
    
    void beautify() {
        removeLinebreaks();
        replaceAllTabsWithSingleSpace();
        replaceAnyNumberSpacesWithSingleSpace();
        sgmlNormalize();
        indentSgml();
    }
}

void Sgml::load( const string &filename ) {
    ifstream file( filename.c_str() );
    content.append( ( istreambuf_iterator<char>( file ) ), istreambuf_iterator<char>() );
    ::filename = filename;
    file.close();
    beautify();
}

void Sgml::save() {
    saveAs( filename.c_str() );
}

void Sgml::saveAs( const string &filename ) {
    ofstream file( filename.c_str() );
    ostream_iterator<string> output_iterator( file, "\n" );
    copy( lines.begin(), lines.end() - 1, output_iterator );
    file << lines.back();
    file.close();
}

//~ void Sgml::beautify() const {
    //~ removeLinebreaks();
    //~ replaceAllTabsWithSingleSpace();
    //~ replaceAnyNumberSpacesWithSingleSpace();
    //~ sgmlNormalize();
    //~ indentSgml();
    
    
    
    
    
    
    
    
    //~ string line("test\ttest2\ttest3");
    //~ vector<string> strs;
    //~ split( strs, content, is_any_of( " " ) );
    
    //~ for( unsigned i = 0; i < strs.size(); ++i ) {
        //~ cout << strs[i] << endl;
    //~ }
    
    // cout << content;
//~ }







