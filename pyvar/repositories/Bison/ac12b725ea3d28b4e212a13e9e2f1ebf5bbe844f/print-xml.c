@@ -77,14 +77,8 @@ print_core (FILE *out, int level, state *s)
     {
       bool printed = false;
       item_number *sp1 = ritem + sitems[i];
-      item_number *sp = sp1;
-      rule *r;
-
-      while (0 <= *sp)
-        sp++;
-
-      r = &rules[item_number_as_rule_number (*sp)];
-      sp = r->rhs;
+      rule const *r = item_rule (sp1);
+      item_number *sp = r->rhs;
 
       /* Display the lookahead tokens?  */
       if (item_number_is_rule_number (*sp1))
