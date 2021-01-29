@@ -229,48 +229,55 @@ ARGMATCH_VERIFY (trace_args, trace_types);
 
 /** Decode a single argument from -W.
  *
- *  \param flags    the flags to update
  *  \param arg      the subarguments to decode.
  *                  If null, then activate all the flags.
  *  \param no       length of the potential "no-" prefix.
  *                  Can be 0 or 3. If 3, negate the action of the subargument.
  *  \param err      length of a potential "error=".
- *                  Can be 0 or 5. If 5, treat the subargument as a CATEGORY.
+ *                  Can be 0 or 6. If 6, treat the subargument as a CATEGORY.
  *
  *  If VALUE != 0 then KEY sets flags and no-KEY clears them.
  *  If VALUE == 0 then KEY clears all flags from \c all and no-KEY sets all
  *  flags from \c all.  Thus no-none = all and no-all = none.
  */
 static void
-warning_argmatch (int *flags, char *arg, size_t no, size_t err)
+warning_argmatch (char const *arg, size_t no, size_t err)
 {
-  int value = 0;
-  if (!err || arg[no + err++] != '\0')
-    value = XARGMATCH ("--warning", arg + no + err,
-                       warnings_args, warnings_types);
+  int value = XARGMATCH ("--warning", arg + no + err,
+                         warnings_args, warnings_types);
 
-  if (value)
+  /* -Wnone == -Wno-all, and -Wno-none == -Wall.  */
+  if (!value)
     {
-      if (no)
-        *flags &= ~value;
-      else
-        {
-          if (err)
-            warnings_flag |= value;
-          *flags |= value;
-        }
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
     }
   else
     {
-      /* With a simpler 'if (no)' version, -Werror means -Werror=all
-         (or rather, -Werror=no-none, but that syntax is invalid).
-         The difference is:
-         - Werror activates all errors, but not the warnings
-         - Werror=all activates errors, and all warnings */
-      if (no ? !err : err)
-        *flags |= Wall;
-      else
-        *flags &= ~Wall;
+      size_t b;
+      for (b = 0; b < warnings_size; ++b)
+        if (value & 1 << b)
+          /* -Wfoo and -Werror=foo. */
+          warnings_flag[b] = err ? severity_error : severity_warning;
     }
 }
 
@@ -284,15 +291,22 @@ warnings_argmatch (char *args)
 {
   if (args)
     for (args = strtok (args, ","); args; args = strtok (NULL, ","))
-      {
-        size_t no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
-        size_t err = STRPREFIX_LIT ("error", args + no) ? 5 : 0;
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
 
-        warning_argmatch (err ? &errors_flag : &warnings_flag,
-                          args, no, err);
-      }
+          warning_argmatch (args, no, err);
+        }
   else
-    warnings_flag |= Wall;
+    warning_argmatch ("all", 0, 0);
 }
 
 const char * const warnings_args[] =
@@ -790,8 +804,7 @@ getargs (int argc, char *argv[])
         break;
 
       case 'y':
-        warnings_flag |= Wyacc;
-        errors_flag |= Wyacc;
+        warnings_flag[warning_yacc] = severity_error;
         yacc_flag = true;
         break;
 
