@@ -49,10 +49,14 @@ symbol_list_new (symbol *sym, location loc)
 `------------------*/
 
 void
-symbol_list_print (FILE *f, symbol_list *l)
+symbol_list_print (symbol_list *l, FILE *f)
 {
-  for (/* Nothing. */; l; l = l->next)
-    symbol_print (f, l->sym);
+  for (/* Nothing. */; l && l->sym; l = l->next)
+    {
+      symbol_print (l->sym, f);
+      if (l && l->sym)
+	fputc (' ', f);
+    }
 }
 
 
