@@ -63,12 +63,9 @@ print_core (FILE *out, int level, state *s)
   size_t snritems = s->nitems;
 
   /* Output all the items of a state, not only its kernel.  */
-  if (report_flag & report_itemsets)
-    {
-      closure (sitems, snritems);
-      sitems = itemset;
-      snritems = nitemset;
-    }
+  closure (sitems, snritems);
+  sitems = itemset;
+  snritems = nitemset;
 
   if (!snritems) {
     xml_puts (out, level, "<itemset/>");
@@ -93,8 +90,7 @@ print_core (FILE *out, int level, state *s)
       sp = rules[r].rhs;
 
       /* Display the lookahead tokens?  */
-      if (report_flag & report_lookahead_tokens
-          && item_number_is_rule_number (*sp1))
+      if (item_number_is_rule_number (*sp1))
 	{
 	  reductions *reds = s->reductions;
 	  int red = state_reduction_find (s, &rules[r]);
@@ -365,7 +361,7 @@ print_state (FILE *out, int level, state *s)
   xml_printf (out, level, "<state number=\"%d\">", s->number);
   print_core (out, level + 1, s);
   print_actions (out, level + 1, s);
-  if ((report_flag & report_solved_conflicts) && s->solved_conflicts_xml)
+  if (s->solved_conflicts_xml)
     {
       xml_puts (out, level + 1, "<solved-conflicts>");
       fputs (s->solved_conflicts_xml, out);
@@ -563,8 +559,7 @@ print_xml (void)
   /* print grammar */
   print_grammar (out, level + 1);
 
-  if (report_flag & report_itemsets)
-    new_closure (nritems);
+  new_closure (nritems);
   no_reduce_set =  bitset_create (ntokens, BITSET_FIXED);
 
   /* print automaton */
@@ -575,8 +570,7 @@ print_xml (void)
   xml_puts (out, level + 1, "</automaton>");
 
   bitset_free (no_reduce_set);
-  if (report_flag & report_itemsets)
-    free_closure ();
+  free_closure ();
 
   xml_puts (out, 0, "</bison-xml-report>");
 
