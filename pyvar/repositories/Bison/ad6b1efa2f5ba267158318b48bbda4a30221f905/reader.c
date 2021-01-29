@@ -448,10 +448,10 @@ packgram (void)
       rules[ruleno].action_location = p->action_location;
 
       /* If this rule contains midrules, rest assured that
-        grammar_midrule_action inserted the midrules into grammar before this
-        rule.  Thus, the midrule actions have already been scanned in order to
-        set `used' flags for this rule's rhs, so grammar_rule_check will work
-        properly.  */
+	 grammar_midrule_action inserted the midrules into grammar before this
+	 rule.  Thus, the midrule actions have already been scanned in order to
+	 set `used' flags for this rule's rhs, so grammar_rule_check will work
+	 properly.  */
       grammar_rule_check (p);
 
       for (p = p->next; p && p->sym; p = p->next)
