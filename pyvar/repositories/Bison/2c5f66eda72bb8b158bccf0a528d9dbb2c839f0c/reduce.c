@@ -200,38 +200,33 @@ inaccessable_symbols (void)
   Pp = XCALLOC (unsigned, WORDSIZE (nrules + 1));
 
   /* If the start symbol isn't useful, then nothing will be useful. */
-  if (!BITISSET (N, start_symbol - ntokens))
-    goto end_iteration;
-
-  SETBIT (V, start_symbol);
-
-  while (1)
+  if (BITISSET (N, start_symbol - ntokens))
     {
-      for (i = WORDSIZE (nsyms) - 1; i >= 0; i--)
-	Vp[i] = V[i];
-      for (i = 1; i <= nrules; i++)
+      SETBIT (V, start_symbol);
+
+      while (1)
 	{
-	  if (!BITISSET (Pp, i) && BITISSET (P, i) && BITISSET (V, rule_table[i].lhs))
+	  for (i = WORDSIZE (nsyms) - 1; i >= 0; i--)
+	    Vp[i] = V[i];
+	  for (i = 1; i <= nrules; i++)
 	    {
-	      for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
+	      if (!BITISSET (Pp, i)
+		  && BITISSET (P, i)
+		  && BITISSET (V, rule_table[i].lhs))
 		{
-		  if (ISTOKEN (t = *r) || BITISSET (N, t - ntokens))
-		    {
+		  for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
+		    if (ISTOKEN (t = *r) || BITISSET (N, t - ntokens))
 		      SETBIT (Vp, t);
-		    }
+		  SETBIT (Pp, i);
 		}
-	      SETBIT (Pp, i);
 	    }
+	  if (bits_equal (V, Vp, WORDSIZE (nsyms)))
+	    break;
+	  Vs = Vp;
+	  Vp = V;
+	  V = Vs;
 	}
-      if (bits_equal (V, Vp, WORDSIZE (nsyms)))
-	{
-	  break;
-	}
-      Vs = Vp;
-      Vp = V;
-      V = Vs;
     }
-end_iteration:
 
   XFREE (V);
   V = Vp;
@@ -430,28 +425,27 @@ reduce_output (FILE *out)
       fprintf (out, _("Useless rules:"));
       fprintf (out, "\n\n");
       for (i = 1; i <= nrules; i++)
-	{
-	  if (!BITISSET (P, i))
-	    {
-	      fprintf (out, "#%-4d  ", i);
-	      fprintf (out, "%s :\t", tags[rule_table[i].lhs]);
-	      for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
-		fprintf (out, " %s", tags[*r]);
-	      fprintf (out, ";\n");
-	    }
-	}
+	if (!BITISSET (P, i))
+	  {
+	    fprintf (out, "#%-4d  ", i);
+	    fprintf (out, "%s :\t", tags[rule_table[i].lhs]);
+	    for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
+	      fprintf (out, " %s", tags[*r]);
+	    fprintf (out, ";\n");
+	  }
     }
   if (nuseless_nonterminals > 0 || nuseless_productions > 0 || b)
     fprintf (out, "\n\n");
 }
 
-#if 0				/* XXX currently unused.  */
+#if TRACE
 static void
 dump_grammar (FILE *out)
 {
   int i;
   rule r;
 
+  fprintf (out, "REDUCED GRAMMAR\n\n");
   fprintf (out,
 	 "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nitems = %d\n\n",
 	 ntokens, nvars, nsyms, nrules, nitems);
@@ -545,12 +539,8 @@ reduce_grammar (void)
 	   tags[start_symbol]);
 
   reduce_grammar_tables ();
-#if 0
-  if (verbose_flag)
-    {
-      fprintf (out, "REDUCED GRAMMAR\n\n");
-      dump_grammar ();
-    }
+#if TRACE
+  dump_grammar (stderr);
 #endif
 
   if (statistics_flag)
