@@ -407,7 +407,7 @@ duplicate_directive (char const *directive,
   if (feature_flag & feature_caret)
     complain_indent (&second, Wother, &i, _("duplicate directive"));
   else
-    complain_indent (&second, Wother, &i, _("duplicate directive: %s"), directive);
+    complain_indent (&second, Wother, &i, _("duplicate directive: %s"), quote (directive));
   i += SUB_INDENT;
   complain_indent (&first, Wother, &i, _("previous declaration"));
   fixits_register (&second, "");
