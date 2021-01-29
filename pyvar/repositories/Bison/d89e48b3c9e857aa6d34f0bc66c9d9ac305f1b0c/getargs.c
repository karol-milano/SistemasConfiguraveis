@@ -258,7 +258,8 @@ usage (int status)
       printf (_("Usage: %s [OPTION]... FILE\n"), program_name);
       fputs (_("\
 Generate a deterministic LR or generalized LR (GLR) parser employing\n\
-LALR(1), IELR(1), or canonical LR(1) parser tables.\n\
+LALR(1), IELR(1), or canonical LR(1) parser tables.  IELR(1) and\n\
+canonical LR(1) support is experimental.\n\
 \n\
 "), stdout);
 
