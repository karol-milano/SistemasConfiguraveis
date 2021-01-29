@@ -25,7 +25,14 @@
 #include <mbswidth.h>
 #include <quotearg.h>
 #include <stdio.h>    /* fileno */
+#include <sys/ioctl.h>
 #include <sys/stat.h> /* fstat */
+#include <termios.h>
+
+#ifdef WINSIZE_IN_PTEM
+# include <sys/stream.h>
+# include <sys/ptem.h>
+#endif
 
 #include "complain.h"
 #include "getargs.h"
@@ -39,7 +46,13 @@ min_int (int a, int b)
   return a < b ? a : b;
 }
 
-/* The terminal width.  */
+static int
+max_int (int a, int b)
+{
+  return a >= b ? a : b;
+}
+
+/* The terminal width.  Not less than 40.  */
 static int
 columns (void)
 {
@@ -50,9 +63,21 @@ columns (void)
       unsigned long ul = strtoul (cp, NULL, 10);
       res = ul < INT_MAX ? ul : INT_MAX;
     }
-  return res;
+  else
+    {
+#ifdef TIOCGWINSZ
+      struct winsize ws;
+      if (ioctl (STDERR_FILENO, TIOCGWINSZ, &ws) != -1
+          && 0 < ws.ws_col && ws.ws_col == (size_t) ws.ws_col)
+        res = ws.ws_col;
+#endif
+    }
+  return max_int (res, 40);
 }
 
+/* Available screen width.  */
+static int screen_width = 80;
+
 /* If BUF is null, add BUFSIZE (which in this case must be less than
    INT_MAX) to COLUMN; otherwise, add mbsnwidth (BUF, BUFSIZE, 0) to
    COLUMN.  If an overflow occurs, return INT_MAX.  */
@@ -235,6 +260,11 @@ caret_set_file (const char *file)
   return caret_info.file;
 }
 
+void caret_init (void)
+{
+  screen_width = columns ();
+}
+
 void
 caret_free (void)
 {
@@ -308,10 +338,17 @@ location_caret (location loc, const char *style, FILE *out)
       boundary_compute (&caret_info.pos, mb_ptr (c), mb_len (c));
     }
   int line_len = caret_info.pos.column;
+  /* Go back to the beginning of line.  */
+  fseek (caret_info.file, caret_info.offset, SEEK_SET);
+  /* Reset mbf's internal state.
+     FIXME: should be done in mbfile.  */
+  caret_info.mbfile.eof_seen = 0;
+  caret_info.pos.column = 1;
+
 
   /* Available width.  Eight chars are consumed by the left-margin of
      the quoting lines.  */
-  int width = columns () - 8;
+  int width = screen_width - 8;
   int skip = 0;
   if (width < line_len)
     {
@@ -327,13 +364,6 @@ location_caret (location loc, const char *style, FILE *out)
   if (width < line_len - skip)
     width -= 3;
 
-  /* Go back to the beginning of line.  */
-  fseek (caret_info.file, caret_info.offset, SEEK_SET);
-  /* Reset mbf's internal state.
-     FIXME: should be done in mbfile.  */
-  caret_info.mbfile.eof_seen = 0;
-  caret_info.pos.column = 1;
-
   /* Read the actual line.  Don't update the offset, so that we keep a pointer
      to the start of the line.  */
   {
