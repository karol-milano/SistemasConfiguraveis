@@ -100,8 +100,8 @@ errs_new (int num, symbol_t **tokens)
 | Create a new array of N reductions.  |
 `-------------------------------------*/
 
-#define REDUCTIONS_ALLOC(Nreductions)				\
-  (reductions_t *) xcalloc ((sizeof (reductions_t)		\
+#define REDUCTIONS_ALLOC(Nreductions)                          \
+  (reductions_t *) xcalloc ((sizeof (reductions_t)             \
                             + (Nreductions - 1) * sizeof (rule_t *)), 1)
 
 static reductions_t *
@@ -110,6 +110,7 @@ reductions_new (int num, rule_t **reductions)
   reductions_t *res = REDUCTIONS_ALLOC (num);
   res->num = num;
   memcpy (res->rules, reductions, num * sizeof (reductions[0]));
+  res->lookaheads = NULL;
   return res;
 }
 
@@ -196,6 +197,18 @@ state_reductions_set (state_t *state, int num, rule_t **reductions)
 }
 
 
+int
+state_reduction_find (state_t *state, rule_t *rule)
+{
+  int i;
+  reductions_t *reds = state->reductions;
+  for (i = 0; i < reds->num; ++i)
+    if (reds->rules[i] == rule)
+      return i;
+  return -1;
+}
+
+
 /*------------------------.
 | Set the errs of STATE.  |
 `------------------------*/
@@ -217,25 +230,21 @@ state_errs_set (state_t *state, int num, symbol_t **tokens)
 void
 state_rule_lookaheads_print (state_t *state, rule_t *rule, FILE *out)
 {
-  int j, k;
-  bitset_iterator biter;
-  int nlookaheads = 0;
-  /* Count the number of lookaheads corresponding to this rule.  */
-  for (j = 0; j < state->nlookaheads; ++j)
-    BITSET_FOR_EACH (biter, state->lookaheads[j], k, 0)
-      if (state->lookaheads_rule[j] == rule)
-	nlookaheads++;
+  /* Find the reduction we are handling.  */
+  reductions_t *reds = state->reductions;
+  int red = state_reduction_find (state, rule);
 
   /* Print them if there are.  */
-  if (nlookaheads)
+  if (reds->lookaheads && red != -1)
     {
+      bitset_iterator biter;
+      int k;
+      int not_first = 0;
       fprintf (out, "  [");
-      for (j = 0; j < state->nlookaheads; ++j)
-	BITSET_FOR_EACH (biter, state->lookaheads[j], k, 0)
-	  if (state->lookaheads_rule[j] == rule)
-	    fprintf (out, "%s%s",
-		     symbols[k]->tag,
-		     --nlookaheads ? ", " : "");
+      BITSET_FOR_EACH (biter, reds->lookaheads[red], k, 0)
+	fprintf (out, "%s%s",
+		 not_first++ ? ", " : "",
+		 symbols[k]->tag);
       fprintf (out, "]");
     }
 }
