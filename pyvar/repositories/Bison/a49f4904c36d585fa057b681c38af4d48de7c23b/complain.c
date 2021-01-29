@@ -130,7 +130,7 @@ complains (const location *loc, warnings flags, const char *message,
        error_message (loc, fatal, _("fatal error"), message, args);
        exit (EXIT_FAILURE);
     }
-  else if (flags & (complaint | warnings_flag))
+  else if (flags & (complaint | warnings_flag | silent))
     {
       const char* prefix =
         flags & (errors_flag | complaint) ? _("error") : _("warning");
