@@ -564,7 +564,7 @@ grammar_current_rule_predicate_append (const char *pred, location loc)
 static void
 packgram (void)
 {
-  unsigned int itemno = 0;
+  unsigned itemno = 0;
   rule_number ruleno = 0;
 
   ritem = xnmalloc (nritems + 1, sizeof *ritem);
