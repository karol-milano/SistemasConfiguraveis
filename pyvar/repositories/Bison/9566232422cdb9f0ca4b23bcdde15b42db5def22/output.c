@@ -137,9 +137,8 @@ string_output (FILE *out, char const *string)
 }
 
 
-/*----------------------------.
-| Prepare the symbols names.  |
-`----------------------------*/
+/* Generate the b4_<MUSCLE_NAME> (e.g., b4_tname) table with the
+   symbol names (aka tags). */
 
 static void
 prepare_symbol_names (char const *muscle_name)
@@ -430,13 +429,13 @@ prepare_symbol_definitions (void)
       key = obstack_finish0 (&format_obstack);
 
       /* Whether the symbol has an identifier.  */
-      const char *value = symbol_id_get (sym);
+      const char *id = symbol_id_get (sym);
       SET_KEY ("has_id");
-      MUSCLE_INSERT_INT (key, !!value);
+      MUSCLE_INSERT_INT (key, !!id);
 
       /* Its identifier.  */
       SET_KEY ("id");
-      MUSCLE_INSERT_STRING (key, value ? value : "");
+      MUSCLE_INSERT_STRING (key, id ? id : "");
 
       /* Its tag.  Typically for documentation purpose.  */
       SET_KEY ("tag");
