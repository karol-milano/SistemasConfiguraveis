@@ -42,33 +42,15 @@
 /* Print the lhs of a rule in such a manner that there is no vertical
    repetition, like in *.output files. */
 
-static void
-print_lhs (struct obstack *oout, rule *previous_rule, rule *r)
-{
-  if (previous_rule && STREQ (previous_rule->lhs->tag, r->lhs->tag))
-    {
-      int i;
-      for (i = 0; i < strlen (r->lhs->tag); ++i)
-        obstack_1grow (oout, ' ');
-      obstack_1grow (oout, '|');
-    }
-  else
-    {
-      obstack_sgrow (oout, escape (r->lhs->tag));
-      obstack_1grow (oout, ':');
-    }
-  obstack_1grow (oout, ' ');
-}
-
 static void
 print_core (struct obstack *oout, state *s)
 {
-  item_number *sitems = s->items;
-  rule *previous_rule = NULL;
+  item_number const *sitems = s->items;
+  symbol *previous_lhs = NULL;
   size_t i;
   size_t snritems = s->nitems;
 
-  /* Output all the items of a state, not only its kernel.  */
+  /* Output all the items of a state, not just its kernel.  */
   if (report_flag & report_itemsets)
     {
       closure (sitems, snritems);
@@ -80,22 +62,24 @@ print_core (struct obstack *oout, state *s)
   obstack_sgrow (oout, "\\n\\l");
   for (i = 0; i < snritems; i++)
     {
-      item_number *sp;
-      item_number *sp1;
-      rule_number r;
-
-      sp1 = sp = ritem + sitems[i];
+      item_number const *sp1 = ritem + sitems[i];
+      item_number const *sp = sp1;
+      rule *r;
 
-      while (*sp >= 0)
+      while (0 <= *sp)
         sp++;
 
-      r = item_number_as_rule_number (*sp);
+      r = &rules[item_number_as_rule_number (*sp)];
 
-      obstack_printf (oout, "%3d ", r);
-      print_lhs (oout, previous_rule, &rules[r]);
-      previous_rule = &rules[r];
+      obstack_printf (oout, "%3d ", r->number);
+      if (previous_lhs && UNIQSTR_EQ (previous_lhs->tag, r->lhs->tag))
+        obstack_printf (oout, "%*s| ",
+                        (int) strlen (previous_lhs->tag), "");
+      else
+        obstack_printf (oout, "%s: ", escape (r->lhs->tag));
+      previous_lhs = r->lhs;
 
-      for (sp = rules[r].rhs; sp < sp1; sp++)
+      for (sp = r->rhs; sp < sp1; sp++)
         obstack_printf (oout, "%s ", escape (symbols[*sp]->tag));
 
       obstack_1grow (oout, '.');
@@ -109,7 +93,7 @@ print_core (struct obstack *oout, state *s)
         {
           /* Find the reduction we are handling.  */
           reductions *reds = s->reductions;
-          int redno = state_reduction_find (s, &rules[r]);
+          int redno = state_reduction_find (s, r);
 
           /* Print them if there are.  */
           if (reds->lookahead_tokens && redno != -1)
