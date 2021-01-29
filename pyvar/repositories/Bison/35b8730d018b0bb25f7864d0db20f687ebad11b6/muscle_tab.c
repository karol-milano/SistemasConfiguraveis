@@ -168,27 +168,38 @@ muscle_grow (const char *key, const char *val, const char *separator)
     }
 }
 
-
 /*------------------------------------------------------------------.
-| Append VALUE to the current value of KEY, using muscle_grow.  But |
-| in addition, issue a synchronization line for the location LOC.   |
+| Using muscle_grow, append a synchronization line for the location |
+| LOC to the current value of KEY.                                  |
 `------------------------------------------------------------------*/
 
-void
-muscle_code_grow (const char *key, const char *val, location loc)
+static void
+muscle_syncline_grow (char const *key, location loc)
 {
   char *extension = NULL;
   obstack_fgrow1 (&muscle_obstack, "]b4_syncline(%d, [[", loc.start.line);
   MUSCLE_OBSTACK_SGROW (&muscle_obstack,
 			quotearg_style (c_quoting_style, loc.start.file));
-  obstack_sgrow (&muscle_obstack, "]])[\n");
-  obstack_sgrow (&muscle_obstack, val);
+  obstack_sgrow (&muscle_obstack, "]])[");
   obstack_1grow (&muscle_obstack, 0);
   extension = obstack_finish (&muscle_obstack);
   muscle_grow (key, extension, "");
   obstack_free (&muscle_obstack, extension);
 }
 
+/*------------------------------------------------------------------.
+| Append VALUE to the current value of KEY, using muscle_grow.  But |
+| in addition, issue a synchronization line for the location LOC    |
+| using muscle_syncline_grow.                                       |
+`------------------------------------------------------------------*/
+
+void
+muscle_code_grow (const char *key, const char *val, location loc)
+{
+  muscle_syncline_grow (key, loc);
+  muscle_grow (key, val, "\n");
+}
+
 
 void muscle_pair_list_grow (const char *muscle,
 			    const char *a1, const char *a2)
@@ -395,20 +406,26 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
 {
   char const *name;
   char const *loc_name;
+  char const *syncline_name;
 
   MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
   MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
+  MUSCLE_USER_NAME_CONVERT (syncline_name,
+                            "percent_define_syncline(", variable, ")");
 
   if (muscle_find_const (name))
     {
       warn_at (variable_loc, _("%s `%s' redefined"),
                "%define variable", variable);
-      warn_at (muscle_location_decode (loc_name), _("previous definition"));
+      warn_at (muscle_percent_define_get_loc (variable),
+               _("previous definition"));
     }
   MUSCLE_INSERT_STRING (name, value);
 
   muscle_insert (loc_name, "");
   muscle_location_grow (loc_name, variable_loc);
+  muscle_insert (syncline_name, "");
+  muscle_syncline_grow (syncline_name, variable_loc);
   muscle_user_name_list_grow ("percent_define_user_variables", variable,
                               variable_loc);
 }
@@ -431,6 +448,31 @@ muscle_percent_define_get (char const *variable)
   return value;
 }
 
+location
+muscle_percent_define_get_loc (char const *variable)
+{
+  char const *loc_name;
+  MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
+  if (!muscle_find_const (loc_name))
+    fatal(_("undefined %%define variable `%s' passed to muscle_percent_define_get_loc"),
+          variable);
+  return muscle_location_decode (loc_name);
+}
+
+char const *
+muscle_percent_define_get_syncline (char const *variable)
+{
+  char const *syncline_name;
+  char const *syncline;
+  MUSCLE_USER_NAME_CONVERT (syncline_name,
+                            "percent_define_syncline(", variable, ")");
+  syncline = muscle_find_const (syncline_name);
+  if (!syncline)
+    fatal(_("undefined %%define variable `%s' passed to muscle_percent_define_get_syncline"),
+          variable);
+  return syncline;
+}
+
 bool
 muscle_percent_define_ifdef (char const *variable)
 {
@@ -455,16 +497,9 @@ muscle_percent_define_ifdef (char const *variable)
 bool
 muscle_percent_define_flag_if (char const *variable)
 {
-  char const *name;
-  char const *loc_name;
-  char const *usage_name;
   char const *invalid_boolean_name;
   bool result = false;
 
-  MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
-  MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
-  MUSCLE_USER_NAME_CONVERT (usage_name, "percent_define_bison_variables(",
-                            variable, ")");
   MUSCLE_USER_NAME_CONVERT (invalid_boolean_name,
                             "percent_define_invalid_boolean(", variable, ")");
 
@@ -478,7 +513,7 @@ muscle_percent_define_flag_if (char const *variable)
       else if (!muscle_find_const (invalid_boolean_name))
         {
           muscle_insert (invalid_boolean_name, "");
-          complain_at(muscle_location_decode (loc_name),
+          complain_at(muscle_percent_define_get_loc (variable),
                       _("invalid value for %%define Boolean variable `%s'"),
                       variable);
         }
@@ -496,17 +531,22 @@ muscle_percent_define_default (char const *variable, char const *value)
 {
   char const *name;
   char const *loc_name;
+  char const *syncline_name;
   MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
   MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
+  MUSCLE_USER_NAME_CONVERT (syncline_name,
+                            "percent_define_syncline(", variable, ")");
   if (!muscle_find_const (name))
     {
       location loc;
       MUSCLE_INSERT_STRING (name, value);
       loc.start.file = loc.end.file = "[Bison:muscle_percent_define_default]";
-      loc.start.line = loc.start.column = 0;
-      loc.end.line = loc.end.column = 0;
+      loc.start.line = loc.end.line = 1;
+      loc.start.column = loc.end.column = 0;
       muscle_insert (loc_name, "");
       muscle_location_grow (loc_name, loc);
+      muscle_insert (syncline_name, "");
+      muscle_syncline_grow (syncline_name, loc);
     }
 }
 
@@ -517,11 +557,9 @@ muscle_percent_define_check_values (char const * const *values)
     {
       char const *variable = *values;
       char const *name;
-      char const *loc_name;
       char *value;
 
       MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
-      MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
 
       value = muscle_string_decode (name);
       if (value)
@@ -538,7 +576,7 @@ muscle_percent_define_check_values (char const * const *values)
                 }
             }
           if (!valid)
-            complain_at(muscle_location_decode (loc_name),
+            complain_at(muscle_percent_define_get_loc (variable),
                         _("invalid value for %%define variable `%s': `%s'"),
                         variable, value);
           free (value);
