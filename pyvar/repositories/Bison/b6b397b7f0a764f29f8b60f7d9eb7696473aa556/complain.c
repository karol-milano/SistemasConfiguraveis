@@ -399,6 +399,19 @@ deprecated_directive (location const *loc, char const *old, char const *upd)
     fixits_register (loc, upd);
 }
 
+void
+duplicate_directive (char const *directive,
+                     location first, location second)
+{
+  if (feature_flag & feature_caret)
+    complain (&second, Wother, _("duplicate directive"));
+  else
+    complain (&second, Wother, _("duplicate directive: %s"), directive);
+  unsigned i = SUB_INDENT;
+  complain_indent (&first, complaint, &i, _("previous declaration"));
+  fixits_register (&second, "");
+}
+
 void
 duplicate_rule_directive (char const *directive,
                           location first, location second)
