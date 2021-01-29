@@ -86,7 +86,7 @@ size_t
 rule_rhs_length (rule const *r)
 {
   size_t res = 0;
-  for (item_number *rhsp = r->rhs; *rhsp >= 0; ++rhsp)
+  for (item_number *rhsp = r->rhs; 0 <= *rhsp; ++rhsp)
     ++res;
   return res;
 }
@@ -95,8 +95,8 @@ void
 rule_rhs_print (rule const *r, FILE *out)
 {
   if (0 <= *r->rhs)
-    for (item_number *rp = r->rhs; *rp >= 0; rp++)
-      fprintf (out, " %s", symbols[*rp]->tag);
+    for (item_number *rhsp = r->rhs; 0 <= *rhsp; ++rhsp)
+      fprintf (out, " %s", symbols[*rhsp]->tag);
   else
     fputs (" %empty", out);
 }
@@ -107,9 +107,9 @@ rule_rhs_print_xml (rule const *r, FILE *out, int level)
   if (*r->rhs >= 0)
     {
       xml_puts (out, level, "<rhs>");
-      for (item_number *rp = r->rhs; *rp >= 0; rp++)
+      for (item_number *rhsp = r->rhs; 0 <= *rhsp; ++rhsp)
         xml_printf (out, level + 1, "<symbol>%s</symbol>",
-                    xml_escape (symbols[*rp]->tag));
+                    xml_escape (symbols[*rhsp]->tag));
       xml_puts (out, level, "</rhs>");
     }
   else
@@ -138,7 +138,7 @@ ritem_longest_rhs (void)
   int max = 0;
   for (rule_number r = 0; r < nrules; ++r)
     {
-      int length = rule_rhs_length (&rules[r]);
+      size_t length = rule_rhs_length (&rules[r]);
       if (length > max)
         max = length;
     }
@@ -165,7 +165,7 @@ grammar_rules_partial_print (FILE *out, const char *title,
       first = false;
       rule_lhs_print (&rules[r], previous_lhs, out);
       rule_rhs_print (&rules[r], out);
-      fprintf (out, "\n");
+      fputc ('\n', out);
       previous_lhs = rules[r].lhs;
     }
   if (!first)
@@ -244,33 +244,30 @@ grammar_dump (FILE *out, const char *title)
       {
         rule const *rule_i = &rules[i];
         unsigned const rhs_itemno = rule_i->rhs - ritem;
-        /* Find the last RHS index in ritems. */
-        unsigned rhs_count = 0;
-        for (item_number *rp = rule_i->rhs; *rp >= 0; ++rp)
-          ++rhs_count;
+        unsigned length = rule_rhs_length (rule_i);
         fprintf (out, "%3d (%2d, %2d, %2d, %2u-%2u)   %2d ->",
                  i,
                  rule_i->prec ? rule_i->prec->prec : 0,
                  rule_i->prec ? rule_i->prec->assoc : 0,
                  rule_i->useful,
                  rhs_itemno,
-                 rhs_itemno + rhs_count - 1,
+                 rhs_itemno + length - 1,
                  rule_i->lhs->number);
         /* Dumped the RHS. */
-        for (item_number *rp = rule_i->rhs; *rp >= 0; ++rp)
-          fprintf (out, " %3d", *rp);
+        for (item_number *rhsp = rule_i->rhs; 0 <= *rhsp; ++rhsp)
+          fprintf (out, " %3d", *rhsp);
         fprintf (out, "  [%d]\n",
-                 item_number_as_rule_number (rule_i->rhs[rhs_count+1]));
+                 item_number_as_rule_number (rule_i->rhs[length+1]));
       }
   }
   fprintf (out, "\n\n");
 
   fprintf (out, "Rules interpreted\n-----------------\n\n");
-  for (rule_number r = 0; r < nrules + nuseless_productions; r++)
+  for (rule_number r = 0; r < nrules + nuseless_productions; ++r)
     {
       fprintf (out, "%-5d  %s:", r, rules[r].lhs->symbol->tag);
       rule_rhs_print (&rules[r], out);
-      fprintf (out, "\n");
+      fputc ('\n', out);
     }
   fprintf (out, "\n\n");
 }
@@ -278,7 +275,7 @@ grammar_dump (FILE *out, const char *title)
 void
 grammar_rules_useless_report (const char *message)
 {
-  for (rule_number r = 0; r < nrules ; ++r)
+  for (rule_number r = 0; r < nrules; ++r)
     /* Don't complain about rules whose LHS is useless, we already
        complained about it.  */
     if (!reduce_nonterminal_useless_in_grammar (rules[r].lhs)
