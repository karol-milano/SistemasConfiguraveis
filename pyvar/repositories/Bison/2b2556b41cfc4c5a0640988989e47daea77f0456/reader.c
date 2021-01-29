@@ -114,13 +114,11 @@ record_merge_function_type (int merger, uniqstr type, location declaration_loc)
   if (merger <= 0)
     return;
 
-  int merger_find;
-  merger_list *merge_function;
-
   if (type == NULL)
     type = uniqstr_new ("");
 
-  merger_find = 1;
+  merger_list *merge_function;
+  int merger_find = 1;
   for (merge_function = merge_functions;
        merge_function != NULL && merger_find != merger;
        merge_function = merge_function->next)
@@ -585,6 +583,7 @@ grammar_current_rule_predicate_append (const char *pred, location loc)
 void
 grammar_current_rule_expect_sr (int count, location loc)
 {
+  (void) loc;
   current_rule->expected_sr_conflicts = count;
 }
 
@@ -608,13 +607,11 @@ static void
 packgram (void)
 {
   unsigned itemno = 0;
-  rule_number ruleno = 0;
-
   ritem = xnmalloc (nritems + 1, sizeof *ritem);
-
   /* This sentinel is used by build_relations in gram.c.  */
   *ritem++ = 0;
 
+  rule_number ruleno = 0;
   rules = xnmalloc (nrules, sizeof *rules);
 
   for (symbol_list *p = grammar; p; p = p->next)
@@ -747,11 +744,10 @@ prepare_percent_define_front_end_variables (void)
   /* Set %define front-end variable defaults.  */
   muscle_percent_define_default ("lr.keep-unreachable-state", "false");
   {
-    char *lr_type;
     /* IELR would be a better default, but LALR is historically the
        default.  */
     muscle_percent_define_default ("lr.type", "lalr");
-    lr_type = muscle_percent_define_get ("lr.type");
+    char *lr_type = muscle_percent_define_get ("lr.type");
     if (STRNEQ (lr_type, "canonical-lr"))
       muscle_percent_define_default ("lr.default-reduction", "most");
     else
