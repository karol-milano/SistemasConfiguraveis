@@ -207,23 +207,19 @@ b4_token_enums(b4_tokens)
 [[typedef int YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1]])])[
 #endif
-
+]b4_locations_if([[
 #if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
 typedef struct YYLTYPE
 {
-]b4_locations_if([
   int first_line;
   int first_column;
   int last_line;
   int last_column;
-],[
-  char yydummy;
-])[
 } YYLTYPE;
 # define YYLTYPE_IS_DECLARED 1
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
-
+]])[
 ]b4_percent_code_get([[provides]])[]dnl
 ])
 
@@ -566,9 +562,8 @@ m4_if(b4_prefix[], [yy], [],
 #define b4_prefix[]char yychar
 #define b4_prefix[]lval yylval
 #define b4_prefix[]lloc yylloc])],
-[YYSTYPE yylval;
-
-YYLTYPE yylloc;
+[YYSTYPE yylval;]b4_locations_if([[
+YYLTYPE yylloc;]])[
 
 int yynerrs;
 int yychar;])[
@@ -774,9 +769,9 @@ struct yyGLRState {
     yySemanticOption* yyfirstVal;
     /** Semantic value for this state.  */
     YYSTYPE yysval;
-  } yysemantics;
+  } yysemantics;]b4_locations_if([[
   /** Source location for this state.  */
-  YYLTYPE yyloc;
+  YYLTYPE yyloc;]])[
 };
 
 struct yyGLRStateSet {
@@ -798,8 +793,8 @@ struct yySemanticOption {
   yyGLRState* yystate;
   /** The lookahead for this reduction.  */
   int yyrawchar;
-  YYSTYPE yyval;
-  YYLTYPE yyloc;
+  YYSTYPE yyval;]b4_locations_if([[
+  YYLTYPE yyloc;]])[
   /** Next sibling in chain of options.  To facilitate merging,
    *  options are chained in decreasing order by address.  */
   yySemanticOption* yynext;
@@ -820,8 +815,8 @@ struct yyGLRStack {
 [
   int yyerrcnt;
   int yyrawchar;
-  YYSTYPE yyval;
-  YYLTYPE yyloc;
+  YYSTYPE yyval;]b4_locations_if([[
+  YYLTYPE yyloc;]])[
 ])[
   YYJMP_BUF yyexception_buffer;
   yyGLRStackItem* yyitems;
@@ -880,8 +875,8 @@ yyfillin (yyGLRStackItem *yyvsp, int yylow0, int yylow1)
     {
       YYASSERT (s->yyresolved);
       yyvsp[i].yystate.yyresolved = yytrue;
-      yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;
-      yyvsp[i].yystate.yyloc = s->yyloc;
+      yyvsp[i].yystate.yysemantics.yysval = s->yysemantics.yysval;]b4_locations_if([[
+      yyvsp[i].yystate.yyloc = s->yyloc;]])[
       s = yyvsp[i].yystate.yypred = s->yypred;
     }
 }
