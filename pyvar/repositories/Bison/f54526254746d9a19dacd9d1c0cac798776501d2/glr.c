@@ -510,7 +510,8 @@ int yydebug;
 
 #if (! defined (YYSTACKEXPANDABLE) \
      && (! defined (__cplusplus) \
-	 || (]b4_location_if([YYLTYPE_IS_TRIVIAL && ])[YYSTYPE_IS_TRIVIAL)))
+	 || (]b4_location_if([[defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
+	     && ]])[defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))
 #define YYSTACKEXPANDABLE 1
 #else
 #define YYSTACKEXPANDABLE 0
