@@ -129,10 +129,10 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
   if (merge_function->type != NULL && !UNIQSTR_EQ (merge_function->type, type))
     {
       complain_at (declaration_loc, complaint,
-                _("result type clash on merge function %s: <%s> != <%s>"),
-                quote (merge_function->name), type, merge_function->type);
+                   _("result type clash on merge function %s: <%s> != <%s>"),
+                   quote (merge_function->name), type, merge_function->type);
       complain_at (merge_function->type_declaration_location, complaint,
-                _("previous declaration"));
+                   _("previous declaration"));
     }
   merge_function->type = uniqstr_new (type);
   merge_function->type_declaration_location = declaration_loc;
@@ -319,8 +319,7 @@ grammar_rule_check (const symbol_list *r)
             /* The default action, $$ = $1, `uses' both.  */
             && (r->action_props.code || (n != 0 && n != 1)))
           {
-            int warn_flag =
-              midrule_warning ? Wmidrule_values : Wother;
+            warnings warn_flag = midrule_warning ? Wmidrule_values : Wother;
             if (n)
               complain_at (r->location, warn_flag, _("unused value: $%d"), n);
             else
