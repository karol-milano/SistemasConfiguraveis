@@ -60,7 +60,7 @@
 #define CUMULATIVE_TIME_LIMIT 120.0f
 
 // This is the fastest way to get the tail node from the gl_list API.
-gl_list_node_t
+static gl_list_node_t
 list_get_end (gl_list_t list)
 {
   gl_list_node_t sentinel = gl_list_add_last (list, NULL);
@@ -77,7 +77,7 @@ typedef struct
   bool timeout;
 } counterexample;
 
-counterexample *
+static counterexample *
 new_counterexample (derivation *d1, derivation *d2,
                     bool u, bool t)
 {
@@ -89,7 +89,7 @@ new_counterexample (derivation *d1, derivation *d2,
   return res;
 }
 
-void
+static void
 free_counterexample (counterexample *cex)
 {
   derivation_free (cex->d1);
@@ -97,7 +97,7 @@ free_counterexample (counterexample *cex)
   free (cex);
 }
 
-void
+static void
 print_counterexample (counterexample *cex)
 {
   FILE *out = stderr;
@@ -133,7 +133,7 @@ typedef struct si_bfs_node
   int reference_count;
 } si_bfs_node;
 
-si_bfs_node *
+static si_bfs_node *
 si_bfs_new (state_item_number si, si_bfs_node *parent)
 {
   si_bfs_node *res = xcalloc (1, sizeof (si_bfs_node));
@@ -154,7 +154,7 @@ si_bfs_contains (const si_bfs_node *n, state_item_number sin)
   return false;
 }
 
-void
+static void
 si_bfs_free (si_bfs_node *n)
 {
   if (n == NULL)
@@ -384,11 +384,10 @@ complete_diverging_example (symbol_number conflict_sym,
   return res;
 }
 
-/* iterates backwards through the shifts of the path in the
-  reduce conflict, and finds a path of shifts from the shift
-  conflict that goes through the same states.
- */
-gl_list_t
+/* Iterate backwards through the shifts of the path in the reduce
+   conflict, and find a path of shifts from the shift conflict that
+   goes through the same states. */
+static gl_list_t
 nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
 {
   gl_list_node_t tmp = gl_list_add_last (reduce_path, NULL);
@@ -483,7 +482,7 @@ nonunifying_shift_path (gl_list_t reduce_path, state_item *shift_conflict)
  * Construct a nonunifying counterexample from the shortest
  * lookahead-sensitive path.
  */
-counterexample *
+static counterexample *
 example_from_path (bool shift_reduce,
                    state_item_number itm2,
                    gl_list_t shortest_path, symbol_number next_sym)
@@ -604,7 +603,7 @@ ss_set_parse_state (search_state *ss, int idx, parse_state *ps)
  * which has its parse states unified at the beginning
  * but not the end of the example.
  */
-counterexample *
+static counterexample *
 complete_diverging_examples(search_state *ss,
                             symbol_number next_sym)
 {
@@ -630,7 +629,8 @@ typedef struct
   gl_list_t states;
   int complexity;
 } search_state_bundle;
-void
+
+static void
 ssb_free (search_state_bundle *ssb)
 {
   gl_list_free (ssb->states);
@@ -797,7 +797,7 @@ reduction_step (search_state *ss, const item_number *conflict_item,
  * the given subsequent next symbol on each path. If a reverse transition
  * cannot be made on both states, possible reverse productions are prepended
  */
-void
+static void
 search_state_prepend (search_state *ss, symbol_number sym, bitset guide)
 {
   (void) sym; // FIXME: Unused.
@@ -1042,7 +1042,7 @@ generate_next_states (search_state *ss, state_item *conflict1,
  * we are at and gives the appropriate counterexample
  * type based off of time constraints.
  */
-counterexample *
+static counterexample *
 unifying_example (state_item_number itm1,
                   state_item_number itm2,
                   bool shift_reduce,
