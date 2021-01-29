@@ -63,14 +63,14 @@ print_core (struct obstack *oout, state_t *state)
     {
       item_number_t *sp;
       item_number_t *sp1;
-      int rule;
+      rule_number_t rule;
 
       sp1 = sp = ritem + sitems[i];
 
       while (*sp >= 0)
 	sp++;
 
-      rule = -(*sp);
+      rule = rule_number_of_item_number (*sp);
 
       if (i)
 	obstack_1grow (oout, '\n');
