@@ -212,17 +212,16 @@ grammar_current_rule_begin (symbol *lhs, location loc)
 }
 
 
-/*-----------------------------------------------------------------.
-| A symbol is typed if it has a declared %type, or if it is a      |
-| mid-rule symbol (i.e., the generated LHS replacing a mid-rule    |
-| action) that was assigned to, as in `exp: { $$ = 1; } { $$ = $1; |
-| }'.                                                              |
-`-----------------------------------------------------------------*/
+/*----------------------------------------------------------------------.
+| A symbol should be used if it has a destructor, or if it is a         |
+| mid-rule symbol (i.e., the generated LHS replacing a mid-rule         |
+| action) that was assigned to, as in "exp: { $$ = 1; } { $$ = $1; }".  |
+`----------------------------------------------------------------------*/
 
 static bool
-symbol_typed_p (const symbol_list *s)
+symbol_should_be_used (symbol_list const *s)
 {
-  return (s->sym->type_name
+  return (s->sym->destructor
 	  || (s->midrule && s->midrule->used));
 }
 
@@ -261,13 +260,13 @@ grammar_rule_check (const symbol_list *r)
 		 _("empty rule for typed nonterminal, and no action"));
     }
 
-  /* Check that typed symbol values are used.  */
+  /* Check that symbol values that should be used are in fact used.  */
   {
     symbol_list const *l = r;
     int n = 0;
     for (; l && l->sym; l = l->next, ++n)
       if (! (l->used
-	     || !symbol_typed_p (l)
+	     || !symbol_should_be_used (l)
 	     /* The default action, $$ = $1, `uses' both.  */
 	     || (!r->action && (n == 0 || n == 1))))
 	{
