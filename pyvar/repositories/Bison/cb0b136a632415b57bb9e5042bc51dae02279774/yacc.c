@@ -485,14 +485,16 @@ union yyalloc
 /* YYNSTATES -- Number of states.  */
 #define YYNSTATES  ]b4_states_number[
 
-/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
+/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
+   by yylex, with out-of-bounds checking.  */
 #define YYUNDEFTOK  ]b4_undef_token_number[
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
-/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
+/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
+   as returned by yylex, without out-of-bounds checking.  */
 static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 {
   ]b4_translate[
@@ -529,8 +531,8 @@ static const char *const yytname[] =
 #endif
 
 # ifdef YYPRINT
-/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
-   token YYLEX-NUM.  */
+/* YYTOKNUM[NUM] -- (External) token number corresponding to the
+   (internal) symbol number NUM (which must be that of a token).  */
 static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 {
   ]b4_toknum[
