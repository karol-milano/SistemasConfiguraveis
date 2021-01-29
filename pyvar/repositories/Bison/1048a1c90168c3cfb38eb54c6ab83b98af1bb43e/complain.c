@@ -57,7 +57,9 @@ warnings_print_categories (warnings warn_flags)
       for (i = 0; i < ARRAY_CARDINALITY (warn_names); ++i)
         if (warn_flags & 1 << i)
           {
-            fprintf (stderr, "%s-W%s", any ? ", " : " [", warn_names[i]);
+            bool err = warn_flags & errors_flag;
+            fprintf (stderr, "%s-W", any ? ", " : " [");
+            fprintf (stderr, "%s%s", err ? "error=" : "" , warn_names[i]);
             any = true;
           }
       if (any)
@@ -121,39 +123,22 @@ error_message (const location *loc, warnings flags, const char *prefix,
 static inline void
 complains (const location *loc, warnings flags, const char *message,
            va_list args)
+
 {
-  if (flags & complaint)
-    {
-      error_message (loc, complaint,
-                     indent_ptr && *indent_ptr ? NULL : _("error"),
-                     message, args);
-      complaint_issued = true;
-    }
-  else if (flags & fatal)
+  if (flags & fatal)
     {
-      error_message (loc, fatal, _("fatal error"), message, args);
-      exit (EXIT_FAILURE);
-    }
-  else if (flags & Wyacc)
-    {
-      if (yacc_flag)
-        {
-          error_message (loc, flags, NULL, message, args);
-          complaint_issued = true;
-        }
-      else if (warnings_flag & Wyacc)
-        {
-          set_warning_issued (Wyacc);
-          error_message (loc, flags,
-                         indent_ptr && *indent_ptr ? NULL : _("warning"),
-                         message, args);
-        }
+       error_message (loc, fatal, _("fatal error"), message, args);
+       exit (EXIT_FAILURE);
     }
-  else if (warnings_flag & flags)
+  else if (flags & (complaint | warnings_flag))
     {
+      const char* prefix =
+        flags & (errors_flag | complaint) ? _("error") : _("warning");
+      if (flags & complaint)
+        complaint_issued = true;
       set_warning_issued (flags);
       error_message (loc, flags,
-                     indent_ptr && *indent_ptr ? NULL : _("warning"),
+                     indent_ptr && *indent_ptr ? NULL : prefix,
                      message, args);
     }
 }
