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

#include <boost/regex.hpp>

using std::cout;
using std::endl;
using std::ifstream;

namespace {
    string content;
    
    void removeLinebreaks() {
        // Unix \n - Windows \r\n - MacOSX \r
        string newtext = "";
        boost::regex expression("\n|\r\n|\r");
        content = boost::regex_replace( content, expression, newtext );
    }
}

void Sgml::read( const string &filename ) {
    ifstream file( filename.c_str() );
    content.append( ( std::istreambuf_iterator<char>( file ) ), std::istreambuf_iterator<char>() );
}

void Sgml::beautify() {
    removeLinebreaks();
}







