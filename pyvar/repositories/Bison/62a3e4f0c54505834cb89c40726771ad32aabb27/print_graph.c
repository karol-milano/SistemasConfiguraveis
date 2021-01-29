@@ -50,7 +50,7 @@ static void
 print_core (state_t *state, struct obstack *node_obstack)
 {
   int i;
-  short *sitems = state->items;
+  item_number_t *sitems = state->items;
   int snritems   = state->nitems;
 
   /* Output all the items of a state, not only its kernel.  */
@@ -64,8 +64,8 @@ print_core (state_t *state, struct obstack *node_obstack)
   obstack_fgrow1 (node_obstack, "state %2d\n", state->number);
   for (i = 0; i < snritems; i++)
     {
-      short *sp;
-      short *sp1;
+      item_number_t *sp;
+      item_number_t *sp1;
       int rule;
 
       sp1 = sp = ritem + sitems[i];
