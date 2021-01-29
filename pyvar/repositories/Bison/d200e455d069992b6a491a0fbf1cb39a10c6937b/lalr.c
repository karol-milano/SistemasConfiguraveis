@@ -33,14 +33,13 @@
 #include "derives.h"
 #include "getargs.h"
 
-/* All the decorated states, indexed by the state number.  Warning:
-   there is a state_TABLE in LR0.c, but it is different and static.
-   */
+/* All the decorated states, indexed by the state number.  */
 state_t **state_table = NULL;
 
 int tokensetsize;
 short *LAruleno;
 unsigned *LA;
+size_t nLA;
 
 static int ngotos;
 short *goto_map;
@@ -140,7 +139,7 @@ initialize_LA (void)
   short *np;
   reductions *rp;
 
-  size_t nLA = state_table[nstates]->lookaheadsp;
+  /* Avoid having to special case 0.  */
   if (!nLA)
     nLA = 1;
 
@@ -504,10 +503,10 @@ compute_FOLLOWS (void)
 static void
 compute_lookaheads (void)
 {
-  int i;
+  size_t i;
   shorts *sp;
 
-  for (i = 0; i < state_table[nstates]->lookaheadsp; i++)
+  for (i = 0; i < nLA; i++)
     for (sp = lookback[i]; sp; sp = sp->next)
       {
 	int size = LA (i + 1) - LA (i);
@@ -517,7 +516,7 @@ compute_lookaheads (void)
       }
 
   /* Free LOOKBACK. */
-  for (i = 0; i < state_table[nstates]->lookaheadsp; i++)
+  for (i = 0; i < nLA; i++)
     LIST_FREE (shorts, lookback[i]);
 
   XFREE (lookback);
@@ -533,7 +532,7 @@ static void
 initialize_lookaheads (void)
 {
   int i;
-  int count = 0;
+  nLA = 0;
   for (i = 0; i < nstates; i++)
     {
       int k;
@@ -555,13 +554,9 @@ initialize_lookaheads (void)
 	  }
 
       state_table[i]->nlookaheads = nlookaheads;
-      state_table[i]->lookaheadsp = count;
-      count += nlookaheads;
+      state_table[i]->lookaheadsp = nLA;
+      nLA += nlookaheads;
     }
-
-  /* Seems to be needed by conflicts.c. */
-  state_table[nstates] = STATE_ALLOC (0);
-  state_table[nstates]->lookaheadsp = count;
 }
 
 void
