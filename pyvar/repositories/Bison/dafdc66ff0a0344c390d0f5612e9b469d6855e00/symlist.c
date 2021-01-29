@@ -64,6 +64,20 @@ symbol_list_free (symbol_list_t *list)
 }
 
 
+/*--------------------.
+| Return its length.  |
+`--------------------*/
+
+unsigned int
+symbol_list_length (symbol_list_t *list)
+{
+  int res = 0;
+  for (/* Nothing. */; list; list = list->next)
+    ++res;
+  return res;
+}
+
+
 /*--------------------------------------------------------------.
 | Get the data type (alternative in the union) of the value for |
 | symbol N in rule RULE.                                        |
