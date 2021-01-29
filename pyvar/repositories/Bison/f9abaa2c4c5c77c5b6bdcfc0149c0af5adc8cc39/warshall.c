@@ -79,7 +79,7 @@ bitmatrix_print (const char *title, bitset *matrix, size_t size)
 static void
 TC (bitset *matrix, int n)
 {
-  int i, j, k;
+  int i, j;
 
   if (trace_flag)
     bitmatrix_print ("TC: Input", matrix, n);
@@ -90,9 +90,7 @@ TC (bitset *matrix, int n)
   for (i = 0; i < n; ++i)
     for (j = 0; j < n; ++j)
       if (bitset_test (matrix[j], i))
-	for (k = 0; k < n; ++k)
-	  if (bitset_test (matrix[i], k))
-	    bitset_set (matrix[j], k);
+	bitset_or (matrix[j], matrix[j], matrix[i]);
 
   if (trace_flag)
     bitmatrix_print ("TC: Output", matrix, n);
