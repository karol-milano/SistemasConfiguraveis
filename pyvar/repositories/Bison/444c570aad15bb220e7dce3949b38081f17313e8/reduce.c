@@ -401,7 +401,8 @@ print_results (void)
 
   if (nuseless_nonterminals > 0)
     {
-      fprintf (foutput, _("Useless nonterminals:\n\n"));
+      fputs (_("Useless nonterminals:"), foutput);
+      fputs ("\n\n", foutput);
       for (i = ntokens; i < nsyms; i++)
 	if (!BITISSET (V, i))
 	  fprintf (foutput, "   %s\n", tags[i]);
@@ -413,7 +414,9 @@ print_results (void)
 	{
 	  if (!b)
 	    {
-	      fprintf (foutput, _("\n\nTerminals which are not used:\n\n"));
+	      fputs ("\n\n", foutput);
+	      fprintf (foutput, _("Terminals which are not used:"));
+	      fputs ("\n\n", foutput);
 	      b = TRUE;
 	    }
 	  fprintf (foutput, "   %s\n", tags[i]);
@@ -422,7 +425,9 @@ print_results (void)
 
   if (nuseless_productions > 0)
     {
-      fprintf (foutput, _("\n\nUseless rules:\n\n"));
+      fputs ("\n\n", foutput);
+      fprintf (foutput, _("Useless rules:"));
+      fputs ("\n\n", foutput);
       for (i = 1; i <= nrules; i++)
 	{
 	  if (!BITISSET (P, i))
@@ -438,7 +443,7 @@ print_results (void)
 	}
     }
   if (nuseless_nonterminals > 0 || nuseless_productions > 0 || b)
-    fprintf (foutput, "\n\n");
+    fputs ("\n\n", foutput);
 }
 
 #if 0				/* XXX currently unused.  */
