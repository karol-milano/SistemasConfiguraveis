@@ -439,10 +439,10 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
         atoi (muscle_find_const (how_name));
       if (how_old == MUSCLE_PERCENT_DEFINE_F)
         return;
-      complain_at (variable_loc, _("%%define variable %s redefined"),
+      complain_at (variable_loc, complaint, _("%%define variable %s redefined"),
                    quote (variable));
-      complain_at (muscle_percent_define_get_loc (variable),
-                   _("previous definition"));
+      location loc = muscle_percent_define_get_loc (variable);
+      complain_at (loc, complaint, _("previous definition"));
     }
 
   MUSCLE_INSERT_STRING (name, value);
@@ -503,7 +503,7 @@ muscle_percent_define_get_loc (char const *variable)
   char const *loc_name;
   loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
   if (!muscle_find_const (loc_name))
-    fatal(_("%s: undefined %%define variable %s"),
+    complain (fatal, _("%s: undefined %%define variable %s"),
           "muscle_percent_define_get_loc", quote (variable));
   return muscle_location_decode (loc_name);
 }
@@ -517,7 +517,7 @@ muscle_percent_define_get_syncline (char const *variable)
     UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
   syncline = muscle_find_const (syncline_name);
   if (!syncline)
-    fatal(_("%s: undefined %%define variable %s"),
+    complain (fatal, _("%s: undefined %%define variable %s"),
           "muscle_percent_define_get_syncline", quote (variable));
   return syncline;
 }
@@ -562,15 +562,16 @@ muscle_percent_define_flag_if (char const *variable)
       else if (!muscle_find_const (invalid_boolean_name))
         {
           muscle_insert (invalid_boolean_name, "");
-          complain_at(muscle_percent_define_get_loc (variable),
-                      _("invalid value for %%define Boolean variable %s"),
-                      quote (variable));
+          location loc = muscle_percent_define_get_loc (variable);
+          complain_at (loc, complaint,
+                       _("invalid value for %%define Boolean variable %s"),
+                       quote (variable));
         }
       free (value);
     }
   else
-    fatal(_("%s: undefined %%define variable %s"),
-          "muscle_percent_define_flag", quote (variable));
+    complain (fatal, _("%s: undefined %%define variable %s"),
+              "muscle_percent_define_flag", quote (variable));
 
   return result;
 }
@@ -620,11 +621,12 @@ muscle_percent_define_check_values (char const * const *values)
           if (!*values)
             {
               location loc = muscle_percent_define_get_loc (*variablep);
-              complain_at(loc,
-                          _("invalid value for %%define variable %s: %s"),
-                          quote (*variablep), quote_n (1, value));
+              complain_at (loc, complaint,
+                           _("invalid value for %%define variable %s: %s"),
+                           quote (*variablep), quote_n (1, value));
               for (values = variablep + 1; *values; ++values)
-                complain_at (loc, _("accepted value: %s"), quote (*values));
+                complain_at (loc, complaint, _("accepted value: %s"),
+                             quote (*values));
             }
           else
             {
@@ -634,8 +636,8 @@ muscle_percent_define_check_values (char const * const *values)
           free (value);
         }
       else
-        fatal (_("%s: undefined %%define variable %s"),
-               "muscle_percent_define_check_values", quote (*variablep));
+        complain (fatal, _("%s: undefined %%define variable %s"),
+                  "muscle_percent_define_check_values", quote (*variablep));
     }
 }
 
