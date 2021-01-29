@@ -165,6 +165,15 @@ set_state_table (void)
       state_table[rp->number].reduction_table = rp;
   }
 
+  /* Pessimization, but simplification of the code: make sense all the
+     states have a shift_table, even if reduced to 0 shifts.  */
+  {
+    int i;
+    for (i = 0; i < nstates; i++)
+      if (!state_table[i].shift_table)
+	state_table[i].shift_table = shifts_new (0);
+  }
+
   /* Initializing the lookaheads members.  Please note that it must be
      performed after having set some of the other members which are
      used below.  Change with extreme caution.  */
@@ -180,18 +189,17 @@ set_state_table (void)
 	state_table[i].lookaheads = count;
 
 	if (rp
-	    && (rp->nreds > 1 || (sp && SHIFT_IS_SHIFT (sp, 0))))
+	    && (rp->nreds > 1 || (sp->nshifts && SHIFT_IS_SHIFT (sp, 0))))
 	  count += rp->nreds;
 	else
 	  state_table[i].consistent = 1;
 
-	if (sp)
-	  for (k = 0; k < sp->nshifts; k++)
-	    if (SHIFT_IS_ERROR (sp, k))
-	      {
-		state_table[i].consistent = 0;
-		break;
-	      }
+	for (k = 0; k < sp->nshifts; k++)
+	  if (SHIFT_IS_ERROR (sp, k))
+	    {
+	      state_table[i].consistent = 0;
+	      break;
+	    }
       }
      state_table[nstates].lookaheads = count;
   }
@@ -239,18 +247,16 @@ set_goto_map (void)
 
   ngotos = 0;
   for (sp = first_shift; sp; sp = sp->next)
-    {
-      for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
-	{
-	  symbol = state_table[sp->shifts[i]].accessing_symbol;
+    for (i = sp->nshifts - 1; i >= 0 && SHIFT_IS_GOTO (sp, i); --i)
+      {
+	symbol = state_table[sp->shifts[i]].accessing_symbol;
 
-	  if (ngotos == MAXSHORT)
-	    fatal (_("too many gotos (max %d)"), MAXSHORT);
+	if (ngotos == MAXSHORT)
+	  fatal (_("too many gotos (max %d)"), MAXSHORT);
 
-	  ngotos++;
-	  goto_map[symbol]++;
-	}
-    }
+	ngotos++;
+	goto_map[symbol]++;
+      }
 
   k = 0;
   for (i = ntokens; i < nsyms; i++)
@@ -336,29 +342,26 @@ initialize_F (void)
       int stateno = to_state[i];
       shifts *sp = state_table[stateno].shift_table;
 
-      if (sp)
+      int j;
+      for (j = 0; j < sp->nshifts && SHIFT_IS_SHIFT (sp, j); j++)
 	{
-	  int j;
-	  for (j = 0; j < sp->nshifts && SHIFT_IS_SHIFT (sp, j); j++)
-	    {
-	      int symbol = state_table[sp->shifts[j]].accessing_symbol;
-	      SETBIT (F + i * tokensetsize, symbol);
-	    }
+	  int symbol = state_table[sp->shifts[j]].accessing_symbol;
+	  SETBIT (F + i * tokensetsize, symbol);
+	}
 
-	  for (; j < sp->nshifts; j++)
-	    {
-	      int symbol = state_table[sp->shifts[j]].accessing_symbol;
-	      if (nullable[symbol])
-		edge[nedges++] = map_goto (stateno, symbol);
-	    }
+      for (; j < sp->nshifts; j++)
+	{
+	  int symbol = state_table[sp->shifts[j]].accessing_symbol;
+	  if (nullable[symbol])
+	    edge[nedges++] = map_goto (stateno, symbol);
+	}
 
-	  if (nedges)
-	    {
-	      reads[i] = XCALLOC (short, nedges + 1);
-	      shortcpy (reads[i], edge, nedges);
-	      reads[i][nedges] = -1;
-	      nedges = 0;
-	    }
+      if (nedges)
+	{
+	  reads[i] = XCALLOC (short, nedges + 1);
+	  shortcpy (reads[i], edge, nedges);
+	  reads[i][nedges] = -1;
+	  nedges = 0;
 	}
     }
 
