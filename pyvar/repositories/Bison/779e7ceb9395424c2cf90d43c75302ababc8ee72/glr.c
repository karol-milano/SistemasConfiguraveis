@@ -137,7 +137,7 @@ m4_define([b4_rhs_location],
 m4_changecom()
 m4_divert(0)dnl
 @output @output_parser_name@
-b4_copyright([Skeleton parser for GLR parsing with Bison], [2002, 2003])
+b4_copyright([Skeleton parser for GLR parsing with Bison], [2002, 2003, 2004])
 [
 /* This is the parser code for GLR (Generalized LR) parser. */
 
@@ -282,7 +282,7 @@ b4_syncline([@oline@], [@ofile@])
 
 #define YYTRANSLATE(YYX)						\
   ((YYX <= 0) ? YYEOF :							\
-   (unsigned)(YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
+   (unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
 static const ]b4_int_type_for([b4_translate])[ yytranslate[] =
@@ -394,9 +394,9 @@ static const ]b4_int_type_for([b4_conflict_list_heads])[ yyconflp[] =
 /* YYCONFL[I] -- lists of conflicting rule numbers, each terminated by
    0, pointed into by YYCONFLP.  */
 ]dnl Do not use b4_int_type_for here, since there are places where
-dnl pointers onto yyconfl are taken, which type is "short *".
+dnl pointers onto yyconfl are taken, which type is "short int *".
 dnl We probably ought to introduce a type for confl.
-[static const short yyconfl[] =
+[static const short int yyconfl[] =
 {
   ]b4_conflicting_rules[
 };
@@ -552,10 +552,10 @@ typedef int yyStateNum;
 typedef int yyRuleNum;
 
 /** Grammar symbol */
-typedef short yySymbol;
+typedef short int yySymbol;
 
 /** Item references, as in LALR(1) machine */
-typedef short yyItemNum;
+typedef short int yyItemNum;
 
 typedef struct yyGLRState yyGLRState;
 typedef struct yySemanticOption yySemanticOption;
@@ -809,7 +809,7 @@ yydefaultAction (yyStateNum yystate)
  */
 static inline void
 yygetLRActions (yyStateNum yystate, int yytoken,
-	        int* yyaction, const short** yyconflicts)
+	        int* yyaction, const short int** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
   if (yyindex < 0 || YYLAST < yyindex || yycheck[yyindex] != yytoken)
@@ -1539,7 +1539,7 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 		  ]b4_user_formals[)
 {
   int yyaction;
-  const short* yyconflicts;
+  const short int* yyconflicts;
   yyRuleNum yyrule;
   yySymbol* const yytokenp = yystack->yytokenp;
 
@@ -1840,7 +1840,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 	{
 	  yyRuleNum yyrule;
 	  int yyaction;
-	  const short* yyconflicts;
+	  const short int* yyconflicts;
 
 	  yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
           YYDPRINTF ((stderr, "Entering state %d\n", yystate));
@@ -1942,7 +1942,7 @@ yy_yypstack (yyGLRState* yys)
       yy_yypstack (yys->yypred);
       fprintf (stderr, " -> ");
     }
-  fprintf (stderr, "%d@@%lu", yys->yylrState, (unsigned long) yys->yyposn);
+  fprintf (stderr, "%d@@%lu", yys->yylrState, (unsigned long int) yys->yyposn);
 }
 
 static void
@@ -1972,30 +1972,30 @@ yypdumpstack (yyGLRStack* yystack)
   size_t yyi;
   for (yyp = yystack->yyitems; yyp < yystack->yynextFree; yyp += 1)
     {
-      fprintf (stderr, "%3lu. ", (unsigned long) (yyp - yystack->yyitems));
+      fprintf (stderr, "%3lu. ", (unsigned long int) (yyp - yystack->yyitems));
       if (*(yybool *) yyp)
 	{
 	  fprintf (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
 		   yyp->yystate.yyresolved, yyp->yystate.yylrState,
-		   (unsigned long) yyp->yystate.yyposn,
-		   (long) YYINDEX (yyp->yystate.yypred));
+		   (unsigned long int) yyp->yystate.yyposn,
+		   (long int) YYINDEX (yyp->yystate.yypred));
 	  if (! yyp->yystate.yyresolved)
 	    fprintf (stderr, ", firstVal: %ld",
-		     (long) YYINDEX (yyp->yystate.yysemantics.yyfirstVal));
+		     (long int) YYINDEX (yyp->yystate.yysemantics.yyfirstVal));
 	}
       else
 	{
 	  fprintf (stderr, "Option. rule: %d, state: %ld, next: %ld",
 		   yyp->yyoption.yyrule,
-		   (long) YYINDEX (yyp->yyoption.yystate),
-		   (long) YYINDEX (yyp->yyoption.yynext));
+		   (long int) YYINDEX (yyp->yyoption.yystate),
+		   (long int) YYINDEX (yyp->yyoption.yynext));
 	}
       fprintf (stderr, "\n");
     }
   fprintf (stderr, "Tops:");
   for (yyi = 0; yyi < yystack->yytops.yysize; yyi += 1)
-    fprintf (stderr, "%lu: %ld; ", (unsigned long) yyi,
-	     (long) YYINDEX (yystack->yytops.yystates[yyi]));
+    fprintf (stderr, "%lu: %ld; ", (unsigned long int) yyi,
+	     (long int) YYINDEX (yystack->yytops.yystates[yyi]));
   fprintf (stderr, "\n");
 }
 ]
@@ -2003,7 +2003,7 @@ yypdumpstack (yyGLRStack* yystack)
 b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [@output @output_header_name@
-b4_copyright([Skeleton parser for GLR parsing with Bison], [2002, 2003])
+b4_copyright([Skeleton parser for GLR parsing with Bison], [2002, 2003, 2004])
 
 b4_token_defines(b4_tokens)
 
