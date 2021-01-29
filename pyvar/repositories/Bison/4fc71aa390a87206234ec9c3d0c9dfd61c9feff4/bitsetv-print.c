@@ -1,5 +1,5 @@
 /* Bitset vectors.
-   Copyright (C) 2001 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002 Free Software Foundation, Inc.
 
 This file is part of Bison.
 
@@ -32,8 +32,8 @@ Software Foundation, 59 Temple Place - Suite 330, Boston, MA
 void
 bitsetv_matrix_dump (FILE * out, const char *title, bitsetv bset)
 {
-  size_t i, j;
-  size_t hsize = bitset_size (bset[0]);
+  bitset_bindex i, j;
+  bitset_bindex hsize = bitset_size (bset[0]);
 
   /* Title. */
   fprintf (out, "%s BEGIN\n", title);
@@ -45,7 +45,7 @@ bitsetv_matrix_dump (FILE * out, const char *title, bitsetv bset)
   putc ('\n', out);
   fputs ("   ", out);
   for (i = 0; i < hsize; ++i)
-    fprintf (out, "%d", i % 10);
+    fprintf (out, "%d", (int) (i % 10));
   putc ('\n', out);
 
   /* Bar. */
@@ -57,7 +57,7 @@ bitsetv_matrix_dump (FILE * out, const char *title, bitsetv bset)
   /* Contents. */
   for (i = 0; bset[i]; ++i)
     {
-      fprintf (out, "%2d|", i);
+      fprintf (out, "%2lu|", (unsigned long) i);
       for (j = 0; j < hsize; ++j)
 	fputs (bitset_test (bset[i], j) ? "1" : " ", out);
       fputs ("|\n", out);
