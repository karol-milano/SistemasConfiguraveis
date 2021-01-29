@@ -631,13 +631,15 @@ union yyalloc
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
 ]b4_api_token_raw_if(dnl
-[[#define YYTRANSLATE(YYX) (YYX)]],
-[[#define YYTRANSLATE(YYX)                                                \
-  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYSYMBOL_YYUNDEF)
+[[#define YYTRANSLATE(YYX) YY_CAST (yysymbol_type_t, YYX)]],
+[[#define YYTRANSLATE(YYX)                                \
+  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
+   ? YY_CAST (yysymbol_type_t, yytranslate[YYX])        \
+   : YYSYMBOL_YYUNDEF)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex.  */
-static const yysymbol_type_t yytranslate[] =
+static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 {
   ]b4_translate[
 };]])[
