@@ -139,13 +139,17 @@ static void
 prepare_symbol_names (char const *muscle_name)
 {
   /* We assume that the table will be output starting at column 2. */
+  const bool quote = STREQ (muscle_name, "tname");
   int j = 2;
   struct quoting_options *qo = clone_quoting_options (0);
   set_quoting_style (qo, c_quoting_style);
   set_quoting_flags (qo, QA_SPLIT_TRIGRAPHS);
   for (int i = 0; i < nsyms; i++)
     {
-      char *cp = quotearg_alloc (symbols[i]->tag, -1, qo);
+      char *cp =
+        symbols[i]->tag[0] == '"' && !quote
+        ? xstrdup (symbols[i]->tag)
+        : quotearg_alloc (symbols[i]->tag, -1, qo);
       /* Width of the next token, including the two quotes, the
          comma and the space.  */
       int width = strlen (cp) + 2;
@@ -192,6 +196,7 @@ prepare_symbols (void)
 
   /* tname -- token names.  */
   prepare_symbol_names ("tname");
+  prepare_symbol_names ("symbol_names");
 
   /* Output YYTOKNUM. */
   {
