@@ -26,6 +26,7 @@
 #include "closure.h"
 #include "derives.h"
 #include "warshall.h"
+#include "bitset.h"
 
 /* NITEMSET is the size of the array ITEMSET.  */
 short *itemset;
@@ -34,11 +35,11 @@ int nitemset;
 static unsigned *ruleset;
 
 /* internal data.  See comments before set_fderives and set_firsts.  */
-static unsigned *fderives;
-static unsigned *firsts;
+static bitset *fderives;
+static unsigned int *firsts;
 
 /* Retrieve the FDERIVES/FIRSTS sets of the nonterminals numbered Var.  */
-#define FDERIVES(Var)   (fderives + ((Var) - ntokens) * rulesetsize)
+#define FDERIVES(Var)   fderives[(Var) - ntokens]
 #define   FIRSTS(Var)   (firsts   + ((Var) - ntokens) * varsetsize)
 
 /* number of words required to hold a bit for each rule */
@@ -99,7 +100,7 @@ print_fderives (void)
     {
       fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
       for (j = 0; j <= nrules; j++)
-	if (BITISSET (FDERIVES (i), j))
+	if (bitset_test (FDERIVES (i), j))
 	  {
 	    short *rhsp;
 	    fprintf (stderr, "\t\t%d:", j - 1);
@@ -159,7 +160,13 @@ set_fderives (void)
 {
   int i, j, k;
 
-  fderives = XCALLOC (unsigned, nvars * rulesetsize);
+  fderives = XCALLOC (bitset, nvars);
+  bitset_stats_init ();
+  for (i = 0 ; i < nvars; ++i)
+    {
+      fderives[i] = bitset_create (nrules + 1, BITSET_FIXED);
+      bitset_zero (fderives[i]);
+    }
 
   set_firsts ();
 
@@ -167,7 +174,7 @@ set_fderives (void)
     for (j = ntokens; j < nsyms; ++j)
       if (BITISSET (FIRSTS (i), j - ntokens))
 	for (k = 0; derives[j][k] > 0; ++k)
-	  SETBIT (FDERIVES (i), derives[j][k]);
+	  bitset_set (FDERIVES (i), derives[j][k]);
 
   if (trace_flag)
     print_fderives ();
@@ -206,8 +213,11 @@ closure (short *core, int n)
 
   if (n == 0)
     {
-      for (r = 0; r < rulesetsize; ++r)
-	ruleset[r] = FDERIVES (start_symbol)[r];
+      for (ruleno = 0; ruleno < nrules + 1; ++ruleno)
+	if (bitset_test (FDERIVES (start_symbol), ruleno))
+	  SETBIT (ruleset, ruleno);
+	else
+	  RESETBIT (ruleset, ruleno);
     }
   else
     {
@@ -216,8 +226,9 @@ closure (short *core, int n)
 
       for (c = 0; c < n; ++c)
 	if (ISVAR (ritem[core[c]]))
-	  for (r = 0; r < rulesetsize; ++r)
-	    ruleset[r] |= FDERIVES (ritem[core[c]])[r];
+	  for (ruleno = 0; ruleno < nrules + 1; ++ruleno)
+	    if (bitset_test (FDERIVES (ritem[core[c]]), ruleno))
+	      SETBIT (ruleset, ruleno);
     }
 
   nitemset = 0;
@@ -251,7 +262,11 @@ closure (short *core, int n)
 void
 free_closure (void)
 {
+  int i;
   XFREE (itemset);
   XFREE (ruleset);
-  XFREE (fderives);
+
+  for (i = 0 ; i < nvars; ++i)
+    bitset_free (fderives[i]);
+  free (fderives);
 }
