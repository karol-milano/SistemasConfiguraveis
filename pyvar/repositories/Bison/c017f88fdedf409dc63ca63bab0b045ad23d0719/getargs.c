@@ -74,8 +74,6 @@ const char *include = NULL;
  *                  If null, then activate all the flags.
  *  \param no       length of the potential "no-" prefix.
  *                  Can be 0 or 3. If 3, negate the action of the subargument.
- *  \param err      length of a potential "error=".
- *                  Can be 0 or 6. If 6, treat the subargument as a CATEGORY
  *
  *  If VALUE != 0 then KEY sets flags and no-KEY clears them.
  *  If VALUE == 0 then KEY clears all flags from \c all and no-KEY sets all
@@ -84,36 +82,27 @@ const char *include = NULL;
 static void
 flag_argmatch (const char *option,
                const char * const keys[], const int values[],
-               int all, int *flags, char *arg, size_t no, size_t err)
+               int all, int *flags, char *arg, size_t no)
 {
   int value = 0;
-  if (!err || arg[no + err++] != '\0')
-    value = XARGMATCH (option, arg + no + err, keys, values);
+  value = XARGMATCH (option, arg + no, keys, values);
 
   if (value)
     {
       if (no)
         *flags &= ~value;
       else
-        {
-          if (err)
-            warnings_flag |= value;
-          *flags |= value;
-        }
+        *flags |= value;
     }
   else
     {
-      /* With a simpler 'if (no)' version, -Werror means -Werror=all
-         (or rather, -Werror=no-none, but that syntax is invalid).
-         The difference is:
-         - Werror activates all errors, but not the warnings
-         - Werror=all activates errors, and all warnings */
-      if (no ? !err : err)
+      if (no)
         *flags |= all;
       else
         *flags &= ~all;
     }
 }
+
 /** Decode an option's set of keys.
  *
  *  \param option   option being decoded.
@@ -133,16 +122,14 @@ flags_argmatch (const char *option,
     for (args = strtok (args, ","); args; args = strtok (NULL, ","))
       {
         size_t no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
-        size_t err = STRPREFIX_LIT ("error", args + no) ? 5 : 0;
-
         flag_argmatch (option, keys,
-                       values, all, err ? &errors_flag : flags,
-                       args, no, err);
+                       values, all, flags, args, no);
       }
   else
     *flags |= all;
 }
 
+
 /** Decode a set of sub arguments.
  *
  *  \param FlagName  the flag familly to update.
@@ -240,6 +227,101 @@ ARGMATCH_VERIFY (trace_args, trace_types);
 | --warnings's handling.  |
 `------------------------*/
 
+/** Decode a single argument from -W.
+ *
+ *  \param option   option being decoded.
+ *  \param keys     array of valid subarguments.
+ *  \param values   array of corresponding (int) values.
+ *  \param all      the all value.
+ *  \param flags    the flags to update
+ *  \param arg      the subarguments to decode.
+ *                  If null, then activate all the flags.
+ *  \param no       length of the potential "no-" prefix.
+ *                  Can be 0 or 3. If 3, negate the action of the subargument.
+ *  \param err      length of a potential "error=".
+ *                  Can be 0 or 6. If 6, treat the subargument as a CATEGORY
+ *
+ *  If VALUE != 0 then KEY sets flags and no-KEY clears them.
+ *  If VALUE == 0 then KEY clears all flags from \c all and no-KEY sets all
+ *  flags from \c all.  Thus no-none = all and no-all = none.
+ */
+static void
+warning_argmatch (const char *option,
+                  const char * const keys[], const int values[],
+                  int all, int *flags, char *arg, size_t no, size_t err)
+{
+  int value = 0;
+  if (!err || arg[no + err++] != '\0')
+    value = XARGMATCH (option, arg + no + err, keys, values);
+
+  if (value)
+    {
+      if (no)
+        *flags &= ~value;
+      else
+        {
+          if (err)
+            warnings_flag |= value;
+          *flags |= value;
+        }
+    }
+  else
+    {
+      /* With a simpler 'if (no)' version, -Werror means -Werror=all
+         (or rather, -Werror=no-none, but that syntax is invalid).
+         The difference is:
+         - Werror activates all errors, but not the warnings
+         - Werror=all activates errors, and all warnings */
+      if (no ? !err : err)
+        *flags |= all;
+      else
+        *flags &= ~all;
+    }
+}
+
+/** Decode a comma-separated list of arguments from -W.
+ *
+ *  \param option   option being decoded.
+ *  \param keys     array of valid subarguments.
+ *  \param values   array of corresponding (int) values.
+ *  \param all      the all value.
+ *  \param flags    the flags to update
+ *  \param args     comma separated list of effective subarguments to decode.
+ *                  If 0, then activate all the flags.
+ */
+static void
+warnings_argmatch (const char *option,
+                   const char * const keys[], const int values[],
+                   int all, int *flags, char *args)
+{
+  if (args)
+    for (args = strtok (args, ","); args; args = strtok (NULL, ","))
+      {
+        size_t no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
+        size_t err = STRPREFIX_LIT ("error", args + no) ? 5 : 0;
+
+        warning_argmatch (option, keys,
+                          values, all, err ? &errors_flag : flags,
+                          args, no, err);
+      }
+  else
+    *flags |= all;
+}
+
+/** Decode a set of sub arguments.
+ *
+ *  \param FlagName  the flag familly to update.
+ *  \param Args      the effective sub arguments to decode.
+ *  \param All       the "all" value.
+ *
+ *  \arg FlagName_args   the list of keys.
+ *  \arg FlagName_types  the list of values.
+ *  \arg FlagName_flag   the flag to update.
+ */
+#define WARNINGS_ARGMATCH(FlagName, Args, All)                          \
+  warnings_argmatch ("--" #FlagName, FlagName ## _args, FlagName ## _types, \
+                     All, &FlagName ## _flag, Args)
+
 const char * const warnings_args[] =
 {
   "none",
@@ -666,7 +748,7 @@ getargs (int argc, char *argv[])
         break;
 
       case 'W':
-        FLAGS_ARGMATCH (warnings, optarg, Wall);
+        WARNINGS_ARGMATCH (warnings, optarg, Wall);
         break;
 
       case 'b':
