@@ -217,7 +217,7 @@ set_goto_map (void)
 `----------------------------------------------------------*/
 
 static int
-map_goto (int state, token_number_t symbol)
+map_goto (int state, symbol_number_t symbol)
 {
   int high;
   int low;
@@ -267,7 +267,7 @@ initialize_F (void)
 
       for (; j < sp->nshifts; j++)
 	{
-	  token_number_t symbol = SHIFT_SYMBOL (sp, j);
+	  symbol_number_t symbol = SHIFT_SYMBOL (sp, j);
 	  if (nullable[symbol])
 	    edge[nedges++] = map_goto (stateno, symbol);
 	}
@@ -408,7 +408,7 @@ build_relations (void)
   for (i = 0; i < ngotos; i++)
     {
       int nedges = 0;
-      token_number_t symbol1 = states[to_state[i]]->accessing_symbol;
+      symbol_number_t symbol1 = states[to_state[i]]->accessing_symbol;
       short *rulep;
 
       for (rulep = derives[symbol1]; *rulep > 0; rulep++)
@@ -427,7 +427,7 @@ build_relations (void)
 		{
 		  state = states[sp->shifts[j]];
 		  if (state->accessing_symbol
-		      == item_number_as_token_number (*rp))
+		      == item_number_as_symbol_number (*rp))
 		    break;
 		}
 
@@ -446,9 +446,9 @@ build_relations (void)
 	      /* JF added rp>=ritem &&   I hope to god its right! */
 	      if (rp >= ritem && ISVAR (*rp))
 		{
-		  /* Downcasting from item_number_t to token_number_t. */
+		  /* Downcasting from item_number_t to symbol_number_t. */
 		  edge[nedges++] = map_goto (states1[--length],
-					     item_number_as_token_number (*rp));
+					     item_number_as_symbol_number (*rp));
 		  if (nullable[*rp])
 		    done = 0;
 		}
