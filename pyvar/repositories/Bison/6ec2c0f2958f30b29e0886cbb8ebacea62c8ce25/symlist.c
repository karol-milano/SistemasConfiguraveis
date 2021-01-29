@@ -38,7 +38,7 @@ symbol_list_new (symbol *sym, location loc)
   res->sym = sym;
   res->location = loc;
 
-  res->mid_rule = NULL;
+  res->midrule = NULL;
 
   res->action = NULL;
   res->used = false;
