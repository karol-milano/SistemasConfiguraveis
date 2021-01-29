@@ -433,9 +433,10 @@ define_directive (char const *assignment,
  * value is exactly \a variable.  */
 static
 char const *
-muscle_percent_variable_update (char const *variable, location variable_loc,
+muscle_percent_variable_update (char const *variable,
                                 muscle_kind kind,
-                                char const **value)
+                                char const **value,
+                                char **old, char **upd)
 {
   typedef struct
   {
@@ -476,13 +477,8 @@ muscle_percent_variable_update (char const *variable, location variable_loc,
           : STREQ (c->obsolete, variable))
         {
           /* Generate the deprecation warning. */
-          {
-            char *old = define_directive (c->obsolete, kind, *value);
-            char *upd = define_directive (c->updated, c->kind, *value);
-            deprecated_directive (&variable_loc, old, upd);
-            free (old);
-            free (upd);
-          }
+          *old = define_directive (c->obsolete, kind, *value);
+          *upd = define_directive (c->updated, c->kind, *value);
           /* Update the variable and its value.  */
           {
             char *res = xstrdup (c->updated);
@@ -506,8 +502,11 @@ muscle_percent_define_insert (char const *var, location variable_loc,
                               muscle_percent_define_how how)
 {
   /* Backward compatibility.  */
+  char *old = NULL;
+  char *upd = NULL;
   char const *variable
-    = muscle_percent_variable_update (var, variable_loc, kind, &value);
+    = muscle_percent_variable_update (var, kind,
+                                      &value, &old, &upd);
   uniqstr name = muscle_name (variable, NULL);
   uniqstr loc_name = muscle_name (variable, "loc");
   uniqstr syncline_name = muscle_name (variable, "syncline");
@@ -515,6 +514,7 @@ muscle_percent_define_insert (char const *var, location variable_loc,
   uniqstr kind_name = muscle_name (variable, "kind");
 
   /* Command-line options are processed before the grammar file.  */
+  bool warned = false;
   if (how == MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE
       && muscle_find_const (name))
     {
@@ -528,8 +528,12 @@ muscle_percent_define_insert (char const *var, location variable_loc,
       i += SUB_INDENT;
       location loc = muscle_percent_define_get_loc (variable);
       complain_indent (&loc, complaint, &i, _("previous definition"));
+      warned = true;
     }
 
+  if (!warned && old && upd)
+    deprecated_directive (&variable_loc, old, upd);
+
   MUSCLE_INSERT_STRING (name, value);
   muscle_insert (loc_name, "");
   muscle_location_grow (loc_name, variable_loc);
@@ -540,6 +544,8 @@ muscle_percent_define_insert (char const *var, location variable_loc,
   MUSCLE_INSERT_INT (how_name, how);
   MUSCLE_INSERT_STRING (kind_name, muscle_kind_string (kind));
  end:
+  free (old);
+  free (upd);
   if (variable != var)
     free ((char *) variable);
 }
