@@ -709,6 +709,26 @@ prepare_percent_define_front_end_variables (void)
   }
 }
 
+/* Find the first LHS which is not a dummy.  */
+
+static symbol *
+find_start_symbol ()
+{
+  symbol_list *res = grammar;
+  for (;
+       res != NULL && symbol_is_dummy (res->content.sym);
+       res = res->next)
+    {
+      for (res = res->next;
+           res != NULL && res->content.sym != NULL;
+           res = res->next)
+        continue;
+      aver (res != NULL);
+    }
+  aver (res != NULL);
+  return res->content.sym;
+}
+
 
 /*-------------------------------------------------------------.
 | Check the grammar that has just been read, and convert it to |
@@ -738,19 +758,8 @@ check_and_convert_grammar (void)
   /* Find the start symbol if no %start.  */
   if (!start_flag)
     {
-      symbol_list *node;
-      for (node = grammar;
-           node != NULL && symbol_is_dummy (node->content.sym);
-           node = node->next)
-        {
-          for (node = node->next;
-               node != NULL && node->content.sym != NULL;
-               node = node->next)
-            continue;
-        }
-      aver (node != NULL);
-      grammar_start_symbol_set (node->content.sym,
-                                node->content.sym->location);
+      symbol *start = find_start_symbol ();
+      grammar_start_symbol_set (start, start->location);
     }
 
   /* Insert the initial rule, whose line is that of the first rule
