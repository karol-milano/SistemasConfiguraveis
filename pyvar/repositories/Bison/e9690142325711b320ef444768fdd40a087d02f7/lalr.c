@@ -85,14 +85,14 @@ set_goto_map (void)
       transitions *sp = states[s]->transitions;
       int i;
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
-	{
-	  ngotos++;
+        {
+          ngotos++;
 
-	  /* Abort if (ngotos + 1) would overflow.  */
-	  aver (ngotos != GOTO_NUMBER_MAXIMUM);
+          /* Abort if (ngotos + 1) would overflow.  */
+          aver (ngotos != GOTO_NUMBER_MAXIMUM);
 
-	  goto_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
-	}
+          goto_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
+        }
     }
 
   {
@@ -100,8 +100,8 @@ set_goto_map (void)
     int i;
     for (i = ntokens; i < nsyms; i++)
       {
-	temp_map[i - ntokens] = k;
-	k += goto_map[i - ntokens];
+        temp_map[i - ntokens] = k;
+        k += goto_map[i - ntokens];
       }
 
     for (i = ntokens; i < nsyms; i++)
@@ -119,11 +119,11 @@ set_goto_map (void)
       transitions *sp = states[s]->transitions;
       int i;
       for (i = sp->num - 1; i >= 0 && TRANSITION_IS_GOTO (sp, i); --i)
-	{
-	  goto_number k = temp_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
-	  from_state[k] = s;
-	  to_state[k] = sp->states[i]->number;
-	}
+        {
+          goto_number k = temp_map[TRANSITION_SYMBOL (sp, i) - ntokens]++;
+          from_state[k] = s;
+          to_state[k] = sp->states[i]->number;
+        }
     }
 
   free (temp_map);
@@ -147,11 +147,11 @@ map_goto (state_number s0, symbol_number sym)
       middle = (low + high) / 2;
       s = from_state[middle];
       if (s == s0)
-	return middle;
+        return middle;
       else if (s < s0)
-	low = middle + 1;
+        low = middle + 1;
       else
-	high = middle - 1;
+        high = middle - 1;
     }
 }
 
@@ -174,24 +174,24 @@ initialize_F (void)
 
       int j;
       FOR_EACH_SHIFT (sp, j)
-	bitset_set (goto_follows[i], TRANSITION_SYMBOL (sp, j));
+        bitset_set (goto_follows[i], TRANSITION_SYMBOL (sp, j));
 
       for (; j < sp->num; j++)
-	{
-	  symbol_number sym = TRANSITION_SYMBOL (sp, j);
-	  if (nullable[sym - ntokens])
-	    edge[nedges++] = map_goto (stateno, sym);
-	}
+        {
+          symbol_number sym = TRANSITION_SYMBOL (sp, j);
+          if (nullable[sym - ntokens])
+            edge[nedges++] = map_goto (stateno, sym);
+        }
 
       if (nedges == 0)
-	reads[i] = NULL;
+        reads[i] = NULL;
       else
-	{
-	  reads[i] = xnmalloc (nedges + 1, sizeof reads[i][0]);
-	  memcpy (reads[i], edge, nedges * sizeof edge[0]);
-	  reads[i][nedges] = END_NODE;
-	  nedges = 0;
-	}
+        {
+          reads[i] = xnmalloc (nedges + 1, sizeof reads[i][0]);
+          memcpy (reads[i], edge, nedges * sizeof edge[0]);
+          reads[i][nedges] = END_NODE;
+          nedges = 0;
+        }
     }
 
   relation_digraph (reads, ngotos, &goto_follows);
@@ -232,53 +232,53 @@ build_relations (void)
       rule **rulep;
 
       for (rulep = derives[symbol1 - ntokens]; *rulep; rulep++)
-	{
-	  bool done;
-	  int length = 1;
-	  item_number const *rp;
-	  state *s = states[from_state[i]];
-	  states1[0] = s->number;
-
-	  for (rp = (*rulep)->rhs; ! item_number_is_rule_number (*rp); rp++)
-	    {
-	      s = transitions_to (s->transitions,
-				  item_number_as_symbol_number (*rp));
-	      states1[length++] = s->number;
-	    }
-
-	  if (!s->consistent)
-	    add_lookback_edge (s, *rulep, i);
-
-	  length--;
-	  done = false;
-	  while (!done)
-	    {
-	      done = true;
-	      /* Each rhs ends in a rule number, and there is a
-		 sentinel (ritem[-1]=0) before the first rhs, so it is safe to
-		 decrement RP here.  */
-	      rp--;
-	      if (ISVAR (*rp))
-		{
-		  /* Downcasting from item_number to symbol_number.  */
-		  edge[nedges++] = map_goto (states1[--length],
-					     item_number_as_symbol_number (*rp));
-		  if (nullable[*rp - ntokens])
-		    done = false;
-		}
-	    }
-	}
+        {
+          bool done;
+          int length = 1;
+          item_number const *rp;
+          state *s = states[from_state[i]];
+          states1[0] = s->number;
+
+          for (rp = (*rulep)->rhs; ! item_number_is_rule_number (*rp); rp++)
+            {
+              s = transitions_to (s->transitions,
+                                  item_number_as_symbol_number (*rp));
+              states1[length++] = s->number;
+            }
+
+          if (!s->consistent)
+            add_lookback_edge (s, *rulep, i);
+
+          length--;
+          done = false;
+          while (!done)
+            {
+              done = true;
+              /* Each rhs ends in a rule number, and there is a
+                 sentinel (ritem[-1]=0) before the first rhs, so it is safe to
+                 decrement RP here.  */
+              rp--;
+              if (ISVAR (*rp))
+                {
+                  /* Downcasting from item_number to symbol_number.  */
+                  edge[nedges++] = map_goto (states1[--length],
+                                             item_number_as_symbol_number (*rp));
+                  if (nullable[*rp - ntokens])
+                    done = false;
+                }
+            }
+        }
 
       if (nedges == 0)
-	includes[i] = NULL;
+        includes[i] = NULL;
       else
-	{
-	  int j;
-	  includes[i] = xnmalloc (nedges + 1, sizeof includes[i][0]);
-	  for (j = 0; j < nedges; j++)
-	    includes[i][j] = edge[j];
-	  includes[i][nedges] = END_NODE;
-	}
+        {
+          int j;
+          includes[i] = xnmalloc (nedges + 1, sizeof includes[i][0]);
+          for (j = 0; j < nedges; j++)
+            includes[i][j] = edge[j];
+          includes[i][nedges] = END_NODE;
+        }
     }
 
   free (edge);
@@ -398,10 +398,10 @@ initialize_LA (void)
         state_lookahead_tokens_count (states[i],
                                       default_reduction_only_for_accept);
       if (count)
-	{
-	  states[i]->reductions->lookahead_tokens = pLA;
-	  pLA += count;
-	}
+        {
+          states[i]->reductions->lookahead_tokens = pLA;
+          pLA += count;
+        }
     }
 }
 
@@ -423,21 +423,21 @@ lookahead_tokens_print (FILE *out)
       int n_lookahead_tokens = 0;
 
       if (reds->lookahead_tokens)
-	for (k = 0; k < reds->num; ++k)
-	  if (reds->lookahead_tokens[k])
-	    ++n_lookahead_tokens;
+        for (k = 0; k < reds->num; ++k)
+          if (reds->lookahead_tokens[k])
+            ++n_lookahead_tokens;
 
       fprintf (out, "State %d: %d lookahead tokens\n",
-	       i, n_lookahead_tokens);
+               i, n_lookahead_tokens);
 
       if (reds->lookahead_tokens)
-	for (j = 0; j < reds->num; ++j)
-	  BITSET_FOR_EACH (iter, reds->lookahead_tokens[j], k, 0)
-	  {
-	    fprintf (out, "   on %d (%s) -> rule %d\n",
-		     k, symbols[k]->tag,
-		     reds->rules[j]->number);
-	  };
+        for (j = 0; j < reds->num; ++j)
+          BITSET_FOR_EACH (iter, reds->lookahead_tokens[j], k, 0)
+          {
+            fprintf (out, "   on %d (%s) -> rule %d\n",
+                     k, symbols[k]->tag,
+                     reds->rules[j]->number);
+          };
     }
   fprintf (out, "Lookahead tokens: END\n");
 }
