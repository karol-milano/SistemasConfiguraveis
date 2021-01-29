@@ -185,7 +185,7 @@ AnnotationList__compute_conflicted_tokens (bitset shift_tokens,
 }
 
 static bool
-AnnotationList__compute_lhs_contributions (state *s, rule *the_rule,
+AnnotationList__compute_lhs_contributions (state *s, const rule *the_rule,
                                            symbol_number conflicted_token,
                                            bitsetv follow_kernel_items,
                                            bitsetv always_follows,
@@ -263,18 +263,12 @@ AnnotationList__computePredecessorAnnotations (
                 /* If this kernel item is next to the beginning of the RHS,
                    then check all of the predecessor's goto follows for the
                    LHS.  */
-                if (item_number_is_rule_number (ritem[s->items[self_item]
-                                                      - 2]))
+                if (item_number_is_rule_number (ritem[s->items[self_item] - 2]))
                   {
-                    int rulei;
-                    for (rulei = s->items[self_item];
-                         !item_number_is_rule_number (ritem[rulei]);
-                         ++rulei)
-                      continue;
                     Sbitset items;
                     if (AnnotationList__compute_lhs_contributions (
                           *predecessor,
-                          &rules[item_number_as_rule_number (ritem[rulei])],
+                          item_rule (&ritem[s->items[self_item]]),
                           contribution_token,
                           follow_kernel_items, always_follows, predecessors,
                           item_lookahead_sets, &items, annotations_obstackp))
