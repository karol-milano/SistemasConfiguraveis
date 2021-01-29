@@ -43,6 +43,12 @@
 #include "tables.h"
 
 static bitset no_reduce_set;
+struct escape_buf
+{
+  char *ptr;
+  size_t size;
+};
+static struct escape_buf escape_bufs[2];
 
 
 /*----------------------------.
@@ -516,12 +522,6 @@ xml_printf (FILE *out, int level, char const *fmt, ...)
   fputc ('\n', out);
 }
 
-struct escape_buf
-{
-  char *ptr;
-  size_t size;
-};
-
 static char const *
 xml_escape_string (struct escape_buf *buf, char const *str)
 {
@@ -553,8 +553,7 @@ xml_escape_string (struct escape_buf *buf, char const *str)
 char const *
 xml_escape_n (int n, char const *str)
 {
-  static struct escape_buf buf[2];
-  return xml_escape_string (buf + n, str);
+  return xml_escape_string (escape_bufs + n, str);
 }
 
 char const *
@@ -608,5 +607,8 @@ print_xml (void)
 
   xml_puts (out, 0, "</bison-xml-report>");
 
+  free (escape_bufs[0].ptr);
+  free (escape_bufs[1].ptr);
+
   xfclose (out);
 }
