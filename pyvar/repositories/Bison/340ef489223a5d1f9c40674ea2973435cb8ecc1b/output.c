@@ -993,8 +993,7 @@ pack_vector (int vector)
   i = order[vector];
   t = tally[i];
 
-  if (t == 0)
-    berror ("pack_vector");
+  assert (t);
 
   from = froms[i];
   to = tos[i];
