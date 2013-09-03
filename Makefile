# --------------------------------------------------------------------------
#    DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
#    
#    File: Makefile
#    Version: 1.0.0
#    Copyright: (C) 2013 by Enzo Roberto Verlato
#    Contact: enzover@ig.com.br
#    All rights reserved.
#    
# --------------------------------------------------------------------------
#    This file is part of the BelloSGML Project.
#    
#    This file may be used under the terms of the GNU General Public
#    License version 2.0 as published by the Free Software Foundation
#    and appearing in the file LICENSE.GPL2 included in the packaging of
#    this file.
#    
#    This file is provided "AS IS" in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY OF ANY KIND, INCLUDING THE WARRANTIES OF DESIGN;
#    without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
#    PARTICULAR PURPOSE. See the GNU General Public License for more details.
#    
#    You should have received a copy of the GNU General Public License
#    along with this program; if not, write to the Free Software Foundation,
#    Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
# --------------------------------------------------------------------------

CXX = g++
APPPATH = app
OBJS = build/obj/
BIN  = build/bin/
INCLUDES = -Iinclude
LOCALLIB =
LIB = 

RES = rc
#OPTFLAGS = -Os
OPTFLAGS = -O3
CFLAGS = $(INCLUDES) ${OPTFLAGS} -Wall -pedantic-errors
OSTYPE = $(shell gcc -dumpmachine)
EXEC = myapp.exe

ifneq (,$(findstring $(firstword $(subst -, ,$(shell gcc -dumpmachine))),mingw32 i686 i586 i386))
    BITS = -m32
else 
    BITS = -m64
endif

ifneq (,$(findstring mingw,$(OSTYPE)))
    OSTYPE = Windows
    LIB := ${LIB} -L'C:\Users\xxx\My things\public\boost_1_54_0\stage\lib' -lboost_regex-mgw47-mt-1_54
    INCLUDES := ${INCLUDES} -I'C:\Users\xxx\My things\public\boost_1_54_0'
else
    ifneq (,$(findstring linux,$(OSTYPE)))
        OSTYPE = Linux
    else
        ifneq (,$(findstring freebsd,$(OSTYPE)))
            OSTYPE = FreeBSD
            LIB := ${LIB} -L'/usr/home/enzo/boost_1_54_0/stage/lib' -lboost_regex
            INCLUDES := ${INCLUDES} -I'/usr/home/enzo/boost_1_54_0'
        else
            ifneq (,$(findstring solaris,$(OSTYPE)))
                OSTYPE = Solaris
            else
                ifneq (,$(findstring darwin,$(OSTYPE)))
                    OSTYPE = MacOSX
                else
                    $(error Operating System not found)
                endif
            endif
        endif
    endif
endif

vpath % app:src

define compile
    @echo $(subst _$(OSTYPE),,$1)
    @$(CXX) $^ -c -o $(OBJS)$@.o $(CFLAGS)
endef

all: clean main Sgml
	@echo Linking...
	@$(CXX) -o $(BIN)$(EXEC) $(OBJS)* $(LIB) $(CFLAGS)
	@strip $(BIN)$(EXEC)

main: main.cpp
	@echo Compiling on $(OSTYPE) $(subst -m,,$(BITS))BIT...
	$(call compile,$@)

Sgml: Sgml.cpp
	$(call compile,$@)

.PHONY: clean
clean:
	@echo Cleaning...
	@rm -f $(BIN)*.exe
	@rm -f $(OBJS)*.o