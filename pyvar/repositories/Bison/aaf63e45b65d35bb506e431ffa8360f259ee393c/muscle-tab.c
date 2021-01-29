@@ -177,7 +177,7 @@ static void
 muscle_syncline_grow (char const *key, location loc)
 {
   char *extension = NULL;
-  obstack_fgrow1 (&muscle_obstack, "]b4_syncline(%d, ", loc.start.line);
+  obstack_printf (&muscle_obstack, "]b4_syncline(%d, ", loc.start.line);
   obstack_quote (&muscle_obstack,
                  quotearg_style (c_quoting_style, loc.start.file));
   obstack_sgrow (&muscle_obstack, ")[");
@@ -269,9 +269,9 @@ muscle_boundary_grow (char const *key, boundary bound)
   obstack_sgrow  (&muscle_obstack, "[[");
   obstack_escape (&muscle_obstack, bound.file);
   obstack_1grow  (&muscle_obstack, ':');
-  obstack_fgrow1 (&muscle_obstack, "%d", bound.line);
+  obstack_printf (&muscle_obstack, "%d", bound.line);
   obstack_1grow  (&muscle_obstack, '.');
-  obstack_fgrow1 (&muscle_obstack, "%d", bound.column);
+  obstack_printf (&muscle_obstack, "%d", bound.column);
   obstack_sgrow  (&muscle_obstack, "]]");
   obstack_1grow  (&muscle_obstack, '\0');
   extension = obstack_finish (&muscle_obstack);
