@@ -133,9 +133,10 @@ ritem_longest_rhs (void)
 }
 
 
-/*-----------------------------------.
-| Print the grammar's rules on OUT.  |
-`-----------------------------------*/
+/*----------------------------------------------------------------.
+| Print the grammar's rules numbers from BEGIN (inclusive) to END |
+| (exclusive) on OUT under TITLE.                                 |
+`----------------------------------------------------------------*/
 
 static inline void
 blanks_print (unsigned n, FILE *out)
@@ -145,14 +146,15 @@ blanks_print (unsigned n, FILE *out)
 }
 
 void
-grammar_rules_print (FILE *out)
+grammar_rules_partial_print (FILE *out, const char *title,
+			     int begin, int end)
 {
   int r;
   symbol_t *last_lhs = NULL;
 
   /* rule # : LHS -> RHS */
-  fprintf (out, "%s\n\n", _("Grammar"));
-  for (r = 1; r < nrules + 1; r++)
+  fprintf (out, "%s\n\n", title);
+  for (r = begin; r < end; r++)
     {
       if (last_lhs && last_lhs != rules[r].lhs)
 	fputc ('\n', out);
@@ -173,6 +175,18 @@ grammar_rules_print (FILE *out)
   fputs ("\n\n", out);
 }
 
+
+/*------------------------------------------.
+| Print the grammar's useful rules on OUT.  |
+`------------------------------------------*/
+
+void
+grammar_rules_print (FILE *out)
+{
+  grammar_rules_partial_print (out, _("Grammar"), 1, nrules + 1);
+}
+
+
 /*-------------------.
 | Dump the grammar.  |
 `-------------------*/
