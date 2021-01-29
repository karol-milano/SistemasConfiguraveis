@@ -169,7 +169,7 @@ static struct
 } caret_info;
 
 void
-caret_free ()
+caret_free (void)
 {
   if (caret_info.source)
     {
@@ -178,6 +178,23 @@ caret_free ()
     }
 }
 
+/* Getc, but smash \r\n as \n.  */
+static int
+caret_getc (void)
+{
+  FILE *f = caret_info.source;
+  int res = getc (f);
+  if (res == '\r')
+    {
+      int c = getc (f);
+      if (c == '\n')
+        res = c;
+      else
+        ungetc (c, f);
+    }
+  return res;
+}
+
 void
 location_caret (location loc, const char *style, FILE *out)
 {
@@ -230,7 +247,7 @@ location_caret (location loc, const char *style, FILE *out)
   /* Advance to the line's position, keeping track of the offset.  */
   while (caret_info.line < loc.start.line)
     {
-      int c = getc (caret_info.source);
+      int c = caret_getc ();
       if (c == EOF)
         /* Something is wrong, that line number does not exist.  */
         return;
@@ -241,7 +258,7 @@ location_caret (location loc, const char *style, FILE *out)
   /* Read the actual line.  Don't update the offset, so that we keep a pointer
      to the start of the line.  */
   {
-    int c = getc (caret_info.source);
+    int c = caret_getc ();
     if (c != EOF)
       {
         bool single_line = loc.start.line == loc.end.line;
@@ -268,7 +285,7 @@ location_caret (location loc, const char *style, FILE *out)
                   opened = true;
                 }
               fputc (c, out);
-              c = getc (caret_info.source);
+              c = caret_getc ();
               ++byte;
               if (opened
                   && (single_line
