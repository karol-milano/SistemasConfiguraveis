@@ -467,8 +467,8 @@ grammar_current_rule_prec_set (symbol *precsym, location loc)
      not defined separately as a token.  */
   symbol_class_set (precsym, token_sym, loc, false);
   if (current_rule->ruleprec)
-    duplicate_directive ("%prec",
-                         current_rule->ruleprec->location, loc);
+    duplicate_rule_directive ("%prec",
+                              current_rule->ruleprec->location, loc);
   else
     current_rule->ruleprec = precsym;
 }
@@ -483,8 +483,8 @@ grammar_current_rule_empty_set (location loc)
   if (warning_is_unset (Wempty_rule))
     warning_argmatch ("empty-rule", 0, 0);
   if (current_rule->percent_empty_loc.start.file)
-    duplicate_directive ("%empty",
-                         current_rule->percent_empty_loc, loc);
+    duplicate_rule_directive ("%empty",
+                              current_rule->percent_empty_loc, loc);
   else
     current_rule->percent_empty_loc = loc;
 }
@@ -501,8 +501,8 @@ grammar_current_rule_dprec_set (int dprec, location loc)
     complain (&loc, complaint, _("%s must be followed by positive number"),
               "%dprec");
   else if (current_rule->dprec != 0)
-    duplicate_directive ("%dprec",
-                         current_rule->dprec_location, loc);
+    duplicate_rule_directive ("%dprec",
+                              current_rule->dprec_location, loc);
   else
     {
       current_rule->dprec = dprec;
@@ -520,8 +520,8 @@ grammar_current_rule_merge_set (uniqstr name, location loc)
     complain (&loc, Wother, _("%s affects only GLR parsers"),
               "%merge");
   if (current_rule->merger != 0)
-    duplicate_directive ("%merge",
-                         current_rule->merger_declaration_location, loc);
+    duplicate_rule_directive ("%merge",
+                              current_rule->merger_declaration_location, loc);
   else
     {
       current_rule->merger = get_merge_function (name);
