@@ -234,6 +234,9 @@ b4_syncline([@oline@], [@ofile@])
 # endif
 #endif
 
+/* Suppress unused-variable warnings by "using" E.  */
+#define YYUSE(e) do {;} while (/*CONSTCOND*/ yyfalse && (e))
+
 #ifndef YYFREE
 # define YYFREE free
 #endif
@@ -470,7 +473,7 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 	  (Current).first_column = (Current).last_column =		\
 	    YYRHSLOC (Rhs, 0).last_column;				\
 	}								\
-    while (0)
+    while (/*CONSTCOND*/ 0)
 
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
@@ -515,7 +518,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 
 #define YYCHK(YYE)							     \
    do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }	     \
-   while (0)
+   while (/*CONSTCOND*/ 0)
 
 #if YYDEBUG
 
@@ -527,7 +530,7 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 do {						\
   if (yydebug)					\
     YYFPRINTF Args;				\
-} while (0)
+} while (/*CONSTCOND*/ 0)
 
 ]b4_yysymprint_generate([b4_c_ansi_function_def])[
 
@@ -540,7 +543,7 @@ do {								\
                   Type, Value]b4_location_if([, Location])[);	\
       YYFPRINTF (stderr, "\n");					\
     }								\
-} while (0)
+} while (/*CONSTCOND*/ 0)
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
@@ -877,9 +880,8 @@ b4_syncline([@oline@], [@ofile@])
 static void
 yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 {
-  /* Suppress unused-variable warnings.  */
-  yy0 = yy0;
-  yy1 = yy1;
+  YYUSE (yy0);
+  YYUSE (yy1);
 
   switch (yyn)
     {
@@ -1306,7 +1308,7 @@ yydoAction (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 do {					\
   if (yydebug)				\
     yy_reduce_print (K, Rule);		\
-} while (0)
+} while (/*CONSTCOND*/ 0)
 
 /*----------------------------------------------------------.
 | Report that the RULE is going to be reduced on stack #K.  |
@@ -1621,9 +1623,8 @@ static void
 yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
 		   yyGLRStack* yystack]b4_pure_formals[)
 {
-  /* Suppress unused-variable warnings.  */
-  yyx0 = yyx0;
-  yyx1 = yyx1;
+  YYUSE (yyx0);
+  YYUSE (yyx1);
 
 #if YYDEBUG
   YYFPRINTF (stderr, "Ambiguity detected.\n");
@@ -1836,9 +1837,8 @@ static void
 yyreportSyntaxError (yyGLRStack* yystack,
 		     YYSTYPE* yylvalp, YYLTYPE* yyllocp]b4_user_formals[)
 {
-  /* Suppress unused-variable warnings.  */
-  yylvalp = yylvalp;
-  yyllocp = yyllocp;
+  YYUSE (yylvalp);
+  YYUSE (yyllocp);
 
   if (yystack->yyerrState == 0)
     {
@@ -2046,7 +2046,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
     default:								     \
       goto yybuglab;							     \
     }									     \
-  } while (0)
+  } while (/*CONSTCOND*/ 0)
 
 
 /*----------.
