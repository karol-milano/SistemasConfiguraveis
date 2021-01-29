@@ -445,11 +445,12 @@ dump_grammar (FILE *out)
 	   "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nitems = %d\n\n",
 	   ntokens, nvars, nsyms, nrules, nitems);
   fprintf (out, "Variables\n---------\n\n");
-  fprintf (out, "Value  Sprec    Sassoc    Tag\n");
+  fprintf (out, "Value  Sprec  Sassoc  Tag\n");
   for (i = ntokens; i < nsyms; i++)
-    fprintf (out, "%5d  %5d  %5d  %s\n", i, sprec[i], sassoc[i], tags[i]);
+    fprintf (out, "%5d  %5d   %5d  %s\n", i, sprec[i], sassoc[i], tags[i]);
   fprintf (out, "\n\n");
   fprintf (out, "Rules\n-----\n\n");
+  fprintf (out, "Num (Prec, Assoc) Lhs : (@Rhs) Ritems [Num?]\n");
   for (i = 1; i <= nrules; i++)
     {
       fprintf (out, "%-5d(%5d%5d)%5d : (@%-5d)",
@@ -484,24 +485,27 @@ static void
 reduce_print (void)
 {
   if (yacc_flag && nuseless_productions)
-    fprintf (stderr, _("%d rules never reduced\n"), nuseless_productions);
+    fprintf (stderr, ngettext ("%d rule never reduced\n",
+			       "%d rules never reduced\n",
+			       nuseless_productions),
+	     nuseless_productions);
 
   fprintf (stderr, _("%s contains "), infile);
 
   if (nuseless_nonterminals > 0)
-    {
-      fprintf (stderr, _("%d useless nonterminal%s"),
-	       nuseless_nonterminals,
-	       (nuseless_nonterminals == 1 ? "" : "s"));
-    }
+    fprintf (stderr, ngettext ("%d useless nonterminal",
+			       "%d useless nonterminals",
+			       nuseless_nonterminals),
+	     nuseless_nonterminals);
+
   if (nuseless_nonterminals > 0 && nuseless_productions > 0)
     fprintf (stderr, _(" and "));
 
   if (nuseless_productions > 0)
-    {
-      fprintf (stderr, _("%d useless rule%s"),
-	       nuseless_productions, (nuseless_productions == 1 ? "" : "s"));
-    }
+    fprintf (stderr, ngettext ("%d useless rule",
+			       "%d useless rules",
+			       nuseless_productions),
+	     nuseless_productions);
   fprintf (stderr, "\n");
   fflush (stderr);
 }
