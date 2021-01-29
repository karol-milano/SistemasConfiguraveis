@@ -64,10 +64,10 @@ grammar_start_symbols_add (symbol_list *syms)
       if (first)
         {
           duplicate_directive ("%start", first->sym_loc, l->sym_loc);
-          symbol_list *dup = l;
+          symbol_list *dupl = l;
           l = l->next;
-          dup->next = NULL;
-          symbol_list_free (dup);
+          dupl->next = NULL;
+          symbol_list_free (dupl);
         }
       else
         {
