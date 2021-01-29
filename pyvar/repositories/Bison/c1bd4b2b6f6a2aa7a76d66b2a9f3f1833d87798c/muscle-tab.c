@@ -439,8 +439,8 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
         atoi (muscle_find_const (how_name));
       if (how_old == MUSCLE_PERCENT_DEFINE_F)
         return;
-      complain_at (variable_loc, _("%s `%s' redefined"),
-                   "%define variable", variable);
+      complain_at (variable_loc, _("%%define variable `%s' redefined"),
+                   variable);
       complain_at (muscle_percent_define_get_loc (variable),
                    _("previous definition"));
     }
