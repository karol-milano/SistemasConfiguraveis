@@ -356,24 +356,14 @@ map_goto (int state, int symbol)
 static void
 initialize_F (void)
 {
-  int i;
-  int j;
-  short *edge;
-  unsigned *rowp;
-  short *rp;
-  short **reads;
-  int nedges;
-  int symbol;
-  int nwords;
+  short **reads = XCALLOC (short *, ngotos);
+  short *edge = XCALLOC (short, ngotos + 1);
+  int nedges = 0;
 
-  nwords = ngotos * tokensetsize;
-  F = XCALLOC (unsigned, nwords);
+  int i;
 
-  reads = XCALLOC (short *, ngotos);
-  edge = XCALLOC (short, ngotos + 1);
-  nedges = 0;
+  F = XCALLOC (unsigned, ngotos * tokensetsize);
 
-  rowp = F;
   for (i = 0; i < ngotos; i++)
     {
       int stateno = to_state[i];
@@ -381,34 +371,30 @@ initialize_F (void)
 
       if (sp)
 	{
+	  int j;
 	  for (j = 0; j < sp->nshifts; j++)
 	    {
-	      symbol = state_table[sp->shifts[j]].accessing_symbol;
+	      int symbol = state_table[sp->shifts[j]].accessing_symbol;
 	      if (ISVAR (symbol))
 		break;
-	      SETBIT (rowp, symbol);
+	      SETBIT (F + i * tokensetsize, symbol);
 	    }
 
 	  for (; j < sp->nshifts; j++)
 	    {
-	      symbol = state_table[sp->shifts[j]].accessing_symbol;
+	      int symbol = state_table[sp->shifts[j]].accessing_symbol;
 	      if (nullable[symbol])
 		edge[nedges++] = map_goto (stateno, symbol);
 	    }
 
 	  if (nedges)
 	    {
-	      reads[i] = rp = XCALLOC (short, nedges + 1);
-
-	      for (j = 0; j < nedges; j++)
-		rp[j] = edge[j];
-
-	      rp[nedges] = -1;
+	      reads[i] = XCALLOC (short, nedges + 1);
+	      shortcpy (reads[i], edge, nedges);
+	      reads[i][nedges] = -1;
 	      nedges = 0;
 	    }
 	}
-
-      rowp += tokensetsize;
     }
 
   digraph (reads);
