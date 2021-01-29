@@ -74,25 +74,17 @@ transitions_to (transitions_t *shifts, symbol_number_t s)
 | Create a new array of N errs.  |
 `-------------------------------*/
 
-#define ERRS_ALLOC(Nerrs)						\
-  (errs_t *) xcalloc ((unsigned) (sizeof (errs_t)			\
-                                  + (Nerrs - 1) * sizeof (symbol_number_t)), 1)
+#define ERRS_ALLOC(Nerrs)				\
+  (errs_t *) xcalloc ((sizeof (errs_t)			\
+                      + (Nerrs - 1) * sizeof (symbol_number_t)), 1)
 
 
 errs_t *
-errs_new (int n)
+errs_new (int num, symbol_number_t *tokens)
 {
-  errs_t *res = ERRS_ALLOC (n);
-  res->num = n;
-  return res;
-}
-
-
-errs_t *
-errs_dup (errs_t *src)
-{
-  errs_t *res = errs_new (src->num);
-  memcpy (res->symbols, src->symbols, src->num * sizeof (src->symbols[0]));
+  errs_t *res = ERRS_ALLOC (num);
+  res->num = num;
+  memcpy (res->symbols, tokens, num * sizeof (tokens[0]));
   return res;
 }
 
@@ -108,16 +100,16 @@ errs_dup (errs_t *src)
 | Create a new array of N reductions.  |
 `-------------------------------------*/
 
-#define REDUCTIONS_ALLOC(Nreductions)					\
-  (reductions_t *) xcalloc ((unsigned) (sizeof (reductions_t)		\
-                                  + (Nreductions - 1) * sizeof (rule_number_t)), 1)
+#define REDUCTIONS_ALLOC(Nreductions)				\
+  (reductions_t *) xcalloc ((sizeof (reductions_t)		\
+                            + (Nreductions - 1) * sizeof (rule_number_t)), 1)
 
 static reductions_t *
-reductions_new (int nreductions, short *reductions)
+reductions_new (int num, rule_number_t *reductions)
 {
-  reductions_t *res = REDUCTIONS_ALLOC (nreductions);
-  res->num = nreductions;
-  memcpy (res->rules, reductions, nreductions * sizeof (reductions[0]));
+  reductions_t *res = REDUCTIONS_ALLOC (num);
+  res->num = num;
+  memcpy (res->rules, reductions, num * sizeof (reductions[0]));
   return res;
 }
 
@@ -137,9 +129,10 @@ state_t *final_state = NULL;
   (state_t *) xcalloc ((unsigned) (sizeof (state_t) 			\
                                   + (Nitems - 1) * sizeof (item_number_t)), 1)
 
-/*------------------------------------------------------------.
-| Create a new state with ACCESSING_SYMBOL, for those items.  |
-`------------------------------------------------------------*/
+/*------------------------------------------------------------------.
+| Create a new state with ACCESSING_SYMBOL, for those items.  Store |
+| it in the state hash table.                                       |
+`------------------------------------------------------------------*/
 
 state_t *
 state_new (symbol_number_t accessing_symbol,
@@ -159,18 +152,35 @@ state_new (symbol_number_t accessing_symbol,
   res->nitems = core_size;
   memcpy (res->items, core, core_size * sizeof (core[0]));
 
+  state_hash_insert (res);
+
   return res;
 }
 
 
-/*--------------------------.
-| Set the shifts of STATE.  |
-`--------------------------*/
+/*-------------.
+| Free STATE.  |
+`-------------*/
+
+static void
+state_free (state_t *state)
+{
+  free (state->transitions);
+  free (state->reductions);
+  free (state->errs);
+  free (state);
+}
+
+
+/*-------------------------------.
+| Set the transitions of STATE.  |
+`-------------------------------*/
 
 void
-state_transitions_set (state_t *state, int nshifts, state_number_t *shifts)
+state_transitions_set (state_t *state, int num, state_number_t *transitions)
 {
-  state->shifts = transitions_new (nshifts, shifts);
+  assert (!state->transitions);
+  state->transitions = transitions_new (num, transitions);
 }
 
 
@@ -179,9 +189,22 @@ state_transitions_set (state_t *state, int nshifts, state_number_t *shifts)
 `------------------------------*/
 
 void
-state_reductions_set (state_t *state, int nreductions, short *reductions)
+state_reductions_set (state_t *state, int num, rule_number_t *reductions)
 {
-  state->reductions = reductions_new (nreductions, reductions);
+  assert (!state->reductions);
+  state->reductions = reductions_new (num, reductions);
+}
+
+
+/*------------------------.
+| Set the errs of STATE.  |
+`------------------------*/
+
+void
+state_errs_set (state_t *state, int num, symbol_number_t *tokens)
+{
+  assert (!state->errs);
+  state->errs = errs_new (num, tokens);
 }
 
 
@@ -322,13 +345,7 @@ void
 states_free (void)
 {
   state_number_t i;
-
   for (i = 0; i < nstates; ++i)
-    {
-      free (states[i]->shifts);
-      XFREE (states[i]->reductions);
-      free (states[i]->errs);
-      free (states[i]);
-    }
-  XFREE (states);
+    state_free (states[i]);
+  free (states);
 }
