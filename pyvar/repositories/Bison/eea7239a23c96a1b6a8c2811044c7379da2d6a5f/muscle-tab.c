@@ -266,12 +266,14 @@ static void
 muscle_boundary_grow (char const *key, boundary bound)
 {
   char *extension;
+  obstack_sgrow  (&muscle_obstack, "[[");
   obstack_escape (&muscle_obstack, bound.file);
-  obstack_1grow (&muscle_obstack, ':');
+  obstack_1grow  (&muscle_obstack, ':');
   obstack_fgrow1 (&muscle_obstack, "%d", bound.line);
-  obstack_1grow (&muscle_obstack, '.');
+  obstack_1grow  (&muscle_obstack, '.');
   obstack_fgrow1 (&muscle_obstack, "%d", bound.column);
-  obstack_1grow (&muscle_obstack, '\0');
+  obstack_sgrow  (&muscle_obstack, "]]");
+  obstack_1grow  (&muscle_obstack, '\0');
   extension = obstack_finish (&muscle_obstack);
   muscle_grow (key, extension, "");
   obstack_free (&muscle_obstack, extension);
@@ -285,11 +287,9 @@ muscle_boundary_grow (char const *key, boundary bound)
 static void
 muscle_location_grow (char const *key, location loc)
 {
-  muscle_grow (key, "[[", "");
   muscle_boundary_grow (key, loc.start);
-  muscle_grow (key, "]], [[", "");
+  muscle_grow (key, "", ", ");
   muscle_boundary_grow (key, loc.end);
-  muscle_grow (key, "]]", "");
 }
 
 #define COMMON_DECODE(Value)                                    \
