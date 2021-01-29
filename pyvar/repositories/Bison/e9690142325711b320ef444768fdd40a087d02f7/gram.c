@@ -78,7 +78,7 @@ rule_lhs_print (rule *r, symbol *previous_lhs, FILE *out)
     {
       int n;
       for (n = strlen (previous_lhs->tag); n > 0; --n)
-	fputc (' ', out);
+        fputc (' ', out);
       fputc ('|', out);
     }
 }
@@ -106,7 +106,7 @@ rule_rhs_print (rule *r, FILE *out)
     {
       item_number *rp;
       for (rp = r->rhs; *rp >= 0; rp++)
-	fprintf (out, " %s", symbols[*rp]->tag);
+        fprintf (out, " %s", symbols[*rp]->tag);
       fputc ('\n', out);
     }
   else
@@ -123,8 +123,8 @@ rule_rhs_print_xml (rule *r, FILE *out, int level)
       item_number *rp;
       xml_puts (out, level, "<rhs>");
       for (rp = r->rhs; *rp >= 0; rp++)
-	xml_printf (out, level + 1, "<symbol>%s</symbol>",
-		    xml_escape (symbols[*rp]->tag));
+        xml_printf (out, level + 1, "<symbol>%s</symbol>",
+                    xml_escape (symbols[*rp]->tag));
       xml_puts (out, level, "</rhs>");
     }
   else
@@ -165,7 +165,7 @@ ritem_longest_rhs (void)
     {
       int length = rule_rhs_length (&rules[r]);
       if (length > max)
-	max = length;
+        max = length;
     }
 
   return max;
@@ -173,7 +173,7 @@ ritem_longest_rhs (void)
 
 void
 grammar_rules_partial_print (FILE *out, const char *title,
-			     rule_filter filter)
+                             rule_filter filter)
 {
   rule_number r;
   bool first = true;
@@ -183,11 +183,11 @@ grammar_rules_partial_print (FILE *out, const char *title,
   for (r = 0; r < nrules + nuseless_productions; r++)
     {
       if (filter && !filter (&rules[r]))
-	continue;
+        continue;
       if (first)
-	fprintf (out, "%s\n\n", title);
+        fprintf (out, "%s\n\n", title);
       else if (previous_lhs && previous_lhs != rules[r].lhs)
-	fputc ('\n', out);
+        fputc ('\n', out);
       first = false;
       rule_lhs_print (&rules[r], previous_lhs, out);
       rule_rhs_print (&rules[r], out);
@@ -212,7 +212,7 @@ grammar_rules_print_xml (FILE *out, int level)
   for (r = 0; r < nrules + nuseless_productions; r++)
     {
       if (first)
-	xml_puts (out, level + 1, "<rules>");
+        xml_puts (out, level + 1, "<rules>");
       first = false;
       {
         char const *usefulness;
@@ -245,8 +245,8 @@ grammar_dump (FILE *out, const char *title)
 {
   fprintf (out, "%s\n\n", title);
   fprintf (out,
-	   "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nritems = %d\n\n",
-	   ntokens, nvars, nsyms, nrules, nritems);
+           "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nritems = %d\n\n",
+           ntokens, nvars, nsyms, nrules, nritems);
 
 
   fprintf (out, "Variables\n---------\n\n");
@@ -256,9 +256,9 @@ grammar_dump (FILE *out, const char *title)
 
     for (i = ntokens; i < nsyms; i++)
       fprintf (out, "%5d  %5d   %5d  %s\n",
-	       i,
-	       symbols[i]->prec, symbols[i]->assoc,
-	       symbols[i]->tag);
+               i,
+               symbols[i]->prec, symbols[i]->assoc,
+               symbols[i]->tag);
     fprintf (out, "\n\n");
   }
 
@@ -268,25 +268,25 @@ grammar_dump (FILE *out, const char *title)
     fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
     for (i = 0; i < nrules + nuseless_productions; i++)
       {
-	rule *rule_i = &rules[i];
-	item_number *rp = NULL;
-	unsigned int rhs_itemno = rule_i->rhs - ritem;
-	unsigned int rhs_count = 0;
-	/* Find the last RHS index in ritems. */
-	for (rp = rule_i->rhs; *rp >= 0; ++rp)
-	  ++rhs_count;
-	fprintf (out, "%3d (%2d, %2d, %2d, %2u-%2u)   %2d ->",
-		 i,
-		 rule_i->prec ? rule_i->prec->prec : 0,
-		 rule_i->prec ? rule_i->prec->assoc : 0,
-		 rule_i->useful,
-		 rhs_itemno,
-		 rhs_itemno + rhs_count - 1,
-		 rule_i->lhs->number);
-	/* Dumped the RHS. */
-	for (rp = rule_i->rhs; *rp >= 0; rp++)
-	  fprintf (out, " %3d", *rp);
-	fprintf (out, "  [%d]\n", item_number_as_rule_number (*rp));
+        rule *rule_i = &rules[i];
+        item_number *rp = NULL;
+        unsigned int rhs_itemno = rule_i->rhs - ritem;
+        unsigned int rhs_count = 0;
+        /* Find the last RHS index in ritems. */
+        for (rp = rule_i->rhs; *rp >= 0; ++rp)
+          ++rhs_count;
+        fprintf (out, "%3d (%2d, %2d, %2d, %2u-%2u)   %2d ->",
+                 i,
+                 rule_i->prec ? rule_i->prec->prec : 0,
+                 rule_i->prec ? rule_i->prec->assoc : 0,
+                 rule_i->useful,
+                 rhs_itemno,
+                 rhs_itemno + rhs_count - 1,
+                 rule_i->lhs->number);
+        /* Dumped the RHS. */
+        for (rp = rule_i->rhs; *rp >= 0; rp++)
+          fprintf (out, " %3d", *rp);
+        fprintf (out, "  [%d]\n", item_number_as_rule_number (*rp));
       }
   }
   fprintf (out, "\n\n");
@@ -296,8 +296,8 @@ grammar_dump (FILE *out, const char *title)
     rule_number r;
     for (r = 0; r < nrules + nuseless_productions; r++)
       {
-	fprintf (out, "%-5d  ", r);
-	rule_print (&rules[r], out);
+        fprintf (out, "%-5d  ", r);
+        rule_print (&rules[r], out);
       }
   }
   fprintf (out, "\n\n");
