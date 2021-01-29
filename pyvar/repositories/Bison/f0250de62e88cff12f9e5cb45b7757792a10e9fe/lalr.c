@@ -141,10 +141,7 @@ initialize_LA (void)
 
   LA = XCALLOC (bitset, nLA);
   for (i = 0; i < nLA; ++i)
-    {
-      LA[i] = bitset_create (ntokens, BITSET_FIXED);
-      bitset_zero (LA[i]);
-    }
+    LA[i] = bitset_create (ntokens, BITSET_FIXED);
   LAruleno = XCALLOC (short, nLA);
   lookback = XCALLOC (shorts *, nLA);
 
@@ -258,10 +255,7 @@ initialize_F (void)
 
   F = XCALLOC (bitset, ngotos);
   for (i = 0; i < ngotos; ++i)
-    {
-      F[i] = bitset_create (ntokens, BITSET_FIXED);
-      bitset_zero (F[i]);
-    }
+    F[i] = bitset_create (ntokens, BITSET_FIXED);
 
   for (i = 0; i < ngotos; i++)
     {
