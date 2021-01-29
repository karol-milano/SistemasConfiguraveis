@@ -259,7 +259,6 @@ state_rule_lookahead_tokens_print_xml (state *s, rule *r,
     {
       bitset_iterator biter;
       int k;
-      char const *sep = "";
       xml_puts (out, level, "<lookaheads>");
       BITSET_FOR_EACH (biter, reds->lookahead_tokens[red], k, 0)
 	{
