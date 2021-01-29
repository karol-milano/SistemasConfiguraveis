@@ -128,12 +128,16 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
   aver (merge_function != NULL && merger_find == merger);
   if (merge_function->type != NULL && !UNIQSTR_EQ (merge_function->type, type))
     {
-      complain_at (declaration_loc,
-                   _("result type clash on merge function %s: <%s> != <%s>"),
-                   quote (merge_function->name), type, merge_function->type);
-      complain_at (merge_function->type_declaration_location,
-		   _("previous declaration"));
-    }
+      unsigned indent = 0;
+      complain_at_indent (declaration_loc, &indent,
+                          _("result type clash on merge function %s: "
+                            "<%s> != <%s>"),
+                          quote (merge_function->name), type,
+                          merge_function->type);
+      indent += SUB_INDENT;
+      complain_at_indent (merge_function->type_declaration_location, &indent,
+                          _("previous declaration"));
+   }
   merge_function->type = uniqstr_new (type);
   merge_function->type_declaration_location = declaration_loc;
 }
