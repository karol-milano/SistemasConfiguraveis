@@ -442,14 +442,14 @@ dump_grammar (FILE *out)
 
   fprintf (out, "REDUCED GRAMMAR\n\n");
   fprintf (out,
-	 "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nitems = %d\n\n",
-	 ntokens, nvars, nsyms, nrules, nitems);
-  fprintf (out, _("Variables\n---------\n\n"));
-  fprintf (out, _("Value  Sprec    Sassoc    Tag\n"));
+	   "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nitems = %d\n\n",
+	   ntokens, nvars, nsyms, nrules, nitems);
+  fprintf (out, "Variables\n---------\n\n");
+  fprintf (out, "Value  Sprec    Sassoc    Tag\n");
   for (i = ntokens; i < nsyms; i++)
     fprintf (out, "%5d  %5d  %5d  %s\n", i, sprec[i], sassoc[i], tags[i]);
   fprintf (out, "\n\n");
-  fprintf (out, _("Rules\n-----\n\n"));
+  fprintf (out, "Rules\n-----\n\n");
   for (i = 1; i <= nrules; i++)
     {
       fprintf (out, "%-5d(%5d%5d)%5d : (@%-5d)",
@@ -463,7 +463,7 @@ dump_grammar (FILE *out)
       fprintf (out, " [%d]\n", -(*r));
     }
   fprintf (out, "\n\n");
-  fprintf (out, _("Rules interpreted\n-----------------\n\n"));
+  fprintf (out, "Rules interpreted\n-----------------\n\n");
   for (i = 1; i <= nrules; i++)
     {
       fprintf (out, "%-5d  %s :", i, tags[rule_table[i].lhs]);
