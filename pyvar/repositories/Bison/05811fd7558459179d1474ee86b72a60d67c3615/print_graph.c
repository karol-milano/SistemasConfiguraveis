@@ -51,7 +51,7 @@ print_core (struct obstack *oout, state_t *state)
   int snritems   = state->nitems;
 
   /* Output all the items of a state, not only its kernel.  */
-  if (trace_flag)
+  if (report_flag & report_itemsets)
     {
       closure (sitems, snritems);
       sitems = itemset;
@@ -86,7 +86,8 @@ print_core (struct obstack *oout, state_t *state)
 	obstack_fgrow1 (oout, " %s", symbol_tag_get (symbols[*sp]));
 
       /* Experimental feature: display the lookaheads. */
-      if (trace_flag && state->nlookaheads)
+      if ((report_flag & report_lookaheads)
+	  && state->nlookaheads)
 	{
 	  int j, k;
 	  int nlookaheads = 0;
