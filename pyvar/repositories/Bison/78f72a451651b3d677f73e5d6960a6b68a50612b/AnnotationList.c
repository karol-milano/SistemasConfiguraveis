@@ -169,10 +169,10 @@ AnnotationList__compute_conflicted_tokens (bitset shift_tokens,
   bitset_copy (tokens, shift_tokens);
   for (int i = 0; i < reds->num; ++i)
     {
-      bitset_and (conflicted_tokens_rule, tokens, reds->lookahead_tokens[i]);
+      bitset_and (conflicted_tokens_rule, tokens, reds->lookaheads[i]);
       bitset_or (conflicted_tokens,
                  conflicted_tokens, conflicted_tokens_rule);
-      bitset_or (tokens, tokens, reds->lookahead_tokens[i]);
+      bitset_or (tokens, tokens, reds->lookaheads[i]);
       /* Check that rules are sorted on rule number or the next step in
          AnnotationList__compute_from_inadequacies will misbehave.  */
       aver (i == 0 || reds->rules[i-1] < reds->rules[i]);
@@ -401,7 +401,7 @@ AnnotationList__compute_from_inadequacies (
   struct obstack *annotations_obstackp,
   InadequacyListNodeCount *inadequacy_list_node_count)
 {
-  /* Return an empty list if s->lookahead_tokens = NULL.  */
+  /* Return an empty list if s->lookaheads = NULL.  */
   if (s->consistent)
     return;
 
@@ -422,7 +422,7 @@ AnnotationList__compute_from_inadequacies (
       /* Allocate the annotation node.  */
       {
         for (int rule_i = 0; rule_i < s->reductions->num; ++rule_i)
-          if (bitset_test (s->reductions->lookahead_tokens[rule_i],
+          if (bitset_test (s->reductions->lookaheads[rule_i],
                            conflicted_token))
             ++contribution_count;
         if (bitset_test (shift_tokens, conflicted_token))
@@ -445,7 +445,7 @@ AnnotationList__compute_from_inadequacies (
         for (int rule_i = 0; rule_i < s->reductions->num; ++rule_i)
           {
             rule *the_rule = s->reductions->rules[rule_i];
-            if (bitset_test (s->reductions->lookahead_tokens[rule_i],
+            if (bitset_test (s->reductions->lookaheads[rule_i],
                              conflicted_token))
               {
                 bitset_set (actions, rule_i);
