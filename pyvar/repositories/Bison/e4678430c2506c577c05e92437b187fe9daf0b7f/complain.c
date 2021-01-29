@@ -35,6 +35,17 @@ err_status complaint_status = status_none;
 
 bool warnings_are_errors = false;
 
+/** Whether -Werror/-Wno-error was applied to a warning.  */
+typedef enum
+  {
+    errority_unset = 0,     /** No explict status.  */
+    errority_disabled = 1,  /** Explictly disabled with -Wno-error=foo.  */
+    errority_enabled = 2    /** Explictly enabled with -Werror=foo. */
+  } errority;
+
+/** For each warning type, its errority.  */
+static errority errority_flag[warnings_size];
+
 /** Diagnostics severity.  */
 typedef enum
   {
@@ -103,32 +114,26 @@ warning_argmatch (char const *arg, size_t no, size_t err)
       no = !no;
     }
 
-  if (no)
-    {
-      size_t b;
-      for (b = 0; b < warnings_size; ++b)
-        if (value & 1 << b)
+  size_t b;
+  for (b = 0; b < warnings_size; ++b)
+    if (value & 1 << b)
+      {
+        if (err && no)
+          /* -Wno-error=foo.  */
+          errority_flag[b] = errority_disabled;
+        else if (err && !no)
           {
-            if (err)
-              {
-                /* -Wno-error=foo: if foo enabled as an error,
-                   make it a warning.  */
-                if (warnings_flag[b] == severity_error)
-                  warnings_flag[b] = severity_warning;
-              }
-            else
-              /* -Wno-foo.  */
-              warnings_flag[b] = severity_disabled;
+            /* -Werror=foo: enables -Wfoo. */
+            errority_flag[b] = errority_enabled;
+            warnings_flag[b] = severity_warning;
           }
-    }
-  else
-    {
-      size_t b;
-      for (b = 0; b < warnings_size; ++b)
-        if (value & 1 << b)
-          /* -Wfoo and -Werror=foo. */
-          warnings_flag[b] = err ? severity_error : severity_warning;
-    }
+        else if (no)
+          /* -Wno-foo.  */
+          warnings_flag[b] = severity_disabled;
+        else
+          /* -Wfoo. */
+          warnings_flag[b] = severity_warning;
+      }
 }
 
 /** Decode a comma-separated list of arguments from -W.
@@ -145,10 +150,7 @@ warnings_argmatch (char *args)
       if (STREQ (args, "error"))
         warnings_are_errors = true;
       else if (STREQ (args, "no-error"))
-        {
-          warnings_are_errors = false;
-          warning_argmatch ("no-error=everything", 3, 6);
-        }
+        warnings_are_errors = false;
       else
         {
           // The length of the possible 'no-' prefix: 3, or 0.
@@ -176,27 +178,46 @@ complain_init (void)
 
   size_t b;
   for (b = 0; b < warnings_size; ++b)
-    warnings_flag[b] = (1 << b & warnings_default
-                        ? severity_warning
-                        : severity_unset);
+    {
+      warnings_flag[b] = (1 << b & warnings_default
+                          ? severity_warning
+                          : severity_unset);
+      errority_flag[b] = errority_unset;
+    }
 }
 
+
+/* A diagnostic with FLAGS is about to be issued.  With what severity?
+   (severity_fatal, severity_error, severity_disabled, or
+   severity_warning.) */
+
 static severity
 warning_severity (warnings flags)
 {
   if (flags & fatal)
+    /* Diagnostics about fatal errors.  */
     return severity_fatal;
   else if (flags & complaint)
+    /* Diagnostics about errors.  */
     return severity_error;
   else
     {
+      /* Diagnostics about warnings.  */
       severity res = severity_disabled;
       size_t b;
       for (b = 0; b < warnings_size; ++b)
         if (flags & 1 << b)
-          res = res < warnings_flag[b] ? warnings_flag[b] : res;
-      if (res == severity_warning && warnings_are_errors)
-        res = severity_error;
+          {
+            res = res < warnings_flag[b] ? warnings_flag[b] : res;
+            /* If the diagnostic is enabled, and -Werror is enabled,
+               and -Wno-error=foo was not explicitly requested, this
+               is an error. */
+            if (res == severity_warning
+                && (errority_flag[b] == errority_enabled
+                    || (warnings_are_errors
+                        && errority_flag[b] != errority_disabled)))
+              res = severity_error;
+          }
       return res;
     }
 }
