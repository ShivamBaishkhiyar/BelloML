![BelloSGML](https://cdn.rawgit.com/FreeSource/BelloSGML/Daisy/rc/bellosgml.jpg)
---------

#### DESCRIPTION
A simple markup language beautifier, that helps you making SGML, XML or HTML files easier read by human beings.

#### OPERATING SYSTEM SUPPORT _[DOWNLOAD]_

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

- ``-i``: Specify the input file.
- ``-o``: Specify the output file.
- ``-r``: Replace the current input file.
- ``-t``: Specify the tab indentation level with number of spaces.

#### EXAMPLES

````
bellosgml.exe -i myfile.xml -o mynewfile.xml
bellosgml.exe -i myfile.xml -r
bellosgml.exe -i myfile.xml -r -t 4
````

#### VERSION

This document was last revised for BelloSGML - Daisy 1.00.