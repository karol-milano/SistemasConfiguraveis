@@ -70,20 +70,20 @@ print_core (FILE *out, state_t *state)
 {
   int i;
   short *sitems = state->items;
-  int snitems   = state->nitems;
+  int snritems   = state->nitems;
 
   /* New experimental feature: if TRACE_FLAGS output all the items of
      a state, not only its kernel.  */
   if (trace_flag)
     {
-      closure (sitems, snitems);
+      closure (sitems, snritems);
       sitems = itemset;
-      snitems = nitemset;
+      snritems = nritemset;
     }
 
-  if (snitems)
+  if (snritems)
     {
-      for (i = 0; i < snitems; i++)
+      for (i = 0; i < snritems; i++)
 	{
 	  short *sp;
 	  short *sp1;
