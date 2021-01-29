@@ -282,11 +282,7 @@ muscle_boundary_grow (char const *key, boundary bound)
 }
 
 
-/* In the format '[[file_name:line.column]], [[file_name:line.column]]',
-   append LOC to MUSCLE.  Use digraphs for special characters in each
-   file name.  */
-
-static void
+void
 muscle_location_grow (char const *key, location loc)
 {
   muscle_boundary_grow (key, loc.start);
