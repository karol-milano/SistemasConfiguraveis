@@ -75,15 +75,15 @@ print_core (struct obstack *oout, state_t *state)
       if (i)
 	obstack_1grow (oout, '\n');
       obstack_fgrow1 (oout, " %s -> ",
-		      symbol_tag_get (rules[rule].lhs));
+		      rules[rule].lhs->tag);
 
       for (sp = rules[rule].rhs; sp < sp1; sp++)
-	obstack_fgrow1 (oout, "%s ", symbol_tag_get (symbols[*sp]));
+	obstack_fgrow1 (oout, "%s ", symbols[*sp]->tag);
 
       obstack_1grow (oout, '.');
 
       for (/* Nothing */; *sp >= 0; ++sp)
-	obstack_fgrow1 (oout, " %s", symbol_tag_get (symbols[*sp]));
+	obstack_fgrow1 (oout, " %s", symbols[*sp]->tag);
 
       /* Experimental feature: display the lookaheads. */
       if ((report_flag & report_lookaheads)
@@ -107,7 +107,7 @@ print_core (struct obstack *oout, state_t *state)
 		{
 		  if (state->lookaheads_rule[j]->number == rule)
 		    obstack_fgrow2 (oout, "%s%s",
-				    symbol_tag_get (symbols[k]),
+				    symbols[k]->tag,
 				    --nlookaheads ? ", " : "");
 		});
 	      obstack_sgrow (oout, "]");
@@ -156,7 +156,7 @@ print_actions (state_t *state, const char *node_name)
 	  edge.color = red;
 	else
 	  edge.color = TRANSITION_IS_SHIFT(transitions, i) ? blue : green;
-	edge.label = symbol_tag_get (symbols[symbol]);
+	edge.label = symbols[symbol]->tag;
 	output_edge (&edge, fgraph);
 	close_edge (fgraph);
       }
