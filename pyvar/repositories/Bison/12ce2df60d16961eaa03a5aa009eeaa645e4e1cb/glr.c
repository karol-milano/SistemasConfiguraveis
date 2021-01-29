@@ -257,10 +257,20 @@ b4_syncline([@oline@], [@ofile@])
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
-#if __cplusplus
-# define YYUSE(e) (void) (e)
+#ifndef lint
+# define YYUSE(e) ((void) (e))
 #else
-# define YYUSE(e) do {;} while (/*CONSTCOND*/ yyfalse && (e))
+# define YYUSE(e) /* empty */
+#endif
+
+/* Identity function, used to suppress warnings about constant conditions.  */
+#ifndef lint
+# define YYID(n) (n)
+#else
+]b4_c_function_def([YYID], [static int], [[int i], [i]])[
+{
+  return i;
+}
 #endif
 
 #ifndef YYFREE
@@ -499,7 +509,7 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 	  (Current).first_column = (Current).last_column =		\
 	    YYRHSLOC (Rhs, 0).last_column;				\
 	}								\
-    while (/*CONSTCOND*/ 0)
+    while (YYID (0))
 
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
@@ -544,7 +554,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 
 #define YYCHK(YYE)							     \
    do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }	     \
-   while (/*CONSTCOND*/ 0)
+   while (YYID (0))
 
 #if YYDEBUG
 
@@ -556,7 +566,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 do {						\
   if (yydebug)					\
     YYFPRINTF Args;				\
-} while (/*CONSTCOND*/ 0)
+} while (YYID (0))
 
 ]b4_yysymprint_generate([b4_c_ansi_function_def])[
 
@@ -569,7 +579,7 @@ do {									    \
 		  Type, Value]b4_location_if([, Location])[]b4_user_args[); \
       YYFPRINTF (stderr, "\n");						    \
     }									    \
-} while (/*CONSTCOND*/ 0)
+} while (YYID (0))
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
@@ -620,13 +630,13 @@ int yydebug;
   do {							\
     if (Yystack->yyspaceLeft < YYHEADROOM)		\
       yyexpandGLRStack (Yystack);			\
-  } while (/*CONSTCOND*/ 0)
+  } while (YYID (0))
 #else
 # define YY_RESERVE_GLRSTACK(Yystack)			\
   do {							\
     if (Yystack->yyspaceLeft < YYHEADROOM)		\
       yyMemoryExhausted (Yystack);			\
-  } while (/*CONSTCOND*/ 0)
+  } while (YYID (0))
 #endif
 
 
@@ -862,7 +872,7 @@ yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
  *  value ($$), and yylocp points to place for location information
  *  (@@$). Returns yyok for normal return, yyaccept for YYACCEPT,
  *  yyerr for YYERROR, yyabort for YYABORT. */
-static YYRESULTTAG
+/*ARGSUSED*/ static YYRESULTTAG
 yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 	      YYSTYPE* yyvalp,
 	      YYLTYPE* YYOPTIONAL_LOC (yylocp),
@@ -919,7 +929,7 @@ b4_syncline([@oline@], [@ofile@])
 }
 
 
-static void
+/*ARGSUSED*/ static void
 yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 {
   YYUSE (yy0);
@@ -1360,13 +1370,13 @@ yydoAction (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 do {					\
   if (yydebug)				\
     yy_reduce_print Args;		\
-} while (/*CONSTCOND*/ 0)
+} while (YYID (0))
 
 /*----------------------------------------------------------.
 | Report that the RULE is going to be reduced on stack #K.  |
 `----------------------------------------------------------*/
 
-static inline void
+/*ARGSUSED*/ static inline void
 yy_reduce_print (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 		 YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
@@ -2003,7 +2013,7 @@ yyreportSyntaxError (yyGLRStack* yystack,
 /* Recover from a syntax error on YYSTACK, assuming that YYTOKENP,
    YYLVALP, and YYLLOCP point to the syntactic category, semantic
    value, and location of the look-ahead.  */
-static void
+/*ARGSUSED*/ static void
 yyrecoverSyntaxError (yyGLRStack* yystack,
 		      YYSTYPE* yylvalp,
 		      YYLTYPE* YYOPTIONAL_LOC (yyllocp)
@@ -2108,7 +2118,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
     default:								     \
       goto yybuglab;							     \
     }									     \
-  } while (/*CONSTCOND*/ 0)
+  } while (YYID (0))
 
 
 /*----------.
