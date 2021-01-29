@@ -44,8 +44,7 @@ typedef struct symbol_list
   const char *action;
   int action_line;
   bucket *ruleprec;
-}
-symbol_list;
+} symbol_list;
 
 int lineno;
 char **tags;
@@ -75,6 +74,8 @@ symbol_list_new (bucket *sym)
   res->next = NULL;
   res->sym = sym;
   res->line = lineno;
+  res->action = NULL;
+  res->action_line = 0;
   res->ruleprec = NULL;
   return res;
 }
