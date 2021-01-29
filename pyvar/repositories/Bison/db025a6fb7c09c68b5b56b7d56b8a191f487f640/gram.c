@@ -84,8 +84,7 @@ size_t
 rule_rhs_length (rule const *r)
 {
   size_t res = 0;
-  item_number *rhsp;
-  for (rhsp = r->rhs; *rhsp >= 0; ++rhsp)
+  for (item_number *rhsp = r->rhs; *rhsp >= 0; ++rhsp)
     ++res;
   return res;
 }
@@ -94,11 +93,8 @@ void
 rule_rhs_print (rule const *r, FILE *out)
 {
   if (0 <= *r->rhs)
-    {
-      item_number *rp;
-      for (rp = r->rhs; *rp >= 0; rp++)
-        fprintf (out, " %s", symbols[*rp]->tag);
-    }
+    for (item_number *rp = r->rhs; *rp >= 0; rp++)
+      fprintf (out, " %s", symbols[*rp]->tag);
   else
     fputs (" %empty", out);
 }
@@ -108,9 +104,8 @@ rule_rhs_print_xml (rule const *r, FILE *out, int level)
 {
   if (*r->rhs >= 0)
     {
-      item_number *rp;
       xml_puts (out, level, "<rhs>");
-      for (rp = r->rhs; *rp >= 0; rp++)
+      for (item_number *rp = r->rhs; *rp >= 0; rp++)
         xml_printf (out, level + 1, "<symbol>%s</symbol>",
                     xml_escape (symbols[*rp]->tag));
       xml_puts (out, level, "</rhs>");
@@ -126,9 +121,8 @@ rule_rhs_print_xml (rule const *r, FILE *out, int level)
 void
 ritem_print (FILE *out)
 {
-  unsigned i;
   fputs ("RITEM\n", out);
-  for (i = 0; i < nritems; ++i)
+  for (unsigned i = 0; i < nritems; ++i)
     if (ritem[i] >= 0)
       fprintf (out, "  %s", symbols[ritem[i]]->tag);
     else
@@ -140,9 +134,7 @@ size_t
 ritem_longest_rhs (void)
 {
   int max = 0;
-  rule_number r;
-
-  for (r = 0; r < nrules; ++r)
+  for (rule_number r = 0; r < nrules; ++r)
     {
       int length = rule_rhs_length (&rules[r]);
       if (length > max)
@@ -156,12 +148,11 @@ void
 grammar_rules_partial_print (FILE *out, const char *title,
                              rule_filter filter)
 {
-  rule_number r;
   bool first = true;
   sym_content *previous_lhs = NULL;
 
   /* rule # : LHS -> RHS */
-  for (r = 0; r < nrules + nuseless_productions; r++)
+  for (rule_number r = 0; r < nrules + nuseless_productions; r++)
     {
       if (filter && !filter (&rules[r]))
         continue;
@@ -188,10 +179,9 @@ grammar_rules_print (FILE *out)
 void
 grammar_rules_print_xml (FILE *out, int level)
 {
-  rule_number r;
   bool first = true;
 
-  for (r = 0; r < nrules + nuseless_productions; r++)
+  for (rule_number r = 0; r < nrules + nuseless_productions; r++)
     {
       if (first)
         xml_puts (out, level + 1, "<rules>");
@@ -233,10 +223,9 @@ grammar_dump (FILE *out, const char *title)
 
   fprintf (out, "Variables\n---------\n\n");
   {
-    symbol_number i;
     fprintf (out, "Value  Sprec  Sassoc  Tag\n");
 
-    for (i = ntokens; i < nsyms; i++)
+    for (symbol_number i = ntokens; i < nsyms; i++)
       fprintf (out, "%5d  %5d   %5d  %s\n",
                i,
                symbols[i]->content->prec, symbols[i]->content->assoc,
@@ -246,18 +235,16 @@ grammar_dump (FILE *out, const char *title)
 
   fprintf (out, "Rules\n-----\n\n");
   {
-    rule_number i;
     fprintf (out,
              "Num (Prec, Assoc, Useful, Ritem Range) Lhs"
              " -> Rhs (Ritem range) [Num]\n");
-    for (i = 0; i < nrules + nuseless_productions; i++)
+    for (rule_number i = 0; i < nrules + nuseless_productions; i++)
       {
         rule const *rule_i = &rules[i];
-        item_number *rp = NULL;
-        unsigned rhs_itemno = rule_i->rhs - ritem;
-        unsigned rhs_count = 0;
+        unsigned const rhs_itemno = rule_i->rhs - ritem;
         /* Find the last RHS index in ritems. */
-        for (rp = rule_i->rhs; *rp >= 0; ++rp)
+        unsigned rhs_count = 0;
+        for (item_number *rp = rule_i->rhs; *rp >= 0; ++rp)
           ++rhs_count;
         fprintf (out, "%3d (%2d, %2d, %2d, %2u-%2u)   %2d ->",
                  i,
@@ -268,31 +255,28 @@ grammar_dump (FILE *out, const char *title)
                  rhs_itemno + rhs_count - 1,
                  rule_i->lhs->number);
         /* Dumped the RHS. */
-        for (rp = rule_i->rhs; *rp >= 0; rp++)
+        for (item_number *rp = rule_i->rhs; *rp >= 0; ++rp)
           fprintf (out, " %3d", *rp);
-        fprintf (out, "  [%d]\n", item_number_as_rule_number (*rp));
+        fprintf (out, "  [%d]\n",
+                 item_number_as_rule_number (rule_i->rhs[rhs_count+1]));
       }
   }
   fprintf (out, "\n\n");
 
   fprintf (out, "Rules interpreted\n-----------------\n\n");
-  {
-    rule_number r;
-    for (r = 0; r < nrules + nuseless_productions; r++)
-      {
-        fprintf (out, "%-5d  %s:", r, rules[r].lhs->symbol->tag);
-        rule_rhs_print (&rules[r], out);
-        fprintf (out, "\n");
-      }
-  }
+  for (rule_number r = 0; r < nrules + nuseless_productions; r++)
+    {
+      fprintf (out, "%-5d  %s:", r, rules[r].lhs->symbol->tag);
+      rule_rhs_print (&rules[r], out);
+      fprintf (out, "\n");
+    }
   fprintf (out, "\n\n");
 }
 
 void
 grammar_rules_useless_report (const char *message)
 {
-  rule_number r;
-  for (r = 0; r < nrules ; ++r)
+  for (rule_number r = 0; r < nrules ; ++r)
     /* Don't complain about rules whose LHS is useless, we already
        complained about it.  */
     if (!reduce_nonterminal_useless_in_grammar (rules[r].lhs)
