@@ -24,6 +24,7 @@
    tokens they accept.  */
 
 #include "system.h"
+#include "bitset.h"
 #include "reader.h"
 #include "types.h"
 #include "LR0.h"
@@ -39,14 +40,14 @@
 state_t **states = NULL;
 
 int tokensetsize;
-short *LAruleno;
-unsigned *LA;
+short *LAruleno = NULL;
+bitset *LA = NULL;
 size_t nLA;
 
 static int ngotos;
-short *goto_map;
-short *from_state;
-short *to_state;
+short *goto_map = NULL;
+short *from_state = NULL;
+short *to_state = NULL;
 
 /* And for the famous F variable, which name is so descriptive that a
    comment is hardly needed.  <grin>.  */
@@ -136,7 +137,7 @@ digraph (short **relation)
 static void
 initialize_LA (void)
 {
-  int i;
+  size_t i;
   int j;
   short *np;
 
@@ -144,7 +145,12 @@ initialize_LA (void)
   if (!nLA)
     nLA = 1;
 
-  LA = XCALLOC (unsigned, nLA * tokensetsize);
+  LA = XCALLOC (bitset, nLA);
+  for (i = 0; i < nLA; ++i)
+    {
+      LA[i] = bitset_create (ntokens, BITSET_FIXED);
+      bitset_zero (LA[i]);
+    }
   LAruleno = XCALLOC (short, nLA);
   lookback = XCALLOC (shorts *, nLA);
 
@@ -159,7 +165,8 @@ initialize_LA (void)
 static void
 set_goto_map (void)
 {
-  int state, i;
+  size_t state;
+  int i;
   short *temp_map;
 
   goto_map = XCALLOC (short, nvars + 1) - ntokens;
@@ -494,10 +501,10 @@ compute_lookaheads (void)
   for (i = 0; i < nLA; i++)
     for (sp = lookback[i]; sp; sp = sp->next)
       {
-	int size = LA (i + 1) - LA (i);
 	int j;
-	for (j = 0; j < size; ++j)
-	  LA (i)[j] |= F (sp->value)[j];
+	for (j = 0; j < ntokens; ++j)
+	  if (BITISSET (F (sp->value), j))
+	    bitset_set (LA[i], j);
       }
 
   /* Free LOOKBACK. */
@@ -516,7 +523,7 @@ compute_lookaheads (void)
 static void
 initialize_lookaheads (void)
 {
-  int i;
+  size_t i;
   nLA = 0;
   for (i = 0; i < nstates; i++)
     {
@@ -556,7 +563,8 @@ initialize_lookaheads (void)
 static void
 lookaheads_print (FILE *out)
 {
-  int i, j, k;
+  size_t i;
+  int j, k;
   fprintf (out, "Lookaheads: BEGIN\n");
   for (i = 0; i < nstates; ++i)
     {
@@ -565,7 +573,7 @@ lookaheads_print (FILE *out)
 
       for (j = 0; j < states[i]->nlookaheads; ++j)
 	for (k = 0; k < ntokens; ++k)
-	  if (BITISSET (LA (states[i]->lookaheadsp + j), j))
+	  if (bitset_test (LA[states[i]->lookaheadsp + j], j))
 	    fprintf (out, "   on %d (%s) -> rule %d\n",
 		     k, symbols[k]->tag,
 		     -LAruleno[states[i]->lookaheadsp + j] - 1);
