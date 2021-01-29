@@ -776,18 +776,18 @@ check_and_convert_grammar (void)
   if (nrules == 0)
     complain (NULL, fatal, _("no rules in the input grammar"));
 
-  /* If the user did not define her ENDTOKEN, do it now. */
-  if (!endtoken)
+  /* If the user did not define her EOFTOKEN, do it now. */
+  if (!eoftoken)
     {
-      endtoken = symbol_get ("YYEOF", empty_loc);
-      endtoken->content->class = token_sym;
-      endtoken->content->number = 0;
+      eoftoken = symbol_get ("YYEOF", empty_loc);
+      eoftoken->content->class = token_sym;
+      eoftoken->content->number = 0;
       /* Value specified by POSIX.  */
-      endtoken->content->code = 0;
+      eoftoken->content->code = 0;
       {
         symbol *alias = symbol_get ("$end", empty_loc);
         symbol_class_set (alias, token_sym, empty_loc, false);
-        symbol_make_alias (endtoken, alias, empty_loc);
+        symbol_make_alias (eoftoken, alias, empty_loc);
       }
     }
 
@@ -809,7 +809,7 @@ check_and_convert_grammar (void)
     symbol_list *p = symbol_list_sym_new (accept, empty_loc);
     p->rhs_loc = grammar->rhs_loc;
     p->next = symbol_list_sym_new (startsymbol, empty_loc);
-    p->next->next = symbol_list_sym_new (endtoken, empty_loc);
+    p->next->next = symbol_list_sym_new (eoftoken, empty_loc);
     p->next->next->next = symbol_list_sym_new (NULL, empty_loc);
     p->next->next->next->next = grammar;
     nrules += 1;
