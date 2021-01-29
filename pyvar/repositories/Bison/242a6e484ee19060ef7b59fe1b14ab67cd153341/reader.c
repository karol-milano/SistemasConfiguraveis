@@ -541,9 +541,9 @@ reader (void)
     grammar = p;
   }
 
-  if (nsyms > SHRT_MAX)
+  if (SYMBOL_NUMBER_MAX < nsyms)
     fatal (_("too many symbols (tokens plus nonterminals); maximum %d"),
-          SHRT_MAX);
+	   SYMBOL_NUMBER_MAX);
 
   assert (nsyms == ntokens + nvars);
 
