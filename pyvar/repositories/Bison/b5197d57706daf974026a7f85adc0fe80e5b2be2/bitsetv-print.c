@@ -29,7 +29,6 @@
 void
 bitsetv_matrix_dump (FILE * out, const char *title, bitsetv bset)
 {
-  bitset_bindex i, j;
   bitset_bindex hsize = bitset_size (bset[0]);
 
   /* Title. */
@@ -37,32 +36,32 @@ bitsetv_matrix_dump (FILE * out, const char *title, bitsetv bset)
 
   /* Column numbers. */
   fputs ("   ", out);
-  for (i = 0; i < hsize; ++i)
+  for (bitset_bindex i = 0; i < hsize; ++i)
     putc (i / 10 ? '0' + i / 10 : ' ', out);
   putc ('\n', out);
   fputs ("   ", out);
-  for (i = 0; i < hsize; ++i)
+  for (bitset_bindex i = 0; i < hsize; ++i)
     fprintf (out, "%d", (int) (i % 10));
   putc ('\n', out);
 
   /* Bar. */
   fputs ("  .", out);
-  for (i = 0; i < hsize; ++i)
+  for (bitset_bindex i = 0; i < hsize; ++i)
     putc ('-', out);
   fputs (".\n", out);
 
   /* Contents. */
-  for (i = 0; bset[i]; ++i)
+  for (bitset_bindex i = 0; bset[i]; ++i)
     {
       fprintf (out, "%2lu|", (unsigned long) i);
-      for (j = 0; j < hsize; ++j)
+      for (bitset_bindex j = 0; j < hsize; ++j)
         fputs (bitset_test (bset[i], j) ? "1" : " ", out);
       fputs ("|\n", out);
     }
 
   /* Bar. */
   fputs ("  `", out);
-  for (i = 0; i < hsize; ++i)
+  for (bitset_bindex i = 0; i < hsize; ++i)
     putc ('-', out);
   fputs ("'\n", out);
 
