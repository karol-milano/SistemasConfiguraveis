@@ -196,8 +196,6 @@ ARGMATCH_VERIFY (report_args, report_types);
 
 static const char * const trace_args[] =
 {
-  /* In a series of synonyms, present the most meaningful first, so
-     that argmatch_valid be more readable.  */
   "none       - no traces",
   "scan       - grammar scanner traces",
   "parse      - grammar parser traces",
@@ -244,18 +242,16 @@ ARGMATCH_VERIFY (trace_args, trace_types);
 
 static const char * const warnings_args[] =
 {
-  /* In a series of synonyms, present the most meaningful first, so
-     that argmatch_valid be more readable.  */
-  "none            - no warnings",
-  "midrule-values  - unset or unused midrule values",
-  "yacc            - incompatibilities with POSIX Yacc",
-  "conflicts-sr    - S/R conflicts",
-  "conflicts-rr    - R/R conflicts",
-  "deprecated      - obsolete constructs",
-  "precedence      - useless precedence and associativity",
-  "other           - all other warnings",
-  "all             - all of the above",
-  "error           - warnings are errors",
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
   0
 };
 
