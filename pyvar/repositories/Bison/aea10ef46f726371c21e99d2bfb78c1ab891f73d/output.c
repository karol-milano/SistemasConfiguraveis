@@ -396,26 +396,6 @@ merger_output (FILE *out)
 }
 
 
-/*----------------------------------.
-| Whether S is a valid identifier.  |
-`----------------------------------*/
-
-static bool
-is_identifier (uniqstr s)
-{
-  static char const alphanum[26 + 26 + 1 + 10] =
-    "abcdefghijklmnopqrstuvwxyz"
-    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
-    "_"
-    "0123456789";
-  if (!s || ! memchr (alphanum, *s, sizeof alphanum - 10))
-    return false;
-  for (++s; *s; ++s)
-    if (! memchr (alphanum, *s, sizeof alphanum))
-      return false;
-  return true;
-}
-
 /*---------------------------------------.
 | Output the symbol definitions to OUT.  |
 `---------------------------------------*/
@@ -428,17 +408,23 @@ symbol_definitions_output (FILE *out)
     {
       symbol *sym = symbols[i];
       const char *key;
+      const char *value;
 
 #define SET_KEY(Entry)                                                  \
       obstack_fgrow2 (&format_obstack, "symbol(%d, %s)", i, Entry);     \
       obstack_1grow (&format_obstack, 0);                               \
       key = obstack_finish (&format_obstack);
 
-      // Whether the tag is a valid identifier.
-      SET_KEY("tag_is_id");
-      MUSCLE_INSERT_INT (key, is_identifier(sym->tag));
+      // Whether the symbol has an identifier.
+      value = symbol_id_get (sym);
+      SET_KEY("has_id");
+      MUSCLE_INSERT_INT (key, !!value);
+
+      // Its identifier.
+      SET_KEY("id");
+      MUSCLE_INSERT_STRING (key, value ? value : "");
 
-      // The inner tag.
+      // Its tag.  Typically for documentation purpose.
       SET_KEY("tag");
       MUSCLE_INSERT_STRING (key, sym->tag);
 
