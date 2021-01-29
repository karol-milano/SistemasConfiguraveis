@@ -59,12 +59,12 @@ rule_lhs_print (rule_t *rule, symbol_t *previous_lhs, FILE *out)
   fprintf (out, "  %3d ", rule->number - 1);
   if (previous_lhs != rule->lhs)
     {
-      fprintf (out, "%s:", symbol_tag_get (rule->lhs));
+      fprintf (out, "%s:", rule->lhs->tag);
     }
   else
     {
       int n;
-      for (n = strlen (symbol_tag_get (previous_lhs)); n > 0; --n)
+      for (n = strlen (previous_lhs->tag); n > 0; --n)
 	fputc (' ', out);
       fputc ('|', out);
     }
@@ -97,7 +97,7 @@ rule_rhs_print (rule_t *rule, FILE *out)
     {
       item_number_t *r;
       for (r = rule->rhs; *r >= 0; r++)
-	fprintf (out, " %s", symbol_tag_get (symbols[*r]));
+	fprintf (out, " %s", symbols[*r]->tag);
       fputc ('\n', out);
     }
   else
@@ -114,7 +114,7 @@ rule_rhs_print (rule_t *rule, FILE *out)
 void
 rule_print (rule_t *rule, FILE *out)
 {
-  fprintf (out, "%s:", symbol_tag_get (rule->lhs));
+  fprintf (out, "%s:", rule->lhs->tag);
   rule_rhs_print (rule, out);
 }
 
@@ -130,7 +130,7 @@ ritem_print (FILE *out)
   fputs ("RITEM\n", out);
   for (i = 0; i < nritems; ++i)
     if (ritem[i] >= 0)
-      fprintf (out, "  %s", symbol_tag_get (symbols[ritem[i]]));
+      fprintf (out, "  %s", symbols[ritem[i]]->tag);
     else
       fprintf (out, "  (rule %d)\n", -ritem[i] - 1);
   fputs ("\n\n", out);
@@ -217,7 +217,7 @@ grammar_dump (FILE *out, const char *title)
       fprintf (out, "%5d  %5d   %5d  %s\n",
 	       i,
 	       symbols[i]->prec, symbols[i]->assoc,
-	       symbol_tag_get (symbols[i]));
+	       symbols[i]->tag);
     fprintf (out, "\n\n");
   }
 
