@@ -435,6 +435,11 @@ add_lookback_edge (int stateno, int ruleno, int gotono)
 }
 
 
+/*-------------------------------------------------------------------.
+| Return the transpose of R_ARG, of size N.  Destroy R_ARG, as it is |
+| replaced with the result.                                          |
+`-------------------------------------------------------------------*/
+
 static short **
 transpose (short **R_arg, int n)
 {
@@ -479,6 +484,11 @@ transpose (short **R_arg, int n)
 
   XFREE (temp_R);
 
+  /* Free the input: it is replaced with the result. */
+  for (i = 0; i < n; i++)
+    XFREE (R_arg[i]);
+  XFREE (R_arg);
+
   return new_R;
 }
 
@@ -486,44 +496,35 @@ transpose (short **R_arg, int n)
 static void
 build_relations (void)
 {
+  short *edge = XCALLOC (short, ngotos + 1);
+  short *states = XCALLOC (short, maxrhs () + 1);
   int i;
-  int j;
-  short *rulep;
-  short *rp;
-  int nedges;
-  int done;
-  int state1;
-  int stateno;
-  int symbol1;
-  short *edge;
-  short *states;
-  short **new_includes;
 
   includes = XCALLOC (short *, ngotos);
-  edge = XCALLOC (short, ngotos + 1);
-  states = XCALLOC (short, maxrhs () + 1);
 
   for (i = 0; i < ngotos; i++)
     {
-      nedges = 0;
-      state1 = from_state[i];
-      symbol1 = state_table[to_state[i]].accessing_symbol;
+      int nedges = 0;
+      int state1 = from_state[i];
+      int symbol1 = state_table[to_state[i]].accessing_symbol;
+      short *rulep;
 
       for (rulep = derives[symbol1]; *rulep > 0; rulep++)
 	{
+	  int done;
 	  int length = 1;
+	  int stateno = state1;
+	  short *rp;
 	  states[0] = state1;
-	  stateno = state1;
 
 	  for (rp = ritem + rule_table[*rulep].rhs; *rp > 0; rp++)
 	    {
-	      int symbol2 = *rp;
 	      shifts *sp = state_table[stateno].shift_table;
-
+	      int j;
 	      for (j = 0; j < sp->nshifts; j++)
 		{
 		  stateno = sp->shifts[j];
-		  if (state_table[stateno].accessing_symbol == symbol2)
+		  if (state_table[stateno].accessing_symbol == *rp)
 		    break;
 		}
 
@@ -552,6 +553,7 @@ build_relations (void)
 
       if (nedges)
 	{
+	  int j;
 	  includes[i] = XCALLOC (short, nedges + 1);
 	  for (j = 0; j < nedges; j++)
 	    includes[i][j] = edge[j];
@@ -559,16 +561,10 @@ build_relations (void)
 	}
     }
 
-  new_includes = transpose (includes, ngotos);
-
-  for (i = 0; i < ngotos; i++)
-    XFREE (includes[i]);
-  XFREE (includes);
-
-  includes = new_includes;
-
   XFREE (edge);
   XFREE (states);
+
+  includes = transpose (includes, ngotos);
 }
 
 
@@ -596,10 +592,10 @@ compute_lookaheads (void)
   for (i = 0; i < state_table[nstates].lookaheads; i++)
     for (sp = lookback[i]; sp; sp = sp->next)
       {
-	unsigned *fp1 = LA (i);
-	unsigned *fp2 = F (sp->value);
-	while (fp1 < LA (i + 1))
-	  *fp1++ |= *fp2++;
+	int size = LA (i + 1) - LA (i);
+	int j;
+	for (j = 0; j < size; ++j)
+	  LA (i)[j] |= F (sp->value)[j];
       }
 
   /* Free LOOKBACK. */
