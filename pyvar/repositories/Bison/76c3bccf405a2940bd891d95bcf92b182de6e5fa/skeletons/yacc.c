@@ -132,6 +132,7 @@ m4_define([b4_rhs_value],
 # b4_lhs_location()
 # -----------------
 # Expansion of @$.
+# Overparenthetized to avoid obscure problems with "foo$$bar = foo$1bar".
 m4_define([b4_lhs_location],
 [(yyloc)])
 
@@ -140,6 +141,7 @@ m4_define([b4_lhs_location],
 # ---------------------------------
 # Expansion of @POS, where the current rule has RULE-LENGTH symbols
 # on RHS.
+# Overparenthetized to avoid obscure problems with "foo$$bar = foo$1bar".
 m4_define([b4_rhs_location],
 [(yylsp@{b4_subtract([$2], [$1])@})])
 
@@ -826,9 +828,8 @@ yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,]b4_locations_if([[ YYLTYPE *
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr,
                        YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
-                       &]b4_rhs_value(yynrhs, yyi + 1)[
-                       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
-                       b4_user_args[);
+                       &]b4_rhs_value(yynrhs, yyi + 1)[]b4_locations_if([,
+                       &]b4_rhs_location(yynrhs, yyi + 1))[]b4_user_args[);
       YYFPRINTF (stderr, "\n");
     }
 }
