@@ -224,7 +224,7 @@ typedef struct YYLTYPE
 ])
 
 b4_defines_if([[#include "@basename(]b4_spec_defines_file[@)"]],
-	      [b4_shared_declarations])[
+              [b4_shared_declarations])[
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -361,7 +361,7 @@ b4_percent_code_get[]dnl
 #define YYUNDEFTOK  ]b4_undef_token_number[
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
-#define YYTRANSLATE(YYX)						\
+#define YYTRANSLATE(YYX)                                                \
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
@@ -506,32 +506,32 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 ]b4_locations_if([[
 #define YYRHSLOC(Rhs, K) ((Rhs)[K].yystate.yyloc)
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)				\
-    do									\
-      if (YYID (N))							\
-	{								\
-	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
-	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
-	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
-	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
-	}								\
-      else								\
-	{								\
-	  (Current).first_line   = (Current).last_line   =		\
-	    YYRHSLOC (Rhs, 0).last_line;				\
-	  (Current).first_column = (Current).last_column =		\
-	    YYRHSLOC (Rhs, 0).last_column;				\
-	}								\
+# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
+    do                                                                  \
+      if (YYID (N))                                                     \
+        {                                                               \
+          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
+          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
+          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
+          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
+        }                                                               \
+      else                                                              \
+        {                                                               \
+          (Current).first_line   = (Current).last_line   =              \
+            YYRHSLOC (Rhs, 0).last_line;                                \
+          (Current).first_column = (Current).last_column =              \
+            YYRHSLOC (Rhs, 0).last_column;                              \
+        }                                                               \
     while (YYID (0))
 
 /* YY_LOCATION_PRINT -- Print the location on the stream.
    This macro was not mandated originally: define only if we know
    we won't break user code: when these are the locations we know.  */
 
-# define YY_LOCATION_PRINT(File, Loc)			\
-    fprintf (File, "%d.%d-%d.%d",			\
-	     (Loc).first_line, (Loc).first_column,	\
-	     (Loc).last_line,  (Loc).last_column)
+# define YY_LOCATION_PRINT(File, Loc)                   \
+    fprintf (File, "%d.%d-%d.%d",                       \
+             (Loc).first_line, (Loc).first_column,      \
+             (Loc).last_line,  (Loc).last_column)
 #endif
 ]],[
 #ifndef YYLLOC_DEFAULT
@@ -573,8 +573,8 @@ static const int YYEMPTY = -2;
 
 typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 
-#define YYCHK(YYE)							     \
-   do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }	     \
+#define YYCHK(YYE)                                                           \
+   do { YYRESULTTAG yyflag = YYE; if (yyflag != yyok) return yyflag; }       \
    while (YYID (0))
 
 #if YYDEBUG
@@ -583,10 +583,10 @@ typedef enum { yyok, yyaccept, yyabort, yyerr } YYRESULTTAG;
 #  define YYFPRINTF fprintf
 # endif
 
-# define YYDPRINTF(Args)			\
-do {						\
-  if (yydebug)					\
-    YYFPRINTF Args;				\
+# define YYDPRINTF(Args)                        \
+do {                                            \
+  if (yydebug)                                  \
+    YYFPRINTF Args;                             \
 } while (YYID (0))
 
 ]b4_yy_symbol_print_generate([b4_c_ansi_function_def])[
@@ -613,7 +613,7 @@ int yydebug;
 #endif /* !YYDEBUG */
 
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
-#ifndef	YYINITDEPTH
+#ifndef YYINITDEPTH
 # define YYINITDEPTH ]b4_stack_depth_init[
 #endif
 
@@ -638,7 +638,7 @@ int yydebug;
 #ifndef YYSTACKEXPANDABLE
 # if (! defined __cplusplus \
       || (]b4_locations_if([[defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
-	  && ]])[defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
+          && ]])[defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL))
 #  define YYSTACKEXPANDABLE 1
 # else
 #  define YYSTACKEXPANDABLE 0
@@ -646,16 +646,16 @@ int yydebug;
 #endif
 
 #if YYSTACKEXPANDABLE
-# define YY_RESERVE_GLRSTACK(Yystack)			\
-  do {							\
-    if (Yystack->yyspaceLeft < YYHEADROOM)		\
-      yyexpandGLRStack (Yystack);			\
+# define YY_RESERVE_GLRSTACK(Yystack)                   \
+  do {                                                  \
+    if (Yystack->yyspaceLeft < YYHEADROOM)              \
+      yyexpandGLRStack (Yystack);                       \
   } while (YYID (0))
 #else
-# define YY_RESERVE_GLRSTACK(Yystack)			\
-  do {							\
-    if (Yystack->yyspaceLeft < YYHEADROOM)		\
-      yyMemoryExhausted (Yystack);			\
+# define YY_RESERVE_GLRSTACK(Yystack)                   \
+  do {                                                  \
+    if (Yystack->yyspaceLeft < YYHEADROOM)              \
+      yyMemoryExhausted (Yystack);                      \
   } while (YYID (0))
 #endif
 
@@ -699,27 +699,27 @@ yytnamerr (char *yyres, const char *yystr)
       char const *yyp = yystr;
 
       for (;;)
-	switch (*++yyp)
-	  {
-	  case '\'':
-	  case ',':
-	    goto do_not_strip_quotes;
-
-	  case '\\':
-	    if (*++yyp != '\\')
-	      goto do_not_strip_quotes;
-	    /* Fall through.  */
-	  default:
-	    if (yyres)
-	      yyres[yyn] = *yyp;
-	    yyn++;
-	    break;
-
-	  case '"':
-	    if (yyres)
-	      yyres[yyn] = '\0';
-	    return yyn;
-	  }
+        switch (*++yyp)
+          {
+          case '\'':
+          case ',':
+            goto do_not_strip_quotes;
+
+          case '\\':
+            if (*++yyp != '\\')
+              goto do_not_strip_quotes;
+            /* Fall through.  */
+          default:
+            if (yyres)
+              yyres[yyn] = *yyp;
+            yyn++;
+            break;
+
+          case '"':
+            if (yyres)
+              yyres[yyn] = '\0';
+            return yyn;
+          }
     do_not_strip_quotes: ;
     }
 
@@ -904,8 +904,8 @@ yyfill (yyGLRStackItem *yyvsp, int *yylow, int yylow1, yybool yynormal)
  *  yyerr for YYERROR, yyabort for YYABORT.  */
 /*ARGSUSED*/ static YYRESULTTAG
 yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
-	      yyGLRStack* yystackp,
-	      YYSTYPE* yyvalp]b4_locuser_formals[)
+              yyGLRStack* yystackp,
+              YYSTYPE* yyvalp]b4_locuser_formals[)
 {
   yybool yynormal __attribute__ ((__unused__)) =
     (yystackp->yysplitPoint == YY_NULL);
@@ -926,9 +926,9 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 # undef YYFILL
 # define YYFILL(N) yyfill (yyvsp, &yylow, N, yynormal)
 # undef YYBACKUP
-# define YYBACKUP(Token, Value)						     \
+# define YYBACKUP(Token, Value)                                              \
   return yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")),     \
-	 yyerrok, yyerr
+         yyerrok, yyerr
 
   yylow = 1;
   if (yyrhslen == 0)
@@ -968,7 +968,7 @@ yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
     }
 }
 
-			      /* Bison grammar-table manipulation.  */
+                              /* Bison grammar-table manipulation.  */
 
 ]b4_yydestruct_generate([b4_c_ansi_function_def])[
 
@@ -984,32 +984,32 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 {
   if (yys->yyresolved)
     yydestruct (yymsg, yystos[yys->yylrState],
-		&yys->yysemantics.yysval]b4_locuser_args([&yys->yyloc])[);
+                &yys->yysemantics.yysval]b4_locuser_args([&yys->yyloc])[);
   else
     {
 #if YYDEBUG
       if (yydebug)
-	{
-	  if (yys->yysemantics.yyfirstVal)
-	    YYFPRINTF (stderr, "%s unresolved ", yymsg);
-	  else
-	    YYFPRINTF (stderr, "%s incomplete ", yymsg);
-	  yy_symbol_print (stderr, yystos[yys->yylrState],
-			   YY_NULL]b4_locuser_args([&yys->yyloc])[);
-	  YYFPRINTF (stderr, "\n");
-	}
+        {
+          if (yys->yysemantics.yyfirstVal)
+            YYFPRINTF (stderr, "%s unresolved ", yymsg);
+          else
+            YYFPRINTF (stderr, "%s incomplete ", yymsg);
+          yy_symbol_print (stderr, yystos[yys->yylrState],
+                           YY_NULL]b4_locuser_args([&yys->yyloc])[);
+          YYFPRINTF (stderr, "\n");
+        }
 #endif
 
       if (yys->yysemantics.yyfirstVal)
-	{
-	  yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
-	  yyGLRState *yyrh;
-	  int yyn;
-	  for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
-	       yyn > 0;
-	       yyrh = yyrh->yypred, yyn -= 1)
-	    yydestroyGLRState (yymsg, yyrh]b4_user_args[);
-	}
+        {
+          yySemanticOption *yyoption = yys->yysemantics.yyfirstVal;
+          yyGLRState *yyrh;
+          int yyn;
+          for (yyrh = yyoption->yystate, yyn = yyrhsLength (yyoption->yyrule);
+               yyn > 0;
+               yyrh = yyrh->yypred, yyn -= 1)
+            yydestroyGLRState (yymsg, yyrh]b4_user_args[);
+        }
     }
 }
 
@@ -1051,7 +1051,7 @@ yydefaultAction (yyStateNum yystate)
  */
 static inline void
 yygetLRActions (yyStateNum yystate, int yytoken,
-		int* yyaction, const short int** yyconflicts)
+                int* yyaction, const short int** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
   if (yypact_value_is_default (yypact[yystate])
@@ -1095,7 +1095,7 @@ yyisErrorAction (int yyaction)
   return yyaction == 0;
 }
 
-				/* GLRStates */
+                                /* GLRStates */
 
 /** Return a fresh GLRStackItem.  Callers should call
  * YY_RESERVE_GLRSTACK afterwards to make sure there is sufficient
@@ -1117,7 +1117,7 @@ yynewGLRStackItem (yyGLRStack* yystackp, yybool yyisState)
  *  stack #K of *STACKP. */
 static void
 yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
-		     yyGLRState* rhs, yyRuleNum yyrule)
+                     yyGLRState* rhs, yyRuleNum yyrule)
 {
   yySemanticOption* yynewOption =
     &yynewGLRStackItem (yystackp, yyfalse)->yyoption;
@@ -1137,7 +1137,7 @@ yyaddDeferredAction (yyGLRStack* yystackp, size_t yyk, yyGLRState* yystate,
   YY_RESERVE_GLRSTACK (yystackp);
 }
 
-				/* GLRStacks */
+                                /* GLRStacks */
 
 /** Initialize SET to a singleton set containing an empty stack.  */
 static yybool
@@ -1215,35 +1215,35 @@ yyexpandGLRStack (yyGLRStack* yystackp)
     {
       *yyp1 = *yyp0;
       if (*(yybool *) yyp0)
-	{
-	  yyGLRState* yys0 = &yyp0->yystate;
-	  yyGLRState* yys1 = &yyp1->yystate;
-	  if (yys0->yypred != YY_NULL)
-	    yys1->yypred =
-	      YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
-	  if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULL)
-	    yys1->yysemantics.yyfirstVal =
-	      YYRELOC(yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
-	}
+        {
+          yyGLRState* yys0 = &yyp0->yystate;
+          yyGLRState* yys1 = &yyp1->yystate;
+          if (yys0->yypred != YY_NULL)
+            yys1->yypred =
+              YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
+          if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != YY_NULL)
+            yys1->yysemantics.yyfirstVal =
+              YYRELOC(yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
+        }
       else
-	{
-	  yySemanticOption* yyv0 = &yyp0->yyoption;
-	  yySemanticOption* yyv1 = &yyp1->yyoption;
-	  if (yyv0->yystate != YY_NULL)
-	    yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
-	  if (yyv0->yynext != YY_NULL)
-	    yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
-	}
+        {
+          yySemanticOption* yyv0 = &yyp0->yyoption;
+          yySemanticOption* yyv1 = &yyp1->yyoption;
+          if (yyv0->yystate != YY_NULL)
+            yyv1->yystate = YYRELOC (yyp0, yyp1, yyv0->yystate, yystate);
+          if (yyv0->yynext != YY_NULL)
+            yyv1->yynext = YYRELOC (yyp0, yyp1, yyv0->yynext, yyoption);
+        }
     }
   if (yystackp->yysplitPoint != YY_NULL)
     yystackp->yysplitPoint = YYRELOC (yystackp->yyitems, yynewItems,
-				 yystackp->yysplitPoint, yystate);
+                                 yystackp->yysplitPoint, yystate);
 
   for (yyn = 0; yyn < yystackp->yytops.yysize; yyn += 1)
     if (yystackp->yytops.yystates[yyn] != YY_NULL)
       yystackp->yytops.yystates[yyn] =
-	YYRELOC (yystackp->yyitems, yynewItems,
-		 yystackp->yytops.yystates[yyn], yystate);
+        YYRELOC (yystackp->yyitems, yynewItems,
+                 yystackp->yytops.yystates[yyn], yystate);
   YYFREE (yystackp->yyitems);
   yystackp->yyitems = yynewItems;
   yystackp->yynextFree = yynewItems + yysize;
@@ -1299,30 +1299,30 @@ yyremoveDeletes (yyGLRStack* yystackp)
   while (yyj < yystackp->yytops.yysize)
     {
       if (yystackp->yytops.yystates[yyi] == YY_NULL)
-	{
-	  if (yyi == yyj)
-	    {
-	      YYDPRINTF ((stderr, "Removing dead stacks.\n"));
-	    }
-	  yystackp->yytops.yysize -= 1;
-	}
+        {
+          if (yyi == yyj)
+            {
+              YYDPRINTF ((stderr, "Removing dead stacks.\n"));
+            }
+          yystackp->yytops.yysize -= 1;
+        }
       else
-	{
-	  yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
-	  /* In the current implementation, it's unnecessary to copy
-	     yystackp->yytops.yylookaheadNeeds[yyi] since, after
-	     yyremoveDeletes returns, the parser immediately either enters
-	     deterministic operation or shifts a token.  However, it doesn't
-	     hurt, and the code might evolve to need it.  */
-	  yystackp->yytops.yylookaheadNeeds[yyj] =
-	    yystackp->yytops.yylookaheadNeeds[yyi];
-	  if (yyj != yyi)
-	    {
-	      YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
-			  (unsigned long int) yyi, (unsigned long int) yyj));
-	    }
-	  yyj += 1;
-	}
+        {
+          yystackp->yytops.yystates[yyj] = yystackp->yytops.yystates[yyi];
+          /* In the current implementation, it's unnecessary to copy
+             yystackp->yytops.yylookaheadNeeds[yyi] since, after
+             yyremoveDeletes returns, the parser immediately either enters
+             deterministic operation or shifts a token.  However, it doesn't
+             hurt, and the code might evolve to need it.  */
+          yystackp->yytops.yylookaheadNeeds[yyj] =
+            yystackp->yytops.yylookaheadNeeds[yyi];
+          if (yyj != yyi)
+            {
+              YYDPRINTF ((stderr, "Rename stack %lu -> %lu.\n",
+                          (unsigned long int) yyi, (unsigned long int) yyj));
+            }
+          yyj += 1;
+        }
       yyi += 1;
     }
 }
@@ -1331,8 +1331,8 @@ yyremoveDeletes (yyGLRStack* yystackp)
  * LRSTATE, at input position POSN, with (resolved) semantic value SVAL.  */
 static inline void
 yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
-	    size_t yyposn,
-	    YYSTYPE* yyvalp]b4_locations_if([, YYLTYPE* yylocp])[)
+            size_t yyposn,
+            YYSTYPE* yyvalp]b4_locations_if([, YYLTYPE* yylocp])[)
 {
   yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
 
@@ -1352,7 +1352,7 @@ yyglrShift (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
  *  semantic value of YYRHS under the action for YYRULE.  */
 static inline void
 yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
-		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
+                 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule)
 {
   yyGLRState* yynewState = &yynewGLRStackItem (yystackp, yytrue)->yystate;
 
@@ -1375,7 +1375,7 @@ yyglrShiftDefer (yyGLRStack* yystackp, size_t yyk, yyStateNum yylrState,
  *  for userAction.  */
 static inline YYRESULTTAG
 yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
-	    YYSTYPE* yyvalp]b4_locuser_formals[)
+            YYSTYPE* yyvalp]b4_locuser_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);
 
@@ -1388,7 +1388,7 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       yystackp->yyspaceLeft += yynrhs;
       yystackp->yytops.yystates[0] = & yystackp->yynextFree[-1].yystate;
       return yyuserAction (yyrule, yynrhs, rhs, yystackp,
-			   yyvalp]b4_locuser_args[);
+                           yyvalp]b4_locuser_args[);
     }
   else
     {
@@ -1400,29 +1400,29 @@ yydoAction (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       yyGLRState* yys;
       yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
       yys = yyrhsVals[YYMAXRHS + YYMAXLEFT].yystate.yypred
-	= yystackp->yytops.yystates[yyk];]b4_locations_if([[
+        = yystackp->yytops.yystates[yyk];]b4_locations_if([[
       if (yynrhs == 0)
-	/* Set default location.  */
-	yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;]])[
+        /* Set default location.  */
+        yyrhsVals[YYMAXRHS + YYMAXLEFT - 1].yystate.yyloc = yys->yyloc;]])[
       for (yyi = 0; yyi < yynrhs; yyi += 1)
-	{
-	  yys = yys->yypred;
-	  YYASSERT (yys);
-	}
+        {
+          yys = yys->yypred;
+          YYASSERT (yys);
+        }
       yyupdateSplit (yystackp, yys);
       yystackp->yytops.yystates[yyk] = yys;
       return yyuserAction (yyrule, yynrhs, yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
-			   yystackp, yyvalp]b4_locuser_args[);
+                           yystackp, yyvalp]b4_locuser_args[);
     }
 }
 
 #if !YYDEBUG
 # define YY_REDUCE_PRINT(Args)
 #else
-# define YY_REDUCE_PRINT(Args)		\
-do {					\
-  if (yydebug)				\
-    yy_reduce_print Args;		\
+# define YY_REDUCE_PRINT(Args)          \
+do {                                    \
+  if (yydebug)                          \
+    yy_reduce_print Args;               \
 } while (YYID (0))
 
 /*----------------------------------------------------------.
@@ -1431,7 +1431,7 @@ do {					\
 
 /*ARGSUSED*/ static inline void
 yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
-		 YYSTYPE* yyvalp]b4_locuser_formals[)
+                 YYSTYPE* yyvalp]b4_locuser_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);
   yybool yynormal __attribute__ ((__unused__)) =
@@ -1443,16 +1443,16 @@ yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
   YYUSE (yylocp);])[
 ]b4_parse_param_use[]dnl
 [  YYFPRINTF (stderr, "Reducing stack %lu by rule %d (line %lu):\n",
-	     (unsigned long int) yyk, yyrule - 1,
-	     (unsigned long int) yyrline[yyrule]);
+             (unsigned long int) yyk, yyrule - 1,
+             (unsigned long int) yyrline[yyrule]);
   /* The symbols being reduced.  */
   for (yyi = 0; yyi < yynrhs; yyi++)
     {
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
-		       &]b4_rhs_value(yynrhs, yyi + 1)[
-		       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
-		       b4_user_args[);
+                       &]b4_rhs_value(yynrhs, yyi + 1)[
+                       ]b4_locations_if([, &]b4_rhs_location(yynrhs, yyi + 1))[]dnl
+                       b4_user_args[);
       YYFPRINTF (stderr, "\n");
     }
 }
@@ -1471,7 +1471,7 @@ yy_reduce_print (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
  */
 static inline YYRESULTTAG
 yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
-	     yybool yyforceEval]b4_user_formals[)
+             yybool yyforceEval]b4_user_formals[)
 {
   size_t yyposn = yystackp->yytops.yystates[yyk]->yyposn;
 
@@ -1484,9 +1484,9 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       YYCHK (yydoAction (yystackp, yyk, yyrule, &yysval]b4_locuser_args([&yyloc])[));
       YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyrule], &yysval, &yyloc);
       yyglrShift (yystackp, yyk,
-		  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
-				 yylhsNonterm (yyrule)),
-		  yyposn, &yysval]b4_locations_if([, &yyloc])[);
+                  yyLRgotoState (yystackp->yytops.yystates[yyk]->yylrState,
+                                 yylhsNonterm (yyrule)),
+                  yyposn, &yysval]b4_locations_if([, &yyloc])[);
     }
   else
     {
@@ -1496,35 +1496,35 @@ yyglrReduce (yyGLRStack* yystackp, size_t yyk, yyRuleNum yyrule,
       yyStateNum yynewLRState;
 
       for (yys = yystackp->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
-	   0 < yyn; yyn -= 1)
-	{
-	  yys = yys->yypred;
-	  YYASSERT (yys);
-	}
+           0 < yyn; yyn -= 1)
+        {
+          yys = yys->yypred;
+          YYASSERT (yys);
+        }
       yyupdateSplit (yystackp, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
       YYDPRINTF ((stderr,
-		  "Reduced stack %lu by rule #%d; action deferred.  Now in state %d.\n",
-		  (unsigned long int) yyk, yyrule - 1, yynewLRState));
+                  "Reduced stack %lu by rule #%d; action deferred.  Now in state %d.\n",
+                  (unsigned long int) yyk, yyrule - 1, yynewLRState));
       for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
-	if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULL)
-	  {
-	    yyGLRState* yyp, *yysplit = yystackp->yysplitPoint;
-	    yyp = yystackp->yytops.yystates[yyi];
-	    while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
-	      {
-		if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
-		  {
-		    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
-		    yymarkStackDeleted (yystackp, yyk);
-		    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
-				(unsigned long int) yyk,
-				(unsigned long int) yyi));
-		    return yyok;
-		  }
-		yyp = yyp->yypred;
-	      }
-	  }
+        if (yyi != yyk && yystackp->yytops.yystates[yyi] != YY_NULL)
+          {
+            yyGLRState* yyp, *yysplit = yystackp->yysplitPoint;
+            yyp = yystackp->yytops.yystates[yyi];
+            while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
+              {
+                if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
+                  {
+                    yyaddDeferredAction (yystackp, yyk, yyp, yys0, yyrule);
+                    yymarkStackDeleted (yystackp, yyk);
+                    YYDPRINTF ((stderr, "Merging stack %lu into stack %lu.\n",
+                                (unsigned long int) yyk,
+                                (unsigned long int) yyi));
+                    return yyok;
+                  }
+                yyp = yyp->yypred;
+              }
+          }
       yystackp->yytops.yystates[yyk] = yys;
       yyglrShiftDefer (yystackp, yyk, yynewLRState, yyposn, yys0, yyrule);
     }
@@ -1547,24 +1547,24 @@ yysplitStack (yyGLRStack* yystackp, size_t yyk)
       yynewStates = YY_NULL;
 
       if (yystackp->yytops.yycapacity
-	  > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
-	yyMemoryExhausted (yystackp);
+          > (YYSIZEMAX / (2 * sizeof yynewStates[0])))
+        yyMemoryExhausted (yystackp);
       yystackp->yytops.yycapacity *= 2;
 
       yynewStates =
-	(yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
-				  (yystackp->yytops.yycapacity
-				   * sizeof yynewStates[0]));
+        (yyGLRState**) YYREALLOC (yystackp->yytops.yystates,
+                                  (yystackp->yytops.yycapacity
+                                   * sizeof yynewStates[0]));
       if (yynewStates == YY_NULL)
-	yyMemoryExhausted (yystackp);
+        yyMemoryExhausted (yystackp);
       yystackp->yytops.yystates = yynewStates;
 
       yynewLookaheadNeeds =
-	(yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
-			     (yystackp->yytops.yycapacity
-			      * sizeof yynewLookaheadNeeds[0]));
+        (yybool*) YYREALLOC (yystackp->yytops.yylookaheadNeeds,
+                             (yystackp->yytops.yycapacity
+                              * sizeof yynewLookaheadNeeds[0]));
       if (yynewLookaheadNeeds == YY_NULL)
-	yyMemoryExhausted (yystackp);
+        yyMemoryExhausted (yystackp);
       yystackp->yytops.yylookaheadNeeds = yynewLookaheadNeeds;
     }
   yystackp->yytops.yystates[yystackp->yytops.yysize]
@@ -1586,11 +1586,11 @@ yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
       yyGLRState *yys0, *yys1;
       int yyn;
       for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
-	   yyn = yyrhsLength (yyy0->yyrule);
-	   yyn > 0;
-	   yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
-	if (yys0->yyposn != yys1->yyposn)
-	  return yyfalse;
+           yyn = yyrhsLength (yyy0->yyrule);
+           yyn > 0;
+           yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
+        if (yys0->yyposn != yys1->yyposn)
+          return yyfalse;
       return yytrue;
     }
   else
@@ -1610,43 +1610,43 @@ yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
        yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
     {
       if (yys0 == yys1)
-	break;
+        break;
       else if (yys0->yyresolved)
-	{
-	  yys1->yyresolved = yytrue;
-	  yys1->yysemantics.yysval = yys0->yysemantics.yysval;
-	}
+        {
+          yys1->yyresolved = yytrue;
+          yys1->yysemantics.yysval = yys0->yysemantics.yysval;
+        }
       else if (yys1->yyresolved)
-	{
-	  yys0->yyresolved = yytrue;
-	  yys0->yysemantics.yysval = yys1->yysemantics.yysval;
-	}
+        {
+          yys0->yyresolved = yytrue;
+          yys0->yysemantics.yysval = yys1->yysemantics.yysval;
+        }
       else
-	{
-	  yySemanticOption** yyz0p;
-	  yySemanticOption* yyz1;
-	  yyz0p = &yys0->yysemantics.yyfirstVal;
-	  yyz1 = yys1->yysemantics.yyfirstVal;
-	  while (YYID (yytrue))
-	    {
-	      if (yyz1 == *yyz0p || yyz1 == YY_NULL)
-		break;
-	      else if (*yyz0p == YY_NULL)
-		{
-		  *yyz0p = yyz1;
-		  break;
-		}
-	      else if (*yyz0p < yyz1)
-		{
-		  yySemanticOption* yyz = *yyz0p;
-		  *yyz0p = yyz1;
-		  yyz1 = yyz1->yynext;
-		  (*yyz0p)->yynext = yyz;
-		}
-	      yyz0p = &(*yyz0p)->yynext;
-	    }
-	  yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
-	}
+        {
+          yySemanticOption** yyz0p;
+          yySemanticOption* yyz1;
+          yyz0p = &yys0->yysemantics.yyfirstVal;
+          yyz1 = yys1->yysemantics.yyfirstVal;
+          while (YYID (yytrue))
+            {
+              if (yyz1 == *yyz0p || yyz1 == YY_NULL)
+                break;
+              else if (*yyz0p == YY_NULL)
+                {
+                  *yyz0p = yyz1;
+                  break;
+                }
+              else if (*yyz0p < yyz1)
+                {
+                  yySemanticOption* yyz = *yyz0p;
+                  *yyz0p = yyz1;
+                  yyz1 = yyz1->yynext;
+                  (*yyz0p)->yynext = yyz;
+                }
+              yyz0p = &(*yyz0p)->yynext;
+            }
+          yys1->yysemantics.yyfirstVal = yys0->yysemantics.yyfirstVal;
+        }
     }
 }
 
@@ -1662,9 +1662,9 @@ yypreference (yySemanticOption* y0, yySemanticOption* y1)
   if (p0 == p1)
     {
       if (yymerger[r0] == 0 || yymerger[r0] != yymerger[r1])
-	return 0;
+        return 0;
       else
-	return 1;
+        return 1;
     }
   if (p0 == 0 || p1 == 0)
     return 0;
@@ -1676,7 +1676,7 @@ yypreference (yySemanticOption* y0, yySemanticOption* y1)
 }
 
 static YYRESULTTAG yyresolveValue (yyGLRState* yys,
-				   yyGLRStack* yystackp]b4_user_formals[);
+                                   yyGLRStack* yystackp]b4_user_formals[);
 
 
 /** Resolve the previous N states starting at and including state S.  If result
@@ -1686,14 +1686,14 @@ static YYRESULTTAG yyresolveValue (yyGLRState* yys,
  *  if necessary.  */
 static YYRESULTTAG
 yyresolveStates (yyGLRState* yys, int yyn,
-		 yyGLRStack* yystackp]b4_user_formals[)
+                 yyGLRStack* yystackp]b4_user_formals[)
 {
   if (0 < yyn)
     {
       YYASSERT (yys->yypred);
       YYCHK (yyresolveStates (yys->yypred, yyn-1, yystackp]b4_user_args[));
       if (! yys->yyresolved)
-	YYCHK (yyresolveValue (yys, yystackp]b4_user_args[));
+        YYCHK (yyresolveValue (yys, yystackp]b4_user_args[));
     }
   return yyok;
 }
@@ -1704,7 +1704,7 @@ yyresolveStates (yyGLRState* yys, int yyn,
  *  semantic values if invoked).  */
 static YYRESULTTAG
 yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
-		 YYSTYPE* yyvalp]b4_locuser_formals[)
+                 YYSTYPE* yyvalp]b4_locuser_formals[)
 {
   yyGLRStackItem yyrhsVals[YYMAXRHS + YYMAXLEFT + 1];
   int yynrhs;
@@ -1719,7 +1719,7 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
     {
       yyGLRState *yys;
       for (yys = yyopt->yystate; yynrhs > 0; yys = yys->yypred, yynrhs -= 1)
-	yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
+        yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
       return yyflag;
     }
 
@@ -1734,8 +1734,8 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystackp,
   yylval = yyopt->yyval;]b4_locations_if([
   yylloc = yyopt->yyloc;])[
   yyflag = yyuserAction (yyopt->yyrule, yynrhs,
-			 yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
-			 yystackp, yyvalp]b4_locuser_args[);
+                         yyrhsVals + YYMAXRHS + YYMAXLEFT - 1,
+                         yystackp, yyvalp]b4_locuser_args[);
   yychar = yychar_current;
   yylval = yylval_current;]b4_locations_if([
   yylloc = yylloc_current;])[
@@ -1764,35 +1764,35 @@ yyreportTree (yySemanticOption* yyx, int yyindent)
 
   if (yyx->yystate->yyposn < yys->yyposn + 1)
     YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
-	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
-	       yyx->yyrule - 1);
+               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
+               yyx->yyrule - 1);
   else
     YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %lu .. %lu>\n",
-	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
-	       yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
-	       (unsigned long int) yyx->yystate->yyposn);
+               yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
+               yyx->yyrule - 1, (unsigned long int) (yys->yyposn + 1),
+               (unsigned long int) yyx->yystate->yyposn);
   for (yyi = 1; yyi <= yynrhs; yyi += 1)
     {
       if (yystates[yyi]->yyresolved)
-	{
-	  if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
-	    YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
-		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]));
-	  else
-	    YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
-		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]),
-		       (unsigned long int) (yystates[yyi - 1]->yyposn + 1),
-		       (unsigned long int) yystates[yyi]->yyposn);
-	}
+        {
+          if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
+            YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
+                       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]));
+          else
+            YYFPRINTF (stderr, "%*s%s <tokens %lu .. %lu>\n", yyindent+2, "",
+                       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]),
+                       (unsigned long int) (yystates[yyi - 1]->yyposn + 1),
+                       (unsigned long int) yystates[yyi]->yyposn);
+        }
       else
-	yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
+        yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
     }
 }
 #endif
 
 /*ARGSUSED*/ static YYRESULTTAG
 yyreportAmbiguity (yySemanticOption* yyx0,
-		   yySemanticOption* yyx1]b4_pure_formals[)
+                   yySemanticOption* yyx1]b4_pure_formals[)
 {
   YYUSE (yyx0);
   YYUSE (yyx1);
@@ -1815,56 +1815,56 @@ yyreportAmbiguity (yySemanticOption* yyx0,
  *  is always chosen.  */
 static void
 yyresolveLocations (yyGLRState* yys1, int yyn1,
-		    yyGLRStack *yystackp]b4_user_formals[)
+                    yyGLRStack *yystackp]b4_user_formals[)
 {
   if (0 < yyn1)
     {
       yyresolveLocations (yys1->yypred, yyn1 - 1, yystackp]b4_user_args[);
       if (!yys1->yyresolved)
-	{
-	  yySemanticOption *yyoption;
-	  yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
-	  int yynrhs;
-	  int yychar_current;
-	  YYSTYPE yylval_current;
-	  YYLTYPE yylloc_current;
-	  yyoption = yys1->yysemantics.yyfirstVal;
-	  YYASSERT (yyoption != YY_NULL);
-	  yynrhs = yyrhsLength (yyoption->yyrule);
-	  if (yynrhs > 0)
-	    {
-	      yyGLRState *yys;
-	      int yyn;
-	      yyresolveLocations (yyoption->yystate, yynrhs,
-				  yystackp]b4_user_args[);
-	      for (yys = yyoption->yystate, yyn = yynrhs;
-		   yyn > 0;
-		   yys = yys->yypred, yyn -= 1)
-		yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
-	    }
-	  else
-	    {
-	      /* Both yyresolveAction and yyresolveLocations traverse the GSS
-		 in reverse rightmost order.  It is only necessary to invoke
-		 yyresolveLocations on a subforest for which yyresolveAction
-		 would have been invoked next had an ambiguity not been
-		 detected.  Thus the location of the previous state (but not
-		 necessarily the previous state itself) is guaranteed to be
-		 resolved already.  */
-	      yyGLRState *yyprevious = yyoption->yystate;
-	      yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
-	    }
-	  yychar_current = yychar;
-	  yylval_current = yylval;
-	  yylloc_current = yylloc;
-	  yychar = yyoption->yyrawchar;
-	  yylval = yyoption->yyval;
-	  yylloc = yyoption->yyloc;
-	  YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
-	  yychar = yychar_current;
-	  yylval = yylval_current;
-	  yylloc = yylloc_current;
-	}
+        {
+          yySemanticOption *yyoption;
+          yyGLRStackItem yyrhsloc[1 + YYMAXRHS];
+          int yynrhs;
+          int yychar_current;
+          YYSTYPE yylval_current;
+          YYLTYPE yylloc_current;
+          yyoption = yys1->yysemantics.yyfirstVal;
+          YYASSERT (yyoption != YY_NULL);
+          yynrhs = yyrhsLength (yyoption->yyrule);
+          if (yynrhs > 0)
+            {
+              yyGLRState *yys;
+              int yyn;
+              yyresolveLocations (yyoption->yystate, yynrhs,
+                                  yystackp]b4_user_args[);
+              for (yys = yyoption->yystate, yyn = yynrhs;
+                   yyn > 0;
+                   yys = yys->yypred, yyn -= 1)
+                yyrhsloc[yyn].yystate.yyloc = yys->yyloc;
+            }
+          else
+            {
+              /* Both yyresolveAction and yyresolveLocations traverse the GSS
+                 in reverse rightmost order.  It is only necessary to invoke
+                 yyresolveLocations on a subforest for which yyresolveAction
+                 would have been invoked next had an ambiguity not been
+                 detected.  Thus the location of the previous state (but not
+                 necessarily the previous state itself) is guaranteed to be
+                 resolved already.  */
+              yyGLRState *yyprevious = yyoption->yystate;
+              yyrhsloc[0].yystate.yyloc = yyprevious->yyloc;
+            }
+          yychar_current = yychar;
+          yylval_current = yylval;
+          yylloc_current = yylloc;
+          yychar = yyoption->yyrawchar;
+          yylval = yyoption->yyval;
+          yylloc = yyoption->yyloc;
+          YYLLOC_DEFAULT ((yys1->yyloc), yyrhsloc, yynrhs);
+          yychar = yychar_current;
+          yylval = yylval_current;
+          yylloc = yylloc_current;
+        }
     }
 }]])[
 
@@ -1890,35 +1890,35 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
       yySemanticOption* yyp = *yypp;
 
       if (yyidenticalOptions (yybest, yyp))
-	{
-	  yymergeOptionSets (yybest, yyp);
-	  *yypp = yyp->yynext;
-	}
+        {
+          yymergeOptionSets (yybest, yyp);
+          *yypp = yyp->yynext;
+        }
       else
-	{
-	  switch (yypreference (yybest, yyp))
-	    {
-	    case 0:]b4_locations_if([[
-	      yyresolveLocations (yys, 1, yystackp]b4_user_args[);]])[
-	      return yyreportAmbiguity (yybest, yyp]b4_pure_args[);
-	      break;
-	    case 1:
-	      yymerge = yytrue;
-	      break;
-	    case 2:
-	      break;
-	    case 3:
-	      yybest = yyp;
-	      yymerge = yyfalse;
-	      break;
-	    default:
-	      /* This cannot happen so it is not worth a YYASSERT (yyfalse),
-		 but some compilers complain if the default case is
-		 omitted.  */
-	      break;
-	    }
-	  yypp = &yyp->yynext;
-	}
+        {
+          switch (yypreference (yybest, yyp))
+            {
+            case 0:]b4_locations_if([[
+              yyresolveLocations (yys, 1, yystackp]b4_user_args[);]])[
+              return yyreportAmbiguity (yybest, yyp]b4_pure_args[);
+              break;
+            case 1:
+              yymerge = yytrue;
+              break;
+            case 2:
+              break;
+            case 3:
+              yybest = yyp;
+              yymerge = yyfalse;
+              break;
+            default:
+              /* This cannot happen so it is not worth a YYASSERT (yyfalse),
+                 but some compilers complain if the default case is
+                 omitted.  */
+              break;
+            }
+          yypp = &yyp->yynext;
+        }
     }
 
   if (yymerge)
@@ -1927,23 +1927,23 @@ yyresolveValue (yyGLRState* yys, yyGLRStack* yystackp]b4_user_formals[)
       int yyprec = yydprec[yybest->yyrule];
       yyflag = yyresolveAction (yybest, yystackp, &yysval]b4_locuser_args[);
       if (yyflag == yyok)
-	for (yyp = yybest->yynext; yyp != YY_NULL; yyp = yyp->yynext)
-	  {
-	    if (yyprec == yydprec[yyp->yyrule])
-	      {
-		YYSTYPE yysval_other;]b4_locations_if([
+        for (yyp = yybest->yynext; yyp != YY_NULL; yyp = yyp->yynext)
+          {
+            if (yyprec == yydprec[yyp->yyrule])
+              {
+                YYSTYPE yysval_other;]b4_locations_if([
                 YYLTYPE yydummy;])[
                 yyflag = yyresolveAction (yyp, yystackp, &yysval_other]b4_locuser_args([&yydummy])[);
-		if (yyflag != yyok)
-		  {
-		    yydestruct ("Cleanup: discarding incompletely merged value for",
-				yystos[yys->yylrState],
-				&yysval]b4_locuser_args[);
-		    break;
-		  }
-		yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
-	      }
-	  }
+                if (yyflag != yyok)
+                  {
+                    yydestruct ("Cleanup: discarding incompletely merged value for",
+                                yystos[yys->yylrState],
+                                &yysval]b4_locuser_args[);
+                    break;
+                  }
+                yyuserMerge (yymerger[yyp->yyrule], &yysval, &yysval_other);
+              }
+          }
     }
   else
     yyflag = yyresolveAction (yybest, yystackp, &yysval]b4_locuser_args([yylocp])[);
@@ -1967,11 +1967,11 @@ yyresolveStack (yyGLRStack* yystackp]b4_user_formals[)
       int yyn;
 
       for (yyn = 0, yys = yystackp->yytops.yystates[0];
-	   yys != yystackp->yysplitPoint;
-	   yys = yys->yypred, yyn += 1)
-	continue;
+           yys != yystackp->yysplitPoint;
+           yys = yys->yypred, yyn += 1)
+        continue;
       YYCHK (yyresolveStates (yystackp->yytops.yystates[0], yyn, yystackp
-			     ]b4_user_args[));
+                             ]b4_user_args[));
     }
   return yyok;
 }
@@ -2008,7 +2008,7 @@ yycompressStack (yyGLRStack* yystackp)
 
 static YYRESULTTAG
 yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
-		   size_t yyposn]b4_pure_formals[)
+                   size_t yyposn]b4_pure_formals[)
 {
   int yyaction;
   const short int* yyconflicts;
@@ -2018,71 +2018,71 @@ yyprocessOneStack (yyGLRStack* yystackp, size_t yyk,
     {
       yyStateNum yystate = yystackp->yytops.yystates[yyk]->yylrState;
       YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
-		  (unsigned long int) yyk, yystate));
+                  (unsigned long int) yyk, yystate));
 
       YYASSERT (yystate != YYFINAL);
 
       if (yyisDefaultedState (yystate))
-	{
-	  yyrule = yydefaultAction (yystate);
-	  if (yyrule == 0)
-	    {
-	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
-			  (unsigned long int) yyk));
-	      yymarkStackDeleted (yystackp, yyk);
-	      return yyok;
-	    }
-	  YYCHK (yyglrReduce (yystackp, yyk, yyrule, yyfalse]b4_user_args[));
-	}
+        {
+          yyrule = yydefaultAction (yystate);
+          if (yyrule == 0)
+            {
+              YYDPRINTF ((stderr, "Stack %lu dies.\n",
+                          (unsigned long int) yyk));
+              yymarkStackDeleted (yystackp, yyk);
+              return yyok;
+            }
+          YYCHK (yyglrReduce (yystackp, yyk, yyrule, yyfalse]b4_user_args[));
+        }
       else
-	{
-	  yySymbol yytoken;
-	  yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
-	  if (yychar == YYEMPTY)
-	    {
-	      YYDPRINTF ((stderr, "Reading a token: "));
-	      yychar = YYLEX;
-	    }
-
-	  if (yychar <= YYEOF)
-	    {
-	      yychar = yytoken = YYEOF;
-	      YYDPRINTF ((stderr, "Now at end of input.\n"));
-	    }
-	  else
-	    {
-	      yytoken = YYTRANSLATE (yychar);
-	      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
-	    }
-
-	  yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
-
-	  while (*yyconflicts != 0)
-	    {
-	      size_t yynewStack = yysplitStack (yystackp, yyk);
-	      YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
-			  (unsigned long int) yynewStack,
-			  (unsigned long int) yyk));
-	      YYCHK (yyglrReduce (yystackp, yynewStack,
-				  *yyconflicts, yyfalse]b4_user_args[));
-	      YYCHK (yyprocessOneStack (yystackp, yynewStack,
-					yyposn]b4_pure_args[));
-	      yyconflicts += 1;
-	    }
-
-	  if (yyisShiftAction (yyaction))
-	    break;
-	  else if (yyisErrorAction (yyaction))
-	    {
-	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
-			  (unsigned long int) yyk));
-	      yymarkStackDeleted (yystackp, yyk);
-	      break;
-	    }
-	  else
-	    YYCHK (yyglrReduce (yystackp, yyk, -yyaction,
-				yyfalse]b4_user_args[));
-	}
+        {
+          yySymbol yytoken;
+          yystackp->yytops.yylookaheadNeeds[yyk] = yytrue;
+          if (yychar == YYEMPTY)
+            {
+              YYDPRINTF ((stderr, "Reading a token: "));
+              yychar = YYLEX;
+            }
+
+          if (yychar <= YYEOF)
+            {
+              yychar = yytoken = YYEOF;
+              YYDPRINTF ((stderr, "Now at end of input.\n"));
+            }
+          else
+            {
+              yytoken = YYTRANSLATE (yychar);
+              YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
+            }
+
+          yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
+
+          while (*yyconflicts != 0)
+            {
+              size_t yynewStack = yysplitStack (yystackp, yyk);
+              YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
+                          (unsigned long int) yynewStack,
+                          (unsigned long int) yyk));
+              YYCHK (yyglrReduce (yystackp, yynewStack,
+                                  *yyconflicts, yyfalse]b4_user_args[));
+              YYCHK (yyprocessOneStack (yystackp, yynewStack,
+                                        yyposn]b4_pure_args[));
+              yyconflicts += 1;
+            }
+
+          if (yyisShiftAction (yyaction))
+            break;
+          else if (yyisErrorAction (yyaction))
+            {
+              YYDPRINTF ((stderr, "Stack %lu dies.\n",
+                          (unsigned long int) yyk));
+              yymarkStackDeleted (yystackp, yyk);
+              break;
+            }
+          else
+            YYCHK (yyglrReduce (yystackp, yyk, -yyaction,
+                                yyfalse]b4_user_args[));
+        }
     }
   return yyok;
 }
@@ -2230,45 +2230,45 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
        reductions.  Skip tokens until we can proceed.  */
     while (YYID (yytrue))
       {
-	yySymbol yytoken;
-	if (yychar == YYEOF)
-	  yyFail (yystackp][]b4_lpure_args[, YY_NULL);
-	if (yychar != YYEMPTY)
-	  {]b4_locations_if([[
-	    /* We throw away the lookahead, but the error range
-	       of the shifted error token must take it into account.  */
-	    yyGLRState *yys = yystackp->yytops.yystates[0];
-	    yyGLRStackItem yyerror_range[3];
-	    yyerror_range[1].yystate.yyloc = yys->yyloc;
-	    yyerror_range[2].yystate.yyloc = yylloc;
-	    YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);]])[
-	    yytoken = YYTRANSLATE (yychar);
-	    yydestruct ("Error: discarding",
-			yytoken, &yylval]b4_locuser_args([&yylloc])[);
-	  }
-	YYDPRINTF ((stderr, "Reading a token: "));
-	yychar = YYLEX;
-	if (yychar <= YYEOF)
-	  {
-	    yychar = yytoken = YYEOF;
-	    YYDPRINTF ((stderr, "Now at end of input.\n"));
-	  }
-	else
-	  {
-	    yytoken = YYTRANSLATE (yychar);
-	    YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
-	  }
-	yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
-	if (yypact_value_is_default (yyj))
-	  return;
-	yyj += yytoken;
-	if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
-	  {
-	    if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
-	      return;
-	  }
-	else if (! yytable_value_is_error (yytable[yyj]))
-	  return;
+        yySymbol yytoken;
+        if (yychar == YYEOF)
+          yyFail (yystackp][]b4_lpure_args[, YY_NULL);
+        if (yychar != YYEMPTY)
+          {]b4_locations_if([[
+            /* We throw away the lookahead, but the error range
+               of the shifted error token must take it into account.  */
+            yyGLRState *yys = yystackp->yytops.yystates[0];
+            yyGLRStackItem yyerror_range[3];
+            yyerror_range[1].yystate.yyloc = yys->yyloc;
+            yyerror_range[2].yystate.yyloc = yylloc;
+            YYLLOC_DEFAULT ((yys->yyloc), yyerror_range, 2);]])[
+            yytoken = YYTRANSLATE (yychar);
+            yydestruct ("Error: discarding",
+                        yytoken, &yylval]b4_locuser_args([&yylloc])[);
+          }
+        YYDPRINTF ((stderr, "Reading a token: "));
+        yychar = YYLEX;
+        if (yychar <= YYEOF)
+          {
+            yychar = yytoken = YYEOF;
+            YYDPRINTF ((stderr, "Now at end of input.\n"));
+          }
+        else
+          {
+            yytoken = YYTRANSLATE (yychar);
+            YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
+          }
+        yyj = yypact[yystackp->yytops.yystates[0]->yylrState];
+        if (yypact_value_is_default (yyj))
+          return;
+        yyj += yytoken;
+        if (yyj < 0 || YYLAST < yyj || yycheck[yyj] != yytoken)
+          {
+            if (yydefact[yystackp->yytops.yystates[0]->yylrState] != 0)
+              return;
+          }
+        else if (! yytable_value_is_error (yytable[yyj]))
+          return;
       }
 
   /* Reduce to one stack.  */
@@ -2289,27 +2289,27 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
       yyGLRState *yys = yystackp->yytops.yystates[0];
       yyj = yypact[yys->yylrState];
       if (! yypact_value_is_default (yyj))
-	{
-	  yyj += YYTERROR;
-	  if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
-	      && yyisShiftAction (yytable[yyj]))
-	    {
-	      /* Shift the error token.  */]b4_locations_if([[
-	      /* First adjust its location.*/
+        {
+          yyj += YYTERROR;
+          if (0 <= yyj && yyj <= YYLAST && yycheck[yyj] == YYTERROR
+              && yyisShiftAction (yytable[yyj]))
+            {
+              /* Shift the error token.  */]b4_locations_if([[
+              /* First adjust its location.*/
               YYLTYPE yyerrloc;
-	      yystackp->yyerror_range[2].yystate.yyloc = yylloc;
-	      YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);]])[
-	      YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
-			       &yylval, &yyerrloc);
-	      yyglrShift (yystackp, 0, yytable[yyj],
-			  yys->yyposn, &yylval]b4_locations_if([, &yyerrloc])[);
-	      yys = yystackp->yytops.yystates[0];
-	      break;
-	    }
-	}]b4_locations_if([[
+              yystackp->yyerror_range[2].yystate.yyloc = yylloc;
+              YYLLOC_DEFAULT (yyerrloc, (yystackp->yyerror_range), 2);]])[
+              YY_SYMBOL_PRINT ("Shifting", yystos[yytable[yyj]],
+                               &yylval, &yyerrloc);
+              yyglrShift (yystackp, 0, yytable[yyj],
+                          yys->yyposn, &yylval]b4_locations_if([, &yyerrloc])[);
+              yys = yystackp->yytops.yystates[0];
+              break;
+            }
+        }]b4_locations_if([[
       yystackp->yyerror_range[1].yystate.yyloc = yys->yyloc;]])[
       if (yys->yypred != YY_NULL)
-	yydestroyGLRState ("Error: popping", yys]b4_user_args[);
+        yydestroyGLRState ("Error: popping", yys]b4_user_args[);
       yystackp->yytops.yystates[0] = yys->yypred;
       yystackp->yynextFree -= 1;
       yystackp->yyspaceLeft += 1;
@@ -2318,20 +2318,20 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
     yyFail (yystackp][]b4_lpure_args[, YY_NULL);
 }
 
-#define YYCHK1(YYE)							     \
-  do {									     \
-    switch (YYE) {							     \
-    case yyok:								     \
-      break;								     \
-    case yyabort:							     \
-      goto yyabortlab;							     \
-    case yyaccept:							     \
-      goto yyacceptlab;							     \
-    case yyerr:								     \
-      goto yyuser_error;						     \
-    default:								     \
-      goto yybuglab;							     \
-    }									     \
+#define YYCHK1(YYE)                                                          \
+  do {                                                                       \
+    switch (YYE) {                                                           \
+    case yyok:                                                               \
+      break;                                                                 \
+    case yyabort:                                                            \
+      goto yyabortlab;                                                       \
+    case yyaccept:                                                           \
+      goto yyacceptlab;                                                      \
+    case yyerr:                                                              \
+      goto yyuser_error;                                                     \
+    default:                                                                 \
+      goto yybuglab;                                                         \
+    }                                                                        \
   } while (YYID (0))
 
 
@@ -2379,148 +2379,148 @@ m4_popdef([b4_at_dollar])])dnl
   while (YYID (yytrue))
     {
       /* For efficiency, we have two loops, the first of which is
-	 specialized to deterministic operation (single stack, no
-	 potential ambiguity).  */
+         specialized to deterministic operation (single stack, no
+         potential ambiguity).  */
       /* Standard mode */
       while (YYID (yytrue))
-	{
-	  yyRuleNum yyrule;
-	  int yyaction;
-	  const short int* yyconflicts;
-
-	  yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
-	  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
-	  if (yystate == YYFINAL)
-	    goto yyacceptlab;
-	  if (yyisDefaultedState (yystate))
-	    {
-	      yyrule = yydefaultAction (yystate);
-	      if (yyrule == 0)
-		{
-]b4_locations_if([[		  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
-		  yyreportSyntaxError (&yystack]b4_user_args[);
-		  goto yyuser_error;
-		}
-	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue]b4_user_args[));
-	    }
-	  else
-	    {
-	      yySymbol yytoken;
-	      if (yychar == YYEMPTY)
-		{
-		  YYDPRINTF ((stderr, "Reading a token: "));
-		  yychar = YYLEX;
-		}
-
-	      if (yychar <= YYEOF)
-		{
-		  yychar = yytoken = YYEOF;
-		  YYDPRINTF ((stderr, "Now at end of input.\n"));
-		}
-	      else
-		{
-		  yytoken = YYTRANSLATE (yychar);
-		  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
-		}
-
-	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
-	      if (*yyconflicts != 0)
-		break;
-	      if (yyisShiftAction (yyaction))
-		{
-		  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
-		  yychar = YYEMPTY;
-		  yyposn += 1;
-		  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval]b4_locations_if([, &yylloc])[);
-		  if (0 < yystack.yyerrState)
-		    yystack.yyerrState -= 1;
-		}
-	      else if (yyisErrorAction (yyaction))
-		{
-]b4_locations_if([[		  yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
-		  yyreportSyntaxError (&yystack]b4_user_args[);
-		  goto yyuser_error;
-		}
-	      else
-		YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue]b4_user_args[));
-	    }
-	}
+        {
+          yyRuleNum yyrule;
+          int yyaction;
+          const short int* yyconflicts;
+
+          yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
+          YYDPRINTF ((stderr, "Entering state %d\n", yystate));
+          if (yystate == YYFINAL)
+            goto yyacceptlab;
+          if (yyisDefaultedState (yystate))
+            {
+              yyrule = yydefaultAction (yystate);
+              if (yyrule == 0)
+                {
+]b4_locations_if([[               yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+                  yyreportSyntaxError (&yystack]b4_user_args[);
+                  goto yyuser_error;
+                }
+              YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue]b4_user_args[));
+            }
+          else
+            {
+              yySymbol yytoken;
+              if (yychar == YYEMPTY)
+                {
+                  YYDPRINTF ((stderr, "Reading a token: "));
+                  yychar = YYLEX;
+                }
+
+              if (yychar <= YYEOF)
+                {
+                  yychar = yytoken = YYEOF;
+                  YYDPRINTF ((stderr, "Now at end of input.\n"));
+                }
+              else
+                {
+                  yytoken = YYTRANSLATE (yychar);
+                  YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
+                }
+
+              yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
+              if (*yyconflicts != 0)
+                break;
+              if (yyisShiftAction (yyaction))
+                {
+                  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
+                  yychar = YYEMPTY;
+                  yyposn += 1;
+                  yyglrShift (&yystack, 0, yyaction, yyposn, &yylval]b4_locations_if([, &yylloc])[);
+                  if (0 < yystack.yyerrState)
+                    yystack.yyerrState -= 1;
+                }
+              else if (yyisErrorAction (yyaction))
+                {
+]b4_locations_if([[               yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+                  yyreportSyntaxError (&yystack]b4_user_args[);
+                  goto yyuser_error;
+                }
+              else
+                YYCHK1 (yyglrReduce (&yystack, 0, -yyaction, yytrue]b4_user_args[));
+            }
+        }
 
       while (YYID (yytrue))
-	{
-	  yySymbol yytoken_to_shift;
-	  size_t yys;
-
-	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
-	    yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;
-
-	  /* yyprocessOneStack returns one of three things:
-
-	      - An error flag.  If the caller is yyprocessOneStack, it
-		immediately returns as well.  When the caller is finally
-		yyparse, it jumps to an error label via YYCHK1.
-
-	      - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
-		(&yystack, yys), which sets the top state of yys to NULL.  Thus,
-		yyparse's following invocation of yyremoveDeletes will remove
-		the stack.
-
-	      - yyok, when ready to shift a token.
-
-	     Except in the first case, yyparse will invoke yyremoveDeletes and
-	     then shift the next token onto all remaining stacks.  This
-	     synchronization of the shift (that is, after all preceding
-	     reductions on all stacks) helps prevent double destructor calls
-	     on yylval in the event of memory exhaustion.  */
-
-	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
-	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn]b4_lpure_args[));
-	  yyremoveDeletes (&yystack);
-	  if (yystack.yytops.yysize == 0)
-	    {
-	      yyundeleteLastStack (&yystack);
-	      if (yystack.yytops.yysize == 0)
-		yyFail (&yystack][]b4_lpure_args[, YY_("syntax error"));
-	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
-	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
-]b4_locations_if([[	      yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
-	      yyreportSyntaxError (&yystack]b4_user_args[);
-	      goto yyuser_error;
-	    }
-
-	  /* If any yyglrShift call fails, it will fail after shifting.  Thus,
-	     a copy of yylval will already be on stack 0 in the event of a
-	     failure in the following loop.  Thus, yychar is set to YYEMPTY
-	     before the loop to make sure the user destructor for yylval isn't
-	     called twice.  */
-	  yytoken_to_shift = YYTRANSLATE (yychar);
-	  yychar = YYEMPTY;
-	  yyposn += 1;
-	  for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
-	    {
-	      int yyaction;
-	      const short int* yyconflicts;
-	      yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
-	      yygetLRActions (yystate, yytoken_to_shift, &yyaction,
-			      &yyconflicts);
-	      /* Note that yyconflicts were handled by yyprocessOneStack.  */
-	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
-	      YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
-	      yyglrShift (&yystack, yys, yyaction, yyposn,
-			  &yylval]b4_locations_if([, &yylloc])[);
-	      YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
-			  (unsigned long int) yys,
-			  yystack.yytops.yystates[yys]->yylrState));
-	    }
-
-	  if (yystack.yytops.yysize == 1)
-	    {
-	      YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
-	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
-	      yycompressStack (&yystack);
-	      break;
-	    }
-	}
+        {
+          yySymbol yytoken_to_shift;
+          size_t yys;
+
+          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
+            yystackp->yytops.yylookaheadNeeds[yys] = yychar != YYEMPTY;
+
+          /* yyprocessOneStack returns one of three things:
+
+              - An error flag.  If the caller is yyprocessOneStack, it
+                immediately returns as well.  When the caller is finally
+                yyparse, it jumps to an error label via YYCHK1.
+
+              - yyok, but yyprocessOneStack has invoked yymarkStackDeleted
+                (&yystack, yys), which sets the top state of yys to NULL.  Thus,
+                yyparse's following invocation of yyremoveDeletes will remove
+                the stack.
+
+              - yyok, when ready to shift a token.
+
+             Except in the first case, yyparse will invoke yyremoveDeletes and
+             then shift the next token onto all remaining stacks.  This
+             synchronization of the shift (that is, after all preceding
+             reductions on all stacks) helps prevent double destructor calls
+             on yylval in the event of memory exhaustion.  */
+
+          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
+            YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn]b4_lpure_args[));
+          yyremoveDeletes (&yystack);
+          if (yystack.yytops.yysize == 0)
+            {
+              yyundeleteLastStack (&yystack);
+              if (yystack.yytops.yysize == 0)
+                yyFail (&yystack][]b4_lpure_args[, YY_("syntax error"));
+              YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
+              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
+]b4_locations_if([[           yystack.yyerror_range[1].yystate.yyloc = yylloc;]])[
+              yyreportSyntaxError (&yystack]b4_user_args[);
+              goto yyuser_error;
+            }
+
+          /* If any yyglrShift call fails, it will fail after shifting.  Thus,
+             a copy of yylval will already be on stack 0 in the event of a
+             failure in the following loop.  Thus, yychar is set to YYEMPTY
+             before the loop to make sure the user destructor for yylval isn't
+             called twice.  */
+          yytoken_to_shift = YYTRANSLATE (yychar);
+          yychar = YYEMPTY;
+          yyposn += 1;
+          for (yys = 0; yys < yystack.yytops.yysize; yys += 1)
+            {
+              int yyaction;
+              const short int* yyconflicts;
+              yyStateNum yystate = yystack.yytops.yystates[yys]->yylrState;
+              yygetLRActions (yystate, yytoken_to_shift, &yyaction,
+                              &yyconflicts);
+              /* Note that yyconflicts were handled by yyprocessOneStack.  */
+              YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yys));
+              YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
+              yyglrShift (&yystack, yys, yyaction, yyposn,
+                          &yylval]b4_locations_if([, &yylloc])[);
+              YYDPRINTF ((stderr, "Stack %lu now in state #%d\n",
+                          (unsigned long int) yys,
+                          yystack.yytops.yystates[yys]->yylrState));
+            }
+
+          if (yystack.yytops.yysize == 1)
+            {
+              YYCHK1 (yyresolveStack (&yystack]b4_user_args[));
+              YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
+              yycompressStack (&yystack);
+              break;
+            }
+        }
       continue;
     yyuser_error:
       yyrecoverSyntaxError (&yystack]b4_user_args[);
@@ -2547,7 +2547,7 @@ m4_popdef([b4_at_dollar])])dnl
  yyreturn:
   if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
-		YYTRANSLATE (yychar), &yylval]b4_locuser_args([&yylloc])[);
+                YYTRANSLATE (yychar), &yylval]b4_locuser_args([&yylloc])[);
 
   /* If the stack is well-formed, pop the stack until it is empty,
      destroying its entries as we go.  But free the stack regardless
@@ -2556,25 +2556,25 @@ m4_popdef([b4_at_dollar])])dnl
     {
       yyGLRState** yystates = yystack.yytops.yystates;
       if (yystates)
-	{
-	  size_t yysize = yystack.yytops.yysize;
-	  size_t yyk;
-	  for (yyk = 0; yyk < yysize; yyk += 1)
-	    if (yystates[yyk])
-	      {
-		while (yystates[yyk])
-		  {
-		    yyGLRState *yys = yystates[yyk];
-]b4_locations_if([[		    yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
-)[		    if (yys->yypred != YY_NULL)
-		      yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
-		    yystates[yyk] = yys->yypred;
-		    yystack.yynextFree -= 1;
-		    yystack.yyspaceLeft += 1;
-		  }
-		break;
-	      }
-	}
+        {
+          size_t yysize = yystack.yytops.yysize;
+          size_t yyk;
+          for (yyk = 0; yyk < yysize; yyk += 1)
+            if (yystates[yyk])
+              {
+                while (yystates[yyk])
+                  {
+                    yyGLRState *yys = yystates[yyk];
+]b4_locations_if([[                 yystack.yyerror_range[1].yystate.yyloc = yys->yyloc;]]
+)[                  if (yys->yypred != YY_NULL)
+                      yydestroyGLRState ("Cleanup: popping", yys]b4_user_args[);
+                    yystates[yyk] = yys->yypred;
+                    yystack.yynextFree -= 1;
+                    yystack.yyspaceLeft += 1;
+                  }
+                break;
+              }
+        }
       yyfreeGLRStack (&yystack);
     }
 
@@ -2616,7 +2616,7 @@ yypstack (yyGLRStack* yystackp, size_t yyk)
   yypstates (yystackp->yytops.yystates[yyk]);
 }
 
-#define YYINDEX(YYX)							     \
+#define YYINDEX(YYX)                                                         \
     ((YYX) == YY_NULL ? -1 : (yyGLRStackItem*) (YYX) - yystackp->yyitems)
 
 
@@ -2630,29 +2630,29 @@ yypdumpstack (yyGLRStack* yystackp)
       YYFPRINTF (stderr, "%3lu. ",
                  (unsigned long int) (yyp - yystackp->yyitems));
       if (*(yybool *) yyp)
-	{
-	  YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
-		     yyp->yystate.yyresolved, yyp->yystate.yylrState,
-		     (unsigned long int) yyp->yystate.yyposn,
-		     (long int) YYINDEX (yyp->yystate.yypred));
-	  if (! yyp->yystate.yyresolved)
-	    YYFPRINTF (stderr, ", firstVal: %ld",
-		       (long int) YYINDEX (yyp->yystate
+        {
+          YYFPRINTF (stderr, "Res: %d, LR State: %d, posn: %lu, pred: %ld",
+                     yyp->yystate.yyresolved, yyp->yystate.yylrState,
+                     (unsigned long int) yyp->yystate.yyposn,
+                     (long int) YYINDEX (yyp->yystate.yypred));
+          if (! yyp->yystate.yyresolved)
+            YYFPRINTF (stderr, ", firstVal: %ld",
+                       (long int) YYINDEX (yyp->yystate
                                              .yysemantics.yyfirstVal));
-	}
+        }
       else
-	{
-	  YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
-		     yyp->yyoption.yyrule - 1,
-		     (long int) YYINDEX (yyp->yyoption.yystate),
-		     (long int) YYINDEX (yyp->yyoption.yynext));
-	}
+        {
+          YYFPRINTF (stderr, "Option. rule: %d, state: %ld, next: %ld",
+                     yyp->yyoption.yyrule - 1,
+                     (long int) YYINDEX (yyp->yyoption.yystate),
+                     (long int) YYINDEX (yyp->yyoption.yynext));
+        }
       YYFPRINTF (stderr, "\n");
     }
   YYFPRINTF (stderr, "Tops:");
   for (yyi = 0; yyi < yystackp->yytops.yysize; yyi += 1)
     YYFPRINTF (stderr, "%lu: %ld; ", (unsigned long int) yyi,
-	       (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
+               (long int) YYINDEX (yystackp->yytops.yystates[yyi]));
   YYFPRINTF (stderr, "\n");
 }
 #endif
