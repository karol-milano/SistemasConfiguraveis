@@ -403,11 +403,12 @@ void
 duplicate_directive (char const *directive,
                      location first, location second)
 {
+  unsigned i = 0;
   if (feature_flag & feature_caret)
-    complain (&second, Wother, _("duplicate directive"));
+    complain_indent (&second, Wother, &i, _("duplicate directive"));
   else
-    complain (&second, Wother, _("duplicate directive: %s"), directive);
-  unsigned i = SUB_INDENT;
+    complain_indent (&second, Wother, &i, _("duplicate directive: %s"), directive);
+  i += SUB_INDENT;
   complain_indent (&first, complaint, &i, _("previous declaration"));
   fixits_register (&second, "");
 }
@@ -416,7 +417,8 @@ void
 duplicate_rule_directive (char const *directive,
                           location first, location second)
 {
-  complain (&second, complaint, _("only one %s allowed per rule"), directive);
-  unsigned i = SUB_INDENT;
+  unsigned i = 0;
+  complain_indent (&second, complaint, &i, _("only one %s allowed per rule"), directive);
+  i += SUB_INDENT;
   complain_indent (&first, complaint, &i, _("previous declaration"));
 }
