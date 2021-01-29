@@ -35,7 +35,7 @@
 #include "lalr.h"
 #include "reduce.h"
 
-unsigned int nstates;
+unsigned int nstates = 0;
 /* Initialize the final state to -1, otherwise, it might be set to 0
    by default, and since we don't compute the reductions of the final
    state, we end up not computing the reductions of the initial state,
@@ -190,7 +190,7 @@ new_state (int symbol)
 
   if (trace_flag)
     fprintf (stderr, "Entering new_state, state = %d, symbol = %d (%s)\n",
-	     this_state->number, symbol, symbols[symbol]->tag);
+	     nstates, symbol, symbols[symbol]->tag);
 
   if (nstates >= MAXSHORT)
     fatal (_("too many states (max %d)"), MAXSHORT);
@@ -202,13 +202,18 @@ new_state (int symbol)
 
   shortcpy (p->items, kernel_base[symbol], kernel_size[symbol]);
 
-  last_state->next = p;
+  /* If this is the eoftoken, and this is not the initial state, then
+     this is the final state.  */
+  if (symbol == 0 && first_state)
+    final_state = p->number;
+
+  if (!first_state)
+    first_state = p;
+  if (last_state)
+    last_state->next = p;
   last_state = p;
-  nstates++;
 
-  /* If this is the eoftoken, then this is the final state. */
-  if (symbol == 0)
-    final_state = p->number;
+  nstates++;
 
   return p;
 }
@@ -317,8 +322,10 @@ append_states (void)
 static void
 new_states (void)
 {
-  first_state = last_state = this_state = STATE_ALLOC (0);
-  nstates = 1;
+  /* The 0 at the lhs is the index of the item of this initial rule.  */
+  kernel_base[0][0] = 0;
+  kernel_size[0] = 1;
+  this_state = new_state (0);
 }
 
 
