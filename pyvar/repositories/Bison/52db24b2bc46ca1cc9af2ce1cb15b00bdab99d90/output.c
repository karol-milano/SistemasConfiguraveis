@@ -200,8 +200,8 @@ prepare_symbol_names (char const *muscle_name)
   set_quoting_flags (qo, QA_SPLIT_TRIGRAPHS);
   for (int i = 0; i < nsyms; i++)
     {
-      char *cp =
-        symbols[i]->tag[0] == '"' && !quote
+      char *cp
+        = symbols[i]->tag[0] == '"' && !quote
         ? xescape_trigraphs (symbols[i]->tag)
         : quotearg_alloc (symbols[i]->tag, -1, qo);
       /* Width of the next token, including the two quotes, the
@@ -219,10 +219,10 @@ prepare_symbol_names (char const *muscle_name)
       if (i)
         obstack_1grow (&format_obstack, ' ');
       if (!quote && symbols[i]->translatable)
-        obstack_sgrow (&format_obstack, "N_(");
+        obstack_sgrow (&format_obstack, "]b4_symbol_translate([");
       obstack_escape (&format_obstack, cp);
       if (!quote && symbols[i]->translatable)
-        obstack_1grow (&format_obstack, ')');
+        obstack_sgrow (&format_obstack, "])[");
       free (cp);
       obstack_1grow (&format_obstack, ',');
       j += width;
