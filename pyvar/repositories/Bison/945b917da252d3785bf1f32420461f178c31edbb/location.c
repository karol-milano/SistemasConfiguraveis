@@ -21,6 +21,7 @@
 #include <config.h>
 #include "system.h"
 
+#include <mbfile.h>
 #include <mbswidth.h>
 #include <quotearg.h>
 #include <stdio.h>    /* fileno */
@@ -167,6 +168,8 @@ static struct
 {
   /* Raw input file.  */
   FILE *file;
+  /* Input file as a stream of multibyte characters.  */
+  mb_file_t mbfile;
   /* The position within the last file we quoted.  If POS.FILE is non
      NULL, but FILE is NULL, it means this file is special and should
      not be quoted. */
@@ -201,7 +204,7 @@ caret_set_file (const char *file)
               && buf.st_mode & S_IFREG)
             {
               caret_info.pos.line = 1;
-              caret_info.offset = 0;
+              mbf_init (caret_info.mbfile, caret_info.file);
             }
           else
             caret_free ();
@@ -221,22 +224,23 @@ caret_free (void)
 }
 
 /* Getc, but smash \r\n as \n.  */
-static int
-caret_getc (void)
+static void
+caret_getc_internal (mbchar_t *res)
 {
-  FILE *f = caret_info.file;
-  int res = getc (f);
-  if (res == '\r')
+  mbf_getc (*res, caret_info.mbfile);
+  if (mb_iseq (*res, '\r'))
     {
-      int c = getc (f);
-      if (c == '\n')
-        res = c;
+      mbchar_t c;
+      mbf_getc (c, caret_info.mbfile);
+      if (mb_iseq (c, '\n'))
+        mb_copy (res, &c);
       else
-        ungetc (c, f);
+        mbf_ungetc (c, caret_info.mbfile);
     }
-  return res;
 }
 
+#define caret_getc(Var) caret_getc_internal(&Var)
+
 void
 location_caret (location loc, const char *style, FILE *out)
 {
@@ -259,19 +263,25 @@ location_caret (location loc, const char *style, FILE *out)
   /* Advance to the line's position, keeping track of the offset.  */
   while (caret_info.pos.line < loc.start.line)
     {
-      int c = caret_getc ();
-      if (c == EOF)
+      mbchar_t c;
+      caret_getc (c);
+      if (mb_iseof (c))
         /* Something is wrong, that line number does not exist.  */
         return;
-      caret_info.pos.line += c == '\n';
+      caret_info.pos.line += mb_iseq (c, '\n');
     }
   caret_info.offset = ftell (caret_info.file);
+  caret_info.pos.column = 1;
+  /* Reset mbf's internal state.
+     FIXME: should be done in mbfile.  */
+  caret_info.mbfile.eof_seen = 0;
 
   /* Read the actual line.  Don't update the offset, so that we keep a pointer
      to the start of the line.  */
   {
-    int c = caret_getc ();
-    if (c != EOF)
+    mbchar_t c;
+    caret_getc (c);
+    if (!mb_iseof (c))
       {
         bool single_line = loc.start.line == loc.end.line;
         /* Quote the file (at most the first line in the case of
@@ -280,29 +290,27 @@ location_caret (location loc, const char *style, FILE *out)
           fprintf (out, "%5d | ", loc.start.line);
           /* Consider that single point location (with equal boundaries)
              actually denote the character that they follow.  */
-          int byte_end = loc.end.byte +
-            (single_line && loc.start.byte == loc.end.byte);
-          /* Byte number.  */
-          int byte = 1;
+          int col_end = loc.end.column +
+            (single_line && loc.start.column == loc.end.column);
           /* Whether we opened the style.  If the line is not as
              expected (maybe the file was changed since the scanner
              ran), we might reach the end before we actually saw the
              opening column.  */
           bool opened = false;
-          while (c != EOF && c != '\n')
+          while (!mb_iseof (c) && !mb_iseq (c, '\n'))
             {
-              if (byte == loc.start.byte)
+              if (caret_info.pos.column == loc.start.column)
                 {
                   begin_use_class (style, out);
                   opened = true;
                 }
-              fputc (c, out);
-              c = caret_getc ();
-              ++byte;
+              mb_putc (c, out);
+              boundary_compute (&caret_info.pos, mb_ptr (c), mb_len (c));
+              caret_getc (c);
               if (opened
                   && (single_line
-                      ? byte == byte_end
-                      : c == '\n' || c == EOF))
+                      ? caret_info.pos.column == col_end
+                      : mb_iseq (c, '\n') || mb_iseof (c)))
                 end_use_class (style, out);
             }
           putc ('\n', out);
