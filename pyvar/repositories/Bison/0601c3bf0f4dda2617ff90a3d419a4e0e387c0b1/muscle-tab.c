@@ -177,10 +177,10 @@ static void
 muscle_syncline_grow (char const *key, location loc)
 {
   char *extension = NULL;
-  obstack_fgrow1 (&muscle_obstack, "]b4_syncline(%d, [[", loc.start.line);
-  obstack_escape (&muscle_obstack,
-                  quotearg_style (c_quoting_style, loc.start.file));
-  obstack_sgrow (&muscle_obstack, "]])[");
+  obstack_fgrow1 (&muscle_obstack, "]b4_syncline(%d, ", loc.start.line);
+  obstack_quote (&muscle_obstack,
+                 quotearg_style (c_quoting_style, loc.start.file));
+  obstack_sgrow (&muscle_obstack, ")[");
   obstack_1grow (&muscle_obstack, 0);
   extension = obstack_finish (&muscle_obstack);
   muscle_grow (key, extension, "");
@@ -205,11 +205,11 @@ void muscle_pair_list_grow (const char *muscle,
 			    const char *a1, const char *a2)
 {
   char *pair;
-  obstack_sgrow (&muscle_obstack, "[[[");
-  obstack_escape (&muscle_obstack, a1);
-  obstack_sgrow (&muscle_obstack, "]], [[");
-  obstack_escape (&muscle_obstack, a2);
-  obstack_sgrow (&muscle_obstack, "]]]");
+  obstack_sgrow (&muscle_obstack, "[");
+  obstack_quote (&muscle_obstack, a1);
+  obstack_sgrow (&muscle_obstack, ", ");
+  obstack_quote (&muscle_obstack, a2);
+  obstack_sgrow (&muscle_obstack, "]");
   obstack_1grow (&muscle_obstack, 0);
   pair = obstack_finish (&muscle_obstack);
   muscle_grow (muscle, pair, ",\n");
