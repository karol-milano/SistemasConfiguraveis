@@ -166,11 +166,12 @@ location_print (location loc, FILE *out)
 static struct
 {
   /* Raw input file.  */
-  FILE *source;
-  /* The last file we tried to open.  If non NULL, but SOURCE is NULL,
-     it means this file is special and should not be quoted. */
+  FILE *file;
+  /* The position within the last file we quoted.  If POS.FILE is non
+     NULL, but FILE is NULL, it means this file is special and should
+     not be quoted. */
   boundary pos;
-  /* Offset in SOURCE where line POS.LINE starts.  */
+  /* Offset in FILE where line POS.LINE starts.  */
   size_t offset;
 } caret_info;
 
@@ -178,7 +179,7 @@ static struct
 static bool
 caret_set_file (const char *file)
 {
-  /* If a different source than before, close and let the rest open
+  /* If a different file than before, close and let the rest open
      the new one. */
   if (caret_info.pos.file && caret_info.pos.file != file)
     {
@@ -188,15 +189,15 @@ caret_set_file (const char *file)
   if (!caret_info.pos.file)
     {
       caret_info.pos.file = file;
-      if ((caret_info.source = fopen (caret_info.pos.file, "r")))
+      if ((caret_info.file = fopen (caret_info.pos.file, "r")))
         {
           /* If the file is not regular (imagine #line 1 "/dev/stdin"
              in the input file for instance), don't try to quote the
-             source.  Keep caret_info.file set so that we don't try to
+             file.  Keep caret_info.file set so that we don't try to
              open it again, but leave caret_info.file NULL so that we
              don't try to quote it. */
           struct stat buf;
-          if (fstat (fileno (caret_info.source), &buf) == 0
+          if (fstat (fileno (caret_info.file), &buf) == 0
               && buf.st_mode & S_IFREG)
             {
               caret_info.pos.line = 1;
@@ -206,16 +207,16 @@ caret_set_file (const char *file)
             caret_free ();
         }
     }
-  return caret_info.source;
+  return caret_info.file;
 }
 
 void
 caret_free (void)
 {
-  if (caret_info.source)
+  if (caret_info.file)
     {
-      fclose (caret_info.source);
-      caret_info.source = NULL;
+      fclose (caret_info.file);
+      caret_info.file = NULL;
     }
 }
 
@@ -223,7 +224,7 @@ caret_free (void)
 static int
 caret_getc (void)
 {
-  FILE *f = caret_info.source;
+  FILE *f = caret_info.file;
   int res = getc (f);
   if (res == '\r')
     {
@@ -253,7 +254,7 @@ location_caret (location loc, const char *style, FILE *out)
       caret_info.pos.line = 1;
       caret_info.offset = 0;
     }
-  fseek (caret_info.source, caret_info.offset, SEEK_SET);
+  fseek (caret_info.file, caret_info.offset, SEEK_SET);
 
   /* Advance to the line's position, keeping track of the offset.  */
   while (caret_info.pos.line < loc.start.line)
@@ -264,7 +265,7 @@ location_caret (location loc, const char *style, FILE *out)
         return;
       caret_info.pos.line += c == '\n';
     }
-  caret_info.offset = ftell (caret_info.source);
+  caret_info.offset = ftell (caret_info.file);
 
   /* Read the actual line.  Don't update the offset, so that we keep a pointer
      to the start of the line.  */
@@ -316,7 +317,7 @@ location_caret (location loc, const char *style, FILE *out)
              line.  */
           int len = single_line
             ? loc.end.column
-            : ftell (caret_info.source) - caret_info.offset;
+            : ftell (caret_info.file) - caret_info.offset;
           for (int i = loc.start.column + 1; i < len; ++i)
             putc ('~', out);
           end_use_class (style, out);
