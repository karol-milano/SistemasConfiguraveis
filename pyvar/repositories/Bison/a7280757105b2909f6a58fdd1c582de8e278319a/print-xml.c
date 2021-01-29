@@ -260,7 +260,7 @@ print_reductions (FILE *out, int level, state *s)
     bitset_set (no_reduce_set, TRANSITION_SYMBOL (trans, i));
   for (i = 0; i < s->errs->num; ++i)
     if (s->errs->symbols[i])
-      bitset_set (no_reduce_set, s->errs->symbols[i]->number);
+      bitset_set (no_reduce_set, s->errs->symbols[i]->content->number);
 
   if (default_reduction)
     report = true;
@@ -388,11 +388,11 @@ print_grammar (FILE *out, int level)
   /* Terminals */
   xml_puts (out, level + 1, "<terminals>");
   for (i = 0; i < max_user_token_number + 1; i++)
-    if (token_translations[i] != undeftoken->number)
+    if (token_translations[i] != undeftoken->content->number)
       {
         char const *tag = symbols[token_translations[i]]->tag;
-        int precedence = symbols[token_translations[i]]->prec;
-        assoc associativity = symbols[token_translations[i]]->assoc;
+        int precedence = symbols[token_translations[i]]->content->prec;
+        assoc associativity = symbols[token_translations[i]]->content->assoc;
         xml_indent (out, level + 2);
         fprintf (out,
                  "<terminal symbol-number=\"%d\" token-number=\"%d\""
