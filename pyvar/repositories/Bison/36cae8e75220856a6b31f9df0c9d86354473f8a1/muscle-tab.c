@@ -520,21 +520,27 @@ muscle_percent_define_insert (char const *var, location variable_loc,
 
   /* Command-line options are processed before the grammar file.  */
   bool warned = false;
-  if (how == MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE
-      && muscle_find_const (name))
+  if (how == MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE)
     {
-      muscle_percent_define_how how_old = atoi (muscle_find_const (how_name));
-      if (how_old == MUSCLE_PERCENT_DEFINE_F)
-        goto end;
-      unsigned i = 0;
-      complain_indent (&variable_loc, complaint, &i,
-                       _("%%define variable %s redefined"),
-                       quote (variable));
-      i += SUB_INDENT;
-      location loc = muscle_percent_define_get_loc (variable);
-      complain_indent (&loc, complaint, &i, _("previous definition"));
-      fixits_register (&variable_loc, "");
-      warned = true;
+      char const *current_value = muscle_find_const (name);
+      if (current_value)
+        {
+          muscle_percent_define_how how_old
+            = atoi (muscle_find_const (how_name));
+          if (how_old == MUSCLE_PERCENT_DEFINE_F)
+            goto end;
+          unsigned i = 0;
+          /* If assigning the same value, make it a warning.  */
+          warnings warn = STREQ (value, current_value) ? Wother : complaint;
+          complain_indent (&variable_loc, warn, &i,
+                           _("%%define variable %s redefined"),
+                           quote (variable));
+          i += SUB_INDENT;
+          location loc = muscle_percent_define_get_loc (variable);
+          complain_indent (&loc, warn, &i, _("previous definition"));
+          fixits_register (&variable_loc, "");
+          warned = true;
+        }
     }
 
   if (!warned && old && upd)
