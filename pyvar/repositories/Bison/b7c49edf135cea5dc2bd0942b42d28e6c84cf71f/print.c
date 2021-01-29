@@ -389,8 +389,6 @@ print_grammar (FILE *out)
 
   /* TERMINAL (type #) : rule #s terminal is on RHS */
   fprintf (out, "%s\n\n", _("Terminals, with rules where they appear"));
-  fprintf (out, "%s (-1)\n", escape (tags[0]));
-
   for (i = 0; i <= max_user_token_number; i++)
     if (token_translations[i] != 2)
       {
