@@ -39,13 +39,13 @@
 #include "reduce.h"
 #include "symtab.h"
 
-/* Set of all nonterminals whose language is not empty.  */
+/* Set of nonterminals whose language is not empty.  */
 static bitset N;
 
-/* Set of all rules which have no useless nonterminals in their RHS.  */
+/* Set of rules that have no useless nonterminals in their RHS.  */
 static bitset P;
 
-/* Set of all accessible symbols.  */
+/* Set of accessible symbols.  */
 static bitset V;
 
 /* Set of symbols used to define rule precedence (so they are
@@ -81,9 +81,11 @@ useful_production (rule_number r, bitset N0)
 }
 
 
-/*---------------------------------------------------------.
-| Remember that rules are 1-origin, symbols are 0-origin.  |
-`---------------------------------------------------------*/
+/*-----------------------------------------------------------------.
+| Compute N, the set of nonterminals whose language is not empty.  |
+|                                                                  |
+| Remember that rules are 1-origin, symbols are 0-origin.          |
+`-----------------------------------------------------------------*/
 
 static void
 useless_nonterminals (void)
