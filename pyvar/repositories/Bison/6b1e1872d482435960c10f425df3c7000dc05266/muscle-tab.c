@@ -426,6 +426,7 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
   if (how == MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE
       && muscle_find_const (name))
     {
+      unsigned i = 0;
       muscle_percent_define_how how_old =
         atoi (muscle_find_const (how_name));
       if (how_old == MUSCLE_PERCENT_DEFINE_F)
@@ -433,10 +434,11 @@ muscle_percent_define_insert (char const *variable, location variable_loc,
           free (variable_tr);
           return;
         }
-      complain_at (variable_loc, _("%%define variable %s redefined"),
-                   quote (variable));
-      complain_at (muscle_percent_define_get_loc (variable),
-                   _("previous definition"));
+      complain_at_indent (variable_loc, &i,
+                          _("%%define variable %s redefined"), quote (variable));
+      i += SUB_INDENT;
+      complain_at_indent (muscle_percent_define_get_loc (variable), &i,
+                          _("previous definition"));
     }
 
   MUSCLE_INSERT_STRING (name, value);
