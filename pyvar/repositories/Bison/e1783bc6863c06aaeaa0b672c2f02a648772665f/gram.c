@@ -48,6 +48,35 @@ int max_user_token_number = 256;
 
 int required_version = 0;
 
+rule const *
+item_rule (item_number const *item)
+{
+  item_number const *sp = item;
+  while (*sp >= 0)
+    ++sp;
+
+  rule_number r = item_number_as_rule_number (*sp);
+  return &rules[r];
+}
+
+
+void
+item_print (item_number *item, rule const *previous_rule, FILE *out)
+{
+  rule const *r = item_rule (item);
+  rule_lhs_print (r, previous_rule ? previous_rule->lhs : NULL, out);
+
+  for (item_number *sp = r->rhs; sp < item; sp++)
+    fprintf (out, " %s", symbols[*sp]->tag);
+  fputs (" .", out);
+  if (0 <= *r->rhs)
+    for (item_number *sp = item; 0 <= *sp; ++sp)
+      fprintf (out, " %s", symbols[*sp]->tag);
+  else
+    fprintf (out, " %%empty");
+}
+
+
 bool
 rule_useful_in_grammar_p (rule const *r)
 {
