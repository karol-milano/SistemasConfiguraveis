@@ -54,8 +54,16 @@ typedef struct goto_list
   goto_number value;
 } goto_list;
 
+static goto_list *
+goto_list_new (goto_number value, struct goto_list *next)
+{
+  goto_list *res = xmalloc (sizeof *res);
+  res->next = next;
+  res->value = value;
+  return res;
+}
 
-/* LA is an NLA by NTOKENS matrix of bits.  LA[l, i] is 1 if the rule
+/* LA is an nLA by NTOKENS matrix of bits.  LA[l, i] is 1 if the rule
    LArule[l] is applicable in the appropriate state when the next
    token is symbol i.  If LA[l, i] and LA[l, j] are both 1 for i != j,
    it is a conflict.  */
@@ -232,10 +240,8 @@ static void
 add_lookback_edge (state *s, rule const *r, goto_number gotono)
 {
   int ri = state_reduction_find (s, r);
-  goto_list *sp = xmalloc (sizeof *sp);
-  sp->next = lookback[(s->reductions->lookahead_tokens - LA) + ri];
-  sp->value = gotono;
-  lookback[(s->reductions->lookahead_tokens - LA) + ri] = sp;
+  int idx = (s->reductions->lookahead_tokens - LA) + ri;
+  lookback[idx] = goto_list_new (gotono, lookback[idx]);
 }
 
 
