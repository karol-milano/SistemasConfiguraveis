@@ -1286,6 +1286,7 @@ counterexample_report_state (const state *s, FILE *out, const char *prefix)
 {
   const state_number sn = s->number;
   const reductions *reds = s->reductions;
+  bitset lookahead_tokens = bitset_create (ntokens, BITSET_FIXED);
   for (int i = 0; i < reds->num; ++i)
     {
       const rule *r1 = reds->rules[i];
@@ -1300,20 +1301,20 @@ counterexample_report_state (const state *s, FILE *out, const char *prefix)
           }
       for (int j = i+1; j < reds->num; ++j)
         {
-          bitset conf = bitset_create (ntokens, BITSET_FIXED);
           const rule *r2 = reds->rules[j];
-          bitset_intersection (conf,
+          // Conflicts: common lookaheads.
+          bitset_intersection (lookahead_tokens,
                                reds->lookahead_tokens[i],
                                reds->lookahead_tokens[j]);
-          if (!bitset_empty_p (conf))
+          if (!bitset_empty_p (lookahead_tokens))
             for (state_item_number c2 = state_item_map[sn]; c2 < state_item_map[sn + 1]; ++c2)
               if (!SI_DISABLED (c2)
                   && item_rule (state_items[c2].item) == r2)
                 {
-                  counterexample_report_reduce_reduce (c1, c2, conf, out, prefix);
+                  counterexample_report_reduce_reduce (c1, c2, lookahead_tokens, out, prefix);
                   break;
                 }
-          bitset_free (conf);
         }
     }
+  bitset_free (lookahead_tokens);
 }
