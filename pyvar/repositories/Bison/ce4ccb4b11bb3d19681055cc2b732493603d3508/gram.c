@@ -47,6 +47,30 @@ int glr_parser = 0;
 int pure_parser = 0;
 
 
+/*----------------------------------------------------------------.
+| Print this RULE's number and lhs on OUT.  If a PREVIOUS_LHS was |
+| already displayed (by a previous call for another rule), avoid  |
+| useless repetitions.                                            |
+`----------------------------------------------------------------*/
+
+void
+rule_lhs_print (rule_t *rule, symbol_t *previous_lhs, FILE *out)
+{
+  fprintf (out, "  %3d ", rule->number - 1);
+  if (previous_lhs != rule->lhs)
+    {
+      fprintf (out, "%s:", symbol_tag_get (rule->lhs));
+    }
+  else
+    {
+      int n;
+      for (n = strlen (symbol_tag_get (previous_lhs)); n > 0; --n)
+	fputc (' ', out);
+      fputc ('|', out);
+    }
+}
+
+
 /*--------------------------------------.
 | Return the number of symbols in RHS.  |
 `--------------------------------------*/
@@ -139,39 +163,22 @@ ritem_longest_rhs (void)
 | (exclusive) on OUT under TITLE.                                 |
 `----------------------------------------------------------------*/
 
-static inline void
-blanks_print (unsigned n, FILE *out)
-{
-  for (/* Nothing*/; n > 0; --n)
-    fputc (' ', out);
-}
-
 void
 grammar_rules_partial_print (FILE *out, const char *title,
 			     rule_number_t begin, rule_number_t end)
 {
   int r;
-  symbol_t *last_lhs = NULL;
+  symbol_t *previous_lhs = NULL;
 
   /* rule # : LHS -> RHS */
   fprintf (out, "%s\n\n", title);
   for (r = begin; r < end; r++)
     {
-      if (last_lhs && last_lhs != rules[r].lhs)
+      if (previous_lhs && previous_lhs != rules[r].lhs)
 	fputc ('\n', out);
-
-      fprintf (out, "  %3d ", r - 1);
-      if (last_lhs != rules[r].lhs)
-	{
-	  last_lhs = rules[r].lhs;
-	  fprintf (out, "%s:", symbol_tag_get (last_lhs));
-	}
-      else
-	{
-	  blanks_print (strlen (symbol_tag_get (last_lhs)), out);
-	  fputc ('|', out);
-	}
+      rule_lhs_print (&rules[r], previous_lhs, out);
       rule_rhs_print (&rules[r], out);
+      previous_lhs = rules[r].lhs;
     }
   fputs ("\n\n", out);
 }
