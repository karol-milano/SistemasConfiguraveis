@@ -218,16 +218,16 @@ b4_syncline([@oline@], [@ofile@])[
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
 
-# if YYSTACK_USE_ALLOCA
-#  define YYSTACK_ALLOC alloca
+# ifdef YYSTACK_USE_ALLOCA
+#  if YYSTACK_USE_ALLOCA
+#   define YYSTACK_ALLOC alloca
+#  endif
 # else
-#  ifndef YYSTACK_USE_ALLOCA
-#   if defined (alloca) || defined (_ALLOCA_H)
-#    define YYSTACK_ALLOC alloca
-#   else
-#    ifdef __GNUC__
-#     define YYSTACK_ALLOC __builtin_alloca
-#    endif
+#  if defined (alloca) || defined (_ALLOCA_H)
+#   define YYSTACK_ALLOC alloca
+#  else
+#   ifdef __GNUC__
+#    define YYSTACK_ALLOC __builtin_alloca
 #   endif
 #  endif
 # endif
@@ -622,7 +622,7 @@ int yydebug;
    SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
    evaluated with infinite-precision integer arithmetic.  */
 
-#if YYMAXDEPTH == 0
+#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
 # undef YYMAXDEPTH
 #endif
 
