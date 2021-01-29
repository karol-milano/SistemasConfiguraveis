@@ -69,6 +69,54 @@ const char *include = NULL;
 extern char *program_name;
 
 
+/*----------------------.
+| --report's handling.  |
+`----------------------*/
+
+static const char * const report_args[] =
+{
+  /* In a series of synonyms, present the most meaningful first, so
+     that argmatch_valid be more readable.  */
+  "none",
+  "state", "states",
+  "itemset", "itemsets",
+  "lookahead", "lookaheads", "look-ahead",
+  "solved",
+  "all",
+  0
+};
+
+static const int report_types[] =
+{
+  report_none,
+  report_states, report_states,
+  report_states | report_itemsets, report_states | report_itemsets,
+  report_states | report_lookahead_tokens,
+  report_states | report_lookahead_tokens,
+  report_states | report_lookahead_tokens,
+  report_states | report_solved_conflicts,
+  report_all
+};
+
+ARGMATCH_VERIFY (report_args, report_types);
+
+static void
+report_argmatch (char *args)
+{
+  args = strtok (args, ",");
+  do
+    {
+      int report = XARGMATCH ("--report", args,
+			      report_args, report_types);
+      if (report == report_none)
+	report_flag = report_none;
+      else
+	report_flag |= report;
+    }
+  while ((args = strtok (NULL, ",")));
+}
+
+
 /*---------------------.
 | --trace's handling.  |
 `---------------------*/
@@ -77,12 +125,12 @@ static const char * const trace_args[] =
 {
   /* In a series of synonyms, present the most meaningful first, so
      that argmatch_valid be more readable.  */
-  "none       - no report",
+  "none       - no traces",
   "scan       - grammar scanner traces",
   "parse      - grammar parser traces",
-  "automaton  - contruction of the automaton",
+  "automaton  - construction of the automaton",
   "bitsets    - use of bitsets",
-  "grammar    - reading, reducing of the grammar",
+  "grammar    - reading, reducing the grammar",
   "resource   - memory consumption (where available)",
   "sets       - grammar sets: firsts, nullable etc.",
   "tools      - m4 invocation",
@@ -134,54 +182,6 @@ trace_argmatch (char *args)
 }
 
 
-/*----------------------.
-| --report's handling.  |
-`----------------------*/
-
-static const char * const report_args[] =
-{
-  /* In a series of synonyms, present the most meaningful first, so
-     that argmatch_valid be more readable.  */
-  "none",
-  "state", "states",
-  "itemset", "itemsets",
-  "lookahead", "lookaheads", "look-ahead",
-  "solved",
-  "all",
-  0
-};
-
-static const int report_types[] =
-{
-  report_none,
-  report_states, report_states,
-  report_states | report_itemsets, report_states | report_itemsets,
-  report_states | report_lookahead_tokens,
-  report_states | report_lookahead_tokens,
-  report_states | report_lookahead_tokens,
-  report_states | report_solved_conflicts,
-  report_all
-};
-
-ARGMATCH_VERIFY (report_args, report_types);
-
-static void
-report_argmatch (char *args)
-{
-  args = strtok (args, ",");
-  do
-    {
-      int report = XARGMATCH ("--report", args,
-			      report_args, report_types);
-      if (report == report_none)
-	report_flag = report_none;
-      else
-	report_flag |= report;
-    }
-  while ((args = strtok (NULL, ",")));
-}
-
-
 /*-------------------------------------------.
 | Display the help message and exit STATUS.  |
 `-------------------------------------------*/
