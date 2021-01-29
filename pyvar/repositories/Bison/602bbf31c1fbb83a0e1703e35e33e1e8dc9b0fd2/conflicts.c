@@ -1,5 +1,5 @@
 /* Find and resolve or report look-ahead conflicts for bison,
-   Copyright 1984, 1989, 1992, 2000, 2001 Free Software Foundation, Inc.
+   Copyright 1984, 1989, 1992, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -19,6 +19,7 @@
    02111-1307, USA.  */
 
 #include "system.h"
+#include "bitset.h"
 #include "complain.h"
 #include "getargs.h"
 #include "symtab.h"
@@ -78,7 +79,7 @@ flush_shift (state_t *state, int token)
 static void
 flush_reduce (int lookahead, int token)
 {
-  RESETBIT (LA (lookahead), token);
+  bitset_reset (LA[lookahead], token);
 }
 
 
@@ -99,7 +100,7 @@ resolve_sr_conflict (state_t *state, int lookahead)
   errp->nerrs = 0;
 
   for (i = 0; i < ntokens; i++)
-    if (BITISSET (LA (lookahead), i)
+    if (bitset_test (LA[lookahead], i)
 	&& BITISSET (lookaheadset, i)
 	&& symbols[i]->prec)
       {
@@ -173,8 +174,9 @@ set_conflicts (state_t *state)
      precedence */
   for (i = 0; i < state->nlookaheads; ++i)
     if (rules[LAruleno[state->lookaheadsp + i]].prec)
-      for (j = 0; j < tokensetsize; ++j)
-	if (LA (state->lookaheadsp + i)[j] & lookaheadset[j])
+      for (j = 0; j < ntokens; ++j)
+	if (bitset_test (LA[state->lookaheadsp + i], j)
+	    && BITISSET (lookaheadset, j))
 	  {
 	    resolve_sr_conflict (state, state->lookaheadsp + i);
 	    break;
@@ -185,19 +187,21 @@ set_conflicts (state_t *state)
      for conflicts not resolved above.  */
   for (i = 0; i < state->nlookaheads; ++i)
     {
-      for (j = 0; j < tokensetsize; ++j)
-	if (LA (state->lookaheadsp + i)[j] & lookaheadset[j])
+      for (j = 0; j < ntokens; ++j)
+	if (bitset_test (LA[state->lookaheadsp + i], j)
+	    && BITISSET (lookaheadset, j))
 	  conflicts[state->number] = 1;
 
-      for (j = 0; j < tokensetsize; ++j)
-	lookaheadset[j] |= LA (state->lookaheadsp + i)[j];
+      for (j = 0; j < ntokens; ++j)
+	if (bitset_test (LA[state->lookaheadsp + i], j))
+	  SETBIT (lookaheadset, j);
     }
 }
 
 void
 solve_conflicts (void)
 {
-  int i;
+  size_t i;
 
   conflicts = XCALLOC (char, nstates);
   shiftset = XCALLOC (unsigned, tokensetsize);
@@ -233,8 +237,9 @@ count_sr_conflicts (state_t *state)
       SETBIT (shiftset, SHIFT_SYMBOL (shiftp, i));
 
   for (i = 0; i < state->nlookaheads; ++i)
-    for (k = 0; k < tokensetsize; ++k)
-      lookaheadset[k] |= LA (state->lookaheadsp + i)[k];
+    for (k = 0; k < ntokens; ++k)
+      if (bitset_test (LA[state->lookaheadsp + i], k))
+	SETBIT (lookaheadset, k);
 
   for (k = 0; k < tokensetsize; ++k)
     lookaheadset[k] &= shiftset[k];
@@ -265,7 +270,7 @@ count_rr_conflicts (state_t *state)
       int count = 0;
       int j;
       for (j = 0; j < state->nlookaheads; ++j)
-	if (BITISSET (LA (state->lookaheadsp + j), i))
+	if (bitset_test (LA[state->lookaheadsp + j], i))
 	  count++;
 
       if (count >= 2)
@@ -322,7 +327,7 @@ void
 conflicts_output (FILE *out)
 {
   bool printed_sth = FALSE;
-  int i;
+  size_t i;
   for (i = 0; i < nstates; i++)
     if (conflicts[i])
       {
@@ -343,7 +348,7 @@ conflicts_output (FILE *out)
 void
 conflicts_print (void)
 {
-  int i;
+  size_t i;
 
   /* Is the number of SR conflicts OK?  Either EXPECTED_CONFLICTS is
      not set, and then we want 0 SR, or else it is specified, in which
