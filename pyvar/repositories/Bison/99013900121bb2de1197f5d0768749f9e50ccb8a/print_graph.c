@@ -80,7 +80,7 @@ print_core (state_t *state, struct obstack *node_obstack)
       obstack_fgrow1 (node_obstack, " %s -> ",
 		      escape (symbols[rules[rule].lhs]->tag));
 
-      for (sp = ritem + rules[rule].rhs; sp < sp1; sp++)
+      for (sp = rules[rule].rhs; sp < sp1; sp++)
 	obstack_fgrow1 (node_obstack, "%s ", escape (symbols[*sp]->tag));
 
       obstack_1grow (node_obstack, '.');
