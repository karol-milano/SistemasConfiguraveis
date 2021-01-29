@@ -407,50 +407,46 @@ nonterminals_reduce (void)
 void
 reduce_output (FILE *out)
 {
-  int i;
-  rule r;
-  bool b;
-
   if (nuseless_nonterminals > 0)
     {
-      fprintf (out, _("Useless nonterminals:"));
-      fprintf (out, "\n\n");
+      int i;
+      fprintf (out, "%s\n\n", _("Useless nonterminals:"));
       for (i = 0; i < nuseless_nonterminals; ++i)
 	fprintf (out, "   %s\n", tags[nsyms + i]);
+      fputs ("\n\n", out);
     }
-  b = FALSE;
-  for (i = 0; i < ntokens; i++)
-    {
+
+  {
+    bool b = FALSE;
+    int i;
+    for (i = 0; i < ntokens; i++)
       if (!BITISSET (V, i) && !BITISSET (V1, i))
 	{
 	  if (!b)
-	    {
-	      fprintf (out, "\n\n");
-	      fprintf (out, _("Terminals which are not used:"));
-	      fprintf (out, "\n\n");
-	      b = TRUE;
-	    }
+	    fprintf (out, "%s\n\n", _("Terminals which are not used:"));
+	  b = TRUE;
 	  fprintf (out, "   %s\n", tags[i]);
 	}
-    }
+    if (b)
+      fputs ("\n\n", out);
+  }
 
   if (nuseless_productions > 0)
     {
-      fprintf (out, "\n\n");
-      fprintf (out, _("Useless rules:"));
-      fprintf (out, "\n\n");
+      int i;
+      fprintf (out, "%s\n\n", _("Useless rules:"));
       for (i = 1; i <= nrules; i++)
 	if (!BITISSET (P, i))
 	  {
+	    rule r;
 	    fprintf (out, "#%-4d  ", i);
 	    fprintf (out, "%s :\t", tags[rule_table[i].lhs]);
 	    for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
 	      fprintf (out, " %s", tags[*r]);
-	    fprintf (out, ";\n");
+	    fputs (";\n", out);
 	  }
+      fputs ("\n\n", out);
     }
-  if (nuseless_nonterminals > 0 || nuseless_productions > 0 || b)
-    fprintf (out, "\n\n");
 }
 
 static void
