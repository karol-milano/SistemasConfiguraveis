@@ -576,8 +576,8 @@ grammar_current_rule_predicate_append (const char *pred, location loc)
                                /* is_predicate */ true);
 }
 
-/* Set the expected number of shift-reduce (reduce-reduce) conflicts for
- * the current rule.  If a midrule is encountered later, the count
+/* Set the expected number of shift/reduce (reduce/reduce) conflicts
+ * for the current rule.  If a midrule is encountered later, the count
  * is transferred to it and reset in the current rule to -1. */
 
 void
