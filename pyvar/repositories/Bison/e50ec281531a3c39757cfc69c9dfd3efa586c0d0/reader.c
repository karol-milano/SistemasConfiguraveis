@@ -764,6 +764,33 @@ find_start_symbol (void)
 }
 
 
+/* Insert an initial rule, whose location is that of the first rule
+   (not that of the start symbol):
+
+   $accept: SWITCHING_TOKEN START $end.  */
+static void
+create_start_rule (symbol *swtok, symbol *start)
+{
+  symbol_list *initial_rule = symbol_list_sym_new (acceptsymbol, empty_loc);
+  initial_rule->rhs_loc = grammar->rhs_loc;
+  symbol_list *p = initial_rule;
+  if (swtok)
+    {
+      p->next = symbol_list_sym_new (swtok, empty_loc);
+      p = p->next;
+    }
+  p->next = symbol_list_sym_new (start, empty_loc);
+  p = p->next;
+  p->next = symbol_list_sym_new (eoftoken, empty_loc);
+  p = p->next;
+  p->next = symbol_list_sym_new (NULL, empty_loc);
+  p = p->next;
+  p->next = grammar;
+  nrules += 1;
+  nritems += 3 + !!swtok;
+  grammar = initial_rule;
+}
+
 /*-------------------------------------------------------------.
 | Check the grammar that has just been read, and convert it to |
 | internal form.                                               |
@@ -801,21 +828,8 @@ check_and_convert_grammar (void)
       grammar_start_symbol_set (start, start->location);
     }
 
-  /* Insert the initial rule, whose line is that of the first rule
-     (not that of the start symbol):
-
-     $accept: %start $end.  */
-  {
-    symbol_list *p = symbol_list_sym_new (acceptsymbol, empty_loc);
-    p->rhs_loc = grammar->rhs_loc;
-    p->next = symbol_list_sym_new (startsymbol, empty_loc);
-    p->next->next = symbol_list_sym_new (eoftoken, empty_loc);
-    p->next->next->next = symbol_list_sym_new (NULL, empty_loc);
-    p->next->next->next->next = grammar;
-    nrules += 1;
-    nritems += 3;
-    grammar = p;
-  }
+  /* Insert the initial rule.  */
+  create_start_rule (NULL, startsymbol);
 
   if (SYMBOL_NUMBER_MAXIMUM - nnterms < ntokens)
     complain (NULL, fatal, "too many symbols in input grammar (limit is %d)",
