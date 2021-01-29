@@ -1,5 +1,6 @@
 /* Compute look-ahead criteria for bison,
-   Copyright 1984, 1986, 1989, 2000, 2001  Free Software Foundation, Inc.
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -40,7 +41,7 @@
 /* All the decorated states, indexed by the state number.  */
 state_t **states = NULL;
 
-short *LAruleno = NULL;
+rule_t **LArule = NULL;
 bitsetv LA = NULL;
 size_t nLA;
 
@@ -134,21 +135,21 @@ initialize_LA (void)
 {
   size_t i;
   int j;
-  short *np;
+  rule_t **np;
 
   /* Avoid having to special case 0.  */
   if (!nLA)
     nLA = 1;
 
   LA = bitsetv_create (nLA, ntokens, BITSET_FIXED);
-  LAruleno = XCALLOC (short, nLA);
+  LArule = XCALLOC (rule_t *, nLA);
   lookback = XCALLOC (shorts *, nLA);
 
-  np = LAruleno;
+  np = LArule;
   for (i = 0; i < nstates; i++)
     if (!states[i]->consistent)
       for (j = 0; j < states[i]->reductions->nreds; j++)
-	*np++ = states[i]->reductions->rules[j];
+	*np++ = &rules[states[i]->reductions->rules[j]];
 }
 
 
@@ -296,10 +297,10 @@ add_lookback_edge (state_t *state, int ruleno, int gotono)
   shorts *sp;
 
   for (i = 0; i < state->nlookaheads; ++i)
-    if (LAruleno[state->lookaheadsp + i] == ruleno)
+    if (LArule[state->lookaheadsp + i]->number == ruleno)
       break;
 
-  assert (LAruleno[state->lookaheadsp + i] == ruleno);
+  assert (LArule[state->lookaheadsp + i]->number == ruleno);
 
   sp = XCALLOC (shorts, 1);
   sp->next = lookback[state->lookaheadsp + i];
@@ -561,7 +562,7 @@ lookaheads_print (FILE *out)
 	  if (bitset_test (LA[states[i]->lookaheadsp + j], j))
 	    fprintf (out, "   on %d (%s) -> rule %d\n",
 		     k, symbols[k]->tag,
-		     -LAruleno[states[i]->lookaheadsp + j] - 1);
+		     LArule[states[i]->lookaheadsp + j]->number - 1);
     }
   fprintf (out, "Lookaheads: END\n");
 }
