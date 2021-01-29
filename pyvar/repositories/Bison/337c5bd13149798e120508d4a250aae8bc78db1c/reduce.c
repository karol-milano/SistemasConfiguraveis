@@ -1,5 +1,5 @@
 /* Grammar reduction for Bison.
-   Copyright 1988, 1989, 2000 Free Software Foundation, Inc.
+   Copyright 1988, 1989, 2000, 2001  Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -388,21 +388,25 @@ reduce_grammar_tables (void)
     }
 }
 
-static void
-print_results (void)
+
+/*-----------------------------------------------------------------.
+| Ouput the detailed results of the reductions.  For FILE.output.  |
+`-----------------------------------------------------------------*/
+
+void
+reduce_output (FILE *out)
 {
   int i;
-/*  short j; JF unused */
   rule r;
   bool b;
 
   if (nuseless_nonterminals > 0)
     {
-      obstack_sgrow (&output_obstack, _("Useless nonterminals:"));
-      obstack_sgrow (&output_obstack, "\n\n");
+      fprintf (out, _("Useless nonterminals:"));
+      fprintf (out, "\n\n");
       for (i = ntokens; i < nsyms; i++)
 	if (!BITISSET (V, i))
-	  obstack_fgrow1 (&output_obstack, "   %s\n", tags[i]);
+	  fprintf (out, "   %s\n", tags[i]);
     }
   b = FALSE;
   for (i = 0; i < ntokens; i++)
@@ -411,81 +415,81 @@ print_results (void)
 	{
 	  if (!b)
 	    {
-	      obstack_sgrow (&output_obstack, "\n\n");
-	      obstack_sgrow (&output_obstack,
-				   _("Terminals which are not used:"));
-	      obstack_sgrow (&output_obstack, "\n\n");
+	      fprintf (out, "\n\n");
+	      fprintf (out, _("Terminals which are not used:"));
+	      fprintf (out, "\n\n");
 	      b = TRUE;
 	    }
-	  obstack_fgrow1 (&output_obstack, "   %s\n", tags[i]);
+	  fprintf (out, "   %s\n", tags[i]);
 	}
     }
 
   if (nuseless_productions > 0)
     {
-      obstack_sgrow (&output_obstack, "\n\n");
-      obstack_sgrow (&output_obstack, _("Useless rules:"));
-      obstack_sgrow (&output_obstack, "\n\n");
+      fprintf (out, "\n\n");
+      fprintf (out, _("Useless rules:"));
+      fprintf (out, "\n\n");
       for (i = 1; i <= nrules; i++)
 	{
 	  if (!BITISSET (P, i))
 	    {
-	      obstack_fgrow1 (&output_obstack, "#%-4d  ", i);
-	      obstack_fgrow1 (&output_obstack, "%s :\t", tags[rlhs[i]]);
+	      fprintf (out, "#%-4d  ", i);
+	      fprintf (out, "%s :\t", tags[rlhs[i]]);
 	      for (r = &ritem[rrhs[i]]; *r >= 0; r++)
-		obstack_fgrow1 (&output_obstack, " %s", tags[*r]);
-	      obstack_sgrow (&output_obstack, ";\n");
+		fprintf (out, " %s", tags[*r]);
+	      fprintf (out, ";\n");
 	    }
 	}
     }
   if (nuseless_nonterminals > 0 || nuseless_productions > 0 || b)
-    obstack_sgrow (&output_obstack, "\n\n");
+    fprintf (out, "\n\n");
 }
 
 #if 0				/* XXX currently unused.  */
 static void
-dump_grammar (void)
+dump_grammar (FILE *out)
 {
   int i;
   rule r;
 
-  obstack_fgrow5 (&output_obstack,
+  fprintf (out,
 	 "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nitems = %d\n\n",
 	 ntokens, nvars, nsyms, nrules, nitems);
-  obstack_sgrow (&output_obstack,
-		       _("Variables\n---------\n\n"));
-  obstack_sgrow (&output_obstack,
-		       _("Value  Sprec    Sassoc    Tag\n"));
+  fprintf (out, _("Variables\n---------\n\n"));
+  fprintf (out, _("Value  Sprec    Sassoc    Tag\n"));
   for (i = ntokens; i < nsyms; i++)
-    obstack_fgrow4 (&output_obstack,
-		    "%5d  %5d  %5d  %s\n", i, sprec[i], sassoc[i], tags[i]);
-  obstack_sgrow (&output_obstack, "\n\n");
-  obstack_sgrow (&output_obstack, _("Rules\n-----\n\n"));
+    fprintf (out, "%5d  %5d  %5d  %s\n", i, sprec[i], sassoc[i], tags[i]);
+  fprintf (out, "\n\n");
+  fprintf (out, _("Rules\n-----\n\n"));
   for (i = 1; i <= nrules; i++)
     {
-      obstack_fgrow5 (&output_obstack, "%-5d(%5d%5d)%5d : (@%-5d)",
-		      i, rprec[i], rassoc[i], rlhs[i], rrhs[i]);
+      fprintf (out, "%-5d(%5d%5d)%5d : (@%-5d)",
+	       i, rprec[i], rassoc[i], rlhs[i], rrhs[i]);
       for (r = &ritem[rrhs[i]]; *r > 0; r++)
-	obstack_fgrow1 (&output_obstack, "%5d", *r);
-      obstack_fgrow1 (&output_obstack, " [%d]\n", -(*r));
+	fprintf (out, "%5d", *r);
+      fprintf (out, " [%d]\n", -(*r));
     }
-  obstack_sgrow (&output_obstack, "\n\n");
-  obstack_sgrow (&output_obstack,
-		       _("Rules interpreted\n-----------------\n\n"));
+  fprintf (out, "\n\n");
+  fprintf (out, _("Rules interpreted\n-----------------\n\n"));
   for (i = 1; i <= nrules; i++)
     {
-      obstack_fgrow2 (&output_obstack, "%-5d  %s :", i, tags[rlhs[i]]);
+      fprintf (out, "%-5d  %s :", i, tags[rlhs[i]]);
       for (r = &ritem[rrhs[i]]; *r > 0; r++)
-	obstack_fgrow1 (&output_obstack, " %s", tags[*r]);
-      obstack_grow1 (&output_obstack, '\n');
+	fprintf (out, " %s", tags[*r]);
+      fputc ('\n', out);
     }
-  obstack_sgrow (&output_obstack, "\n\n");
+  fprintf (out, "\n\n");
 }
 #endif
 
 
+
+/*-------------------------------.
+| Report the results to STDERR.  |
+`-------------------------------*/
+
 static void
-print_notices (void)
+reduce_print (void)
 {
   if (yacc_flag && nuseless_productions)
     fprintf (stderr, _("%d rules never reduced\n"), nuseless_productions);
@@ -527,13 +531,10 @@ reduce_grammar (void)
 
   reduced = (bool) (nuseless_nonterminals + nuseless_productions > 0);
 
-  if (verbose_flag)
-    print_results ();
-
-  if (reduced == FALSE)
-    goto done_reducing;
+  if (!reduced)
+    return;
 
-  print_notices ();
+  reduce_print ();
 
   if (!BITISSET (N, start_symbol - ntokens))
     fatal (_("Start symbol %s does not derive any sentence"),
@@ -543,7 +544,7 @@ reduce_grammar (void)
 #if 0
   if (verbose_flag)
     {
-      obstack_fgrow1 (&output_obstack, "REDUCED GRAMMAR\n\n");
+      fprintf (out, "REDUCED GRAMMAR\n\n");
       dump_grammar ();
     }
 #endif
@@ -558,11 +559,18 @@ reduce_grammar (void)
 	     (nvars == 1 ? "" : "s"),
 	     nrules,
 	     (nrules == 1 ? "" : "s"));
+}
 
-done_reducing:
-  /* Free the global sets used to compute the reduced grammar */
 
+/*-----------------------------------------------------------.
+| Free the global sets used to compute the reduced grammar.  |
+`-----------------------------------------------------------*/
+
+void
+reduce_free (void)
+{
   XFREE (N);
   XFREE (V);
+  XFREE (V1);
   XFREE (P);
 }
