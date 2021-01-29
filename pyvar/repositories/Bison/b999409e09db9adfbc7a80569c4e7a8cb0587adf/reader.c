@@ -129,15 +129,15 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
   if (merge_function->type != NULL && !UNIQSTR_EQ (merge_function->type, type))
     {
       unsigned indent = 0;
-      complain_at_indent (declaration_loc, complaint, &indent,
-                          _("result type clash on merge function %s: "
-                            "<%s> != <%s>"),
-                          quote (merge_function->name), type,
-                          merge_function->type);
+      complain_indent (&declaration_loc, complaint, &indent,
+                       _("result type clash on merge function %s: "
+                         "<%s> != <%s>"),
+                       quote (merge_function->name), type,
+                       merge_function->type);
       indent += SUB_INDENT;
-      complain_at_indent (merge_function->type_declaration_location, complaint,
-                          &indent,
-                          _("previous declaration"));
+      complain_indent (&merge_function->type_declaration_location, complaint,
+                       &indent,
+                       _("previous declaration"));
     }
   merge_function->type = uniqstr_new (type);
   merge_function->type_declaration_location = declaration_loc;
