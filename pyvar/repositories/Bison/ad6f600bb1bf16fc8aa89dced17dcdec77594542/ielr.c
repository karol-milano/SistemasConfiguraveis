@@ -423,7 +423,7 @@ ielr_item_has_lookahead (state *s, symbol_number lhs, size_t item,
              check all predecessors' goto follows for the LHS.  */
           if (item_number_is_rule_number (ritem[s->items[item] - 2]))
             {
-              aver (lhs != accept->content->number);
+              aver (lhs != acceptsymbol->content->number);
               for (state **predecessor = predecessors[s->number];
                    *predecessor;
                    ++predecessor)
