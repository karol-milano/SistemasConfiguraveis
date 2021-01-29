@@ -221,7 +221,7 @@ static bool
 symbol_typed_p (const symbol_list *s)
 {
   return (s->sym->type_name
-	  || s->mid_rule && s->mid_rule->used);
+	  || s->midrule && s->midrule->used);
 }
 
 /*----------------------------------------------------------------.
@@ -341,7 +341,7 @@ grammar_midrule_action (void)
   /* Insert the dummy nonterminal replacing the midrule action into
      the current rule.  Bind it to its dedicated rule.  */
   grammar_current_rule_symbol_append (dummy, dummy_location);
-  grammar_end->mid_rule = midrule;
+  grammar_end->midrule = midrule;
 }
 
 /* Set the precedence symbol of the current rule to PRECSYM. */
