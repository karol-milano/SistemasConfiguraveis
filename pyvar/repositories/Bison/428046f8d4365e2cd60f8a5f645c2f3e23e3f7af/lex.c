@@ -130,7 +130,7 @@ skip_white_space (void)
 | Do a getc, but give error message if EOF encountered |
 `-----------------------------------------------------*/
 
-static int
+int
 xgetc (FILE *f)
 {
   int c = getc (f);
