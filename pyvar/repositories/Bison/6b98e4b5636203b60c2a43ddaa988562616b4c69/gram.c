@@ -26,7 +26,7 @@
 #include "reduce.h"
 #include "reader.h"
 
-/* comments for these variables are in gram.h  */
+/* Comments for these variables are in gram.h.  */
 
 item_number_t *ritem = NULL;
 unsigned int nritems = 0;
@@ -61,6 +61,39 @@ rule_rhs_length (rule_t *rule)
 }
 
 
+/*-------------------------------.
+| Print this RULE's RHS on OUT.  |
+`-------------------------------*/
+
+void
+rule_rhs_print (rule_t *rule, FILE *out)
+{
+  if (*rule->rhs >= 0)
+    {
+      item_number_t *r;
+      for (r = rule->rhs; *r >= 0; r++)
+	fprintf (out, " %s", symbol_tag_get (symbols[*r]));
+      fputc ('\n', out);
+    }
+  else
+    {
+      fprintf (out, " /* %s */\n", _("empty"));
+    }
+}
+
+
+/*-------------------------.
+| Print this RULE on OUT.  |
+`-------------------------*/
+
+void
+rule_print (rule_t *rule, FILE *out)
+{
+  fprintf (out, "%s:", symbol_tag_get (rule->lhs));
+  rule_rhs_print (rule, out);
+}
+
+
 /*------------------------.
 | Dump RITEM for traces.  |
 `------------------------*/
@@ -72,8 +105,7 @@ ritem_print (FILE *out)
   fputs ("RITEM\n", out);
   for (i = 0; i < nritems; ++i)
     if (ritem[i] >= 0)
-      fprintf (out, "  %s", quotearg_style (escape_quoting_style,
-					    symbols[ritem[i]]->tag));
+      fprintf (out, "  %s", symbol_tag_get (symbols[ritem[i]]));
     else
       fprintf (out, "  (rule %d)\n", -ritem[i] - 1);
   fputs ("\n\n", out);
@@ -101,6 +133,46 @@ ritem_longest_rhs (void)
 }
 
 
+/*-----------------------------------.
+| Print the grammar's rules on OUT.  |
+`-----------------------------------*/
+
+static inline void
+blanks_print (unsigned n, FILE *out)
+{
+  for (/* Nothing*/; n > 0; --n)
+    fputc (' ', out);
+}
+
+void
+grammar_rules_print (FILE *out)
+{
+  int r;
+  symbol_t *last_lhs = NULL;
+
+  /* rule # : LHS -> RHS */
+  fprintf (out, "%s\n\n", _("Grammar"));
+  for (r = 1; r < nrules + 1; r++)
+    {
+      if (last_lhs && last_lhs != rules[r].lhs)
+	fputc ('\n', out);
+
+      fprintf (out, "  %3d ", r - 1);
+      if (last_lhs != rules[r].lhs)
+	{
+	  last_lhs = rules[r].lhs;
+	  fprintf (out, "%s:", symbol_tag_get (last_lhs));
+	}
+      else
+	{
+	  blanks_print (strlen (symbol_tag_get (last_lhs)), out);
+	  fputc ('|', out);
+	}
+      rule_rhs_print (&rules[r], out);
+    }
+  fputs ("\n\n", out);
+}
+
 /*-------------------.
 | Dump the grammar.  |
 `-------------------*/
@@ -121,7 +193,7 @@ grammar_dump (FILE *out, const char *title)
     fprintf (out, "%5d  %5d   %5d  %s\n",
 	     i,
 	     symbols[i]->prec, symbols[i]->assoc,
-	     quotearg_style (escape_quoting_style, symbols[i]->tag));
+	     symbol_tag_get (symbols[i]));
   fprintf (out, "\n\n");
   fprintf (out, "Rules\n-----\n\n");
   fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
@@ -148,12 +220,8 @@ grammar_dump (FILE *out, const char *title)
   fprintf (out, "Rules interpreted\n-----------------\n\n");
   for (i = 1; i < nrules + nuseless_productions + 1; i++)
     {
-      fprintf (out, "%-5d  %s :",
-	       i, quotearg_style (escape_quoting_style, rules[i].lhs->tag));
-      for (r = rules[i].rhs; *r >= 0; r++)
-	fprintf (out, " %s",
-		 quotearg_style (escape_quoting_style, symbols[*r]->tag));
-      fputc ('\n', out);
+      fprintf (out, "%-5d  ", i);
+      rule_print (&rules[i], out);
     }
   fprintf (out, "\n\n");
 }
