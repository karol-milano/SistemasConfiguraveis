@@ -216,6 +216,13 @@ location_caret (location loc, FILE *out)
   }
 }
 
+bool
+location_empty (location loc)
+{
+  return !loc.start.file && !loc.start.line && !loc.start.column
+    && !loc.end.file && !loc.end.line && !loc.end.column;
+}
+
 void
 boundary_set_from_string (boundary *bound, char *loc_str)
 {
