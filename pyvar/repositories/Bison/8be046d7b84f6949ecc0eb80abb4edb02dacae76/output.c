@@ -396,6 +396,26 @@ merger_output (FILE *out)
 }
 
 
+/*----------------------------------.
+| Whether S is a valid identifier.  |
+`----------------------------------*/
+
+static bool
+is_identifier (uniqstr s)
+{
+  static char const alphanum[26 + 26 + 1 + 10] =
+    "abcdefghijklmnopqrstuvwxyz"
+    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
+    "_"
+    "0123456789";
+  if (!s || ! memchr (alphanum, *s, sizeof alphanum - 10))
+    return false;
+  for (++s; *s; ++s)
+    if (! memchr (alphanum, *s, sizeof alphanum))
+      return false;
+  return true;
+}
+
 /*---------------------------------------.
 | Output the symbol definitions to OUT.  |
 `---------------------------------------*/
@@ -414,6 +434,11 @@ symbol_definitions_output (FILE *out)
       obstack_1grow (&format_obstack, 0);                               \
       key = obstack_finish (&format_obstack);
 
+      // Whether the tag is a valid identifier.
+      SET_KEY("tag_is_id");
+      MUSCLE_INSERT_INT (key, is_identifier(sym->tag));
+
+      // The inner tag.
       SET_KEY("tag");
       MUSCLE_INSERT_STRING (key, sym->tag);
 
