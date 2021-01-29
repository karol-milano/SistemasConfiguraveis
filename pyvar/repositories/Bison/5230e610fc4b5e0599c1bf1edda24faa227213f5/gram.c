@@ -52,9 +52,8 @@ rule const *
 item_rule (item_number const *item)
 {
   item_number const *sp = item;
-  while (*sp >= 0)
+  while (0 <= *sp)
     ++sp;
-
   rule_number r = item_number_as_rule_number (*sp);
   return &rules[r];
 }
