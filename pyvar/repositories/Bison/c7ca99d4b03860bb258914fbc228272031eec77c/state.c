@@ -20,6 +20,7 @@
 
 
 #include "system.h"
+#include "hash.h"
 #include "complain.h"
 #include "gram.h"
 #include "state.h"
@@ -30,9 +31,9 @@
 			`-------------------*/
 
 
-/*---------------------------------.
-| Create a new array of N shitfs.  |
-`---------------------------------*/
+/*---------------------------------------.
+| Create a new array of N shifts/gotos.  |
+`---------------------------------------*/
 
 #define SHIFTS_ALLOC(Nshifts)						\
   (shifts *) xcalloc ((unsigned) (sizeof (shifts) 			\
@@ -116,6 +117,10 @@ state_number_t nstates = 0;
    accessing symbol: EOF.  */
 state_t *final_state = NULL;
 
+#define STATE_ALLOC(Nitems)						\
+  (state_t *) xcalloc ((unsigned) (sizeof (state_t) 			\
+                                  + (Nitems - 1) * sizeof (item_number_t)), 1)
+
 /*------------------------------------------------------------.
 | Create a new state with ACCESSING_SYMBOL, for those items.  |
 `------------------------------------------------------------*/
@@ -129,10 +134,6 @@ state_new (symbol_number_t accessing_symbol,
   if (nstates >= STATE_NUMBER_MAX)
     fatal (_("too many states (max %d)"), STATE_NUMBER_MAX);
 
-#define STATE_ALLOC(Nitems)						\
-  (state_t *) xcalloc ((unsigned) (sizeof (state_t) 			\
-                                  + (Nitems - 1) * sizeof (item_number_t)), 1)
-
   res = STATE_ALLOC (core_size);
   res->accessing_symbol = accessing_symbol;
   res->number = nstates;
@@ -177,3 +178,119 @@ state_rule_lookaheads_print (state_t *state, rule_t *rule, FILE *out)
       fprintf (out, "]");
     }
 }
+
+
+/*----------------------.
+| A state hash table.  |
+`----------------------*/
+
+/* Initial capacity of states hash table.  */
+#define HT_INITIAL_CAPACITY 257
+
+static struct hash_table *state_table = NULL;
+
+/* Two states are equal if they have the same core items.  */
+static bool
+state_compare (const state_t *s1, const state_t *s2)
+{
+  int i;
+
+  if (s1->nitems != s2->nitems)
+    return FALSE;
+
+  for (i = 0; i < s1->nitems; ++i)
+    if (s1->items[i] != s2->items[i])
+      return FALSE;
+
+  return TRUE;
+}
+
+static unsigned int
+state_hash (const state_t *state, unsigned int tablesize)
+{
+  /* Add up the state's item numbers to get a hash key.  */
+  int key = 0;
+  int i;
+  for (i = 0; i < state->nitems; ++i)
+    key += state->items[i];
+  return key % tablesize;
+}
+
+
+/*-------------------------------.
+| Create the states hash table.  |
+`-------------------------------*/
+
+void
+state_hash_new (void)
+{
+  state_table = hash_initialize (HT_INITIAL_CAPACITY,
+				 NULL,
+				 (Hash_hasher) state_hash,
+				 (Hash_comparator) state_compare,
+				 (Hash_data_freer) NULL);
+}
+
+
+/*---------------------------------------------.
+| Free the states hash table, not the states.  |
+`---------------------------------------------*/
+
+void
+state_hash_free (void)
+{
+  hash_free (state_table);
+}
+
+
+/*---------------------------------------.
+| Insert STATE in the state hash table.  |
+`---------------------------------------*/
+
+void
+state_hash_insert (state_t *state)
+{
+  hash_insert (state_table, state);
+}
+
+
+/*------------------------------------------------------------------.
+| Find the state associated to the CORE, and return it.  If it does |
+| not exist yet, return NULL.                                       |
+`------------------------------------------------------------------*/
+
+state_t *
+state_hash_lookup (size_t core_size, item_number_t *core)
+{
+  state_t *probe = STATE_ALLOC (core_size);
+  state_t *entry;
+
+  probe->nitems = core_size;
+  memcpy (probe->items, core, core_size * sizeof (core[0]));
+  entry = hash_lookup (state_table, probe);
+  free (probe);
+  return entry;
+}
+
+/* All the decorated states, indexed by the state number.  */
+state_t **states = NULL;
+
+
+/*----------------------.
+| Free all the states.  |
+`----------------------*/
+
+void
+states_free (void)
+{
+  state_number_t i;
+
+  for (i = 0; i < nstates; ++i)
+    {
+      free (states[i]->shifts);
+      XFREE (states[i]->reductions);
+      free (states[i]->errs);
+      free (states[i]);
+    }
+  XFREE (states);
+}
