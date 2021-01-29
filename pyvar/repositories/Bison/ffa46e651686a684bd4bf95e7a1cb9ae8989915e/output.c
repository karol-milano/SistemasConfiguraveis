@@ -196,6 +196,23 @@ has_translations (void)
   return false;
 }
 
+/* The tag to show in the generated parsers.  Use "end of file" rather
+   than "$end".  But keep "$end" in the reports, it's shorter and more
+   consistent.  Support i18n if the user already uses it.  */
+static const char *
+symbol_tag (const symbol *sym)
+{
+  const bool eof_is_user_defined
+    = !endtoken->alias || STRNEQ (endtoken->alias->tag, "$end");
+
+  if (!eof_is_user_defined && sym->content == endtoken->content)
+    return "\"end of file\"";
+  else if (sym->content == undeftoken->content)
+    return "\"invalid token\"";
+  else
+    return sym->tag;
+}
+
 /* Generate the b4_<MUSCLE_NAME> (e.g., b4_tname) table with the
    symbol names (aka tags). */
 
@@ -209,27 +226,18 @@ prepare_symbol_names (char const *muscle_name)
   const bool with_translations = !quote && has_translations ();
 
   /* We assume that the table will be output starting at column 2. */
-  int j = 2;
+  int col = 2;
   struct quoting_options *qo = clone_quoting_options (0);
   set_quoting_style (qo, c_quoting_style);
   set_quoting_flags (qo, QA_SPLIT_TRIGRAPHS);
   for (int i = 0; i < nsyms; i++)
     {
-      /* Use "end of file" rather than "$end".  But keep "$end" in the
-         reports, it's shorter and more consistent.  Support i18n if
-         the user already uses it.  */
-      const char *tag = symbols[i]->tag;
-      bool translatable = with_translations && symbols[i]->translatable;
-      if (!eof_is_user_defined && symbols[i]->content == endtoken->content)
-        {
-          tag = "\"end of file\"";
-          translatable = with_translations;
-        }
-      else if (symbols[i]->content == undeftoken->content)
-        {
-          tag = "\"invalid token\"";
-          translatable = with_translations;
-        }
+      const char *tag = symbol_tag (symbols[i]);
+      bool translatable =
+        with_translations
+        && (symbols[i]->translatable
+            || (!eof_is_user_defined && symbols[i]->content == endtoken->content)
+            || symbols[i]->content == undeftoken->content);
 
       char *cp
         = tag[0] == '"' && !quote
@@ -241,10 +249,10 @@ prepare_symbol_names (char const *muscle_name)
         = strlen (cp) + 2
         + (translatable ? strlen ("N_()") : 0);
 
-      if (j + width > 75)
+      if (col + width > 75)
         {
           obstack_sgrow (&format_obstack, "\n ");
-          j = 1;
+          col = 1;
         }
 
       if (i)
@@ -256,7 +264,7 @@ prepare_symbol_names (char const *muscle_name)
         obstack_sgrow (&format_obstack, "])[");
       free (cp);
       obstack_1grow (&format_obstack, ',');
-      j += width;
+      col += width;
     }
   free (qo);
   obstack_sgrow (&format_obstack, " ]b4_null[");
@@ -570,7 +578,7 @@ prepare_symbol_definitions (void)
 
       /* Its tag.  Typically for documentation purpose.  */
       SET_KEY ("tag");
-      MUSCLE_INSERT_STRING (key, sym->tag);
+      MUSCLE_INSERT_STRING (key, symbol_tag (sym));
 
       SET_KEY ("user_number");
       MUSCLE_INSERT_INT (key, sym->content->user_token_number);
