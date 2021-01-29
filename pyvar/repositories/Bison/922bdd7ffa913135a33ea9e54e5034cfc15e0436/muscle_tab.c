@@ -479,7 +479,7 @@ muscle_percent_define_flag_if (char const *variable)
         {
           muscle_insert (invalid_boolean_name, "");
           complain_at(muscle_location_decode (loc_name),
-                      _("invalid value for %%define boolean variable `%s'"),
+                      _("invalid value for %%define Boolean variable `%s'"),
                       variable);
         }
       free (value);
