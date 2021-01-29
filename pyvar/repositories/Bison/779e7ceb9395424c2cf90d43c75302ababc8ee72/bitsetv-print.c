@@ -1,5 +1,5 @@
 /* Bitset vectors.
-   Copyright (C) 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 2001, 2002, 2004 Free Software Foundation, Inc.
 
 This file is part of Bison.
 
@@ -57,7 +57,7 @@ bitsetv_matrix_dump (FILE * out, const char *title, bitsetv bset)
   /* Contents. */
   for (i = 0; bset[i]; ++i)
     {
-      fprintf (out, "%2lu|", (unsigned long) i);
+      fprintf (out, "%2lu|", (unsigned long int) i);
       for (j = 0; j < hsize; ++j)
 	fputs (bitset_test (bset[i], j) ? "1" : " ", out);
       fputs ("|\n", out);
