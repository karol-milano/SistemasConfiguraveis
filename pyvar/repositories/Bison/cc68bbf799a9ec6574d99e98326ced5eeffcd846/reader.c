@@ -817,9 +817,9 @@ check_and_convert_grammar (void)
   /* Assign the symbols their symbol numbers.  */
   symbols_pack ();
 
-  /* Scan rule actions after invoking symbol_check_alias_consistency (in
-     symbols_pack above) so that token types are set correctly before the rule
-     action type checking.
+  /* Scan rule actions after invoking symbol_check_alias_consistency
+     (in symbols_pack above) so that token types are set correctly
+     before the rule action type checking.
 
      Before invoking grammar_rule_check_and_complete (in packgram
      below) on any rule, make sure all actions have already been
