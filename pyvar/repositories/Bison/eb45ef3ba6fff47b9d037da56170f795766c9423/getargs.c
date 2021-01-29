@@ -262,7 +262,8 @@ usage (int status)
 
       printf (_("Usage: %s [OPTION]... FILE\n"), program_name);
       fputs (_("\
-Generate LALR(1) and GLR parsers.\n\
+Generate a deterministic or GLR parser employing LALR(1), IELR(1), or\n\
+canonical LR(1) parser tables.\n\
 \n\
 "), stdout);
 
