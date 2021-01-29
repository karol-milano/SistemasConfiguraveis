@@ -243,19 +243,24 @@ grammar_current_rule_begin (symbol *lhs, location loc)
 
 
 /*----------------------------------------------------------------------.
-| A symbol should be used if it has a destructor, or if it is a         |
-| mid-rule symbol (i.e., the generated LHS replacing a mid-rule         |
-| action) that was assigned to, as in "exp: { $$ = 1; } { $$ = $1; }".  |
+| A symbol should be used if either:                                    |
+|   1. It has a destructor.                                             |
+|   2. --warnings=midrule-values and the symbol is a mid-rule symbol    |
+|      (i.e., the generated LHS replacing a mid-rule action) that was   |
+|      assigned to or used, as in "exp: { $$ = 1; } { $$ = $1; }".      |
 `----------------------------------------------------------------------*/
 
 static bool
 symbol_should_be_used (symbol_list const *s)
 {
-  return (symbol_destructor_get (s->content.sym)
-	  || (s->midrule && s->midrule->used)
-	  || (s->midrule_parent_rule
-	      && symbol_list_n_get (s->midrule_parent_rule,
-                                    s->midrule_parent_rhs_index)->used));
+  if (symbol_destructor_get (s->content.sym))
+    return true;
+  if (warnings_flag & warnings_midrule_values)
+    return ((s->midrule && s->midrule->used)
+	    || (s->midrule_parent_rule
+		&& symbol_list_n_get (s->midrule_parent_rule,
+				      s->midrule_parent_rhs_index)->used));
+  return false;
 }
 
 /*----------------------------------------------------------------.
@@ -666,5 +671,5 @@ check_and_convert_grammar (void)
   packgram ();
 
   /* The grammar as a symbol_list is no longer needed. */
-  LIST_FREE (symbol_list, grammar);
+  symbol_list_free (grammar);
 }
