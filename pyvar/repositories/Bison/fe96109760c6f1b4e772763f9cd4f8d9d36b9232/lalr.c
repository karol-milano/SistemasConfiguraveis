@@ -50,7 +50,7 @@ extern void berror PARAMS ((const char *));
 static int infinity;
 static int ngotos;
 
-/* And for the famous F variable, which named is so descriptive that a
+/* And for the famous F variable, which name is so descriptive that a
    comment is hardly needed.  <grin>.  */
 static unsigned *F = NULL;
 #define F(Rule)  (F + (Rule) * tokensetsize)
@@ -66,57 +66,39 @@ static int top;
 static void
 traverse (int i)
 {
-  unsigned *fp1;
-  unsigned *fp2;
-  unsigned *fp3;
   int j;
-  short *rp;
-
+  size_t k;
   int height;
-  unsigned *base;
+  size_t size = F (i + 1) - F(i);
 
   VERTICES[++top] = i;
   INDEX[i] = height = top;
 
-  base = F (i);
-  fp3 = F (i + 1);
-
-  rp = R[i];
-  if (rp)
-    {
-      while ((j = *rp++) >= 0)
-	{
-	  if (INDEX[j] == 0)
-	    traverse (j);
-
-	  if (INDEX[i] > INDEX[j])
-	    INDEX[i] = INDEX[j];
+  if (R[i])
+    for (j = 0; R[i][j] >= 0; ++j)
+      {
+	if (INDEX[R[i][j]] == 0)
+	  traverse (R[i][j]);
 
-	  fp1 = base;
-	  fp2 = F (j);
+	if (INDEX[i] > INDEX[R[i][j]])
+	  INDEX[i] = INDEX[R[i][j]];
 
-	  while (fp1 < fp3)
-	    *fp1++ |= *fp2++;
-	}
-    }
+	for (k = 0; k < size; ++k)
+	  F (i)[k] |= F (R[i][j])[k];
+      }
 
   if (INDEX[i] == height)
-    {
-      for (;;)
-	{
-	  j = VERTICES[top--];
-	  INDEX[j] = infinity;
-
-	  if (i == j)
-	    break;
+    for (;;)
+      {
+	j = VERTICES[top--];
+	INDEX[j] = infinity;
 
-	  fp1 = base;
-	  fp2 = F (j);
+	if (i == j)
+	  break;
 
-	  while (fp1 < fp3)
-	    *fp2++ = *fp1++;
-	}
-    }
+	for (k = 0; k < size; ++k)
+	  F (i)[k] = F (j)[k];
+      }
 }
 
 
@@ -212,7 +194,10 @@ set_state_table (void)
 }
 
 
-/* Return the size of the longest ride hand side of the rules. */
+/*------------------------------------------.
+| Return the size of the longest rule RHS.  |
+`------------------------------------------*/
+
 static size_t
 maxrhs (void)
 {
