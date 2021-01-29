@@ -49,6 +49,12 @@ static struct obstack solved_conflicts_xml_obstack;
 static bitset shift_set;
 static bitset lookahead_set;
 
+bool
+has_conflicts (const state *s)
+{
+  return conflicts[s->number];
+}
+
 
 
 enum conflict_resolution
@@ -631,7 +637,7 @@ report_counterexamples (void)
 {
   for (state_number sn = 0; sn < nstates; ++sn)
     if (conflicts[sn])
-      counterexample_report_state (states[sn], stderr);
+      counterexample_report_state (states[sn], stderr, "");
 }
 
 /*------------------------------------------------.
