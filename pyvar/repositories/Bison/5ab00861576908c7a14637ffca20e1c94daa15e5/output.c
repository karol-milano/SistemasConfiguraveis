@@ -186,16 +186,6 @@ xescape_trigraphs (const char *src)
   return buf;
 }
 
-/* Whether some symbol requires internationalization.  */
-static bool
-has_translations (void)
-{
-  for (int i = 0; i < nsyms; i++)
-    if (symbols[i]->translatable)
-      return true;
-  return false;
-}
-
 /* The tag to show in the generated parsers.  Use "end of file" rather
    than "$end".  But keep "$end" in the reports, it's shorter and more
    consistent.  Support i18n if the user already uses it.  */
@@ -219,11 +209,9 @@ symbol_tag (const symbol *sym)
 static void
 prepare_symbol_names (char const *muscle_name)
 {
-  const bool eof_is_user_defined
-    = !endtoken->alias || STRNEQ (endtoken->alias->tag, "$end");
-
+  // Whether to add a pair of quotes around the name.
   const bool quote = STREQ (muscle_name, "tname");
-  const bool with_translations = !quote && has_translations ();
+  bool has_translations = false;
 
   /* We assume that the table will be output starting at column 2. */
   int col = 2;
@@ -233,11 +221,9 @@ prepare_symbol_names (char const *muscle_name)
   for (int i = 0; i < nsyms; i++)
     {
       const char *tag = symbol_tag (symbols[i]);
-      bool translatable =
-        with_translations
-        && (symbols[i]->translatable
-            || (!eof_is_user_defined && symbols[i]->content == endtoken->content)
-            || symbols[i]->content == undeftoken->content);
+      bool translatable = !quote && symbols[i]->translatable;
+      if (translatable)
+        has_translations = true;
 
       char *cp
         = tag[0] == '"' && !quote
@@ -273,8 +259,7 @@ prepare_symbol_names (char const *muscle_name)
   muscle_insert (muscle_name, obstack_finish0 (&format_obstack));
 
   /* Announce whether translation support is needed.  */
-  if (!quote)
-    MUSCLE_INSERT_BOOL ("has_translations", with_translations);
+  MUSCLE_INSERT_BOOL ("has_translations", has_translations);
 }
 
 
