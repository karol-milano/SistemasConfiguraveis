@@ -38,7 +38,6 @@
 state_t *state_table = NULL;
 
 int tokensetsize;
-short *lookaheads;
 short *LAruleno;
 unsigned *LA;
 
@@ -145,7 +144,10 @@ digraph (short **relation)
 static void
 set_state_table (void)
 {
-  state_table = XCALLOC (state_t, nstates);
+  /* NSTATES + 1 because lookahead for the pseudo state number NSTATES
+     might be used (see conflicts.c).  It is too opaque for me to
+     provide a probably less hacky implementation. --akim */
+  state_table = XCALLOC (state_t, nstates + 1);
 
   {
     core *sp;
@@ -202,19 +204,16 @@ initialize_LA (void)
 {
   int i;
   int j;
-  int count;
+  int count = 0;
   reductions *rp;
   shifts *sp;
   short *np;
 
-  lookaheads = XCALLOC (short, nstates + 1);
-
-  count = 0;
   for (i = 0; i < nstates; i++)
     {
       int k;
 
-      lookaheads[i] = count;
+      state_table[i].lookaheads = count;
 
       rp = state_table[i].reduction_table;
       sp = state_table[i].shift_table;
@@ -235,7 +234,7 @@ initialize_LA (void)
 	    }
     }
 
-  lookaheads[nstates] = count;
+  state_table[nstates].lookaheads = count;
 
   if (count == 0)
     {
@@ -450,8 +449,8 @@ add_lookback_edge (int stateno, int ruleno, int gotono)
   int found;
   shorts *sp;
 
-  i = lookaheads[stateno];
-  k = lookaheads[stateno + 1];
+  i = state_table[stateno].lookaheads;
+  k = state_table[stateno + 1].lookaheads;
   found = 0;
   while (!found && i < k)
     {
@@ -653,8 +652,7 @@ compute_lookaheads (void)
   shorts *sptmp;		/* JF */
 
   rowp = LA;
-  n = lookaheads[nstates];
-  for (i = 0; i < n; i++)
+  for (i = 0; i < state_table[nstates].lookaheads; i++)
     {
       fp3 = rowp + tokensetsize;
       for (sp = lookback[i]; sp; sp = sp->next)
@@ -668,7 +666,7 @@ compute_lookaheads (void)
       rowp = fp3;
     }
 
-  for (i = 0; i < n; i++)
+  for (i = 0; i < state_table[nstates].lookaheads; i++)
     {
       /* JF removed ref to freed storage */
       for (sp = lookback[i]; sp; sp = sptmp)
