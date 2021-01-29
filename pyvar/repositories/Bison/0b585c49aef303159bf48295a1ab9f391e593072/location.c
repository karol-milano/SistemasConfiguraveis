@@ -470,6 +470,19 @@ location_caret (location loc, const char *style, FILE *out)
   }
 }
 
+void
+location_caret_suggestion (location loc, const char *s, FILE *out)
+{
+  const char *style = "insertion";
+  fprintf (out, "      | %*s",
+           loc.start.column - 1 - caret_info.skip + (caret_info.skip ? 3 : 0),
+           "");
+  begin_use_class (style, out);
+  fputs (s, out);
+  end_use_class (style, out);
+  putc ('\n', out);
+}
+
 bool
 location_empty (location loc)
 {
