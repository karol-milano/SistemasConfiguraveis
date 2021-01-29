@@ -641,9 +641,6 @@ check_and_convert_grammar (void)
   if (nrules == 0)
     fatal (_("no rules in the input grammar"));
 
-  /* Report any undefined symbols and consider them nonterminals.  */
-  symbols_check_defined ();
-
   /* If the user did not define her ENDTOKEN, do it now. */
   if (!endtoken)
     {
@@ -654,6 +651,9 @@ check_and_convert_grammar (void)
       endtoken->user_token_number = 0;
     }
 
+  /* Report any undefined symbols and consider them nonterminals.  */
+  symbols_check_defined ();
+
   /* Find the start symbol if no %start.  */
   if (!start_flag)
     {
