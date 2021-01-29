@@ -593,12 +593,15 @@ muscle_percent_define_check_values (char const * const *values)
             }
           if (!*values)
             {
+              unsigned i = 0;
               location loc = muscle_percent_define_get_loc (*variablep);
-              complain_at(loc,
-                          _("invalid value for %%define variable %s: %s"),
-                          quote (*variablep), quote_n (1, value));
+              complain_at_indent (loc, &i,
+                                _("invalid value for %%define variable %s: %s"),
+                                  quote (*variablep), quote_n (1, value));
+              i += SUB_INDENT;
               for (values = variablep + 1; *values; ++values)
-                complain_at (loc, _("accepted value: %s"), quote (*values));
+                complain_at_indent (loc, &i, _("accepted value: %s"),
+                                    quote (*values));
             }
           else
             {
