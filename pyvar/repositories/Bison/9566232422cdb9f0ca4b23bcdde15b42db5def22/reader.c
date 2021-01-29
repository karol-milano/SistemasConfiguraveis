@@ -829,8 +829,7 @@ check_and_convert_grammar (void)
   aver (nsyms <= SYMBOL_NUMBER_MAXIMUM);
   aver (nsyms == ntokens + nvars);
 
-  /* Assign the symbols their symbol numbers.  Write #defines for the
-     token symbols into FDEFINES if requested.  */
+  /* Assign the symbols their symbol numbers.  */
   symbols_pack ();
 
   /* Scan rule actions after invoking symbol_check_alias_consistency (in
