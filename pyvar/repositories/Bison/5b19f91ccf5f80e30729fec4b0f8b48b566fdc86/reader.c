@@ -55,7 +55,37 @@ bool default_prec = true;
 void
 grammar_start_symbols_add (symbol_list *syms)
 {
-  start_symbols = symbol_list_append (start_symbols, syms);
+  /* Report and ignore duplicates.  Append the others to START_SYMBOLS.  */
+  symbol_list *last = symbol_list_last (start_symbols);
+  for (symbol_list *l = syms; l && l->content.sym; /* nothing */)
+    {
+      /* Is there a previous definition?  */
+      symbol_list *first = symbol_list_find_symbol (start_symbols, l->content.sym);
+      if (first)
+        {
+          duplicate_directive ("%start", first->sym_loc, l->sym_loc);
+          symbol_list *dup = l;
+          l = l->next;
+          dup->next = NULL;
+          symbol_list_free (dup);
+        }
+      else
+        {
+          if (last)
+            {
+              last->next = l;
+              last = l;
+            }
+          else
+            {
+              last = l;
+              start_symbols = last;
+            }
+          symbol_list *next = l->next;
+          l->next = NULL;
+          l = next;
+        }
+    }
 }
 
 
