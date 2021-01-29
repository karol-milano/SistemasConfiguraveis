@@ -34,7 +34,14 @@
 #include "reduce.h"
 
 int nstates;
-int final_state;
+/* Initialize the final state to -1, otherwise, it might be set to 0
+   by default, and since we don't compute the reductions of the final
+   state, we end up not computing the reductions of the initial state,
+   which is of course needed.
+
+   FINAL_STATE is properly set by new_state when it recognizes the
+   accessing symbol: EOF.  */
+int final_state = -1;
 static state_t *first_state = NULL;
 
 static state_t *this_state = NULL;
