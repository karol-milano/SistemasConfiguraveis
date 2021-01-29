@@ -90,9 +90,9 @@ location_compute (location *loc, boundary *cur, char const *token, size_t size)
   loc->end = *cur;
 
   if (line == INT_MAX && loc->start.line != INT_MAX)
-    complain_at (*loc, Wother, _("line number overflow"));
+    complain (loc, Wother, _("line number overflow"));
   if (column == INT_MAX && loc->start.column != INT_MAX)
-    complain_at (*loc, Wother, _("column number overflow"));
+    complain (loc, Wother, _("column number overflow"));
 }
 
 
