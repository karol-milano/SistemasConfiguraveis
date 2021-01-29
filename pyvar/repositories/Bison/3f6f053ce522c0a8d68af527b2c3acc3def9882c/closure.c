@@ -124,33 +124,24 @@ print_fderives (void)
 static void
 set_firsts (void)
 {
-  unsigned *row;
-  int symbol;
-  short *sp;
   int rowsize;
 
-  int i;
+  int i, j;
 
   varsetsize = rowsize = WORDSIZE (nvars);
 
   firsts = XCALLOC (unsigned, nvars * rowsize);
 
-  row = firsts;
   for (i = ntokens; i < nsyms; i++)
-    {
-      sp = derives[i];
-      while (*sp >= 0)
-	{
-	  symbol = ritem[rule_table[*sp++].rhs];
-	  if (ISVAR (symbol))
-	    {
-	      symbol -= ntokens;
-	      SETBIT (row, symbol);
-	    }
-	}
-
-      row += rowsize;
-    }
+    for (j = 0; derives[i][j] >= 0; ++j)
+      {
+	int symbol = ritem[rule_table[derives[i][j]].rhs];
+	if (ISVAR (symbol))
+	  {
+	    symbol -= ntokens;
+	    SETBIT (FIRSTS (i - ntokens), symbol);
+	  }
+      }
 
   RTC (firsts, nvars);
 
