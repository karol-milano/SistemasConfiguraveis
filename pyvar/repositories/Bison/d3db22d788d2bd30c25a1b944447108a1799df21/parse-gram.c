@@ -608,7 +608,7 @@ union yyalloc
 
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
-#define YYTRANSLATE(YYX) (YYX)
+#define YYTRANSLATE(YYX) YY_CAST (yysymbol_type_t, YYX)
 
 #if GRAM_DEBUG
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
