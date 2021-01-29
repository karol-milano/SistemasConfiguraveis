@@ -35,12 +35,12 @@
 | Create a new array of N shifts/gotos.  |
 `---------------------------------------*/
 
-#define TRANSITIONS_ALLOC(Num)					\
-  (transitions_t *) xcalloc ((sizeof (transitions_t) 			\
-                                  + (Num - 1) * sizeof (state_number_t)), 1)
+#define TRANSITIONS_ALLOC(Num)						\
+  (transitions_t *) xcalloc ((sizeof (transitions_t)			\
+                                  + (Num - 1) * sizeof (state_t *)), 1)
 
 static transitions_t *
-transitions_new (int num, state_number_t *the_states)
+transitions_new (int num, state_t **the_states)
 {
   transitions_t *res = TRANSITIONS_ALLOC (num);
   res->num = num;
@@ -60,7 +60,7 @@ transitions_to (transitions_t *shifts, symbol_number_t s)
   int j;
   for (j = 0; j < shifts->num; j++)
     if (TRANSITION_SYMBOL (shifts, j) == s)
-      return states[shifts->states[j]];
+      return shifts->states[j];
   abort ();
 }
 
@@ -76,11 +76,11 @@ transitions_to (transitions_t *shifts, symbol_number_t s)
 
 #define ERRS_ALLOC(Nerrs)				\
   (errs_t *) xcalloc ((sizeof (errs_t)			\
-                      + (Nerrs - 1) * sizeof (symbol_number_t)), 1)
+                      + (Nerrs - 1) * sizeof (symbol_t *)), 1)
 
 
 errs_t *
-errs_new (int num, symbol_number_t *tokens)
+errs_new (int num, symbol_t **tokens)
 {
   errs_t *res = ERRS_ALLOC (num);
   res->num = num;
@@ -102,10 +102,10 @@ errs_new (int num, symbol_number_t *tokens)
 
 #define REDUCTIONS_ALLOC(Nreductions)				\
   (reductions_t *) xcalloc ((sizeof (reductions_t)		\
-                            + (Nreductions - 1) * sizeof (rule_number_t)), 1)
+                            + (Nreductions - 1) * sizeof (rule_t *)), 1)
 
 static reductions_t *
-reductions_new (int num, rule_number_t *reductions)
+reductions_new (int num, rule_t **reductions)
 {
   reductions_t *res = REDUCTIONS_ALLOC (num);
   res->num = num;
@@ -126,8 +126,8 @@ state_number_t nstates = 0;
 state_t *final_state = NULL;
 
 #define STATE_ALLOC(Nitems)						\
-  (state_t *) xcalloc ((unsigned) (sizeof (state_t) 			\
-                                  + (Nitems - 1) * sizeof (item_number_t)), 1)
+  (state_t *) xcalloc ((sizeof (state_t) 		       		\
+			+ (Nitems - 1) * sizeof (item_number_t)), 1)
 
 /*------------------------------------------------------------------.
 | Create a new state with ACCESSING_SYMBOL, for those items.  Store |
@@ -177,7 +177,7 @@ state_free (state_t *state)
 `-------------------------------*/
 
 void
-state_transitions_set (state_t *state, int num, state_number_t *transitions)
+state_transitions_set (state_t *state, int num, state_t **transitions)
 {
   assert (!state->transitions);
   state->transitions = transitions_new (num, transitions);
@@ -189,7 +189,7 @@ state_transitions_set (state_t *state, int num, state_number_t *transitions)
 `------------------------------*/
 
 void
-state_reductions_set (state_t *state, int num, rule_number_t *reductions)
+state_reductions_set (state_t *state, int num, rule_t **reductions)
 {
   assert (!state->reductions);
   state->reductions = reductions_new (num, reductions);
@@ -201,7 +201,7 @@ state_reductions_set (state_t *state, int num, rule_number_t *reductions)
 `------------------------*/
 
 void
-state_errs_set (state_t *state, int num, symbol_number_t *tokens)
+state_errs_set (state_t *state, int num, symbol_t **tokens)
 {
   assert (!state->errs);
   state->errs = errs_new (num, tokens);
