@@ -406,11 +406,11 @@ static void
 packgram (void)
 {
   unsigned int itemno = 0;
-  rule_number_t ruleno = 1;
+  rule_number_t ruleno = 0;
   symbol_list_t *p = grammar;
 
   ritem = XCALLOC (item_number_t, nritems);
-  rules = XCALLOC (rule_t, nrules) - 1;
+  rules = XCALLOC (rule_t, nrules);
 
   while (p)
     {
@@ -447,7 +447,7 @@ packgram (void)
 	  rules[ruleno].precsym = ruleprec;
 	  rules[ruleno].prec = ruleprec;
 	}
-      ritem[itemno++] = -ruleno;
+      ritem[itemno++] = rule_number_as_item_number (ruleno);
       ++ruleno;
 
       if (p)
