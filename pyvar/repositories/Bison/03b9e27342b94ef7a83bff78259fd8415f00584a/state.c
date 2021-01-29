@@ -1,4 +1,5 @@
 /* Type definitions for nondeterministic finite state machine for Bison.
+
    Copyright (C) 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -33,21 +34,17 @@
 			`-------------------*/
 
 
-/*---------------------------------------.
-| Create a new array of N shifts/gotos.  |
-`---------------------------------------*/
-
-#define TRANSITIONS_ALLOC(Num)						\
-  (transitions *) xcalloc ((sizeof (transitions)			\
-                            + (Num - 1) * sizeof (state *)),		\
-			   1)
+/*-----------------------------------------.
+| Create a new array of NUM shifts/gotos.  |
+`-----------------------------------------*/
 
 static transitions *
 transitions_new (int num, state **the_states)
 {
-  transitions *res = TRANSITIONS_ALLOC (num);
+  size_t states_size = num * sizeof *the_states;
+  transitions *res = xmalloc (offsetof (transitions, states) + states_size);
   res->num = num;
-  memcpy (res->states, the_states, num * sizeof (the_states[0]));
+  memcpy (res->states, the_states, states_size);
   return res;
 }
 
@@ -73,20 +70,17 @@ transitions_to (transitions *shifts, symbol_number s)
 			`--------------------*/
 
 
-/*-------------------------------.
-| Create a new array of N errs.  |
-`-------------------------------*/
-
-#define ERRS_ALLOC(Nerrs) \
-  ((errs *) xcalloc ((sizeof (errs) + (Nerrs - 1) * sizeof (symbol *)), 1))
-
+/*---------------------------------.
+| Create a new array of NUM errs.  |
+`---------------------------------*/
 
 errs *
 errs_new (int num, symbol **tokens)
 {
-  errs *res = ERRS_ALLOC (num);
+  size_t symbols_size = num * sizeof *tokens;
+  errs *res = xmalloc (offsetof (errs, symbols) + symbols_size);
   res->num = num;
-  memcpy (res->symbols, tokens, num * sizeof (tokens[0]));
+  memcpy (res->symbols, tokens, symbols_size);
   return res;
 }
 
@@ -98,21 +92,18 @@ errs_new (int num, symbol **tokens)
 			`-------------*/
 
 
-/*-------------------------------------.
-| Create a new array of N reductions.  |
-`-------------------------------------*/
-
-#define REDUCTIONS_ALLOC(Nreductions)                          \
-  (reductions *) xcalloc ((sizeof (reductions)		       \
-                          + (Nreductions - 1) * sizeof (rule *)), 1)
+/*---------------------------------------.
+| Create a new array of NUM reductions.  |
+`---------------------------------------*/
 
 static reductions *
 reductions_new (int num, rule **reds)
 {
-  reductions *res = REDUCTIONS_ALLOC (num);
+  size_t rules_size = num * sizeof *reds;
+  reductions *res = xmalloc (offsetof (reductions, rules) + rules_size);
   res->num = num;
-  memcpy (res->rules, reds, num * sizeof (reds[0]));
   res->lookaheads = NULL;
+  memcpy (res->rules, reds, rules_size);
   return res;
 }
 
@@ -128,10 +119,6 @@ state_number nstates = 0;
    accessing symbol: $end.  */
 state *final_state = NULL;
 
-#define STATE_ALLOC(Nitems)						\
-  (state *) xcalloc ((sizeof (state)	 		       		\
-		      + (Nitems - 1) * sizeof (item_number)),		\
-		     1)
 
 /*------------------------------------------------------------------.
 | Create a new state with ACCESSING_SYMBOL, for those items.  Store |
@@ -140,21 +127,25 @@ state *final_state = NULL;
 
 state *
 state_new (symbol_number accessing_symbol,
-	   size_t core_size, item_number *core)
+	   size_t nitems, item_number *core)
 {
   state *res;
+  size_t items_size = nitems * sizeof *core;
 
   if (STATE_NUMBER_MAXIMUM <= nstates)
     abort ();
 
-  res = STATE_ALLOC (core_size);
+  res = xmalloc (offsetof (state, items) + items_size);
+  res->number = nstates++;
   res->accessing_symbol = accessing_symbol;
-  res->number = nstates;
-  ++nstates;
+  res->transitions = NULL;
+  res->reductions = NULL;
+  res->errs = NULL;
+  res->consistent = 0;
   res->solved_conflicts = NULL;
 
-  res->nitems = core_size;
-  memcpy (res->items, core, core_size * sizeof (core[0]));
+  res->nitems = nitems;
+  memcpy (res->items, core, items_size);
 
   state_hash_insert (res);
 
@@ -266,7 +257,7 @@ state_rule_lookaheads_print (state *s, rule *r, FILE *out)
 static struct hash_table *state_table = NULL;
 
 /* Two states are equal if they have the same core items.  */
-static bool
+static inline bool
 state_compare (state const *s1, state const *s2)
 {
   int i;
@@ -281,17 +272,29 @@ state_compare (state const *s1, state const *s2)
   return true;
 }
 
-static unsigned int
+static bool
+state_comparator (void const *s1, void const *s2)
+{
+  return state_compare (s1, s2);
+}
+
+static inline unsigned int
 state_hash (state const *s, unsigned int tablesize)
 {
   /* Add up the state's item numbers to get a hash key.  */
-  int key = 0;
+  unsigned int key = 0;
   int i;
   for (i = 0; i < s->nitems; ++i)
     key += s->items[i];
   return key % tablesize;
 }
 
+static unsigned int
+state_hasher (void const *s, unsigned int tablesize)
+{
+  return state_hash (s, tablesize);
+}
+
 
 /*-------------------------------.
 | Create the states hash table.  |
@@ -302,9 +305,9 @@ state_hash_new (void)
 {
   state_table = hash_initialize (HT_INITIAL_CAPACITY,
 				 NULL,
-				 (Hash_hasher) state_hash,
-				 (Hash_comparator) state_compare,
-				 (Hash_data_freer) NULL);
+				 state_hasher,
+				 state_comparator,
+				 NULL);
 }
 
 
@@ -336,13 +339,14 @@ state_hash_insert (state *s)
 `------------------------------------------------------------------*/
 
 state *
-state_hash_lookup (size_t core_size, item_number *core)
+state_hash_lookup (size_t nitems, item_number *core)
 {
-  state *probe = STATE_ALLOC (core_size);
+  size_t items_size = nitems * sizeof *core;
+  state *probe = xmalloc (offsetof (state, items) + items_size);
   state *entry;
 
-  probe->nitems = core_size;
-  memcpy (probe->items, core, core_size * sizeof (core[0]));
+  probe->nitems = nitems;
+  memcpy (probe->items, core, items_size);
   entry = hash_lookup (state_table, probe);
   free (probe);
   return entry;
