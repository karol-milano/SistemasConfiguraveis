@@ -52,8 +52,22 @@ typedef struct goto_list_s
 } goto_list_t;
 
 
-rule_t **LArule = NULL;
-bitsetv LA = NULL;
+/* LARULE is a vector which records the rules that need lookahead in
+   various states.  The elements of LARULE that apply to state S are
+   those from LOOKAHEADS[S] through LOOKAHEADS[S+1]-1.
+
+   If LR is the length of LArule, then a number from 0 to LR-1 can
+   specify both a rule and a state where the rule might be applied.
+   */
+
+static rule_t **LArule = NULL;
+
+/* LA is a LR by NTOKENS matrix of bits.  LA[l, i] is 1 if the rule
+   LArule[l] is applicable in the appropriate state when the next
+   token is symbol i.  If LA[l, i] and LA[l, j] are both 1 for i != j,
+   it is a conflict.  */
+
+static bitsetv LA = NULL;
 size_t nLA;
 
 
@@ -460,3 +474,17 @@ lalr (void)
   if (trace_flag & trace_sets)
     lookaheads_print (stderr);
 }
+
+
+void
+lalr_free (void)
+{
+  state_number_t s;
+  for (s = 0; s < nstates; ++s)
+    {
+      states[s]->lookaheads = NULL;
+      states[s]->lookaheads_rule = NULL;
+    }
+  bitsetv_free (LA);
+  free (LArule);
+}
