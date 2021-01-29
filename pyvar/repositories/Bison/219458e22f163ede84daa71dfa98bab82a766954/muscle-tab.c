@@ -664,7 +664,7 @@ muscle_percent_define_check_values (char const * const *values)
                                quote (*variablep), quote_n (1, value));
               i += SUB_INDENT;
               for (values = variablep + 1; *values; ++values)
-                complain_indent (&loc, complaint | no_caret, &i,
+                complain_indent (&loc, complaint | no_caret | silent, &i,
                                  _("accepted value: %s"), quote (*values));
             }
           else
