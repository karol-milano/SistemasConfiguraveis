@@ -247,23 +247,24 @@ grammar_dump (FILE *out, const char *title)
 	   ntokens, nvars, nsyms, nrules, nritems);
 
 
-  fprintf (out, "Variables\n---------\n\n");
+  fputs (("Variables\n---------\n\n"
+	  "Value  Sprec  Sassoc  Tag\n"),
+	 out);
   {
     symbol_number i;
-    fprintf (out, "Value  Sprec  Sassoc  Tag\n");
-
     for (i = ntokens; i < nsyms; i++)
       fprintf (out, "%5d  %5d   %5d  %s\n",
 	       i,
 	       symbols[i]->prec, symbols[i]->assoc,
 	       symbols[i]->tag);
-    fprintf (out, "\n\n");
   }
+  fputs ("\n\n", out);
 
-  fprintf (out, "Rules\n-----\n\n");
+  fputs (("Rules\n-----\n\n"
+	  "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n"),
+	 out);
   {
     rule_number i;
-    fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
     for (i = 0; i < nrules + nuseless_productions; i++)
       {
 	rule *rule_i = &rules[i];
@@ -287,9 +288,9 @@ grammar_dump (FILE *out, const char *title)
 	fprintf (out, "  [%d]\n", item_number_as_rule_number (*rp));
       }
   }
-  fprintf (out, "\n\n");
+  fputs ("\n\n", out);
 
-  fprintf (out, "Rules interpreted\n-----------------\n\n");
+  fputs ("Rules interpreted\n-----------------\n\n", out);
   {
     rule_number r;
     for (r = 0; r < nrules + nuseless_productions; r++)
@@ -298,7 +299,7 @@ grammar_dump (FILE *out, const char *title)
 	rule_print (&rules[r], out);
       }
   }
-  fprintf (out, "\n\n");
+  fputs ("\n\n", out);
 }
 
 
