@@ -421,4 +421,5 @@ duplicate_rule_directive (char const *directive,
   complain_indent (&second, complaint, &i, _("only one %s allowed per rule"), directive);
   i += SUB_INDENT;
   complain_indent (&first, complaint, &i, _("previous declaration"));
+  fixits_register (&second, "");
 }
