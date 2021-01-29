@@ -66,6 +66,9 @@ symbol_new (uniqstr tag, location loc)
   res->alias = NULL;
   res->class = unknown_sym;
 
+  if (nsyms == SYMBOL_NUMBER_MAXIMUM)
+    fatal (_("too many symbols in input grammar (limit is %d)"),
+	   SYMBOL_NUMBER_MAXIMUM);
   nsyms++;
   return res;
 }
