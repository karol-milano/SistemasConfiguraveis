@@ -640,8 +640,11 @@ check_and_convert_grammar (void)
      rule.  For the same reason, all the `used' flags must be set before
      checking whether to remove `$' from any midrule symbol name (also in
      packgram).  */
-  for (symbol_list *sym = grammar; sym; sym = sym->next)
-    code_props_translate_code (&sym->action_props);
+  {
+    symbol_list *sym;
+    for (sym = grammar; sym; sym = sym->next)
+      code_props_translate_code (&sym->action_props);
+  }
 
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
