@@ -460,12 +460,15 @@ muscle_percent_define_flag_if (char const *variable)
   char const *name;
   char const *loc_name;
   char const *usage_name;
+  char const *invalid_boolean_name;
   bool result = false;
 
   MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
   MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
   MUSCLE_USER_NAME_CONVERT (usage_name, "percent_define_bison_variables(",
                             variable, ")");
+  MUSCLE_USER_NAME_CONVERT (invalid_boolean_name,
+                            "percent_define_invalid_boolean(", variable, ")");
 
   if (muscle_percent_define_ifdef (variable))
     {
@@ -474,10 +477,13 @@ muscle_percent_define_flag_if (char const *variable)
         result = true;
       else if (0 == strcmp (value, "false"))
         result = false;
-      else if (!muscle_find_const (usage_name))
-        complain_at(muscle_location_decode (loc_name),
-                    _("invalid value for %%define boolean variable `%s'"),
-                    variable);
+      else if (!muscle_find_const (invalid_boolean_name))
+        {
+          muscle_insert (invalid_boolean_name, "");
+          complain_at(muscle_location_decode (loc_name),
+                      _("invalid value for %%define boolean variable `%s'"),
+                      variable);
+        }
       free (value);
     }
   else
