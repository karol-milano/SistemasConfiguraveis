@@ -20,6 +20,7 @@
 
 
 #include "system.h"
+#include "getargs.h"
 #include "warshall.h"
 
 /*-------------------------------------------------------------.
@@ -27,6 +28,51 @@
 | transive closure of what was given.                          |
 `-------------------------------------------------------------*/
 
+static void
+bitmatrix_print (const char *title, unsigned *matrix, size_t size)
+{
+  size_t i, j;
+  size_t rowsize = WORDSIZE (size) * sizeof (unsigned);
+#define ROW(Num) ((unsigned *) ((char *) matrix + ((Num) * rowsize)))
+
+  /* Title. */
+  fprintf (stderr, "%s BEGIN\n", title);
+
+  /* Column numbers. */
+  fputs ("   ", stderr);
+  for (i = 0; i < size; ++i)
+    putc (i / 10 ? '0' + i / 10 : ' ', stderr);
+  putc ('\n', stderr);
+  fputs ("   ", stderr);
+  for (i = 0; i < size; ++i)
+    fprintf (stderr, "%d", i % 10);
+  putc ('\n', stderr);
+
+  /* Bar. */
+  fputs ("  +", stderr);
+  for (i = 0; i < size; ++i)
+    putc ('-', stderr);
+  fputs ("+\n", stderr);
+
+  /* Contents. */
+  for (i = 0; i < size; ++i)
+    {
+      fprintf (stderr, "%2d|", i);
+      for (j = 0; j < size; ++j)
+	fputs (BITISSET (ROW (i), j) ? "1" : " ", stderr);
+      fputs ("|\n", stderr);
+    }
+
+  /* Bar. */
+  fputs ("  +", stderr);
+  for (i = 0; i < size; ++i)
+    putc ('-', stderr);
+  fputs ("+\n", stderr);
+
+  /* End title. */
+  fprintf (stderr, "%s END\n\n", title);
+}
+
 #define R(Num) (unsigned *) ((char *) R + ((Num) * rowsize))
 
 static void
@@ -35,12 +81,21 @@ TC (unsigned *R, int n)
   int rowsize = WORDSIZE (n) * sizeof (unsigned);
   int i, j, k;
 
+  if (trace_flag)
+    bitmatrix_print ("TC: Input", R, n);
+
+  /* R (J, I) && R (I, K) => R (J, K).
+     I *must* be the outter loop. */
+
   for (i = 0; i < n; ++i)
     for (j = 0; j < n; ++j)
-      if (BITISSET (R (i), j))
-	for (k = 0; k < rowsize; ++k)
+      if (BITISSET (R (j), i))
+	for (k = 0; k < n; ++k)
 	  if (BITISSET (R (i), k))
 	    SETBIT (R (j), k);
+
+  if (trace_flag)
+    bitmatrix_print ("TC: Output", R, n);
 }
 
 
