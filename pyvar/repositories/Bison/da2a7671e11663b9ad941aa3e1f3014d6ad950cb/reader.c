@@ -108,7 +108,7 @@ get_merge_function (uniqstr name, uniqstr type, location loc)
       break;
   if (syms->next == NULL)
     {
-      MALLOC (syms->next, 1);
+      syms->next = xmalloc (sizeof syms->next[0]);
       syms->next->name = uniqstr_new (name);
       syms->next->type = uniqstr_new (type);
       syms->next->next = NULL;
@@ -387,8 +387,8 @@ packgram (void)
   rule_number ruleno = 0;
   symbol_list *p = grammar;
 
-  CALLOC (ritem, nritems);
-  CALLOC (rules, nrules);
+  ritem = xnmalloc (nritems, sizeof *ritem);
+  rules = xnmalloc (nrules, sizeof *rules);
 
   while (p)
     {
@@ -397,12 +397,14 @@ packgram (void)
       rules[ruleno].number = ruleno;
       rules[ruleno].lhs = p->sym;
       rules[ruleno].rhs = ritem + itemno;
+      rules[ruleno].prec = NULL;
+      rules[ruleno].dprec = p->dprec;
+      rules[ruleno].merger = p->merger;
+      rules[ruleno].precsym = NULL;
       rules[ruleno].location = p->location;
       rules[ruleno].useful = true;
       rules[ruleno].action = p->action;
       rules[ruleno].action_location = p->action_location;
-      rules[ruleno].dprec = p->dprec;
-      rules[ruleno].merger = p->merger;
 
       p = p->next;
       while (p && p->sym)
