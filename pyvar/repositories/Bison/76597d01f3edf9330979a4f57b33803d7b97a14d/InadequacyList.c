@@ -34,8 +34,10 @@ InadequacyList__new_conflict (state *manifesting_state, symbol *token,
 {
   InadequacyList *result = xmalloc (sizeof *result);
   result->id = *node_count;
+  IGNORE_TYPE_LIMITS_BEGIN
   if (INT_ADD_WRAPV (*node_count, 1, node_count))
     aver (false);
+  IGNORE_TYPE_LIMITS_END
   result->next = NULL;
   result->manifestingState = manifesting_state;
   result->contributionCount = bitset_count (actions);
