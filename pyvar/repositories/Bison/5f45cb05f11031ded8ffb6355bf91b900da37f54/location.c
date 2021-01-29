@@ -388,9 +388,8 @@ location_caret (location loc, const char *style, FILE *out)
 
         /* Print the carets with the same indentation as above.  */
         {
-          fprintf (out, "      | %s%*s",
-                   skip ? "..." : "",
-                   loc.start.column - 1 - skip, "");
+          fprintf (out, "      | %*s",
+                   loc.start.column - 1 - skip + (skip ? 3 : 0), "");
           begin_use_class (style, out);
           putc ('^', out);
           /* Underlining a multiline location ends with the first
