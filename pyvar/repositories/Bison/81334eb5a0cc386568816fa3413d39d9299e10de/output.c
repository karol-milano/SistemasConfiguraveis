@@ -259,7 +259,7 @@ prepare_symbol_names (char const *muscle_name)
   muscle_insert (muscle_name, obstack_finish0 (&format_obstack));
 
   /* Announce whether translation support is needed.  */
-  MUSCLE_INSERT_BOOL ("has_translations", has_translations);
+  MUSCLE_INSERT_BOOL ("has_translations_flag", has_translations);
 }
 
 
