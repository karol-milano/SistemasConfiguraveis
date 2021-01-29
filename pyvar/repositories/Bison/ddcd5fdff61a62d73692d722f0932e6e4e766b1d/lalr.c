@@ -50,7 +50,12 @@ extern void berror PARAMS ((const char *));
 static int infinity;
 static int maxrhs;
 static int ngotos;
-static unsigned *F;
+
+/* And for the famous F variable, which named is so descriptive that a
+   comment is hardly needed.  <grin>.  */
+static unsigned *F = NULL;
+#define F(Rule)  (F + (Rule) * tokensetsize)
+
 static short **includes;
 static shorts **lookback;
 static short **R;
@@ -74,8 +79,8 @@ traverse (int i)
   VERTICES[++top] = i;
   INDEX[i] = height = top;
 
-  base = F + i * tokensetsize;
-  fp3 = base + tokensetsize;
+  base = F (i);
+  fp3 = F (i + 1);
 
   rp = R[i];
   if (rp)
@@ -89,7 +94,7 @@ traverse (int i)
 	    INDEX[i] = INDEX[j];
 
 	  fp1 = base;
-	  fp2 = F + j * tokensetsize;
+	  fp2 = F (j);
 
 	  while (fp1 < fp3)
 	    *fp1++ |= *fp2++;
@@ -107,7 +112,7 @@ traverse (int i)
 	    break;
 
 	  fp1 = base;
-	  fp2 = F + j * tokensetsize;
+	  fp2 = F (j);
 
 	  while (fp1 < fp3)
 	    *fp2++ = *fp1++;
@@ -132,10 +137,8 @@ digraph (short **relation)
     INDEX[i] = 0;
 
   for (i = 0; i < ngotos; i++)
-    {
-      if (INDEX[i] == 0 && R[i])
-	traverse (i);
-    }
+    if (INDEX[i] == 0 && R[i])
+      traverse (i);
 
   XFREE (INDEX);
   XFREE (VERTICES);
@@ -431,10 +434,7 @@ initialize_F (void)
   digraph (reads);
 
   for (i = 0; i < ngotos; i++)
-    {
-      if (reads[i])
-	XFREE (reads[i]);
-    }
+    XFREE (reads[i]);
 
   XFREE (reads);
   XFREE (edge);
@@ -630,10 +630,7 @@ compute_FOLLOWS (void)
   digraph (includes);
 
   for (i = 0; i < ngotos; i++)
-    {
-      if (includes[i])
-	XFREE (includes[i]);
-    }
+    XFREE (includes[i]);
 
   XFREE (includes);
 }
@@ -643,28 +640,21 @@ static void
 compute_lookaheads (void)
 {
   int i;
-  int n;
-  unsigned *fp1;
-  unsigned *fp2;
-  unsigned *fp3;
   shorts *sp;
-  shorts *sptmp;		/* JF */
 
   for (i = 0; i < state_table[nstates].lookaheads; i++)
-    {
-      fp3 = LA (i + 1);
-      for (sp = lookback[i]; sp; sp = sp->next)
-	{
-	  fp1 = LA (i);
-	  fp2 = F + tokensetsize * sp->value;
-	  while (fp1 < fp3)
-	    *fp1++ |= *fp2++;
-	}
-    }
+    for (sp = lookback[i]; sp; sp = sp->next)
+      {
+	unsigned *fp1 = LA (i);
+	unsigned *fp2 = F (sp->value);
+	while (fp1 < LA (i + 1))
+	  *fp1++ |= *fp2++;
+      }
 
+  /* Free LOOKBACK. */
   for (i = 0; i < state_table[nstates].lookaheads; i++)
     {
-      /* JF removed ref to freed storage */
+      shorts *sptmp;
       for (sp = lookback[i]; sp; sp = sptmp)
 	{
 	  sptmp = sp->next;
