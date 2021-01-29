@@ -218,7 +218,7 @@ state_reductions_set (state *s, int num, rule **reds)
 
 
 int
-state_reduction_find (state *s, rule *r)
+state_reduction_find (state *s, rule const *r)
 {
   reductions *reds = s->reductions;
   for (int i = 0; i < reds->num; ++i)
@@ -247,7 +247,7 @@ state_errs_set (state *s, int num, symbol **tokens)
 `--------------------------------------------------*/
 
 void
-state_rule_lookahead_tokens_print (state *s, rule *r, FILE *out)
+state_rule_lookahead_tokens_print (state *s, rule const *r, FILE *out)
 {
   /* Find the reduction we are handling.  */
   reductions *reds = s->reductions;
@@ -270,7 +270,7 @@ state_rule_lookahead_tokens_print (state *s, rule *r, FILE *out)
 }
 
 void
-state_rule_lookahead_tokens_print_xml (state *s, rule *r,
+state_rule_lookahead_tokens_print_xml (state *s, rule const *r,
                                        FILE *out, int level)
 {
   /* Find the reduction we are handling.  */
