@@ -25,28 +25,30 @@
    The entry point is generate_states.  */
 
 #include "system.h"
-#include "bitset.h"
-#include "quotearg.h"
-#include "symtab.h"
-#include "gram.h"
+
+#include <bitset.h>
+#include <quotearg.h>
+
+#include "LR0.h"
+#include "closure.h"
+#include "complain.h"
 #include "getargs.h"
-#include "reader.h"
 #include "gram.h"
-#include "state.h"
-#include "complain.h"
-#include "closure.h"
-#include "LR0.h"
+#include "gram.h"
 #include "lalr.h"
+#include "reader.h"
 #include "reduce.h"
+#include "state.h"
+#include "symtab.h"
 
-typedef struct state_list_s
+typedef struct state_list
 {
-  struct state_list_s *next;
-  state_t *state;
-} state_list_t;
+  struct state_list *next;
+  state *state;
+} state_list;
 
-static state_list_t *first_state = NULL;
-static state_list_t *last_state = NULL;
+static state_list *first_state = NULL;
+static state_list *last_state = NULL;
 
 
 /*------------------------------------------------------------------.
@@ -54,24 +56,23 @@ static state_list_t *last_state = NULL;
 | later examination, in order to find its transitions.  Return it.  |
 `------------------------------------------------------------------*/
 
-static state_t *
-state_list_append (symbol_number_t symbol,
-		   size_t core_size, item_number_t *core)
+static state *
+state_list_append (symbol_number sym, size_t core_size, item_number *core)
 {
-  state_list_t *node = XMALLOC (state_list_t, 1);
-  state_t *state = state_new (symbol, core_size, core);
+  state_list *node = XMALLOC (state_list, 1);
+  state *s = state_new (sym, core_size, core);
 
   if (trace_flag & trace_automaton)
     fprintf (stderr, "state_list_append (state = %d, symbol = %d (%s))\n",
-	     nstates, symbol, symbols[symbol]->tag);
+	     nstates, sym, symbols[sym]->tag);
 
   /* If this is the endtoken, and this is not the initial state, then
      this is the final state.  */
-  if (symbol == 0 && first_state)
-    final_state = state;
+  if (sym == 0 && first_state)
+    final_state = s;
 
   node->next = NULL;
-  node->state = state;
+  node->state = s;
 
   if (!first_state)
     first_state = node;
@@ -79,26 +80,26 @@ state_list_append (symbol_number_t symbol,
     last_state->next = node;
   last_state = node;
 
-  return state;
+  return s;
 }
 
 static int nshifts;
-static symbol_number_t *shift_symbol = NULL;
+static symbol_number *shift_symbol = NULL;
 
-static rule_t **redset = NULL;
-static state_t **shiftset = NULL;
+static rule **redset = NULL;
+static state **shiftset = NULL;
 
-static item_number_t **kernel_base = NULL;
+static item_number **kernel_base = NULL;
 static int *kernel_size = NULL;
-static item_number_t *kernel_items = NULL;
+static item_number *kernel_items = NULL;
 
 
 static void
 allocate_itemsets (void)
 {
-  symbol_number_t i;
-  rule_number_t r;
-  item_number_t *rhsp;
+  symbol_number i;
+  rule_number r;
+  item_number *rhsp;
 
   /* Count the number of occurrences of all the symbols in RITEMS.
      Note that useless productions (hence useless nonterminals) are
@@ -116,13 +117,13 @@ allocate_itemsets (void)
 
   /* See comments before new_itemsets.  All the vectors of items
      live inside KERNEL_ITEMS.  The number of active items after
-     some symbol cannot be more than the number of times that symbol
-     appears as an item, which is SYMBOL_COUNT[SYMBOL].
+     some symbol S cannot be more than the number of times that S
+     appears as an item, which is SYMBOL_COUNT[S].
      We allocate that much space for each symbol.  */
 
-  kernel_base = XCALLOC (item_number_t *, nsyms);
+  kernel_base = XCALLOC (item_number *, nsyms);
   if (count)
-    kernel_items = XCALLOC (item_number_t, count);
+    kernel_items = XCALLOC (item_number, count);
 
   count = 0;
   for (i = 0; i < nsyms; i++)
@@ -141,10 +142,10 @@ allocate_storage (void)
 {
   allocate_itemsets ();
 
-  shiftset = XCALLOC (state_t *, nsyms);
-  redset = XCALLOC (rule_t *, nrules);
+  shiftset = XCALLOC (state *, nsyms);
+  redset = XCALLOC (rule *, nrules);
   state_hash_new ();
-  shift_symbol = XCALLOC (symbol_number_t, nsyms);
+  shift_symbol = XCALLOC (symbol_number, nsyms);
 }
 
 
@@ -164,7 +165,7 @@ free_storage (void)
 
 
 /*---------------------------------------------------------------.
-| Find which symbols can be shifted in STATE, and for each one   |
+| Find which symbols can be shifted in S, and for each one       |
 | record which items would be active after that shift.  Uses the |
 | contents of itemset.                                           |
 |                                                                |
@@ -175,13 +176,12 @@ free_storage (void)
 `---------------------------------------------------------------*/
 
 static void
-new_itemsets (state_t *state)
+new_itemsets (state *s)
 {
   int i;
 
   if (trace_flag & trace_automaton)
-    fprintf (stderr, "Entering new_itemsets, state = %d\n",
-	     state->number);
+    fprintf (stderr, "Entering new_itemsets, state = %d\n", s->number);
 
   for (i = 0; i < nsyms; i++)
     kernel_size[i] = 0;
@@ -191,39 +191,38 @@ new_itemsets (state_t *state)
   for (i = 0; i < nritemset; ++i)
     if (ritem[itemset[i]] >= 0)
       {
-	symbol_number_t symbol
-	  = item_number_as_symbol_number (ritem[itemset[i]]);
-	if (!kernel_size[symbol])
+	symbol_number sym = item_number_as_symbol_number (ritem[itemset[i]]);
+	if (!kernel_size[sym])
 	  {
-	    shift_symbol[nshifts] = symbol;
+	    shift_symbol[nshifts] = sym;
 	    nshifts++;
 	  }
 
-	kernel_base[symbol][kernel_size[symbol]] = itemset[i] + 1;
-	kernel_size[symbol]++;
+	kernel_base[sym][kernel_size[sym]] = itemset[i] + 1;
+	kernel_size[sym]++;
       }
 }
 
 
 
-/*-----------------------------------------------------------------.
-| Find the state we would get to (from the current state) by       |
-| shifting SYMBOL.  Create a new state if no equivalent one exists |
-| already.  Used by append_states.                                 |
-`-----------------------------------------------------------------*/
+/*--------------------------------------------------------------.
+| Find the state we would get to (from the current state) by    |
+| shifting SYM.  Create a new state if no equivalent one exists |
+| already.  Used by append_states.                              |
+`--------------------------------------------------------------*/
 
-static state_t *
-get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
+static state *
+get_state (symbol_number sym, size_t core_size, item_number *core)
 {
-  state_t *sp;
+  state *sp;
 
   if (trace_flag & trace_automaton)
     fprintf (stderr, "Entering get_state, symbol = %d (%s)\n",
-	     symbol, symbols[symbol]->tag);
+	     sym, symbols[sym]->tag);
 
   sp = state_hash_lookup (core_size, core);
   if (!sp)
-    sp = state_list_append (symbol, core_size, core);
+    sp = state_list_append (sym, core_size, core);
 
   if (trace_flag & trace_automaton)
     fprintf (stderr, "Exiting get_state => %d\n", sp->number);
@@ -233,41 +232,34 @@ get_state (symbol_number_t symbol, size_t core_size, item_number_t *core)
 
 /*---------------------------------------------------------------.
 | Use the information computed by new_itemsets to find the state |
-| numbers reached by each shift transition from STATE.           |
+| numbers reached by each shift transition from S.		 |
 |                                                                |
 | SHIFTSET is set up as a vector of those states.                |
 `---------------------------------------------------------------*/
 
 static void
-append_states (state_t *state)
+append_states (state *s)
 {
   int i;
-  int j;
-  symbol_number_t symbol;
 
   if (trace_flag & trace_automaton)
-    fprintf (stderr, "Entering append_states, state = %d\n",
-	     state->number);
+    fprintf (stderr, "Entering append_states, state = %d\n", s->number);
 
-  /* first sort shift_symbol into increasing order */
+  /* First sort shift_symbol into increasing order.  */
 
   for (i = 1; i < nshifts; i++)
     {
-      symbol = shift_symbol[i];
-      j = i;
-      while (j > 0 && shift_symbol[j - 1] > symbol)
-	{
-	  shift_symbol[j] = shift_symbol[j - 1];
-	  j--;
-	}
-      shift_symbol[j] = symbol;
+      symbol_number sym = shift_symbol[i];
+      int j;
+      for (j = i; 0 < j && sym < shift_symbol [j - 1]; j--)
+	shift_symbol[j] = shift_symbol[j - 1];
+      shift_symbol[j] = sym;
     }
 
   for (i = 0; i < nshifts; i++)
     {
-      symbol = shift_symbol[i];
-      shiftset[i] = get_state (symbol,
-			       kernel_size[symbol], kernel_base[symbol]);
+      symbol_number sym = shift_symbol[i];
+      shiftset[i] = get_state (sym, kernel_size[sym], kernel_base[sym]);
     }
 }
 
@@ -279,7 +271,7 @@ append_states (state_t *state)
 `----------------------------------------------------------------*/
 
 static void
-save_reductions (state_t *state)
+save_reductions (state *s)
 {
   int count = 0;
   int i;
@@ -293,7 +285,7 @@ save_reductions (state_t *state)
     }
 
   /* Make a reductions structure and copy the data into it.  */
-  state_reductions_set (state, count, redset);
+  state_reductions_set (s, count, redset);
 }
 
 
@@ -304,23 +296,23 @@ save_reductions (state_t *state)
 static void
 set_states (void)
 {
-  states = XCALLOC (state_t *, nstates);
+  states = XCALLOC (state *, nstates);
 
   while (first_state)
     {
-      state_list_t *this = first_state;
+      state_list *this = first_state;
 
       /* Pessimization, but simplification of the code: make sure all
 	 the states have valid transitions and reductions members,
 	 even if reduced to 0.  It is too soon for errs, which are
 	 computed later, but set_conflicts.  */
-      state_t *state = this->state;
-      if (!state->transitions)
-	state_transitions_set (state, 0, 0);
-      if (!state->reductions)
-	state_reductions_set (state, 0, 0);
+      state *s = this->state;
+      if (!s->transitions)
+	state_transitions_set (s, 0, 0);
+      if (!s->reductions)
+	state_reductions_set (s, 0, 0);
 
-      states[state->number] = state;
+      states[s->number] = s;
 
       first_state = this->next;
       free (this);
@@ -338,7 +330,7 @@ set_states (void)
 void
 generate_states (void)
 {
-  state_list_t *list = NULL;
+  state_list *list = NULL;
   allocate_storage ();
   new_closure (nritems);
 
@@ -352,28 +344,28 @@ generate_states (void)
 
   while (list)
     {
-      state_t *state = list->state;
+      state *s = list->state;
       if (trace_flag & trace_automaton)
 	fprintf (stderr, "Processing state %d (reached by %s)\n",
-		 state->number,
-		 symbols[state->accessing_symbol]->tag);
+		 s->number,
+		 symbols[s->accessing_symbol]->tag);
       /* Set up ruleset and itemset for the transitions out of this
          state.  ruleset gets a 1 bit for each rule that could reduce
          now.  itemset gets a vector of all the items that could be
          accepted next.  */
-      closure (state->items, state->nitems);
+      closure (s->items, s->nitems);
       /* Record the reductions allowed out of this state.  */
-      save_reductions (state);
+      save_reductions (s);
       /* Find the itemsets of the states that shifts can reach.  */
-      new_itemsets (state);
+      new_itemsets (s);
       /* Find or create the core structures for those states.  */
-      append_states (state);
+      append_states (s);
 
       /* Create the shifts structures for the shifts to those states,
 	 now that the state numbers transitioning to are known.  */
-      state_transitions_set (state, nshifts, shiftset);
+      state_transitions_set (s, nshifts, shiftset);
 
-      /* States are queued when they are created; process them all.
+      /* states are queued when they are created; process them all.
 	 */
       list = list->next;
     }
