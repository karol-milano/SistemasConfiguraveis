@@ -199,7 +199,6 @@ initialize_goto_follows (void)
 {
   goto_number **reads = xnmalloc (ngotos, sizeof *reads);
   goto_number *edge = xnmalloc (ngotos, sizeof *edge);
-  goto_number nedges = 0;
 
   goto_follows = bitsetv_create (ngotos, ntokens, BITSET_FIXED);
 
@@ -212,6 +211,8 @@ initialize_goto_follows (void)
       FOR_EACH_SHIFT (trans, j)
         bitset_set (goto_follows[i], TRANSITION_SYMBOL (trans, j));
 
+      /* Gotos outgoing from DST. */
+      goto_number nedges = 0;
       for (; j < trans->num; ++j)
         {
           symbol_number sym = TRANSITION_SYMBOL (trans, j);
@@ -229,7 +230,6 @@ initialize_goto_follows (void)
           reads[i] = xnmalloc (nedges + 1, sizeof reads[i][0]);
           memcpy (reads[i], edge, nedges * sizeof edge[0]);
           reads[i][nedges] = END_NODE;
-          nedges = 0;
         }
     }
   if (trace_flag & trace_automaton)
