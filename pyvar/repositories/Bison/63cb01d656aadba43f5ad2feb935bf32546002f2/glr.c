@@ -142,12 +142,6 @@ b4_copyright([Skeleton parser for GLR parsing with Bison],
 [
 /* This is the parser code for GLR (Generalized LR) parser. */
 
-#include <stdio.h>
-#include <stdlib.h>
-#include <string.h>
-#include <stdarg.h>
-#include <setjmp.h>
-
 ]b4_identification
 m4_if(b4_prefix[], [yy], [],
 [/* Substitute the variable and function names.  */
@@ -218,6 +212,12 @@ static YYSTYPE yyval_default;
 ]/* Line __line__ of glr.c.  */
 b4_syncline([@oline@], [@ofile@])
 [
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <stdarg.h>
+#include <setjmp.h>
+
 #ifndef YYFREE
 # define YYFREE free
 #endif
@@ -228,6 +228,8 @@ b4_syncline([@oline@], [@ofile@])
 # define YYREALLOC realloc
 #endif
 
+#define YYSIZEMAX ((size_t) -1)
+
 #ifdef __cplusplus
    typedef bool yybool;
 #else
@@ -549,7 +551,7 @@ int yydebug;
 
 /* Minimum number of free items on the stack allowed after an
    allocation.  This is to allow allocation and initialization
-   to be completed by functions that call expandGLRStack before the
+   to be completed by functions that call yyexpandGLRStack before the
    stack is expanded, thus insuring that all necessary pointers get
    properly redirected to new data. */
 #define YYHEADROOM 2
@@ -563,6 +565,30 @@ int yydebug;
 #define YYSTACKEXPANDABLE 0
 #endif
 
+#if YYERROR_VERBOSE
+
+# ifndef yystpcpy
+#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
+#   define yystpcpy stpcpy
+#  else
+/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
+   YYDEST.  */
+static char *
+yystpcpy (char *yydest, const char *yysrc)
+{
+  char *yyd = yydest;
+  const char *yys = yysrc;
+
+  while ((*yyd++ = *yys++) != '\0')
+    continue;
+
+  return yyd - 1;
+}
+#  endif
+# endif
+
+#endif /* !YYERROR_VERBOSE */
+
 /** State numbers, as in LALR(1) machine */
 typedef int yyStateNum;
 
@@ -643,15 +669,13 @@ struct yyGLRStack {
   jmp_buf yyexception_buffer;
   yyGLRStackItem* yyitems;
   yyGLRStackItem* yynextFree;
-  int yyspaceLeft;
+  size_t yyspaceLeft;
   yyGLRState* yysplitPoint;
   yyGLRState* yylastDeleted;
   yyGLRStateSet yytops;
 };
 
-static void yyinitGLRStack (yyGLRStack* yystack, size_t yysize);
 static void yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[);
-static void yyfreeGLRStack (yyGLRStack* yystack);
 
 static void
 yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yyformat, ...)
@@ -659,18 +683,43 @@ yyFail (yyGLRStack* yystack]b4_pure_formals[, const char* yyformat, ...)
   yystack->yyerrflag = 1;
   if (yyformat != NULL)
     {
-      char yymsg[256];
+      char yysmallbuf[1024];
+      char const *yymsg = yysmallbuf;
+      char *yybigbuf = NULL;
+      int yymsglen;
       va_list yyap;
+
       va_start (yyap, yyformat);
-      vsprintf (yymsg, yyformat, yyap);
+      yymsglen = vsnprintf (yysmallbuf, sizeof yysmallbuf, yyformat, yyap);
+      va_end (yyap);
+
+      if (yymsglen < 0)
+	yymsg = "message is too long to be printed";
+      else if (sizeof yysmallbuf <= yymsglen && yymsglen < YYSIZEMAX)
+	{
+	  size_t yybigsize = yymsglen;
+	  yybigsize++;
+	  yymsg = yybigbuf = YYMALLOC (yybigsize);
+
+	  va_start (yyap, yyformat);
+	  vsnprintf (yybigbuf, yybigsize, yyformat, yyap);
+	  va_end (yyap);
+	}
+
       yyerror (]b4_yyerror_args[yymsg);
+      YYFREE (yybigbuf);
     }
   longjmp (yystack->yyexception_buffer, 1);
 }
 
+static void
+yyStackOverflow (yyGLRStack* yystack]b4_pure_formals[)
+{
+  yyFail (yystack]b4_pure_args[, "parser stack overflow");
+}
+
 #if YYDEBUG || YYERROR_VERBOSE
-/** A printable representation of TOKEN.  Valid until next call to
- *  tokenName. */
+/** A printable representation of TOKEN.  */
 static inline const char*
 yytokenName (yySymbol yytoken)
 {
@@ -909,13 +958,16 @@ yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
 				/* GLRStacks */
 
 /** Initialize SET to a singleton set containing an empty stack. */
-static void
+static yybool
 yyinitStateSet (yyGLRStateSet* yyset)
 {
   yyset->yysize = 1;
   yyset->yycapacity = 16;
   yyset->yystates = (yyGLRState**) YYMALLOC (16 * sizeof yyset->yystates[0]);
+  if (! yyset->yystates)
+    return yyfalse;
   yyset->yystates[0] = NULL;
+  return yytrue;
 }
 
 static void yyfreeStateSet (yyGLRStateSet* yyset)
@@ -925,7 +977,7 @@ static void yyfreeStateSet (yyGLRStateSet* yyset)
 
 /** Initialize STACK to a single empty stack, with total maximum
  *  capacity for all stacks of SIZE. */
-static void
+static yybool
 yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
 {
   yystack->yyerrflag = 0;
@@ -936,7 +988,7 @@ yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
     (yyGLRStackItem*) YYMALLOC (yysize * sizeof yystack->yynextFree[0]);
   yystack->yysplitPoint = NULL;
   yystack->yylastDeleted = NULL;
-  yyinitStateSet (&yystack->yytops);
+  return yyinitStateSet (&yystack->yytops) && yystack->yyitems;
 }
 
 #define YYRELOC(YYFROMITEMS,YYTOITEMS,YYX,YYTYPE) \
@@ -951,18 +1003,20 @@ static void
 yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
 {
 #if YYSTACKEXPANDABLE
-  yyGLRStack yynewStack;
+  yyGLRStackItem* yynewItems;
   yyGLRStackItem* yyp0, *yyp1;
   size_t yysize, yynewSize;
   size_t yyn;
   yysize = yystack->yynextFree - yystack->yyitems;
   if (YYMAXDEPTH <= yysize)
-    yyFail (yystack][]b4_pure_args[, "parser stack overflow");
+    yyStackOverflow (yystack]b4_pure_args[);
   yynewSize = 2*yysize;
   if (YYMAXDEPTH < yynewSize)
     yynewSize = YYMAXDEPTH;
-  yyinitGLRStack (&yynewStack, yynewSize);
-  for (yyp0 = yystack->yyitems, yyp1 = yynewStack.yyitems, yyn = yysize;
+  yynewItems = (yyGLRStackItem*) YYMALLOC (yynewSize * sizeof yynewItems[0]);
+  if (! yynewItems)
+    yyStackOverflow (yystack]b4_pure_args[);
+  for (yyp0 = yystack->yyitems, yyp1 = yynewItems, yyn = yysize;
        0 < yyn;
        yyn -= 1, yyp0 += 1, yyp1 += 1)
     {
@@ -989,22 +1043,22 @@ yyexpandGLRStack (yyGLRStack* yystack]b4_pure_formals[)
 	}
     }
   if (yystack->yysplitPoint != NULL)
-    yystack->yysplitPoint = YYRELOC (yystack->yyitems, yynewStack.yyitems,
+    yystack->yysplitPoint = YYRELOC (yystack->yyitems, yynewItems,
 				 yystack->yysplitPoint, yystate);
 
   for (yyn = 0; yyn < yystack->yytops.yysize; yyn += 1)
     if (yystack->yytops.yystates[yyn] != NULL)
       yystack->yytops.yystates[yyn] =
-	YYRELOC (yystack->yyitems, yynewStack.yyitems,
+	YYRELOC (yystack->yyitems, yynewItems,
 		 yystack->yytops.yystates[yyn], yystate);
   YYFREE (yystack->yyitems);
-  yystack->yyitems = yynewStack.yyitems;
-  yystack->yynextFree = yynewStack.yynextFree + yysize;
-  yystack->yyspaceLeft = yynewStack.yyspaceLeft - yysize;
+  yystack->yyitems = yynewItems;
+  yystack->yynextFree = yynewItems + yysize;
+  yystack->yyspaceLeft = yynewSize - yysize;
 
 #else
 
-  yyFail (yystack][]b4_pure_args[, "parser stack overflow");
+  yyStackOverflow (yystack]b4_pure_args[);
 #endif
 }
 
@@ -1027,7 +1081,7 @@ yyupdateSplit (yyGLRStack* yystack, yyGLRState* yys)
 
 /** Invalidate stack #K in STACK. */
 static inline void
-yymarkStackDeleted (yyGLRStack* yystack, int yyk)
+yymarkStackDeleted (yyGLRStack* yystack, size_t yyk)
 {
   if (yystack->yytops.yystates[yyk] != NULL)
     yystack->yylastDeleted = yystack->yytops.yystates[yyk];
@@ -1080,7 +1134,8 @@ yyremoveDeletes (yyGLRStack* yystack)
 /** Shift to a new state on stack #K of STACK, corresponding to LR state
  * LRSTATE, at input position POSN, with (resolved) semantic value SVAL. */
 static inline void
-yyglrShift (yyGLRStack* yystack, int yyk, yyStateNum yylrState, size_t yyposn,
+yyglrShift (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
+	    size_t yyposn,
 	    YYSTYPE yysval, YYLTYPE* yylocp]b4_user_formals[)
 {
   yyGLRStackItem* yynewItem;
@@ -1104,7 +1159,7 @@ yyglrShift (yyGLRStack* yystack, int yyk, yyStateNum yylrState, size_t yyposn,
  *  state YYLRSTATE, at input position YYPOSN, with the (unresolved)
  *  semantic value of YYRHS under the action for YYRULE. */
 static inline void
-yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
+yyglrShiftDefer (yyGLRStack* yystack, size_t yyk, yyStateNum yylrState,
 		 size_t yyposn, yyGLRState* rhs, yyRuleNum yyrule]b4_pure_formals[)
 {
   yyGLRStackItem* yynewItem;
@@ -1129,7 +1184,7 @@ yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
  *  and *LOCP to the computed location (if any).  Return value is as
  *  for userAction. */
 static inline YYRESULTTAG
-yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
+yydoAction (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
 	    YYSTYPE* yyvalp, YYLTYPE* yylocp]b4_user_formals[)
 {
   int yynrhs = yyrhsLength (yyrule);
@@ -1263,8 +1318,8 @@ yyglrReduce (yyGLRStack* yystack, size_t yyk, yyRuleNum yyrule,
   return yyok;
 }
 
-static int
-yysplitStack (yyGLRStack* yystack, int yyk)
+static size_t
+yysplitStack (yyGLRStack* yystack, size_t yyk]b4_pure_formals[)
 {
   if (yystack->yysplitPoint == NULL)
     {
@@ -1273,11 +1328,15 @@ yysplitStack (yyGLRStack* yystack, int yyk)
     }
   if (yystack->yytops.yysize >= yystack->yytops.yycapacity)
     {
-      yystack->yytops.yycapacity *= 2;
-      yystack->yytops.yystates =
-	(yyGLRState**) YYREALLOC (yystack->yytops.yystates,
-				  (yystack->yytops.yycapacity
-				   * sizeof yystack->yytops.yystates[0]));
+      yyGLRState** yynewStates;
+      if (! ((yystack->yytops.yycapacity
+	      <= (YYSIZEMAX / (2 * sizeof yynewStates[0])))
+	     && (yynewStates =
+		 (yyGLRState**) YYREALLOC (yystack->yytops.yystates,
+					   ((yystack->yytops.yycapacity *= 2)
+					    * sizeof yynewStates[0])))))
+	yyStackOverflow (yystack]b4_pure_args[);
+      yystack->yytops.yystates = yynewStates;
     }
   yystack->yytops.yystates[yystack->yytops.yysize]
     = yystack->yytops.yystates[yyk];
@@ -1503,10 +1562,10 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
 {
   yySemanticOption* yybest;
   yySemanticOption* yyp;
-  int yymerge;
+  yybool yymerge;
 
   yybest = yyoptionList;
-  yymerge = 0;
+  yymerge = yyfalse;
   for (yyp = yyoptionList->yynext; yyp != NULL; yyp = yyp->yynext)
     {
       if (yyidenticalOptions (yybest, yyp))
@@ -1518,13 +1577,13 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
 	    yyreportAmbiguity (yybest, yyp, yystack]b4_pure_args[);
 	    break;
 	  case 1:
-	    yymerge = 1;
+	    yymerge = yytrue;
 	    break;
 	  case 2:
 	    break;
 	  case 3:
 	    yybest = yyp;
-	    yymerge = 0;
+	    yymerge = yyfalse;
 	    break;
 	  }
     }
@@ -1598,9 +1657,9 @@ yycompressStack (yyGLRStack* yystack)
 }
 
 static YYRESULTTAG
-yyprocessOneStack (yyGLRStack* yystack, int yyk,
+yyprocessOneStack (yyGLRStack* yystack, size_t yyk,
 	           size_t yyposn, YYSTYPE* yylvalp, YYLTYPE* yyllocp
-		  ]b4_user_formals[)
+		  ]b4_pure_formals[)
 {
   int yyaction;
   const short int* yyconflicts;
@@ -1610,7 +1669,8 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
   while (yystack->yytops.yystates[yyk] != NULL)
     {
       yyStateNum yystate = yystack->yytops.yystates[yyk]->yylrState;
-      YYDPRINTF ((stderr, "Stack %d Entering state %d\n", yyk, yystate));
+      YYDPRINTF ((stderr, "Stack %lu Entering state %d\n",
+		  (unsigned long int) yyk, yystate));
 
       YYASSERT (yystate != YYFINAL);
 
@@ -1619,7 +1679,8 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	  yyrule = yydefaultAction (yystate);
 	  if (yyrule == 0)
 	    {
-	      YYDPRINTF ((stderr, "Stack %d dies.\n", yyk));
+	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
+			  (unsigned long int) yyk));
 	      yymarkStackDeleted (yystack, yyk);
 	      return yyok;
 	    }
@@ -1639,19 +1700,20 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 
 	  while (*yyconflicts != 0)
 	    {
-	      int yynewStack = yysplitStack (yystack, yyk);
-	      YYDPRINTF ((stderr, "Splitting off stack %d from %d.\n",
-			  yynewStack, yyk));
+	      size_t yynewStack = yysplitStack (yystack, yyk]b4_pure_args[);
+	      YYDPRINTF ((stderr, "Splitting off stack %lu from %lu.\n",
+			  (unsigned long int) yynewStack,
+			  (unsigned long int) yyk));
 	      YYCHK (yyglrReduce (yystack, yynewStack,
 				  *yyconflicts, yyfalse]b4_lpure_args[));
 	      YYCHK (yyprocessOneStack (yystack, yynewStack, yyposn,
-					yylvalp, yyllocp]b4_user_args[));
+					yylvalp, yyllocp]b4_pure_args[));
 	      yyconflicts += 1;
 	    }
 
 	  if (yyisShiftAction (yyaction))
 	    {
-	      YYDPRINTF ((stderr, "On stack %d, ", yyk));
+	      YYDPRINTF ((stderr, "On stack %lu, ", (unsigned long int) yyk));
 	      YY_SYMBOL_PRINT ("shifting", *yytokenp, yylvalp, yyllocp);
 	      yyglrShift (yystack, yyk, yyaction, yyposn+1,
 			  *yylvalp, yyllocp]b4_user_args[);
@@ -1661,7 +1723,8 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	    }
 	  else if (yyisErrorAction (yyaction))
 	    {
-	      YYDPRINTF ((stderr, "Stack %d dies.\n", yyk));
+	      YYDPRINTF ((stderr, "Stack %lu dies.\n",
+			  (unsigned long int) yyk));
 	      yymarkStackDeleted (yystack, yyk);
 	      break;
 	    }
@@ -1688,10 +1751,24 @@ yyreportSyntaxError (yyGLRStack* yystack,
       yyn = yypact[yystack->yytops.yystates[0]->yylrState];
       if (YYPACT_NINF < yyn && yyn < YYLAST)
 	{
-	  size_t yysize = 0;
-	  const char* yyprefix;
-	  char* yymsg;
+	  size_t yysize0 = strlen (yytokenName (*yytokenp));
+	  size_t yysize = yysize0;
+	  size_t yysize1;
+	  yybool yysize_overflow = yyfalse;
+	  char* yymsg = NULL;
+	  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
+	  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
 	  int yyx;
+	  char *yyfmt;
+	  char const *yyf;
+	  static char const yyunexpected[] = "syntax error, unexpected %s";
+	  static char const yyexpecting[] = ", expecting %s";
+	  static char const yyor[] = " or %s";
+	  char yyformat[sizeof yyunexpected
+			+ sizeof yyexpecting - 1
+			+ ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
+			   * (sizeof yyor - 1))];
+	  char const *yyprefix = yyexpecting;
 
 	  /* Start YYX at -YYN if negative to avoid negative indexes in
 	     YYCHECK.  */
@@ -1700,41 +1777,53 @@ yyreportSyntaxError (yyGLRStack* yystack,
 	  /* Stay within bounds of both yycheck and yytname.  */
 	  int yychecklim = YYLAST - yyn;
 	  int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-	  int yycount = 0;
+	  int yycount = 1;
+
+	  yyarg[0] = yytokenName (*yytokenp);
+	  yyfmt = yystpcpy (yyformat, yyunexpected);
 
-	  yyprefix = ", expecting ";
 	  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
 	      {
-		yysize += strlen (yyprefix) + strlen (yytokenName (yyx));
-		yycount += 1;
-		if (yycount == 5)
+		if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 		  {
-		    yysize = 0;
+		    yycount = 1;
+		    yysize = yysize0;
+		    yyformat[sizeof yyunexpected - 1] = '\0';
 		    break;
 		  }
-		yyprefix = " or ";
+		yyarg[yycount++] = yytokenName (yyx);
+		yysize1 = yysize + strlen (yytokenName (yyx));
+		yysize_overflow |= yysize1 < yysize;
+		yysize = yysize1;
+		yyfmt = yystpcpy (yyfmt, yyprefix);
+		yyprefix = yyor;
 	      }
-	  yysize += (sizeof ("syntax error, unexpected ")
-		     + strlen (yytokenName (*yytokenp)));
-	  yymsg = (char*) YYMALLOC (yysize);
-	  if (yymsg != 0)
+
+	  yyf = yyformat;
+	  yysize1 = yysize + (yyfmt - yyformat);
+	  yysize_overflow |= yysize1 < yysize;
+	  yysize = yysize1;
+
+	  if (!yysize_overflow)
+	    yymsg = (char *) YYMALLOC (yysize);
+
+	  if (yymsg)
 	    {
-	      char* yyp = yymsg;
-	      sprintf (yyp, "syntax error%s%s",
-		       (*yytokenp == YYEMPTY ? "" : ", unexpected "),
-		       yytokenName (*yytokenp));
-	      yyp += strlen (yyp);
-	      if (yycount < 5)
+	      char *yyp = yymsg;
+	      int yyi = 0;
+	      while ((*yyp = *yyf))
 		{
-		  yyprefix = ", expecting ";
-		  for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-		    if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
-		      {
-			sprintf (yyp, "%s%s", yyprefix, yytokenName (yyx));
-			yyp += strlen (yyp);
-			yyprefix = " or ";
-		      }
+		  if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
+		    {
+		      yyp = yystpcpy (yyp, yyarg[yyi++]);
+		      yyf += 2;
+		    }
+		  else
+		    {
+		      yyp++;
+		      yyf++;
+		    }
 		}
 	      yyerror (]b4_lyyerror_args[yymsg);
 	      YYFREE (yymsg);
@@ -1884,7 +1973,7 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
 
 ]b4_c_ansi_function_def([yyparse], [int], b4_parse_param)[
 {
-  yySymbol yytoken;
+  yySymbol yytoken = YYEMPTY;
   yyGLRStack yystack;
   size_t yyposn;
 ]b4_pure_if(
@@ -1898,14 +1987,15 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
   YYSTYPE* const yylvalp = &yylval;
   YYLTYPE* const yyllocp = &yylloc;
 
-  yyinitGLRStack (&yystack, YYINITDEPTH);
-  yystack.yytokenp = &yytoken;
-
   YYDPRINTF ((stderr, "Starting parse\n"));
 
   if (setjmp (yystack.yyexception_buffer) != 0)
     goto yyDone;
 
+  if (! yyinitGLRStack (&yystack, YYINITDEPTH))
+    goto yyDone;
+  yystack.yytokenp = &yytoken;
+
   yylval = yyval_default;
 ]b4_location_if([
 #if YYLTYPE_IS_TRIVIAL
@@ -1924,7 +2014,6 @@ m4_popdef([b4_at_dollar])dnl
 b4_syncline([@oline@], [@ofile@])])dnl
 [
   yyglrShift (&yystack, 0, 0, 0, yylval, &yylloc]b4_user_args[);
-  yytoken = YYEMPTY;
   yyposn = 0;
 
   while (yytrue)
@@ -1992,11 +2081,11 @@ b4_syncline([@oline@], [@ofile@])])dnl
 
       while (yytrue)
 	{
-	  int yys;
-	  int yyn = yystack.yytops.yysize;
+	  size_t yys;
+	  size_t yyn = yystack.yytops.yysize;
 	  for (yys = 0; yys < yyn; yys += 1)
 	    YYCHK1 (yyprocessOneStack (&yystack, yys, yyposn,
-				       yylvalp, yyllocp]b4_user_args[));
+				       yylvalp, yyllocp]b4_lpure_args[));
 	  yytoken = YYEMPTY;
 	  yyposn += 1;
 	  yyremoveDeletes (&yystack);
@@ -2036,7 +2125,7 @@ b4_syncline([@oline@], [@ofile@])])dnl
 
 /* DEBUGGING ONLY */
 #ifdef YYDEBUG
-static void yypstack (yyGLRStack* yystack, int yyk) ATTRIBUTE_UNUSED;
+static void yypstack (yyGLRStack* yystack, size_t yyk) ATTRIBUTE_UNUSED;
 static void yypdumpstack (yyGLRStack* yystack) ATTRIBUTE_UNUSED;
 
 static void
@@ -2061,7 +2150,7 @@ yypstates (yyGLRState* yyst)
 }
 
 static void
-yypstack (yyGLRStack* yystack, int yyk)
+yypstack (yyGLRStack* yystack, size_t yyk)
 {
   yypstates (yystack->yytops.yystates[yyk]);
 }
