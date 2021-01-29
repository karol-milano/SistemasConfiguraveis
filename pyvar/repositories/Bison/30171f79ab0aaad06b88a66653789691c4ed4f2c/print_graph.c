@@ -53,9 +53,12 @@ print_core (state_t *state, struct obstack *node_obstack)
   int snitems   = state->nitems;
 
   /* Output all the items of a state, not only its kernel.  */
-  closure (sitems, snitems);
-  sitems = itemset;
-  snitems = nitemset;
+  if (trace_flag)
+    {
+      closure (sitems, snitems);
+      sitems = itemset;
+      snitems = nitemset;
+    }
 
   obstack_fgrow1 (node_obstack, "state %2d\n", state->number);
   for (i = 0; i < snitems; i++)
