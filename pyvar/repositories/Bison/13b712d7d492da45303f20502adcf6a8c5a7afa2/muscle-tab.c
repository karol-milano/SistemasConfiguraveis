@@ -178,8 +178,8 @@ muscle_syncline_grow (char const *key, location loc)
 {
   char *extension = NULL;
   obstack_fgrow1 (&muscle_obstack, "]b4_syncline(%d, [[", loc.start.line);
-  MUSCLE_OBSTACK_SGROW (&muscle_obstack,
-			quotearg_style (c_quoting_style, loc.start.file));
+  obstack_escape (&muscle_obstack,
+                  quotearg_style (c_quoting_style, loc.start.file));
   obstack_sgrow (&muscle_obstack, "]])[");
   obstack_1grow (&muscle_obstack, 0);
   extension = obstack_finish (&muscle_obstack);
@@ -206,9 +206,9 @@ void muscle_pair_list_grow (const char *muscle,
 {
   char *pair;
   obstack_sgrow (&muscle_obstack, "[[[");
-  MUSCLE_OBSTACK_SGROW (&muscle_obstack, a1);
+  obstack_escape (&muscle_obstack, a1);
   obstack_sgrow (&muscle_obstack, "]], [[");
-  MUSCLE_OBSTACK_SGROW (&muscle_obstack, a2);
+  obstack_escape (&muscle_obstack, a2);
   obstack_sgrow (&muscle_obstack, "]]]");
   obstack_1grow (&muscle_obstack, 0);
   pair = obstack_finish (&muscle_obstack);
@@ -263,7 +263,7 @@ void
 muscle_boundary_grow (char const *key, boundary bound)
 {
   char *extension;
-  MUSCLE_OBSTACK_SGROW (&muscle_obstack, bound.file);
+  obstack_escape (&muscle_obstack, bound.file);
   obstack_1grow (&muscle_obstack, ':');
   obstack_fgrow1 (&muscle_obstack, "%d", bound.line);
   obstack_1grow (&muscle_obstack, '.');
