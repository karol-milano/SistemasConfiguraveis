@@ -70,7 +70,7 @@ print_core (struct obstack *oout, state_t *state)
       while (*sp >= 0)
 	sp++;
 
-      rule = rule_number_of_item_number (*sp);
+      rule = item_number_as_rule_number (*sp);
 
       if (i)
 	obstack_1grow (oout, '\n');
