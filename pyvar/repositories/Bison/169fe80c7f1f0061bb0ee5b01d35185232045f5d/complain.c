@@ -394,7 +394,9 @@ deprecated_directive (location const *loc, char const *old, char const *upd)
     complain (loc, Wdeprecated,
               _("deprecated directive: %s, use %s"),
               quote (old), quote_n (1, upd));
-  fixits_register (loc, upd);
+  /* Register updates only if -Wdeprecated is enabled.  */
+  if (warnings_flag[warning_deprecated] != severity_disabled)
+    fixits_register (loc, upd);
 }
 
 void
