@@ -421,8 +421,10 @@ duplicate_rule_directive (char const *directive,
                           location first, location second)
 {
   unsigned i = 0;
-  complain_indent (&second, complaint, &i, _("only one %s allowed per rule"), directive);
+  complain_indent (&second, complaint, &i,
+                   _("only one %s allowed per rule"), directive);
   i += SUB_INDENT;
-  complain_indent (&first, complaint, &i, _("previous declaration"));
+  complain_indent (&first, complaint, &i,
+                   _("previous declaration"));
   fixits_register (&second, "");
 }
