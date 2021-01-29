@@ -51,18 +51,18 @@ print_core (state_t *state, struct obstack *node_obstack)
 {
   int i;
   short *sitems = state->items;
-  int snitems   = state->nitems;
+  int snritems   = state->nitems;
 
   /* Output all the items of a state, not only its kernel.  */
   if (trace_flag)
     {
-      closure (sitems, snitems);
+      closure (sitems, snritems);
       sitems = itemset;
-      snitems = nitemset;
+      snritems = nritemset;
     }
 
   obstack_fgrow1 (node_obstack, "state %2d\n", state->number);
-  for (i = 0; i < snitems; i++)
+  for (i = 0; i < snritems; i++)
     {
       short *sp;
       short *sp1;
