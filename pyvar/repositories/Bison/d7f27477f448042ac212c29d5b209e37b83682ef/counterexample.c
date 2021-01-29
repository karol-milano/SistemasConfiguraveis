@@ -84,7 +84,7 @@ static counterexample *
 new_counterexample (derivation *d1, derivation *d2,
                     bool u, bool t)
 {
-  counterexample *res = xmalloc (sizeof (counterexample));
+  counterexample *res = xmalloc (sizeof *res);
   res->d1 = d1;
   res->d2 = d2;
   res->unifying = u;
@@ -144,7 +144,7 @@ typedef struct si_bfs_node
 static si_bfs_node *
 si_bfs_new (state_item_number si, si_bfs_node *parent)
 {
-  si_bfs_node *res = xcalloc (1, sizeof (si_bfs_node));
+  si_bfs_node *res = xcalloc (1, sizeof *res);
   res->si = si;
   res->parent = parent;
   res->reference_count = 1;
@@ -528,7 +528,7 @@ typedef struct
 static search_state *
 initial_search_state (state_item *conflict1, state_item *conflict2)
 {
-  search_state *res = xmalloc (sizeof (search_state));
+  search_state *res = xmalloc (sizeof *res);
   res->states[0] = new_parse_state (conflict1);
   res->states[1] = new_parse_state (conflict2);
   parse_state_retain (res->states[0]);
@@ -540,7 +540,7 @@ initial_search_state (state_item *conflict1, state_item *conflict2)
 static search_state *
 new_search_state (parse_state *ps1, parse_state *ps2, int complexity)
 {
-  search_state *res = xmalloc (sizeof (search_state));
+  search_state *res = xmalloc (sizeof *res);
   res->states[0] = ps1;
   res->states[1] = ps2;
   parse_state_retain (res->states[0]);
@@ -552,8 +552,8 @@ new_search_state (parse_state *ps1, parse_state *ps2, int complexity)
 static search_state *
 copy_search_state (search_state *parent)
 {
-  search_state *res = xmalloc (sizeof (search_state));
-  memcpy (res, parent, sizeof (search_state));
+  search_state *res = xmalloc (sizeof *res);
+  *res = *parent;
   parse_state_retain (res->states[0]);
   parse_state_retain (res->states[1]);
   return res;
@@ -709,7 +709,7 @@ ssb_append (search_state *ss)
   parse_state_free_contents_early (ss->states[1]);
   parse_state_retain (ss->states[0]);
   parse_state_retain (ss->states[1]);
-  search_state_bundle *ssb = xmalloc (sizeof (search_state_bundle));
+  search_state_bundle *ssb = xmalloc (sizeof *ssb);
   ssb->complexity = ss->complexity;
   gl_list_node_t n = gl_list_search (ssb_queue, ssb);
   if (!n)
@@ -1295,7 +1295,7 @@ counterexample_report_state (const state *s, FILE *out, const char *prefix)
           {
             item_number conf = *state_items[j].item;
             if (item_number_is_symbol_number (conf)
-              && bitset_test (reds->lookahead_tokens[i], conf))
+                && bitset_test (reds->lookahead_tokens[i], conf))
               counterexample_report_shift_reduce (c1, j, conf, out, prefix);
           }
       for (int j = i+1; j < reds->num; ++j)
