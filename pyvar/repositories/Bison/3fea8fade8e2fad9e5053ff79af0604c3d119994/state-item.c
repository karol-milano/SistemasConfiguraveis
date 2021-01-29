@@ -35,7 +35,7 @@ size_t nstate_items;
 state_item_number *state_item_map;
 state_item *state_items;
 
-// hash functions for index -> bitset hash maps
+// Hash functions for index -> bitset hash maps.
 typedef struct
 {
   int key;
@@ -293,10 +293,9 @@ init_prods (void)
     }
 }
 
-/* Since lookaheads are only generated for reductions,
-  we need to propogate lookahead sets backwards as
-  the searches require each state_item to have a lookahead.
- */
+/* Since lookaheads are only generated for reductions, we need to
+   propagate lookahead sets backwards as the searches require each
+   state_item to have a lookahead. */
 static inline void
 gen_lookaheads (void)
 {
