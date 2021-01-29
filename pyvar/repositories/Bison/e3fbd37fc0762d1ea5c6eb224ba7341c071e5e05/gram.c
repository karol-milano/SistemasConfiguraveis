@@ -247,10 +247,10 @@ grammar_dump (FILE *out, const char *title)
 	   ntokens, nvars, nsyms, nrules, nritems);
 
 
-  fprintf (out, "Variables\n---------\n\n");
+  fprintf (out, _("Variables\n---------\n\n"));
   {
     symbol_number_t i;
-    fprintf (out, "Value  Sprec  Sassoc  Tag\n");
+    fprintf (out, _("Value  Sprec  Sassoc  Tag\n"));
 
     for (i = ntokens; i < nsyms; i++)
       fprintf (out, "%5d  %5d   %5d  %s\n",
@@ -260,25 +260,26 @@ grammar_dump (FILE *out, const char *title)
     fprintf (out, "\n\n");
   }
 
-  fprintf (out, "Rules\n-----\n\n");
+  fprintf (out, _("Rules\n-----\n\n"));
   {
     rule_number_t i;
-    fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
+    fprintf (out, _("Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n"));
     for (i = 0; i < nrules + nuseless_productions; i++)
       {
 	rule_t *rule = &rules[i];
 	item_number_t *r = NULL;
-  	int rhs_count = 0;
+	unsigned int rhs_itemno = rule->rhs - ritem;
+  	unsigned int rhs_count = 0;
 	/* Find the last RHS index in ritems. */
 	for (r = rule->rhs; *r >= 0; ++r)
 	  ++rhs_count;
-	fprintf (out, "%3d (%2d, %2d, %2d, %2d-%2d)   %2d ->",
+	fprintf (out, "%3d (%2d, %2d, %2d, %2u-%2u)   %2d ->",
 		 i,
 		 rule->prec ? rule->prec->prec : 0,
 		 rule->prec ? rule->prec->assoc : 0,
 		 rule->useful,
-		 rule->rhs - ritem,
-		 rule->rhs - ritem + rhs_count - 1,
+		 rhs_itemno,
+		 rhs_itemno + rhs_count - 1,
 		 rule->lhs->number);
 	/* Dumped the RHS. */
 	for (r = rule->rhs; *r >= 0; r++)
@@ -288,7 +289,7 @@ grammar_dump (FILE *out, const char *title)
   }
   fprintf (out, "\n\n");
 
-  fprintf (out, "Rules interpreted\n-----------------\n\n");
+  fprintf (out, _("Rules interpreted\n-----------------\n\n"));
   {
     rule_number_t r;
     for (r = 0; r < nrules + nuseless_productions; r++)
