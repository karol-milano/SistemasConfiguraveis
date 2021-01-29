@@ -34,62 +34,35 @@
 #include "reduce.h"
 #include "reader.h"
 #include "getargs.h"
+#include "bitset.h"
 
-typedef unsigned *BSet;
 typedef short *rule;
 
 
 /* Set of all nonterminals which are not useless.  */
-static BSet N;
+static bitset N;
 
 /* Set of all rules which have no useless nonterminals in their RHS.  */
-static BSet P;
+static bitset P;
 
 /* Set of all accessible symbols.  */
-static BSet V;
+static bitset V;
 
 /* Set of symbols used to define rule precedence (so they are
    `useless', but no warning should be issued).  */
-static BSet V1;
+static bitset V1;
 
 static int nuseful_productions;
 static int nuseless_productions;
 static int nuseful_nonterminals;
 int nuseless_nonterminals;
 
-static bool
-bits_equal (BSet L, BSet R, int n)
-{
-  int i;
-
-  for (i = n - 1; i >= 0; i--)
-    if (L[i] != R[i])
-      return FALSE;
-  return TRUE;
-}
-
-
-static int
-nbits (unsigned i)
-{
-  int count = 0;
-
-  while (i != 0)
-    {
-      i ^= (i & ((unsigned) (-(int) i)));
-      ++count;
-    }
-  return count;
-}
-
-
 static int
-bits_size (BSet S, int n)
+bits_size (bitset S)
 {
   int i, count = 0;
 
-  for (i = n - 1; i >= 0; i--)
-    count += nbits (S[i]);
+  BITSET_EXECUTE (S, 0, i, { ++count; });
   return count;
 }
 
@@ -100,7 +73,7 @@ bits_size (BSet S, int n)
 `-------------------------------------------------------------------*/
 
 static bool
-useful_production (int i, BSet N0)
+useful_production (int i, bitset N0)
 {
   rule r;
   short n;
@@ -110,7 +83,7 @@ useful_production (int i, BSet N0)
 
   for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
     if (ISVAR (n = *r))
-      if (!BITISSET (N0, n - ntokens))
+      if (!bitset_test (N0, n - ntokens))
 	return FALSE;
   return TRUE;
 }
@@ -123,13 +96,15 @@ useful_production (int i, BSet N0)
 static void
 useless_nonterminals (void)
 {
-  BSet Np, Ns;
+  bitset Np, Ns;
   int i;
 
   /* N is set as built.  Np is set being built this iteration. P is
      set of all productions which have a RHS all in N.  */
 
-  Np = XCALLOC (unsigned, WORDSIZE (nvars));
+  Np = bitset_create (nvars, BITSET_FIXED);
+  bitset_zero (Np);
+
 
   /* The set being computed is a set of nonterminals which can derive
      the empty string or strings consisting of all terminals. At each
@@ -149,26 +124,25 @@ useless_nonterminals (void)
 
   while (1)
     {
-      for (i = WORDSIZE (nvars) - 1; i >= 0; i--)
-	Np[i] = N[i];
+      bitset_copy (Np, N);
       for (i = 1; i <= nrules; i++)
 	{
-	  if (!BITISSET (P, i))
+	  if (!bitset_test (P, i))
 	    {
 	      if (useful_production (i, N))
 		{
-		  SETBIT (Np, rules[i].lhs - ntokens);
-		  SETBIT (P, i);
+		  bitset_set (Np, rules[i].lhs - ntokens);
+		  bitset_set (P, i);
 		}
 	    }
 	}
-      if (bits_equal (N, Np, WORDSIZE (nvars)))
+      if (bitset_equal_p (N, Np))
 	break;
       Ns = Np;
       Np = N;
       N = Ns;
     }
-  XFREE (N);
+  bitset_free (N);
   N = Np;
 }
 
@@ -176,7 +150,7 @@ useless_nonterminals (void)
 static void
 inaccessable_symbols (void)
 {
-  BSet Vp, Vs, Pp;
+  bitset Vp, Vs, Pp;
   int i;
   short t;
   rule r;
@@ -204,31 +178,32 @@ inaccessable_symbols (void)
      terminals are printed (if running in verbose mode) so that the
      user can know.  */
 
-  Vp = XCALLOC (unsigned, WORDSIZE (nsyms));
-  Pp = XCALLOC (unsigned, WORDSIZE (nrules + 1));
+  Vp = bitset_create (nsyms, BITSET_FIXED);
+  bitset_zero (Vp);
+  Pp = bitset_create (nrules + 1, BITSET_FIXED);
+  bitset_zero (Pp);
 
   /* If the start symbol isn't useful, then nothing will be useful. */
-  if (BITISSET (N, start_symbol - ntokens))
+  if (bitset_test (N, start_symbol - ntokens))
     {
-      SETBIT (V, start_symbol);
+      bitset_set (V, start_symbol);
 
       while (1)
 	{
-	  for (i = WORDSIZE (nsyms) - 1; i >= 0; i--)
-	    Vp[i] = V[i];
+	  bitset_copy (Vp, V);
 	  for (i = 1; i <= nrules; i++)
 	    {
-	      if (!BITISSET (Pp, i)
-		  && BITISSET (P, i)
-		  && BITISSET (V, rules[i].lhs))
+	      if (!bitset_test (Pp, i)
+		  && bitset_test (P, i)
+		  && bitset_test (V, rules[i].lhs))
 		{
 		  for (r = &ritem[rules[i].rhs]; *r >= 0; r++)
-		    if (ISTOKEN (t = *r) || BITISSET (N, t - ntokens))
-		      SETBIT (Vp, t);
-		  SETBIT (Pp, i);
+		    if (ISTOKEN (t = *r) || bitset_test (N, t - ntokens))
+		      bitset_set (Vp, t);
+		  bitset_set (Pp, i);
 		}
 	    }
-	  if (bits_equal (V, Vp, WORDSIZE (nsyms)))
+	  if (bitset_equal_p (V, Vp))
 	    break;
 	  Vs = Vp;
 	  Vp = V;
@@ -236,30 +211,30 @@ inaccessable_symbols (void)
 	}
     }
 
-  XFREE (V);
+  bitset_free (V);
   V = Vp;
 
   /* Tokens 0, 1, and 2 are internal to Bison.  Consider them useful. */
-  SETBIT (V, 0);		/* end-of-input token */
-  SETBIT (V, 1);		/* error token */
-  SETBIT (V, 2);		/* some undefined token */
+  bitset_set (V, 0);		/* end-of-input token */
+  bitset_set (V, 1);		/* error token */
+  bitset_set (V, 2);		/* some undefined token */
 
-  XFREE (P);
+  bitset_free (P);
   P = Pp;
 
-  nuseful_productions = bits_size (P, WORDSIZE (nrules + 1));
+  nuseful_productions = bits_size (P);
   nuseless_productions = nrules - nuseful_productions;
 
   nuseful_nonterminals = 0;
   for (i = ntokens; i < nsyms; i++)
-    if (BITISSET (V, i))
+    if (bitset_test (V, i))
       nuseful_nonterminals++;
   nuseless_nonterminals = nvars - nuseful_nonterminals;
 
   /* A token that was used in %prec should not be warned about.  */
   for (i = 1; i < nrules; i++)
     if (rules[i].precsym != 0)
-      SETBIT (V1, rules[i].precsym);
+      bitset_set (V1, rules[i].precsym);
 }
 
 static void
@@ -284,7 +259,7 @@ reduce_grammar_tables (void)
 	np = 0;
 	ni = 0;
 	for (pn = 1; pn <= nrules; pn++)
-	  if (BITISSET (P, pn))
+	  if (bitset_test (P, pn))
 	    {
 	      np++;
 	      if (pn != np)
@@ -324,7 +299,7 @@ reduce_grammar_tables (void)
     {
       int pn;
       for (pn = 1; pn <= nrules; pn++)
-	rules[pn].useful = BITISSET (P, pn);
+	rules[pn].useful = bitset_test (P, pn);
     }
 }
 
@@ -344,10 +319,10 @@ nonterminals_reduce (void)
   short *nontermmap = XCALLOC (short, nvars) - ntokens;
   n = ntokens;
   for (i = ntokens; i < nsyms; i++)
-    if (BITISSET (V, i))
+    if (bitset_test (V, i))
       nontermmap[i] = n++;
   for (i = ntokens; i < nsyms; i++)
-    if (!BITISSET (V, i))
+    if (!bitset_test (V, i))
       nontermmap[i] = n++;
 
 
@@ -405,7 +380,7 @@ reduce_output (FILE *out)
     bool b = FALSE;
     int i;
     for (i = 0; i < ntokens; i++)
-      if (!BITISSET (V, i) && !BITISSET (V1, i))
+      if (!bitset_test (V, i) && !bitset_test (V1, i))
 	{
 	  if (!b)
 	    fprintf (out, "%s\n\n", _("Terminals which are not used:"));
@@ -523,10 +498,14 @@ reduce_grammar (void)
 
   /* Allocate the global sets used to compute the reduced grammar */
 
-  N = XCALLOC (unsigned, WORDSIZE (nvars));
-  P = XCALLOC (unsigned, WORDSIZE (nrules + 1));
-  V = XCALLOC (unsigned, WORDSIZE (nsyms));
-  V1 = XCALLOC (unsigned, WORDSIZE (nsyms));
+  N = bitset_create (nvars, BITSET_FIXED);
+  bitset_zero (N);
+  P =  bitset_create (nrules + 1, BITSET_FIXED);
+  bitset_zero (P);
+  V = bitset_create (nsyms, BITSET_FIXED);
+  bitset_zero (V);
+  V1 = bitset_create (nsyms, BITSET_FIXED);
+  bitset_zero (V1);
 
   useless_nonterminals ();
   inaccessable_symbols ();
@@ -538,7 +517,7 @@ reduce_grammar (void)
 
   reduce_print ();
 
-  if (!BITISSET (N, start_symbol - ntokens))
+  if (!bitset_test (N, start_symbol - ntokens))
     fatal (_("Start symbol %s does not derive any sentence"),
 	   symbols[start_symbol]->tag);
 
@@ -564,8 +543,8 @@ reduce_grammar (void)
 void
 reduce_free (void)
 {
-  XFREE (N);
-  XFREE (V);
-  XFREE (V1);
-  XFREE (P);
+  bitset_free (N);
+  bitset_free (V);
+  bitset_free (V1);
+  bitset_free (P);
 }
