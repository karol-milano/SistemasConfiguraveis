@@ -86,7 +86,7 @@ symbol_list_length (symbol_list_t *list)
 | symbol N in rule RULE.                                        |
 `--------------------------------------------------------------*/
 
-char *
+struniq_t
 symbol_list_n_type_name_get (symbol_list_t *rule, location_t location, int n)
 {
   int i;
