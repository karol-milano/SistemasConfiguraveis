@@ -46,46 +46,24 @@ symbol_number *token_translations = NULL;
 
 int max_user_token_number = 256;
 
-/*--------------------------------------------------------------.
-| Return true IFF the rule has a `number' smaller than NRULES.  |
-`--------------------------------------------------------------*/
-
 bool
-rule_useful_p (rule *r)
+rule_useful_in_grammar_p (rule *r)
 {
   return r->number < nrules;
 }
 
-
-/*-------------------------------------------------------------.
-| Return true IFF the rule has a `number' higher than NRULES.  |
-`-------------------------------------------------------------*/
-
 bool
-rule_useless_p (rule *r)
+rule_useless_in_grammar_p (rule *r)
 {
-  return !rule_useful_p (r);
+  return !rule_useful_in_grammar_p (r);
 }
 
-
-/*--------------------------------------------------------------------.
-| Return true IFF the rule is not flagged as useful *and* is useful.  |
-| In other words, it was discarded because of conflicts.              |
-`--------------------------------------------------------------------*/
-
 bool
-rule_never_reduced_p (rule *r)
+rule_useless_in_parser_p (rule *r)
 {
-  return !r->useful && rule_useful_p (r);
+  return !r->useful && rule_useful_in_grammar_p (r);
 }
 
-
-/*----------------------------------------------------------------.
-| Print this RULE's number and lhs on OUT.  If a PREVIOUS_LHS was |
-| already displayed (by a previous call for another rule), avoid  |
-| useless repetitions.                                            |
-`----------------------------------------------------------------*/
-
 void
 rule_lhs_print (rule *r, symbol *previous_lhs, FILE *out)
 {
@@ -109,11 +87,6 @@ rule_lhs_print_xml (rule *r, FILE *out, int level)
   xml_printf (out, level, "<lhs>%s</lhs>", r->lhs->tag);
 }
 
-
-/*--------------------------------------.
-| Return the number of symbols in RHS.  |
-`--------------------------------------*/
-
 int
 rule_rhs_length (rule *r)
 {
@@ -124,11 +97,6 @@ rule_rhs_length (rule *r)
   return res;
 }
 
-
-/*-------------------------------.
-| Print this rule's RHS on OUT.  |
-`-------------------------------*/
-
 void
 rule_rhs_print (rule *r, FILE *out)
 {
@@ -166,10 +134,6 @@ rule_rhs_print_xml (rule *r, FILE *out, int level)
     }
 }
 
-/*-------------------------.
-| Print this rule on OUT.  |
-`-------------------------*/
-
 void
 rule_print (rule *r, FILE *out)
 {
@@ -177,11 +141,6 @@ rule_print (rule *r, FILE *out)
   rule_rhs_print (r, out);
 }
 
-
-/*------------------------.
-| Dump RITEM for traces.  |
-`------------------------*/
-
 void
 ritem_print (FILE *out)
 {
@@ -195,11 +154,6 @@ ritem_print (FILE *out)
   fputs ("\n\n", out);
 }
 
-
-/*------------------------------------------.
-| Return the size of the longest rule RHS.  |
-`------------------------------------------*/
-
 size_t
 ritem_longest_rhs (void)
 {
@@ -216,11 +170,6 @@ ritem_longest_rhs (void)
   return max;
 }
 
-
-/*-----------------------------------------------------------------.
-| Print the grammar's rules that match FILTER on OUT under TITLE.  |
-`-----------------------------------------------------------------*/
-
 void
 grammar_rules_partial_print (FILE *out, const char *title,
 			     rule_filter filter)
@@ -247,11 +196,6 @@ grammar_rules_partial_print (FILE *out, const char *title,
     fputs ("\n\n", out);
 }
 
-
-/*----------------------------------------------------------.
-| Print the grammar's rules that match FILTER on OUT (XML). |
-`-----------------------------------------------------------*/
-
 void
 grammar_rules_partial_print_xml (FILE *out, int level, bool rtag,
 				 rule_filter filter)
@@ -282,27 +226,18 @@ grammar_rules_partial_print_xml (FILE *out, int level, bool rtag,
     }
 }
 
-/*------------------------------------------.
-| Print the grammar's useful rules on OUT.  |
-`------------------------------------------*/
-
 void
 grammar_rules_print (FILE *out)
 {
-  grammar_rules_partial_print (out, _("Grammar"), rule_useful_p);
+  grammar_rules_partial_print (out, _("Grammar"), rule_useful_in_grammar_p);
 }
 
 void
 grammar_rules_print_xml (FILE *out, int level)
 {
-  grammar_rules_partial_print_xml (out, level, true, rule_useful_p);
+  grammar_rules_partial_print_xml (out, level, true, rule_useful_in_grammar_p);
 }
 
-
-/*-------------------.
-| Dump the grammar.  |
-`-------------------*/
-
 void
 grammar_dump (FILE *out, const char *title)
 {
@@ -366,16 +301,8 @@ grammar_dump (FILE *out, const char *title)
   fprintf (out, "\n\n");
 }
 
-
-/*------------------------------------------------------------------.
-| Report on STDERR the rules that are not flagged USEFUL, using the |
-| MESSAGE (which can be `useless rule' when invoked after grammar   |
-| reduction, or `never reduced' after conflicts were taken into     |
-| account).                                                         |
-`------------------------------------------------------------------*/
-
 void
-grammar_rules_never_reduced_report (const char *message)
+grammar_rules_useless_report (const char *message)
 {
   rule_number r;
   for (r = 0; r < nrules ; ++r)
