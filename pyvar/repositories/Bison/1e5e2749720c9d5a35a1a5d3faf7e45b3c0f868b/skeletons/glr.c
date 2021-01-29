@@ -346,7 +346,9 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
-#define YYTRANSLATE(YYX)                                                \
+]b4_api_token_raw_if(dnl
+[[#define YYTRANSLATE(YYX) (YYX)]],
+[[#define YYTRANSLATE(YYX)                         \
   ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
@@ -354,7 +356,7 @@ static YYLTYPE yyloc_default][]b4_yyloc_default;])[
 static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
 {
   ]b4_translate[
-};
+};]])[
 
 #if ]b4_api_PREFIX[DEBUG
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
