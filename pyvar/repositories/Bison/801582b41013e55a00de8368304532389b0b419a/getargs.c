@@ -154,6 +154,49 @@ flags_argmatch (const char *opt,
                   argmatch_## FlagName ## _usage,                       \
                   All, &FlagName ## _flag, Args)
 
+/*---------------------.
+| --color's handling.  |
+`---------------------*/
+
+enum color
+  {
+    color_always,
+    color_never,
+    color_auto
+  };
+
+ARGMATCH_DEFINE_GROUP(color, enum color);
+
+static const argmatch_color_doc argmatch_color_docs[] =
+{
+  { "always",     N_("colorize the output") },
+  { "never",      N_("don't colorize the output") },
+  { "auto",       N_("colorize if the output device is a tty") },
+  { NULL, NULL },
+};
+
+static const argmatch_color_arg argmatch_color_args[] =
+{
+  { "always",   color_always },
+  { "yes",      color_always },
+  { "never",    color_never },
+  { "no",       color_never },
+  { "auto",     color_auto },
+  { "tty",      color_auto },
+  { NULL, color_always },
+};
+
+const argmatch_color_group_type argmatch_color_group =
+{
+  argmatch_color_args,
+  argmatch_color_docs,
+  /* TRANSLATORS: Use the same translation for WHEN as in the
+     --color=WHEN help message.  */
+  N_("WHEN can be one of the following:"),
+  NULL
+};
+
+
 /*----------------------.
 | --report's handling.  |
 `----------------------*/
@@ -187,6 +230,8 @@ const argmatch_report_group_type argmatch_report_group =
 {
   argmatch_report_args,
   argmatch_report_docs,
+  /* TRANSLATORS: Use the same translation for THINGS as in the
+     --report=THINGS help message.  */
   N_("THINGS is a list of comma separated words that can include:"),
   NULL
 };
@@ -282,6 +327,8 @@ const argmatch_feature_group_type argmatch_feature_group =
 {
   argmatch_feature_args,
   argmatch_feature_docs,
+  /* TRANSLATORS: Use the same translation for FEATURES as in the
+     --feature=FEATURES help message.  */
   N_("FEATURES is a list of comma separated words that can include:"),
   NULL
 };
@@ -331,6 +378,8 @@ Operation modes:\n\
   -u, --update               apply fixes to the source grammar file and exit\n\
   -y, --yacc                 emulate POSIX Yacc\n\
   -W, --warnings[=CATEGORY]  report the warnings falling in CATEGORY\n\
+      --color[=WHEN]         whether to colorize the diagnostics\n\
+      --style=FILE           specify the CSS FILE for colorizer diagnostics\n\
   -f, --feature[=FEATURES]   activate miscellaneous features\n\
 \n\
 "), stdout);
@@ -367,6 +416,9 @@ Output:\n\
 "), stdout);
       putc ('\n', stdout);
 
+      argmatch_color_usage (stdout);
+      putc ('\n', stdout);
+
       warning_usage (stdout);
       putc ('\n', stdout);
 
@@ -600,6 +652,8 @@ getargs_colors (int argc, char *argv[])
           else
             handle_color_option (color);
         }
+      else if (STREQ ("--color", arg))
+        handle_color_option (NULL);
       else if (STRPREFIX_LIT ("--style=", arg))
         {
           const char *style = arg + strlen ("--style=");
