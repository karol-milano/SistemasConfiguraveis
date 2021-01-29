@@ -78,9 +78,9 @@ print_core (state_t *state, struct obstack *node_obstack)
       if (i)
 	obstack_1grow (node_obstack, '\n');
       obstack_fgrow1 (node_obstack, " %s -> ",
-		      escape (symbols[rule_table[rule].lhs]->tag));
+		      escape (symbols[rules[rule].lhs]->tag));
 
-      for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
+      for (sp = ritem + rules[rule].rhs; sp < sp1; sp++)
 	obstack_fgrow1 (node_obstack, "%s ", escape (symbols[*sp]->tag));
 
       obstack_1grow (node_obstack, '.');
