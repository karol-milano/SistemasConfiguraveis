@@ -257,7 +257,11 @@ b4_syncline([@oline@], [@ofile@])
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
-#define YYUSE(e) do {;} while (/*CONSTCOND*/ yyfalse && (e))
+#if __cplusplus
+# define YYUSE(e) (void) (e)
+#else
+# define YYUSE(e) do {;} while (/*CONSTCOND*/ yyfalse && (e))
+#endif
 
 #ifndef YYFREE
 # define YYFREE free
@@ -868,8 +872,8 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   yybool yynormal __attribute__ ((__unused__)) =
     (yystack->yysplitPoint == NULL);
   int yylow;
-
-# undef yyerrok
+]b4_parse_param_use[]dnl
+[# undef yyerrok
 # define yyerrok (yystack->yyerrState = 0)
 # undef YYACCEPT
 # define YYACCEPT return yyaccept
@@ -1372,7 +1376,10 @@ yy_reduce_print (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
   yyGLRStackItem* yyvsp = (yyGLRStackItem*) yystack->yytops.yystates[yyk];
   int yylow = 1;
   int yyi;
-  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
+  YYUSE (yyvalp);
+  YYUSE (yylocp);
+]b4_parse_param_use[]dnl
+[  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
 	     (unsigned long int) yyk, yyrule - 1,
 	     (unsigned long int) yyrline[yyrule]);
   /* Print the symbols being reduced, and their result.  */
