@@ -607,7 +607,7 @@ packgram (void)
 {
   int itemno = 0;
   ritem = xnmalloc (nritems + 1, sizeof *ritem);
-  /* This sentinel is used by build_relations in gram.c.  */
+  /* This sentinel is used by build_relations() in lalr.c.  */
   *ritem++ = 0;
 
   rule_number ruleno = 0;
