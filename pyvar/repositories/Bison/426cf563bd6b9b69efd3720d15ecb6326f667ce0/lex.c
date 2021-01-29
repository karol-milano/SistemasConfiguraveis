@@ -152,7 +152,7 @@ xgetc (FILE *f)
    being, I prefer have literalchar behave like quotearg, and change
    my mind later if I was wrong.  */
 
-static int
+int
 literalchar (struct obstack *out, int *pcode, char term)
 {
   int c;
