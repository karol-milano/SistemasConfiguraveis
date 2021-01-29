@@ -56,7 +56,7 @@ bitsetv_matrix_dump (FILE * out, const char *title, bitsetv bset)
     {
       fprintf (out, "%2lu|", (unsigned long int) i);
       for (j = 0; j < hsize; ++j)
-	fputs (bitset_test (bset[i], j) ? "1" : " ", out);
+        fputs (bitset_test (bset[i], j) ? "1" : " ", out);
       fputs ("|\n", out);
     }
 
