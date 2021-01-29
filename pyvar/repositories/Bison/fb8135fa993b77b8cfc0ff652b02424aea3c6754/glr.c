@@ -1,20 +1,25 @@
 m4_divert(-1)                                                       -*- YYC -*-
 
-# b4_sint_type(MAX)
-# -----------------
-# Return the smallest signed int type able to handle the number MAX.
-m4_define([b4_sint_type],
-[m4_if(m4_eval([$1 <= 127]),        [1], [signed char],
-       m4_eval([$1 <= 32767]),      [1], [signed short],
-       [signed int])])
+# GLR skeleton for Bison
+# Copyright (C) 2002 Free Software Foundation, Inc.
+
+# This program is free software; you can redistribute it and/or modify
+# it under the terms of the GNU General Public License as published by
+# the Free Software Foundation; either version 2 of the License, or
+# (at your option) any later version.
+
+# This program is distributed in the hope that it will be useful,
+# but WITHOUT ANY WARRANTY; without even the implied warranty of
+# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+# GNU General Public License for more details.
+
+# You should have received a copy of the GNU General Public License
+# along with this program; if not, write to the Free Software
+# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA
+# 02111-1307  USA
+
+m4_include([c.m4])
 
-# b4_uint_type(MAX)
-# -----------------
-# Return the smallest unsigned int type able to handle the number MAX.
-m4_define([b4_uint_type],
-[m4_if(m4_eval([$1 <= 255]),        [1], [unsigned char],
-       m4_eval([$1 <= 65535]),      [1], [unsigned short],
-       [unsigned int])])
 
 
 # b4_lhs_value([TYPE])
@@ -99,74 +104,10 @@ m4_define_default([b4_header_guard],
                                 [[^ABCDEFGHIJKLMNOPQRSTUVWXYZ]], [_])])
 
 
-## ------------------------- ##
-## Assigning token numbers.  ##
-## ------------------------- ##
-
-# b4_token_define(TOKEN-NAME, TOKEN-NUMBER)
-# -----------------------------------------
-# Output the definition of this token as #define.
-m4_define([b4_token_define],
-[#define $1 $2
-])
-
-
-# b4_token_enum(TOKEN-NAME, TOKEN-NUMBER)
-# ---------------------------------------
-# Output the definition of this token as an enum.
-m4_define([b4_token_enum],
-[$1 = $2])
-
-
-# b4_token_defines(LIST-OF-PAIRS-TOKEN-NAME-TOKEN-NUMBER)
-# -------------------------------------------------------
-# Output the definition of the tokens (if there are) as enums and #define.
-m4_define([b4_token_defines],
-[m4_if([$@], [[]], [],
-[/* Tokens.  */
-#ifndef YYTOKENTYPE
-# if defined (__STDC__) || defined (__cplusplus)
-   /* Put the tokens into the symbol table, so that GDB and other debuggers
-      know about them.  */
-   enum yytokentype {
-m4_map_sep([     b4_token_enum], [,
-],
-           [$@])
-   };
-# endif
-  /* POSIX requires `int' for tokens in interfaces.  */
-# define YYTOKENTYPE int
-#endif /* !YYTOKENTYPE */
-m4_map([b4_token_define], [$@])
-])
-])
-
-
 m4_divert(0)dnl
 #output "b4_output_parser_name"
-[/* Skeleton parser for GLR parsing with Bison,
-   Copyright (C) 2002 Free Software Foundation, Inc.
-
-   This program is free software; you can redistribute it and/or modify
-   it under the terms of the GNU General Public License as published by
-   the Free Software Foundation; either version 2, or (at your option)
-   any later version.
-
-   This program is distributed in the hope that it will be useful,
-   but WITHOUT ANY WARRANTY; without even the implied warranty of
-   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-   GNU General Public License for more details.
-
-   You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 59 Temple Place - Suite 330,
-   Boston, MA 02111-1307, USA.  */
-
-/* As a special exception, when this file is copied by Bison into a
-   Bison output file, you may use that output file without restriction.
-   This special exception was added by the Free Software Foundation
-   in version 1.24 of Bison.  */
-
+b4_copyright([Skeleton parser for GLR parsing with Bison], [2002])
+[
 /* This is the parser code for GLR (Generalized LR) parser. */
 
 /* FIXME: minimize these */
@@ -240,7 +181,7 @@ typedef struct yyltype
 #endif
 
 /* Default (constant) values used for initialization for null
-   right-hand sides.  Unlike the standard bison.simple template, 
+   right-hand sides.  Unlike the standard bison.simple template,
    here we set the default values of the $$ and $@ to zeroed-out
    values.  Since the default value of these quantities is undefined,
    this behavior is technically correct. */
@@ -260,7 +201,7 @@ static YYLTYPE yyloc_default;
 #endif
 
 #if ! defined (yy__GNUC__)
-#  define inline 
+#  define inline
 #endif
 
 /* YYFINAL -- State number of the termination state. */
@@ -385,14 +326,14 @@ static const short yytable[] =
 
 /* YYCONFLP[YYPACT[STATE-NUM]] -- pointer into yyconfl of start of list
    of conflicting reductions corresponding to action entry for state
-   STATE-NUM in yytable.  0 means no conflicts.  The list in yyconfl 
+   STATE-NUM in yytable.  0 means no conflicts.  The list in yyconfl
    is terminated by a rule number of 0. */
 static const short yyconflp[] =
 {
   ]b4_conflict_list_heads[
 };
 
-/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated 
+/* YYCONFL[I] -- lists of conflicting rule numbers, each terminated
    by 0, pointed into by YYCONFLP. */
 static const short yyconfl[] =
 {
@@ -502,7 +443,7 @@ int yydebug;
    if the built-in stack extension method is used).
 
    Do not make this value too large; the results are undefined if
-   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem) 
+   SIZE_MAX < YYMAXDEPTH * sizeof (GLRStackItem)
    evaluated with infinite-precision integer arithmetic.  */
 
 #if YYMAXDEPTH == 0
@@ -514,9 +455,9 @@ int yydebug;
 #endif
 
 /* Minimum number of free items on the stack allowed after an
-   allocation.  This is to allow allocation and initialization 
-   to be completed by functions that call expandGLRStack before the 
-   stack is expanded, thus insuring that all necessary pointers get 
+   allocation.  This is to allow allocation and initialization
+   to be completed by functions that call expandGLRStack before the
+   stack is expanded, thus insuring that all necessary pointers get
    properly redirected to new data. */
 #define YYHEADROOM 2
 
@@ -546,7 +487,7 @@ typedef struct yyGLRStack yyGLRStack;
 typedef struct yyGLRStateSet yyGLRStateSet;
 
 struct yyGLRState {
-  bool yyisState;	
+  bool yyisState;
   bool yyresolved;
   yyStateNum yylrState;
   yyGLRState* yypred;
@@ -598,7 +539,7 @@ static void yyexpandGLRStack (yyGLRStack* yystack);
 static void yyfreeGLRStack (yyGLRStack* yystack);
 
 static void
-yyFail (yyGLRStack* yystack, const char* yyformat, ...) 
+yyFail (yyGLRStack* yystack, const char* yyformat, ...)
 {
   if (yyformat != NULL)
     {
@@ -615,8 +556,8 @@ yyFail (yyGLRStack* yystack, const char* yyformat, ...)
 #if YYDEBUG || YYERROR_VERBOSE
 /** A printable representation of TOKEN.  Valid until next call to
  *  tokenName. */
-static inline const char* 
-yytokenName (yySymbol yytoken) 
+static inline const char*
+yytokenName (yySymbol yytoken)
 {
   return yytname[yytoken];
 }
@@ -628,15 +569,15 @@ yytokenName (yySymbol yytoken)
  *  (@$). Returns yyok for normal return, yyaccept for YYACCEPT,
  *  yyerr for YYERROR, yyabort for YYABORT. */
 static YYRESULTTAG
-yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp, 
+yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
 	      YYSTYPE* yyvalp, YYLTYPE* yylocp, yyGLRStack* yystack)
 {
-  if (yyrhslen == 0) 
+  if (yyrhslen == 0)
     {
       *yyvalp = yyval_default;
       *yylocp = yyloc_default;
     }
-  else 
+  else
     {
       *yyvalp = yyvsp[1-yyrhslen].yystate.yysemantics.yysval;
       *yylocp = yyvsp[1-yyrhslen].yystate.yyloc;
@@ -663,7 +604,7 @@ yyuserAction (yyRuleNum yyn, int yyrhslen, yyGLRStackItem* yyvsp,
   } while (0)
 
 ]
-   switch (yyn) 
+   switch (yyn)
      {
        b4_actions
      }
@@ -686,7 +627,7 @@ static YYSTYPE
 yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 {
   YYSTYPE yyval = *yy0;
-  switch (yyn) 
+  switch (yyn)
     {
       b4_mergers
     }
@@ -697,14 +638,14 @@ yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 
 /** Number of symbols composing the right hand side of rule #RULE. */
 static inline int
-yyrhsLength (yyRuleNum yyrule) 
+yyrhsLength (yyRuleNum yyrule)
 {
   return yyr2[yyrule];
 }
 
 /** Left-hand-side symbol for rule #RULE. */
 static inline yySymbol
-yylhsNonterm (yyRuleNum yyrule) 
+yylhsNonterm (yyRuleNum yyrule)
 {
   return yyr1[yyrule];
 }
@@ -716,7 +657,7 @@ yyisDefaultedState (yyStateNum yystate)
 {
   return yypact[yystate] == YYFLAG;
 }
-  
+
 /** The default reduction for STATE, assuming it has one. */
 static inline yyRuleNum
 yydefaultAction (yyStateNum yystate)
@@ -724,16 +665,16 @@ yydefaultAction (yyStateNum yystate)
   return yydefact[yystate];
 }
 
-/** Set *ACTION to the action to take in STATE on seeing TOKEN.  
+/** Set *ACTION to the action to take in STATE on seeing TOKEN.
  *  Result R means
  *    R < 0:  Reduce on rule -R.
  *    R = 0:  Error.
- *    R > 0:  Shift to state R. 
- *  Set *CONFLICTS to a pointer into yyconfl to 0-terminated list of 
+ *    R > 0:  Shift to state R.
+ *  Set *CONFLICTS to a pointer into yyconfl to 0-terminated list of
  *  conflicting reductions.
  */
 static inline void
-yygetLRActions (yyStateNum yystate, int yytoken, 
+yygetLRActions (yyStateNum yystate, int yytoken,
 	        int* yyaction, const short** yyconflicts)
 {
   int yyindex = yypact[yystate] + yytoken;
@@ -742,7 +683,7 @@ yygetLRActions (yyStateNum yystate, int yytoken,
       *yyaction = -yydefact[yystate];
       *yyconflicts = yyconfl;
     }
-  else 
+  else
     {
       *yyaction = yytable[yyindex];
       *yyconflicts = yyconfl + yyconflp[yyindex];
@@ -761,13 +702,13 @@ yyLRgotoState (yyStateNum yystate, yySymbol yylhs)
 }
 
 static inline bool
-yyisShiftAction (int yyaction) 
+yyisShiftAction (int yyaction)
 {
   return yyaction > 0;
 }
 
 static inline bool
-yyisErrorAction (int yyaction) 
+yyisErrorAction (int yyaction)
 {
   return yyaction == 0 || yyaction == YYFLAG;
 }
@@ -777,12 +718,12 @@ yyisErrorAction (int yyaction)
 /** True iff the semantic value of the edge leading to STATE is
  *  resolved. */
 static inline bool
-yyhasResolvedValue (yyGLRState* yystate) 
+yyhasResolvedValue (yyGLRState* yystate)
 {
   return yystate->yyresolved;
 }
 
-void yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate, 
+void yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
 			  yyGLRState* yyrhs, yyRuleNum yyrule)
 {
   yySemanticOption* yynewItem;
@@ -791,7 +732,7 @@ void yyaddDeferredAction (yyGLRStack* yystack, yyGLRState* yystate,
   yystack->yynextFree += 1;
   yynewItem->yyisState = yyfalse;
   yynewItem->yystate = yyrhs;
-  yynewItem->yyrule = yyrule; 
+  yynewItem->yyrule = yyrule;
   yynewItem->yynext = yystate->yysemantics.yyfirstVal;
   yystate->yysemantics.yyfirstVal = yynewItem;
   if (yystack->yyspaceLeft < YYHEADROOM)
@@ -810,7 +751,7 @@ yyinitStateSet (yyGLRStateSet* yyset)
   yyset->yystates[0] = NULL;
 }
 
-static void yyfreeStateSet (yyGLRStateSet* yyset) 
+static void yyfreeStateSet (yyGLRStateSet* yyset)
 {
   free (yyset->yystates);
 }
@@ -824,7 +765,7 @@ yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
   yystack->yyerrState = 0;
   yynerrs = 0;
   yystack->yyspaceLeft = yysize;
-  yystack->yynextFree = yystack->yyitems = 
+  yystack->yynextFree = yystack->yyitems =
     (yyGLRStackItem*) malloc (yysize * sizeof (yystack->yynextFree[0]));
   yystack->yysplitPoint = NULL;
   yystack->yylastDeleted = NULL;
@@ -840,7 +781,7 @@ yyinitGLRStack (yyGLRStack* yystack, size_t yysize)
     allocation, so that we can avoid having external pointers exist
     across an allocation. */
 static void
-yyexpandGLRStack (yyGLRStack* yystack) 
+yyexpandGLRStack (yyGLRStack* yystack)
 {
 #if YYSTACKEXPANDABLE
   yyGLRStack yynewStack;
@@ -854,23 +795,23 @@ yyexpandGLRStack (yyGLRStack* yystack)
   if (yynewSize > YYMAXDEPTH)
     yynewSize = YYMAXDEPTH;
   yyinitGLRStack (&yynewStack, yynewSize);
-  for (yyp0 = yystack->yyitems, yyp1 = yynewStack.yyitems, yyn = yysize; 
+  for (yyp0 = yystack->yyitems, yyp1 = yynewStack.yyitems, yyn = yysize;
        yyn > 0;
-       yyn -= 1, yyp0 += 1, yyp1 += 1) 
+       yyn -= 1, yyp0 += 1, yyp1 += 1)
     {
       *yyp1 = *yyp0;
-      if (*(bool*) yyp0) 
-	{  
+      if (*(bool*) yyp0)
+	{
 	  yyGLRState* yys0 = &yyp0->yystate;
 	  yyGLRState* yys1 = &yyp1->yystate;
-	  if (yys0->yypred != NULL) 
-	    yys1->yypred = 
+	  if (yys0->yypred != NULL)
+	    yys1->yypred =
 	      YYRELOC (yyp0, yyp1, yys0->yypred, yystate);
 	  if (! yys0->yyresolved && yys0->yysemantics.yyfirstVal != NULL)
-	    yys1->yysemantics.yyfirstVal = 
+	    yys1->yysemantics.yyfirstVal =
 	      YYRELOC(yyp0, yyp1, yys0->yysemantics.yyfirstVal, yyoption);
 	}
-      else 
+      else
 	{
 	  yySemanticOption* yyv0 = &yyp0->yyoption;
 	  yySemanticOption* yyv1 = &yyp1->yyoption;
@@ -881,13 +822,13 @@ yyexpandGLRStack (yyGLRStack* yystack)
 	}
     }
   if (yystack->yysplitPoint != NULL)
-    yystack->yysplitPoint = YYRELOC (yystack->yyitems, yynewStack.yyitems, 
+    yystack->yysplitPoint = YYRELOC (yystack->yyitems, yynewStack.yyitems,
 				 yystack->yysplitPoint, yystate);
-  
-  for (yyn = 0; yyn < yystack->yytops.yysize; yyn += 1) 
+
+  for (yyn = 0; yyn < yystack->yytops.yysize; yyn += 1)
     if (yystack->yytops.yystates[yyn] != NULL)
-      yystack->yytops.yystates[yyn] = 
-	YYRELOC (yystack->yyitems, yynewStack.yyitems, 
+      yystack->yytops.yystates[yyn] =
+	YYRELOC (yystack->yyitems, yynewStack.yyitems,
 		 yystack->yytops.yystates[yyn], yystate);
   free (yystack->yyitems);
   yystack->yyitems = yynewStack.yyitems;
@@ -895,39 +836,39 @@ yyexpandGLRStack (yyGLRStack* yystack)
   yystack->yyspaceLeft = yynewStack.yyspaceLeft - yysize;
 
 #else
-  
+
   yyFail (yystack, "parsing stack overflow (%d items)", yysize);
 
-#endif  
+#endif
 }
 
 static void
-yyfreeGLRStack (yyGLRStack* yystack) 
+yyfreeGLRStack (yyGLRStack* yystack)
 {
   free (yystack->yyitems);
   yyfreeStateSet (&yystack->yytops);
 }
 
 /** Assuming that S is a GLRState somewhere on STACK, update the
- *  splitpoint of STACK, if needed, so that it is at least as deep as 
+ *  splitpoint of STACK, if needed, so that it is at least as deep as
  *  S. */
 static inline void
-yyupdateSplit (yyGLRStack* yystack, yyGLRState* yys) 
+yyupdateSplit (yyGLRStack* yystack, yyGLRState* yys)
 {
-  if (yystack->yysplitPoint != NULL && yystack->yysplitPoint > yys) 
+  if (yystack->yysplitPoint != NULL && yystack->yysplitPoint > yys)
     yystack->yysplitPoint = yys;
 }
 
 /** Invalidate stack #K in STACK. */
 static inline void
-yymarkStackDeleted (yyGLRStack* yystack, int yyk) 
+yymarkStackDeleted (yyGLRStack* yystack, int yyk)
 {
   if (yystack->yytops.yystates[yyk] != NULL)
     yystack->yylastDeleted = yystack->yytops.yystates[yyk];
   yystack->yytops.yystates[yyk] = NULL;
 }
 
-/** Undelete the last stack that was marked as deleted.  Can only be 
+/** Undelete the last stack that was marked as deleted.  Can only be
     done once after a deletion, and only when all other stacks have
     been deleted. */
 static void
@@ -935,7 +876,7 @@ yyundeleteLastStack (yyGLRStack* yystack)
 {
   if (yystack->yylastDeleted == NULL || yystack->yytops.yysize != 0)
     return;
-  yystack->yytops.yystates[0] = yystack->yylastDeleted;	
+  yystack->yytops.yystates[0] = yystack->yylastDeleted;
   yystack->yytops.yysize = 1;
   YYDPRINTF ((stderr, "Restoring last deleted stack as stack #0.\n"));
   yystack->yylastDeleted = NULL;
@@ -946,15 +887,15 @@ yyremoveDeletes (yyGLRStack* yystack)
 {
   int yyi, yyj;
   yyi = yyj = 0;
-  while (yyj < yystack->yytops.yysize) 
+  while (yyj < yystack->yytops.yysize)
     {
       if (yystack->yytops.yystates[yyi] == NULL)
 	{
-	  if (YYDEBUG && yyi == yyj) 
+	  if (YYDEBUG && yyi == yyj)
 	    YYDPRINTF ((stderr, "Removing dead stacks.\n"));
 	  yystack->yytops.yysize -= 1;
 	}
-      else 
+      else
 	{
 	  yystack->yytops.yystates[yyj] = yystack->yytops.yystates[yyi];
 	  if (yyj != yyi)
@@ -965,11 +906,11 @@ yyremoveDeletes (yyGLRStack* yystack)
     }
 }
 
-/** Shift to a new state on stack #K of STACK, corresponding to LR state 
+/** Shift to a new state on stack #K of STACK, corresponding to LR state
  * LRSTATE, at input position POSN, with (resolved) semantic value SVAL. */
 static inline void
-yyglrShift (yyGLRStack* yystack, int yyk, yyStateNum yylrState, size_t yyposn, 
-	    YYSTYPE yysval, YYLTYPE* yylocp) 
+yyglrShift (yyGLRStack* yystack, int yyk, yyStateNum yylrState, size_t yyposn,
+	    YYSTYPE yysval, YYLTYPE* yylocp)
 {
   yyGLRStackItem* yynewItem;
 
@@ -992,7 +933,7 @@ yyglrShift (yyGLRStack* yystack, int yyk, yyStateNum yylrState, size_t yyposn,
  *  corresponding to LR state LRSTATE, at input position POSN, with
  * the (unresolved) semantic value of RHS under the action for RULE. */
 static inline void
-yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState, 
+yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
 		 size_t yyposn, yyGLRState* yyrhs, yyRuleNum yyrule)
 {
   yyGLRStackItem* yynewItem;
@@ -1011,8 +952,8 @@ yyglrShiftDefer (yyGLRStack* yystack, int yyk, yyStateNum yylrState,
 }
 
 /** Pop the symbols consumed by reduction #RULE from the top of stack
- *  #K of STACK, and perform the appropriate semantic action on their 
- *  semantic values.  Assumes that all ambiguities in semantic values 
+ *  #K of STACK, and perform the appropriate semantic action on their
+ *  semantic values.  Assumes that all ambiguities in semantic values
  *  have been previously resolved. Set *VALP to the resulting value,
  *  and *LOCP to the computed location (if any).  Return value is as
  *  for userAction. */
@@ -1022,7 +963,7 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
 {
   int yynrhs = yyrhsLength (yyrule);
 
-  if (yystack->yysplitPoint == NULL) 
+  if (yystack->yysplitPoint == NULL)
     {
       /* Standard special case: single stack. */
       yyGLRStackItem* yyrhs = (yyGLRStackItem*) yystack->yytops.yystates[yyk];
@@ -1030,25 +971,25 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
       yystack->yynextFree -= yynrhs;
       yystack->yyspaceLeft += yynrhs;
       yystack->yytops.yystates[0] = & yystack->yynextFree[-1].yystate;
-      if (yynrhs == 0) 
+      if (yynrhs == 0)
 	{
 	  *yyvalp = yyval_default;
 	  *yylocp = yyloc_default;
 	}
-      else 
+      else
 	{
 	  *yyvalp = yyrhs[1-yynrhs].yystate.yysemantics.yysval;
 	  *yylocp = yyrhs[1-yynrhs].yystate.yyloc;
 	}
       return yyuserAction (yyrule, yynrhs, yyrhs, yyvalp, yylocp, yystack);
     }
-  else 
+  else
     {
       int yyi;
       yyGLRState* yys;
       yyGLRStackItem yyrhsVals[YYMAXRHS];
-      for (yyi = yynrhs-1, yys = yystack->yytops.yystates[yyk]; yyi >= 0; 
-	   yyi -= 1, yys = yys->yypred) 
+      for (yyi = yynrhs-1, yys = yystack->yytops.yystates[yyk]; yyi >= 0;
+	   yyi -= 1, yys = yys->yypred)
 	{
 	  assert (yys->yypred != NULL);
 	  yyrhsVals[yyi].yystate.yyresolved = yytrue;
@@ -1057,76 +998,76 @@ yydoAction (yyGLRStack* yystack, int yyk, yyRuleNum yyrule,
 	}
       yyupdateSplit (yystack, yys);
       yystack->yytops.yystates[yyk] = yys;
-      if (yynrhs == 0) 
+      if (yynrhs == 0)
 	{
 	  *yyvalp = yyval_default;
 	  *yylocp = yyloc_default;
 	}
-      else 
+      else
 	{
 	  *yyvalp = yyrhsVals[0].yystate.yysemantics.yysval;
 	  *yylocp = yyrhsVals[0].yystate.yyloc;
 	}
-      return yyuserAction (yyrule, yynrhs, yyrhsVals + (yynrhs-1), 
+      return yyuserAction (yyrule, yynrhs, yyrhsVals + (yynrhs-1),
 			   yyvalp, yylocp, yystack);
     }
 }
 
 /** Pop items off stack #K of STACK according to grammar rule RULE,
  *  and push back on the resulting nonterminal symbol.  Perform the
- *  semantic action associated with RULE and store its value with the 
+ *  semantic action associated with RULE and store its value with the
  *  newly pushed state, if FORCEEVAL or if STACK is currently
  *  unambiguous.  Otherwise, store the deferred semantic action with
  *  the new state.  If the new state would have an identical input
  *  position, LR state, and predecessor to an existing state on the stack,
- *  it is identified with that existing state, eliminating stack #K from 
- *  the STACK. In this case, the (necessarily deferred) semantic value is 
- *  added to the options for the existing state's semantic value. 
+ *  it is identified with that existing state, eliminating stack #K from
+ *  the STACK. In this case, the (necessarily deferred) semantic value is
+ *  added to the options for the existing state's semantic value.
  */
 static inline YYRESULTTAG
 yyglrReduce (yyGLRStack* yystack, int yyk, yyRuleNum yyrule, bool yyforceEval)
 {
   int yyposn = yystack->yytops.yystates[yyk]->yyposn;
 
-  if (yyforceEval || yystack->yysplitPoint == NULL) 
+  if (yyforceEval || yystack->yysplitPoint == NULL)
     {
       YYSTYPE yysval;
       YYLTYPE yyloc;
-    
+
       YYCHK (yydoAction (yystack, yyk, yyrule, &yysval, &yyloc));
-      yyglrShift (yystack, yyk, 
-		  yyLRgotoState (yystack->yytops.yystates[yyk]->yylrState, 
+      yyglrShift (yystack, yyk,
+		  yyLRgotoState (yystack->yytops.yystates[yyk]->yylrState,
 				 yylhsNonterm (yyrule)),
 		yyposn, yysval, &yyloc);
       YYDPRINTF ((stderr, "Reduced stack %d by rule #%d. Now in state %d.\n",
 		  yyk, yyrule-1, yystack->yytops.yystates[yyk]->yylrState));
     }
-  else 
+  else
     {
       int yyi, yyn;
       yyGLRState* yys, *yys0 = yystack->yytops.yystates[yyk];
       yyStateNum yynewLRState;
 
-      for (yys = yystack->yytops.yystates[yyk], yyn = yyrhsLength (yyrule); 
-	   yyn > 0; yyn -= 1) 
+      for (yys = yystack->yytops.yystates[yyk], yyn = yyrhsLength (yyrule);
+	   yyn > 0; yyn -= 1)
 	{
 	  yys = yys->yypred;
 	  assert (yys != NULL);
 	}
       yyupdateSplit (yystack, yys);
       yynewLRState = yyLRgotoState (yys->yylrState, yylhsNonterm (yyrule));
-      YYDPRINTF ((stderr, 
+      YYDPRINTF ((stderr,
 		  "Reduced stack %d by rule #%d; action deferred. "
 		  "Now in state %d.\n",
 		  yyk, yyrule-1, yynewLRState));
       for (yyi = 0; yyi < yystack->yytops.yysize; yyi += 1)
-	if (yyi != yyk && yystack->yytops.yystates[yyi] != NULL) 
+	if (yyi != yyk && yystack->yytops.yystates[yyi] != NULL)
 	  {
 	    yyGLRState* yyp, *yysplit = yystack->yysplitPoint;
 	    yyp = yystack->yytops.yystates[yyi];
-	    while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn) 
+	    while (yyp != yys && yyp != yysplit && yyp->yyposn >= yyposn)
 	      {
-		if (yyp->yylrState == yynewLRState && yyp->yypred == yys) 
+		if (yyp->yylrState == yynewLRState && yyp->yypred == yys)
 		  {
 		    yyaddDeferredAction (yystack, yyp, yys0, yyrule);
 		    yymarkStackDeleted (yystack, yyk);
@@ -1139,27 +1080,27 @@ yyglrReduce (yyGLRStack* yystack, int yyk, yyRuleNum yyrule, bool yyforceEval)
 	  }
       yystack->yytops.yystates[yyk] = yys;
       yyglrShiftDefer (yystack, yyk, yynewLRState, yyposn, yys0, yyrule);
-    }    
+    }
   return 0;
 }
 
 static int
 yysplitStack (yyGLRStack* yystack, int yyk)
 {
-  if (yystack->yysplitPoint == NULL) 
+  if (yystack->yysplitPoint == NULL)
     {
       assert (yyk == 0);
       yystack->yysplitPoint = yystack->yytops.yystates[yyk];
     }
-  if (yystack->yytops.yysize >= yystack->yytops.yycapacity) 
+  if (yystack->yytops.yysize >= yystack->yytops.yycapacity)
     {
       yystack->yytops.yycapacity *= 2;
-      yystack->yytops.yystates = 
-	(yyGLRState**) realloc (yystack->yytops.yystates, 
-				yystack->yytops.yycapacity 
+      yystack->yytops.yystates =
+	(yyGLRState**) realloc (yystack->yytops.yystates,
+				yystack->yytops.yycapacity
 				* sizeof (yyGLRState*));
     }
-  yystack->yytops.yystates[yystack->yytops.yysize] 
+  yystack->yytops.yystates[yystack->yytops.yysize]
     = yystack->yytops.yystates[yyk];
   yystack->yytops.yysize += 1;
   return yystack->yytops.yysize-1;
@@ -1171,11 +1112,11 @@ yysplitStack (yyGLRStack* yystack, int yyk)
 static bool
 yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
 {
-  if (yyy0->yyrule == yyy1->yyrule) 
+  if (yyy0->yyrule == yyy1->yyrule)
     {
       yyGLRState *yys0, *yys1;
       int yyn;
-      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate, 
+      for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
 	   yyn = yyrhsLength (yyy0->yyrule);
 	   yyn > 0;
 	   yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
@@ -1188,23 +1129,23 @@ yyidenticalOptions (yySemanticOption* yyy0, yySemanticOption* yyy1)
 }
 
 /** Assuming identicalOptions (Y0,Y1), (destructively) merge the
- *  alternative semantic values for the RHS-symbols of Y1 into the 
+ *  alternative semantic values for the RHS-symbols of Y1 into the
  *  corresponding semantic value sets of the symbols of Y0. */
 static void
 yymergeOptionSets (yySemanticOption* yyy0, yySemanticOption* yyy1)
 {
   yyGLRState *yys0, *yys1;
   int yyn;
-  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate, 
+  for (yys0 = yyy0->yystate, yys1 = yyy1->yystate,
        yyn = yyrhsLength (yyy0->yyrule);
        yyn > 0;
        yys0 = yys0->yypred, yys1 = yys1->yypred, yyn -= 1)
     if (yys0 == yys1)
       break;
-    else if (! yys0->yyresolved && ! yys1->yyresolved) 
+    else if (! yys0->yyresolved && ! yys1->yyresolved)
       {
 	yySemanticOption* yyz;
-	for (yyz = yys0->yysemantics.yyfirstVal; yyz->yynext != NULL; 
+	for (yyz = yys0->yysemantics.yyfirstVal; yyz->yynext != NULL;
 	     yyz = yyz->yynext)
 	  ;
 	yyz->yynext = yys1->yysemantics.yyfirstVal;
@@ -1220,7 +1161,7 @@ yypreference (yySemanticOption* yyy0, yySemanticOption* yyy1)
   yyRuleNum yyr0 = yyy0->yyrule, yyr1 = yyy1->yyrule;
   int yyp0 = yydprec[yyr0], yyp1 = yydprec[yyr1];
 
-  if (yyp0 == yyp1) 
+  if (yyp0 == yyp1)
     {
       if (yymerger[yyr0] == 0 || yymerger[yyr0] != yymerger[yyr1])
 	return 0;
@@ -1236,21 +1177,21 @@ yypreference (yySemanticOption* yyy0, yySemanticOption* yyy1)
   return 0;
 }
 
-static YYRESULTTAG yyresolveValue (yySemanticOption* yyoptionList, 
-				   yyGLRStack* yystack, YYSTYPE* yyvalp, 
+static YYRESULTTAG yyresolveValue (yySemanticOption* yyoptionList,
+				   yyGLRStack* yystack, YYSTYPE* yyvalp,
 				   YYLTYPE* yylocp);
 
 static YYRESULTTAG
 yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack)
 {
   YYRESULTTAG yyflag;
-  if (yyn > 0) 
+  if (yyn > 0)
     {
       assert (yys->yypred != NULL);
       yyflag = yyresolveStates (yys->yypred, yyn-1, yystack);
       if (yyflag != yyok)
 	return yyflag;
-      if (! yys->yyresolved) 
+      if (! yys->yyresolved)
 	{
 	  yyflag = yyresolveValue (yys->yysemantics.yyfirstVal, yystack,
 			       &yys->yysemantics.yysval, &yys->yyloc);
@@ -1263,7 +1204,7 @@ yyresolveStates (yyGLRState* yys, int yyn, yyGLRStack* yystack)
 }
 
 static YYRESULTTAG
-yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack, 
+yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
 	         YYSTYPE* yyvalp, YYLTYPE* yylocp)
 {
   yyGLRStackItem yyrhsVals[YYMAXRHS];
@@ -1272,22 +1213,22 @@ yyresolveAction (yySemanticOption* yyopt, yyGLRStack* yystack,
 
   yynrhs = yyrhsLength (yyopt->yyrule);
   YYCHK (yyresolveStates (yyopt->yystate, yynrhs, yystack));
-  for (yyi = yynrhs-1, yys = yyopt->yystate; yyi >= 0; 
+  for (yyi = yynrhs-1, yys = yyopt->yystate; yyi >= 0;
        yyi -= 1, yys = yys->yypred)
     {
       assert (yys->yypred != NULL);
       yyrhsVals[yyi].yystate.yyresolved = yytrue;
       yyrhsVals[yyi].yystate.yysemantics.yysval = yys->yysemantics.yysval;
       yyrhsVals[yyi].yystate.yyloc = yys->yyloc;
-    }	
-  return yyuserAction (yyopt->yyrule, yynrhs, yyrhsVals + (yynrhs-1), 
+    }
+  return yyuserAction (yyopt->yyrule, yynrhs, yyrhsVals + (yynrhs-1),
 		       yyvalp, yylocp, yystack);
 }
 
 #if YYDEBUG
 static yyGLRState YYLEFTMOST_STATE = { 0, NULL, -1, 0, { NULL } };
 
-static void yyreportTree (yySemanticOption* yyx, int yyindent) 
+static void yyreportTree (yySemanticOption* yyx, int yyindent)
 {
   int yynrhs = yyrhsLength (yyx->yyrule);
   int yyi;
@@ -1303,15 +1244,15 @@ static void yyreportTree (yySemanticOption* yyx, int yyindent)
 
   if (yys->yyposn+1 > yyx->yystate->yyposn)
     YYFPRINTF (stderr, "%*s%s -> <Rule %d, empty>\n",
-	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)), 
+	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
 	       yyx->yyrule);
   else
-    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %d .. %d>\n", 
+    YYFPRINTF (stderr, "%*s%s -> <Rule %d, tokens %d .. %d>\n",
 	       yyindent, "", yytokenName (yylhsNonterm (yyx->yyrule)),
 	       yyx->yyrule, yys->yyposn+1, yyx->yystate->yyposn);
-  for (yyi = 1; yyi <= yynrhs; yyi += 1) 
+  for (yyi = 1; yyi <= yynrhs; yyi += 1)
     {
-      if (yystates[yyi]->yyresolved) 
+      if (yystates[yyi]->yyresolved)
 	{
 	  if (yystates[yyi-1]->yyposn+1 > yystates[yyi]->yyposn)
 	    YYFPRINTF (stderr, "%*s%s <empty>\n", yyindent+2, "",
@@ -1321,11 +1262,11 @@ static void yyreportTree (yySemanticOption* yyx, int yyindent)
 		       yytokenName (yyrhs[yyprhs[yyx->yyrule]+yyi-1]),
 		       yystates[yyi-1]->yyposn+1, yystates[yyi]->yyposn);
 	}
-      else 
+      else
 	yyreportTree (yystates[yyi]->yysemantics.yyfirstVal, yyindent+2);
     }
 }
-#endif    
+#endif
 
 static void
 yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
@@ -1346,21 +1287,21 @@ yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
 /** Resolve the ambiguity represented by OPTIONLIST, perform the indicated
  *  actions, and return the result. */
 static YYRESULTTAG
-yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack, 
-		YYSTYPE* yyvalp, YYLTYPE* yylocp) 
+yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
+		YYSTYPE* yyvalp, YYLTYPE* yylocp)
 {
   yySemanticOption* yybest;
   yySemanticOption* yyp;
   int yymerge;
 
-  yybest = yyoptionList; 
+  yybest = yyoptionList;
   yymerge = 0;
-  for (yyp = yyoptionList->yynext; yyp != NULL; yyp = yyp->yynext) 
+  for (yyp = yyoptionList->yynext; yyp != NULL; yyp = yyp->yynext)
     {
       if (yyidenticalOptions (yybest, yyp))
 	yymergeOptionSets (yybest, yyp);
       else
-	switch (yypreference (yybest, yyp)) 
+	switch (yypreference (yybest, yyp))
 	  {
 	  case 0:
 	    yyreportAmbiguity (yybest, yyp, yystack);
@@ -1377,13 +1318,13 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
 	  }
     }
 
-  if (yymerge) 
+  if (yymerge)
     {
       int yyprec = yydprec[yybest->yyrule];
       YYCHK (yyresolveAction (yybest, yystack, yyvalp, yylocp));
-      for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext) 
+      for (yyp = yybest->yynext; yyp != NULL; yyp = yyp->yynext)
 	{
-	  if (yyprec == yydprec[yyp->yyrule]) 
+	  if (yyprec == yydprec[yyp->yyrule])
 	    {
 	      YYSTYPE yyval1;
 	      YYLTYPE yydummy;
@@ -1398,15 +1339,15 @@ yyresolveValue (yySemanticOption* yyoptionList, yyGLRStack* yystack,
 }
 
 static YYRESULTTAG
-yyresolveStack (yyGLRStack* yystack) 
+yyresolveStack (yyGLRStack* yystack)
 {
-  if (yystack->yysplitPoint != NULL) 
+  if (yystack->yysplitPoint != NULL)
     {
       yyGLRState* yys;
       int yyn;
 
-      for (yyn = 0, yys = yystack->yytops.yystates[0]; 
-	   yys != yystack->yysplitPoint; 
+      for (yyn = 0, yys = yystack->yytops.yystates[0];
+	   yys != yystack->yysplitPoint;
 	   yys = yys->yypred, yyn += 1)
 	;
       YYCHK (yyresolveStates (yystack->yytops.yystates[0], yyn, yystack));
@@ -1415,26 +1356,26 @@ yyresolveStack (yyGLRStack* yystack)
 }
 
 static void
-yycompressStack (yyGLRStack* yystack) 
+yycompressStack (yyGLRStack* yystack)
 {
   yyGLRState* yyp, *yyq, *yyr;
 
   if (yystack->yytops.yysize != 1 || yystack->yysplitPoint == NULL)
     return;
 
-  for (yyp = yystack->yytops.yystates[0], yyq = yyp->yypred, yyr = NULL; 
-       yyp != yystack->yysplitPoint; 
+  for (yyp = yystack->yytops.yystates[0], yyq = yyp->yypred, yyr = NULL;
+       yyp != yystack->yysplitPoint;
        yyr = yyp, yyp = yyq, yyq = yyp->yypred)
     yyp->yypred = yyr;
-  
+
   yystack->yyspaceLeft += yystack->yynextFree - yystack->yyitems;
   yystack->yynextFree = ((yyGLRStackItem*) yystack->yysplitPoint) + 1;
   yystack->yyspaceLeft -= yystack->yynextFree - yystack->yyitems;
   yystack->yysplitPoint = NULL;
   yystack->yylastDeleted = NULL;
-  
-  while (yyr != NULL) 
-    {	
+
+  while (yyr != NULL)
+    {
       yystack->yynextFree->yystate = *yyr;
       yyr = yyr->yypred;
       yystack->yynextFree->yystate.yypred = & yystack->yynextFree[-1].yystate;
@@ -1445,7 +1386,7 @@ yycompressStack (yyGLRStack* yystack)
 }
 
 static YYRESULTTAG
-yyprocessOneStack (yyGLRStack* yystack, int yyk, 
+yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	           size_t yyposn, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 {
   int yyaction;
@@ -1453,15 +1394,15 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
   yyRuleNum yyrule;
   yySymbol* const yytokenp = yystack->yytokenp;
 
-  while (yystack->yytops.yystates[yyk] != NULL) 
+  while (yystack->yytops.yystates[yyk] != NULL)
     {
       yyStateNum yystate = yystack->yytops.yystates[yyk]->yylrState;
 
       assert (yystate != YYFINAL);
-      if (yyisDefaultedState (yystate)) 
+      if (yyisDefaultedState (yystate))
 	{
 	  yyrule = yydefaultAction (yystate);
-	  if (yyrule == 0) 
+	  if (yyrule == 0)
 	    {
 	      YYDPRINTF ((stderr, "Stack %d dies.\n", yyk));
 	      yymarkStackDeleted (yystack, yyk);
@@ -1469,9 +1410,9 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	    }
 	  YYCHK (yyglrReduce (yystack, yyk, yyrule, yyfalse));
 	}
-      else 
+      else
 	{
-	  if (*yytokenp == YYEMPTY) 
+	  if (*yytokenp == YYEMPTY)
 	    {
 	      yychar = YYLEX;
 	      *yytokenp = YYTRANSLATE(yychar);
@@ -1479,27 +1420,27 @@ yyprocessOneStack (yyGLRStack* yystack, int yyk,
 	    }
 	  yygetLRActions (yystate, *yytokenp, &yyaction, &yyconflicts);
 
-	  while (*yyconflicts != 0) 
+	  while (*yyconflicts != 0)
 	    {
 	      int yynewStack = yysplitStack (yystack, yyk);
 	      YYDPRINTF ((stderr, "Splitting off stack %d from %d.\n",
 			  yynewStack, yyk));
 	      YYCHK (yyglrReduce (yystack, yynewStack, *yyconflicts, yyfalse));
-	      YYCHK (yyprocessOneStack (yystack, yynewStack, yyposn, 
+	      YYCHK (yyprocessOneStack (yystack, yynewStack, yyposn,
 					yylvalp, yyllocp));
 	      yyconflicts += 1;
 	    }
-      
-	  if (yyisShiftAction (yyaction)) 
+
+	  if (yyisShiftAction (yyaction))
 	    {
-	      YYDPRINTF ((stderr, "Shifted token %s on stack %d, ", 
+	      YYDPRINTF ((stderr, "Shifted token %s on stack %d, ",
 			  yytokenName (*yytokenp), yyk));
 	      yyglrShift (yystack, yyk, yyaction, yyposn+1, *yylvalp, yyllocp);
-	      YYDPRINTF ((stderr, "which is now in state #%d\n", 
+	      YYDPRINTF ((stderr, "which is now in state #%d\n",
 			  yystack->yytops.yystates[yyk]->yylrState));
 	      break;
 	    }
-	  else if (yyisErrorAction (yyaction)) 
+	  else if (yyisErrorAction (yyaction))
 	    {
 	      YYDPRINTF ((stderr, "Stack %d dies.\n", yyk));
 	      yymarkStackDeleted (yystack, yyk);
@@ -1519,7 +1460,7 @@ yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 
   if (yystack->yyerrState == 0)
     {
-#if YYERROR_VERBOSE  
+#if YYERROR_VERBOSE
       int yyn, yyx, yycount, yysize;
       char* yyprefix;
       char* yyp;
@@ -1530,16 +1471,16 @@ yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	  yycount = 0;
 	  /* Start YYX at -YYN if negative to avoid negative indexes in
 	     YYCHECK.  */
-	  yysize = sizeof ("parse error, unexpected ") 
+	  yysize = sizeof ("parse error, unexpected ")
 	    + strlen (yytokenName (*yytokenp));
 	  yyprefix = ", expecting ";
-	  for (yyx = yyn < 0 ? -yyn : 0; yyx < yytname_size && yycount <= 5; 
+	  for (yyx = yyn < 0 ? -yyn : 0; yyx < yytname_size && yycount <= 5;
 	       yyx += 1)
 	    if (yycheck[yyx + yyn] == yyx)
 	      yysize += strlen (yytokenName (yyx)) + strlen (yyprefix),
 		yycount += 1, yyprefix = " or ";
 	  yymsg = yyp = (char*) malloc (yysize);
-	  yyp += sprintf (yyp, "parse error, unexpected %s", 
+	  yyp += sprintf (yyp, "parse error, unexpected %s",
 			  yytokenName (*yytokenp));
 	  if (yycount < 5)
 	    {
@@ -1563,20 +1504,20 @@ yyreportParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 
 /* Recover from a syntax error on STACK, assuming that TOKENP,
    YYLVALP, and YYLLOCP point to the syntactic category, semantic
-   value, and location of the lookahead.  
-   NOTE: This uses the panic-mode recovery algorithm described in the 
-   Bison documentation, which differs from what is in bison.simple.  
+   value, and location of the lookahead.
+   NOTE: This uses the panic-mode recovery algorithm described in the
+   Bison documentation, which differs from what is in bison.simple.
    Specifically, this routine performs no reductions before shifting
    the error token. */
-static void 
+static void
 yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 {
   yySymbol* const yytokenp = yystack->yytokenp;
   int yyk, yyj;
 
-  if (yystack->yyerrState == 0) 
+  if (yystack->yyerrState == 0)
     yystack->yyerrState = 3;
-  else if (yystack->yyerrState == 3) 
+  else if (yystack->yyerrState == 3)
     {
       /* We just shifted the error token and (perhaps) took some
 	 reductions. Skip tokens until we can proceed. */
@@ -1584,7 +1525,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	if (*yytokenp == YYEOF)
 	  yyFail (yystack, NULL);
 	if (*yytokenp != YYEMPTY)
-	  YYDPRINTF ((stderr, "Discarding token %s\n", 
+	  YYDPRINTF ((stderr, "Discarding token %s\n",
 		      yytokenName (*yytokenp)));
 	yychar = YYLEX;
 	*yytokenp = YYTRANSLATE (yychar);
@@ -1603,7 +1544,7 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
 	  return;
       } while (yytrue);
     }
-      
+
   /* Reduce to one stack */
   for (yyk = 0; yyk < yystack->yytops.yysize; yyk += 1)
     if (yystack->yytops.yystates[yyk] != NULL)
@@ -1616,13 +1557,13 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
   yycompressStack (yystack);
 
   /* Now pop stack until we find a state that shifts the error token. */
-  while (yystack->yytops.yystates[0] != NULL) 
+  while (yystack->yytops.yystates[0] != NULL)
     {
       yyj = yypact[yystack->yytops.yystates[0]->yylrState] + YYTERROR;
-      if (yyj != YYFLAG + YYTERROR && yyj >= 0 && yyj <= YYLAST && 
+      if (yyj != YYFLAG + YYTERROR && yyj >= 0 && yyj <= YYLAST &&
 	  yycheck[yyj] == YYTERROR && yyisShiftAction (yytable[yyj]))
 	{
-	  yyglrShift (yystack, 0, yytable[yyj], 
+	  yyglrShift (yystack, 0, yytable[yyj],
 		      yystack->yytops.yystates[0]->yyposn, *yylvalp, yyllocp);
 	  break;
 	}
@@ -1632,8 +1573,8 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
     }
   if (yystack->yytops.yystates[0] == NULL)
     yyFail (yystack, NULL);
-}    
-  
+}
+
 #define YYCHK1(YYE)							     \
   do {									     \
     switch (YYE) {							     \
@@ -1648,10 +1589,10 @@ yyrecoverParseError (yyGLRStack* yystack, YYSTYPE* yylvalp, YYLTYPE* yyllocp)
     case yyerr:								     \
       goto yyuser_error;						     \
     }									     \
-  } while (0) 
+  } while (0)
 
 int
-yyparse (YYPARSE_PARAM_ARG) 
+yyparse (YYPARSE_PARAM_ARG)
 {
   yySymbol yytoken;
   yyGLRStack yystack;
@@ -1666,7 +1607,7 @@ yyparse (YYPARSE_PARAM_ARG)
 
   YYSTYPE* const yylvalp = &yylval;
   YYLTYPE* const yyllocp = &yylloc;
-  
+
   yyinitGLRStack (&yystack, YYINITDEPTH);
   yystack.yytokenp = &yytoken;
 
@@ -1677,14 +1618,14 @@ yyparse (YYPARSE_PARAM_ARG)
   yytoken = YYEMPTY;
   yyposn = 0;
 
-  while (yytrue) 
+  while (yytrue)
     {
       /* For efficiency, we have two loops, of which the first of which
        * is specialized to deterministic operation (single stack, no
        * potential ambiguity). */
-       
+
       /* Standard mode */
-      while (yytrue) 
+      while (yytrue)
 	{
 	  yyRuleNum yyrule;
 	  int yyaction;
@@ -1693,31 +1634,31 @@ yyparse (YYPARSE_PARAM_ARG)
 	  yyStateNum yystate = yystack.yytops.yystates[0]->yylrState;
 	  if (yystate == YYFINAL)
 	    goto yyDone;
-	  if (yyisDefaultedState (yystate)) 
+	  if (yyisDefaultedState (yystate))
 	    {
 	      yyrule = yydefaultAction (yystate);
-	      if (yyrule == 0) 
+	      if (yyrule == 0)
 		{
 		  yyreportParseError (&yystack, yylvalp, yyllocp);
 		  goto yyuser_error;
 		}
 	      YYCHK1 (yyglrReduce (&yystack, 0, yyrule, yytrue));
 	    }
-	  else 
+	  else
 	    {
-	      if (yytoken == YYEMPTY) 
+	      if (yytoken == YYEMPTY)
 		{
 		  yychar = YYLEX;
 		  yytoken = YYTRANSLATE (yychar);
-		  YYDPRINTF ((stderr, "Read token %s\n", 
+		  YYDPRINTF ((stderr, "Read token %s\n",
 			      yytokenName (yytoken)));
 		}
 	      yygetLRActions (yystate, yytoken, &yyaction, &yyconflicts);
 	      if (*yyconflicts != 0)
 		break;
-	      if (yyisShiftAction (yyaction)) 
+	      if (yyisShiftAction (yyaction))
 		{
-		  YYDPRINTF ((stderr, "Shifted token %s. ", 
+		  YYDPRINTF ((stderr, "Shifted token %s. ",
 			      yytokenName (yytoken)));
 		  if (yytoken != YYEOF)
 		    yytoken = YYEMPTY;
@@ -1725,7 +1666,7 @@ yyparse (YYPARSE_PARAM_ARG)
 		  yyglrShift (&yystack, 0, yyaction, yyposn, yylval, yyllocp);
 		  if (yystack.yyerrState > 0)
 		    yystack.yyerrState -= 1;
-		  YYDPRINTF ((stderr, "Now in state #%d\n", 
+		  YYDPRINTF ((stderr, "Now in state #%d\n",
 			      yystack.yytops.yystates[0]->yylrState));
 		}
 	      else if (yyisErrorAction (yyaction))
@@ -1738,7 +1679,7 @@ yyparse (YYPARSE_PARAM_ARG)
 	    }
 	}
 
-      while (yytrue) 
+      while (yytrue)
 	{
 	  int yys;
 	  int yyn = yystack.yytops.yysize;
@@ -1758,7 +1699,7 @@ yyparse (YYPARSE_PARAM_ARG)
 	      yyreportParseError (&yystack, yylvalp, yyllocp);
 	      goto yyuser_error;
 	    }
-	  else if (yystack.yytops.yysize == 1) 
+	  else if (yystack.yytops.yysize == 1)
 	    {
 	      YYCHK1 (yyresolveStack (&yystack));
 	      YYDPRINTF ((stderr, "Returning to deterministic operation.\n"));
@@ -1781,28 +1722,28 @@ yyparse (YYPARSE_PARAM_ARG)
 /* DEBUGGING ONLY */
 
 void
-yypstates (yyGLRState* yyst) 
+yypstates (yyGLRState* yyst)
 {
-  void yy_yypstack (yyGLRState* yys) 
+  void yy_yypstack (yyGLRState* yys)
     {
       if (yys->yypred == NULL)
 	fprintf (stderr, "%d@%d", yys->yylrState, yys->yyposn);
-      else 
+      else
 	{
 	  yy_yypstack (yys->yypred);
 	  fprintf (stderr, " -> %d@%d", yys->yylrState, yys->yyposn);
 	}
     }
 
-  if (yyst == NULL) 
+  if (yyst == NULL)
     fprintf (stderr, "<null>");
-  else 
+  else
     yy_yypstack (yyst);
   fprintf (stderr, "\n");
 }
 
 void
-yypstack (yyGLRStack* yystack, int yyk) 
+yypstack (yyGLRStack* yystack, int yyk)
 {
   yypstates (yystack->yytops.yystates[yyk]);
 }
@@ -1812,27 +1753,27 @@ yypstack (yyGLRStack* yystack, int yyk)
 
 
 void
-yypdumpstack (yyGLRStack* yystack) 
+yypdumpstack (yyGLRStack* yystack)
 {
   yyGLRStackItem* yyp;
   int yyi;
-  for (yyp = yystack->yyitems; yyp < yystack->yynextFree; yyp += 1) 
+  for (yyp = yystack->yyitems; yyp < yystack->yynextFree; yyp += 1)
     {
       fprintf (stderr, "%3d. ", yyp - yystack->yyitems);
-      if (*(bool*) yyp) 
+      if (*(bool*) yyp)
 	{
 	  fprintf (stderr, "Res: %d, LR State: %d, posn: %d, pred: %d",
-		   yyp->yystate.yyresolved, yyp->yystate.yylrState, 
+		   yyp->yystate.yyresolved, yyp->yystate.yylrState,
 		   yyp->yystate.yyposn,
 		   YYINDEX(yyp->yystate.yypred));
-	  if (! yyp->yystate.yyresolved) 
-	    fprintf (stderr, ", firstVal: %d", 
+	  if (! yyp->yystate.yyresolved)
+	    fprintf (stderr, ", firstVal: %d",
 		     YYINDEX (yyp->yystate.yysemantics.yyfirstVal));
 	}
-      else  
+      else
 	{
 	  fprintf (stderr, "Option. rule: %d, state: %d, next: %d",
-		   yyp->yyoption.yyrule, YYINDEX (yyp->yyoption.yystate), 
+		   yyp->yyoption.yyrule, YYINDEX (yyp->yyoption.yystate),
 		   YYINDEX (yyp->yyoption.yynext));
 	}
       fprintf (stderr, "\n");
@@ -1848,6 +1789,7 @@ yypdumpstack (yyGLRStack* yystack)
 b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [#output "b4_output_header_name"
+b4_copyright([Skeleton parser for GLR parsing with Bison], [2002])
 #ifndef b4_header_guard
 # define b4_header_guard
 
