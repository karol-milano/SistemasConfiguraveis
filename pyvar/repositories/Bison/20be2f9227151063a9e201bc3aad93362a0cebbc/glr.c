@@ -576,13 +576,7 @@ int yydebug;
 #define YYHEADROOM 2
 
 #ifndef YYSTACKEXPANDABLE
-# if (! defined __cplusplus \
-      || (]b4_locations_if([[defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
-	  && ]])[defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
 #  define YYSTACKEXPANDABLE 1
-# else
-#  define YYSTACKEXPANDABLE 0
-# endif
 #endif
 
 #if YYSTACKEXPANDABLE
