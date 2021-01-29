@@ -404,22 +404,12 @@ typedef short int yytype_int16;
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
-#if ! defined lint || defined __GNUC__
+#ifdef __GNUC__
 # define YYUSE(e) ((void) (e))
 #else
 # define YYUSE(e) /* empty */
 #endif
 
-/* Identity function, used to suppress warnings about constant conditions.  */
-#ifndef lint
-# define YYID(n) (n)
-#else
-]b4_function_define([YYID], [static int], [[int yyi], [yyi]])[
-{
-  return yyi;
-}
-#endif
-
 #if ]b4_lac_if([[1]], [[! defined yyoverflow || YYERROR_VERBOSE]])[
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */]dnl
@@ -451,7 +441,7 @@ b4_push_if([], [b4_lac_if([], [[
 
 # ifdef YYSTACK_ALLOC
    /* Pacify GCC's `empty if-body' warning.  */
-#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
+#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
 #  ifndef YYSTACK_ALLOC_MAXIMUM
     /* The OS might guarantee only one guard page at the bottom of the stack,
        and a page size can be as small as 4096 bytes.  So we cannot safely
@@ -532,7 +522,7 @@ union yyalloc
         yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
         yyptr += yynewbytes / sizeof (*yyptr);                          \
       }                                                                 \
-    while (YYID (0))
+    while (0)
 
 #endif
 
@@ -551,7 +541,7 @@ union yyalloc
           for (yyi = 0; yyi < (Count); yyi++)   \
             (Dst)[yyi] = (Src)[yyi];            \
         }                                       \
-      while (YYID (0))
+      while (0)
 #  endif
 # endif
 #endif /* !YYCOPY_NEEDED */
@@ -648,7 +638,7 @@ do                                                              \
       yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")); \
       YYERROR;                                                  \
     }                                                           \
-while (YYID (0))
+while (0)
 
 
 #define YYTERROR        1
@@ -701,7 +691,7 @@ while (YYID (0))
 do {                                            \
   if (yydebug)                                  \
     YYFPRINTF Args;                             \
-} while (YYID (0))
+} while (0)
 
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
 do {                                                                      \
@@ -712,7 +702,7 @@ do {                                                                      \
                   Type, Value]b4_locations_if([, Location])[]b4_user_args[); \
       YYFPRINTF (stderr, "\n");                                           \
     }                                                                     \
-} while (YYID (0))
+} while (0)
 
 ]b4_yy_symbol_print_define[
 
@@ -738,7 +728,7 @@ do {                                                                      \
 do {                                                            \
   if (yydebug)                                                  \
     yy_stack_print ((Bottom), (Top));                           \
-} while (YYID (0))
+} while (0)
 
 
 /*------------------------------------------------.
@@ -774,7 +764,7 @@ do {                                                            \
 do {                                    \
   if (yydebug)                          \
     yy_reduce_print (yyssp, yyvsp, ]b4_locations_if([yylsp, ])[Rule]b4_user_args[); \
-} while (YYID (0))
+} while (0)
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
@@ -908,7 +898,7 @@ do {                                                             \
           goto yyerrlab;                                         \
       }                                                          \
     }                                                            \
-} while (YYID (0))
+} while (0)
 
 /* Discard any previous initial lookahead context because of Event,
    which may be a lookahead change or an invalidation of the currently
@@ -931,7 +921,7 @@ do {                                                                     \
                    Event "\n");                                          \
       yy_lac_established = 0;                                            \
     }                                                                    \
-} while (YYID (0))
+} while (0)
 #else
 # define YY_LAC_DISCARD(Event) yy_lac_established = 0
 #endif
@@ -1941,8 +1931,7 @@ yypushreturn:]])[
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
 #endif
-  /* Make sure YYID is used.  */
-  return YYID (yyresult);
+  return yyresult;
 }
 
 ]b4_epilogue[]dnl
