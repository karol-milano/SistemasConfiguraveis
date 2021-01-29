@@ -20,7 +20,9 @@
 
 
 #include "system.h"
-#include "hash.h"
+
+#include <hash.h>
+
 #include "complain.h"
 #include "gram.h"
 #include "state.h"
@@ -36,13 +38,14 @@
 `---------------------------------------*/
 
 #define TRANSITIONS_ALLOC(Num)						\
-  (transitions_t *) xcalloc ((sizeof (transitions_t)			\
-                                  + (Num - 1) * sizeof (state_t *)), 1)
+  (transitions *) xcalloc ((sizeof (transitions)			\
+                            + (Num - 1) * sizeof (state *)),		\
+			   1)
 
-static transitions_t *
-transitions_new (int num, state_t **the_states)
+static transitions *
+transitions_new (int num, state **the_states)
 {
-  transitions_t *res = TRANSITIONS_ALLOC (num);
+  transitions *res = TRANSITIONS_ALLOC (num);
   res->num = num;
   memcpy (res->states, the_states, num * sizeof (the_states[0]));
   return res;
@@ -51,11 +54,11 @@ transitions_new (int num, state_t **the_states)
 
 /*-------------------------------------------------------------------.
 | Return the state such these TRANSITIONS contain a shift/goto to it |
-| on SYMBOL.  Aborts if none found.                                  |
+| on S.  Abort if none found.                                        |
 `-------------------------------------------------------------------*/
 
-state_t *
-transitions_to (transitions_t *shifts, symbol_number_t s)
+state *
+transitions_to (transitions *shifts, symbol_number s)
 {
   int j;
   for (j = 0; j < shifts->num; j++)
@@ -74,15 +77,14 @@ transitions_to (transitions_t *shifts, symbol_number_t s)
 | Create a new array of N errs.  |
 `-------------------------------*/
 
-#define ERRS_ALLOC(Nerrs)				\
-  (errs_t *) xcalloc ((sizeof (errs_t)			\
-                      + (Nerrs - 1) * sizeof (symbol_t *)), 1)
+#define ERRS_ALLOC(Nerrs) \
+  ((errs *) xcalloc ((sizeof (errs) + (Nerrs - 1) * sizeof (symbol *)), 1))
 
 
-errs_t *
-errs_new (int num, symbol_t **tokens)
+errs *
+errs_new (int num, symbol **tokens)
 {
-  errs_t *res = ERRS_ALLOC (num);
+  errs *res = ERRS_ALLOC (num);
   res->num = num;
   memcpy (res->symbols, tokens, num * sizeof (tokens[0]));
   return res;
@@ -101,15 +103,15 @@ errs_new (int num, symbol_t **tokens)
 `-------------------------------------*/
 
 #define REDUCTIONS_ALLOC(Nreductions)                          \
-  (reductions_t *) xcalloc ((sizeof (reductions_t)             \
-                            + (Nreductions - 1) * sizeof (rule_t *)), 1)
+  (reductions *) xcalloc ((sizeof (reductions)		       \
+                          + (Nreductions - 1) * sizeof (rule *)), 1)
 
-static reductions_t *
-reductions_new (int num, rule_t **reductions)
+static reductions *
+reductions_new (int num, rule **reds)
 {
-  reductions_t *res = REDUCTIONS_ALLOC (num);
+  reductions *res = REDUCTIONS_ALLOC (num);
   res->num = num;
-  memcpy (res->rules, reductions, num * sizeof (reductions[0]));
+  memcpy (res->rules, reds, num * sizeof (reds[0]));
   res->lookaheads = NULL;
   return res;
 }
@@ -121,27 +123,28 @@ reductions_new (int num, rule_t **reductions)
 			`---------*/
 
 
-state_number_t nstates = 0;
+state_number nstates = 0;
 /* FINAL_STATE is properly set by new_state when it recognizes its
    accessing symbol: $end.  */
-state_t *final_state = NULL;
+state *final_state = NULL;
 
 #define STATE_ALLOC(Nitems)						\
-  (state_t *) xcalloc ((sizeof (state_t) 		       		\
-			+ (Nitems - 1) * sizeof (item_number_t)), 1)
+  (state *) xcalloc ((sizeof (state)	 		       		\
+		      + (Nitems - 1) * sizeof (item_number)),		\
+		     1)
 
 /*------------------------------------------------------------------.
 | Create a new state with ACCESSING_SYMBOL, for those items.  Store |
 | it in the state hash table.                                       |
 `------------------------------------------------------------------*/
 
-state_t *
-state_new (symbol_number_t accessing_symbol,
-	   size_t core_size, item_number_t *core)
+state *
+state_new (symbol_number accessing_symbol,
+	   size_t core_size, item_number *core)
 {
-  state_t *res;
+  state *res;
 
-  if (STATE_NUMBER_MAX <= nstates)
+  if (STATE_NUMBER_MAXIMUM <= nstates)
     abort ();
 
   res = STATE_ALLOC (core_size);
@@ -159,83 +162,83 @@ state_new (symbol_number_t accessing_symbol,
 }
 
 
-/*-------------.
-| Free STATE.  |
-`-------------*/
+/*---------.
+| Free S.  |
+`---------*/
 
 static void
-state_free (state_t *state)
+state_free (state *s)
 {
-  free (state->transitions);
-  free (state->reductions);
-  free (state->errs);
-  free (state);
+  free (s->transitions);
+  free (s->reductions);
+  free (s->errs);
+  free (s);
 }
 
 
-/*-------------------------------.
-| Set the transitions of STATE.  |
-`-------------------------------*/
+/*---------------------------.
+| Set the transitions of S.  |
+`---------------------------*/
 
 void
-state_transitions_set (state_t *state, int num, state_t **transitions)
+state_transitions_set (state *s, int num, state **trans)
 {
-  if (state->transitions)
+  if (s->transitions)
     abort ();
-  state->transitions = transitions_new (num, transitions);
+  s->transitions = transitions_new (num, trans);
 }
 
 
-/*------------------------------.
-| Set the reductions of STATE.  |
-`------------------------------*/
+/*--------------------------.
+| Set the reductions of S.  |
+`--------------------------*/
 
 void
-state_reductions_set (state_t *state, int num, rule_t **reductions)
+state_reductions_set (state *s, int num, rule **reds)
 {
-  if (state->reductions)
+  if (s->reductions)
     abort ();
-  state->reductions = reductions_new (num, reductions);
+  s->reductions = reductions_new (num, reds);
 }
 
 
 int
-state_reduction_find (state_t *state, rule_t *rule)
+state_reduction_find (state *s, rule *r)
 {
   int i;
-  reductions_t *reds = state->reductions;
+  reductions *reds = s->reductions;
   for (i = 0; i < reds->num; ++i)
-    if (reds->rules[i] == rule)
+    if (reds->rules[i] == r)
       return i;
   return -1;
 }
 
 
-/*------------------------.
-| Set the errs of STATE.  |
-`------------------------*/
+/*--------------------.
+| Set the errs of S.  |
+`--------------------*/
 
 void
-state_errs_set (state_t *state, int num, symbol_t **tokens)
+state_errs_set (state *s, int num, symbol **tokens)
 {
-  if (state->errs)
+  if (s->errs)
     abort ();
-  state->errs = errs_new (num, tokens);
+  s->errs = errs_new (num, tokens);
 }
 
 
 
-/*--------------------------------------------------------------.
-| Print on OUT all the lookaheads such that this STATE wants to |
-| reduce this RULE.                                             |
-`--------------------------------------------------------------*/
+/*-----------------------------------------------------.
+| Print on OUT all the lookaheads such that S wants to |
+| reduce R.                                            |
+`-----------------------------------------------------*/
 
 void
-state_rule_lookaheads_print (state_t *state, rule_t *rule, FILE *out)
+state_rule_lookaheads_print (state *s, rule *r, FILE *out)
 {
   /* Find the reduction we are handling.  */
-  reductions_t *reds = state->reductions;
-  int red = state_reduction_find (state, rule);
+  reductions *reds = s->reductions;
+  int red = state_reduction_find (s, r);
 
   /* Print them if there are.  */
   if (reds->lookaheads && red != -1)
@@ -264,7 +267,7 @@ static struct hash_table *state_table = NULL;
 
 /* Two states are equal if they have the same core items.  */
 static bool
-state_compare (const state_t *s1, const state_t *s2)
+state_compare (state const *s1, state const *s2)
 {
   int i;
 
@@ -279,13 +282,13 @@ state_compare (const state_t *s1, const state_t *s2)
 }
 
 static unsigned int
-state_hash (const state_t *state, unsigned int tablesize)
+state_hash (state const *s, unsigned int tablesize)
 {
   /* Add up the state's item numbers to get a hash key.  */
   int key = 0;
   int i;
-  for (i = 0; i < state->nitems; ++i)
-    key += state->items[i];
+  for (i = 0; i < s->nitems; ++i)
+    key += s->items[i];
   return key % tablesize;
 }
 
@@ -316,14 +319,14 @@ state_hash_free (void)
 }
 
 
-/*---------------------------------------.
-| Insert STATE in the state hash table.  |
-`---------------------------------------*/
+/*-----------------------------------.
+| Insert S in the state hash table.  |
+`-----------------------------------*/
 
 void
-state_hash_insert (state_t *state)
+state_hash_insert (state *s)
 {
-  hash_insert (state_table, state);
+  hash_insert (state_table, s);
 }
 
 
@@ -332,11 +335,11 @@ state_hash_insert (state_t *state)
 | not exist yet, return NULL.                                       |
 `------------------------------------------------------------------*/
 
-state_t *
-state_hash_lookup (size_t core_size, item_number_t *core)
+state *
+state_hash_lookup (size_t core_size, item_number *core)
 {
-  state_t *probe = STATE_ALLOC (core_size);
-  state_t *entry;
+  state *probe = STATE_ALLOC (core_size);
+  state *entry;
 
   probe->nitems = core_size;
   memcpy (probe->items, core, core_size * sizeof (core[0]));
@@ -346,7 +349,7 @@ state_hash_lookup (size_t core_size, item_number_t *core)
 }
 
 /* All the decorated states, indexed by the state number.  */
-state_t **states = NULL;
+state **states = NULL;
 
 
 /*----------------------.
@@ -356,7 +359,7 @@ state_t **states = NULL;
 void
 states_free (void)
 {
-  state_number_t i;
+  state_number i;
   for (i = 0; i < nstates; ++i)
     state_free (states[i]);
   free (states);
