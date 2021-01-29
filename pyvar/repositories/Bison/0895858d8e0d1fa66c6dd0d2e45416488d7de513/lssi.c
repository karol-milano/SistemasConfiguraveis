@@ -186,7 +186,7 @@ shortest_path_from_start (state_item_number target, symbol_number next_sym)
             }
         }
       // For production steps, follow_L is based on the symbol after the
-      // non-terminal being produced.
+      // nonterminal being produced.
       // if no such symbol exists, follow_L is unchanged
       // if the symbol is a terminal, follow_L only contains that terminal
       // if the symbol is not nullable, follow_L is its FIRSTS set
