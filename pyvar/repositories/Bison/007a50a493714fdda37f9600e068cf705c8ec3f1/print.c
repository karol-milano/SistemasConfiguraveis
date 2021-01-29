@@ -386,7 +386,7 @@ print_grammar (FILE *out)
   /* TERMINAL (type #) : rule #s terminal is on RHS */
   fprintf (out, "%s\n\n", _("Terminals, with rules where they appear"));
   for (i = 0; i < max_user_token_number + 1; i++)
-    if (token_translations[i] != 2)
+    if (token_translations[i] != undeftoken->number)
       {
 	buffer[0] = 0;
 	column = strlen (escape (symbols[token_translations[i]]->tag));
