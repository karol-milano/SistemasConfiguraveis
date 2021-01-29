@@ -1,4 +1,5 @@
 /* Input parser for Bison
+
    Copyright (C) 1984, 1986, 1989, 1992, 1998, 2000, 2001, 2002
    Free Software Foundation, Inc.
 
@@ -127,7 +128,7 @@ get_merge_function (uniqstr name, uniqstr type, location loc)
       break;
   if (syms->next == NULL)
     {
-      syms->next = XMALLOC (merger_list, 1);
+      MALLOC (syms->next, 1);
       syms->next->name = uniqstr_new (name);
       syms->next->type = uniqstr_new (type);
       syms->next->next = NULL;
@@ -406,8 +407,8 @@ packgram (void)
   rule_number ruleno = 0;
   symbol_list *p = grammar;
 
-  ritem = XCALLOC (item_number, nritems);
-  rules = XCALLOC (rule, nrules);
+  CALLOC (ritem, nritems);
+  CALLOC (rules, nrules);
 
   while (p)
     {
