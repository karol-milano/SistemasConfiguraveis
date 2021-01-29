@@ -168,10 +168,9 @@ AnnotationList__compute_conflicted_tokens (bitset shift_tokens,
   bitset conflicted_tokens = bitset_create (ntokens, BITSET_FIXED);
   bitset conflicted_tokens_rule = bitset_create (ntokens, BITSET_FIXED);
   bitset tokens = bitset_create (ntokens, BITSET_FIXED);
-  int i;
 
   bitset_copy (tokens, shift_tokens);
-  for (i = 0; i < reds->num; ++i)
+  for (int i = 0; i < reds->num; ++i)
     {
       bitset_and (conflicted_tokens_rule, tokens, reds->lookahead_tokens[i]);
       bitset_or (conflicted_tokens,
@@ -215,20 +214,17 @@ AnnotationList__compute_lhs_contributions (state *s, rule *the_rule,
 }
 
 static void
-AnnotationList__computePredecessorAnnotations (AnnotationList *self, state *s,
-                                               bitsetv follow_kernel_items,
-                                               bitsetv always_follows,
-                                               state ***predecessors,
-                                               bitset **item_lookahead_sets,
-                                               AnnotationList
-                                                 **annotation_lists,
-                                               AnnotationIndex
-                                                 *annotation_counts,
-                                               struct obstack
-                                                 *annotations_obstackp)
+AnnotationList__computePredecessorAnnotations (
+  AnnotationList *self, state *s,
+  bitsetv follow_kernel_items,
+  bitsetv always_follows,
+  state ***predecessors,
+  bitset **item_lookahead_sets,
+  AnnotationList **annotation_lists,
+  AnnotationIndex *annotation_counts,
+  struct obstack *annotations_obstackp)
 {
-  state **predecessor;
-  for (predecessor = predecessors[s->number]; *predecessor; ++predecessor)
+  for (state **predecessor = predecessors[s->number]; *predecessor; ++predecessor)
     {
       AnnotationList *annotation_node =
         AnnotationList__alloc_on_obstack (
@@ -237,8 +233,7 @@ AnnotationList__computePredecessorAnnotations (AnnotationList *self, state *s,
       bool potential_contribution = false;
       bitset *lookaheads = NULL;
       {
-        ContributionIndex ci;
-        for (ci = 0; ci < self->inadequacyNode->contributionCount; ++ci)
+        for (ContributionIndex ci = 0; ci < self->inadequacyNode->contributionCount; ++ci)
           {
             symbol_number contribution_token =
               InadequacyList__getContributionToken (self->inadequacyNode, ci)
@@ -274,12 +269,12 @@ AnnotationList__computePredecessorAnnotations (AnnotationList *self, state *s,
                   if (item_number_is_rule_number (ritem[s->items[self_item]
                                                         - 2]))
                     {
-                      Sbitset items;
                       unsigned rulei;
                       for (rulei = s->items[self_item];
                            !item_number_is_rule_number (ritem[rulei]);
                            ++rulei)
-                        ;
+                        continue;
+                      Sbitset items;
                       if (AnnotationList__compute_lhs_contributions (
                             *predecessor,
                             &rules[item_number_as_rule_number (ritem[rulei])],
@@ -334,10 +329,9 @@ AnnotationList__computePredecessorAnnotations (AnnotationList *self, state *s,
                     potential_contribution = true;
                     if (!lookaheads)
                       {
-                        size_t j;
                         lookaheads = xnmalloc ((*predecessor)->nitems,
                                                sizeof *lookaheads);
-                        for (j = 0; j < (*predecessor)->nitems; ++j)
+                        for (size_t j = 0; j < (*predecessor)->nitems; ++j)
                           lookaheads[j] = NULL;
                       }
                     if (!lookaheads[i])
@@ -377,8 +371,7 @@ AnnotationList__computePredecessorAnnotations (AnnotationList *self, state *s,
               annotation_node = NULL;
             }
           {
-            size_t i;
-            for (i = 0; i < (*predecessor)->nitems; ++i)
+            for (size_t i = 0; i < (*predecessor)->nitems; ++i)
               if (lookaheads[i])
                 bitset_free (lookaheads[i]);
             free (lookaheads);
@@ -416,23 +409,19 @@ AnnotationList__compute_from_inadequacies (
   struct obstack *annotations_obstackp,
   InadequacyListNodeCount *inadequacy_list_node_count)
 {
-  bitsetv all_lookaheads;
-  bitset shift_tokens;
-  bitset conflicted_tokens;
-  bitset_iterator biter_conflict;
-  bitset_bindex conflicted_token;
-
   /* Return an empty list if s->lookahead_tokens = NULL.  */
   if (s->consistent)
     return;
 
-  all_lookaheads = bitsetv_create (s->nitems, ntokens, BITSET_FIXED);
+  bitsetv all_lookaheads = bitsetv_create (s->nitems, ntokens, BITSET_FIXED);
   bitsetv_ones (all_lookaheads);
-  shift_tokens = AnnotationList__compute_shift_tokens (s->transitions);
-  conflicted_tokens =
+  bitset shift_tokens = AnnotationList__compute_shift_tokens (s->transitions);
+  bitset conflicted_tokens =
     AnnotationList__compute_conflicted_tokens (shift_tokens, s->reductions);
 
   /* Add an inadequacy annotation for each conflicted_token.  */
+  bitset_iterator biter_conflict;
+  bitset_bindex conflicted_token;
   BITSET_FOR_EACH (biter_conflict, conflicted_tokens, conflicted_token, 0)
     {
       AnnotationList *annotation_node;
@@ -444,8 +433,7 @@ AnnotationList__compute_from_inadequacies (
 
       /* Allocate the annotation node.  */
       {
-        int rule_i;
-        for (rule_i = 0; rule_i < s->reductions->num; ++rule_i)
+        for (int rule_i = 0; rule_i < s->reductions->num; ++rule_i)
           if (bitset_test (s->reductions->lookahead_tokens[rule_i],
                            conflicted_token))
             ++contribution_count;
@@ -461,8 +449,7 @@ AnnotationList__compute_from_inadequacies (
       {
         ContributionIndex ci = 0;
         int item_i = 0;
-        int rule_i;
-        for (rule_i = 0; rule_i < s->reductions->num; ++rule_i)
+        for (int rule_i = 0; rule_i < s->reductions->num; ++rule_i)
           {
             rule *the_rule = s->reductions->rules[rule_i];
             if (bitset_test (s->reductions->lookahead_tokens[rule_i],
@@ -584,27 +571,20 @@ AnnotationList__debug (AnnotationList const *self, size_t nitems, int spaces)
   AnnotationIndex ai;
   for (a = self, ai = 0; a; a = a->next, ++ai)
     {
-      {
-        int j;
-        for (j = 0; j < spaces; ++j)
-          putc (' ', stderr);
-      }
+      for (int j = 0; j < spaces; ++j)
+        putc (' ', stderr);
       fprintf (stderr, "Annotation %d (manifesting state %d):\n",
                ai, a->inadequacyNode->manifestingState->number);
       {
-        ContributionIndex ci;
-        bitset_bindex rulei = 0; /* init suppresses compiler warning */
-        rulei = bitset_first (a->inadequacyNode->inadequacy.conflict.actions);
-        for (ci = 0; ci < a->inadequacyNode->contributionCount; ++ci)
+        bitset_bindex rulei
+          = bitset_first (a->inadequacyNode->inadequacy.conflict.actions);
+        for (ContributionIndex ci = 0; ci < a->inadequacyNode->contributionCount; ++ci)
           {
             symbol_number token =
               InadequacyList__getContributionToken (a->inadequacyNode, ci)
                 ->content->number;
-            {
-              int j;
-              for (j = 0; j < spaces+2; ++j)
-                putc (' ', stderr);
-            }
+            for (int j = 0; j < spaces+2; ++j)
+              putc (' ', stderr);
             if (ci == InadequacyList__getShiftContributionIndex (
                         a->inadequacyNode))
               fprintf (stderr, "Contributes shift of token %d.\n", token);
@@ -639,20 +619,17 @@ AnnotationList__computeLookaheadFilter (AnnotationList const *self,
 {
   bitsetv_zero (lookahead_filter);
   for (; self; self = self->next)
-    {
-      ContributionIndex ci;
-      for (ci = 0; ci < self->inadequacyNode->contributionCount; ++ci)
-        if (!AnnotationList__isContributionAlways (self, ci))
-          {
-            Sbitset__Index item;
-            Sbitset biter;
-            symbol_number token =
-              InadequacyList__getContributionToken (self->inadequacyNode, ci)
-                ->content->number;
-            SBITSET__FOR_EACH (self->contributions[ci], nitems, biter, item)
-              bitset_set (lookahead_filter[item], token);
-          }
-    }
+    for (ContributionIndex ci = 0; ci < self->inadequacyNode->contributionCount; ++ci)
+      if (!AnnotationList__isContributionAlways (self, ci))
+        {
+          symbol_number token =
+            InadequacyList__getContributionToken (self->inadequacyNode, ci)
+            ->content->number;
+          Sbitset__Index item;
+          Sbitset biter;
+          SBITSET__FOR_EACH (self->contributions[ci], nitems, biter, item)
+            bitset_set (lookahead_filter[item], token);
+        }
 }
 
 /**
@@ -699,11 +676,10 @@ AnnotationList__computeDominantContribution (AnnotationList const *self,
                                              size_t nitems, bitset *lookaheads,
                                              bool require_split_stable)
 {
-  symbol *token;
   ContributionIndex const ci_shift =
     InadequacyList__getShiftContributionIndex (self->inadequacyNode);
 
-  token = self->inadequacyNode->inadequacy.conflict.token;
+  symbol *token = self->inadequacyNode->inadequacy.conflict.token;
 
   /* S/R conflict.  */
   if (ci_shift != ContributionIndex__none)
@@ -711,9 +687,6 @@ AnnotationList__computeDominantContribution (AnnotationList const *self,
       bool find_stable_domination_over_shift = false;
       bool find_stable_error_action_domination = false;
       {
-        ContributionIndex ci;
-        int actioni;
-        ContributionIndex ci_rr_dominator = ContributionIndex__none;
         int shift_precedence = token->content->prec;
 
         /* If the token has no precedence set, shift is always chosen.  */
@@ -723,11 +696,16 @@ AnnotationList__computeDominantContribution (AnnotationList const *self,
         /* Figure out which reductions contribute, which of those would
            dominate in a R/R comparison, and whether any reduction dominates
            the shift so that the R/R comparison is actually needed.  */
-        for (ci = 0, actioni = bitset_first (self->inadequacyNode->inadequacy
-                                             .conflict.actions);
+        ContributionIndex ci_rr_dominator = ContributionIndex__none;
+        int actioni;
+        ContributionIndex ci;
+        for (ci = 0,
+               actioni = bitset_first (self->inadequacyNode->inadequacy
+                                       .conflict.actions);
              ci < self->inadequacyNode->contributionCount;
-             ++ci, actioni = bitset_next (self->inadequacyNode->inadequacy
-                                          .conflict.actions, actioni+1))
+             ++ci,
+               actioni = bitset_next (self->inadequacyNode->inadequacy
+                                      .conflict.actions, actioni+1))
           {
             int reduce_precedence = 0;
             if (ci == ci_shift)
@@ -796,17 +774,14 @@ AnnotationList__computeDominantContribution (AnnotationList const *self,
 
   /* R/R conflict, so the reduction with the lowest rule number dominates.
      Fortunately, contributions are sorted by rule number.  */
-  {
-    ContributionIndex ci;
-    for (ci = 0; ci < self->inadequacyNode->contributionCount; ++ci)
-      if (AnnotationList__stateMakesContribution (self, nitems, ci,
-                                                  lookaheads))
-        {
-          if (require_split_stable
-              && !AnnotationList__isContributionAlways (self, ci))
-            return ContributionIndex__none;
-          return ci;
-        }
-  }
+  for (ContributionIndex ci = 0; ci < self->inadequacyNode->contributionCount; ++ci)
+    if (AnnotationList__stateMakesContribution (self, nitems, ci,
+                                                lookaheads))
+      {
+        if (require_split_stable
+            && !AnnotationList__isContributionAlways (self, ci))
+          return ContributionIndex__none;
+        return ci;
+      }
   return ContributionIndex__none;
 }
