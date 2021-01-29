@@ -217,7 +217,7 @@ set_goto_map (void)
 `----------------------------------------------------------*/
 
 static int
-map_goto (int state, int symbol)
+map_goto (int state, token_number_t symbol)
 {
   int high;
   int low;
@@ -267,7 +267,7 @@ initialize_F (void)
 
       for (; j < sp->nshifts; j++)
 	{
-	  int symbol = SHIFT_SYMBOL (sp, j);
+	  token_number_t symbol = SHIFT_SYMBOL (sp, j);
 	  if (nullable[symbol])
 	    edge[nedges++] = map_goto (stateno, symbol);
 	}
@@ -408,7 +408,7 @@ build_relations (void)
   for (i = 0; i < ngotos; i++)
     {
       int nedges = 0;
-      int symbol1 = states[to_state[i]]->accessing_symbol;
+      token_number_t symbol1 = states[to_state[i]]->accessing_symbol;
       short *rulep;
 
       for (rulep = derives[symbol1]; *rulep > 0; rulep++)
@@ -426,7 +426,8 @@ build_relations (void)
 	      for (j = 0; j < sp->nshifts; j++)
 		{
 		  state = states[sp->shifts[j]];
-		  if (state->accessing_symbol == *rp)
+		  if (state->accessing_symbol
+		      == item_number_as_token_number (*rp))
 		    break;
 		}
 
@@ -445,7 +446,9 @@ build_relations (void)
 	      /* JF added rp>=ritem &&   I hope to god its right! */
 	      if (rp >= ritem && ISVAR (*rp))
 		{
-		  edge[nedges++] = map_goto (states1[--length], *rp);
+		  /* Downcasting from item_number_t to token_number_t. */
+		  edge[nedges++] = map_goto (states1[--length],
+					     item_number_as_token_number (*rp));
 		  if (nullable[*rp])
 		    done = 0;
 		}
