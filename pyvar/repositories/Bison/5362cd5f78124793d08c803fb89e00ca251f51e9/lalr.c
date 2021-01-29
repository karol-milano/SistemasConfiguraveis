@@ -1,4 +1,5 @@
-/* Compute look-ahead criteria for bison,
+/* Compute look-ahead criteria for Bison.
+
    Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
@@ -79,8 +80,8 @@ set_goto_map (void)
   state_number s;
   goto_number *temp_map;
 
-  goto_map = XCALLOC (goto_number, nvars + 1) - ntokens;
-  temp_map = XCALLOC (goto_number, nvars + 1) - ntokens;
+  CALLOC (goto_map, nvars + 1);
+  CALLOC (temp_map, nvars + 1);
 
   ngotos = 0;
   for (s = 0; s < nstates; ++s)
@@ -92,7 +93,7 @@ set_goto_map (void)
 	  if (ngotos >= GOTO_NUMBER_MAXIMUM)
 	    abort ();
 	  ngotos++;
-	  goto_map[TRANSITION_SYMBOL (sp, i)]++;
+	  goto_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
 	}
     }
 
@@ -101,19 +102,19 @@ set_goto_map (void)
     int i;
     for (i = ntokens; i < nsyms; i++)
       {
-	temp_map[i] = k;
-	k += goto_map[i];
+	temp_map[i - ntokens] = k;
+	k += goto_map[i - ntokens];
       }
 
     for (i = ntokens; i < nsyms; i++)
-      goto_map[i] = temp_map[i];
+      goto_map[i - ntokens] = temp_map[i - ntokens];
 
-    goto_map[nsyms] = ngotos;
-    temp_map[nsyms] = ngotos;
+    goto_map[nsyms - ntokens] = ngotos;
+    temp_map[nsyms - ntokens] = ngotos;
   }
 
-  from_state = XCALLOC (state_number, ngotos);
-  to_state = XCALLOC (state_number, ngotos);
+  CALLOC (from_state, ngotos);
+  CALLOC (to_state, ngotos);
 
   for (s = 0; s < nstates; ++s)
     {
@@ -121,13 +122,13 @@ set_goto_map (void)
       int i;
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
 	{
-	  int k = temp_map[TRANSITION_SYMBOL (sp, i)]++;
+	  int k = temp_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
 	  from_state[k] = s;
 	  to_state[k] = sp->states[i]->number;
 	}
     }
 
-  XFREE (temp_map + ntokens);
+  XFREE (temp_map);
 }
 
 
@@ -144,8 +145,8 @@ map_goto (state_number s0, symbol_number sym)
   int middle;
   state_number s;
 
-  low = goto_map[sym];
-  high = goto_map[sym + 1] - 1;
+  low = goto_map[sym - ntokens];
+  high = goto_map[sym - ntokens + 1] - 1;
 
   for (;;)
     {
@@ -166,8 +167,8 @@ map_goto (state_number s0, symbol_number sym)
 static void
 initialize_F (void)
 {
-  goto_number **reads = XCALLOC (goto_number *, ngotos);
-  goto_number *edge = XCALLOC (goto_number, ngotos + 1);
+  goto_number **reads = CALLOC (reads, ngotos);
+  goto_number *edge = CALLOC (edge, ngotos + 1);
   int nedges = 0;
 
   int i;
@@ -186,13 +187,13 @@ initialize_F (void)
       for (; j < sp->num; j++)
 	{
 	  symbol_number sym = TRANSITION_SYMBOL (sp, j);
-	  if (nullable[sym])
+	  if (nullable[sym - ntokens])
 	    edge[nedges++] = map_goto (stateno, sym);
 	}
 
       if (nedges)
 	{
-	  reads[i] = XCALLOC (goto_number, nedges + 1);
+	  CALLOC (reads[i], nedges + 1);
 	  memcpy (reads[i], edge, nedges * sizeof (edge[0]));
 	  reads[i][nedges] = -1;
 	  nedges = 0;
@@ -213,7 +214,7 @@ static void
 add_lookback_edge (state *s, rule *r, int gotono)
 {
   int ri = state_reduction_find (s, r);
-  goto_list *sp = XCALLOC (goto_list, 1);
+  goto_list *sp = MALLOC (sp, 1);
   sp->next = lookback[(s->reductions->lookaheads - LA) + ri];
   sp->value = gotono;
   lookback[(s->reductions->lookaheads - LA) + ri] = sp;
@@ -224,11 +225,11 @@ add_lookback_edge (state *s, rule *r, int gotono)
 static void
 build_relations (void)
 {
-  goto_number *edge = XCALLOC (goto_number, ngotos + 1);
-  state_number *states1 = XCALLOC (state_number, ritem_longest_rhs () + 1);
+  goto_number *edge = CALLOC (edge, ngotos + 1);
+  state_number *states1 = CALLOC (states1, ritem_longest_rhs () + 1);
   int i;
 
-  includes = XCALLOC (goto_number *, ngotos);
+  CALLOC (includes, ngotos);
 
   for (i = 0; i < ngotos; i++)
     {
@@ -236,7 +237,7 @@ build_relations (void)
       symbol_number symbol1 = states[to_state[i]]->accessing_symbol;
       rule **rulep;
 
-      for (rulep = derives[symbol1]; *rulep; rulep++)
+      for (rulep = derives[symbol1 - ntokens]; *rulep; rulep++)
 	{
 	  int done;
 	  int length = 1;
@@ -266,7 +267,7 @@ build_relations (void)
 		  /* Downcasting from item_number to symbol_number.  */
 		  edge[nedges++] = map_goto (states1[--length],
 					     item_number_as_symbol_number (*rp));
-		  if (nullable[*rp])
+		  if (nullable[*rp - ntokens])
 		    done = 0;
 		}
 	    }
@@ -275,7 +276,7 @@ build_relations (void)
       if (nedges)
 	{
 	  int j;
-	  includes[i] = XCALLOC (goto_number, nedges + 1);
+	  CALLOC (includes[i], nedges + 1);
 	  for (j = 0; j < nedges; j++)
 	    includes[i][j] = edge[j];
 	  includes[i][nedges] = -1;
@@ -377,7 +378,7 @@ initialize_LA (void)
     nLA = 1;
 
   pLA = LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
-  lookback = XCALLOC (goto_list *, nLA);
+  CALLOC (lookback, nLA);
 
   /* Initialize the members LOOKAHEADS for each state which reductions
      require lookaheads.  */
