@@ -78,7 +78,7 @@ print_core (state_t *state, struct obstack *node_obstack)
       if (i)
 	obstack_1grow (node_obstack, '\n');
       obstack_fgrow1 (node_obstack, " %s -> ",
-		      escape (symbols[rules[rule].lhs]->tag));
+		      escape (rules[rule].lhs->tag));
 
       for (sp = rules[rule].rhs; sp < sp1; sp++)
 	obstack_fgrow1 (node_obstack, "%s ", escape (symbols[*sp]->tag));
