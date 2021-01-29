@@ -247,10 +247,10 @@ grammar_dump (FILE *out, const char *title)
 	   ntokens, nvars, nsyms, nrules, nritems);
 
 
-  fprintf (out, _("Variables\n---------\n\n"));
+  fprintf (out, "Variables\n---------\n\n");
   {
     symbol_number_t i;
-    fprintf (out, _("Value  Sprec  Sassoc  Tag\n"));
+    fprintf (out, "Value  Sprec  Sassoc  Tag\n");
 
     for (i = ntokens; i < nsyms; i++)
       fprintf (out, "%5d  %5d   %5d  %s\n",
@@ -260,10 +260,10 @@ grammar_dump (FILE *out, const char *title)
     fprintf (out, "\n\n");
   }
 
-  fprintf (out, _("Rules\n-----\n\n"));
+  fprintf (out, "Rules\n-----\n\n");
   {
     rule_number_t i;
-    fprintf (out, _("Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n"));
+    fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
     for (i = 0; i < nrules + nuseless_productions; i++)
       {
 	rule_t *rule = &rules[i];
@@ -289,7 +289,7 @@ grammar_dump (FILE *out, const char *title)
   }
   fprintf (out, "\n\n");
 
-  fprintf (out, _("Rules interpreted\n-----------------\n\n"));
+  fprintf (out, "Rules interpreted\n-----------------\n\n");
   {
     rule_number_t r;
     for (r = 0; r < nrules + nuseless_productions; r++)
