@@ -539,10 +539,7 @@ reader (void)
     grammar = p;
   }
 
-  if (SYMBOL_NUMBER_MAX < nsyms)
-    fatal (_("too many symbols (tokens plus nonterminals); maximum %d"),
-	   SYMBOL_NUMBER_MAX);
-
+  assert (nsyms <= SYMBOL_NUMBER_MAX);
   assert (nsyms == ntokens + nvars);
 
   xfclose (finput);
