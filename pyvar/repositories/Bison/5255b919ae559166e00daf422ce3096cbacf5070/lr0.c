@@ -185,19 +185,19 @@ free_storage (void)
 
 
 
-/*-------------------------------------------------------------------.
-| Find which symbols can be shifted in S, and for each one record    |
-| which items would be active after that shift.  Uses the contents   |
-| of itemset.                                                        |
-|                                                                    |
-| shift_symbol is a bitset of the symbols that can be shifted.  For  |
-| each symbol in the grammar, kernel_base[symbol] points to a vector |
-| of item numbers activated if that symbol is shifted, and           |
-| kernel_size[symbol] is their numbers.                              |
-|                                                                    |
-| itemset is sorted on item index in ritem, which is sorted on rule  |
-| number.  Compute each kernel_base[symbol] with the same sort.      |
-`-------------------------------------------------------------------*/
+/*------------------------------------------------------------------.
+| Find which term/nterm symbols can be "shifted" in S, and for each |
+| one record which items would be active after that transition.     |
+| Uses the contents of itemset.                                     |
+|                                                                   |
+| shift_symbol is a bitset of the term/nterm symbols that can be    |
+| shifted.  For each symbol in the grammar, kernel_base[symbol]     |
+| points to a vector of item numbers activated if that symbol is    |
+| shifted, and kernel_size[symbol] is their numbers.                |
+|                                                                   |
+| itemset is sorted on item index in ritem, which is sorted on rule |
+| number.  Compute each kernel_base[symbol] with the same sort.     |
+`------------------------------------------------------------------*/
 
 static void
 new_itemsets (state *s)
