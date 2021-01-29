@@ -30,27 +30,62 @@
 #include "getargs.h"
 #include "quote.h"
 
-warnings warnings_flag =
-  Wconflicts_sr | Wconflicts_rr | Wdeprecated | Wother;
+err_status complaint_status = status_none;
 
-warnings errors_flag;
+bool warnings_are_errors = false;
+severity warnings_flag[warnings_size];
 
-err_status complaint_status = status_none;
 static unsigned *indent_ptr = 0;
 
+void
+complain_init (void)
+{
+  warnings warnings_default =
+    Wconflicts_sr | Wconflicts_rr | Wdeprecated | Wother;
+
+  size_t b;
+  for (b = 0; b < warnings_size; ++b)
+    warnings_flag[b] = (1 << b & warnings_default
+                        ? severity_warning
+                        : severity_unset);
+}
+
+static severity
+warning_severity (warnings flags)
+{
+  if (flags & fatal)
+    return severity_fatal;
+  else if (flags & complaint)
+    return severity_error;
+  else
+    {
+      severity res = severity_disabled;
+      size_t b;
+      for (b = 0; b < warnings_size; ++b)
+        if (flags & 1 << b)
+          res = res < warnings_flag[b] ? warnings_flag[b] : res;
+      if (res == severity_warning && warnings_are_errors)
+        res = severity_error;
+      return res;
+    }
+}
+
+
 /** Display a "[-Wyacc]" like message on \a f.  */
 
 static void
 warnings_print_categories (warnings warn_flags, FILE *f)
 {
   /* Display only the first match, the second is "-Wall".  */
-  int i;
+  size_t i;
   for (i = 0; warnings_args[i]; ++i)
     if (warn_flags & warnings_types[i])
       {
-        bool err = warn_flags & errors_flag;
-        fprintf (f, " [-W%s%s]", err ? "error=" : "" , warnings_args[i]);
-        break;
+        severity s = warning_severity (warnings_types[i]);
+        fprintf (f, " [-W%s%s]",
+                 s == severity_error ? "error=" : "",
+                 warnings_args[i]);
+        return;
       }
 }
 
@@ -109,23 +144,28 @@ error_message (const location *loc, warnings flags, const char *prefix,
   fflush (stderr);
 }
 
-/** Raise a complaint. That can be a fatal error, a complaint or just a
+/** Raise a complaint. That can be a fatal error, an error or just a
     warning.  */
-static inline void
+
+static void
 complains (const location *loc, warnings flags, const char *message,
            va_list args)
 {
-  const char* prefix =
-    flags & fatal ? _("fatal error")
-    : flags & (errors_flag | complaint) ? _("error")
-    : _("warning");
-
+  severity s = warning_severity (flags);
   if ((flags & complaint) && complaint_status < status_complaint)
     complaint_status = status_complaint;
-  else if ((flags & (warnings_flag & errors_flag)) && ! complaint_status)
-    complaint_status = status_warning_as_error;
-  if (flags & (warnings_flag | fatal | complaint))
-    error_message (loc, flags, prefix, message, args);
+
+  if (severity_warning <= s)
+    {
+      const char* prefix =
+        s == severity_fatal ? _("fatal error")
+        : s == severity_error ? _("error")
+        : _("warning");
+      if (severity_error <= s && ! complaint_status)
+        complaint_status = status_warning_as_error;
+      error_message (loc, flags, prefix, message, args);
+    }
+
   if (flags & fatal)
     exit (EXIT_FAILURE);
 }
@@ -176,7 +216,6 @@ complain_args (location const *loc, warnings w, unsigned *indent,
     complain (loc, fatal, "too many arguments for complains");
     break;
   }
-
 }
 
 void
