@@ -488,7 +488,11 @@ packgram (void)
 	 rule.  Thus, the midrule actions have already been scanned in order to
 	 set `used' flags for this rule's rhs, so grammar_rule_check will work
 	 properly.  */
-      grammar_rule_check (p);
+      /* Don't check the generated rule 0.  It has no action, so some rhs
+	 symbols may appear unused, but the parsing algorithm ensures that
+	 %destructor's are invoked appropriately.  */
+      if (p != grammar)
+	grammar_rule_check (p);
 
       for (p = p->next; p && p->sym; p = p->next)
 	{
