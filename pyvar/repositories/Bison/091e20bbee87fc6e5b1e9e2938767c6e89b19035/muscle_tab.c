@@ -58,9 +58,6 @@ muscle_init (void)
   muscle_insert ("stype", "int");
   muscle_insert ("ltype", "yyltype");
 
-  /* Tokens.  */
-  muscle_insert ("tokendef", NULL);
-
   /* Tables.  */
   muscle_insert ("rhs", NULL);
   muscle_insert ("pact", NULL);
