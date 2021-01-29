@@ -608,7 +608,9 @@ union yyalloc
 
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
-#define YYTRANSLATE(YYX)                                                \
+]b4_api_token_raw_if(dnl
+[[#define YYTRANSLATE(YYX) (YYX)]],
+[[#define YYTRANSLATE(YYX)                                                \
   ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
@@ -616,7 +618,7 @@ union yyalloc
 static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 {
   ]b4_translate[
-};
+};]])[
 
 #if ]b4_api_PREFIX[DEBUG
 ]b4_integral_parser_table_define([rline], [b4_rline],
