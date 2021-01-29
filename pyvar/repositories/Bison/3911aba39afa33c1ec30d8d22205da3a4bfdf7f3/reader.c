@@ -143,19 +143,24 @@ record_merge_function_type (int merger, symbol *sym, location declaration_loc)
        merge_function = merge_function->next)
     merger_find += 1;
   aver (merge_function != NULL && merger_find == merger);
-  if (merge_function->sym && merge_function->sym->content->type_name
-      && !UNIQSTR_EQ (merge_function->sym->content->type_name, type))
+  if (merge_function->sym && merge_function->sym->content->type_name)
     {
-      complain (&declaration_loc, complaint,
-                _("result type clash on merge function %s: "
-                "<%s> != <%s>"),
-                quote (merge_function->name), type,
-                merge_function->sym->content->type_name);
-      subcomplain (&merge_function->type_declaration_loc, complaint,
-                   _("previous declaration"));
+      if (!UNIQSTR_EQ (merge_function->sym->content->type_name, type))
+        {
+          complain (&declaration_loc, complaint,
+                    _("result type clash on merge function %s: "
+                      "<%s> != <%s>"),
+                    quote (merge_function->name), type,
+                    merge_function->sym->content->type_name);
+          subcomplain (&merge_function->type_declaration_loc, complaint,
+                       _("previous declaration"));
+        }
+    }
+  else
+    {
+      merge_function->sym = sym;
+      merge_function->type_declaration_loc = declaration_loc;
     }
-  merge_function->sym = sym;
-  merge_function->type_declaration_loc = declaration_loc;
 }
 
 /*--------------------------------------.
