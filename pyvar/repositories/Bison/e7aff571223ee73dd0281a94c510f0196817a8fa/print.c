@@ -362,7 +362,7 @@ print_terminal_symbols (FILE *out)
 {
   /* TERMINAL (type #) : rule #s terminal is on RHS */
   fprintf (out, "%s\n\n", _("Terminals, with rules where they appear"));
-  for (symbol_number i = 0; i < max_user_token_number + 1; i++)
+  for (int i = 0; i < max_code + 1; ++i)
     if (token_translations[i] != undeftoken->content->number)
       {
         const char *tag = symbols[token_translations[i]]->tag;
@@ -445,7 +445,7 @@ print_results (void)
   reduce_output (out);
   grammar_rules_partial_print (out,
                                _("Rules useless in parser due to conflicts"),
-                                 rule_useless_in_parser_p);
+                               rule_useless_in_parser_p);
   conflicts_output (out);
 
   grammar_rules_print (out);
