@@ -175,6 +175,7 @@ int yychar;
 /* Suppress an incorrect diagnostic about yylval being uninitialized.  */
 # define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
     _Pragma ("GCC diagnostic push") \
+    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
     _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
 # define YY_IGNORE_MAYBE_UNINITIALIZED_END \
     _Pragma ("GCC diagnostic pop")
