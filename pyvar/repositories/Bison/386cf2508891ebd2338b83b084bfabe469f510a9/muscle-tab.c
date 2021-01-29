@@ -275,7 +275,7 @@ muscle_boundary_grow (char const *key, boundary bound)
 {
   obstack_sgrow  (&muscle_obstack, "[[");
   obstack_escape (&muscle_obstack, bound.file);
-  obstack_printf (&muscle_obstack, ":%d.%d]]", bound.line, bound.column);
+  obstack_printf (&muscle_obstack, ":%d.%d@@%d]]", bound.line, bound.column, bound.byte);
   char const *extension = obstack_finish0 (&muscle_obstack);
   muscle_grow (key, extension, "", "");
   obstack_free (&muscle_obstack, extension);
