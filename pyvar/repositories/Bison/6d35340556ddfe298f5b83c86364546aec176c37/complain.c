@@ -144,6 +144,56 @@ static const warnings warnings_types[] =
 
 ARGMATCH_VERIFY (warnings_args, warnings_types);
 
+ARGMATCH_DEFINE_GROUP(warning, warnings);
+
+static const argmatch_warning_doc argmatch_warning_docs[] =
+{
+  { "conflicts-sr",     N_("S/R conflicts (enabled by default)") },
+  { "conflicts-rr",     N_("R/R conflicts (enabled by default)") },
+  { "deprecated",       N_("obsolete constructs") },
+  { "empty-rule",       N_("empty rules without %empty") },
+  { "midrule-values",   N_("unset or unused midrule values") },
+  { "precedence",       N_("useless precedence and associativity") },
+  { "yacc",             N_("incompatibilities with POSIX Yacc") },
+  { "other",            N_("all other warnings (enabled by default)") },
+  { "all",              N_("all the warnings except 'yacc'") },
+  { "no-CATEGORY",      N_("turn off warnings in CATEGORY") },
+  { "none",             N_("turn off all the warnings") },
+  { "error[=CATEGORY]", N_("treat warnings as errors") },
+  { NULL, NULL }
+};
+
+static const argmatch_warning_arg argmatch_warning_args[] =
+{
+  { "none",           Wnone },
+  { "midrule-values", Wmidrule_values },
+  { "yacc",           Wyacc },
+  { "conflicts-sr",   Wconflicts_sr },
+  { "conflicts-rr",   Wconflicts_rr },
+  { "deprecated",     Wdeprecated },
+  { "empty-rule",     Wempty_rule },
+  { "precedence",     Wprecedence },
+  { "other",          Wother },
+  { "all",            Wall },
+  { "error",          Werror },
+  { "everything",     Weverything },
+  { NULL, Wnone }
+};
+
+const argmatch_warning_group_type argmatch_warning_group =
+{
+  argmatch_warning_args,
+  argmatch_warning_docs,
+  N_("Warning categories include:"),
+  NULL
+};
+
+void
+warning_usage (FILE *out)
+{
+  argmatch_warning_usage (out);
+}
+
 void
 warning_argmatch (char const *arg, size_t no, size_t err)
 {
@@ -187,7 +237,14 @@ warning_argmatch (char const *arg, size_t no, size_t err)
 void
 warnings_argmatch (char *args)
 {
-  if (args)
+  if (!args)
+    warning_argmatch ("all", 0, 0);
+  else if (STREQ (args, "help"))
+    {
+      warning_usage (stdout);
+      exit (EXIT_SUCCESS);
+    }
+  else
     for (args = strtok (args, ","); args; args = strtok (NULL, ","))
       if (STREQ (args, "error"))
         warnings_are_errors = true;
@@ -203,8 +260,6 @@ warnings_argmatch (char *args)
 
           warning_argmatch (args, no, err);
         }
-  else
-    warning_argmatch ("all", 0, 0);
 }
 
 static const char*
