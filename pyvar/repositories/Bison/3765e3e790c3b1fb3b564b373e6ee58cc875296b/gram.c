@@ -291,7 +291,7 @@ grammar_dump (FILE *out, const char *title)
         rule const *rule_i = &rules[i];
         int const rhs_itemno = rule_i->rhs - ritem;
         int length = rule_rhs_length (rule_i);
-        aver (item_number_as_rule_number (rule_i->rhs[length] == i));
+        aver (item_number_as_rule_number (rule_i->rhs[length]) == i);
         fprintf (out, "%3d (%2d, %2d, %2s, %2s)   %2d -> (%2u-%2u)",
                  i,
                  rule_i->prec ? rule_i->prec->prec : 0,
