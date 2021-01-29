@@ -188,7 +188,7 @@ location_caret (location loc, FILE *out)
   /* Read the actual line.  Don't update the offset, so that we keep a pointer
      to the start of the line.  */
   {
-    char c = getc (caret_info.source);
+    int c = getc (caret_info.source);
     if (c != EOF)
       {
         /* Quote the file, indent by a single column.  */
