@@ -1071,7 +1071,7 @@ vbitset_or_and_cmp (bitset dst, bitset src1, bitset src2, bitset src3)
 }
 
 
-void
+static void
 vbitset_copy (bitset dst, bitset src)
 {
   if (BITSET_COMPATIBLE_ (dst, src))
