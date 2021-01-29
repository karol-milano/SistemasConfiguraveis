@@ -93,7 +93,7 @@ no_reduce_bitset_init (state const *s, bitset *no_reduce_set)
     bitset_set (*no_reduce_set, TRANSITION_SYMBOL (s->transitions, n));
   for (n = 0; n < s->errs->num; ++n)
     if (s->errs->symbols[n])
-      bitset_set (*no_reduce_set, s->errs->symbols[n]->number);
+      bitset_set (*no_reduce_set, s->errs->symbols[n]->content->number);
 }
 
 static void
