@@ -223,123 +223,6 @@ static const int trace_types[] =
 ARGMATCH_VERIFY (trace_args, trace_types);
 
 
-/*------------------------.
-| --warnings's handling.  |
-`------------------------*/
-
-/** Decode a single argument from -W.
- *
- *  \param arg      the subarguments to decode.
- *                  If null, then activate all the flags.
- *  \param no       length of the potential "no-" prefix.
- *                  Can be 0 or 3. If 3, negate the action of the subargument.
- *  \param err      length of a potential "error=".
- *                  Can be 0 or 6. If 6, treat the subargument as a CATEGORY.
- *
- *  If VALUE != 0 then KEY sets flags and no-KEY clears them.
- *  If VALUE == 0 then KEY clears all flags from \c all and no-KEY sets all
- *  flags from \c all.  Thus no-none = all and no-all = none.
- */
-static void
-warning_argmatch (char const *arg, size_t no, size_t err)
-{
-  int value = XARGMATCH ("--warning", arg + no + err,
-                         warnings_args, warnings_types);
-
-  /* -Wnone == -Wno-all, and -Wno-none == -Wall.  */
-  if (!value)
-    {
-      value = Wall;
-      no = !no;
-    }
-
-  if (no)
-    {
-      size_t b;
-      for (b = 0; b < warnings_size; ++b)
-        if (value & 1 << b)
-          {
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
-          }
-    }
-  else
-    {
-      size_t b;
-      for (b = 0; b < warnings_size; ++b)
-        if (value & 1 << b)
-          /* -Wfoo and -Werror=foo. */
-          warnings_flag[b] = err ? severity_error : severity_warning;
-    }
-}
-
-/** Decode a comma-separated list of arguments from -W.
- *
- *  \param args     comma separated list of effective subarguments to decode.
- *                  If 0, then activate all the flags.
- */
-static void
-warnings_argmatch (char *args)
-{
-  if (args)
-    for (args = strtok (args, ","); args; args = strtok (NULL, ","))
-      if (STREQ (args, "error"))
-        warnings_are_errors = true;
-      else if (STREQ (args, "no-error"))
-        {
-          warnings_are_errors = false;
-          warning_argmatch ("no-error=all", 3, 6);
-        }
-      else
-        {
-          size_t no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
-          size_t err = STRPREFIX_LIT ("error=", args + no) ? 6 : 0;
-
-          warning_argmatch (args, no, err);
-        }
-  else
-    warning_argmatch ("all", 0, 0);
-}
-
-const char * const warnings_args[] =
-{
-  "none",
-  "midrule-values",
-  "yacc",
-  "conflicts-sr",
-  "conflicts-rr",
-  "deprecated",
-  "precedence",
-  "other",
-  "all",
-  "error",
-  0
-};
-
-const int warnings_types[] =
-{
-  Wnone,
-  Wmidrule_values,
-  Wyacc,
-  Wconflicts_sr,
-  Wconflicts_rr,
-  Wdeprecated,
-  Wprecedence,
-  Wother,
-  Wall,
-  Werror
-};
-
-ARGMATCH_VERIFY (warnings_args, warnings_types);
-
 /*-----------------------.
 | --feature's handling.  |
 `-----------------------*/
@@ -804,7 +687,7 @@ getargs (int argc, char *argv[])
         break;
 
       case 'y':
-        warnings_flag[warning_yacc] = severity_error;
+        warning_argmatch ("error=yacc", 0, 6);
         yacc_flag = true;
         break;
 
