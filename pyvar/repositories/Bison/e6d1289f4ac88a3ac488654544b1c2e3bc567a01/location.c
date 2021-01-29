@@ -400,6 +400,8 @@ caret_set_column (int col)
 void
 location_caret (location loc, const char *style, FILE *out)
 {
+  if (!(feature_flag & feature_caret))
+    return;
   if (!loc.start.line)
     return;
   if (!caret_set_file (loc.start.file))
@@ -486,6 +488,8 @@ location_caret (location loc, const char *style, FILE *out)
 void
 location_caret_suggestion (location loc, const char *s, FILE *out)
 {
+  if (!(feature_flag & feature_caret))
+    return;
   const char *style = "fixit-insert";
   fprintf (out, "      | %*s",
            loc.start.column - 1 - caret_info.skip
