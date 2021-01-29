@@ -130,7 +130,7 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
   if (merge_function->type != NULL && !UNIQSTR_EQ (merge_function->type, type))
     {
       complain_at (declaration_loc,
-                   _("result type clash on merge function `%s': <%s> != <%s>"),
+                   _("result type clash on merge function '%s': <%s> != <%s>"),
                    merge_function->name, type, merge_function->type);
       complain_at (merge_function->type_declaration_location,
                    _("previous declaration"));
