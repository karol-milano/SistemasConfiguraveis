@@ -169,6 +169,39 @@ set_state_table (void)
     for (rp = first_reduction; rp; rp = rp->next)
       state_table[rp->number].reduction_table = rp;
   }
+
+  /* Initializing the lookaheads members.  Please note that it must be
+     performed after having set some of the other members which are
+     used below.  Change with extreme caution.  */
+  {
+    int i;
+    int count = 0;
+    for (i = 0; i < nstates; i++)
+      {
+	int k;
+	reductions *rp = state_table[i].reduction_table;
+	shifts *sp = state_table[i].shift_table;
+
+	state_table[i].lookaheads = count;
+
+	if (rp
+	    && (rp->nreds > 1
+		|| (sp && !ISVAR (state_table[sp->shifts[0]].accessing_symbol))))
+	  count += rp->nreds;
+	else
+	  state_table[i].consistent = 1;
+
+	if (sp)
+	  for (k = 0; k < sp->nshifts; k++)
+	    if (state_table[sp->shifts[k]].accessing_symbol
+		== error_token_number)
+	      {
+		state_table[i].consistent = 0;
+		break;
+	      }
+      }
+     state_table[nstates].lookaheads = count;
+  }
 }
 
 
@@ -204,61 +237,23 @@ initialize_LA (void)
 {
   int i;
   int j;
-  int count = 0;
-  reductions *rp;
-  shifts *sp;
   short *np;
+  reductions *rp;
 
-  for (i = 0; i < nstates; i++)
-    {
-      int k;
-
-      state_table[i].lookaheads = count;
-
-      rp = state_table[i].reduction_table;
-      sp = state_table[i].shift_table;
-      if (rp
-	  && (rp->nreds > 1
-	      || (sp && !ISVAR (state_table[sp->shifts[0]].accessing_symbol))))
-	count += rp->nreds;
-      else
-	state_table[i].consistent = 1;
-
-      if (sp)
-	for (k = 0; k < sp->nshifts; k++)
-	  if (state_table[sp->shifts[k]].accessing_symbol
-	      == error_token_number)
-	    {
-	      state_table[i].consistent = 0;
-	      break;
-	    }
-    }
-
-  state_table[nstates].lookaheads = count;
+  size_t nLA = state_table[nstates].lookaheads;
+  if (!nLA)
+    nLA = 1;
 
-  if (count == 0)
-    {
-      LA = XCALLOC (unsigned, 1 * tokensetsize);
-      LAruleno = XCALLOC (short, 1);
-      lookback = XCALLOC (shorts *, 1);
-    }
-  else
-    {
-      LA = XCALLOC (unsigned, count * tokensetsize);
-      LAruleno = XCALLOC (short, count);
-      lookback = XCALLOC (shorts *, count);
-    }
+  LA = XCALLOC (unsigned, nLA * tokensetsize);
+  LAruleno = XCALLOC (short, nLA);
+  lookback = XCALLOC (shorts *, nLA);
 
   np = LAruleno;
   for (i = 0; i < nstates; i++)
-    {
-      if (!state_table[i].consistent)
-	{
-	  if ((rp = state_table[i].reduction_table))
-	    for (j = 0; j < rp->nreds; j++)
-	      *np++ = rp->rules[j];
-	}
-    }
+    if (!state_table[i].consistent)
+      if ((rp = state_table[i].reduction_table))
+	for (j = 0; j < rp->nreds; j++)
+	  *np++ = rp->rules[j];
 }
 
 
