@@ -1,5 +1,5 @@
 /* Generate transitive closure of a matrix,
-   Copyright 1984, 1989, 2000, 2001 Free Software Foundation, Inc.
+   Copyright 1984, 1989, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -21,19 +21,17 @@
 
 #include "system.h"
 #include "getargs.h"
+#include "bitset.h"
 #include "warshall.h"
 
-/*-------------------------------------------------------------.
-| Given n by n matrix of bits R, modify its contents to be the |
-| transive closure of what was given.                          |
-`-------------------------------------------------------------*/
+/*--------------------------------------------------------.
+| Display the MATRIX array of SIZE bitsets of size SIZE.  |
+`--------------------------------------------------------*/
 
 static void
-bitmatrix_print (const char *title, unsigned *matrix, size_t size)
+bitmatrix_print (const char *title, bitset *matrix, size_t size)
 {
   size_t i, j;
-  size_t rowsize = WORDSIZE (size) * sizeof (unsigned);
-#define ROW(Num) ((unsigned *) ((char *) matrix + ((Num) * rowsize)))
 
   /* Title. */
   fprintf (stderr, "%s BEGIN\n", title);
@@ -59,7 +57,7 @@ bitmatrix_print (const char *title, unsigned *matrix, size_t size)
     {
       fprintf (stderr, "%2d|", i);
       for (j = 0; j < size; ++j)
-	fputs (BITISSET (ROW (i), j) ? "1" : " ", stderr);
+	fputs (bitset_test (matrix[i], j) ? "1" : " ", stderr);
       fputs ("|\n", stderr);
     }
 
@@ -73,44 +71,45 @@ bitmatrix_print (const char *title, unsigned *matrix, size_t size)
   fprintf (stderr, "%s END\n\n", title);
 }
 
-#define R(Num) (unsigned *) ((char *) R + ((Num) * rowsize))
+/*-------------------------------------------------------------------.
+| Given the MATRIX array of N bitsets of size N, modify its contents |
+| to be the transive closure of what was given.                      |
+`-------------------------------------------------------------------*/
 
 static void
-TC (unsigned *R, int n)
+TC (bitset *matrix, int n)
 {
-  int rowsize = WORDSIZE (n) * sizeof (unsigned);
   int i, j, k;
 
   if (trace_flag)
-    bitmatrix_print ("TC: Input", R, n);
+    bitmatrix_print ("TC: Input", matrix, n);
 
   /* R (J, I) && R (I, K) => R (J, K).
      I *must* be the outter loop. */
 
   for (i = 0; i < n; ++i)
     for (j = 0; j < n; ++j)
-      if (BITISSET (R (j), i))
+      if (bitset_test (matrix[j], i))
 	for (k = 0; k < n; ++k)
-	  if (BITISSET (R (i), k))
-	    SETBIT (R (j), k);
+	  if (bitset_test (matrix[i], k))
+	    bitset_set (matrix[j], k);
 
   if (trace_flag)
-    bitmatrix_print ("TC: Output", R, n);
+    bitmatrix_print ("TC: Output", matrix, n);
 }
 
 
 /*---------------------------------------------------------------.
 | Reflexive Transitive Closure.  Same as TC and then set all the |
-| bits on the diagonal of R.                                     |
+| bits on the diagonal of MATRIX.                                |
 `---------------------------------------------------------------*/
 
 void
-RTC (unsigned *R, int n)
+RTC (bitset *matrix, int n)
 {
-  int rowsize = WORDSIZE (n) * sizeof (unsigned);
   int i;
 
-  TC (R, n);
+  TC (matrix, n);
   for (i = 0; i < n; ++i)
-    SETBIT (R (i), i);
+    bitset_set (matrix[i], i);
 }
