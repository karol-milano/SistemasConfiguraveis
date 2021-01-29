@@ -436,9 +436,9 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
           free (variable_tr);
           return;
         }
-      warn_at (variable_loc, _("%s `%s' redefined"),
-               "%define variable", variable);
-      warn_at (muscle_percent_define_get_loc (variable),
+      complain_at (variable_loc, _("%s `%s' redefined"),
+                   "%define variable", variable);
+      complain_at (muscle_percent_define_get_loc (variable),
                    _("previous definition"));
     }
 
