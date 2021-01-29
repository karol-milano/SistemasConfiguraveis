@@ -698,7 +698,7 @@ pack_vector (vector_number vector)
 
       if (ok)
         {
-          int loc;
+          int loc PACIFY_CC (= -1);
           int k;
           for (k = 0; k < t; k++)
             {
