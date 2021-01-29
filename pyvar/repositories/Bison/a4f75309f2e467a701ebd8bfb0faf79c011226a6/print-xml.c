@@ -494,9 +494,8 @@ void
 xml_puts (FILE *out, int level, char const *s)
 {
   int i;
-  level *= 2;
   for (i = 0; i < level; i++)
-    fputc (' ', out);
+    fputs ("  ", out);
   fputs (s, out);
   fputc ('\n', out);
 }
@@ -508,7 +507,7 @@ xml_printf (FILE *out, int level, char const *fmt, ...)
   va_list arglist;
 
   for (i = 0; i < level; i++)
-    fputc (' ', out);
+    fputs ("  ", out);
 
   va_start (arglist, fmt);
   vfprintf (out, fmt, arglist);
