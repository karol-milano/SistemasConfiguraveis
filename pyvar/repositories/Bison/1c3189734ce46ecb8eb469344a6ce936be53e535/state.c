@@ -231,7 +231,7 @@ state_reductions_set (state *s, int num, rule **reds)
 
 
 int
-state_reduction_find (state *s, rule const *r)
+state_reduction_find (state const *s, rule const *r)
 {
   reductions *reds = s->reductions;
   for (int i = 0; i < reds->num; ++i)
@@ -260,7 +260,7 @@ state_errs_set (state *s, int num, symbol **tokens)
 `--------------------------------------------------*/
 
 void
-state_rule_lookahead_tokens_print (state *s, rule const *r, FILE *out)
+state_rule_lookahead_tokens_print (state const *s, rule const *r, FILE *out)
 {
   /* Find the reduction we are handling.  */
   reductions *reds = s->reductions;
@@ -283,7 +283,7 @@ state_rule_lookahead_tokens_print (state *s, rule const *r, FILE *out)
 }
 
 void
-state_rule_lookahead_tokens_print_xml (state *s, rule const *r,
+state_rule_lookahead_tokens_print_xml (state const *s, rule const *r,
                                        FILE *out, int level)
 {
   /* Find the reduction we are handling.  */
@@ -395,7 +395,7 @@ state_hash_insert (state *s)
 `------------------------------------------------------------------*/
 
 state *
-state_hash_lookup (size_t nitems, item_index *core)
+state_hash_lookup (size_t nitems, const item_index *core)
 {
   size_t items_size = nitems * sizeof *core;
   state *probe = xmalloc (offsetof (state, items) + items_size);
