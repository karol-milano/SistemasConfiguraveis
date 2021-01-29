@@ -1,5 +1,5 @@
 /* Print information on generated parser, for bison,
-   Copyright 1984, 1986, 1989, 2000, 2001 Free Software Foundation, Inc.
+   Copyright 1984, 1986, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -33,9 +33,10 @@
 #include "print.h"
 #include "reduce.h"
 #include "closure.h"
+#include "bitset.h"
 
-static unsigned *shiftset = NULL;
-static unsigned *lookaheadset = NULL;
+static bitset shiftset;
+static bitset lookaheadset;
 
 #if 0
 static void
@@ -194,8 +195,7 @@ print_reductions (FILE *out, state_t *state)
       return;
     }
 
-  for (i = 0; i < tokensetsize; i++)
-    shiftset[i] = 0;
+  bitset_zero (shiftset);
 
   for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
     if (!SHIFT_IS_DISABLED (shiftp, i))
@@ -204,23 +204,26 @@ print_reductions (FILE *out, state_t *state)
 	   default rule.  */
 	if (SHIFT_IS_ERROR (shiftp, i))
 	  nodefault = 1;
-	SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
+	bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
       }
 
   for (i = 0; i < errp->nerrs; i++)
     if (errp->errs[i])
-      SETBIT (shiftset, errp->errs[i]);
+      bitset_set (shiftset, errp->errs[i]);
 
   if (state->nlookaheads == 1 && !nodefault)
     {
-      int k;
       int default_rule = LAruleno[state->lookaheadsp];
 
-      for (k = 0; k < tokensetsize; ++k)
-	lookaheadset[k] = LA (state->lookaheadsp)[k] & shiftset[k];
+      for (i = 0; i < ntokens; ++i)
+	if (BITISSET (LA (state->lookaheadsp), i)
+	    && bitset_test (shiftset, i))
+	  bitset_set (lookaheadset, i);
+	else
+	  bitset_reset (lookaheadset, i);
 
       for (i = 0; i < ntokens; i++)
-	if (BITISSET (lookaheadset, i))
+	if (bitset_test (lookaheadset, i))
 	  fprintf (out, _("    %-4s\t[reduce using rule %d (%s)]\n"),
 		   escape (symbols[i]->tag), default_rule - 1,
 		   escape2 (symbols[rules[default_rule].lhs]->tag));
@@ -240,11 +243,15 @@ print_reductions (FILE *out, state_t *state)
 	    int count = 0;
 	    int j, k;
 
-	    for (k = 0; k < tokensetsize; ++k)
-	      lookaheadset[k] = LA (state->lookaheadsp + i)[k] & ~shiftset[k];
+	    for (k = 0; k < ntokens; ++k)
+	      if (BITISSET (LA (state->lookaheadsp + i), k)
+		  && ! bitset_test (shiftset, k))
+		bitset_set (lookaheadset, k);
+	      else
+		bitset_reset (lookaheadset, k);
 
 	    for (j = 0; j < ntokens; j++)
-	      if (BITISSET (lookaheadset, j))
+	      if (bitset_test (lookaheadset, j))
 		count++;
 
 	    if (count > cmax)
@@ -254,22 +261,20 @@ print_reductions (FILE *out, state_t *state)
 		default_rule = LAruleno[state->lookaheadsp + i];
 	      }
 
-	    for (k = 0; k < tokensetsize; ++k)
-	      shiftset[k] |= lookaheadset[k];
+	    bitset_or (shiftset, shiftset, lookaheadset);
 	  }
 
-      for (i = 0; i < tokensetsize; i++)
-	shiftset[i] = 0;
+      bitset_zero (shiftset);
 
       for (i = 0; i < shiftp->nshifts && SHIFT_IS_SHIFT (shiftp, i); i++)
 	if (!SHIFT_IS_DISABLED (shiftp, i))
-	  SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
+	  bitset_set (shiftset, SHIFT_SYMBOL (shiftp, i));
 
       for (i = 0; i < ntokens; i++)
 	{
 	  int j;
 	  int defaulted = 0;
-	  int count = BITISSET (shiftset, i);
+	  int count = bitset_test (shiftset, i);
 
 	  for (j = 0; j < state->nlookaheads; ++j)
 	    {
@@ -498,12 +503,14 @@ print_results (void)
   if (trace_flag)
     new_closure (nritems);
   /* Storage for print_reductions.  */
-  shiftset = XCALLOC (unsigned, tokensetsize);
-  lookaheadset = XCALLOC (unsigned, tokensetsize);
+  shiftset =  bitset_create (ntokens, BITSET_FIXED);
+  bitset_zero (shiftset);
+  lookaheadset = bitset_create (ntokens, BITSET_FIXED);
+  bitset_zero (lookaheadset);
   for (i = 0; i < nstates; i++)
     print_state (out, states[i]);
-  free (shiftset);
-  free (lookaheadset);
+  bitset_free (shiftset);
+  bitset_free (lookaheadset);
   if (trace_flag)
     free_closure ();
 
