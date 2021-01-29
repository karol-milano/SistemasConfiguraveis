@@ -61,7 +61,7 @@ transitions_to (transitions *shifts, symbol_number sym)
   int j;
   for (j = 0; ; j++)
     {
-      assert (j < shifts->num);
+      aver (j < shifts->num);
       if (TRANSITION_SYMBOL (shifts, j) == sym)
 	return shifts->states[j];
     }
@@ -135,7 +135,7 @@ state_new (symbol_number accessing_symbol,
   state *res;
   size_t items_size = nitems * sizeof *core;
 
-  assert (nstates < STATE_NUMBER_MAXIMUM);
+  aver (nstates < STATE_NUMBER_MAXIMUM);
 
   res = xmalloc (offsetof (state, items) + items_size);
   res->number = nstates++;
@@ -176,7 +176,7 @@ state_free (state *s)
 void
 state_transitions_set (state *s, int num, state **trans)
 {
-  assert (!s->transitions);
+  aver (!s->transitions);
   s->transitions = transitions_new (num, trans);
 }
 
@@ -188,7 +188,7 @@ state_transitions_set (state *s, int num, state **trans)
 void
 state_reductions_set (state *s, int num, rule **reds)
 {
-  assert (!s->reductions);
+  aver (!s->reductions);
   s->reductions = reductions_new (num, reds);
 }
 
@@ -212,7 +212,7 @@ state_reduction_find (state *s, rule *r)
 void
 state_errs_set (state *s, int num, symbol **tokens)
 {
-  assert (!s->errs);
+  aver (!s->errs);
   s->errs = errs_new (num, tokens);
 }
 
