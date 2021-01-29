@@ -32,7 +32,7 @@
 short *itemset;
 int nitemset;
 
-static unsigned *ruleset;
+static bitset ruleset;
 
 /* internal data.  See comments before set_fderives and set_firsts.  */
 static bitset *fderives;
@@ -42,9 +42,6 @@ static unsigned int *firsts;
 #define FDERIVES(Var)   fderives[(Var) - ntokens]
 #define   FIRSTS(Var)   (firsts   + ((Var) - ntokens) * varsetsize)
 
-/* number of words required to hold a bit for each rule */
-static int rulesetsize;
-
 /* number of words required to hold a bit for each variable */
 static int varsetsize;
 
@@ -188,8 +185,8 @@ new_closure (int n)
 {
   itemset = XCALLOC (short, n);
 
-  rulesetsize = WORDSIZE (nrules + 1);
-  ruleset = XCALLOC (unsigned, rulesetsize);
+  ruleset = bitset_create (nrules + 1, BITSET_FIXED);
+  bitset_zero (ruleset);
 
   set_fderives ();
 }
@@ -213,28 +210,21 @@ closure (short *core, int n)
 
   if (n == 0)
     {
-      for (ruleno = 0; ruleno < nrules + 1; ++ruleno)
-	if (bitset_test (FDERIVES (start_symbol), ruleno))
-	  SETBIT (ruleset, ruleno);
-	else
-	  RESETBIT (ruleset, ruleno);
+      bitset_copy (ruleset, FDERIVES (start_symbol));
     }
   else
     {
-      for (r = 0; r < rulesetsize; ++r)
-	ruleset[r] = 0;
+      bitset_zero (ruleset);
 
       for (c = 0; c < n; ++c)
 	if (ISVAR (ritem[core[c]]))
-	  for (ruleno = 0; ruleno < nrules + 1; ++ruleno)
-	    if (bitset_test (FDERIVES (ritem[core[c]]), ruleno))
-	      SETBIT (ruleset, ruleno);
+	  bitset_or (ruleset, ruleset, FDERIVES (ritem[core[c]]));
     }
 
   nitemset = 0;
   c = 0;
   for (ruleno = 0; ruleno < nrules + 1; ++ruleno)
-    if (BITISSET (ruleset, ruleno))
+    if (bitset_test (ruleset, ruleno))
       {
 	int itemno = rules[ruleno].rhs;
 	while (c < n && core[c] < itemno)
@@ -264,7 +254,8 @@ free_closure (void)
 {
   int i;
   XFREE (itemset);
-  XFREE (ruleset);
+
+  bitset_free (ruleset);
 
   for (i = 0 ; i < nvars; ++i)
     bitset_free (fderives[i]);
