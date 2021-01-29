@@ -400,11 +400,10 @@ deprecated_directive (location const *loc, char const *old, char const *upd)
 }
 
 void
-duplicate_directive (char const *directive,
-                     location first, location second)
+duplicate_rule_directive (char const *directive,
+                          location first, location second)
 {
-  unsigned i = 0;
   complain (&second, complaint, _("only one %s allowed per rule"), directive);
-  i += SUB_INDENT;
+  unsigned i = SUB_INDENT;
   complain_indent (&first, complaint, &i, _("previous declaration"));
 }
