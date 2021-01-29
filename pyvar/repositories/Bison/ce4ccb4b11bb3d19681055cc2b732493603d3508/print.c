@@ -58,6 +58,7 @@ print_core (FILE *out, state_t *state)
   int i;
   item_number_t *sitems = state->items;
   int snritems   = state->nitems;
+  symbol_t *previous_lhs = NULL;
 
   /* Output all the items of a state, not only its kernel.  */
   if (report_flag & report_itemsets)
@@ -67,40 +68,39 @@ print_core (FILE *out, state_t *state)
       snritems = nritemset;
     }
 
-  if (snritems)
-    {
-      for (i = 0; i < snritems; i++)
-	{
-	  item_number_t *sp;
-	  item_number_t *sp1;
-	  int rule;
-
-	  sp1 = sp = ritem + sitems[i];
+  if (!snritems)
+    return;
 
-	  while (*sp >= 0)
-	    sp++;
+  for (i = 0; i < snritems; i++)
+    {
+      item_number_t *sp;
+      item_number_t *sp1;
+      int rule;
 
-	  rule = -(*sp);
-	  fprintf (out, "    %s  ->  ", symbol_tag_get (rules[rule].lhs));
+      sp1 = sp = ritem + sitems[i];
 
-	  for (sp = rules[rule].rhs; sp < sp1; sp++)
-	    fprintf (out, "%s ", symbol_tag_get (symbols[*sp]));
+      while (*sp >= 0)
+	sp++;
 
-	  fputc ('.', out);
+      rule = -(*sp);
 
-	  for (/* Nothing */; *sp >= 0; ++sp)
-	    fprintf (out, " %s", symbol_tag_get (symbols[*sp]));
+      rule_lhs_print (&rules[rule], previous_lhs, out);
+      previous_lhs = rules[rule].lhs;
 
-	  /* Display the lookaheads?  */
-	  if (report_flag & report_lookaheads)
-	    state_rule_lookaheads_print (state, &rules[rule], out);
+      for (sp = rules[rule].rhs; sp < sp1; sp++)
+	fprintf (out, " %s", symbol_tag_get (symbols[*sp]));
+      fputs (" .", out);
+      for (/* Nothing */; *sp >= 0; ++sp)
+	fprintf (out, " %s", symbol_tag_get (symbols[*sp]));
 
-	  fprintf (out, _("   (rule %d)"), rule - 1);
-	  fputc ('\n', out);
-	}
+      /* Display the lookaheads?  */
+      if (report_flag & report_lookaheads)
+	state_rule_lookaheads_print (state, &rules[rule], out);
 
       fputc ('\n', out);
     }
+
+  fputc ('\n', out);
 }
 
 
