libconjugar
===========

Libconjugar is a Spanish conjugation library.
It is programmed in C with Vala bindings provided.
It was made because other programs that conjugated Spanish verbs had some problems.
These were that they were always written in a scripting language and their configuration systems were horrible.
Being written in a scripting language usually forces code that uses the code to be written in the same language.
C code can be used by many languages, which causes it to make sense as a universal library selection.
However, only Vala is currently planned to *use* the C code.
If ported to other languages such as Python or Ruby, it is likely that the library would be rewritten in those languages.
The other programs that have been made have not advertised their amazing configuration engines.
It causes the impression that their program does not have an easy system for adding new irregular verbs.
In some cases, it looks like the program simply has each conjugation of the verb listed out.
In other cases, some patterns can be written, but not in a very efficient manner.
Still, configuration is repeated.
This library seeks to fix the two problems, resulting in a library that is easy to use, usable in many cases, and has a good configuration system.

License
-------

This program is licensed under the GNU General Public License version 3.
To see the license, visit the file [LICENSE](LICENSE).
