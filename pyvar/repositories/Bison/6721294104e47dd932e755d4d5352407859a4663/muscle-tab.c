@@ -403,10 +403,20 @@ void
 muscle_percent_define_insert (char const *variable, location variable_loc,
                               char const *value)
 {
+  char *variable_tr = NULL;
   char const *name;
   char const *loc_name;
   char const *syncline_name;
 
+  /* Permit certain names with underscores for backward compatibility.  */
+  if (0 == strcmp (variable, "api.push_pull")
+      || 0 == strcmp (variable, "lr.keep_unreachable_states"))
+    {
+      variable_tr = strdup (variable);
+      tr (variable_tr, '_', '-');
+      variable = variable_tr;
+    }
+
   MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
   MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
   MUSCLE_USER_NAME_CONVERT (syncline_name,
@@ -427,6 +437,8 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
   muscle_syncline_grow (syncline_name, variable_loc);
   muscle_user_name_list_grow ("percent_define_user_variables", variable,
                               variable_loc);
+
+  free (variable_tr);
 }
 
 /* This is used for backward compatibility, e.g., "%define api.pure"
