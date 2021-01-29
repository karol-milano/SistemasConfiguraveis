@@ -169,9 +169,8 @@ static struct
   FILE *source;
   /* The last file we tried to open.  If non NULL, but SOURCE is NULL,
      it means this file is special and should not be quoted. */
-  uniqstr file;
-  size_t line;
-  /* Offset in SOURCE where line LINE starts.  */
+  boundary pos;
+  /* Offset in SOURCE where line POS.LINE starts.  */
   size_t offset;
 } caret_info;
 
@@ -181,26 +180,26 @@ caret_set_file (const char *file)
 {
   /* If a different source than before, close and let the rest open
      the new one. */
-  if (caret_info.file && caret_info.file != file)
+  if (caret_info.pos.file && caret_info.pos.file != file)
     {
       caret_free ();
-      caret_info.file = NULL;
+      caret_info.pos.file = NULL;
     }
-  if (!caret_info.file)
+  if (!caret_info.pos.file)
     {
-      caret_info.file = file;
-      if ((caret_info.source = fopen (caret_info.file, "r")))
+      caret_info.pos.file = file;
+      if ((caret_info.source = fopen (caret_info.pos.file, "r")))
         {
           /* If the file is not regular (imagine #line 1 "/dev/stdin"
              in the input file for instance), don't try to quote the
              source.  Keep caret_info.file set so that we don't try to
-             open it again, but leave caret_info.source NULL so that
-             we don't try to quote it. */
+             open it again, but leave caret_info.file NULL so that we
+             don't try to quote it. */
           struct stat buf;
           if (fstat (fileno (caret_info.source), &buf) == 0
               && buf.st_mode & S_IFREG)
             {
-              caret_info.line = 1;
+              caret_info.pos.line = 1;
               caret_info.offset = 0;
             }
           else
@@ -249,21 +248,21 @@ location_caret (location loc, const char *style, FILE *out)
   /* If the line we want to quote is seekable (the same line as the previous
      location), just seek it. If it was a previous line, we lost track of it,
      so return to the start of file.  */
-  if (loc.start.line < caret_info.line)
+  if (loc.start.line < caret_info.pos.line)
     {
-      caret_info.line = 1;
+      caret_info.pos.line = 1;
       caret_info.offset = 0;
     }
   fseek (caret_info.source, caret_info.offset, SEEK_SET);
 
   /* Advance to the line's position, keeping track of the offset.  */
-  while (caret_info.line < loc.start.line)
+  while (caret_info.pos.line < loc.start.line)
     {
       int c = caret_getc ();
       if (c == EOF)
         /* Something is wrong, that line number does not exist.  */
         return;
-      caret_info.line += c == '\n';
+      caret_info.pos.line += c == '\n';
     }
   caret_info.offset = ftell (caret_info.source);
 
