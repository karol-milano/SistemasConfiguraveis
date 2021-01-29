@@ -546,17 +546,16 @@ bison_directive (location const *loc, char const *directive)
 void
 deprecated_directive (location const *loc, char const *old, char const *upd)
 {
-  if (feature_flag & feature_caret)
-    complain (loc, Wdeprecated,
-              _("deprecated directive, use %s"),
-              quote_n (1, upd));
-  else
-    complain (loc, Wdeprecated,
-              _("deprecated directive: %s, use %s"),
-              quote (old), quote_n (1, upd));
-  /* Register updates only if -Wdeprecated is enabled.  */
   if (warning_is_enabled (Wdeprecated))
-    fixits_register (loc, upd);
+    {
+      complain (loc, Wdeprecated,
+                _("deprecated directive: %s, use %s"),
+                quote (old), quote_n (1, upd));
+      if (feature_flag & feature_caret)
+        location_caret_suggestion (*loc, upd, stderr);
+      /* Register updates only if -Wdeprecated is enabled.  */
+      fixits_register (loc, upd);
+    }
 }
 
 void
