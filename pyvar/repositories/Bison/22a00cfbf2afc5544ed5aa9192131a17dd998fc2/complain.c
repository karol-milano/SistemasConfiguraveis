@@ -521,7 +521,7 @@ deprecated_directive (location const *loc, char const *old, char const *upd)
               _("deprecated directive: %s, use %s"),
               quote (old), quote_n (1, upd));
   /* Register updates only if -Wdeprecated is enabled.  */
-  if (warnings_flag[warning_deprecated] != severity_disabled)
+  if (warning_is_enabled (Wdeprecated))
     fixits_register (loc, upd);
 }
 
