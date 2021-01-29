@@ -192,6 +192,9 @@ xescape_trigraphs (const char *src)
 static void
 prepare_symbol_names (char const *muscle_name)
 {
+  const bool eof_is_user_defined
+    = !endtoken->alias || STRNEQ (endtoken->alias->tag, "$end");
+
   /* We assume that the table will be output starting at column 2. */
   const bool quote = STREQ (muscle_name, "tname");
   bool has_translations = false;
@@ -201,10 +204,16 @@ prepare_symbol_names (char const *muscle_name)
   set_quoting_flags (qo, QA_SPLIT_TRIGRAPHS);
   for (int i = 0; i < nsyms; i++)
     {
+      /* Use "end of file" rather than "$end".  But keep "$end" in the
+         reports, it's shorter and more consistent.  */
+      const char *tag
+        = !eof_is_user_defined && symbols[i]->content == endtoken->content
+        ? "\"end of file\""
+        : symbols[i]->tag;
       char *cp
-        = symbols[i]->tag[0] == '"' && !quote
-        ? xescape_trigraphs (symbols[i]->tag)
-        : quotearg_alloc (symbols[i]->tag, -1, qo);
+        = tag[0] == '"' && !quote
+        ? xescape_trigraphs (tag)
+        : quotearg_alloc (tag, -1, qo);
       /* Width of the next token, including the two quotes, the
          comma and the space.  */
       int width
