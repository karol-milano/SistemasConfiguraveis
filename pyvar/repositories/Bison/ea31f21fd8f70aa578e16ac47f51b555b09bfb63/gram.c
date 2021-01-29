@@ -46,6 +46,8 @@ symbol_number *token_translations = NULL;
 
 int max_user_token_number = 256;
 
+int required_version = 0;
+
 bool
 rule_useful_in_grammar_p (rule const *r)
 {
