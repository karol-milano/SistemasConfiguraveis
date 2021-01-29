@@ -257,8 +257,8 @@ usage (int status)
 
       printf (_("Usage: %s [OPTION]... FILE\n"), program_name);
       fputs (_("\
-Generate a deterministic or GLR parser employing LALR(1), IELR(1), or\n\
-canonical LR(1) parser tables.\n\
+Generate a deterministic LR or generalized LR (GLR) parser employing\n\
+LALR(1), IELR(1), or canonical LR(1) parser tables.\n\
 \n\
 "), stdout);
 
