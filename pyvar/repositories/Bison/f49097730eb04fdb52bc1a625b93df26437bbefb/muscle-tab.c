@@ -575,35 +575,40 @@ muscle_percent_define_check_values (char const * const *values)
 {
   for (; *values; ++values)
     {
-      char const *variable = *values;
+      char const * const *variablep = values;
       char const *name;
       char *value;
 
-      MUSCLE_USER_NAME_CONVERT (name, "percent_define(", variable, ")");
+      MUSCLE_USER_NAME_CONVERT (name, "percent_define(", *variablep, ")");
 
       value = muscle_string_decode (name);
       if (value)
         {
-          bool valid = false;
           for (++values; *values; ++values)
             {
               if (0 == strcmp (value, *values))
-                {
-                  valid = true;
-                  while (*values)
-                    ++values;
-                  break;
-                }
+                break;
+            }
+          if (!*values)
+            {
+              location loc = muscle_percent_define_get_loc (*variablep);
+              complain_at(loc,
+                          _("invalid value for %%define variable `%s': `%s'"),
+                          *variablep, value);
+              for (values = variablep + 1; *values; ++values)
+                complain_at (loc, _("accepted value: `%s'"), *values);
+            }
+          else
+            {
+              while (*values)
+                ++values;
             }
-          if (!valid)
-            complain_at(muscle_percent_define_get_loc (variable),
-                        _("invalid value for %%define variable `%s': `%s'"),
-                        variable, value);
           free (value);
         }
       else
-        fatal(_("undefined %%define variable `%s' passed to muscle_percent_define_check_values"),
-              variable);
+        fatal(_("undefined %%define variable `%s' passed to"
+                " muscle_percent_define_check_values"),
+              *variablep);
     }
 }
 
