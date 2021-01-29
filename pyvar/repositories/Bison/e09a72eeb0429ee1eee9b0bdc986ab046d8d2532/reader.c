@@ -124,16 +124,13 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
   aver (merge_function != NULL && merger_find == merger);
   if (merge_function->type != NULL && !UNIQSTR_EQ (merge_function->type, type))
     {
-      int indent = 0;
-      complain_indent (&declaration_loc, complaint, &indent,
-                       _("result type clash on merge function %s: "
-                         "<%s> != <%s>"),
-                       quote (merge_function->name), type,
-                       merge_function->type);
-      indent += SUB_INDENT;
-      complain_indent (&merge_function->type_declaration_loc, complaint,
-                       &indent,
-                       _("previous declaration"));
+      complain (&declaration_loc, complaint,
+                _("result type clash on merge function %s: "
+                "<%s> != <%s>"),
+                quote (merge_function->name), type,
+                merge_function->type);
+      subcomplain (&merge_function->type_declaration_loc, complaint,
+                   _("previous declaration"));
     }
   merge_function->type = uniqstr_new (type);
   merge_function->type_declaration_loc = declaration_loc;
