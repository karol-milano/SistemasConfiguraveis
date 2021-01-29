@@ -109,41 +109,6 @@ flush (FILE *out)
 | --warnings's handling.  |
 `------------------------*/
 
-static const char * const warnings_args[] =
-{
-  "none",
-  "midrule-values",
-  "yacc",
-  "conflicts-sr",
-  "conflicts-rr",
-  "deprecated",
-  "empty-rule",
-  "precedence",
-  "other",
-  "all",
-  "error",
-  "everything",
-  0
-};
-
-static const warnings warnings_types[] =
-{
-  Wnone,
-  Wmidrule_values,
-  Wyacc,
-  Wconflicts_sr,
-  Wconflicts_rr,
-  Wdeprecated,
-  Wempty_rule,
-  Wprecedence,
-  Wother,
-  Wall,
-  Werror,
-  Weverything
-};
-
-ARGMATCH_VERIFY (warnings_args, warnings_types);
-
 ARGMATCH_DEFINE_GROUP(warning, warnings);
 
 static const argmatch_warning_doc argmatch_warning_docs[] =
@@ -175,7 +140,6 @@ static const argmatch_warning_arg argmatch_warning_args[] =
   { "precedence",     Wprecedence },
   { "other",          Wother },
   { "all",            Wall },
-  { "error",          Werror },
   { "everything",     Weverything },
   { NULL, Wnone }
 };
@@ -197,8 +161,7 @@ warning_usage (FILE *out)
 void
 warning_argmatch (char const *arg, size_t no, size_t err)
 {
-  int value = XARGMATCH ("--warning", arg + no + err,
-                         warnings_args, warnings_types);
+  int value = *argmatch_warning_value ("--warning", arg + no + err);
 
   /* -Wnone == -Wno-everything, and -Wno-none == -Weverything.  */
   if (!value)
@@ -420,16 +383,17 @@ warning_is_enabled (warnings flags)
 static void
 warnings_print_categories (warnings warn_flags, FILE *out)
 {
-  for (size_t i = 0; warnings_args[i]; ++i)
-    if (warn_flags & warnings_types[i])
+  for (int wbit = 0; wbit < warnings_size; ++wbit)
+    if (warn_flags & (1 << wbit))
       {
-        severity s = warning_severity (warnings_types[i]);
+        warnings w = 1 << wbit;
+        severity s = warning_severity (w);
         const char* style = severity_style (s);
         fputs (" [", out);
         begin_use_class (style, out);
         fprintf (out, "-W%s%s",
                  s == severity_error ? "error=" : "",
-                 warnings_args[i]);
+                 argmatch_warning_argument (&w));
         end_use_class (style, out);
         fputc (']', out);
         /* Display only the first match, the second is "-Wall".  */
