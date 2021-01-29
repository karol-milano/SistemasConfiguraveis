@@ -128,10 +128,7 @@ set_firsts (void)
       {
 	int symbol = ritem[rule_table[derives[i][j]].rhs];
 	if (ISVAR (symbol))
-	  {
-	    symbol -= ntokens;
-	    SETBIT (FIRSTS (i - ntokens), symbol);
-	  }
+	  SETBIT (FIRSTS (i - ntokens), symbol - ntokens);
       }
 
   RTC (firsts, nvars);
@@ -153,46 +150,17 @@ set_firsts (void)
 static void
 set_fderives (void)
 {
-  unsigned *rrow;
-  unsigned *vrow;
-  int j;
-  unsigned cword;
-  short *rp;
-  int b;
-
-  int ruleno;
-  int i;
+  int i, j, k;
 
   fderives = XCALLOC (unsigned, nvars * rulesetsize) - ntokens * rulesetsize;
 
   set_firsts ();
 
-  rrow = FDERIVES (ntokens);
-
-  for (i = ntokens; i < nsyms; i++)
-    {
-      vrow = FIRSTS (i - ntokens);
-      cword = *vrow++;
-      b = 0;
-      for (j = ntokens; j < nsyms; j++)
-	{
-	  if (cword & (1 << b))
-	    {
-	      rp = derives[j];
-	      while ((ruleno = *rp++) > 0)
-		SETBIT (rrow, ruleno);
-	    }
-
-	  b++;
-	  if (b >= BITS_PER_WORD && j + 1 < nsyms)
-	    {
-	      cword = *vrow++;
-	      b = 0;
-	    }
-	}
-
-      rrow += rulesetsize;
-    }
+  for (i = ntokens; i < nsyms; ++i)
+    for (j = ntokens; j < nsyms; ++j)
+      if (BITISSET (FIRSTS (i - ntokens), j - ntokens))
+	for (k = 0; derives[j][k] > 0; ++k)
+	  SETBIT (FDERIVES (i), derives[j][k]);
 
   if (trace_flag)
     print_fderives ();
