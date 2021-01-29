@@ -220,70 +220,64 @@ inaccessable_symbols (void)
       bitset_set (V1, rules[i].precsym);
 }
 
+
+/*-------------------------------------------------------------------.
+| Put the useless productions at the end of RULES, and adjust NRULES |
+| accordingly.                                                       |
+`-------------------------------------------------------------------*/
+
 static void
 reduce_grammar_tables (void)
 {
-  /* This is turned off because we would need to change the numbers in
-     the case statements in the actions file.
+  /* Flag useless productions.  */
+  {
+    int pn;
+    for (pn = 1; pn < nrules + 1; pn++)
+      rules[pn].useful = bitset_test (P, pn);
+  }
 
-     We don't disable it via CPP so that it is still checked with the
-     rest of the code, to avoid its becoming completely obsolete.
+  /* Map the nonterminals to their new index: useful first, useless
+     afterwards.  Kept for later report.  */
+  {
+    int useful = 1;
+    int useless = nrules + 1 - nuseless_productions;
+    rule_t *rules_sorted = XMALLOC (rule_t, nrules + 1) - 1;
+    int i;
+    for (i = 1; i < nrules + 1; ++i)
+      rules_sorted[rules[i].useful ? useful++ : useless++] = rules[i];
+    free (rules + 1);
+    rules = rules_sorted;
 
-     FIXME: I think the comment above demonstrates this code must be
-     turned off for *semantic* parser, not in the general case.  Try
-     to understand this better --akim.  */
+    /* Also reorder ritems. */
+    {
+      short *ritems_sorted = XCALLOC (short, nitems + 1);
+      short *ritemsp = ritems_sorted;
+      for (i = 1; i < nrules + 1; ++i)
+	{
+	  short *rhsp = rules[i].rhs;
+	  rules[i].rhs = ritemsp;
+	  for (/* Nothing. */; *rhsp >= 0; ++rhsp)
+	    *ritemsp++ = *rhsp;
+	  *ritemsp++ = -i;
+	}
+      *ritemsp++ = 0;
+      free (ritem);
+      ritem = ritems_sorted;
+    }
+    nrules -= nuseless_productions;
+  }
 
-  if (0)
-    /* remove useless productions */
-    if (nuseless_productions > 0)
+  /* Adjust NRITEMS and NITEMS.  */
+  {
+    int r;
+    int length;
+    for (r = nrules + 1; r < nrules + 1 + nuseless_productions; ++r)
       {
-	short np, pn, ni, pi;
-
-	np = 0;
-	ni = 0;
-	for (pn = 1; pn < nrules + 1; pn++)
-	  if (bitset_test (P, pn))
-	    {
-	      np++;
-	      if (pn != np)
-		{
-		  rules[np].lhs   = rules[pn].lhs;
-		  rules[np].line  = rules[pn].line;
-		  rules[np].prec  = rules[pn].prec;
-		  rules[np].assoc = rules[pn].assoc;
-		  rules[np].rhs   = rules[pn].rhs;
-		  if (rules[np].rhs - ritem != ni)
-		    {
-		      pi = rules[np].rhs - ritem;
-		      rules[np].rhs = ritem + ni;
-		      while (ritem[pi] >= 0)
-			ritem[ni++] = ritem[pi++];
-		      ritem[ni++] = -np;
-		    }
-		}
-	      else
-		{
-		  while (ritem[ni++] >= 0)
-		    /* Nothing. */;
-		}
-	    }
-
-	ritem[ni] = 0;
-	nrules -= nuseless_productions;
-	nitems = ni;
-	nritems = ni;
-
-	/* Is it worth it to reduce the amount of memory for the
-	   grammar? Probably not.  */
+	length = rule_rhs_length (&rules[r]);
+	nritems -= length + 1;
+	nitems -= length + 1;
       }
-
-  /* Disable useless productions. */
-  if (nuseless_productions > 0)
-    {
-      int pn;
-      for (pn = 1; pn < nrules + 1; pn++)
-	rules[pn].useful = bitset_test (P, pn);
-    }
+  }
 }
 
 
@@ -378,16 +372,15 @@ reduce_output (FILE *out)
     {
       int i;
       fprintf (out, "%s\n\n", _("Useless rules:"));
-      for (i = 1; i < nrules + 1; i++)
-	if (!rules[i].useful)
-	  {
-	    rule r;
-	    fprintf (out, "#%-4d  ", i - 1);
-	    fprintf (out, "%s:", symbols[rules[i].lhs]->tag);
-	    for (r = rules[i].rhs; *r >= 0; r++)
-	      fprintf (out, " %s", symbols[*r]->tag);
-	    fputs (";\n", out);
-	  }
+      for (i = nrules + 1; i < nuseless_productions + nrules + 1; i++)
+	{
+	  rule r;
+	  fprintf (out, "#%-4d  ", rules[i].number - 1);
+	  fprintf (out, "%s:", symbols[rules[i].lhs]->tag);
+	  for (r = rules[i].rhs; *r >= 0; r++)
+	    fprintf (out, " %s", symbols[*r]->tag);
+	  fputs (";\n", out);
+	}
       fputs ("\n\n", out);
     }
 }
@@ -411,7 +404,7 @@ dump_grammar (FILE *out)
   fprintf (out, "\n\n");
   fprintf (out, "Rules\n-----\n\n");
   fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
-  for (i = 1; i < nrules + 1; i++)
+  for (i = 1; i < nrules + nuseless_productions + 1; i++)
     {
       int rhs_count = 0;
       /* Find the last RHS index in ritems. */
@@ -429,7 +422,7 @@ dump_grammar (FILE *out)
     }
   fprintf (out, "\n\n");
   fprintf (out, "Rules interpreted\n-----------------\n\n");
-  for (i = 1; i < nrules + 1; i++)
+  for (i = 1; i < nrules + nuseless_productions + 1; i++)
     {
       fprintf (out, "%-5d  %s :", i, symbols[rules[i].lhs]->tag);
       for (r = rules[i].rhs; *r >= 0; r++)
@@ -499,7 +492,8 @@ reduce_grammar (void)
     fatal (_("Start symbol %s does not derive any sentence"),
 	   symbols[start_symbol]->tag);
 
-  reduce_grammar_tables ();
+  if (nuseless_productions > 0)
+    reduce_grammar_tables ();
   if (nuseless_nonterminals > 0)
     nonterminals_reduce ();
 
