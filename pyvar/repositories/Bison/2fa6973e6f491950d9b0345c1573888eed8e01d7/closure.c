@@ -19,52 +19,15 @@
    02111-1307, USA.  */
 
 
-/* Subroutines of file LR0.c.
-
-Entry points:
-
-  closure (items, n)
-
-Given a vector of item numbers items, of length n, set up ruleset and
-itemset to indicate what rules could be run and which items could be
-accepted when those items are the active ones.
-
-ruleset contains a bit for each rule.  closure sets the bits for all
-rules which could potentially describe the next input to be read.
-
-itemset is a vector of item numbers; itemsetend points to just beyond
-the end of the part of it that is significant.  closure places there
-the indices of all items which represent units of input that could
-arrive next.
-
-  initialize_closure (n)
-
-Allocates the itemset and ruleset vectors, and precomputes useful data
-so that closure can be called.  n is the number of elements to
-allocate for itemset.
-
-  finalize_closure ()
-
-Frees itemset, ruleset and internal data.
-
-*/
-
 #include "system.h"
 #include "alloc.h"
 #include "gram.h"
-
+#include "closure.h"
 
 extern short **derives;
 extern char **tags;
 
-extern void initialize_closure PARAMS((int));
-extern void closure PARAMS((short *, int));
-extern void finalize_closure PARAMS((void));
-
-static void set_fderives PARAMS((void));
-static void set_firsts PARAMS((void));
-
-extern void RTC PARAMS((unsigned *, int));
+extern void RTC PARAMS ((unsigned *, int));
 
 short *itemset;
 short *itemsetend;
@@ -79,47 +42,143 @@ static int rulesetsize;
 
 /* number of words required to hold a bit for each variable */
 static int varsetsize;
+
+#if DEBUG
 
-#ifdef DEBUG
-static void print_closure PARAMS((int));
-static void print_fderives PARAMS((void));
-static void print_firsts PARAMS((void));
-#endif
+/*-----------------.
+| Debugging code.  |
+`-----------------*/
 
-void
-initialize_closure (int n)
+static void
+print_closure (int n)
+{
+  short *isp;
+
+  printf ("\n\nn = %d\n\n", n);
+  for (isp = itemset; isp < itemsetend; isp++)
+    printf ("   %d\n", *isp);
+}
+
+
+static void
+print_firsts (void)
 {
-  itemset = NEW2(n, short);
+  int i;
+  int j;
+  unsigned *rowp;
+
+  printf ("\n\n\nFIRSTS\n\n");
+
+  for (i = ntokens; i < nsyms; i++)
+    {
+      printf ("\n\n%s firsts\n\n", tags[i]);
 
-  rulesetsize = WORDSIZE(nrules + 1);
-  ruleset = NEW2(rulesetsize, unsigned);
+      rowp = firsts + ((i - ntokens) * varsetsize);
 
-  set_fderives();
+      for (j = 0; j < nvars; j++)
+	if (BITISSET (rowp, j))
+	  printf ("   %s\n", tags[j + ntokens]);
+    }
 }
 
 
+static void
+print_fderives (void)
+{
+  int i;
+  int j;
+  unsigned *rp;
+
+  printf ("\n\n\nFDERIVES\n");
+
+  for (i = ntokens; i < nsyms; i++)
+    {
+      printf ("\n\n%s derives\n\n", tags[i]);
+      rp = fderives + i * rulesetsize;
+
+      for (j = 0; j <= nrules; j++)
+	if (BITISSET (rp, j))
+	  printf ("   %d\n", j);
+    }
+
+  fflush (stdout);
+}
+#endif
+
+/*-------------------------------------------------------------------.
+| Set FIRSTS to be an NVARS by NVARS bit matrix indicating which     |
+| items can represent the beginning of the input corresponding to    |
+| which other items.                                                 |
+|                                                                    |
+| For example, if some rule expands symbol 5 into the sequence of    |
+| symbols 8 3 20, the symbol 8 can be the beginning of the data for  |
+| symbol 5, so the bit [8 - ntokens, 5 - ntokens] in firsts is set.  |
+`-------------------------------------------------------------------*/
+
+static void
+set_firsts (void)
+{
+  unsigned *row;
+  int symbol;
+  short *sp;
+  int rowsize;
+
+  int i;
+
+  varsetsize = rowsize = WORDSIZE (nvars);
+
+  firsts = NEW2 (nvars * rowsize, unsigned);
+
+  row = firsts;
+  for (i = ntokens; i < nsyms; i++)
+    {
+      sp = derives[i];
+      while (*sp >= 0)
+	{
+	  symbol = ritem[rrhs[*sp++]];
+	  if (ISVAR (symbol))
+	    {
+	      symbol -= ntokens;
+	      SETBIT (row, symbol);
+	    }
+	}
+
+      row += rowsize;
+    }
+
+  RTC (firsts, nvars);
+
+#ifdef	DEBUG
+  print_firsts ();
+#endif
+}
+
+/*-------------------------------------------------------------------.
+| Set FDERIVES to an NVARS by NRULES matrix of bits indicating which |
+| rules can help derive the beginning of the data for each           |
+| nonterminal.                                                       |
+|                                                                    |
+| For example, if symbol 5 can be derived as the sequence of symbols |
+| 8 3 20, and one of the rules for deriving symbol 8 is rule 4, then |
+| the [5 - NTOKENS, 4] bit in FDERIVES is set.                       |
+`-------------------------------------------------------------------*/
 
-/* set fderives to an nvars by nrules matrix of bits
-   indicating which rules can help derive the beginning of the data
-   for each nonterminal.  For example, if symbol 5 can be derived as
-   the sequence of symbols 8 3 20, and one of the rules for deriving
-   symbol 8 is rule 4, then the [5 - ntokens, 4] bit in fderives is set.  */
 static void
 set_fderives (void)
 {
-  register unsigned *rrow;
-  register unsigned *vrow;
-  register int j;
-  register unsigned cword;
-  register short *rp;
-  register int b;
+  unsigned *rrow;
+  unsigned *vrow;
+  int j;
+  unsigned cword;
+  short *rp;
+  int b;
 
   int ruleno;
   int i;
 
-  fderives = NEW2(nvars * rulesetsize, unsigned) - ntokens * rulesetsize;
+  fderives = NEW2 (nvars * rulesetsize, unsigned) - ntokens * rulesetsize;
 
-  set_firsts();
+  set_firsts ();
 
   rrow = fderives + ntokens * rulesetsize;
 
@@ -135,7 +194,7 @@ set_fderives (void)
 	      rp = derives[j];
 	      while ((ruleno = *rp++) > 0)
 		{
-		  SETBIT(rrow, ruleno);
+		  SETBIT (rrow, ruleno);
 		}
 	    }
 
@@ -151,71 +210,34 @@ set_fderives (void)
     }
 
 #ifdef	DEBUG
-  print_fderives();
+  print_fderives ();
 #endif
 
-  FREE(firsts);
+  FREE (firsts);
 }
+
 
-
-
-/* set firsts to be an nvars by nvars bit matrix indicating which
-   items can represent the beginning of the input corresponding to
-   which other items.
-
-   For example, if some rule expands symbol 5 into the sequence of
-   symbols 8 3 20, the symbol 8 can be the beginning of the data for
-   symbol 5, so the bit [8 - ntokens, 5 - ntokens] in firsts is
-   set. */
-
-static void
-set_firsts (void)
+void
+new_closure (int n)
 {
-  register unsigned *row;
-/*   register int done; JF unused */
-  register int symbol;
-  register short *sp;
-  register int rowsize;
-
-  int i;
+  itemset = NEW2 (n, short);
 
-  varsetsize = rowsize = WORDSIZE(nvars);
+  rulesetsize = WORDSIZE (nrules + 1);
+  ruleset = NEW2 (rulesetsize, unsigned);
 
-  firsts = NEW2(nvars * rowsize, unsigned);
-
-  row = firsts;
-  for (i = ntokens; i < nsyms; i++)
-    {
-      sp = derives[i];
-      while (*sp >= 0)
-	{
-	  symbol = ritem[rrhs[*sp++]];
-	  if (ISVAR(symbol))
-	    {
-	      symbol -= ntokens;
-	      SETBIT(row, symbol);
-	    }
-	}
-
-      row += rowsize;
-    }
-
-  RTC(firsts, nvars);
-
-#ifdef	DEBUG
-  print_firsts ();
-#endif
+  set_fderives ();
 }
 
 
+
 void
 closure (short *core, int n)
 {
-  register int ruleno;
-  register unsigned word;
-  register short *csp;
-  register unsigned *dsp;
-  register unsigned *rsp;
+  int ruleno;
+  unsigned word;
+  short *csp;
+  unsigned *dsp;
+  unsigned *rsp;
 
   short *csend;
   unsigned *rsend;
@@ -241,7 +263,7 @@ closure (short *core, int n)
       while (csp < csend)
 	{
 	  symbol = ritem[*csp++];
-	  if (ISVAR(symbol))
+	  if (ISVAR (symbol))
 	    {
 	      dsp = fderives + symbol * rulesetsize;
 	      rsp = ruleset;
@@ -264,7 +286,7 @@ closure (short *core, int n)
 	}
       else
 	{
-	  register int b;
+	  int b;
 
 	  for (b = 0; b < BITS_PER_WORD; b++)
 	    {
@@ -284,77 +306,16 @@ closure (short *core, int n)
   while (csp < csend)
     *itemsetend++ = *csp++;
 
-#ifdef	DEBUG
-  print_closure(n);
+#if DEBUG
+  print_closure (n);
 #endif
 }
 
 
 void
-finalize_closure (void)
-{
-  FREE(itemset);
-  FREE(ruleset);
-  FREE(fderives + ntokens * rulesetsize);
-}
-
-
-
-#ifdef	DEBUG
-
-static void
-print_closure(int n)
-{
-  register short *isp;
-
-  printf ("\n\nn = %d\n\n", n);
-  for (isp = itemset; isp < itemsetend; isp++)
-    printf ("   %d\n", *isp);
-}
-
-
-static void
-print_firsts (void)
+free_closure (void)
 {
-  register int i;
-  register int j;
-  register unsigned *rowp;
-
-  printf ("\n\n\nFIRSTS\n\n");
-
-  for (i = ntokens; i < nsyms; i++)
-    {
-      printf ("\n\n%s firsts\n\n", tags[i]);
-
-      rowp = firsts + ((i - ntokens) * varsetsize);
-
-      for (j = 0; j < nvars; j++)
-	if (BITISSET (rowp, j))
-	  printf ("   %s\n", tags[j + ntokens]);
-    }
+  FREE (itemset);
+  FREE (ruleset);
+  FREE (fderives + ntokens * rulesetsize);
 }
-
-
-static void
-print_fderives (void)
-{
-  register int i;
-  register int j;
-  register unsigned *rp;
-
-  printf ("\n\n\nFDERIVES\n");
-
-  for (i = ntokens; i < nsyms; i++)
-    {
-      printf ("\n\n%s derives\n\n", tags[i]);
-      rp = fderives + i * rulesetsize;
-
-      for (j = 0; j <= nrules; j++)
-	if (BITISSET (rp, j))
-	  printf ("   %d\n", j);
-    }
-
-  fflush(stdout);
-}
-
-#endif
