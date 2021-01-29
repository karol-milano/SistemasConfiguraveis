@@ -242,7 +242,7 @@ AnnotationList__computePredecessorAnnotations (AnnotationList *self, state *s,
           {
             symbol_number contribution_token =
               InadequacyList__getContributionToken (self->inadequacyNode, ci)
-                ->number;
+                ->content->number;
             if (AnnotationList__isContributionAlways (self, ci))
               {
                 annotation_node->contributions[ci] = NULL;
@@ -549,7 +549,7 @@ AnnotationList__compute_from_inadequacies (
                    does discard annotations in the simplest case of a S/R
                    conflict with no token precedence.  */
                 aver (!bitset_test (shift_tokens, conflicted_token)
-                      || symbols[conflicted_token]->prec);
+                      || symbols[conflicted_token]->content->prec);
                 ++annotation_counts[s->number];
                 if (contribution_count > *max_contributionsp)
                   *max_contributionsp = contribution_count;
@@ -595,7 +595,7 @@ AnnotationList__debug (AnnotationList const *self, size_t nitems, int spaces)
           {
             symbol_number token =
               InadequacyList__getContributionToken (a->inadequacyNode, ci)
-                ->number;
+                ->content->number;
             {
               int j;
               for (j = 0; j < spaces+2; ++j)
@@ -644,7 +644,7 @@ AnnotationList__computeLookaheadFilter (AnnotationList const *self,
             Sbitset biter;
             symbol_number token =
               InadequacyList__getContributionToken (self->inadequacyNode, ci)
-                ->number;
+                ->content->number;
             SBITSET__FOR_EACH (self->contributions[ci], nitems, biter, item)
               bitset_set (lookahead_filter[item], token);
           }
@@ -679,7 +679,8 @@ AnnotationList__stateMakesContribution (AnnotationList const *self,
     return false;
   {
     symbol_number token =
-      InadequacyList__getContributionToken (self->inadequacyNode, ci)->number;
+      InadequacyList__getContributionToken (self->inadequacyNode, ci)
+      ->content->number;
     Sbitset__Index item;
     Sbitset biter;
     SBITSET__FOR_EACH (self->contributions[ci], nitems, biter, item)
@@ -709,7 +710,7 @@ AnnotationList__computeDominantContribution (AnnotationList const *self,
         ContributionIndex ci;
         int actioni;
         ContributionIndex ci_rr_dominator = ContributionIndex__none;
-        int shift_precedence = token->prec;
+        int shift_precedence = token->content->prec;
 
         /* If the token has no precedence set, shift is always chosen.  */
         if (!shift_precedence)
@@ -739,7 +740,7 @@ AnnotationList__computeDominantContribution (AnnotationList const *self,
             if (reduce_precedence
                 && (reduce_precedence < shift_precedence
                     || (reduce_precedence == shift_precedence
-                        && token->assoc == right_assoc)))
+                        && token->content->assoc == right_assoc)))
               continue;
             if (!AnnotationList__stateMakesContribution (self, nitems, ci,
                                                          lookaheads))
@@ -747,7 +748,7 @@ AnnotationList__computeDominantContribution (AnnotationList const *self,
             /* This uneliminated reduction contributes, so see if it can cause
                an error action.  */
             if (reduce_precedence == shift_precedence
-                 && token->assoc == non_assoc)
+                 && token->content->assoc == non_assoc)
               {
                 /* It's not possible to find split-stable domination over
                    shift after a potential %nonassoc.  */
