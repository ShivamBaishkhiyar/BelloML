![BelloSGML](https://rawgit.com/FreeSource/BelloSGML/master/test/bellosgml.svg)
---------
_BelloSGML_: A beautifier for SGML, XML and HTML.

#### OPERATING SYSTEM SUPPORT

- [Windows](https://github.com/FreeSource/BelloSGML/blob/master/build/windows/bin/bellosgml.exe?raw=true)
- [Linux](https://github.com/FreeSource/BelloSGML/blob/master/build/linux/bin/bellosgml.exe?raw=true)
- [FreeBSD](https://github.com/FreeSource/BelloSGML/blob/master/build/freebsd/bin/bellosgml.exe?raw=true)
- [MacOS](https://github.com/FreeSource/BelloSGML/blob/master/build/macos/bin/bellosgml.exe?raw=true)
- [Solaris](https://github.com/FreeSource/BelloSGML/blob/master/build/solaris/bin/bellosgml.exe?raw=true)
- [OpenIndiana](https://github.com/FreeSource/BelloSGML/blob/master/build/openindiana/bin/bellosgml.exe?raw=true)

#### SYNOPSIS
bellosgml.exe [options]

#### DESCRIPTION
A simple XML beautifier, that helps you making XML files easier read by human beings.

#### OPTIONS

__--in__ Specify a file to be beautifier.

__--out__ Specify a file to be written.

__--overwrite__ Overwrites the current XML input file.

__--spaces__ Specify the indentation level with number of spaces (default indent is tab).

__--guides__ Specify pipe char (vertical bar) to be guide lines used with simple editor.

#### EXAMPLES

````
bellosgml.exe --in myfile.xml --out mynewfile.xml
bellosgml.exe --in myfile.xml --overwrite
bellosgml.exe --in myfile.xml --out mynewfile.xml --spaces 4
bellosgml.exe --in myfile.xml --out mynewfile.xml --spaces 4 --guides
bellosgml.exe --spaces 4 --out mynewfile.xml --guides --in myfile.xml
````

#### VERSION

This document was last revised for BelloSGML version 1.00.  

#### AUTHOR
Enzo Roberto Verlato <enzover@ig.com.br> is the principal author of BelloSGML.