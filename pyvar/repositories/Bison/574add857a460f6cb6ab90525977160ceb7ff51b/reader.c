@@ -444,20 +444,6 @@ packgram (void)
 
   rules = xnmalloc (nrules, sizeof *rules);
 
-  /* Before invoking grammar_rule_check on any rule, make sure all actions have
-     already been scanned in order to set `used' flags.  Otherwise, checking
-     that a midrule's $$ should be set will not always work properly because
-     the check must forward-reference the midrule's parent rule.  For the same
-     reason, all the `used' flags must be set before checking whether to remove
-     `$' from any midrule symbol name.  */
-  while (p)
-    {
-      code_props_translate_code (&p->action_props);
-      if (p)
-	p = p->next;
-    }
-
-  p = grammar;
   while (p)
     {
       int rule_length = 0;
@@ -643,6 +629,20 @@ check_and_convert_grammar (void)
      token symbols into FDEFINES if requested.  */
   symbols_pack ();
 
+  /* Scan rule actions after invoking symbol_check_alias_consistency (in
+     symbols_pack above) so that token types are set correctly before the rule
+     action type checking.
+
+     Before invoking grammar_rule_check (in packgram below) on any rule, make
+     sure all actions have already been scanned in order to set `used' flags.
+     Otherwise, checking that a midrule's $$ should be set will not always work
+     properly because the check must forward-reference the midrule's parent
+     rule.  For the same reason, all the `used' flags must be set before
+     checking whether to remove `$' from any midrule symbol name (also in
+     packgram).  */
+  for (symbol_list *sym = grammar; sym; sym = sym->next)
+    code_props_translate_code (&sym->action_props);
+
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
 
