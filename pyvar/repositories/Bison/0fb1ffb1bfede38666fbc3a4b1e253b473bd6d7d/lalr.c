@@ -51,8 +51,7 @@ short *to_state = NULL;
 
 /* And for the famous F variable, which name is so descriptive that a
    comment is hardly needed.  <grin>.  */
-static unsigned *F = NULL;
-#define F(Rule)  (F + (Rule) * tokensetsize)
+static bitset *F = NULL;
 
 static short **includes;
 static shorts **lookback;
@@ -75,9 +74,7 @@ static void
 traverse (int i)
 {
   int j;
-  size_t k;
   int height;
-  size_t size = F (i + 1) - F(i);
 
   VERTICES[++top] = i;
   INDEX[i] = height = top;
@@ -91,8 +88,7 @@ traverse (int i)
 	if (INDEX[i] > INDEX[R[i][j]])
 	  INDEX[i] = INDEX[R[i][j]];
 
-	for (k = 0; k < size; ++k)
-	  F (i)[k] |= F (R[i][j])[k];
+	bitset_or (F[i], F[i], F[R[i][j]]);
       }
 
   if (INDEX[i] == height)
@@ -104,8 +100,7 @@ traverse (int i)
 	if (i == j)
 	  break;
 
-	for (k = 0; k < size; ++k)
-	  F (j)[k] = F (i)[k];
+	bitset_copy (F[j], F[i]);
       }
 }
 
@@ -262,7 +257,12 @@ initialize_F (void)
 
   int i;
 
-  F = XCALLOC (unsigned, ngotos * tokensetsize);
+  F = XCALLOC (bitset, ngotos);
+  for (i = 0; i < ngotos; ++i)
+    {
+      F[i] = bitset_create (ntokens, BITSET_FIXED);
+      bitset_zero (F[i]);
+    }
 
   for (i = 0; i < ngotos; i++)
     {
@@ -271,7 +271,7 @@ initialize_F (void)
 
       int j;
       for (j = 0; j < sp->nshifts && SHIFT_IS_SHIFT (sp, j); j++)
-	SETBIT (F (i), SHIFT_SYMBOL (sp, j));
+	bitset_set (F[i], SHIFT_SYMBOL (sp, j));
 
       for (; j < sp->nshifts; j++)
 	{
@@ -500,18 +500,15 @@ compute_lookaheads (void)
 
   for (i = 0; i < nLA; i++)
     for (sp = lookback[i]; sp; sp = sp->next)
-      {
-	int j;
-	for (j = 0; j < ntokens; ++j)
-	  if (BITISSET (F (sp->value), j))
-	    bitset_set (LA[i], j);
-      }
+      bitset_or (LA[i], LA[i], F[sp->value]);
 
   /* Free LOOKBACK. */
   for (i = 0; i < nLA; i++)
     LIST_FREE (shorts, lookback[i]);
 
   XFREE (lookback);
+  for (i = 0; i < (unsigned) ngotos; ++i)
+    bitset_free (F[i]);
   XFREE (F);
 }
 
