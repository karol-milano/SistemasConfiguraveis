@@ -525,15 +525,13 @@ muscle_percent_define_insert (char const *var, location variable_loc,
             = atoi (muscle_find_const (how_name));
           if (how_old == MUSCLE_PERCENT_DEFINE_F)
             goto end;
-          int i = 0;
           /* If assigning the same value, make it a warning.  */
           warnings warn = STREQ (value, current_value) ? Wother : complaint;
-          complain_indent (&variable_loc, warn, &i,
-                           _("%%define variable %s redefined"),
-                           quote (variable));
-          i += SUB_INDENT;
+          complain (&variable_loc, warn,
+                    _("%%define variable %s redefined"),
+                    quote (variable));
           location loc = muscle_percent_define_get_loc (variable);
-          complain_indent (&loc, warn, &i, _("previous definition"));
+          subcomplain (&loc, warn, _("previous definition"));
           fixits_register (&variable_loc, "");
           warned = true;
         }
@@ -739,14 +737,12 @@ muscle_percent_define_check_values (char const * const *values)
           if (!*values)
             {
               location loc = muscle_percent_define_get_loc (*variablep);
-              int i = 0;
-              complain_indent (&loc, complaint, &i,
-                               _("invalid value for %%define variable %s: %s"),
-                               quote (*variablep), quote_n (1, value));
-              i += SUB_INDENT;
+              complain (&loc, complaint,
+                        _("invalid value for %%define variable %s: %s"),
+                        quote (*variablep), quote_n (1, value));
               for (values = variablep + 1; *values; ++values)
-                complain_indent (&loc, complaint | no_caret | silent, &i,
-                                 _("accepted value: %s"), quote (*values));
+                subcomplain (&loc, complaint | no_caret | silent,
+                             _("accepted value: %s"), quote (*values));
             }
           else
             while (*values)
