@@ -91,14 +91,17 @@ set_goto_map (void)
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
 	  ngotos++;
-	  if (! ngotos)
+
+	  /* Abort if (ngotos + 1) would overflow.  */
+	  if (ngotos == GOTO_NUMBER_MAXIMUM)
 	    abort ();
+
 	  goto_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
 	}
     }
 
   {
-    int k = 0;
+    goto_number k = 0;
     int i;
     for (i = ntokens; i < nsyms; i++)
       {
@@ -122,7 +125,7 @@ set_goto_map (void)
       int i;
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
-	  int k = temp_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
+	  goto_number k = temp_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
 	  from_state[k] = s;
 	  to_state[k] = sp->states[i]->number;
 	}
@@ -137,12 +140,12 @@ set_goto_map (void)
 | Map a state/symbol pair into its numeric representation.  |
 `----------------------------------------------------------*/
 
-static int
+static goto_number
 map_goto (state_number s0, symbol_number sym)
 {
-  int high;
-  int low;
-  int middle;
+  goto_number high;
+  goto_number low;
+  goto_number middle;
   state_number s;
 
   low = goto_map[sym - ntokens];
@@ -169,9 +172,9 @@ initialize_F (void)
 {
   goto_number **reads = CALLOC (reads, ngotos);
   goto_number *edge = CALLOC (edge, ngotos + 1);
-  int nedges = 0;
+  goto_number nedges = 0;
 
-  int i;
+  goto_number i;
 
   F = bitsetv_create (ngotos, ntokens, BITSET_FIXED);
 
@@ -195,7 +198,7 @@ initialize_F (void)
 	{
 	  CALLOC (reads[i], nedges + 1);
 	  memcpy (reads[i], edge, nedges * sizeof (edge[0]));
-	  reads[i][nedges] = -1;
+	  reads[i][nedges] = END_NODE;
 	  nedges = 0;
 	}
     }
@@ -211,7 +214,7 @@ initialize_F (void)
 
 
 static void
-add_lookback_edge (state *s, rule *r, int gotono)
+add_lookback_edge (state *s, rule *r, goto_number gotono)
 {
   int ri = state_reduction_find (s, r);
   goto_list *sp = MALLOC (sp, 1);
@@ -227,7 +230,7 @@ build_relations (void)
 {
   goto_number *edge = CALLOC (edge, ngotos + 1);
   state_number *states1 = CALLOC (states1, ritem_longest_rhs () + 1);
-  int i;
+  goto_number i;
 
   CALLOC (includes, ngotos);
 
@@ -279,7 +282,7 @@ build_relations (void)
 	  CALLOC (includes[i], nedges + 1);
 	  for (j = 0; j < nedges; j++)
 	    includes[i][j] = edge[j];
-	  includes[i][nedges] = -1;
+	  includes[i][nedges] = END_NODE;
 	}
     }
 
@@ -294,7 +297,7 @@ build_relations (void)
 static void
 compute_FOLLOWS (void)
 {
-  int i;
+  goto_number i;
 
   relation_digraph (includes, ngotos, &F);
 
