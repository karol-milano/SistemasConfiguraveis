@@ -159,6 +159,7 @@ location_print (location loc, FILE *out)
    same file all over for each error.  */
 static struct
 {
+  /* Raw input file.  */
   FILE *source;
   /* The last file we tried to open.  If non NULL, but SOURCE is NULL,
      it means this file is special and should not be quoted. */
@@ -168,6 +169,41 @@ static struct
   size_t offset;
 } caret_info;
 
+
+static bool
+caret_set_file (const char *file)
+{
+  /* If a different source than before, close and let the rest open
+     the new one. */
+  if (caret_info.file && caret_info.file != file)
+    {
+      caret_free ();
+      caret_info.file = NULL;
+    }
+  if (!caret_info.file)
+    {
+      caret_info.file = file;
+      if ((caret_info.source = fopen (caret_info.file, "r")))
+        {
+          /* If the file is not regular (imagine #line 1 "/dev/stdin"
+             in the input file for instance), don't try to quote the
+             source.  Keep caret_info.file set so that we don't try to
+             open it again, but leave caret_info.source NULL so that
+             we don't try to quote it. */
+          struct stat buf;
+          if (fstat (fileno (caret_info.source), &buf) == 0
+              && buf.st_mode & S_IFREG)
+            {
+              caret_info.line = 1;
+              caret_info.offset = 0;
+            }
+          else
+            caret_free ();
+        }
+    }
+  return caret_info.source;
+}
+
 void
 caret_free (void)
 {
@@ -200,35 +236,7 @@ location_caret (location loc, const char *style, FILE *out)
 {
   if (loc.start.column == -1 || loc.start.line == -1)
     return;
-  /* If a different source than before, close and let the rest open
-     the new one. */
-  if (caret_info.file && caret_info.file != loc.start.file)
-    {
-      caret_free ();
-      caret_info.file = NULL;
-    }
-  if (!caret_info.file)
-    {
-      caret_info.file = loc.start.file;
-      if ((caret_info.source = fopen (caret_info.file, "r")))
-        {
-          /* If the file is not regular (imagine #line 1 "/dev/stdin"
-             in the input file for instance), don't try to quote the
-             source.  Keep caret_info.file set so that we don't try to
-             open it again, but leave caret_info.source NULL so that
-             we don't try to quote it. */
-          struct stat buf;
-          if (fstat (fileno (caret_info.source), &buf) == 0
-              && buf.st_mode & S_IFREG)
-            {
-              caret_info.line = 1;
-              caret_info.offset = 0;
-            }
-          else
-            caret_free ();
-        }
-    }
-  if (!caret_info.source)
+  if (!caret_set_file (loc.start.file))
     return;
 
 
