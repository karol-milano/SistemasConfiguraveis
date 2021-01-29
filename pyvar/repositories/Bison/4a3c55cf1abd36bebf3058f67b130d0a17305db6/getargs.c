@@ -229,30 +229,25 @@ ARGMATCH_VERIFY (trace_args, trace_types);
 
 /** Decode a single argument from -W.
  *
- *  \param option   option being decoded.
- *  \param keys     array of valid subarguments.
- *  \param values   array of corresponding (int) values.
- *  \param all      the all value.
  *  \param flags    the flags to update
  *  \param arg      the subarguments to decode.
  *                  If null, then activate all the flags.
  *  \param no       length of the potential "no-" prefix.
  *                  Can be 0 or 3. If 3, negate the action of the subargument.
  *  \param err      length of a potential "error=".
- *                  Can be 0 or 6. If 6, treat the subargument as a CATEGORY
+ *                  Can be 0 or 5. If 5, treat the subargument as a CATEGORY.
  *
  *  If VALUE != 0 then KEY sets flags and no-KEY clears them.
  *  If VALUE == 0 then KEY clears all flags from \c all and no-KEY sets all
  *  flags from \c all.  Thus no-none = all and no-all = none.
  */
 static void
-warning_argmatch (const char *option,
-                  const char * const keys[], const int values[],
-                  int all, int *flags, char *arg, size_t no, size_t err)
+warning_argmatch (int *flags, char *arg, size_t no, size_t err)
 {
   int value = 0;
   if (!err || arg[no + err++] != '\0')
-    value = XARGMATCH (option, arg + no + err, keys, values);
+    value = XARGMATCH ("--warning", arg + no + err,
+                       warnings_args, warnings_types);
 
   if (value)
     {
@@ -273,26 +268,19 @@ warning_argmatch (const char *option,
          - Werror activates all errors, but not the warnings
          - Werror=all activates errors, and all warnings */
       if (no ? !err : err)
-        *flags |= all;
+        *flags |= Wall;
       else
-        *flags &= ~all;
+        *flags &= ~Wall;
     }
 }
 
 /** Decode a comma-separated list of arguments from -W.
  *
- *  \param option   option being decoded.
- *  \param keys     array of valid subarguments.
- *  \param values   array of corresponding (int) values.
- *  \param all      the all value.
- *  \param flags    the flags to update
  *  \param args     comma separated list of effective subarguments to decode.
  *                  If 0, then activate all the flags.
  */
 static void
-warnings_argmatch (const char *option,
-                   const char * const keys[], const int values[],
-                   int all, int *flags, char *args)
+warnings_argmatch (char *args)
 {
   if (args)
     for (args = strtok (args, ","); args; args = strtok (NULL, ","))
@@ -300,28 +288,13 @@ warnings_argmatch (const char *option,
         size_t no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
         size_t err = STRPREFIX_LIT ("error", args + no) ? 5 : 0;
 
-        warning_argmatch (option, keys,
-                          values, all, err ? &errors_flag : flags,
+        warning_argmatch (err ? &errors_flag : &warnings_flag,
                           args, no, err);
       }
   else
-    *flags |= all;
+    warnings_flag |= Wall;
 }
 
-/** Decode a set of sub arguments.
- *
- *  \param FlagName  the flag familly to update.
- *  \param Args      the effective sub arguments to decode.
- *  \param All       the "all" value.
- *
- *  \arg FlagName_args   the list of keys.
- *  \arg FlagName_types  the list of values.
- *  \arg FlagName_flag   the flag to update.
- */
-#define WARNINGS_ARGMATCH(FlagName, Args, All)                          \
-  warnings_argmatch ("--" #FlagName, FlagName ## _args, FlagName ## _types, \
-                     All, &FlagName ## _flag, Args)
-
 const char * const warnings_args[] =
 {
   "none",
@@ -748,7 +721,7 @@ getargs (int argc, char *argv[])
         break;
 
       case 'W':
-        WARNINGS_ARGMATCH (warnings, optarg, Wall);
+        warnings_argmatch (optarg);
         break;
 
       case 'b':
