@@ -40,11 +40,32 @@
 | Construct the node labels.  |
 `----------------------------*/
 
+/* Print the lhs of a rule in such a manner that there is no vertical
+   repetition, like in *.output files. */
+
+static void
+print_lhs (struct obstack *oout, rule *previous_rule, rule *r)
+{
+  if (previous_rule && STREQ (previous_rule->lhs->tag, r->lhs->tag))
+    {
+      int i;
+      for (i = 0; i < strlen (r->lhs->tag); ++i)
+        obstack_1grow (oout, ' ');
+      obstack_1grow (oout, '|');
+    }
+  else
+    {
+      obstack_sgrow (oout, escape (r->lhs->tag));
+      obstack_1grow (oout, ':');
+    }
+}
+
 static void
 print_core (struct obstack *oout, state *s)
 {
-  size_t i;
   item_number *sitems = s->items;
+  rule *previous_rule = NULL;
+  size_t i;
   size_t snritems = s->nitems;
 
   /* Output all the items of a state, not only its kernel.  */
@@ -70,7 +91,9 @@ print_core (struct obstack *oout, state *s)
 
       r = item_number_as_rule_number (*sp);
 
-      obstack_printf (oout, "%d: %s ->", r, escape (rules[r].lhs->tag));
+      obstack_printf (oout, "%3d ", r);
+      print_lhs (oout, previous_rule, &rules[r]);
+      previous_rule = &rules[r];
 
       for (sp = rules[r].rhs; sp < sp1; sp++)
         obstack_printf (oout, " %s", escape (symbols[*sp]->tag));
