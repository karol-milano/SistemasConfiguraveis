@@ -38,14 +38,11 @@
 static graph_t graph;
 static FILE *fgraph = NULL;
 
-static inline const char *
-escape (const char *s)
-{
-  return quotearg_n_style (1, escape_quoting_style, s);
-}
 
+/*----------------------------.
+| Construct the node labels.  |
+`----------------------------*/
 
-/* This part will construct the label of nodes. */
 static void
 print_core (struct obstack *oout, state_t *state)
 {
@@ -78,15 +75,15 @@ print_core (struct obstack *oout, state_t *state)
       if (i)
 	obstack_1grow (oout, '\n');
       obstack_fgrow1 (oout, " %s -> ",
-		      escape (rules[rule].lhs->tag));
+		      symbol_tag_get (rules[rule].lhs));
 
       for (sp = rules[rule].rhs; sp < sp1; sp++)
-	obstack_fgrow1 (oout, "%s ", escape (symbols[*sp]->tag));
+	obstack_fgrow1 (oout, "%s ", symbol_tag_get (symbols[*sp]));
 
       obstack_1grow (oout, '.');
 
       for (/* Nothing */; *sp >= 0; ++sp)
-	obstack_fgrow1 (oout, " %s", escape (symbols[*sp]->tag));
+	obstack_fgrow1 (oout, " %s", symbol_tag_get (symbols[*sp]));
 
       /* Experimental feature: display the lookaheads. */
       if (trace_flag && state->nlookaheads)
@@ -107,8 +104,7 @@ print_core (struct obstack *oout, state_t *state)
 		  if (bitset_test (LA[state->lookaheadsp + j], k)
 		      && LArule[state->lookaheadsp + j]->number == rule)
 		    obstack_fgrow2 (oout, "%s%s",
-				    quotearg_style (escape_quoting_style,
-						    symbols[k]->tag),
+				    symbol_tag_get (symbols[k]),
 				    --nlookaheads ? ", " : "");
 	      obstack_sgrow (oout, "]");
 	    }
@@ -156,7 +152,7 @@ print_actions (state_t *state, const char *node_name)
 	  edge.color = red;
 	else
 	  edge.color = SHIFT_IS_SHIFT(shiftp, i) ? blue : green;
-	edge.label = escape (symbols[symbol]->tag);
+	edge.label = symbol_tag_get (symbols[symbol]);
 	output_edge (&edge, fgraph);
 	close_edge (fgraph);
       }
