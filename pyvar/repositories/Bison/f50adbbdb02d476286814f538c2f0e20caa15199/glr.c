@@ -169,10 +169,10 @@ typedef union b4_stype yystype;
 typedef struct yyltype
 {
 ]b4_location_if([
-  int yyfirst_line;
-  int yyfirst_column;
-  int yylast_line;
-  int yylast_column;])[
+  int first_line;
+  int first_column;
+  int last_line;
+  int last_column;])[
 } yyltype;
 # define YYLTYPE ]b4_ltype[
 # define YYLTYPE_IS_TRIVIAL 1
@@ -333,7 +333,8 @@ static const ]b4_int_type_for([b4_pgoto])[ yypgoto[] =
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
-   number is the opposite.  If zero, do what YYDEFACT says.  */
+   number is the opposite.  If zero, do what YYDEFACT says.
+   If YYTABLE_NINF, parse error.  */
 #define YYTABLE_NINF ]b4_table_ninf[
 static const ]b4_int_type_for([b4_table])[ yytable[] =
 {
@@ -396,10 +397,10 @@ int yyparse (void);
 
 #ifndef YYLLOC_DEFAULT
 # define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN)			\
-  yyCurrent.yyfirst_line   = YYRHSLOC(yyRhs,1).yyfirst_line;	\
-  yyCurrent.yyfirst_column = YYRHSLOC(yyRhs,1).yyfirst_column;	\
-  yyCurrent.yylast_line    = YYRHSLOC(yyRhs,YYN).yylast_line;	\
-  yyCurrent.yylast_column  = YYRHSLOC(yyRhs,YYN).yylast_column;
+  yyCurrent.first_line   = YYRHSLOC(yyRhs,1).first_line;	\
+  yyCurrent.first_column = YYRHSLOC(yyRhs,1).first_column;	\
+  yyCurrent.last_line    = YYRHSLOC(yyRhs,YYN).last_line;	\
+  yyCurrent.last_column  = YYRHSLOC(yyRhs,YYN).last_column;
 #endif
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
@@ -705,16 +706,21 @@ yygetLRActions (yyStateNum yystate, int yytoken,
 	        int* yyaction, const short** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
-  if (yyindex < 0 || yyindex > YYLAST || yycheck[yyindex] != yytoken)
+  if (yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
     {
       *yyaction = -yydefact[yystate];
       *yyconflicts = yyconfl;
     }
-  else
+  else if (yytable[yyindex] != YYTABLE_NINF)
     {
       *yyaction = yytable[yyindex];
       *yyconflicts = yyconfl + yyconflp[yyindex];
     }
+  else
+    {
+      *yyaction = 0;
+      *yyconflicts = yyconfl + yyconflp[yyindex];
+    }
 }
 
 static inline yyStateNum
@@ -722,7 +728,7 @@ yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
 {
   int yyr;
   yyr = yypgoto[yylhs - YYNTOKENS] + yystate;
-  if (yyr >= 0 && yyr <= YYLAST && yycheck[yyr] == yystate)
+  if (0 <= yyr && yyr <= YYLAST && yycheck[yyr] == yystate)
     return yytable[yyr];
   else
     return yydefgoto[yylhs - YYNTOKENS];
@@ -737,7 +743,7 @@ yyisShiftAction (int yyaction)
 static inline bool
 yyisErrorAction (int yyaction)
 {
-  return yyaction == 0 || yyaction == YYPACT_NINF;
+  return yyaction == 0;
 }
 
 				/* GLRStates */
@@ -1256,7 +1262,7 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
 }
 
 #if YYDEBUG
-static yyGLRState YYLEFTMOST_STATE = { 0, NULL, -1, 0, { NULL } };
+static yyGLRState YYLEFTMOST_STATE = { 0, 0, -1, NULL, 0, { NULL } };
 
 static void yyreportTree (yySemanticOption* yyx, int yyindent)
 {
@@ -1524,7 +1530,7 @@ yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	    {
 	      yyprefix = ", expecting ";
 	      for (yyx = yyn < 0 ? -yyn : 0; yyx < yytname_size; yyx += 1)
-		if (yycheck[yyx + yyn] == yyx)
+		if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 		  {
 		    yyp += sprintf (yyp, "%s%s", yyprefix, yytokenName (yyx));
 		    yyprefix = " or ";
@@ -1540,13 +1546,9 @@ yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
     }
 }
 
-/* Recover from a syntax error on STACK, assuming that TOKENP,
+/* Recover from a syntax error on YYSTACK, assuming that YYTOKENP,
    YYLVALP, and YYLLOCP point to the syntactic category, semantic
-   value, and location of the lookahead.
-   NOTE: This uses the panic-mode recovery algorithm described in the
-   Bison documentation, which differs from what is in bison.simple.
-   Specifically, this routine performs no reductions before shifting
-   the error token. */
+   value, and location of the lookahead.  */
 static void
 yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 {
@@ -1855,10 +1857,10 @@ b4_location_if(
 [#ifndef YYLTYPE
 typedef struct yyltype
 {
-  int yyfirst_line;
-  int yyfirst_column;
-  int yylast_line;
-  int yylast_column;
+  int first_line;
+  int first_column;
+  int last_line;
+  int last_column;
 } yyltype;
 # define YYLTYPE yyltype
 #endif
