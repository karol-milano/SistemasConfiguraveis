@@ -225,13 +225,6 @@ static symbol_list *previous_rule_end = NULL;
 void
 grammar_current_rule_begin (symbol *lhs, location loc)
 {
-  if (!start_flag)
-    {
-      startsymbol = lhs;
-      startsymbol_location = loc;
-      start_flag = true;
-    }
-
   /* Start a new rule and record its lhs.  */
   ++nrules;
   previous_rule_end = grammar_end;
@@ -607,6 +600,23 @@ check_and_convert_grammar (void)
       endtoken->user_token_number = 0;
     }
 
+  /* Find the start symbol if no %start.  */
+  if (!start_flag)
+    {
+      symbol_list *node;
+      for (node = grammar;
+           node != NULL && symbol_is_dummy (node->sym);
+           node = node->next)
+        {
+          for (node = node->next;
+               node != NULL && node->sym != NULL;
+               node = node->next)
+            ;
+        }
+      assert (node != NULL);
+      grammar_start_symbol_set (node->sym, node->sym->location);
+    }
+
   /* Insert the initial rule, whose line is that of the first rule
      (not that of the start symbol):
 
