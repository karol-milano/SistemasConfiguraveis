@@ -275,8 +275,7 @@ usage (int status)
       printf (_("Usage: %s [OPTION]... FILE\n"), program_name);
       fputs (_("\
 Generate a deterministic LR or generalized LR (GLR) parser employing\n\
-LALR(1), IELR(1), or canonical LR(1) parser tables.  IELR(1) and\n\
-canonical LR(1) support is experimental.\n\
+LALR(1), IELR(1), or canonical LR(1) parser tables.\n\
 \n\
 "), stdout);
 
@@ -332,7 +331,6 @@ Output:\n\
   -o, --output=FILE          leave output to FILE\n\
   -g, --graph[=FILE]         also output a graph of the automaton\n\
   -x, --xml[=FILE]           also output an XML report of the automaton\n\
-                             (the XML schema is experimental)\n\
 "), stdout);
       putc ('\n', stdout);
 
