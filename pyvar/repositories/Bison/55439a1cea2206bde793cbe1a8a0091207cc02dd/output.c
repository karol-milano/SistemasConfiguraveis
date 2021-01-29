@@ -284,10 +284,10 @@ prepare_states (void)
 static int
 symbol_type_name_cmp (const symbol **lhs, const symbol **rhs)
 {
-  int res = UNIQSTR_CMP((*lhs)->type_name, (*rhs)->type_name);
-  if (res)
-    return res;
-  return (*lhs)->number - (*rhs)->number;
+  int res = uniqstr_cmp ((*lhs)->type_name, (*rhs)->type_name);
+  if (!res)
+    res = (*lhs)->number - (*rhs)->number;
+  return res;
 }
 
 
