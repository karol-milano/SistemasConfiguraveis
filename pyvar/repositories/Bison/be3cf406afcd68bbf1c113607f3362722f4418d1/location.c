@@ -473,7 +473,7 @@ location_caret (location loc, const char *style, FILE *out)
 void
 location_caret_suggestion (location loc, const char *s, FILE *out)
 {
-  const char *style = "insertion";
+  const char *style = "fixit-insert";
   fprintf (out, "      | %*s",
            loc.start.column - 1 - caret_info.skip + (caret_info.skip ? 3 : 0),
            "");
