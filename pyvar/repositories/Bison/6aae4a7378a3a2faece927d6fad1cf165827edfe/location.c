@@ -155,7 +155,9 @@ int
 location_print (location loc, FILE *out)
 {
   int res = 0;
-  if (trace_flag & trace_locations)
+  if (location_empty (loc))
+    res += fprintf (out, "(empty location)");
+  else if (trace_flag & trace_locations)
     {
       res += boundary_print (&loc.start, out);
       res += fprintf (out, "-");
