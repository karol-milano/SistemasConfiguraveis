@@ -353,7 +353,7 @@ bitset_count_ (bitset src)
   {
     bitset_bindex next = 0;
     bitset_bindex num;
-    while (num = bitset_list (src, list, BITSET_LIST_SIZE, &next))
+    while ((num = bitset_list (src, list, BITSET_LIST_SIZE, &next)))
       count += num;
   }
 
