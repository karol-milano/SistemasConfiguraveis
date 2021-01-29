@@ -95,6 +95,12 @@ rule_useless_in_parser_p (rule const *r)
   return !r->useful && rule_useful_in_grammar_p (r);
 }
 
+bool
+rule_useless_chain_p (rule const *r)
+{
+  return rule_rhs_length (r) == 1 && !r->action;
+}
+
 void
 rule_lhs_print (rule const *r, sym_content const *previous_lhs, FILE *out)
 {
@@ -272,12 +278,13 @@ grammar_dump (FILE *out, const char *title)
         rule const *rule_i = &rules[i];
         unsigned const rhs_itemno = rule_i->rhs - ritem;
         unsigned length = rule_rhs_length (rule_i);
-        fprintf (out, "%3d (%3d, %2d, %2d, %2s, %2u-%2u)   %2d ->",
+        fprintf (out, "%3d (%3d, %2d, %2d, %2s, %2s, %2u-%2u)   %2d ->",
                  item_number_as_rule_number (rule_i->rhs[length]),
                  i,
                  rule_i->prec ? rule_i->prec->prec : 0,
                  rule_i->prec ? rule_i->prec->assoc : 0,
                  rule_i->useful ? "t" : "f",
+                 rule_useless_chain_p (rule_i) ? "t" : "f",
                  rhs_itemno,
                  rhs_itemno + length - 1,
                  rule_i->lhs->number);
