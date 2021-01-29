@@ -804,7 +804,7 @@ check_and_convert_grammar (void)
 
      $accept: %start $end.  */
   {
-    symbol_list *p = symbol_list_sym_new (accept, empty_loc);
+    symbol_list *p = symbol_list_sym_new (acceptsymbol, empty_loc);
     p->rhs_loc = grammar->rhs_loc;
     p->next = symbol_list_sym_new (startsymbol, empty_loc);
     p->next->next = symbol_list_sym_new (eoftoken, empty_loc);
