@@ -212,8 +212,7 @@ table_grow (size_t desired)
 
   table = XREALLOC (table, base_t, table_size);
   check = XREALLOC (check, base_t, table_size);
-  if (glr_parser)
-    conflict_table = XREALLOC (conflict_table, unsigned int, table_size);
+  conflict_table = XREALLOC (conflict_table, unsigned int, table_size);
 
   for (/* Nothing. */; old_size < table_size; ++old_size)
     {
@@ -470,27 +469,22 @@ token_actions (void)
   symbol_number_t j;
   rule_number_t r;
 
-  int nconflict = conflicts_total_count ();
+  int nconflict = glr_parser ? conflicts_total_count () : 0;
 
   yydefact = XCALLOC (rule_number_t, nstates);
 
   actrow = XCALLOC (action_t, ntokens);
   conflrow = XCALLOC (unsigned int, ntokens);
 
+  conflict_list = XCALLOC (unsigned int, 1 + 2 * nconflict);
+  conflict_list_free = 2 * nconflict;
+  conflict_list_cnt = 1;
+
   /* Find the rules which are reduced.  */
   if (!glr_parser)
     for (r = 0; r < nrules; ++r)
       rules[r].useful = FALSE;
 
-  if (glr_parser)
-    {
-      conflict_list = XCALLOC (unsigned int, 1 + 2 * nconflict);
-      conflict_list_free = 2 * nconflict;
-      conflict_list_cnt = 1;
-    }
-  else
-    conflict_list_free = conflict_list_cnt = 0;
-
   for (i = 0; i < nstates; ++i)
     {
       rule_t *default_rule = action_row (states[i]);
@@ -799,8 +793,7 @@ pack_table (void)
   base = XCALLOC (base_t, nvectors);
   pos = XCALLOC (base_t, nentries);
   table = XCALLOC (base_t, table_size);
-  if (glr_parser)
-    conflict_table = XCALLOC (unsigned int, table_size);
+  conflict_table = XCALLOC (unsigned int, table_size);
   check = XCALLOC (base_t, table_size);
 
   lowzero = 0;
