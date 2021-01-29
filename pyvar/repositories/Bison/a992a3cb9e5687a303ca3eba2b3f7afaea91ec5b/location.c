@@ -23,6 +23,8 @@
 
 #include <mbswidth.h>
 #include <quotearg.h>
+#include <stdio.h>    /* fileno */
+#include <sys/stat.h> /* fstat */
 
 #include "complain.h"
 #include "location.h"
@@ -138,33 +140,63 @@ location_print (location loc, FILE *out)
 
 /* Persistent data used by location_caret to avoid reopening and rereading the
    same file all over for each error.  */
-struct caret_info
+static struct
 {
   FILE *source;
+  /* The last file we tried to open.  If non NULL, but SOURCE is NULL,
+     it means this file is special and should not be quoted. */
+  uniqstr file;
   size_t line;
   /* Offset in SOURCE where line LINE starts.  */
   size_t offset;
-};
-
-static struct caret_info caret_info = { NULL, 1, 0 };
+} caret_info;
 
 void
 caret_free ()
 {
   if (caret_info.source)
-    fclose (caret_info.source);
-  caret_info.source = NULL;
-  caret_info.line = 1;
-  caret_info.offset = 0;
+    {
+      fclose (caret_info.source);
+      caret_info.source = NULL;
+    }
 }
 
 void
 location_caret (location loc, const char *style, FILE *out)
 {
-  if (! (caret_info.source
-         || (caret_info.source = fopen (loc.start.file, "r")))
-      || loc.start.column == -1 || loc.start.line == -1)
+  if (loc.start.column == -1 || loc.start.line == -1)
     return;
+  /* If a different source than before, close and let the rest open
+     the new one. */
+  if (caret_info.file && caret_info.file != loc.start.file)
+    {
+      caret_free ();
+      caret_info.file = NULL;
+    }
+  if (!caret_info.file)
+    {
+      caret_info.file = loc.start.file;
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
+  if (!caret_info.source)
+    return;
+
 
   /* If the line we want to quote is seekable (the same line as the previous
      location), just seek it. If it was a previous line, we lost track of it,
