@@ -101,7 +101,7 @@ reductions_new (int num, rule **reds)
   size_t rules_size = num * sizeof *reds;
   reductions *res = xmalloc (offsetof (reductions, rules) + rules_size);
   res->num = num;
-  res->lookahead_tokens = NULL;
+  res->lookaheads = NULL;
   memcpy (res->rules, reds, rules_size);
   return res;
 }
@@ -260,20 +260,20 @@ state_errs_set (state *s, int num, symbol **tokens)
 `--------------------------------------------------*/
 
 void
-state_rule_lookahead_tokens_print (state const *s, rule const *r, FILE *out)
+state_rule_lookaheads_print (state const *s, rule const *r, FILE *out)
 {
   /* Find the reduction we are handling.  */
   reductions *reds = s->reductions;
   int red = state_reduction_find (s, r);
 
   /* Print them if there are.  */
-  if (reds->lookahead_tokens && red != -1)
+  if (reds->lookaheads && red != -1)
     {
       bitset_iterator biter;
       int k;
       char const *sep = "";
       fprintf (out, "  [");
-      BITSET_FOR_EACH (biter, reds->lookahead_tokens[red], k, 0)
+      BITSET_FOR_EACH (biter, reds->lookaheads[red], k, 0)
         {
           fprintf (out, "%s%s", sep, symbols[k]->tag);
           sep = ", ";
@@ -283,7 +283,7 @@ state_rule_lookahead_tokens_print (state const *s, rule const *r, FILE *out)
 }
 
 void
-state_rule_lookahead_tokens_print_xml (state const *s, rule const *r,
+state_rule_lookaheads_print_xml (state const *s, rule const *r,
                                        FILE *out, int level)
 {
   /* Find the reduction we are handling.  */
@@ -291,12 +291,12 @@ state_rule_lookahead_tokens_print_xml (state const *s, rule const *r,
   int red = state_reduction_find (s, r);
 
   /* Print them if there are.  */
-  if (reds->lookahead_tokens && red != -1)
+  if (reds->lookaheads && red != -1)
     {
       bitset_iterator biter;
       int k;
       xml_puts (out, level, "<lookaheads>");
-      BITSET_FOR_EACH (biter, reds->lookahead_tokens[red], k, 0)
+      BITSET_FOR_EACH (biter, reds->lookaheads[red], k, 0)
         {
           xml_printf (out, level + 1, "<symbol>%s</symbol>",
                       xml_escape (symbols[k]->tag));
