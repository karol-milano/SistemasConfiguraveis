@@ -430,6 +430,11 @@ grammar_midrule_action (void)
                                current_rule->action_props.is_predicate);
   code_props_none_init (&current_rule->action_props);
 
+  midrule->expected_sr_conflicts = current_rule->expected_sr_conflicts;
+  midrule->expected_rr_conflicts = current_rule->expected_rr_conflicts;
+  current_rule->expected_sr_conflicts = -1;
+  current_rule->expected_rr_conflicts = -1;
+
   if (previous_rule_end)
     previous_rule_end->next = midrule;
   else
@@ -573,6 +578,26 @@ grammar_current_rule_predicate_append (const char *pred, location loc)
                                /* is_predicate */ true);
 }
 
+/* Set the expected number of shift-reduce (reduce-reduce) conflicts for
+ * the current rule.  If a midrule is encountered later, the count
+ * is transferred to it and reset in the current rule to -1. */
+
+void
+grammar_current_rule_expect_sr (int count, location loc)
+{
+  current_rule->expected_sr_conflicts = count;
+}
+
+void
+grammar_current_rule_expect_rr (int count, location loc)
+{
+  if (! glr_parser)
+    complain (&loc, Wother, _("%s affects only GLR parsers"),
+              "%expect-rr");
+  else
+    current_rule->expected_rr_conflicts = count;
+}
+
 
 /*---------------------------------------------------------------.
 | Convert the rules into the representation using RRHS, RLHS and |
@@ -626,6 +651,8 @@ packgram (void)
       rules[ruleno].action = lhs->action_props.code;
       rules[ruleno].action_location = lhs->action_props.location;
       rules[ruleno].is_predicate = lhs->action_props.is_predicate;
+      rules[ruleno].expected_sr_conflicts = p->expected_sr_conflicts;
+      rules[ruleno].expected_rr_conflicts = p->expected_rr_conflicts;
 
       /* Traverse the rhs.  */
       {
