@@ -43,9 +43,10 @@
 #include "symtab.h"
 
 goto_number *goto_map;
-static goto_number ngotos;
+goto_number ngotos;
 state_number *from_state;
 state_number *to_state;
+bitsetv goto_follows = NULL;
 
 /* Linked list of goto numbers.  */
 typedef struct goto_list
@@ -64,17 +65,13 @@ static bitsetv LA = NULL;
 size_t nLA;
 
 
-/* And for the famous F variable, which name is so descriptive that a
-   comment is hardly needed.  <grin>.  */
-static bitsetv F = NULL;
-
 static goto_number **includes;
 static goto_list **lookback;
 
 
 
 
-static void
+void
 set_goto_map (void)
 {
   state_number s;
@@ -134,12 +131,7 @@ set_goto_map (void)
 }
 
 
-
-/*----------------------------------------------------------.
-| Map a state/symbol pair into its numeric representation.  |
-`----------------------------------------------------------*/
-
-static goto_number
+goto_number
 map_goto (state_number s0, symbol_number sym)
 {
   goto_number high;
@@ -174,7 +166,7 @@ initialize_F (void)
 
   goto_number i;
 
-  F = bitsetv_create (ngotos, ntokens, BITSET_FIXED);
+  goto_follows = bitsetv_create (ngotos, ntokens, BITSET_FIXED);
 
   for (i = 0; i < ngotos; i++)
     {
@@ -183,7 +175,7 @@ initialize_F (void)
 
       int j;
       FOR_EACH_SHIFT (sp, j)
-	bitset_set (F[i], TRANSITION_SYMBOL (sp, j));
+	bitset_set (goto_follows[i], TRANSITION_SYMBOL (sp, j));
 
       for (; j < sp->num; j++)
 	{
@@ -203,7 +195,7 @@ initialize_F (void)
 	}
     }
 
-  relation_digraph (reads, ngotos, &F);
+  relation_digraph (reads, ngotos, &goto_follows);
 
   for (i = 0; i < ngotos; i++)
     free (reads[i]);
@@ -264,7 +256,7 @@ build_relations (void)
 	    {
 	      done = true;
 	      /* Each rhs ends in a rule number, and there is a
-		 sentinel before the first rhs, so it is safe to
+		 sentinel (ritem[-1]=0) before the first rhs, so it is safe to
 		 decrement RP here.  */
 	      rp--;
 	      if (ISVAR (*rp))
@@ -303,7 +295,7 @@ compute_FOLLOWS (void)
 {
   goto_number i;
 
-  relation_digraph (includes, ngotos, &F);
+  relation_digraph (includes, ngotos, &goto_follows);
 
   for (i = 0; i < ngotos; i++)
     free (includes[i]);
@@ -320,14 +312,13 @@ compute_lookahead_tokens (void)
 
   for (i = 0; i < nLA; i++)
     for (sp = lookback[i]; sp; sp = sp->next)
-      bitset_or (LA[i], LA[i], F[sp->value]);
+      bitset_or (LA[i], LA[i], goto_follows[sp->value]);
 
   /* Free LOOKBACK. */
   for (i = 0; i < nLA; i++)
     LIST_FREE (goto_list, lookback[i]);
 
   free (lookback);
-  bitsetv_free (F);
 }
 
 
@@ -373,7 +364,7 @@ state_lookahead_tokens_count (state *s, bool default_rule_only_for_accept)
 | Compute LA, NLA, and the lookahead_tokens members.  |
 `----------------------------------------------------*/
 
-static void
+void
 initialize_LA (void)
 {
   state_number i;
@@ -395,7 +386,6 @@ initialize_LA (void)
     nLA = 1;
 
   pLA = LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
-  lookback = xcalloc (nLA, sizeof *lookback);
 
   /* Initialize the members LOOKAHEAD_TOKENS for each state whose reductions
      require lookahead tokens.  */
@@ -454,6 +444,7 @@ lalr (void)
   initialize_LA ();
   set_goto_map ();
   initialize_F ();
+  lookback = xcalloc (nLA, sizeof *lookback);
   build_relations ();
   compute_FOLLOWS ();
   compute_lookahead_tokens ();
