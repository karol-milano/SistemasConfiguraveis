@@ -154,12 +154,12 @@ m4_define([b4_lhs_location],
 [(yyloc)])
 
 
-# b4_rhs_location(RULE-LENGTH, NUM)
+# b4_rhs_location(RULE-LENGTH, POS)
 # ---------------------------------
-# Expansion of @NUM, where the current rule has RULE-LENGTH symbols
+# Expansion of @POS, where the current rule has RULE-LENGTH symbols
 # on RHS.
 m4_define([b4_rhs_location],
-          [(yylsp@{b4_subtract([$2], [$1])@})])
+[(yylsp@{b4_subtract([$2], [$1])@})])
 
 
 ## -------------- ##
