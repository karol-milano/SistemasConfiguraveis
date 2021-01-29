@@ -76,9 +76,10 @@ print_core (int state, struct obstack *node_obstack)
       rule = -(*sp);
 
       obstack_fgrow1 (node_obstack, "%d: ", rule);
-      obstack_fgrow1 (node_obstack, " %s  ->  ", quote (tags[rlhs[rule]]));
+      obstack_fgrow1 (node_obstack, " %s  ->  ",
+		      quote (tags[rule_table[rule].lhs]));
 
-      for (sp = ritem + rrhs[rule]; sp < sp1; sp++)
+      for (sp = ritem + rule_table[rule].rhs; sp < sp1; sp++)
 	obstack_fgrow1 (node_obstack, "%s ", quote (tags[*sp]));
 
       obstack_1grow (node_obstack, '.');
@@ -181,7 +182,7 @@ print_actions (int state, const char *node_name, struct obstack *node_obstack)
   if (state_table[state].consistent && redp)
     {
       rule = redp->rules[0];
-      symbol = rlhs[rule];
+      symbol = rule_table[rule].lhs;
       if (obstack_object_size (node_obstack) > node_output_size)
 	obstack_sgrow (node_obstack, "\\n");
       obstack_fgrow2 (node_obstack, _("$default\treduce using rule %d (%s)"),
