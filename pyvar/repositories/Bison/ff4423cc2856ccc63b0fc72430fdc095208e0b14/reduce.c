@@ -401,11 +401,11 @@ print_results (void)
 
   if (nuseless_nonterminals > 0)
     {
-      fputs (_("Useless nonterminals:"), foutput);
-      fputs ("\n\n", foutput);
+      obstack_sgrow (&output_obstack, _("Useless nonterminals:"));
+      obstack_sgrow (&output_obstack, "\n\n");
       for (i = ntokens; i < nsyms; i++)
 	if (!BITISSET (V, i))
-	  fprintf (foutput, "   %s\n", tags[i]);
+	  obstack_fgrow1 (&output_obstack, "   %s\n", tags[i]);
     }
   b = FALSE;
   for (i = 0; i < ntokens; i++)
@@ -414,36 +414,35 @@ print_results (void)
 	{
 	  if (!b)
 	    {
-	      fputs ("\n\n", foutput);
-	      fprintf (foutput, _("Terminals which are not used:"));
-	      fputs ("\n\n", foutput);
+	      obstack_sgrow (&output_obstack, "\n\n");
+	      obstack_sgrow (&output_obstack,
+				   _("Terminals which are not used:"));
+	      obstack_sgrow (&output_obstack, "\n\n");
 	      b = TRUE;
 	    }
-	  fprintf (foutput, "   %s\n", tags[i]);
+	  obstack_fgrow1 (&output_obstack, "   %s\n", tags[i]);
 	}
     }
 
   if (nuseless_productions > 0)
     {
-      fputs ("\n\n", foutput);
-      fprintf (foutput, _("Useless rules:"));
-      fputs ("\n\n", foutput);
+      obstack_sgrow (&output_obstack, "\n\n");
+      obstack_sgrow (&output_obstack, _("Useless rules:"));
+      obstack_sgrow (&output_obstack, "\n\n");
       for (i = 1; i <= nrules; i++)
 	{
 	  if (!BITISSET (P, i))
 	    {
-	      fprintf (foutput, "#%-4d  ", i);
-	      fprintf (foutput, "%s :\t", tags[rlhs[i]]);
+	      obstack_fgrow1 (&output_obstack, "#%-4d  ", i);
+	      obstack_fgrow1 (&output_obstack, "%s :\t", tags[rlhs[i]]);
 	      for (r = &ritem[rrhs[i]]; *r >= 0; r++)
-		{
-		  fprintf (foutput, " %s", tags[*r]);
-		}
-	      fprintf (foutput, ";\n");
+		obstack_fgrow1 (&output_obstack, " %s", tags[*r]);
+	      obstack_sgrow (&output_obstack, ";\n");
 	    }
 	}
     }
   if (nuseless_nonterminals > 0 || nuseless_productions > 0 || b)
-    fputs ("\n\n", foutput);
+    obstack_sgrow (&output_obstack, "\n\n");
 }
 
 #if 0				/* XXX currently unused.  */
@@ -453,35 +452,38 @@ dump_grammar (void)
   int i;
   rule r;
 
-  fprintf (foutput,
-	   "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nitems = %d\n\n",
-	   ntokens, nvars, nsyms, nrules, nitems);
-  fprintf (foutput, _("Variables\n---------\n\n"));
-  fprintf (foutput, _("Value  Sprec    Sassoc    Tag\n"));
+  obstack_fgrow5 (&output_obstack,
+	 "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nitems = %d\n\n",
+	 ntokens, nvars, nsyms, nrules, nitems);
+  obstack_sgrow (&output_obstack,
+		       _("Variables\n---------\n\n"));
+  obstack_sgrow (&output_obstack,
+		       _("Value  Sprec    Sassoc    Tag\n"));
   for (i = ntokens; i < nsyms; i++)
-    fprintf (foutput, "%5d  %5d  %5d  %s\n", i, sprec[i], sassoc[i], tags[i]);
-  fprintf (foutput, "\n\n");
-  fprintf (foutput, _("Rules\n-----\n\n"));
+    obstack_fgrow4 (&output_obstack,
+		    "%5d  %5d  %5d  %s\n", i, sprec[i], sassoc[i], tags[i]);
+  obstack_sgrow (&output_obstack, "\n\n");
+  obstack_sgrow (&output_obstack, _("Rules\n-----\n\n"));
   for (i = 1; i <= nrules; i++)
     {
-      fprintf (foutput, "%-5d(%5d%5d)%5d : (@%-5d)",
-	       i, rprec[i], rassoc[i], rlhs[i], rrhs[i]);
+      obstack_fgrow5 (&output_obstack, "%-5d(%5d%5d)%5d : (@%-5d)",
+		      i, rprec[i], rassoc[i], rlhs[i], rrhs[i]);
       for (r = &ritem[rrhs[i]]; *r > 0; r++)
-	fprintf (foutput, "%5d", *r);
-      fprintf (foutput, " [%d]\n", -(*r));
+	obstack_fgrow1 (&output_obstack, "%5d", *r);
+      obstack_fgrow1 (&output_obstack, " [%d]\n", -(*r));
     }
-  fprintf (foutput, "\n\n");
-  fprintf (foutput, _("Rules interpreted\n-----------------\n\n"));
+  obstack_sgrow (&output_obstack, "\n\n");
+  obstack_sgrow (&output_obstack,
+		       _("Rules interpreted\n-----------------\n\n"));
   for (i = 1; i <= nrules; i++)
     {
-      fprintf (foutput, "%-5d  %s :", i, tags[rlhs[i]]);
+      obstack_fgrow2 (&output_obstack, "%-5d  %s :", i, tags[rlhs[i]]);
       for (r = &ritem[rrhs[i]]; *r > 0; r++)
-	fprintf (foutput, " %s", tags[*r]);
-      fprintf (foutput, "\n");
+	obstack_fgrow1 (&output_obstack, " %s", tags[*r]);
+      obstack_grow1 (&output_obstack, '\n');
     }
-  fprintf (foutput, "\n\n");
+  obstack_sgrow (&output_obstack, "\n\n");
 }
-
 #endif
 
 
@@ -544,7 +546,7 @@ reduce_grammar (void)
 #if 0
   if (verbose_flag)
     {
-      fprintf (foutput, "REDUCED GRAMMAR\n\n");
+      obstack_fgrow1 (&output_obstack, "REDUCED GRAMMAR\n\n");
       dump_grammar ();
     }
 #endif
