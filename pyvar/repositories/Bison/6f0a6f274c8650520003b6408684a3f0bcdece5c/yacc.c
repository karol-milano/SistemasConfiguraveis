@@ -604,7 +604,7 @@ static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 
 #if ]b4_api_PREFIX[DEBUG
 ]b4_integral_parser_table_define([rline], [b4_rline],
-     [YYRLINE[YYN] -- Source line where rule number YYN was defined.])[
+     [[YYRLINE[YYN] -- Source line where rule number YYN was defined.]])[
 #endif
 
 #if ]b4_api_PREFIX[DEBUG || YYERROR_VERBOSE || ]b4_token_table_flag[
