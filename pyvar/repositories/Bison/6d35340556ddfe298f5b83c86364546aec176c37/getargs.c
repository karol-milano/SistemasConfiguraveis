@@ -68,28 +68,28 @@ const char *skeleton = NULL;
 int language_prio = default_prio;
 struct bison_language const *language = &valid_languages[0];
 
+typedef int* (xargmatch_fn) (const char *context, const char *arg);
+
 /** Decode an option's key.
  *
- *  \param opt      option being decoded.
- *  \param keys     array of valid subarguments.
- *  \param values   array of corresponding (int) values.
- *  \param all      the all value.
- *  \param flags    the flags to update
- *  \param arg      the subarguments to decode.
- *                  If null, then activate all the flags.
- *  \param no       length of the potential "no-" prefix.
- *                  Can be 0 or 3. If 3, negate the action of the subargument.
+ *  \param opt        option being decoded.
+ *  \param xargmatch  matching function.
+ *  \param all        the value of the argument 'all'.
+ *  \param flags      the flags to update
+ *  \param arg        the subarguments to decode.
+ *                    If null, then activate all the flags.
+ *  \param no         length of the potential "no-" prefix.
+ *                    Can be 0 or 3. If 3, negate the action of the subargument.
  *
  *  If VALUE != 0 then KEY sets flags and no-KEY clears them.
  *  If VALUE == 0 then KEY clears all flags from \c all and no-KEY sets all
  *  flags from \c all.  Thus no-none = all and no-all = none.
  */
 static void
-flag_argmatch (const char *opt,
-               const char *const keys[], const int values[],
+flag_argmatch (const char *opt, xargmatch_fn xargmatch,
                int all, int *flags, char *arg, size_t no)
 {
-  int value = XARGMATCH (opt, arg + no, keys, values);
+  int value = *xargmatch (opt, arg + no);
 
   /* -rnone == -rno-all, and -rno-none == -rall.  */
   if (!value)
@@ -104,30 +104,37 @@ flag_argmatch (const char *opt,
     *flags |= value;
 }
 
+typedef void (usage_fn) (FILE *out);
+
 /** Decode an option's set of keys.
  *
- *  \param opt      option being decoded (e.g., --report).
- *  \param keys     array of valid subarguments.
- *  \param values   array of corresponding (int) values.
- *  \param all      the all value.
- *  \param flags    the flags to update
- *  \param args     comma separated list of effective subarguments to decode.
- *                  If 0, then activate all the flags.
+ *  \param opt        option being decoded (e.g., --report).
+ *  \param xargmatch  matching function.
+ *  \param all        the value of the argument 'all'.
+ *  \param flags      the flags to update
+ *  \param args       comma separated list of effective subarguments to decode.
+ *                    If 0, then activate all the flags.
  */
 static void
 flags_argmatch (const char *opt,
-                const char * const keys[], const int values[],
+                xargmatch_fn xargmatch,
+                usage_fn usage,
                 int all, int *flags, char *args)
 {
-  if (args)
+  if (!args)
+    *flags |= all;
+  else if (STREQ (args, "help"))
+    {
+      usage (stdout);
+      exit (EXIT_SUCCESS);
+    }
+  else
     for (args = strtok (args, ","); args; args = strtok (NULL, ","))
       {
         size_t no = STRPREFIX_LIT ("no-", args) ? 3 : 0;
-        flag_argmatch (opt, keys,
-                       values, all, flags, args, no);
+        flag_argmatch (opt, xargmatch,
+                       all, flags, args, no);
       }
-  else
-    *flags |= all;
 }
 
 
@@ -142,116 +149,142 @@ flags_argmatch (const char *opt,
  *  \arg FlagName_flag   the flag to update.
  */
 #define FLAGS_ARGMATCH(FlagName, Args, All)                             \
-  flags_argmatch ("--" #FlagName, FlagName ## _args, FlagName ## _types, \
+  flags_argmatch ("--" #FlagName,                                       \
+                  (xargmatch_fn*) argmatch_## FlagName ## _value,        \
+                  argmatch_## FlagName ## _usage,                       \
                   All, &FlagName ## _flag, Args)
 
-
 /*----------------------.
 | --report's handling.  |
 `----------------------*/
 
-static const char * const report_args[] =
+ARGMATCH_DEFINE_GROUP(report, enum report);
+
+static const argmatch_report_doc argmatch_report_docs[] =
 {
-  /* In a series of synonyms, present the most meaningful first, so
-     that argmatch_valid be more readable.  */
-  "none",
-  "state", "states",
-  "itemset", "itemsets",
-  "lookahead", "lookaheads", "look-ahead",
-  "solved",
-  "all",
-  0
+  { "states",     N_("describe the states") },
+  { "itemsets",   N_("complete the core item sets with their closure") },
+  { "lookaheads", N_("explicitly associate lookahead tokens to items") },
+  { "solved",     N_("describe shift/reduce conflicts solving") },
+  { "all",        N_("include all the above information") },
+  { "none",       N_("disable the report") },
+  { NULL, NULL },
 };
 
-static const int report_types[] =
+static const argmatch_report_arg argmatch_report_args[] =
 {
-  report_none,
-  report_states, report_states,
-  report_states | report_itemsets, report_states | report_itemsets,
-  report_states | report_lookahead_tokens,
-  report_states | report_lookahead_tokens,
-  report_states | report_lookahead_tokens,
-  report_states | report_solved_conflicts,
-  report_all
+  { "none",        report_none },
+  { "states",      report_states },
+  { "itemsets",    report_states | report_itemsets },
+  { "lookaheads",  report_states | report_lookahead_tokens },
+  { "look-ahead",  report_states | report_lookahead_tokens },
+  { "solved",      report_states | report_solved_conflicts },
+  { "all",         report_all },
+  { NULL, report_none },
 };
 
-ARGMATCH_VERIFY (report_args, report_types);
-
+const argmatch_report_group_type argmatch_report_group =
+{
+  argmatch_report_args,
+  argmatch_report_docs,
+  N_("THINGS is a list of comma separated words that can include:"),
+  NULL
+};
 
 /*---------------------.
 | --trace's handling.  |
 `---------------------*/
 
-static const char * const trace_args[] =
+ARGMATCH_DEFINE_GROUP(trace, enum trace);
+
+static const argmatch_trace_doc argmatch_trace_docs[] =
 {
-  "none       - no traces",
-  "locations  - full display of the locations",
-  "scan       - grammar scanner traces",
-  "parse      - grammar parser traces",
-  "automaton  - construction of the automaton",
-  "bitsets    - use of bitsets",
-  "closure    - input/output of closure",
-  "grammar    - reading, reducing the grammar",
-  "resource   - memory consumption (where available)",
-  "sets       - grammar sets: firsts, nullable etc.",
-  "muscles    - m4 definitions passed to the skeleton",
-  "tools      - m4 invocation",
-  "m4         - m4 traces",
-  "skeleton   - skeleton postprocessing",
-  "time       - time consumption",
-  "ielr       - IELR conversion",
-  "all        - all of the above",
-  0
+  /* Meant for developers only, don't translate them.  */
+  { "none",       "no traces" },
+  { "locations",  "full display of the locations" },
+  { "scan",       "grammar scanner traces" },
+  { "parse",      "grammar parser traces" },
+  { "automaton",  "construction of the automaton" },
+  { "bitsets",    "use of bitsets" },
+  { "closure",    "input/output of closure" },
+  { "grammar",    "reading, reducing the grammar" },
+  { "resource",   "memory consumption (where available)" },
+  { "sets",       "grammar sets: firsts, nullable etc." },
+  { "muscles",    "m4 definitions passed to the skeleton" },
+  { "tools",      "m4 invocation" },
+  { "m4",         "m4 traces" },
+  { "skeleton",   "skeleton postprocessing" },
+  { "time",       "time consumption" },
+  { "ielr",       "IELR conversion" },
+  { "all",        "all of the above" },
+  { NULL, NULL},
 };
 
-static const int trace_types[] =
+static const argmatch_trace_arg argmatch_trace_args[] =
 {
-  trace_none,
-  trace_locations,
-  trace_scan,
-  trace_parse,
-  trace_automaton,
-  trace_bitsets,
-  trace_closure,
-  trace_grammar,
-  trace_resource,
-  trace_sets,
-  trace_muscles,
-  trace_tools,
-  trace_m4,
-  trace_skeleton,
-  trace_time,
-  trace_ielr,
-  trace_all
+  { "none",      trace_none },
+  { "locations", trace_locations },
+  { "scan",      trace_scan },
+  { "parse",     trace_parse },
+  { "automaton", trace_automaton },
+  { "bitsets",   trace_bitsets },
+  { "closure",   trace_closure },
+  { "grammar",   trace_grammar },
+  { "resource",  trace_resource },
+  { "sets",      trace_sets },
+  { "muscles",   trace_muscles },
+  { "tools",     trace_tools },
+  { "m4",        trace_m4 },
+  { "skeleton",  trace_skeleton },
+  { "time",      trace_time },
+  { "ielr",      trace_ielr },
+  { "all",       trace_all },
+  { NULL,        trace_none},
 };
 
-ARGMATCH_VERIFY (trace_args, trace_types);
-
+const argmatch_trace_group_type argmatch_trace_group =
+{
+  argmatch_trace_args,
+  argmatch_trace_docs,
+  N_("TRACES is a list of comma separated words that can include:"),
+  NULL
+};
 
 /*-----------------------.
 | --feature's handling.  |
 `-----------------------*/
 
-static const char * const feature_args[] =
+ARGMATCH_DEFINE_GROUP(feature, enum feature);
+
+static const argmatch_feature_doc argmatch_feature_docs[] =
 {
-  "none",
-  "caret", "diagnostics-show-caret",
-  "fixit", "diagnostics-parseable-fixits",
-  "syntax-only",
-  "all",
-  0
+  { "caret",       N_("show errors with carets") },
+  { "fixit",       N_("show machine-readable fixes") },
+  { "syntax-only", N_("do not generate any file") },
+  { "all",         N_("all of the above") },
+  { "none",        N_("disable all of the above") },
+  { NULL, NULL }
 };
 
-static const int feature_types[] =
+static const argmatch_feature_arg argmatch_feature_args[] =
 {
-  feature_none,
-  feature_caret, feature_caret,
-  feature_fixit_parsable, feature_fixit_parsable,
-  feature_syntax_only,
-  feature_all
+  { "none",                          feature_none },
+  { "caret",                         feature_caret },
+  { "diagnostics-show-caret",        feature_caret },
+  { "fixit",                         feature_fixit },
+  { "diagnostics-parseable-fixits",  feature_fixit },
+  { "syntax-only",                   feature_syntax_only },
+  { "all",                           feature_all },
+  { NULL, feature_none}
 };
 
-ARGMATCH_VERIFY (feature_args, feature_types);
+const argmatch_feature_group_type argmatch_feature_group =
+{
+  argmatch_feature_args,
+  argmatch_feature_docs,
+  N_("FEATURES is a list of comma separated words that can include:"),
+  NULL
+};
 
 /*-------------------------------------------.
 | Display the help message and exit STATUS.  |
@@ -334,49 +367,15 @@ Output:\n\
 "), stdout);
       putc ('\n', stdout);
 
-      fputs (_("\
-Warning categories include:\n\
-  'conflicts-sr'      S/R conflicts (enabled by default)\n\
-  'conflicts-rr'      R/R conflicts (enabled by default)\n\
-  'deprecated'        obsolete constructs\n\
-  'empty-rule'        empty rules without %empty\n\
-  'midrule-values'    unset or unused midrule values\n\
-  'precedence'        useless precedence and associativity\n\
-  'yacc'              incompatibilities with POSIX Yacc\n\
-  'other'             all other warnings (enabled by default)\n\
-  'all'               all the warnings except 'yacc'\n\
-  'no-CATEGORY'       turn off warnings in CATEGORY\n\
-  'none'              turn off all the warnings\n\
-  'error[=CATEGORY]'  treat warnings as errors\n\
-"), stdout);
+      warning_usage (stdout);
       putc ('\n', stdout);
 
-      fputs (_("\
-THINGS is a list of comma separated words that can include:\n\
-  'state'        describe the states\n\
-  'itemset'      complete the core item sets with their closure\n\
-  'lookahead'    explicitly associate lookahead tokens to items\n\
-  'solved'       describe shift/reduce conflicts solving\n\
-  'all'          include all the above information\n\
-  'none'         disable the report\n\
-"), stdout);
+      argmatch_report_usage (stdout);
       putc ('\n', stdout);
 
-      fputs (_("\
-FEATURES is a list of comma separated words that can include:\n\
-  'caret', 'diagnostics-show-caret'\n\
-    show errors with carets\n\
-  'fixit', 'diagnostics-parseable-fixits'\n\
-    show machine-readable fixes\n\
-  'syntax-only'\n\
-    do not generate any file\n\
-  'all'\n\
-    all of the above\n\
-  'none'\n\
-    disable all of the above\n\
-  "), stdout);
-
+      argmatch_feature_usage (stdout);
       putc ('\n', stdout);
+
       printf (_("Report bugs to <%s>.\n"), PACKAGE_BUGREPORT);
       printf (_("%s home page: <%s>.\n"), PACKAGE_NAME, PACKAGE_URL);
       fputs (_("General help using GNU software: "
