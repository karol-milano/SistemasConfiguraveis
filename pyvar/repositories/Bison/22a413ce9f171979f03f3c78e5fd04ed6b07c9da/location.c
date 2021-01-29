@@ -192,10 +192,15 @@ location_caret (location loc, const char *style, FILE *out)
             if (col == loc.start.column)
               begin_use_class (style, out);
             fputc (c, out);
-            if (col + 1 == loc.end.column)
+            if (loc.start.column == loc.end.column
+                ? col == loc.end.column
+                : col + 1 == loc.end.column)
               end_use_class (style, out);
           }
         while ((c = getc (caret_info.source)) != EOF && c != '\n');
+        /* Close the style, in the case of a multiline location.  */
+        if (loc.start.line != loc.end.line)
+          end_use_class (style, out);
         putc ('\n', out);
 
         {
@@ -211,7 +216,7 @@ location_caret (location loc, const char *style, FILE *out)
           for (i = loc.start.column; i == loc.start.column || i < len; ++i)
             putc (i == loc.start.column ? '^' : '~', out);
           end_use_class (style, out);
-          }
+        }
         putc ('\n', out);
       }
   }
