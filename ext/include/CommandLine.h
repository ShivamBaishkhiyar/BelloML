/*--------------------------------------------------------------------------
    DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
     
    File: CommandLine.h
    Version: 2.0.0
    Copyright: (C) 2012 by Enzo Roberto Verlato
    Contact: enzover@ig.com.br
    All rights reserved.
    
----------------------------------------------------------------------------
    This file is part of the CommandLine Class.
    
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

#ifndef COMMANDLINE_H
#define COMMANDLINE_H

#include <string>

namespace environs {
    
    using std::string;
    
    class CommandLine {
        
        public:
            CommandLine();
            
            const string getCommandLine() const;
            
            const string getApplicationName() const;
            const string getApplicationPath() const;
            const string getApplicationFullPath() const;
            
            const string getCurrentWorkingDirectory() const;
            
            const bool hasParameters() const;
            const bool hasParameter( const unsigned &position ) const;
            
            const int getParametersNumber() const;
            const string getAllParameters() const;
            const string getParameter( const unsigned &position ) const;
            const int getParameterAsInteger( const unsigned &position ) const;
            const double getParameterAsFloat( const unsigned &position ) const;
            
            void gotoFirstParameter();
            const bool gotoNextParameter();
            const int getCurrentPosition() const;
            
            const string getCurrentParameter() const;
            const int getCurrentParameterAsInteger() const;
            const double getCurrentParameterAsFloat() const;
            
            const string getFirstParameter() const;
            const int getFirstParameterAsInteger() const;
            const double getFirstParameterAsFloat() const;
            
            const string getLastParameter() const;
            const int getLastParameterAsInteger() const;
            const double getLastParameterAsFloat() const;
            
            void setOptionPrefix( const string &optionPrefix );
            void setOptionPostfix( const string &optionPostfix );
            
            const string getOptionPrefix() const;
            const string getOptionPostfix() const;
            
            const bool hasOption( const string &option ) const;
            
            const string getOptionValue( const string &option ) const;
            const int getOptionValueAsInteger( const string &option ) const;
            const double getOptionValueAsFloat( const string &option ) const;
            const string getOptionLongValue( const string &option ) const;
            
            void optionCaseSensitive();
            void optionCaseInsensitive();
            const bool isOptionCaseSensitive() const;
    };
}

#endif
