@@ -608,8 +608,8 @@ muscle_percent_define_check_values (char const * const *values)
                                quote (*variablep), quote_n (1, value));
               i += SUB_INDENT;
               for (values = variablep + 1; *values; ++values)
-                complain_indent (&loc, complaint, &i, _("accepted value: %s"),
-                                 quote (*values));
+                complain_indent (&loc, complaint | no_caret, &i,
+                                 _("accepted value: %s"), quote (*values));
             }
           else
             {
