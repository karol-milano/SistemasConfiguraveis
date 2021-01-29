@@ -419,6 +419,15 @@ symbol_check_defined (symbol *sym)
       sym->number = nvars++;
     }
 
+  for (int i = 0; i < 2; ++i)
+    if (sym->props[i].kind == CODE_PROPS_NONE && sym->type_name)
+      {
+        semantic_type *sem_type = semantic_type_get (sym->type_name, NULL);
+        if (sem_type
+            && sem_type->props[i].kind != CODE_PROPS_NONE)
+          sem_type->props[i].is_used = true;
+      }
+
   /* Set the semantic type status associated to the current symbol to
      'declared' so that we could check semantic types unnecessary uses. */
   if (sym->type_name)
@@ -434,7 +443,16 @@ symbol_check_defined (symbol *sym)
 static inline bool
 semantic_type_check_defined (semantic_type *sem_type)
 {
-  if (sem_type->status != declared)
+  if (sem_type->status == declared)
+    {
+      for (int i = 0; i < 2; ++i)
+        if (sem_type->props[i].kind != CODE_PROPS_NONE
+            && ! sem_type->props[i].is_used)
+          warn_at (sem_type->location,
+                   _("useless %s for type <%s>"),
+                   code_props_type_string (i), sem_type->tag);
+    }
+  else
     warn_at (sem_type->location,
              _("type <%s> is used, but is not associated to any symbol"),
              sem_type->tag);
