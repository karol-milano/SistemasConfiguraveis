@@ -1,5 +1,5 @@
 /* Generate transitive closure of a matrix,
-   Copyright 1984, 1989, 2000 Free Software Foundation, Inc.
+   Copyright 1984, 1989, 2000, 2001 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -22,93 +22,40 @@
 #include "system.h"
 #include "warshall.h"
 
-/* Given n by n matrix of bits R, modify its contents to be the
-   transive closure of what was given.  */
+/*-------------------------------------------------------------.
+| Given n by n matrix of bits R, modify its contents to be the |
+| transive closure of what was given.                          |
+`-------------------------------------------------------------*/
+
+#define R(Num) (unsigned *) ((char *) R + ((Num) * rowsize))
 
 static void
 TC (unsigned *R, int n)
 {
-  int rowsize;
-  unsigned mask;
-  unsigned *rowj;
-  unsigned *rp;
-  unsigned *rend;
-  unsigned *ccol;
-
-  unsigned *relend;
-  unsigned *cword;
-  unsigned *rowi;
-
-  rowsize = WORDSIZE(n) * sizeof(unsigned);
-  relend = (unsigned *) ((char *) R + (n * rowsize));
-
-  cword = R;
-  mask = 1;
-  rowi = R;
-  while (rowi < relend)
-    {
-      ccol = cword;
-      rowj = R;
-
-      while (rowj < relend)
-	{
-	  if (*ccol & mask)
-	    {
-	      rp = rowi;
-	      rend = (unsigned *) ((char *) rowj + rowsize);
-
-	      while (rowj < rend)
-		*rowj++ |= *rp++;
-	    }
-	  else
-	    {
-	      rowj = (unsigned *) ((char *) rowj + rowsize);
-	    }
-
-	  ccol = (unsigned *) ((char *) ccol + rowsize);
-	}
-
-      mask <<= 1;
-      if (mask == 0)
-	{
-	  mask = 1;
-	  cword++;
-	}
-
-      rowi = (unsigned *) ((char *) rowi + rowsize);
-    }
+  int rowsize = WORDSIZE (n) * sizeof (unsigned);
+  int i, j, k;
+
+  for (i = 0; i < n; ++i)
+    for (j = 0; j < n; ++j)
+      if (BITISSET (R (i), j))
+	for (k = 0; k < rowsize; ++k)
+	  if (BITISSET (R (i), k))
+	    SETBIT (R (j), k);
 }
 
 
-/* Reflexive Transitive Closure.  Same as TC
-   and then set all the bits on the diagonal of R.  */
+/*---------------------------------------------------------------.
+| Reflexive Transitive Closure.  Same as TC and then set all the |
+| bits on the diagonal of R.                                     |
+`---------------------------------------------------------------*/
 
 void
 RTC (unsigned *R, int n)
 {
-  int rowsize;
-  unsigned mask;
-  unsigned *rp;
-  unsigned *relend;
-
-  TC(R, n);
-
-  rowsize = WORDSIZE(n) * sizeof(unsigned);
-  relend = (unsigned *) ((char *) R + n*rowsize);
-
-  mask = 1;
-  rp = R;
-  while (rp < relend)
-    {
-      *rp |= mask;
-
-      mask <<= 1;
-      if (mask == 0)
-	{
-	  mask = 1;
-	  rp++;
-	}
+  int rowsize = WORDSIZE (n) * sizeof (unsigned);
+  int i;
 
-      rp = (unsigned *) ((char *) rp + rowsize);
-    }
+  TC (R, n);
+  for (i = 0; i < n; ++i)
+    SETBIT (R (i), i);
 }
