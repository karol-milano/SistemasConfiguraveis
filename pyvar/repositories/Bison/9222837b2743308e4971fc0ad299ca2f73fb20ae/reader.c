@@ -403,17 +403,13 @@ grammar_current_rule_action_append (const char *action, location_t location)
 static void
 packgram (void)
 {
-  unsigned int itemno;
-  int ruleno;
-  symbol_list_t *p;
+  unsigned int itemno = 0;
+  rule_number_t ruleno = 1;
+  symbol_list_t *p = grammar;
 
   ritem = XCALLOC (item_number_t, nritems);
   rules = XCALLOC (rule_t, nrules) - 1;
 
-  itemno = 0;
-  ruleno = 1;
-
-  p = grammar;
   while (p)
     {
       symbol_t *ruleprec = p->ruleprec;
