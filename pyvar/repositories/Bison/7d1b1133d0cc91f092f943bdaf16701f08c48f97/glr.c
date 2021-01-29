@@ -336,14 +336,16 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
    accessed by $0, $-1, etc., in any rule.  */
 #define YYMAXLEFT ]b4_max_left_semantic_context[
 
-/* YYTRANSLATE(X) -- Bison symbol number corresponding to X.  */
 #define YYUNDEFTOK  ]b4_undef_token_number[
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
+/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
+   as returned by yylex, with out-of-bounds checking.  */
 #define YYTRANSLATE(YYX)                                                \
   ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
-/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
+/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
+   as returned by yylex.  */
 static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 {
   ]b4_translate[
