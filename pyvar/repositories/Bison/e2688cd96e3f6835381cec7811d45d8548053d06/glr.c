@@ -556,13 +556,14 @@ int yydebug;
    properly redirected to new data. */
 #define YYHEADROOM 2
 
-#if (! defined (YYSTACKEXPANDABLE) \
-     && (! defined (__cplusplus) \
-	 || (]b4_location_if([[defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
-	     && ]])[defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL)))
-#define YYSTACKEXPANDABLE 1
-#else
-#define YYSTACKEXPANDABLE 0
+#ifndef YYSTACKEXPANDABLE
+# if (! defined (__cplusplus) \
+      || (]b4_location_if([[defined (YYLTYPE_IS_TRIVIAL) && YYLTYPE_IS_TRIVIAL \
+	  && ]])[defined (YYSTYPE_IS_TRIVIAL) && YYSTYPE_IS_TRIVIAL))
+#  define YYSTACKEXPANDABLE 1
+# else
+#  define YYSTACKEXPANDABLE 0
+# endif
 #endif
 
 #if YYERROR_VERBOSE
@@ -812,6 +813,7 @@ yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
   switch (yyn)
     {
       b4_mergers
+      default: break;
     }
 }
 [
