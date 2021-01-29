@@ -259,7 +259,10 @@ muscle_find (char const *key)
 }
 
 
-void
+/* In the format `file_name:line.column', append BOUND to MUSCLE.  Use
+   digraphs for special characters in the file name.  */
+
+static void
 muscle_boundary_grow (char const *key, boundary bound)
 {
   char *extension;
@@ -274,7 +277,12 @@ muscle_boundary_grow (char const *key, boundary bound)
   obstack_free (&muscle_obstack, extension);
 }
 
-void
+
+/* In the format `[[file_name:line.column]], [[file_name:line.column]]',
+   append LOC to MUSCLE.  Use digraphs for special characters in each
+   file name.  */
+
+static void
 muscle_location_grow (char const *key, location loc)
 {
   muscle_grow (key, "[[", "");
