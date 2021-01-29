@@ -49,10 +49,10 @@ bitmatrix_print (const char *title, unsigned *matrix, size_t size)
   putc ('\n', stderr);
 
   /* Bar. */
-  fputs ("  +", stderr);
+  fputs ("  .", stderr);
   for (i = 0; i < size; ++i)
     putc ('-', stderr);
-  fputs ("+\n", stderr);
+  fputs (".\n", stderr);
 
   /* Contents. */
   for (i = 0; i < size; ++i)
@@ -64,10 +64,10 @@ bitmatrix_print (const char *title, unsigned *matrix, size_t size)
     }
 
   /* Bar. */
-  fputs ("  +", stderr);
+  fputs ("  `", stderr);
   for (i = 0; i < size; ++i)
     putc ('-', stderr);
-  fputs ("+\n", stderr);
+  fputs ("'\n", stderr);
 
   /* End title. */
   fprintf (stderr, "%s END\n\n", title);
