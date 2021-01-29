@@ -48,17 +48,6 @@ int max_code = 256;
 
 int required_version = 0;
 
-rule const *
-item_rule (item_number const *item)
-{
-  item_number const *sp = item;
-  while (0 <= *sp)
-    ++sp;
-  rule_number r = item_number_as_rule_number (*sp);
-  return &rules[r];
-}
-
-
 void
 item_print (item_number *item, rule const *previous_rule, FILE *out)
 {
