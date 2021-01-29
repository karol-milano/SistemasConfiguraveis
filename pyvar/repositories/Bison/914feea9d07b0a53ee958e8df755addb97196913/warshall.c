@@ -21,7 +21,7 @@
 
 #include "system.h"
 #include "getargs.h"
-#include "bitset.h"
+#include "bitsetv.h"
 #include "warshall.h"
 
 /*--------------------------------------------------------.
@@ -29,9 +29,10 @@
 `--------------------------------------------------------*/
 
 static void
-bitmatrix_print (const char *title, bitset *matrix, size_t size)
+bitmatrix_print (const char *title, bitsetv matrix)
 {
   size_t i, j;
+  size_t size = bitset_size (matrix[0]);
 
   /* Title. */
   fprintf (stderr, "%s BEGIN\n", title);
@@ -77,23 +78,23 @@ bitmatrix_print (const char *title, bitset *matrix, size_t size)
 `-------------------------------------------------------------------*/
 
 static void
-TC (bitset *matrix, int n)
+TC (bitsetv matrix)
 {
   int i, j;
 
   if (trace_flag)
-    bitmatrix_print ("TC: Input", matrix, n);
+    bitmatrix_print ("TC: Input", matrix);
 
   /* R (J, I) && R (I, K) => R (J, K).
      I *must* be the outter loop. */
 
-  for (i = 0; i < n; ++i)
-    for (j = 0; j < n; ++j)
+  for (i = 0; matrix[i]; ++i)
+    for (j = 0; matrix[j]; ++j)
       if (bitset_test (matrix[j], i))
 	bitset_or (matrix[j], matrix[j], matrix[i]);
 
   if (trace_flag)
-    bitmatrix_print ("TC: Output", matrix, n);
+    bitmatrix_print ("TC: Output", matrix);
 }
 
 
@@ -103,11 +104,11 @@ TC (bitset *matrix, int n)
 `---------------------------------------------------------------*/
 
 void
-RTC (bitset *matrix, int n)
+RTC (bitsetv matrix)
 {
   int i;
 
-  TC (matrix, n);
-  for (i = 0; i < n; ++i)
+  TC (matrix);
+  for (i = 0; matrix[i]; ++i)
     bitset_set (matrix[i], i);
 }
