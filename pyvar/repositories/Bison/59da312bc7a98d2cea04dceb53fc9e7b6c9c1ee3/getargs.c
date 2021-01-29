@@ -1,7 +1,7 @@
 /* Parse command line arguments for Bison.
 
    Copyright (C) 1984, 1986, 1989, 1992, 2000, 2001, 2002, 2003, 2004,
-   2005, 2006, 2007 Free Software Foundation, Inc.
+   2005, 2006, 2007, 2008 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -269,6 +269,7 @@ Operation modes:\n\
 
       fputs (_("\
 Parser:\n\
+  -L, --language=LANGUAGE    specify the output programming language\n\
   -S, --skeleton=FILE        specify the skeleton to use\n\
   -t, --debug                instrument the parser for debugging\n\
       --locations            enable locations computation\n\
@@ -288,6 +289,7 @@ Output:\n\
   -o, --output=FILE          leave output to FILE\n\
   -g, --graph[=FILE]         also output a graph of the automaton\n\
   -x, --xml[=FILE]           also output an XML report of the automaton\n\
+                             (the XML schema is experimental)\n\
 \n\
 "), stdout);
 
