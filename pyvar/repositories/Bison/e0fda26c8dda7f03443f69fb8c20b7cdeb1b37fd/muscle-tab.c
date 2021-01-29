@@ -425,8 +425,8 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
           free (variable_tr);
           return;
         }
-      complain_at (variable_loc, _("%s `%s' redefined"),
-                   "%define variable", variable);
+      complain_at (variable_loc, _("%%define variable `%s' redefined"),
+                   variable);
       complain_at (muscle_percent_define_get_loc (variable),
                    _("previous definition"));
     }
