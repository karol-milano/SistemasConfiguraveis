@@ -226,14 +226,10 @@ b4_syncline([@oline@], [@ofile@])[
 
 # ifdef YYSTACK_USE_ALLOCA
 #  if YYSTACK_USE_ALLOCA
-#   define YYSTACK_ALLOC alloca
-#  endif
-# else
-#  if defined (alloca) || defined (_ALLOCA_H)
-#   define YYSTACK_ALLOC alloca
-#  else
 #   ifdef __GNUC__
 #    define YYSTACK_ALLOC __builtin_alloca
+#   else
+#    define YYSTACK_ALLOC alloca
 #   endif
 #  endif
 # endif
@@ -648,10 +644,6 @@ int yydebug;
    SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
    evaluated with infinite-precision integer arithmetic.  */
 
-#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
-# undef YYMAXDEPTH
-#endif
-
 #ifndef YYMAXDEPTH
 # define YYMAXDEPTH ]b4_stack_depth_max[
 #endif
