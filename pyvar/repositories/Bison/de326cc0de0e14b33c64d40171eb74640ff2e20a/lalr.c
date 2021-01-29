@@ -42,7 +42,6 @@ short *lookaheads;
 short *LAruleno;
 unsigned *LA;
 
-char *consistent;
 short *goto_map;
 short *from_state;
 short *to_state;
@@ -208,7 +207,6 @@ initialize_LA (void)
   shifts *sp;
   short *np;
 
-  consistent = XCALLOC (char, nstates);
   lookaheads = XCALLOC (short, nstates + 1);
 
   count = 0;
@@ -225,14 +223,14 @@ initialize_LA (void)
 	      || (sp && !ISVAR (state_table[sp->shifts[0]].accessing_symbol))))
 	count += rp->nreds;
       else
-	consistent[i] = 1;
+	state_table[i].consistent = 1;
 
       if (sp)
 	for (k = 0; k < sp->nshifts; k++)
 	  if (state_table[sp->shifts[k]].accessing_symbol
 	      == error_token_number)
 	    {
-	      consistent[i] = 0;
+	      state_table[i].consistent = 0;
 	      break;
 	    }
     }
@@ -255,7 +253,7 @@ initialize_LA (void)
   np = LAruleno;
   for (i = 0; i < nstates; i++)
     {
-      if (!consistent[i])
+      if (!state_table[i].consistent)
 	{
 	  if ((rp = state_table[i].reduction_table))
 	    for (j = 0; j < rp->nreds; j++)
@@ -580,7 +578,7 @@ build_relations (void)
 	      states[length++] = stateno;
 	    }
 
-	  if (!consistent[stateno])
+	  if (!state_table[stateno].consistent)
 	    add_lookback_edge (stateno, *rulep, i);
 
 	  length--;
