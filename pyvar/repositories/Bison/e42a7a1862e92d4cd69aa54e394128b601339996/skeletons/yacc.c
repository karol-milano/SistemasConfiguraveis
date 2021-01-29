@@ -411,6 +411,15 @@ typedef short yytype_int16;
 
 ]b4_attribute_define[
 
+]b4_parse_assert_if([[#ifdef NDEBUG
+# define YY_ASSERT(E) ((void) (0 && (E)))
+#else
+# include <assert.h> /* INFRINGES ON USER NAME SPACE */
+# define YY_ASSERT(E) assert (E)
+#endif
+]],
+[[#define YY_ASSERT(E) ((void) (0 && (E)))]])[
+
 #if ]b4_lac_if([[1]], [[! defined yyoverflow || YYERROR_VERBOSE]])[
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */]dnl
@@ -1453,6 +1462,8 @@ yynewstate:
 | yynewstate -- set current state (the top of the stack) to yystate.  |
 `--------------------------------------------------------------------*/
 yysetstate:
+  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
+  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
   *yyssp = (yytype_int16) yystate;
 
   if (yyss + yystacksize - 1 <= yyssp)
@@ -1520,8 +1531,6 @@ yysetstate:
     }
 #endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */
 
-  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
-
   if (yystate == YYFINAL)
     YYACCEPT;
 
