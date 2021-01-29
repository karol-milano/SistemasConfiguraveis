@@ -54,7 +54,7 @@ bitsetv_matrix_dump (FILE * out, const char *title, bitsetv bset)
   /* Contents. */
   for (i = 0; bset[i]; ++i)
     {
-      fprintf (out, "%2lu|", (unsigned long int) i);
+      fprintf (out, "%2lu|", (unsigned long) i);
       for (j = 0; j < hsize; ++j)
         fputs (bitset_test (bset[i], j) ? "1" : " ", out);
       fputs ("|\n", out);
