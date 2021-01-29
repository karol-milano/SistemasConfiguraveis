@@ -27,9 +27,12 @@ ContributionIndex const ContributionIndex__error_action = -2;
 
 InadequacyList *
 InadequacyList__new_conflict (state *manifesting_state, symbol *token,
-                              bitset actions)
+                              bitset actions,
+                              InadequacyListNodeCount *node_count)
 {
   InadequacyList *result = xmalloc (sizeof *result);
+  result->id = (*node_count)++;
+  aver (*node_count != 0);
   result->next = NULL;
   result->manifestingState = manifesting_state;
   result->contributionCount = bitset_count (actions);
