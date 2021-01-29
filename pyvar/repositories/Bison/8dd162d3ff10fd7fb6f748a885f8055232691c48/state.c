@@ -102,7 +102,7 @@ reductions_new (int num, rule **reds)
   size_t rules_size = num * sizeof *reds;
   reductions *res = xmalloc (offsetof (reductions, rules) + rules_size);
   res->num = num;
-  res->lookaheads = NULL;
+  res->look_ahead_tokens = NULL;
   memcpy (res->rules, reds, rules_size);
   return res;
 }
@@ -219,26 +219,26 @@ state_errs_set (state *s, int num, symbol **tokens)
 
 
 
-/*-----------------------------------------------------.
-| Print on OUT all the lookaheads such that S wants to |
-| reduce R.                                            |
-`-----------------------------------------------------*/
+/*---------------------------------------------------.
+| Print on OUT all the look-ahead tokens such that S |
+| wants to reduce R.                                 |
+`---------------------------------------------------*/
 
 void
-state_rule_lookaheads_print (state *s, rule *r, FILE *out)
+state_rule_look_ahead_tokens_print (state *s, rule *r, FILE *out)
 {
   /* Find the reduction we are handling.  */
   reductions *reds = s->reductions;
   int red = state_reduction_find (s, r);
 
   /* Print them if there are.  */
-  if (reds->lookaheads && red != -1)
+  if (reds->look_ahead_tokens && red != -1)
     {
       bitset_iterator biter;
       int k;
       char const *sep = "";
       fprintf (out, "  [");
-      BITSET_FOR_EACH (biter, reds->lookaheads[red], k, 0)
+      BITSET_FOR_EACH (biter, reds->look_ahead_tokens[red], k, 0)
 	{
 	  fprintf (out, "%s%s", sep, symbols[k]->tag);
 	  sep = ", ";
