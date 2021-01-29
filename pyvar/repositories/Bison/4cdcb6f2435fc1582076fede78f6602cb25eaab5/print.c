@@ -402,13 +402,11 @@ print_state (FILE *out, state *s)
 
 
 static void
-print_grammar (FILE *out)
+print_terminal_symbols (FILE *out)
 {
   symbol_number i;
   char buffer[90];
 
-  grammar_rules_print (out);
-
   /* TERMINAL (type #) : rule #s terminal is on RHS */
   fprintf (out, "%s\n\n", _("Terminals, with rules where they appear"));
   for (i = 0; i < max_user_token_number + 1; i++)
@@ -435,8 +433,15 @@ print_grammar (FILE *out)
         fprintf (out, "%s\n", buffer);
       }
   fputs ("\n\n", out);
+}
 
 
+static void
+print_nonterminal_symbols (FILE *out)
+{
+  symbol_number i;
+  char buffer[90];
+
   fprintf (out, "%s\n\n", _("Nonterminals, with rules where they appear"));
   for (i = ntokens; i < nsyms; i++)
     {
@@ -513,7 +518,9 @@ print_results (void)
                                  rule_useless_in_parser_p);
   conflicts_output (out);
 
-  print_grammar (out);
+  grammar_rules_print (out);
+  print_terminal_symbols (out);
+  print_nonterminal_symbols (out);
 
   /* If the whole state item sets, not only the kernels, are wanted,
      'closure' will be run, which needs memory allocation/deallocation.   */
