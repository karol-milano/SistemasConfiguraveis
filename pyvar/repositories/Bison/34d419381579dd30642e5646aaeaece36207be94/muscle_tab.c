@@ -401,12 +401,14 @@ do {                                                                 \
 
 void
 muscle_percent_define_insert (char const *variable, location variable_loc,
-                              char const *value)
+                              char const *value,
+                              muscle_percent_define_how how)
 {
   char *variable_tr = NULL;
   char const *name;
   char const *loc_name;
   char const *syncline_name;
+  char const *how_name;
 
   /* Permit certain names with underscores for backward compatibility.  */
   if (0 == strcmp (variable, "api.push_pull")
@@ -421,22 +423,33 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
   MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
   MUSCLE_USER_NAME_CONVERT (syncline_name,
                             "percent_define_syncline(", variable, ")");
+  MUSCLE_USER_NAME_CONVERT (how_name, "percent_define_how(", variable, ")");
 
-  if (muscle_find_const (name))
+  /* Command-line options are processed before the grammar file.  */
+  if (how == MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE
+      && muscle_find_const (name))
     {
+      muscle_percent_define_how how_old =
+        atoi (muscle_find_const (how_name));
+      if (how_old == MUSCLE_PERCENT_DEFINE_F)
+        {
+          free (variable_tr);
+          return;
+        }
       warn_at (variable_loc, _("%s `%s' redefined"),
                "%define variable", variable);
       warn_at (muscle_percent_define_get_loc (variable),
-               _("previous definition"));
+                   _("previous definition"));
     }
-  MUSCLE_INSERT_STRING (name, value);
 
+  MUSCLE_INSERT_STRING (name, value);
   muscle_insert (loc_name, "");
   muscle_location_grow (loc_name, variable_loc);
   muscle_insert (syncline_name, "");
   muscle_syncline_grow (syncline_name, variable_loc);
   muscle_user_name_list_grow ("percent_define_user_variables", variable,
                               variable_loc);
+  MUSCLE_INSERT_INT (how_name, how);
 
   free (variable_tr);
 }
