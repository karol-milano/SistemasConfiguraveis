@@ -36,6 +36,8 @@ symbol_list_new (symbol_t *sym, location_t location)
   res->location = location;
   res->action = NULL;
   res->ruleprec = NULL;
+  res->dprec = 0;
+  res->merger = 0;
   return res;
 }
 
