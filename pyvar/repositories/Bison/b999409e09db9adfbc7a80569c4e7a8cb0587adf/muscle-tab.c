@@ -442,13 +442,12 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
       unsigned i = 0;
       if (how_old == MUSCLE_PERCENT_DEFINE_F)
         return;
-      complain_at_indent (variable_loc, complaint, &i,
-                          _("%%define variable %s redefined"),
-                          quote (variable));
+      complain_indent (&variable_loc, complaint, &i,
+                       _("%%define variable %s redefined"),
+                       quote (variable));
       i += SUB_INDENT;
-      complain_at_indent (muscle_percent_define_get_loc (variable),
-                          complaint, &i,
-                          _("previous definition"));
+      location loc = muscle_percent_define_get_loc (variable);
+      complain_indent (&loc, complaint, &i, _("previous definition"));
     }
 
   MUSCLE_INSERT_STRING (name, value);
@@ -606,14 +605,13 @@ muscle_percent_define_check_values (char const * const *values)
             {
               unsigned i = 0;
               location loc = muscle_percent_define_get_loc (*variablep);
-              complain_at_indent
-                (loc, complaint, &i,
-                 _("invalid value for %%define variable %s: %s"),
-                 quote (*variablep), quote_n (1, value));
+              complain_indent (&loc, complaint, &i,
+                               _("invalid value for %%define variable %s: %s"),
+                               quote (*variablep), quote_n (1, value));
               i += SUB_INDENT;
               for (values = variablep + 1; *values; ++values)
-                complain_at_indent (loc, complaint, &i, _("accepted value: %s"),
-                                    quote (*values));
+                complain_indent (&loc, complaint, &i, _("accepted value: %s"),
+                                 quote (*values));
             }
           else
             {
