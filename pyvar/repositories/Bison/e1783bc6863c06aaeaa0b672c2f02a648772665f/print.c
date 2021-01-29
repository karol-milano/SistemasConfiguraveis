@@ -63,8 +63,6 @@ print_core (FILE *out, state *s)
 {
   item_number *sitems = s->items;
   size_t snritems = s->nitems;
-  sym_content *previous_lhs = NULL;
-
   /* Output all the items of a state, not only its kernel.  */
   if (report_flag & report_itemsets)
     {
@@ -78,33 +76,18 @@ print_core (FILE *out, state *s)
 
   fputc ('\n', out);
 
+  rule const *previous_rule = NULL;
   for (size_t i = 0; i < snritems; i++)
     {
       item_number *sp1 = ritem + sitems[i];
-
-      item_number *sp = sp1;
-      while (*sp >= 0)
-        sp++;
-
-      rule_number r = item_number_as_rule_number (*sp);
-
-      rule_lhs_print (&rules[r], previous_lhs, out);
-      previous_lhs = rules[r].lhs;
-
-      for (sp = rules[r].rhs; sp < sp1; sp++)
-        fprintf (out, " %s", symbols[*sp]->tag);
-      fputs (" .", out);
-      if (0 <= *rules[r].rhs)
-        for (/* Nothing */; 0 <= *sp; ++sp)
-          fprintf (out, " %s", symbols[*sp]->tag);
-      else
-        fprintf (out, " %%empty");
+      rule const *r = item_rule (sp1);
+      item_print (sp1, previous_rule, out);
+      previous_rule = r;
 
       /* Display the lookahead tokens?  */
       if (report_flag & report_lookahead_tokens
           && item_number_is_rule_number (*sp1))
-        state_rule_lookahead_tokens_print (s, &rules[r], out);
-
+        state_rule_lookahead_tokens_print (s, r, out);
       fputc ('\n', out);
     }
 }
