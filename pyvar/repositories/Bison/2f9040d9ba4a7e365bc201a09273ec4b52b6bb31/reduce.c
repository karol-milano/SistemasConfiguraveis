@@ -93,7 +93,7 @@ unsigned i;
   int count = 0;
 
   while (i != 0) {
-    i ^= (i & -i);
+    i ^= (i & ((unsigned) (- (int) i)));
     ++count;
   }
   return count;
