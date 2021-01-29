@@ -405,7 +405,6 @@ static void
 print_terminal_symbols (FILE *out)
 {
   symbol_number i;
-  char buffer[90];
 
   /* TERMINAL (type #) : rule #s terminal is on RHS */
   fprintf (out, "%s\n\n", _("Terminals, with rules where they appear"));
@@ -414,6 +413,7 @@ print_terminal_symbols (FILE *out)
       {
         const char *tag = symbols[token_translations[i]]->tag;
         int column = strlen (tag);
+        char buffer[90];
         rule_number r;
         item_number *rhsp;
 
@@ -440,7 +440,6 @@ static void
 print_nonterminal_symbols (FILE *out)
 {
   symbol_number i;
-  char buffer[90];
 
   fprintf (out, "%s\n\n", _("Nonterminals, with rules where they appear"));
   for (i = ntokens; i < nsyms; i++)
@@ -449,6 +448,8 @@ print_nonterminal_symbols (FILE *out)
       int column = strlen (tag);
       int left_count = 0, right_count = 0;
       rule_number r;
+      char buffer[90];
+      buffer[0] = 0;
 
       for (r = 0; r < nrules; r++)
         {
@@ -463,7 +464,6 @@ print_nonterminal_symbols (FILE *out)
               }
         }
 
-      buffer[0] = 0;
       fputs (tag, out);
       sprintf (buffer, " (%d)", i);
       END_TEST (0);
