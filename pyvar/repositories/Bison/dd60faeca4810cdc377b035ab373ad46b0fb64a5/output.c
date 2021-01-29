@@ -1302,11 +1302,13 @@ output (void)
   int c;
 
   /* output_token_defines(ftable);      / * JF put out token defines FIRST */
-  if (!semantic_parser)		/* JF Put out other stuff */
+
+  /* If using a simple parser the definition of YYSTYPE are put into
+     FTABLE.  */
+  if (!semantic_parser)
     {
-      rewind (fattrs);
-      while ((c = getc (fattrs)) != EOF)
-	putc (c, ftable);
+      size_t size = obstack_object_size (&attrs_obstack);
+      fwrite (obstack_finish (&attrs_obstack), 1, size, ftable);
     }
   reader_output_yylsp (ftable);
   if (debug_flag)
