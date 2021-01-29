@@ -65,19 +65,19 @@ rule_useless_in_parser_p (rule const *r)
 }
 
 void
-rule_lhs_print (rule const *r, symbol const *previous_lhs, FILE *out)
+rule_lhs_print (rule const *r, sym_content const *previous_lhs, FILE *out)
 {
   fprintf (out, "  %3d ", r->number);
   if (previous_lhs != r->lhs)
-    fprintf (out, "%s:", r->lhs->tag);
+    fprintf (out, "%s:", r->lhs->symbol->tag);
   else
-    fprintf (out, "%*s|", (int) strlen (previous_lhs->tag), "");
+    fprintf (out, "%*s|", (int) strlen (previous_lhs->symbol->tag), "");
 }
 
 void
 rule_lhs_print_xml (rule const *r, FILE *out, int level)
 {
-  xml_printf (out, level, "<lhs>%s</lhs>", r->lhs->tag);
+  xml_printf (out, level, "<lhs>%s</lhs>", r->lhs->symbol->tag);
 }
 
 size_t
@@ -158,7 +158,7 @@ grammar_rules_partial_print (FILE *out, const char *title,
 {
   rule_number r;
   bool first = true;
-  symbol *previous_lhs = NULL;
+  sym_content *previous_lhs = NULL;
 
   /* rule # : LHS -> RHS */
   for (r = 0; r < nrules + nuseless_productions; r++)
@@ -209,7 +209,7 @@ grammar_rules_print_xml (FILE *out, int level)
                  rules[r].number, usefulness);
         if (rules[r].precsym)
           fprintf (out, " percent_prec=\"%s\"",
-                   xml_escape (rules[r].precsym->tag));
+                   xml_escape (rules[r].precsym->symbol->tag));
         fputs (">\n", out);
       }
       rule_lhs_print_xml (&rules[r], out, level + 3);
@@ -239,7 +239,7 @@ grammar_dump (FILE *out, const char *title)
     for (i = ntokens; i < nsyms; i++)
       fprintf (out, "%5d  %5d   %5d  %s\n",
                i,
-               symbols[i]->prec, symbols[i]->assoc,
+               symbols[i]->content->prec, symbols[i]->content->assoc,
                symbols[i]->tag);
     fprintf (out, "\n\n");
   }
@@ -280,7 +280,7 @@ grammar_dump (FILE *out, const char *title)
     rule_number r;
     for (r = 0; r < nrules + nuseless_productions; r++)
       {
-        fprintf (out, "%-5d  %s:", r, rules[r].lhs->tag);
+        fprintf (out, "%-5d  %s:", r, rules[r].lhs->symbol->tag);
         rule_rhs_print (&rules[r], out);
         fprintf (out, "\n");
       }
