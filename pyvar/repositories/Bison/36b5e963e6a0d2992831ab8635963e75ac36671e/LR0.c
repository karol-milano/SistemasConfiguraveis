@@ -1,6 +1,6 @@
 /* Generate the nondeterministic finite state machine for Bison.
 
-   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2004 Free
+   Copyright (C) 1984, 1986, 1989, 2000, 2001, 2002, 2004, 2005 Free
    Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
@@ -66,11 +66,6 @@ state_list_append (symbol_number sym, size_t core_size, item_number *core)
     fprintf (stderr, "state_list_append (state = %d, symbol = %d (%s))\n",
 	     nstates, sym, symbols[sym]->tag);
 
-  /* If this is the endtoken, and this is not the initial state, then
-     this is the final state.  */
-  if (sym == 0 && first_state)
-    final_state = s;
-
   node->next = NULL;
   node->state = s;
 
@@ -213,20 +208,20 @@ new_itemsets (state *s)
 static state *
 get_state (symbol_number sym, size_t core_size, item_number *core)
 {
-  state *sp;
+  state *s;
 
   if (trace_flag & trace_automaton)
     fprintf (stderr, "Entering get_state, symbol = %d (%s)\n",
 	     sym, symbols[sym]->tag);
 
-  sp = state_hash_lookup (core_size, core);
-  if (!sp)
-    sp = state_list_append (sym, core_size, core);
+  s = state_hash_lookup (core_size, core);
+  if (!s)
+    s = state_list_append (sym, core_size, core);
 
   if (trace_flag & trace_automaton)
-    fprintf (stderr, "Exiting get_state => %d\n", sp->number);
+    fprintf (stderr, "Exiting get_state => %d\n", s->number);
 
-  return sp;
+  return s;
 }
 
 /*---------------------------------------------------------------.
@@ -278,9 +273,18 @@ save_reductions (state *s)
   /* Find and count the active items that represent ends of rules. */
   for (i = 0; i < nritemset; ++i)
     {
-      int item = ritem[itemset[i]];
-      if (item < 0)
-	redset[count++] = &rules[item_number_as_rule_number (item)];
+      item_number item = ritem[itemset[i]];
+      if (item_number_is_rule_number (item))
+	{
+	  rule_number r = item_number_as_rule_number (item);
+	  redset[count++] = &rules[r];
+	  if (r == 0)
+	    {
+	      /* This is "reduce 0", i.e., accept. */
+	      assert (!final_state);
+	      final_state = s;
+	    }
+	}
     }
 
   /* Make a reductions structure and copy the data into it.  */
@@ -338,9 +342,8 @@ generate_states (void)
      item of this initial rule.  */
   state_list_append (0, 1, &initial_core);
 
-  list = first_state;
-
-  while (list)
+  /* States are queued when they are created; process them all.  */
+  for (list = first_state; list; list = list->next)
     {
       state *s = list->state;
       if (trace_flag & trace_automaton)
@@ -362,10 +365,6 @@ generate_states (void)
       /* Create the shifts structures for the shifts to those states,
 	 now that the state numbers transitioning to are known.  */
       state_transitions_set (s, nshifts, shiftset);
-
-      /* states are queued when they are created; process them all.
-	 */
-      list = list->next;
     }
 
   /* discard various storage */
