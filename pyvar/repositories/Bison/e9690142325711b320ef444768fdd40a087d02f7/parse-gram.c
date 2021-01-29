@@ -113,7 +113,7 @@
 static YYLTYPE lloc_default (YYLTYPE const *, int);
 
 #define YY_LOCATION_PRINT(File, Loc) \
-	  location_print (File, Loc)
+          location_print (File, Loc)
 
 static void version_check (location const *loc, char const *version);
 
@@ -121,7 +121,7 @@ static void version_check (location const *loc, char const *version);
    FIXME: depends on the undocumented availability of YYLLOC.  */
 #undef  yyerror
 #define yyerror(Msg) \
-	gram_error (&yylloc, Msg)
+        gram_error (&yylloc, Msg)
 static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
@@ -493,7 +493,7 @@ YYID (yyi)
 #  endif
 #  if (defined __cplusplus && ! defined EXIT_SUCCESS \
        && ! ((defined YYMALLOC || defined malloc) \
-	     && (defined YYFREE || defined free)))
+             && (defined YYFREE || defined free)))
 #   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
 #   ifndef EXIT_SUCCESS
 #    define EXIT_SUCCESS 0
@@ -520,8 +520,8 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 
 #if (! defined yyoverflow \
      && (! defined __cplusplus \
-	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
-	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))
+         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
+             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))
 
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
@@ -547,15 +547,15 @@ union yyalloc
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
@@ -568,13 +568,13 @@ union yyalloc
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
@@ -599,7 +599,7 @@ union yyalloc
 #define YYUNDEFTOK  2
 #define YYMAXUTOK   311
 
-#define YYTRANSLATE(YYX)						\
+#define YYTRANSLATE(YYX)                                                \
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
 /* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
@@ -875,14 +875,14 @@ static const yytype_uint8 yyr2[] =
 };
 
 
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
@@ -892,7 +892,7 @@ static const yytype_uint8 yyr2[] =
    in Bison 2.4.2's NEWS entry, where a plan to phase it out is
    discussed.  */
 
-#define YYFAIL		goto yyerrlab
+#define YYFAIL          goto yyerrlab
 #if defined YYFAIL
   /* This is here to suppress warnings from the GCC cpp's
      -Wunused-macros.  Normally we don't worry about that warning, but
@@ -902,26 +902,26 @@ static const yytype_uint8 yyr2[] =
 
 #define YYRECOVERING()  (!!yyerrstatus)
 
-#define YYBACKUP(Token, Value)					\
-do								\
-  if (yychar == YYEMPTY && yylen == 1)				\
-    {								\
-      yychar = (Token);						\
-      yylval = (Value);						\
-      YYPOPSTACK (1);						\
-      YY_LAC_DISCARD ("YYBACKUP");				\
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
+      YYPOPSTACK (1);                                           \
+      YY_LAC_DISCARD ("YYBACKUP");                              \
+      goto yybackup;                                            \
+    }                                                           \
+  else                                                          \
+    {                                                           \
       yyerror (YY_("syntax error: cannot back up")); \
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
@@ -930,22 +930,22 @@ while (YYID (0))
 
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
 #endif
 
@@ -956,10 +956,10 @@ while (YYID (0))
 
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
@@ -982,21 +982,21 @@ while (YYID (0))
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
-		  Type, Value, Location); \
-      YYFPRINTF (stderr, "\n");						  \
-    }									  \
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
+do {                                                                      \
+  if (yydebug)                                                            \
+    {                                                                     \
+      YYFPRINTF (stderr, "%s ", Title);                                   \
+      yy_symbol_print (stderr,                                            \
+                  Type, Value, Location); \
+      YYFPRINTF (stderr, "\n");                                           \
+    }                                                                     \
 } while (YYID (0))
 
 
@@ -1221,7 +1221,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
         break;
 
       default:
-	break;
+        break;
     }
 }
 
@@ -1279,10 +1279,10 @@ yy_stack_print (yybottom, yytop)
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
 
 
@@ -1320,9 +1320,9 @@ yy_reduce_print (yyssp, yyvsp, yylsp, yyrule)
     }
 }
 
-# define YY_REDUCE_PRINT(Rule)		\
-do {					\
-  if (yydebug)				\
+# define YY_REDUCE_PRINT(Rule)          \
+do {                                    \
+  if (yydebug)                          \
     yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
 } while (YYID (0))
 
@@ -1338,7 +1338,7 @@ int yydebug;
 
 
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
-#ifndef	YYINITDEPTH
+#ifndef YYINITDEPTH
 # define YYINITDEPTH 200
 #endif
 
@@ -1657,27 +1657,27 @@ yytnamerr (char *yyres, const char *yystr)
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
 
@@ -1858,7 +1858,7 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       default:
-	break;
+        break;
     }
 }
 
@@ -2043,26 +2043,26 @@ YYLTYPE yylloc;
 
 #ifdef yyoverflow
       {
-	/* Give user a chance to reallocate the stack.  Use copies of
-	   these so that the &'s don't force the real ones into
-	   memory.  */
-	YYSTYPE *yyvs1 = yyvs;
-	yytype_int16 *yyss1 = yyss;
-	YYLTYPE *yyls1 = yyls;
-
-	/* Each stack pointer address is followed by the size of the
-	   data in use in that stack, in bytes.  This used to be a
-	   conditional around just the two extra args, but that might
-	   be undefined if yyoverflow is a macro.  */
-	yyoverflow (YY_("memory exhausted"),
-		    &yyss1, yysize * sizeof (*yyssp),
-		    &yyvs1, yysize * sizeof (*yyvsp),
-		    &yyls1, yysize * sizeof (*yylsp),
-		    &yystacksize);
-
-	yyls = yyls1;
-	yyss = yyss1;
-	yyvs = yyvs1;
+        /* Give user a chance to reallocate the stack.  Use copies of
+           these so that the &'s don't force the real ones into
+           memory.  */
+        YYSTYPE *yyvs1 = yyvs;
+        yytype_int16 *yyss1 = yyss;
+        YYLTYPE *yyls1 = yyls;
+
+        /* Each stack pointer address is followed by the size of the
+           data in use in that stack, in bytes.  This used to be a
+           conditional around just the two extra args, but that might
+           be undefined if yyoverflow is a macro.  */
+        yyoverflow (YY_("memory exhausted"),
+                    &yyss1, yysize * sizeof (*yyssp),
+                    &yyvs1, yysize * sizeof (*yyvsp),
+                    &yyls1, yysize * sizeof (*yylsp),
+                    &yystacksize);
+
+        yyls = yyls1;
+        yyss = yyss1;
+        yyvs = yyvs1;
       }
 #else /* no yyoverflow */
 # ifndef YYSTACK_RELOCATE
@@ -2070,23 +2070,23 @@ YYLTYPE yylloc;
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
-	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
-	YYSTACK_RELOCATE (yyls_alloc, yyls);
+        yytype_int16 *yyss1 = yyss;
+        union yyalloc *yyptr =
+          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
+        if (! yyptr)
+          goto yyexhaustedlab;
+        YYSTACK_RELOCATE (yyss_alloc, yyss);
+        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
+        YYSTACK_RELOCATE (yyls_alloc, yyls);
 #  undef YYSTACK_RELOCATE
-	if (yyss1 != yyssa)
-	  YYSTACK_FREE (yyss1);
+        if (yyss1 != yyssa)
+          YYSTACK_FREE (yyss1);
       }
 # endif
 #endif /* no yyoverflow */
@@ -2096,10 +2096,10 @@ YYLTYPE yylloc;
       yylsp = yyls + yysize - 1;
 
       YYDPRINTF ((stderr, "Stack size increased to %lu\n",
-		  (unsigned long int) yystacksize));
+                  (unsigned long int) yystacksize));
 
       if (yyss + yystacksize - 1 <= yyssp)
-	YYABORT;
+        YYABORT;
     }
 
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
@@ -2503,7 +2503,7 @@ yyreduce:
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
-	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
+        symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1740 of yacc.c  */
@@ -2516,7 +2516,7 @@ yyreduce:
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
-	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
+        symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1740 of yacc.c  */
@@ -2640,7 +2640,7 @@ yyreduce:
       symbol_list *list;
       tag_seen = true;
       for (list = (yyvsp[0].list); list; list = list->next)
-	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
+        symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1740 of yacc.c  */
@@ -2654,10 +2654,10 @@ yyreduce:
       symbol_list *list;
       ++current_prec;
       for (list = (yyvsp[0].list); list; list = list->next)
-	{
-	  symbol_type_set (list->content.sym, current_type, (yylsp[-1]));
-	  symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-2].assoc), (yylsp[-2]));
-	}
+        {
+          symbol_type_set (list->content.sym, current_type, (yylsp[-1]));
+          symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-2].assoc), (yylsp[-2]));
+        }
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
@@ -2917,7 +2917,7 @@ yyreduce:
 /* Line 1740 of yacc.c  */
 #line 605 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
-				  current_lhs_named_ref); }
+                                  current_lhs_named_ref); }
 /* Line 1740 of yacc.c  */
 #line 2923 "src/parse-gram.c"
     break;
@@ -3178,20 +3178,20 @@ yyerrlab:
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
-		      yytoken, &yylval, &yylloc);
-	  yychar = YYEMPTY;
-	}
+        {
+          yydestruct ("Error: discarding",
+                      yytoken, &yylval, &yylloc);
+          yychar = YYEMPTY;
+        }
     }
 
   /* Else will try to reuse lookahead token after shifting the error
@@ -3224,29 +3224,29 @@ yyerrorlab:
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
 
       yyerror_range[1] = *yylsp;
       yydestruct ("Error: popping",
-		  yystos[yystate], yyvsp, yylsp);
+                  yystos[yystate], yyvsp, yylsp);
       YYPOPSTACK (1);
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -3311,7 +3311,7 @@ yyreturn:
   while (yyssp != yyss)
     {
       yydestruct ("Cleanup: popping",
-		  yystos[*yyssp], yyvsp, yylsp);
+                  yystos[*yyssp], yyvsp, yylsp);
       YYPOPSTACK (1);
     }
 #ifndef yyoverflow
@@ -3355,8 +3355,8 @@ lloc_default (YYLTYPE const *rhs, int n)
   for (i = 1; i <= n; i++)
     if (! equal_boundaries (rhs[i].start, rhs[i].end))
       {
-	loc.start = rhs[i].start;
-	break;
+        loc.start = rhs[i].start;
+        break;
       }
 
   return loc;
@@ -3399,9 +3399,9 @@ add_param (param_type type, char *decl, location loc)
       size_t name_len;
 
       for (name_len = 1;
-	   memchr (alphanum, name_start[name_len], sizeof alphanum);
-	   name_len++)
-	continue;
+           memchr (alphanum, name_start[name_len], sizeof alphanum);
+           name_len++)
+        continue;
 
       name = xmalloc (name_len + 1);
       memcpy (name, name_start, name_len);
@@ -3423,7 +3423,7 @@ version_check (location const *loc, char const *version)
   if (strverscmp (version, PACKAGE_VERSION) > 0)
     {
       complain_at (*loc, "require bison %s, but have %s",
-		   version, PACKAGE_VERSION);
+                   version, PACKAGE_VERSION);
       exit (63);
     }
 }
