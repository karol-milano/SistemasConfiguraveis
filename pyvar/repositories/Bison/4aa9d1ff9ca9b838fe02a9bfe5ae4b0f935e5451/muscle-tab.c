@@ -439,7 +439,7 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
         atoi (muscle_find_const (how_name));
       if (how_old == MUSCLE_PERCENT_DEFINE_F)
         return;
-      complain_at (variable_loc, _("%%define variable `%s' redefined"),
+      complain_at (variable_loc, _("%%define variable '%s' redefined"),
                    variable);
       complain_at (muscle_percent_define_get_loc (variable),
                    _("previous definition"));
@@ -503,7 +503,7 @@ muscle_percent_define_get_loc (char const *variable)
   char const *loc_name;
   loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
   if (!muscle_find_const (loc_name))
-    fatal(_("undefined %%define variable `%s' passed to"
+    fatal(_("undefined %%define variable '%s' passed to"
             " muscle_percent_define_get_loc"), variable);
   return muscle_location_decode (loc_name);
 }
@@ -517,7 +517,7 @@ muscle_percent_define_get_syncline (char const *variable)
     UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
   syncline = muscle_find_const (syncline_name);
   if (!syncline)
-    fatal(_("undefined %%define variable `%s' passed to"
+    fatal(_("undefined %%define variable '%s' passed to"
             " muscle_percent_define_get_syncline"), variable);
   return syncline;
 }
@@ -563,13 +563,13 @@ muscle_percent_define_flag_if (char const *variable)
         {
           muscle_insert (invalid_boolean_name, "");
           complain_at(muscle_percent_define_get_loc (variable),
-                      _("invalid value for %%define Boolean variable `%s'"),
+                      _("invalid value for %%define Boolean variable '%s'"),
                       variable);
         }
       free (value);
     }
   else
-    fatal(_("undefined %%define variable `%s' passed to muscle_percent_define_flag_if"),
+    fatal(_("undefined %%define variable '%s' passed to muscle_percent_define_flag_if"),
           variable);
 
   return result;
@@ -621,10 +621,10 @@ muscle_percent_define_check_values (char const * const *values)
             {
               location loc = muscle_percent_define_get_loc (*variablep);
               complain_at(loc,
-                          _("invalid value for %%define variable `%s': `%s'"),
+                          _("invalid value for %%define variable '%s': '%s'"),
                           *variablep, value);
               for (values = variablep + 1; *values; ++values)
-                complain_at (loc, _("accepted value: `%s'"), *values);
+                complain_at (loc, _("accepted value: '%s'"), *values);
             }
           else
             {
@@ -634,7 +634,7 @@ muscle_percent_define_check_values (char const * const *values)
           free (value);
         }
       else
-        fatal(_("undefined %%define variable `%s' passed to"
+        fatal(_("undefined %%define variable '%s' passed to"
                 " muscle_percent_define_check_values"),
               *variablep);
     }
