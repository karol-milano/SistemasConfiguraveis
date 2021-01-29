@@ -38,18 +38,18 @@ static FILE *fgraph = NULL;
 
 /* This part will construct the label of nodes. */
 static void
-print_core (int state, struct obstack *node_obstack)
+print_core (state_t *state, struct obstack *node_obstack)
 {
   int i;
-  short *sitems = state_table[state]->items;
-  int snitems   = state_table[state]->nitems;
+  short *sitems = state->items;
+  int snitems   = state->nitems;
 
   /* Output all the items of a state, not only its kernel.  */
   closure (sitems, snitems);
   sitems = itemset;
   snitems = nitemset;
 
-  obstack_fgrow1 (node_obstack, "%2d: ", state);
+  obstack_fgrow1 (node_obstack, "%2d: ", state->number);
   for (i = 0; i < snitems; i++)
     {
       short *sp;
@@ -65,7 +65,7 @@ print_core (int state, struct obstack *node_obstack)
 
       if (i)
 	obstack_sgrow (node_obstack, "\n    ");
-      obstack_fgrow1 (node_obstack, " %s  ->  ",
+      obstack_fgrow1 (node_obstack, " %s -> ",
 		      tags[rule_table[rule].lhs]);
 
       for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
@@ -85,14 +85,14 @@ print_core (int state, struct obstack *node_obstack)
 `---------------------------------------------------------------*/
 
 static void
-print_actions (int state, const char *node_name)
+print_actions (state_t *state, const char *node_name)
 {
   int i;
 
-  shifts   *shiftp = state_table[state]->shifts;
-  reductions *redp = state_table[state]->reductions;
+  shifts   *shiftp = state->shifts;
+  reductions *redp = state->reductions;
 #if 0
-  errs       *errp = state_table[state]->errs;
+  errs       *errp = state->errs;
 #endif
 
   static char buff[10];
@@ -117,7 +117,7 @@ print_actions (int state, const char *node_name)
 
 	new_edge (&edge);
 
-	if (state > state1)
+	if (state->number > state1)
 	  edge.type = back_edge;
 	open_edge (&edge, fgraph);
 	/* The edge source is the current node.  */
@@ -155,7 +155,7 @@ print_actions (int state, const char *node_name)
 	obstack_1grow (node_obstack, '\n');
     }
 
-  if (state_table[state]->consistent && redp)
+  if (state->consistent && redp)
     {
       rule = redp->rules[0];
       symbol = rule_table[rule].lhs;
@@ -176,7 +176,7 @@ print_actions (int state, const char *node_name)
 `-------------------------------------------------------------*/
 
 static void
-print_state (int state)
+print_state (state_t *state)
 {
   static char name[10];
   struct obstack node_obstack;
@@ -185,7 +185,7 @@ print_state (int state)
   /* The labels of the nodes are their the items.  */
   obstack_init (&node_obstack);
   new_node (&node);
-  sprintf (name, "%d", state);
+  sprintf (name, "%d", state->number);
   node.title = name;
   print_core (state, &node_obstack);
   obstack_1grow (&node_obstack, '\0');
@@ -235,7 +235,7 @@ print_graph (void)
   /* Output nodes and edges. */
   new_closure (nitems);
   for (i = 0; i < nstates; i++)
-    print_state (i);
+    print_state (state_table[i]);
   free_closure ();
 
   /* Close graph. */
