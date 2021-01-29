@@ -525,7 +525,7 @@ muscle_percent_define_insert (char const *var, location variable_loc,
             = atoi (muscle_find_const (how_name));
           if (how_old == MUSCLE_PERCENT_DEFINE_F)
             goto end;
-          unsigned i = 0;
+          int i = 0;
           /* If assigning the same value, make it a warning.  */
           warnings warn = STREQ (value, current_value) ? Wother : complaint;
           complain_indent (&variable_loc, warn, &i,
@@ -739,7 +739,7 @@ muscle_percent_define_check_values (char const * const *values)
           if (!*values)
             {
               location loc = muscle_percent_define_get_loc (*variablep);
-              unsigned i = 0;
+              int i = 0;
               complain_indent (&loc, complaint, &i,
                                _("invalid value for %%define variable %s: %s"),
                                quote (*variablep), quote_n (1, value));
