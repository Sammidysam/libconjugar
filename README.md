libconjugar
===========

Libconjugar is a Spanish conjugation library.
It is programmed in C with Vala bindings provided.
It was made because other programs that conjugated Spanish verbs had some major problems.
These problems were
* they were almost always written in a scripting language.

  Being written in a scripting language usually forces code that uses the code to be written in the same language.
  C code can be used in multiple languages, which causes it to make sense as a universal library selection.
  However, only Vala is currently planned to *use* the C code.
  If ported to other languages such as Ruby or Python, it is likely that the library would be rewritten in those languages.
* their configuration systems were horrible.

  The other programs that have been made have not advertised their amazing configuration systems.
  It causes the impression that their program does not have an easy system for adding new irregular verbs.
  In some cases, it looks like the program has each conjugation of the verb listed out.
  This is an incredibly dumb way to go about conjugating Spanish verbs.
  There are patterns in the conjugations, so why not let the computer manipulate them?
  In other cases, some patterns can be written, but not in a very efficient manner; configuration is repeated in the configuration file(s).

This library seeks to fix the two problems, resulting in a library that is easy to use, usable in many cases and places, and has a good, quick, and simple configuration system.

License
-------

This program is licensed under the GNU General Public License version 3.
To see the license, visit the file [LICENSE](LICENSE).
