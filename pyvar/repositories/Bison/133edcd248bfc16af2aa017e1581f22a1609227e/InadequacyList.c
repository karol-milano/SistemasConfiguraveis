@@ -22,6 +22,8 @@
 
 #include "InadequacyList.h"
 
+#include <intprops.h>
+
 ContributionIndex const ContributionIndex__none = -1;
 ContributionIndex const ContributionIndex__error_action = -2;
 
@@ -31,8 +33,9 @@ InadequacyList__new_conflict (state *manifesting_state, symbol *token,
                               InadequacyListNodeCount *node_count)
 {
   InadequacyList *result = xmalloc (sizeof *result);
-  result->id = (*node_count)++;
-  aver (*node_count != 0);
+  result->id = *node_count;
+  if (INT_ADD_WRAPV (*node_count, 1, node_count))
+    aver (false);
   result->next = NULL;
   result->manifestingState = manifesting_state;
   result->contributionCount = bitset_count (actions);
