@@ -18,11 +18,13 @@
    along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
-#include "system.h"
 
 #include "AnnotationList.h"
-#include "lalr.h"
+
+#include "system.h"
+
 #include "ielr.h"
+#include "lalr.h"
 
 /**
  * \pre
@@ -38,15 +40,14 @@ static AnnotationList*
 AnnotationList__alloc_on_obstack (ContributionIndex contribution_count,
                                   struct obstack *annotations_obstackp)
 {
-  AnnotationList *result;
-  size_t contributions_size =
-    contribution_count * sizeof result->contributions[0];
-  result = obstack_alloc (annotations_obstackp,
-                          offsetof (AnnotationList, contributions)
-                          + contributions_size);
-  result->next = NULL;
-  result->inadequacyNode = NULL;
-  return result;
+  AnnotationList *res;
+  size_t contributions_size = contribution_count * sizeof res->contributions[0];
+  res = obstack_alloc (annotations_obstackp,
+                       offsetof (AnnotationList, contributions)
+                       + contributions_size);
+  res->next = NULL;
+  res->inadequacyNode = NULL;
+  return res;
 }
 
 /**
@@ -102,13 +103,12 @@ AnnotationList__insertInto (AnnotationList *self, AnnotationList **list,
   for (node = list; *node; node = &(*node)->next)
     {
       int cmp = 0;
-      ContributionIndex ci;
       if (self->inadequacyNode->id < (*node)->inadequacyNode->id)
         cmp = 1;
       else if ((*node)->inadequacyNode->id < self->inadequacyNode->id)
         cmp = -1;
       else
-        for (ci = 0;
+        for (ContributionIndex ci = 0;
              cmp == 0 && ci < self->inadequacyNode->contributionCount;
              ++ci)
           {
@@ -120,19 +120,16 @@ AnnotationList__insertInto (AnnotationList *self, AnnotationList **list,
             else if (AnnotationList__isContributionAlways (*node, ci))
               cmp = 1;
             else
-              {
-                size_t item;
-                for (item = 0; cmp == 0 && item < nitems; ++item)
-                  {
-                    if (!Sbitset__test (self->contributions[ci], item))
-                      {
-                        if (Sbitset__test ((*node)->contributions[ci], item))
-                          cmp = -1;
-                      }
-                    else if (!Sbitset__test ((*node)->contributions[ci], item))
-                      cmp = 1;
-                  }
-              }
+              for (size_t item = 0; cmp == 0 && item < nitems; ++item)
+                {
+                  if (!Sbitset__test (self->contributions[ci], item))
+                    {
+                      if (Sbitset__test ((*node)->contributions[ci], item))
+                        cmp = -1;
+                    }
+                  else if (!Sbitset__test ((*node)->contributions[ci], item))
+                    cmp = 1;
+                }
           }
       if (cmp < 0)
         {
@@ -232,115 +229,114 @@ AnnotationList__computePredecessorAnnotations (
       annotation_node->inadequacyNode = self->inadequacyNode;
       bool potential_contribution = false;
       bitset *lookaheads = NULL;
-      {
-        for (ContributionIndex ci = 0; ci < self->inadequacyNode->contributionCount; ++ci)
-          {
-            symbol_number contribution_token =
-              InadequacyList__getContributionToken (self->inadequacyNode, ci)
-                ->content->number;
-            if (AnnotationList__isContributionAlways (self, ci))
-              {
-                annotation_node->contributions[ci] = NULL;
-                continue;
-              }
-            annotation_node->contributions[ci] =
-              Sbitset__new_on_obstack ((*predecessor)->nitems,
-                                       annotations_obstackp);
+
+      for (ContributionIndex ci = 0; ci < self->inadequacyNode->contributionCount; ++ci)
+        {
+          symbol_number contribution_token =
+            InadequacyList__getContributionToken (self->inadequacyNode, ci)
+            ->content->number;
+          if (AnnotationList__isContributionAlways (self, ci))
             {
-              size_t predecessor_item = 0;
-              Sbitset sbiter_item;
-              Sbitset__Index self_item;
-              SBITSET__FOR_EACH (self->contributions[ci], s->nitems,
-                                 sbiter_item, self_item)
-                {
-                  /* If this kernel item is the beginning of a RHS, it must be
-                     the kernel item in the start state, and so it has an empty
-                     lookahead set.  Thus, it can't contribute to inadequacies,
-                     and so it should never have been identified as a
-                     contribution.  If, instead, this kernel item is the
-                     successor of the start state's kernel item, the lookahead
-                     set is still empty, and so it also should never have been
-                     identified as a contribution.  This situation is fortunate
-                     because we want to avoid the - 2 below in both cases.  */
-                  aver (s->items[self_item] > 1);
-                  /* If this kernel item is next to the beginning of the RHS,
-                     then check all of the predecessor's goto follows for the
-                     LHS.  */
-                  if (item_number_is_rule_number (ritem[s->items[self_item]
-                                                        - 2]))
-                    {
-                      int rulei;
-                      for (rulei = s->items[self_item];
-                           !item_number_is_rule_number (ritem[rulei]);
-                           ++rulei)
-                        continue;
-                      Sbitset items;
-                      if (AnnotationList__compute_lhs_contributions (
-                            *predecessor,
-                            &rules[item_number_as_rule_number (ritem[rulei])],
-                            contribution_token,
-                            follow_kernel_items, always_follows, predecessors,
-                            item_lookahead_sets, &items, annotations_obstackp))
-                        {
-                          obstack_free (annotations_obstackp,
-                                        annotation_node->contributions[ci]);
-                          annotation_node->contributions[ci] = NULL;
-                          break;
-                        }
-                      else
-                        {
-                          Sbitset__or (annotation_node->contributions[ci],
-                                       annotation_node->contributions[ci],
-                                       items, (*predecessor)->nitems);
-                          obstack_free (annotations_obstackp, items);
-                        }
-                    }
-                  /* If this kernel item is later in the RHS, then check the
-                     predecessor item's lookahead set.  */
-                  else
-                    {
-                      /* We don't have to start the predecessor item search at
-                         the beginning every time because items from both
-                         states are sorted by their indices in ritem.  */
-                      for (;
-                           predecessor_item < (*predecessor)->nitems;
-                           ++predecessor_item)
-                        if ((*predecessor)->items[predecessor_item]
-                            == s->items[self_item] - 1)
-                          break;
-                      aver (predecessor_item != (*predecessor)->nitems);
-                      if (ielr_item_has_lookahead (*predecessor, 0,
-                                                   predecessor_item,
-                                                   contribution_token,
-                                                   predecessors,
-                                                   item_lookahead_sets))
-                        Sbitset__set (annotation_node->contributions[ci],
-                                      predecessor_item);
-                    }
-                }
+              annotation_node->contributions[ci] = NULL;
+              continue;
             }
-            if (annotation_node->contributions[ci])
+          annotation_node->contributions[ci] =
+            Sbitset__new_on_obstack ((*predecessor)->nitems,
+                                     annotations_obstackp);
+          {
+            size_t predecessor_item = 0;
+            Sbitset sbiter_item;
+            Sbitset__Index self_item;
+            SBITSET__FOR_EACH (self->contributions[ci], s->nitems,
+                               sbiter_item, self_item)
               {
-                Sbitset biter;
-                Sbitset__Index i;
-                SBITSET__FOR_EACH (annotation_node->contributions[ci],
-                                   (*predecessor)->nitems, biter, i)
+                /* If this kernel item is the beginning of a RHS, it must be
+                   the kernel item in the start state, and so it has an empty
+                   lookahead set.  Thus, it can't contribute to inadequacies,
+                   and so it should never have been identified as a
+                   contribution.  If, instead, this kernel item is the
+                   successor of the start state's kernel item, the lookahead
+                   set is still empty, and so it also should never have been
+                   identified as a contribution.  This situation is fortunate
+                   because we want to avoid the - 2 below in both cases.  */
+                aver (s->items[self_item] > 1);
+                /* If this kernel item is next to the beginning of the RHS,
+                   then check all of the predecessor's goto follows for the
+                   LHS.  */
+                if (item_number_is_rule_number (ritem[s->items[self_item]
+                                                      - 2]))
                   {
-                    potential_contribution = true;
-                    if (!lookaheads)
+                    int rulei;
+                    for (rulei = s->items[self_item];
+                         !item_number_is_rule_number (ritem[rulei]);
+                         ++rulei)
+                      continue;
+                    Sbitset items;
+                    if (AnnotationList__compute_lhs_contributions (
+                          *predecessor,
+                          &rules[item_number_as_rule_number (ritem[rulei])],
+                          contribution_token,
+                          follow_kernel_items, always_follows, predecessors,
+                          item_lookahead_sets, &items, annotations_obstackp))
                       {
-                        lookaheads = xnmalloc ((*predecessor)->nitems,
-                                               sizeof *lookaheads);
-                        for (size_t j = 0; j < (*predecessor)->nitems; ++j)
-                          lookaheads[j] = NULL;
+                        obstack_free (annotations_obstackp,
+                                      annotation_node->contributions[ci]);
+                        annotation_node->contributions[ci] = NULL;
+                        break;
                       }
-                    if (!lookaheads[i])
-                      lookaheads[i] = bitset_create (ntokens, BITSET_FIXED);
-                    bitset_set (lookaheads[i], contribution_token);
+                    else
+                      {
+                        Sbitset__or (annotation_node->contributions[ci],
+                                     annotation_node->contributions[ci],
+                                     items, (*predecessor)->nitems);
+                        obstack_free (annotations_obstackp, items);
+                      }
+                  }
+                /* If this kernel item is later in the RHS, then check the
+                   predecessor item's lookahead set.  */
+                else
+                  {
+                    /* We don't have to start the predecessor item search at
+                       the beginning every time because items from both
+                       states are sorted by their indices in ritem.  */
+                    for (;
+                         predecessor_item < (*predecessor)->nitems;
+                         ++predecessor_item)
+                      if ((*predecessor)->items[predecessor_item]
+                          == s->items[self_item] - 1)
+                        break;
+                    aver (predecessor_item != (*predecessor)->nitems);
+                    if (ielr_item_has_lookahead (*predecessor, 0,
+                                                 predecessor_item,
+                                                 contribution_token,
+                                                 predecessors,
+                                                 item_lookahead_sets))
+                      Sbitset__set (annotation_node->contributions[ci],
+                                    predecessor_item);
                   }
               }
           }
-      }
+          if (annotation_node->contributions[ci])
+            {
+              Sbitset biter;
+              Sbitset__Index i;
+              SBITSET__FOR_EACH (annotation_node->contributions[ci],
+                                 (*predecessor)->nitems, biter, i)
+                {
+                  potential_contribution = true;
+                  if (!lookaheads)
+                    {
+                      lookaheads = xnmalloc ((*predecessor)->nitems,
+                                             sizeof *lookaheads);
+                      for (size_t j = 0; j < (*predecessor)->nitems; ++j)
+                        lookaheads[j] = NULL;
+                    }
+                  if (!lookaheads[i])
+                    lookaheads[i] = bitset_create (ntokens, BITSET_FIXED);
+                  bitset_set (lookaheads[i], contribution_token);
+                }
+            }
+        }
 
       /* If the predecessor has any contributions besides just "always" and
          "never" contributions:
@@ -425,11 +421,7 @@ AnnotationList__compute_from_inadequacies (
   BITSET_FOR_EACH (biter_conflict, conflicted_tokens, conflicted_token, 0)
     {
       AnnotationList *annotation_node;
-      /* FIXME: Would a BITSET_FRUGAL or BITEST_SPARSE be more efficient?  Now
-         or convert it inside InadequacyList__new_conflict?  */
-      bitset actions = bitset_create (s->reductions->num + 1, BITSET_FIXED);
       ContributionIndex contribution_count = 0;
-      bool potential_contribution = false;
 
       /* Allocate the annotation node.  */
       {
@@ -444,6 +436,11 @@ AnnotationList__compute_from_inadequacies (
                                             annotations_obstackp);
       }
 
+      /* FIXME: Would a BITSET_FRUGAL or BITEST_SPARSE be more efficient?  Now
+         or convert it inside InadequacyList__new_conflict?  */
+      bitset actions = bitset_create (s->reductions->num + 1, BITSET_FIXED);
+      bool potential_contribution = false;
+
       /* Add a contribution for each reduction that has conflicted_token as a
          lookahead.  */
       {
@@ -464,11 +461,8 @@ AnnotationList__compute_from_inadequacies (
                                                annotations_obstackp);
                     /* Catch item_i up to rule_i.  This works because both are
                        sorted on rule number.  */
-                    while (!item_number_is_rule_number (
-                             ritem[s->items[item_i]])
-                           || item_number_as_rule_number (
-                                ritem[s->items[item_i]])
-                              != the_rule->number)
+                    while (!item_number_is_rule_number (ritem[s->items[item_i]])
+                           || item_number_as_rule_number (ritem[s->items[item_i]]) != the_rule->number)
                       {
                         ++item_i;
                         aver (item_i < s->nitems);
@@ -571,44 +565,40 @@ AnnotationList__debug (AnnotationList const *self, size_t nitems, int spaces)
   AnnotationIndex ai;
   for (a = self, ai = 0; a; a = a->next, ++ai)
     {
-      for (int j = 0; j < spaces; ++j)
-        putc (' ', stderr);
-      fprintf (stderr, "Annotation %d (manifesting state %d):\n",
+      fprintf (stderr, "%*sAnnotation %d (manifesting state %d):\n",
+               spaces, "",
                ai, a->inadequacyNode->manifestingState->number);
-      {
-        bitset_bindex rulei
-          = bitset_first (a->inadequacyNode->inadequacy.conflict.actions);
-        for (ContributionIndex ci = 0; ci < a->inadequacyNode->contributionCount; ++ci)
-          {
-            symbol_number token =
-              InadequacyList__getContributionToken (a->inadequacyNode, ci)
-                ->content->number;
-            for (int j = 0; j < spaces+2; ++j)
-              putc (' ', stderr);
-            if (ci == InadequacyList__getShiftContributionIndex (
-                        a->inadequacyNode))
-              fprintf (stderr, "Contributes shift of token %d.\n", token);
-            else
-              {
-                fprintf (stderr, "Contributes token %d", token);
-                aver (rulei != BITSET_BINDEX_MAX);
-                fprintf (stderr, " as lookahead, rule number %d",
-                         a->inadequacyNode->manifestingState
-                           ->reductions->rules[rulei]->number);
-                rulei =
-                  bitset_next (a->inadequacyNode->inadequacy.conflict.actions,
-                               rulei+1);
-                if (AnnotationList__isContributionAlways (a, ci))
-                  fprintf (stderr, " always.");
-                else
-                  {
-                    fprintf (stderr, ", items: ");
-                    Sbitset__fprint (a->contributions[ci], nitems, stderr);
-                  }
-                fprintf (stderr, "\n");
-              }
-          }
-      }
+      bitset_bindex rulei
+        = bitset_first (a->inadequacyNode->inadequacy.conflict.actions);
+      for (ContributionIndex ci = 0; ci < a->inadequacyNode->contributionCount; ++ci)
+        {
+          symbol_number token =
+            InadequacyList__getContributionToken (a->inadequacyNode, ci)
+            ->content->number;
+          fprintf (stderr, "%*s", spaces+2, "");
+          if (ci == InadequacyList__getShiftContributionIndex (
+                                                               a->inadequacyNode))
+            fprintf (stderr, "Contributes shift of token %d.\n", token);
+          else
+            {
+              fprintf (stderr, "Contributes token %d", token);
+              aver (rulei != BITSET_BINDEX_MAX);
+              fprintf (stderr, " as lookahead, rule number %d",
+                       a->inadequacyNode->manifestingState
+                       ->reductions->rules[rulei]->number);
+              rulei =
+                bitset_next (a->inadequacyNode->inadequacy.conflict.actions,
+                             rulei+1);
+              if (AnnotationList__isContributionAlways (a, ci))
+                fprintf (stderr, " always.");
+              else
+                {
+                  fprintf (stderr, ", items: ");
+                  Sbitset__fprint (a->contributions[ci], nitems, stderr);
+                }
+              fprintf (stderr, "\n");
+            }
+        }
     }
 }
 
@@ -775,8 +765,7 @@ AnnotationList__computeDominantContribution (AnnotationList const *self,
   /* R/R conflict, so the reduction with the lowest rule number dominates.
      Fortunately, contributions are sorted by rule number.  */
   for (ContributionIndex ci = 0; ci < self->inadequacyNode->contributionCount; ++ci)
-    if (AnnotationList__stateMakesContribution (self, nitems, ci,
-                                                lookaheads))
+    if (AnnotationList__stateMakesContribution (self, nitems, ci, lookaheads))
       {
         if (require_split_stable
             && !AnnotationList__isContributionAlways (self, ci))
