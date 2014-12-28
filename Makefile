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
OSTYPE = $(shell gcc -dumpmachine)
APP_DIR = app
EXTLIBRARY_DIR = ext/lib/${OSTYPE}/
OBJECT_DIR = build/${OSTYPE}/obj/
LIBRARY_DIR = build/${OSTYPE}/lib/
BINARY_DIR  = build/${OSTYPE}/bin/
INCLUDE_DIR = -Iinclude -Iext/include
# OPTFLAGS = -Os
OPTFLAGS = -O1
CFLAGS = $(INCLUDE_DIR) ${OPTFLAGS} -Wall -pedantic-errors -std=c++98 $(BITS)
LIBNAME = environs.a
EXEC = bellosgml.exe


ifneq (,$(findstring $(firstword $(subst -, ,$(shell gcc -dumpmachine))),mingw32 i686 i586 i386))
    BITS = -m32
else 
    BITS = -m64
endif

ifneq (,$(findstring mingw,$(OSTYPE)))
    OSTYPE = windows
    CFLAGS := ${CFLAGS} -static
else
    ifneq (,$(findstring linux,$(OSTYPE)))
        OSTYPE = linux
    else
        ifneq (,$(findstring freebsd,$(OSTYPE)))
            OSTYPE = freebsd
        else
            ifneq (,$(findstring pc-solaris,$(OSTYPE)))
                OSTYPE = openindiana
                #LIB = -R/usr/local/lib:/usr/lib/64:/usr/local/lib/sparcv9
            else
                ifneq (,$(findstring solaris,$(OSTYPE)))
                    OSTYPE = solaris
                else
                    ifneq (,$(findstring haiku,$(OSTYPE)))
                        OSTYPE = haiku
                        CFLAGS := ${CFLAGS} -lbe -lbsd
                    else
                        ifneq (,$(findstring darwin,$(OSTYPE)))
                            OSTYPE = macos
                        else
                            $(error Operating System not found)
                        endif
                    endif
                endif
            endif
        endif
    endif
endif

vpath % app:src:src/$(OSTYPE)

define compile
    @echo $(subst _$(OSTYPE),,$1)
    @$(CXX) $^ -c -o $(OBJECT_DIR)$@.o $(CFLAGS)
endef

all: clean main Parser
	@echo Linking...
	@$(CXX) -o $(BINARY_DIR)$(EXEC) $(OBJECT_DIR)* $(EXTLIBRARY_DIR)* $(CFLAGS)
	@strip $(BINARY_DIR)$(EXEC)

main: main.cpp
	@echo Compiling on $(OSTYPE) $(subst -m,,$(BITS))BIT...
	$(call compile,$@)

Parser: Parser.cpp
	$(call compile,$@)

.PHONY: clean

clean:
	@echo Cleaning...
	@rm -f $(BINARY_DIR)*.exe
	@rm -f $(OBJECT_DIR)*.o
	@rm -f $(LIBRARY_DIR)*.a