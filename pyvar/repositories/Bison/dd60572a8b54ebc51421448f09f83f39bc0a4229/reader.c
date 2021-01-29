@@ -146,19 +146,16 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
        merge_function = merge_function->next)
     merger_find += 1;
   assert (merge_function != NULL && merger_find == merger);
-  if (merge_function->type == NULL)
-    {
-      merge_function->type = uniqstr_new (type);
-      merge_function->type_declaration_location = declaration_loc;
-    }
-  else if (!UNIQSTR_EQ (merge_function->type, type))
+  if (merge_function->type != NULL && !UNIQSTR_EQ (merge_function->type, type))
     {
       warn_at (declaration_loc,
 	       _("result type clash on merge function `%s': <%s> != <%s>"),
 	       merge_function->name, type, merge_function->type);
       warn_at (merge_function->type_declaration_location,
-	       _("first declaration"));
+	       _("previous declaration"));
     }
+  merge_function->type = uniqstr_new (type);
+  merge_function->type_declaration_location = declaration_loc;
 }
 
 /*--------------------------------------.
