@@ -76,8 +76,8 @@ m4_define([b4_pure_flag],
 # Expand IF-TRUE, if %pure-parser and %parse-param, IF-FALSE otherwise.
 m4_define([b4_yacc_pure_if],
 [b4_pure_if([m4_ifset([b4_parse_param],
-		      [$1], [$2])],
-	    [$2])])
+                      [$1], [$2])],
+            [$2])])
 
 
 # b4_yyerror_args
@@ -117,7 +117,7 @@ m4_define([b4_int_type],
 
        m4_eval([0 <= $1]),                [1], [unsigned int],
 
-					       [int])])
+                                               [int])])
 
 
 ## ----------------- ##
@@ -464,7 +464,7 @@ b4_push_if([], [b4_lac_if([], [[
 #  endif
 #  if (defined __cplusplus && ! defined EXIT_SUCCESS \
        && ! ((defined YYMALLOC || defined malloc) \
-	     && (defined YYFREE || defined free)))
+             && (defined YYFREE || defined free)))
 #   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #   ifndef EXIT_SUCCESS
 #    define EXIT_SUCCESS 0
@@ -489,8 +489,8 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 
 #if (! defined yyoverflow \
      && (! defined __cplusplus \
-	 || (]b4_locations_if([[defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
-	     && ]])[defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))
+         || (]b4_locations_if([[defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
+             && ]])[defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))
 
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
@@ -520,15 +520,15 @@ union yyalloc
    elements in the stack, and YYPTR gives the new location of the
    stack.  Advance YYPTR to a properly aligned location for the next
    stack.  */
-# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
-    do									\
-      {									\
-	YYSIZE_T yynewbytes;						\
-	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
-	Stack = &yyptr->Stack_alloc;					\
-	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
-	yyptr += yynewbytes / sizeof (*yyptr);				\
-      }									\
+# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
+    do                                                                  \
+      {                                                                 \
+        YYSIZE_T yynewbytes;                                            \
+        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
+        Stack = &yyptr->Stack_alloc;                                    \
+        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
+        yyptr += yynewbytes / sizeof (*yyptr);                          \
+      }                                                                 \
     while (YYID (0))
 
 #endif
@@ -541,13 +541,13 @@ union yyalloc
 #   define YYCOPY(To, From, Count) \
       __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
 #  else
-#   define YYCOPY(To, From, Count)		\
-      do					\
-	{					\
-	  YYSIZE_T yyi;				\
-	  for (yyi = 0; yyi < (Count); yyi++)	\
-	    (To)[yyi] = (From)[yyi];		\
-	}					\
+#   define YYCOPY(To, From, Count)              \
+      do                                        \
+        {                                       \
+          YYSIZE_T yyi;                         \
+          for (yyi = 0; yyi < (Count); yyi++)   \
+            (To)[yyi] = (From)[yyi];            \
+        }                                       \
       while (YYID (0))
 #  endif
 # endif
@@ -572,7 +572,7 @@ union yyalloc
 #define YYUNDEFTOK  ]b4_undef_token_number[
 #define YYMAXUTOK   ]b4_user_token_number_max[
 
-#define YYTRANSLATE(YYX)						\
+#define YYTRANSLATE(YYX)                                                \
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
@@ -617,14 +617,14 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 
 ]b4_parser_tables_define[
 
-#define yyerrok		(yyerrstatus = 0)
-#define yyclearin	(yychar = YYEMPTY)
-#define YYEMPTY		(-2)
-#define YYEOF		0
+#define yyerrok         (yyerrstatus = 0)
+#define yyclearin       (yychar = YYEMPTY)
+#define YYEMPTY         (-2)
+#define YYEOF           0
 
-#define YYACCEPT	goto yyacceptlab
-#define YYABORT		goto yyabortlab
-#define YYERROR		goto yyerrorlab
+#define YYACCEPT        goto yyacceptlab
+#define YYABORT         goto yyabortlab
+#define YYERROR         goto yyerrorlab
 
 
 /* Like YYERROR except do call yyerror.  This remains here temporarily
@@ -634,7 +634,7 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
    in Bison 2.4.2's NEWS entry, where a plan to phase it out is
    discussed.  */
 
-#define YYFAIL		goto yyerrlab
+#define YYFAIL          goto yyerrlab
 #if defined YYFAIL
   /* This is here to suppress warnings from the GCC cpp's
      -Wunused-macros.  Normally we don't worry about that warning, but
@@ -644,26 +644,26 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 
 #define YYRECOVERING()  (!!yyerrstatus)
 
-#define YYBACKUP(Token, Value)					\
-do								\
-  if (yychar == YYEMPTY && yylen == 1)				\
-    {								\
-      yychar = (Token);						\
-      yylval = (Value);						\
-      YYPOPSTACK (1);						\]b4_lac_if([[
-      YY_LAC_DISCARD ("YYBACKUP");				\]])[
-      goto yybackup;						\
-    }								\
-  else								\
-    {								\
+#define YYBACKUP(Token, Value)                                  \
+do                                                              \
+  if (yychar == YYEMPTY && yylen == 1)                          \
+    {                                                           \
+      yychar = (Token);                                         \
+      yylval = (Value);                                         \
+      YYPOPSTACK (1);                                           \]b4_lac_if([[
+      YY_LAC_DISCARD ("YYBACKUP");                              \]])[
+      goto yybackup;                                            \
+    }                                                           \
+  else                                                          \
+    {                                                           \
       yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")); \
-      YYERROR;							\
-    }								\
+      YYERROR;                                                  \
+    }                                                           \
 while (YYID (0))
 
 
-#define YYTERROR	1
-#define YYERRCODE	256
+#define YYTERROR        1
+#define YYERRCODE       256
 
 
 /* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
@@ -672,22 +672,22 @@ while (YYID (0))
 
 #define YYRHSLOC(Rhs, K) ((Rhs)[K])
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)				\
-    do									\
+# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
+    do                                                                  \
       if (YYID (N))                                                    \
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
 #endif]b4_locations_if([[
 
@@ -698,10 +698,10 @@ while (YYID (0))
 
 #ifndef YY_LOCATION_PRINT
 # if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
-#  define YY_LOCATION_PRINT(File, Loc)			\
-     fprintf (File, "%d.%d-%d.%d",			\
-	      (Loc).first_line, (Loc).first_column,	\
-	      (Loc).last_line,  (Loc).last_column)
+#  define YY_LOCATION_PRINT(File, Loc)                  \
+     fprintf (File, "%d.%d-%d.%d",                      \
+              (Loc).first_line, (Loc).first_column,     \
+              (Loc).last_line,  (Loc).last_column)
 # else
 #  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 # endif
@@ -731,21 +731,21 @@ while (YYID (0))
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
 
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
-do {									  \
-  if (yydebug)								  \
-    {									  \
-      YYFPRINTF (stderr, "%s ", Title);					  \
-      yy_symbol_print (stderr,						  \
-		  Type, Value]b4_locations_if([, Location])[]b4_user_args[); \
-      YYFPRINTF (stderr, "\n");						  \
-    }									  \
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
+do {                                                                      \
+  if (yydebug)                                                            \
+    {                                                                     \
+      YYFPRINTF (stderr, "%s ", Title);                                   \
+      yy_symbol_print (stderr,                                            \
+                  Type, Value]b4_locations_if([, Location])[]b4_user_args[); \
+      YYFPRINTF (stderr, "\n");                                           \
+    }                                                                     \
 } while (YYID (0))
 
 ]b4_yy_symbol_print_generate([b4_c_function_def])[
@@ -756,8 +756,8 @@ do {									  \
 `------------------------------------------------------------------*/
 
 ]b4_c_function_def([yy_stack_print], [static void],
-		   [[yytype_int16 *yybottom], [yybottom]],
-		   [[yytype_int16 *yytop],    [yytop]])[
+                   [[yytype_int16 *yybottom], [yybottom]],
+                   [[yytype_int16 *yytop],    [yytop]])[
 {
   YYFPRINTF (stderr, "Stack now");
   for (; yybottom <= yytop; yybottom++)
@@ -768,10 +768,10 @@ do {									  \
   YYFPRINTF (stderr, "\n");
 }
 
-# define YY_STACK_PRINT(Bottom, Top)				\
-do {								\
-  if (yydebug)							\
-    yy_stack_print ((Bottom), (Top));				\
+# define YY_STACK_PRINT(Bottom, Top)                            \
+do {                                                            \
+  if (yydebug)                                                  \
+    yy_stack_print ((Bottom), (Top));                           \
 } while (YYID (0))
 
 
@@ -804,9 +804,9 @@ do {								\
     }
 }
 
-# define YY_REDUCE_PRINT(Rule)		\
-do {					\
-  if (yydebug)				\
+# define YY_REDUCE_PRINT(Rule)          \
+do {                                    \
+  if (yydebug)                          \
     yy_reduce_print (yyssp, yyvsp, ]b4_locations_if([yylsp, ])[Rule]b4_user_args[); \
 } while (YYID (0))
 
@@ -822,7 +822,7 @@ int yydebug;
 
 
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
-#ifndef	YYINITDEPTH
+#ifndef YYINITDEPTH
 # define YYINITDEPTH ]b4_stack_depth_init[
 #endif
 
@@ -1129,27 +1129,27 @@ yytnamerr (char *yyres, const char *yystr)
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
 
@@ -1552,26 +1552,26 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 
 #ifdef yyoverflow
       {
-	/* Give user a chance to reallocate the stack.  Use copies of
-	   these so that the &'s don't force the real ones into
-	   memory.  */
-	YYSTYPE *yyvs1 = yyvs;
-	yytype_int16 *yyss1 = yyss;]b4_locations_if([
-	YYLTYPE *yyls1 = yyls;])[
-
-	/* Each stack pointer address is followed by the size of the
-	   data in use in that stack, in bytes.  This used to be a
-	   conditional around just the two extra args, but that might
-	   be undefined if yyoverflow is a macro.  */
-	yyoverflow (YY_("memory exhausted"),
-		    &yyss1, yysize * sizeof (*yyssp),
-		    &yyvs1, yysize * sizeof (*yyvsp),]b4_locations_if([
-		    &yyls1, yysize * sizeof (*yylsp),])[
-		    &yystacksize);
+        /* Give user a chance to reallocate the stack.  Use copies of
+           these so that the &'s don't force the real ones into
+           memory.  */
+        YYSTYPE *yyvs1 = yyvs;
+        yytype_int16 *yyss1 = yyss;]b4_locations_if([
+        YYLTYPE *yyls1 = yyls;])[
+
+        /* Each stack pointer address is followed by the size of the
+           data in use in that stack, in bytes.  This used to be a
+           conditional around just the two extra args, but that might
+           be undefined if yyoverflow is a macro.  */
+        yyoverflow (YY_("memory exhausted"),
+                    &yyss1, yysize * sizeof (*yyssp),
+                    &yyvs1, yysize * sizeof (*yyvsp),]b4_locations_if([
+                    &yyls1, yysize * sizeof (*yylsp),])[
+                    &yystacksize);
 ]b4_locations_if([
-	yyls = yyls1;])[
-	yyss = yyss1;
-	yyvs = yyvs1;
+        yyls = yyls1;])[
+        yyss = yyss1;
+        yyvs = yyvs1;
       }
 #else /* no yyoverflow */
 # ifndef YYSTACK_RELOCATE
@@ -1579,23 +1579,23 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
 # else
       /* Extend the stack our own way.  */
       if (YYMAXDEPTH <= yystacksize)
-	goto yyexhaustedlab;
+        goto yyexhaustedlab;
       yystacksize *= 2;
       if (YYMAXDEPTH < yystacksize)
-	yystacksize = YYMAXDEPTH;
+        yystacksize = YYMAXDEPTH;
 
       {
-	yytype_int16 *yyss1 = yyss;
-	union yyalloc *yyptr =
-	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
-	if (! yyptr)
-	  goto yyexhaustedlab;
-	YYSTACK_RELOCATE (yyss_alloc, yyss);
-	YYSTACK_RELOCATE (yyvs_alloc, yyvs);]b4_locations_if([
-	YYSTACK_RELOCATE (yyls_alloc, yyls);])[
+        yytype_int16 *yyss1 = yyss;
+        union yyalloc *yyptr =
+          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
+        if (! yyptr)
+          goto yyexhaustedlab;
+        YYSTACK_RELOCATE (yyss_alloc, yyss);
+        YYSTACK_RELOCATE (yyvs_alloc, yyvs);]b4_locations_if([
+        YYSTACK_RELOCATE (yyls_alloc, yyls);])[
 #  undef YYSTACK_RELOCATE
-	if (yyss1 != yyssa)
-	  YYSTACK_FREE (yyss1);
+        if (yyss1 != yyssa)
+          YYSTACK_FREE (yyss1);
       }
 # endif
 #endif /* no yyoverflow */
@@ -1605,10 +1605,10 @@ m4_ifdef([b4_at_dollar_used], [[  yylsp[0] = yylloc;
       yylsp = yyls + yysize - 1;])[
 
       YYDPRINTF ((stderr, "Stack size increased to %lu\n",
-		  (unsigned long int) yystacksize));
+                  (unsigned long int) yystacksize));
 
       if (yyss + yystacksize - 1 <= yyssp)
-	YYABORT;
+        YYABORT;
     }
 
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
@@ -1844,20 +1844,20 @@ yyerrlab:
   if (yyerrstatus == 3)
     {
       /* If just tried and failed to reuse lookahead token after an
-	 error, discard it.  */
+         error, discard it.  */
 
       if (yychar <= YYEOF)
-	{
-	  /* Return failure if at end of input.  */
-	  if (yychar == YYEOF)
-	    YYABORT;
-	}
+        {
+          /* Return failure if at end of input.  */
+          if (yychar == YYEOF)
+            YYABORT;
+        }
       else
-	{
-	  yydestruct ("Error: discarding",
-		      yytoken, &yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
-	  yychar = YYEMPTY;
-	}
+        {
+          yydestruct ("Error: discarding",
+                      yytoken, &yylval]b4_locations_if([, &yylloc])[]b4_user_args[);
+          yychar = YYEMPTY;
+        }
     }
 
   /* Else will try to reuse lookahead token after shifting the error
@@ -1890,29 +1890,29 @@ yyerrorlab:
 | yyerrlab1 -- common code for both syntax error and YYERROR.  |
 `-------------------------------------------------------------*/
 yyerrlab1:
-  yyerrstatus = 3;	/* Each real token shifted decrements this.  */
+  yyerrstatus = 3;      /* Each real token shifted decrements this.  */
 
   for (;;)
     {
       yyn = yypact[yystate];
       if (!yypact_value_is_default (yyn))
-	{
-	  yyn += YYTERROR;
-	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
-	    {
-	      yyn = yytable[yyn];
-	      if (0 < yyn)
-		break;
-	    }
-	}
+        {
+          yyn += YYTERROR;
+          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
+            {
+              yyn = yytable[yyn];
+              if (0 < yyn)
+                break;
+            }
+        }
 
       /* Pop the current state because it cannot handle the error token.  */
       if (yyssp == yyss)
-	YYABORT;
+        YYABORT;
 
 ]b4_locations_if([[      yyerror_range[1] = *yylsp;]])[
       yydestruct ("Error: popping",
-		  yystos[yystate], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
+                  yystos[yystate], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK (1);
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -1977,7 +1977,7 @@ yyreturn:
   while (yyssp != yyss)
     {
       yydestruct ("Cleanup: popping",
-		  yystos[*yyssp], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
+                  yystos[*yyssp], yyvsp]b4_locations_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK (1);
     }
 #ifndef yyoverflow
