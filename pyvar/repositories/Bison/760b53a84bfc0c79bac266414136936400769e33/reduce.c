@@ -342,26 +342,38 @@ nonterminals_reduce (void)
      in the map means it was useless and is being eliminated.  */
 
   short *nontermmap = XCALLOC (short, nvars) - ntokens;
-  for (i = ntokens; i < nsyms; i++)
-    nontermmap[i] = -1;
-
   n = ntokens;
   for (i = ntokens; i < nsyms; i++)
     if (BITISSET (V, i))
       nontermmap[i] = n++;
+  for (i = ntokens; i < nsyms; i++)
+    if (!BITISSET (V, i))
+      nontermmap[i] = n++;
 
-  /* Shuffle elements of tables indexed by symbol number.  */
 
-  for (i = ntokens; i < nsyms; i++)
-    {
-      n = nontermmap[i];
-      if (n >= 0)
-	{
-	  sassoc[n] = sassoc[i];
-	  sprec[n] = sprec[i];
-	  tags[n] = tags[i];
-	}
-    }
+  /* Shuffle elements of tables indexed by symbol number.  */
+  {
+    short *sassoc_sorted = XMALLOC (short, nvars) - ntokens;
+    short *sprec_sorted  = XMALLOC (short, nvars) - ntokens;
+    char **tags_sorted   = XMALLOC (char *, nvars) - ntokens;
+
+    for (i = ntokens; i < nsyms; i++)
+      {
+	n = nontermmap[i];
+	sassoc_sorted[n] = sassoc[i];
+	sprec_sorted[n]  = sprec[i];
+	tags_sorted[n]   = tags[i];
+      }
+    for (i = ntokens; i < nsyms; i++)
+      {
+	sassoc[i] = sassoc_sorted[i];
+	sprec[i]  = sprec_sorted[i];
+	tags[i]   = tags_sorted[i];
+      }
+    free (sassoc_sorted + ntokens);
+    free (sprec_sorted + ntokens);
+    free (tags_sorted + ntokens);
+  }
 
   /* Replace all symbol numbers in valid data structures.  */
 
@@ -403,9 +415,8 @@ reduce_output (FILE *out)
     {
       fprintf (out, _("Useless nonterminals:"));
       fprintf (out, "\n\n");
-      for (i = ntokens; i < nsyms; i++)
-	if (!BITISSET (V, i))
-	  fprintf (out, "   %s\n", tags[i]);
+      for (i = 0; i < nuseless_nonterminals; ++i)
+	fprintf (out, "   %s\n", tags[nsyms + i]);
     }
   b = FALSE;
   for (i = 0; i < ntokens; i++)
