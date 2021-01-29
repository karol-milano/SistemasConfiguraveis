@@ -815,8 +815,11 @@ check_and_convert_grammar (void)
     grammar = p;
   }
 
-  aver (nsyms <= SYMBOL_NUMBER_MAXIMUM);
-  aver (nsyms == ntokens + nnterms);
+  if (SYMBOL_NUMBER_MAXIMUM - nnterms < ntokens)
+    complain (NULL, fatal, "too many symbols in input grammar (limit is %d)",
+              SYMBOL_NUMBER_MAXIMUM);
+
+  nsyms = ntokens + nnterms;
 
   /* Assign the symbols their symbol numbers.  */
   symbols_pack ();
