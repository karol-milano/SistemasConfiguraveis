@@ -148,11 +148,11 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
   assert (merge_function != NULL && merger_find == merger);
   if (merge_function->type != NULL && !UNIQSTR_EQ (merge_function->type, type))
     {
-      warn_at (declaration_loc,
-	       _("result type clash on merge function `%s': <%s> != <%s>"),
-	       merge_function->name, type, merge_function->type);
-      warn_at (merge_function->type_declaration_location,
-	       _("previous declaration"));
+      complain_at (declaration_loc,
+		   _("result type clash on merge function `%s': <%s> != <%s>"),
+		   merge_function->name, type, merge_function->type);
+      complain_at (merge_function->type_declaration_location,
+		   _("previous declaration"));
     }
   merge_function->type = uniqstr_new (type);
   merge_function->type_declaration_location = declaration_loc;
