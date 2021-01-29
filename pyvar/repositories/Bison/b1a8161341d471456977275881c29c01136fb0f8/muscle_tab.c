@@ -507,15 +507,44 @@ muscle_percent_define_default (char const *variable, char const *value)
 }
 
 void
-muscle_percent_define_invalid_value (char const *variable)
+muscle_percent_define_check_values (char const * const *values)
 {
-  char const *loc_name;
-  MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
-  complain_at(muscle_location_decode (loc_name),
-              _("invalid value for %%define variable `%s'"), variable);
+  for (; *values; ++values)
+    {
+      char const *variable = *values;
+      char const *name;
+      char const *loc_name;
+      char *value;
+
+      MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
+      MUSCLE_USER_NAME_CONVERT (loc_name, "percent_define_loc(", variable, ")");
+
+      value = muscle_string_decode (name);
+      if (value)
+        {
+          bool valid = false;
+          for (++values; *values; ++values)
+            {
+              if (0 == strcmp (value, *values))
+                {
+                  valid = true;
+                  while (*values)
+                    ++values;
+                  break;
+                }
+            }
+          if (!valid)
+            complain_at(muscle_location_decode (loc_name),
+                        _("invalid value for %%define variable `%s': `%s'"),
+                        variable, value);
+          free (value);
+        }
+      else
+        fatal(_("undefined %%define variable `%s' passed to muscle_percent_define_check_values"),
+              variable);
+    }
 }
 
-
 void
 muscle_percent_code_grow (char const *qualifier, location qualifier_loc,
                           char const *code, location code_loc)
