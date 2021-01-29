@@ -39,6 +39,8 @@ symbol_list_new (symbol *sym, location loc)
   res->location = loc;
 
   res->midrule = NULL;
+  res->midrule_parent_rule = NULL;
+  res->midrule_parent_rhs_index = 0;
 
   res->action = NULL;
   res->used = false;
@@ -102,7 +104,7 @@ unsigned int
 symbol_list_length (const symbol_list *l)
 {
   int res = 0;
-  for (/* Nothing. */; l; l = l->next)
+  for (/* Nothing. */; l && l->sym; l = l->next)
     ++res;
   return res;
 }
