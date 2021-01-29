@@ -211,7 +211,7 @@ muscle_syncline_grow (char const *key, location loc)
   obstack_printf (&muscle_obstack, "]b4_syncline(%d, ", loc.start.line);
   obstack_quote (&muscle_obstack,
                  quotearg_style (c_quoting_style, loc.start.file));
-  obstack_sgrow (&muscle_obstack, ")[");
+  obstack_sgrow (&muscle_obstack, ")dnl\n[");
   char const *extension = obstack_finish0 (&muscle_obstack);
   muscle_grow (key, extension, "", "");
   obstack_free (&muscle_obstack, extension);
@@ -227,7 +227,7 @@ void
 muscle_code_grow (const char *key, const char *val, location loc)
 {
   muscle_syncline_grow (key, loc);
-  muscle_grow (key, val, "\n", "\n");
+  muscle_grow (key, val, "", "\n");
 }
 
 
