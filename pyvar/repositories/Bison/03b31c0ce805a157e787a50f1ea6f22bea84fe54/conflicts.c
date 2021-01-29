@@ -1,5 +1,6 @@
 /* Find and resolve or report look-ahead conflicts for bison,
-   Copyright 1984, 1989, 1992, 2000, 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 1992, 2000, 2001, 2002
+   Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -97,7 +98,7 @@ resolve_sr_conflict (state_t *state, int lookahead)
 {
   int i;
   /* find the rule to reduce by to get precedence of reduction  */
-  int redprec = LArule[lookahead]->prec;
+  int redprec = LArule[lookahead]->prec->prec;
   errs *errp = errs_new (ntokens + 1);
   errp->nerrs = 0;
 
@@ -175,6 +176,7 @@ set_conflicts (state_t *state)
      precedence */
   for (i = 0; i < state->nlookaheads; ++i)
     if (LArule[state->lookaheadsp + i]->prec
+	&& LArule[state->lookaheadsp + i]->prec->prec
 	&& !bitset_disjoint_p (LA[state->lookaheadsp + i], lookaheadset))
       {
 	resolve_sr_conflict (state, state->lookaheadsp + i);
