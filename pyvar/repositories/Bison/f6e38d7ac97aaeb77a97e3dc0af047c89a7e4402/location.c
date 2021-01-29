@@ -160,7 +160,7 @@ caret_free ()
 }
 
 void
-location_caret (location loc, FILE *out)
+location_caret (location loc, const char *style, FILE *out)
 {
   /* FIXME: find a way to support multifile locations, and only open once each
      file. That would make the procedure future-proof.  */
@@ -193,9 +193,17 @@ location_caret (location loc, FILE *out)
     if (c != EOF)
       {
         /* Quote the file, indent by a single column.  */
-        putc (' ', out);
+        fputc (' ', out);
+        int col = 0;
         do
-          putc (c, out);
+          {
+            ++col;
+            if (col == loc.start.column)
+              begin_use_class (style, out);
+            fputc (c, out);
+            if (col + 1 == loc.end.column)
+              end_use_class (style, out);
+          }
         while ((c = getc (caret_info.source)) != EOF && c != '\n');
         putc ('\n', out);
 
@@ -208,8 +216,10 @@ location_caret (location loc, FILE *out)
 
           /* Print the carets (at least one), with the same indent as above.*/
           fprintf (out, " %*s", loc.start.column - 1, "");
+          begin_use_class (style, out);
           for (i = loc.start.column; i == loc.start.column || i < len; ++i)
             putc (i == loc.start.column ? '^' : '~', out);
+          end_use_class (style, out);
           }
         putc ('\n', out);
       }
