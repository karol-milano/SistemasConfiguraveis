@@ -729,17 +729,11 @@ static symbol *
 find_start_symbol (void)
 {
   symbol_list *res = grammar;
-  for (;
-       res && symbol_is_dummy (res->content.sym);
-       res = res->next)
-    {
-      for (res = res->next;
-           res && res->content.sym;
-           res = res->next)
-        continue;
-      assume (res);
-    }
-  assume (res);
+  /* Skip all the possible dummy rules of the first rule.  */
+  for (; symbol_is_dummy (res->content.sym); res = res->next)
+    /* Skip the LHS, and then all the RHS of the dummy rule.  */
+    for (res = res->next; res->content.sym; res = res->next)
+      continue;
   return res->content.sym;
 }
 
