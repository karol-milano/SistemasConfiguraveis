@@ -32,13 +32,17 @@
 #include "nullable.h"
 #include "derives.h"
 
+/* All the decorated states, indexed by the state number.  Warning:
+   there is a state_TABLE in LR0.c, but it is different and static.
+   */
+state_t *state_table = NULL;
+
 int tokensetsize;
 short *lookaheads;
 short *LAruleno;
 unsigned *LA;
-short *accessing_symbol;
+
 char *consistent;
-core **state_table;
 shifts **shift_table;
 reductions **reduction_table;
 short *goto_map;
@@ -146,22 +150,13 @@ set_state_table (void)
 {
   core *sp;
 
-  state_table = XCALLOC (core *, nstates);
-
-  for (sp = first_state; sp; sp = sp->next)
-    state_table[sp->number] = sp;
-}
-
-
-static void
-set_accessing_symbol (void)
-{
-  core *sp;
-
-  accessing_symbol = XCALLOC (short, nstates);
+  state_table = XCALLOC (state_t, nstates);
 
   for (sp = first_state; sp; sp = sp->next)
-    accessing_symbol[sp->number] = sp->accessing_symbol;
+    {
+      state_table[sp->number].state = sp;
+      state_table[sp->number].accessing_symbol = sp->accessing_symbol;
+    }
 }
 
 
@@ -238,21 +233,21 @@ initialize_LA (void)
 
       rp = reduction_table[i];
       sp = shift_table[i];
-      if (rp && (rp->nreds > 1
-		 || (sp && !ISVAR (accessing_symbol[sp->shifts[0]]))))
+      if (rp
+	  && (rp->nreds > 1
+	      || (sp && !ISVAR (state_table[sp->shifts[0]].accessing_symbol))))
 	count += rp->nreds;
       else
 	consistent[i] = 1;
 
       if (sp)
 	for (k = 0; k < sp->nshifts; k++)
-	  {
-	    if (accessing_symbol[sp->shifts[k]] == error_token_number)
-	      {
-		consistent[i] = 0;
-		break;
-	      }
-	  }
+	  if (state_table[sp->shifts[k]].accessing_symbol
+	      == error_token_number)
+	    {
+	      consistent[i] = 0;
+	      break;
+	    }
     }
 
   lookaheads[nstates] = count;
@@ -302,7 +297,7 @@ set_goto_map (void)
     {
       for (i = sp->nshifts - 1; i >= 0; i--)
 	{
-	  symbol = accessing_symbol[sp->shifts[i]];
+	  symbol = state_table[sp->shifts[i]].accessing_symbol;
 
 	  if (ISTOKEN (symbol))
 	    break;
@@ -337,7 +332,7 @@ set_goto_map (void)
       for (i = sp->nshifts - 1; i >= 0; i--)
 	{
 	  state2 = sp->shifts[i];
-	  symbol = accessing_symbol[state2];
+	  symbol = state_table[state2].accessing_symbol;
 
 	  if (ISTOKEN (symbol))
 	    break;
@@ -421,7 +416,7 @@ initialize_F (void)
 
 	  for (j = 0; j < k; j++)
 	    {
-	      symbol = accessing_symbol[sp->shifts[j]];
+	      symbol = state_table[sp->shifts[j]].accessing_symbol;
 	      if (ISVAR (symbol))
 		break;
 	      SETBIT (rowp, symbol);
@@ -429,7 +424,7 @@ initialize_F (void)
 
 	  for (; j < k; j++)
 	    {
-	      symbol = accessing_symbol[sp->shifts[j]];
+	      symbol = state_table[sp->shifts[j]].accessing_symbol;
 	      if (nullable[symbol])
 		edge[nedges++] = map_goto (stateno, symbol);
 	    }
@@ -574,7 +569,7 @@ build_relations (void)
     {
       nedges = 0;
       state1 = from_state[i];
-      symbol1 = accessing_symbol[to_state[i]];
+      symbol1 = state_table[to_state[i]].accessing_symbol;
 
       for (rulep = derives[symbol1]; *rulep > 0; rulep++)
 	{
@@ -591,7 +586,7 @@ build_relations (void)
 	      for (j = 0; j < k; j++)
 		{
 		  stateno = sp->shifts[j];
-		  if (accessing_symbol[stateno] == symbol2)
+		  if (state_table[stateno].accessing_symbol == symbol2)
 		    break;
 		}
 
@@ -709,7 +704,6 @@ lalr (void)
   tokensetsize = WORDSIZE (ntokens);
 
   set_state_table ();
-  set_accessing_symbol ();
   set_shift_table ();
   set_reduction_table ();
   set_maxrhs ();
