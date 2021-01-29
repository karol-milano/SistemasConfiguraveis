@@ -365,3 +365,13 @@ deprecated_directive (location const *loc, char const *old, char const *upd)
               _("deprecated directive: %s, use %s"),
               quote (old), quote_n (1, upd));
 }
+
+void
+duplicate_directive (char const *directive,
+                     location first, location second)
+{
+  unsigned i = 0;
+  complain (&second, complaint, _("only one %s allowed per rule"), directive);
+  i += SUB_INDENT;
+  complain_indent (&first, complaint, &i, _("previous declaration"));
+}
