@@ -22,6 +22,7 @@
 #include <config.h>
 #include "system.h"
 
+#include <argmatch.h>
 #include <stdarg.h>
 #include <progname.h>
 
@@ -33,10 +34,133 @@
 err_status complaint_status = status_none;
 
 bool warnings_are_errors = false;
-severity warnings_flag[warnings_size];
+
+/** Diagnostics severity.  */
+typedef enum
+  {
+    severity_disabled = 0,
+    severity_unset = 1,
+    severity_warning = 2,
+    severity_error = 3,
+    severity_fatal = 4
+  } severity;
+
+
+/** For each warning type, its severity.  */
+static severity warnings_flag[warnings_size];
 
 static unsigned *indent_ptr = 0;
 
+/*------------------------.
+| --warnings's handling.  |
+`------------------------*/
+
+static const char * const warnings_args[] =
+{
+  "none",
+  "midrule-values",
+  "yacc",
+  "conflicts-sr",
+  "conflicts-rr",
+  "deprecated",
+  "precedence",
+  "other",
+  "all",
+  "error",
+  0
+};
+
+static const int warnings_types[] =
+{
+  Wnone,
+  Wmidrule_values,
+  Wyacc,
+  Wconflicts_sr,
+  Wconflicts_rr,
+  Wdeprecated,
+  Wprecedence,
+  Wother,
+  Wall,
+  Werror
+};
+
+ARGMATCH_VERIFY (warnings_args, warnings_types);
+
+void
+warning_argmatch (char const *arg, size_t no, size_t err)
+{
+  int value = XARGMATCH ("--warning", arg + no + err,
+                         warnings_args, warnings_types);
+
+  /* -Wnone == -Wno-all, and -Wno-none == -Wall.  */
+  if (!value)
+    {
+      value = Wall;
+      no = !no;
+    }
+
+  if (no)
+    {
+      size_t b;
+      for (b = 0; b < warnings_size; ++b)
+        if (value & 1 << b)
+          {
+            if (err)
+              {
+                /* -Wno-error=foo: if foo enabled as an error,
+                   make it a warning.  */
+                if (warnings_flag[b] == severity_error)
+                  warnings_flag[b] = severity_warning;
+              }
+            else
+              /* -Wno-foo.  */
+              warnings_flag[b] = severity_disabled;
+          }
+    }
+  else
+    {
+      size_t b;
+      for (b = 0; b < warnings_size; ++b)
+        if (value & 1 << b)
+          /* -Wfoo and -Werror=foo. */
+          warnings_flag[b] = err ? severity_error : severity_warning;
+    }
+}
+
+/** Decode a comma-separated list of arguments from -W.
+ *
+ *  \param args     comma separated list of effective subarguments to decode.
+ *                  If 0, then activate all the flags.
+ */
+
+void
+warnings_argmatch (char *args)
+{
+  if (args)
+    for (args = strtok (args, ","); args; args = strtok (NULL, ","))
+      if (STREQ (args, "error"))
+        warnings_are_errors = true;
+      else if (STREQ (args, "no-error"))
+        {
+          warnings_are_errors = false;
+          warning_argmatch ("no-error=all", 3, 6);
+        }
+      else
+        {
+          size_t no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
+          size_t err = STRPREFIX_LIT ("error=", args + no) ? 6 : 0;
+
+          warning_argmatch (args, no, err);
+        }
+  else
+    warning_argmatch ("all", 0, 0);
+}
+
+
+/*-----------.
+| complain.  |
+`-----------*/
+
 void
 complain_init (void)
 {
