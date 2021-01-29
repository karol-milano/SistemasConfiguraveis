@@ -186,6 +186,16 @@ xescape_trigraphs (const char *src)
   return buf;
 }
 
+/* Whether some symbol requires internationalization.  */
+static bool
+has_translations (void)
+{
+  for (int i = 0; i < nsyms; i++)
+    if (symbols[i]->translatable)
+      return true;
+  return false;
+}
+
 /* Generate the b4_<MUSCLE_NAME> (e.g., b4_tname) table with the
    symbol names (aka tags). */
 
@@ -195,9 +205,10 @@ prepare_symbol_names (char const *muscle_name)
   const bool eof_is_user_defined
     = !endtoken->alias || STRNEQ (endtoken->alias->tag, "$end");
 
-  /* We assume that the table will be output starting at column 2. */
   const bool quote = STREQ (muscle_name, "tname");
-  bool has_translations = false;
+  const bool with_translations = !quote && has_translations ();
+
+  /* We assume that the table will be output starting at column 2. */
   int j = 2;
   struct quoting_options *qo = clone_quoting_options (0);
   set_quoting_style (qo, c_quoting_style);
@@ -205,11 +216,16 @@ prepare_symbol_names (char const *muscle_name)
   for (int i = 0; i < nsyms; i++)
     {
       /* Use "end of file" rather than "$end".  But keep "$end" in the
-         reports, it's shorter and more consistent.  */
-      const char *tag
-        = !eof_is_user_defined && symbols[i]->content == endtoken->content
-        ? "\"end of file\""
-        : symbols[i]->tag;
+         reports, it's shorter and more consistent.  Support i18n if
+         the user already uses it.  */
+      const char *tag = symbols[i]->tag;
+      bool translatable = with_translations && symbols[i]->translatable;
+      if (!eof_is_user_defined && symbols[i]->content == endtoken->content)
+        {
+          tag = "\"end of file\"";
+          translatable = with_translations;
+        }
+
       char *cp
         = tag[0] == '"' && !quote
         ? xescape_trigraphs (tag)
@@ -218,7 +234,7 @@ prepare_symbol_names (char const *muscle_name)
          comma and the space.  */
       int width
         = strlen (cp) + 2
-        + (!quote && symbols[i]->translatable ? strlen ("N_()") : 0);
+        + (translatable ? strlen ("N_()") : 0);
 
       if (j + width > 75)
         {
@@ -228,13 +244,10 @@ prepare_symbol_names (char const *muscle_name)
 
       if (i)
         obstack_1grow (&format_obstack, ' ');
-      if (!quote && symbols[i]->translatable)
-        {
-          has_translations = true;
-          obstack_sgrow (&format_obstack, "]b4_symbol_translate([");
-        }
+      if (translatable)
+        obstack_sgrow (&format_obstack, "]b4_symbol_translate([");
       obstack_escape (&format_obstack, cp);
-      if (!quote && symbols[i]->translatable)
+      if (translatable)
         obstack_sgrow (&format_obstack, "])[");
       free (cp);
       obstack_1grow (&format_obstack, ',');
@@ -248,7 +261,7 @@ prepare_symbol_names (char const *muscle_name)
 
   /* Announce whether translation support is needed.  */
   if (!quote)
-    MUSCLE_INSERT_BOOL ("has_translations", has_translations);
+    MUSCLE_INSERT_BOOL ("has_translations", with_translations);
 }
 
 
