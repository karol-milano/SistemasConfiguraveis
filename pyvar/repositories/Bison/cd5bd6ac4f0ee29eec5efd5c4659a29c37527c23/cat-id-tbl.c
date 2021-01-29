@@ -43,6 +43,7 @@ Operation modes:\n\
   -y, --yacc      emulate POSIX yacc\n", 26},
   {"\
 Parser:\n\
+  -S, --skeleton=FILE        specify the skeleton to use\n\
   -t, --debug                instrument the parser for debugging\n\
       --locations            enable locations computation\n\
   -p, --name-prefix=PREFIX   prepend PREFIX to the external symbols\n\
@@ -58,7 +59,8 @@ Output:\n\
   -o, --output-file=FILE     leave output to FILE\n", 28},
   {"Report bugs to <bug-bison@gnu.org>.\n", 29},
   {"bison (GNU Bison) %s", 30},
-  {"Copyright 1984, 1986, 1989, 1992, 2000 Free Software Foundation, Inc.\n", 31},
+  {"\
+Copyright 1984, 1986, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.\n", 31},
   {"\
 This is free software; see the source for copying conditions.  There is NO\n\
 warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n", 32},
