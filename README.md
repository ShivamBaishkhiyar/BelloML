![BelloSGML](https://rawgit.com/FreeSource/BelloSGML/master/test/bellosgml.jpg)
---------

#### DESCRIPTION
A simple markup language beautifier, that helps you making SGML, XML or HTML files easier read by human beings.

#### OPERATING SYSTEM SUPPORT

- [Windows](https://github.com/FreeSource/BelloSGML/blob/master/build/windows/bin/bellosgml.exe?raw=true)
- [Linux](https://github.com/FreeSource/BelloSGML/blob/master/build/linux/bin/bellosgml.exe?raw=true)
- [FreeBSD](https://github.com/FreeSource/BelloSGML/blob/master/build/freebsd/bin/bellosgml.exe?raw=true)
- [MacOS](https://github.com/FreeSource/BelloSGML/blob/master/build/macos/bin/bellosgml.exe?raw=true)
- [Solaris](https://github.com/FreeSource/BelloSGML/blob/master/build/solaris/bin/bellosgml.exe?raw=true)
- [Haiku](https://github.com/FreeSource/BelloSGML/blob/master/build/haiku/bin/bellosgml.exe?raw=true)
- [OpenIndiana](https://github.com/FreeSource/BelloSGML/blob/master/build/openindiana/bin/bellosgml.exe?raw=true)

#### SYNOPSIS
bellosgml.exe [OPTION]... [FILE]...

#### OPTIONS

- ``--in``: Specify a file to be beautifier.
- ``--out``: Specify a file to be written.
- ``--overwrite``: Overwrites the current input file.
- ``--spaces``: Specify the indentation level with number of spaces (default indent is tab).
- ``--guides``: Use pipe char (vertical bar) to be guide lines with simple editor.

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