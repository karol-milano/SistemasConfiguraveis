@@ -38,6 +38,16 @@ b4_use_push_for_pull_if([
   b4_push_if([m4_define([b4_use_push_for_pull_flag], [[0]])],
              [m4_define([b4_push_flag], [[1]])])])
 
+# Check the value of %define parse.lac, where LAC stands for lookahead
+# correction.
+b4_percent_define_default([[parse.lac]], [[none]])
+b4_percent_define_default([[parse.lac.es-capacity]], [[20]])
+b4_percent_define_check_values([[[[parse.lac]], [[full]], [[none]]]])
+b4_define_flag_if([lac])
+m4_define([b4_lac_flag],
+          [m4_if(b4_percent_define_get([[parse.lac]]),
+                 [none], [[0]], [[1]])])
+
 m4_include(b4_pkgdatadir/[c.m4])
 
 ## ---------------- ##
@@ -629,7 +639,8 @@ do								\
     {								\
       yychar = (Token);						\
       yylval = (Value);						\
-      YYPOPSTACK (1);						\
+      YYPOPSTACK (1);						\]b4_lac_if([[
+      YY_LAC_DISCARD ("YYBACKUP");				\]])[
       goto yybackup;						\
     }								\
   else								\
@@ -813,9 +824,173 @@ int yydebug;
 
 #ifndef YYMAXDEPTH
 # define YYMAXDEPTH ]b4_stack_depth_max[
+#endif]b4_lac_if([[
+
+/* Establish the initial context for the current lookahead if no initial
+   context is currently established.
+
+   We define a context as a snapshot of the parser stacks.  We define
+   the initial context for a lookahead as the context in which the
+   parser initially examines that lookahead in order to select a
+   syntactic action.  Thus, if the lookahead eventually proves
+   syntactically unacceptable (possibly in a later context reached via a
+   series of reductions), the initial context can be used to determine
+   the exact set of tokens that would be syntactically acceptable in the
+   lookahead's place.  Moreover, it is the context after which any
+   further semantic actions would be erroneous because they would be
+   determined by a syntactically unacceptable token.
+
+   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
+   performed in an inconsistent state (which, for the purposes of LAC,
+   includes consistent states that don't know they're consistent because
+   their default reductions have been disabled).  Iff there is a
+   lookahead token, it should also be invoked before reporting a syntax
+   error.  This latter case is for the sake of the debugging output.
+
+   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
+   follows.  If no initial context is currently established for the
+   current lookahead, then check if that lookahead can eventually be
+   shifted if syntactic actions continue from the current context.
+   Report a syntax error if it cannot.  */
+#define YY_LAC_ESTABLISH                                       \
+do {                                                           \
+  if (!yy_lac_established)                                     \
+    {                                                          \
+      YYDPRINTF ((stderr,                                      \
+                  "LAC: initial context established for %s\n", \
+                  yytname[yytoken]));                          \
+      yy_lac_established = 1;                                  \
+      {                                                        \
+        int yy_lac_status =                                    \
+          yy_lac (yyssp, yytoken);                             \
+        if (yy_lac_status == 2)                                \
+          goto yyexhaustedlab;                                 \
+        if (yy_lac_status == 1)                                \
+          goto yyerrlab;                                       \
+      }                                                        \
+    }                                                          \
+} while (YYID (0))
+
+/* Discard any previous initial lookahead context because of Event,
+   which may be a lookahead change or an invalidation of the currently
+   established initial context for the current lookahead.
+
+   The most common example of a lookahead change is a shift.  An example
+   of both cases is syntax error recovery.  That is, a syntax error
+   occurs when the lookahead is syntactically erroneous for the
+   currently established initial context, so error recovery manipulates
+   the parser stacks to try to find a new initial context in which the
+   current lookahead is syntactically acceptable.  If it fails to find
+   such a context, it discards the lookahead.  */
+#if YYDEBUG
+# define YY_LAC_DISCARD(Event)                                           \
+do {                                                                     \
+  if (yy_lac_established)                                                \
+    {                                                                    \
+      if (yydebug)                                                       \
+        YYFPRINTF (stderr, "LAC: initial context discarded due to "      \
+                   Event "\n");                                          \
+      yy_lac_established = 0;                                            \
+    }                                                                    \
+} while (YYID (0))
+#else
+# define YY_LAC_DISCARD(Event) yy_lac_established = 0
 #endif
 
-
+/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
+   eventually (after perhaps some reductions) be shifted, and return 1
+   if not.  Return 2 if memory is exhausted.  */
+static int
+yy_lac (yytype_int16 *yyssp, int yytoken)
+{
+  yytype_int16 *yyes_prev = yyssp;
+  yytype_int16 yyes@{]b4_percent_define_get([[parse.lac.es-capacity]])[@};
+  yytype_int16 *yyesp = yyes_prev;
+  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
+  if (yytoken == YYUNDEFTOK)
+    {
+      YYDPRINTF ((stderr, " Always Err\n"));
+      return 1;
+    }
+  while (1)
+    {
+      int yyrule = yypact[*yyesp];
+      if (yypact_value_is_default (yyrule)
+          || (yyrule += yytoken) < 0 || YYLAST < yyrule
+          || yycheck[yyrule] != yytoken)
+        {
+          yyrule = yydefact[*yyesp];
+          if (yyrule == 0)
+            {
+              YYDPRINTF ((stderr, " Err\n"));
+              return 1;
+            }
+        }
+      else
+        {
+          yyrule = yytable[yyrule];
+          if (yytable_value_is_error (yyrule))
+            {
+              YYDPRINTF ((stderr, " Err\n"));
+              return 1;
+            }
+          if (0 < yyrule)
+            {
+              YYDPRINTF ((stderr, " S%d\n", yyrule));
+              return 0;
+            }
+          yyrule = -yyrule;
+        }
+      {
+        YYSIZE_T yylen = yyr2[yyrule];
+        YYDPRINTF ((stderr, " R%d", yyrule - 1));
+        if (yyesp != yyes_prev)
+          {
+            YYSIZE_T yysize = yyesp - yyes + 1;
+            if (yylen < yysize)
+              {
+                yyesp -= yylen;
+                yylen = 0;
+              }
+            else
+              {
+                yylen -= yysize;
+                yyesp = yyes_prev;
+              }
+          }
+        if (yylen)
+          yyesp = yyes_prev -= yylen;
+      }
+      {
+        int yystate;
+        {
+          int yylhs = yyr1[yyrule] - YYNTOKENS;
+          yystate = yypgoto[yylhs] + *yyesp;
+          if (yystate < 0 || YYLAST < yystate
+              || yycheck[yystate] != *yyesp)
+            yystate = yydefgoto[yylhs];
+          else
+            yystate = yytable[yystate];
+        }
+        if (yyesp == yyes_prev)
+          {
+            yyesp = yyes;
+            *yyesp = yystate;
+          }
+        else
+          {
+            if (yyesp == yyes + (sizeof yyes / sizeof *yyes) - 1)
+              {
+                YYDPRINTF ((stderr, " (max stack size exceeded)\n"));
+                return 2;
+              }
+            *++yyesp = yystate;
+          }
+        YYDPRINTF ((stderr, " G%d", *yyesp));
+      }
+    }
+}]])[
+
 
 #if YYERROR_VERBOSE
 
@@ -904,15 +1079,18 @@ yytnamerr (char *yyres, const char *yystr)
 # endif
 
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
-   about the unexpected token YYTOKEN while in state YYSTATE.
+   about the unexpected token YYTOKEN for the state stack whose top is
+   YYSSP.]b4_lac_if([[  In order to see if a particular token T is a
+   valid looakhead, invoke yy_lac (YYSSP, T).]])[
 
    Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
    not large enough to hold the message.  In that case, also set
    *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
-   required number of bytes is too large to store.  */
+   required number of bytes is too large to store]b4_lac_if([[ or if
+   yy_lac returned 2]])[.  */
 static int
 yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
-                int yystate, int yytoken)
+                yytype_int16 *yyssp, int yytoken)
 {
   YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
@@ -943,7 +1121,12 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
      - Don't assume there isn't a lookahead just because this state is a
        consistent state with a default action.  There might have been a
        previous inconsistent state, consistent state with a non-default
-       action, or user semantic action that manipulated yychar.
+       action, or user semantic action that manipulated yychar.]b4_lac_if([[
+       In the first two cases, it might appear that the current syntax
+       error should have been detected in the previous state when yy_lac
+       was invoked.  However, at that time, there might have been a
+       different syntax error that discarded a different initial context
+       during error recovery, leaving behind the current lookahead.]], [[
      - Of course, the expected token list depends on states to have
        correct lookahead information, and it depends on the parser not
        to perform extra reductions after fetching a lookahead from the
@@ -951,26 +1134,39 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
        (from LALR or IELR) and default reductions corrupt the expected
        token list.  However, the list is correct for canonical LR with
        one exception: it will still contain any token that will not be
-       accepted due to an error action in a later state.
+       accepted due to an error action in a later state.]])[
   */
   if (yytoken != YYEMPTY)
     {
-      int yyn = yypact[yystate];
+      int yyn = yypact[*yyssp];]b4_lac_if([[
+      YYDPRINTF ((stderr, "Constructing syntax error message\n"));]])[
       yyarg[yycount++] = yytname[yytoken];
       if (!yypact_value_is_default (yyn))
-        {
+        {]b4_lac_if([], [[
           /* Start YYX at -YYN if negative to avoid negative indexes in
              YYCHECK.  In other words, skip the first -YYN actions for
              this state because they are default actions.  */
           int yyxbegin = yyn < 0 ? -yyn : 0;
           /* Stay within bounds of both yycheck and yytname.  */
           int yychecklim = YYLAST - yyn + 1;
-          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
-          int yyx;
+          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;]])[
+          int yyx;]b4_lac_if([[
+
+          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
+            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
+              {
+                {
+                  int yy_lac_status = yy_lac (yyssp, yyx);
+                  if (yy_lac_status == 2)
+                    return 2;
+                  if (yy_lac_status == 1)
+                    continue;
+                }]], [[
+
           for (yyx = yyxbegin; yyx < yyxend; ++yyx)
             if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                 && !yytable_value_is_error (yytable[yyx + yyn]))
-              {
+              {]])[
                 if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                   {
                     yycount = 1;
@@ -984,12 +1180,16 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                   return 2;
                 yysize = yysize1;
               }
-        }
+        }]b4_lac_if([[
+# if YYDEBUG
+      else if (yydebug)
+        YYFPRINTF (stderr, "No expected tokens.\n");
+# endif]])[
     }
 
   switch (yycount)
     {
-#define YYCASE_(N, S)                       \
+# define YYCASE_(N, S)                      \
       case N:                               \
         yyformat = S;                       \
       break
@@ -999,7 +1199,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
       YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
       YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
       YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
-#undef YYCASE_
+# undef YYCASE_
     }
 
   yysize1 = yysize + yystrlen (yyformat);
@@ -1037,7 +1237,6 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   return 0;
 }
 #endif /* YYERROR_VERBOSE */
-
 
 ]b4_yydestruct_generate([b4_c_function_def])b4_push_if([], [[
 
@@ -1172,7 +1371,8 @@ b4_c_function_def([[yyparse]], [[int]], b4_parse_param)[
   YYLTYPE yypushed_loc = yylloc;]])
 ])],
   [b4_declare_parser_state_variables
-])[
+])b4_lac_if([[
+  int yy_lac_established = 0;]])[
   int yyn;
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
@@ -1379,13 +1579,18 @@ yyread_pushed_token:]])[
   /* If the proper action on seeing token YYTOKEN is to reduce or to
      detect an error, take that action.  */
   yyn += yytoken;
-  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
-    goto yydefault;
+  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)]b4_lac_if([[
+    {
+      YY_LAC_ESTABLISH;
+      goto yydefault;
+    }]], [[
+    goto yydefault;]])[
   yyn = yytable[yyn];
   if (yyn <= 0)
     {
       if (yytable_value_is_error (yyn))
-	goto yyerrlab;
+        goto yyerrlab;]b4_lac_if([[
+      YY_LAC_ESTABLISH;]])[
       yyn = -yyn;
       goto yyreduce;
     }
@@ -1399,7 +1604,8 @@ yyread_pushed_token:]])[
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
 
   /* Discard the shifted token.  */
-  yychar = YYEMPTY;
+  yychar = YYEMPTY;]b4_lac_if([[
+  YY_LAC_DISCARD ("shift");]])[
 
   yystate = yyn;
   *++yyvsp = yylval;
@@ -1437,12 +1643,22 @@ yyreduce:
 ]b4_locations_if(
 [[  /* Default location.  */
   YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);]])[
-  YY_REDUCE_PRINT (yyn);
+  YY_REDUCE_PRINT (yyn);]b4_lac_if([[
+  {
+    int yychar_backup = yychar;
+    switch (yyn)
+      {
+        ]b4_user_actions[
+        default: break;
+      }
+    if (yychar_backup != yychar)
+      YY_LAC_DISCARD ("yychar change");
+  }]], [[
   switch (yyn)
     {
       ]b4_user_actions[
       default: break;
-    }
+    }]])[
   /* User semantic actions sometimes alter yychar, and that requires
      that yytoken be updated with the new translation.  We take the
      approach of translating immediately before every use of yytoken.
@@ -1493,11 +1709,14 @@ yyerrlab:
 #if ! YYERROR_VERBOSE
       yyerror (]b4_yyerror_args[YY_("syntax error"));
 #else
-# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, yystate, \
+# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, yyssp, \
                                         yytoken)
       {
         char const *yymsgp = YY_("syntax error");
-        int yysyntax_error_status = YYSYNTAX_ERROR;
+        int yysyntax_error_status;]b4_lac_if([[
+        if (yychar != YYEMPTY)
+          YY_LAC_ESTABLISH;]])[
+        yysyntax_error_status = YYSYNTAX_ERROR;
         if (yysyntax_error_status == 0)
           yymsgp = yymsg;
         else if (yysyntax_error_status == 1)
@@ -1602,7 +1821,11 @@ yyerrlab1:
       YYPOPSTACK (1);
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
-    }
+    }]b4_lac_if([[
+
+  /* If the stack popping above didn't lose the initial context for the
+     current lookahead token, the shift below will for sure.  */
+  YY_LAC_DISCARD ("error recovery");]])[
 
   *++yyvsp = yylval;
 ]b4_locations_if([[
@@ -1633,7 +1856,7 @@ yyabortlab:
   yyresult = 1;
   goto yyreturn;
 
-#if !defined(yyoverflow) || YYERROR_VERBOSE
+#if ]b4_lac_if([[1]], [[!defined(yyoverflow) || YYERROR_VERBOSE]])[
 /*-------------------------------------------------.
 | yyexhaustedlab -- memory exhaustion comes here.  |
 `-------------------------------------------------*/
