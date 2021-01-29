@@ -418,7 +418,11 @@ packgram (void)
   rule_number ruleno = 0;
   symbol_list *p = grammar;
 
-  ritem = xnmalloc (nritems, sizeof *ritem);
+  ritem = xnmalloc (nritems + 1, sizeof *ritem);
+
+  /* This sentinel is used by build_relations in gram.c.  */
+  *ritem++ = 0;
+
   rules = xnmalloc (nrules, sizeof *rules);
 
   while (p)
