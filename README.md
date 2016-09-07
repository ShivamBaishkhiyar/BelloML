![BelloSGML](https://cdn.rawgit.com/FreeSource/BelloSGML/master/rc/bellosgml2.jpg)
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
bellosgml.exe [FILE]... [OPTION]...

#### OPTIONS

- ``-r``: Replace the current input file.
- ``-t``: Specify the tab indentation level with number of spaces.
- ``-u``: Define a numeric unique id attribute (uid) to each element.

#### EXAMPLES

````
bellosgml.exe myfile.xml mynewfile.xml
bellosgml.exe myfile.xml -r
bellosgml.exe myfile.xml -r -t 4
bellosgml.exe myfile.xml -r -u
````

#### VERSION

This document was last revised for BelloSGML - Daisy 2.0.0