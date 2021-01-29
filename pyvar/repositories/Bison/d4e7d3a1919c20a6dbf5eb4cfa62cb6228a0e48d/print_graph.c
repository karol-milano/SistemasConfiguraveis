@@ -47,7 +47,7 @@ escape (const char *s)
 
 /* This part will construct the label of nodes. */
 static void
-print_core (state_t *state, struct obstack *node_obstack)
+print_core (struct obstack *oout, state_t *state)
 {
   int i;
   item_number_t *sitems = state->items;
@@ -61,7 +61,7 @@ print_core (state_t *state, struct obstack *node_obstack)
       snritems = nritemset;
     }
 
-  obstack_fgrow1 (node_obstack, "state %2d\n", state->number);
+  obstack_fgrow1 (oout, "state %2d\n", state->number);
   for (i = 0; i < snritems; i++)
     {
       item_number_t *sp;
@@ -76,17 +76,43 @@ print_core (state_t *state, struct obstack *node_obstack)
       rule = -(*sp);
 
       if (i)
-	obstack_1grow (node_obstack, '\n');
-      obstack_fgrow1 (node_obstack, " %s -> ",
+	obstack_1grow (oout, '\n');
+      obstack_fgrow1 (oout, " %s -> ",
 		      escape (rules[rule].lhs->tag));
 
       for (sp = rules[rule].rhs; sp < sp1; sp++)
-	obstack_fgrow1 (node_obstack, "%s ", escape (symbols[*sp]->tag));
+	obstack_fgrow1 (oout, "%s ", escape (symbols[*sp]->tag));
 
-      obstack_1grow (node_obstack, '.');
+      obstack_1grow (oout, '.');
 
       for (/* Nothing */; *sp >= 0; ++sp)
-	obstack_fgrow1 (node_obstack, " %s", escape (symbols[*sp]->tag));
+	obstack_fgrow1 (oout, " %s", escape (symbols[*sp]->tag));
+
+      /* Experimental feature: display the lookaheads. */
+      if (trace_flag && state->nlookaheads)
+	{
+	  int j, k;
+	  int nlookaheads = 0;
+	  /* Look for lookaheads corresponding to this rule. */
+	  for (j = 0; j < state->nlookaheads; ++j)
+	    for (k = 0; k < ntokens; ++k)
+	      if (bitset_test (LA[state->lookaheadsp + j], k)
+		  && LArule[state->lookaheadsp + j]->number == rule)
+		nlookaheads++;
+	  if (nlookaheads)
+	    {
+	      obstack_sgrow (oout, "  [");
+	      for (j = 0; j < state->nlookaheads; ++j)
+		for (k = 0; k < ntokens; ++k)
+		  if (bitset_test (LA[state->lookaheadsp + j], k)
+		      && LArule[state->lookaheadsp + j]->number == rule)
+		    obstack_fgrow2 (oout, "%s%s",
+				    quotearg_style (escape_quoting_style,
+						    symbols[k]->tag),
+				    --nlookaheads ? ", " : "");
+	      obstack_sgrow (oout, "]");
+	    }
+	}
     }
 }
 
@@ -154,7 +180,7 @@ print_state (state_t *state)
   new_node (&node);
   sprintf (name, "%d", state->number);
   node.title = name;
-  print_core (state, &node_obstack);
+  print_core (&node_obstack, state);
   obstack_1grow (&node_obstack, '\0');
   node.label = obstack_finish (&node_obstack);
 
