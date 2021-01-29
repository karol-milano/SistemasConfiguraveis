@@ -904,7 +904,7 @@ search_state_prepend (search_state *ss, symbol_number sym, bitset guide)
  * the same prefix up to the dot.
  */
 static bool
-has_common_prefix (const item_number *itm1, const item_number *itm2)
+have_common_prefix (const item_number *itm1, const item_number *itm2)
 {
   int i = 0;
   for (; !item_number_is_rule_number (itm1[i]); ++i)
@@ -1101,7 +1101,7 @@ unifying_example (state_item_number itm1,
               const state_item *si1src = parse_state_head (ps1);
               const state_item *si2src = parse_state_head (ps2);
               if (item_rule (si1src->item)->lhs == item_rule (si2src->item)->lhs
-                  && has_common_prefix (si1src->item, si2src->item))
+                  && have_common_prefix (si1src->item, si2src->item))
                 {
                   // Stage 4: both paths share a prefix
                   derivation *d1 = parse_state_derivation (ps1);
