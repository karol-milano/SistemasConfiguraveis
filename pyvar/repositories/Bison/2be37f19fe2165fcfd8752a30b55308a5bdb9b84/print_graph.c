@@ -68,7 +68,7 @@ print_core (struct obstack *oout, state *s)
 
       r = item_number_as_rule_number (*sp);
 
-      obstack_printf (oout, "\n%s -> ", rules[r].lhs->tag);
+      obstack_printf (oout, "\n%d: %s -> ", r, rules[r].lhs->tag);
 
       for (sp = rules[r].rhs; sp < sp1; sp++)
 	obstack_printf (oout, "%s ", symbols[*sp]->tag);
