@@ -81,3 +81,36 @@ reductions_new (int n)
   res->nreds = n;
   return res;
 }
+
+
+/*--------------------------------------------------------------.
+| Print on OUT all the lookaheads such that this STATE wants to |
+| reduce this RULE.                                             |
+`--------------------------------------------------------------*/
+
+void
+state_rule_lookaheads_print (state_t *state, rule_t *rule, FILE *out)
+{
+  int j, k;
+  int nlookaheads = 0;
+  /* Count the number of lookaheads corresponding to this rule.  */
+  for (j = 0; j < state->nlookaheads; ++j)
+    for (k = 0; k < ntokens; ++k)
+      if (bitset_test (state->lookaheads[j], k)
+	  && state->lookaheads_rule[j]->number == rule->number)
+	nlookaheads++;
+
+  /* Print them if there are.  */
+  if (nlookaheads)
+    {
+      fprintf (out, "  [");
+      for (j = 0; j < state->nlookaheads; ++j)
+	for (k = 0; k < ntokens; ++k)
+	  if (bitset_test (state->lookaheads[j], k)
+	      && state->lookaheads_rule[j]->number == rule->number)
+	    fprintf (out, "%s%s",
+		     symbol_tag_get (symbols[k]),
+		     --nlookaheads ? ", " : "");
+      fprintf (out, "]");
+    }
+}
