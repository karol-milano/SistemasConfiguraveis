@@ -194,6 +194,7 @@ prepare_symbol_names (char const *muscle_name)
 {
   /* We assume that the table will be output starting at column 2. */
   const bool quote = STREQ (muscle_name, "tname");
+  bool has_translations = false;
   int j = 2;
   struct quoting_options *qo = clone_quoting_options (0);
   set_quoting_style (qo, c_quoting_style);
@@ -219,7 +220,10 @@ prepare_symbol_names (char const *muscle_name)
       if (i)
         obstack_1grow (&format_obstack, ' ');
       if (!quote && symbols[i]->translatable)
-        obstack_sgrow (&format_obstack, "]b4_symbol_translate([");
+        {
+          has_translations = true;
+          obstack_sgrow (&format_obstack, "]b4_symbol_translate([");
+        }
       obstack_escape (&format_obstack, cp);
       if (!quote && symbols[i]->translatable)
         obstack_sgrow (&format_obstack, "])[");
@@ -232,6 +236,10 @@ prepare_symbol_names (char const *muscle_name)
 
   /* Finish table and store. */
   muscle_insert (muscle_name, obstack_finish0 (&format_obstack));
+
+  /* Announce whether translation support is needed.  */
+  if (!quote)
+    MUSCLE_INSERT_BOOL ("has_translations", has_translations);
 }
 
 
