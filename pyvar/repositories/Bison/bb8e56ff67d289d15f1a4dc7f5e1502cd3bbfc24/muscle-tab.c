@@ -407,9 +407,9 @@ muscle_percent_variable_update (char const *variable, location variable_loc)
     if (STREQ (conversion[i].obsolete, variable))
       {
         res = conversion[i].updated;
-        complain_at (variable_loc, Wdeprecated,
-                     _("deprecated %%define variable name: %s, use %s"),
-                     quote (variable), quote_n (1, res));
+        complain (&variable_loc, Wdeprecated,
+                  _("deprecated %%define variable name: %s, use %s"),
+                  quote (variable), quote_n (1, res));
         break;
       }
   return res;
@@ -503,7 +503,7 @@ muscle_percent_define_get_loc (char const *variable)
 {
   char const *loc_name = UNIQSTR_CONCAT ("percent_define_loc(", variable, ")");
   if (!muscle_find_const (loc_name))
-    complain (fatal, _("%s: undefined %%define variable %s"),
+    complain (NULL, fatal, _("%s: undefined %%define variable %s"),
               "muscle_percent_define_get_loc", quote (variable));
   return location_decode (loc_name);
 }
@@ -515,7 +515,7 @@ muscle_percent_define_get_syncline (char const *variable)
     UNIQSTR_CONCAT ("percent_define_syncline(", variable, ")");
   char const *syncline = muscle_find_const (syncline_name);
   if (!syncline)
-    complain (fatal, _("%s: undefined %%define variable %s"),
+    complain (NULL, fatal, _("%s: undefined %%define variable %s"),
               "muscle_percent_define_get_syncline", quote (variable));
   return syncline;
 }
@@ -554,14 +554,14 @@ muscle_percent_define_flag_if (char const *variable)
         {
           muscle_insert (invalid_boolean_name, "");
           location loc = muscle_percent_define_get_loc (variable);
-          complain_at (loc, complaint,
-                       _("invalid value for %%define Boolean variable %s"),
-                       quote (variable));
+          complain (&loc, complaint,
+                    _("invalid value for %%define Boolean variable %s"),
+                    quote (variable));
         }
       free (value);
     }
   else
-    complain (fatal, _("%s: undefined %%define variable %s"),
+    complain (NULL, fatal, _("%s: undefined %%define variable %s"),
               "muscle_percent_define_flag", quote (variable));
 
   return result;
@@ -623,7 +623,7 @@ muscle_percent_define_check_values (char const * const *values)
           free (value);
         }
       else
-        complain (fatal, _("%s: undefined %%define variable %s"),
+        complain (NULL, fatal, _("%s: undefined %%define variable %s"),
                   "muscle_percent_define_check_values", quote (*variablep));
     }
 }
