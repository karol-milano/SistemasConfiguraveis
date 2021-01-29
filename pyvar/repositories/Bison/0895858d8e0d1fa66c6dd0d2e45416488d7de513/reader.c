@@ -818,7 +818,7 @@ check_and_convert_grammar (void)
   }
 
   aver (nsyms <= SYMBOL_NUMBER_MAXIMUM);
-  aver (nsyms == ntokens + nvars);
+  aver (nsyms == ntokens + nnterms);
 
   /* Assign the symbols their symbol numbers.  */
   symbols_pack ();
