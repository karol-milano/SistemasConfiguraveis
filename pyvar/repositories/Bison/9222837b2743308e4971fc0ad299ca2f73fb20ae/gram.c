@@ -32,7 +32,7 @@ item_number_t *ritem = NULL;
 unsigned int nritems = 0;
 
 rule_t *rules = NULL;
-int nrules = 0;
+rule_number_t nrules = 0;
 
 symbol_t **symbols = NULL;
 int nsyms = 0;
@@ -121,11 +121,11 @@ size_t
 ritem_longest_rhs (void)
 {
   int max = 0;
-  int i;
+  rule_number_t r;
 
-  for (i = 1; i < nrules + 1; ++i)
+  for (r = 1; r < nrules + 1; ++r)
     {
-      int length = rule_rhs_length (&rules[i]);
+      int length = rule_rhs_length (&rules[r]);
       if (length > max)
 	max = length;
     }
@@ -148,7 +148,7 @@ blanks_print (unsigned n, FILE *out)
 
 void
 grammar_rules_partial_print (FILE *out, const char *title,
-			     int begin, int end)
+			     rule_number_t begin, rule_number_t end)
 {
   int r;
   symbol_t *last_lhs = NULL;
@@ -195,49 +195,62 @@ grammar_rules_print (FILE *out)
 void
 grammar_dump (FILE *out, const char *title)
 {
-  int i;
-  item_number_t *r;
-
   fprintf (out, "%s\n\n", title);
   fprintf (out,
 	   "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nritems = %d\n\n",
 	   ntokens, nvars, nsyms, nrules, nritems);
+
+
   fprintf (out, "Variables\n---------\n\n");
-  fprintf (out, "Value  Sprec  Sassoc  Tag\n");
-  for (i = ntokens; i < nsyms; i++)
-    fprintf (out, "%5d  %5d   %5d  %s\n",
-	     i,
-	     symbols[i]->prec, symbols[i]->assoc,
-	     symbol_tag_get (symbols[i]));
-  fprintf (out, "\n\n");
+  {
+    symbol_number_t i;
+    fprintf (out, "Value  Sprec  Sassoc  Tag\n");
+
+    for (i = ntokens; i < nsyms; i++)
+      fprintf (out, "%5d  %5d   %5d  %s\n",
+	       i,
+	       symbols[i]->prec, symbols[i]->assoc,
+	       symbol_tag_get (symbols[i]));
+    fprintf (out, "\n\n");
+  }
+
   fprintf (out, "Rules\n-----\n\n");
-  fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
-  for (i = 1; i < nrules + nuseless_productions + 1; i++)
-    {
-      int rhs_count = 0;
-      /* Find the last RHS index in ritems. */
-      for (r = rules[i].rhs; *r >= 0; ++r)
-	++rhs_count;
-      fprintf (out, "%3d (%2d, %2d, %2d, %2d-%2d)   %2d ->",
-	       i - 1,
-	       rules[i].prec ? rules[i].prec->prec : 0,
-	       rules[i].prec ? rules[i].prec->assoc : 0,
-	       rules[i].useful,
-	       rules[i].rhs - ritem,
-	       rules[i].rhs - ritem + rhs_count - 1,
-	       rules[i].lhs->number);
-      /* Dumped the RHS. */
-      for (r = rules[i].rhs; *r >= 0; r++)
-	fprintf (out, " %3d", *r);
-      fprintf (out, "  [%d]\n", -(*r) - 1);
-    }
+  {
+    rule_number_t i;
+    fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
+    for (i = 1; i < nrules + nuseless_productions + 1; i++)
+      {
+	rule_t *rule = &rules[i];
+	item_number_t *r = NULL;
+  	int rhs_count = 0;
+	/* Find the last RHS index in ritems. */
+	for (r = rule->rhs; *r >= 0; ++r)
+	  ++rhs_count;
+	fprintf (out, "%3d (%2d, %2d, %2d, %2d-%2d)   %2d ->",
+		 i - 1,
+		 rule->prec ? rule->prec->prec : 0,
+		 rule->prec ? rule->prec->assoc : 0,
+		 rule->useful,
+		 rule->rhs - ritem,
+		 rule->rhs - ritem + rhs_count - 1,
+		 rule->lhs->number);
+	/* Dumped the RHS. */
+	for (r = rule->rhs; *r >= 0; r++)
+	  fprintf (out, " %3d", *r);
+	fprintf (out, "  [%d]\n", -(*r) - 1);
+      }
+  }
   fprintf (out, "\n\n");
+
   fprintf (out, "Rules interpreted\n-----------------\n\n");
-  for (i = 1; i < nrules + nuseless_productions + 1; i++)
-    {
-      fprintf (out, "%-5d  ", i);
-      rule_print (&rules[i], out);
-    }
+  {
+    rule_number_t r;
+    for (r = 1; r < nrules + nuseless_productions + 1; r++)
+      {
+	fprintf (out, "%-5d  ", r);
+	rule_print (&rules[r], out);
+      }
+  }
   fprintf (out, "\n\n");
 }
 
