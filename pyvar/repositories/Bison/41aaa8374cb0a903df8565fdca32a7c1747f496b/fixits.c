@@ -23,10 +23,17 @@
 
 #include "system.h"
 
+#include "error.h"
+#include "get-errno.h"
 #include "getargs.h"
-#include "gl_xlist.h"
 #include "gl_array_list.h"
+#include "gl_xlist.h"
+#include "progname.h"
+#include "quote.h"
 #include "quotearg.h"
+#include "vasnprintf.h"
+
+#include "files.h"
 
 typedef struct
 {
@@ -84,6 +91,94 @@ fixits_register (location const *loc, char const* fix)
 }
 
 
+void
+fixits_run (void)
+{
+  if (!fixits)
+    return;
+
+  /* This is not unlike what is done in location_caret.  */
+  uniqstr input = ((fixit *) gl_list_get_at (fixits, 0))->location.start.file;
+  /* Backup the file. */
+  char buf[256];
+  size_t len = sizeof (buf);
+  char *backup = asnprintf (buf, &len, "%s~", input);
+  if (!backup)
+    xalloc_die ();
+  if (rename (input, backup))
+    error (EXIT_FAILURE, get_errno (),
+           _("%s: cannot backup"), quotearg_colon (input));
+  FILE *in = xfopen (backup, "r");
+  FILE *out = xfopen (input, "w");
+  size_t line = 1;
+  size_t offset = 1;
+  fixit const *f = NULL;
+  gl_list_iterator_t iter = gl_list_iterator (fixits);
+  while (gl_list_iterator_next (&iter, (const void**) &f, NULL))
+    {
+      /* Look for the correct line. */
+      while (line < f->location.start.line)
+        {
+          int c = getc (in);
+          if (c == EOF)
+            break;
+          if (c == '\n')
+            {
+              ++line;
+              offset = 1;
+            }
+          putc (c, out);
+        }
+      /* Look for the right offset. */
+      while (offset < f->location.start.column)
+        {
+          int c = getc (in);
+          if (c == EOF)
+            break;
+          ++offset;
+          putc (c, out);
+        }
+
+      /* Paste the fix instead. */
+      fputs (f->fix, out);
+
+      /* Skip the bad input. */
+      while (line < f->location.end.line)
+        {
+          int c = getc (in);
+          if (c == EOF)
+            break;
+          if (c == '\n')
+            {
+              ++line;
+              offset = 1;
+            }
+        }
+      while (offset < f->location.end.column)
+        {
+          int c = getc (in);
+          if (c == EOF)
+            break;
+          ++offset;
+        }
+    }
+  /* Paste the rest of the file.  */
+  {
+    int c;
+    while ((c = getc (in)) != EOF)
+      putc (c, out);
+  }
+
+  gl_list_iterator_free (&iter);
+  xfclose (out);
+  xfclose (in);
+  fprintf (stderr, "%s: file %s was updated (backup: %s)\n",
+           program_name, quote_n (0, input), quote_n (1, backup));
+  if (backup != buf)
+    free (backup);
+}
+
+
 /* Free the registered fixits.  */
 void fixits_free (void)
 {
