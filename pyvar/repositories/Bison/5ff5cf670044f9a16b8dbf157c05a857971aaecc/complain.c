@@ -115,10 +115,8 @@ complains (const location *loc, warnings flags, const char *message,
           error_message (loc, flags, _("warning"), message, args);
         }
     }
-  else
+  else if (warnings_flag & flags)
     {
-      if (! (warnings_flag & flags))
-        return;
       set_warning_issued ();
       error_message (loc, flags, _("warning"), message, args);
     }
