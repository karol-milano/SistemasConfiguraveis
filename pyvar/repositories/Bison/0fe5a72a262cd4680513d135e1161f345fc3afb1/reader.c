@@ -442,8 +442,10 @@ grammar_current_rule_prec_set (symbol *precsym, location loc)
      token.  */
   symbol_class_set (precsym, token_sym, loc, false);
   if (current_rule->ruleprec)
-    complain (&loc, complaint, _("only one %s allowed per rule"), "%prec");
-  current_rule->ruleprec = precsym;
+    duplicate_directive ("%prec",
+                         current_rule->ruleprec->location, loc);
+  else
+    current_rule->ruleprec = precsym;
 }
 
 /* Set %empty for the current rule. */
@@ -456,7 +458,8 @@ grammar_current_rule_empty_set (location loc)
   if (warning_is_unset (Wempty_rule))
     warning_argmatch ("empty-rule", 0, 0);
   if (current_rule->percent_empty_loc.start.file)
-    complain (&loc, complaint, _("only one %s allowed per rule"), "%empty");
+    duplicate_directive ("%empty",
+                         current_rule->percent_empty_loc, loc);
   else
     current_rule->percent_empty_loc = loc;
 }
@@ -473,8 +476,13 @@ grammar_current_rule_dprec_set (int dprec, location loc)
     complain (&loc, complaint, _("%s must be followed by positive number"),
               "%dprec");
   else if (current_rule->dprec != 0)
-    complain (&loc, complaint, _("only one %s allowed per rule"), "%dprec");
-  current_rule->dprec = dprec;
+    duplicate_directive ("%dprec",
+                         current_rule->dprec_location, loc);
+  else
+    {
+      current_rule->dprec = dprec;
+      current_rule->dprec_location = loc;
+    }
 }
 
 /* Attach a merge function NAME with argument type TYPE to current
@@ -487,9 +495,13 @@ grammar_current_rule_merge_set (uniqstr name, location loc)
     complain (&loc, Wother, _("%s affects only GLR parsers"),
               "%merge");
   if (current_rule->merger != 0)
-    complain (&loc, complaint, _("only one %s allowed per rule"), "%merge");
-  current_rule->merger = get_merge_function (name);
-  current_rule->merger_declaration_location = loc;
+    duplicate_directive ("%merge",
+                         current_rule->merger_declaration_location, loc);
+  else
+    {
+      current_rule->merger = get_merge_function (name);
+      current_rule->merger_declaration_location = loc;
+    }
 }
 
 /* Attach SYM to the current rule.  If needed, move the previous
