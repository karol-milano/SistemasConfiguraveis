@@ -562,16 +562,16 @@ union yyalloc
 /* YYNSTATES -- Number of states.  */
 #define YYNSTATES  ]b4_states_number[
 
-/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
-   by yylex, with out-of-bounds checking.  */
 #define YYUNDEFTOK  ]b4_undef_token_number[
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
+/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
+   as returned by yylex, with out-of-bounds checking.  */
 #define YYTRANSLATE(YYX)                                                \
   ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
-   as returned by yylex, without out-of-bounds checking.  */
+   as returned by yylex.  */
 static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 {
   ]b4_translate[
