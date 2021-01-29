@@ -138,7 +138,7 @@ m4_changecom()
 m4_divert(0)dnl
 @output @output_parser_name@
 b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
-             [1984, 1989, 1990, 2000, 2001, 2002])
+             [1984, 1989, 1990, 2000, 2001, 2002])[
 
 /* As a special exception, when this file is copied by Bison into a
    Bison output file, you may use that output file without restriction.
@@ -155,7 +155,7 @@ b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
    define necessary library symbols; they are noted "INFRINGES ON
    USER NAME SPACE" below.  */
 
-b4_identification
+]b4_identification
 m4_if(b4_prefix[], [yy], [],
 [/* If NAME_PREFIX is specified substitute the variables and functions
    names.  */
@@ -166,16 +166,16 @@ m4_if(b4_prefix[], [yy], [],
 #define yychar  b4_prefix[]char
 #define yydebug b4_prefix[]debug
 #define yynerrs b4_prefix[]nerrs
-b4_location_if([#define yylloc b4_prefix[]lloc])])
+b4_location_if([#define yylloc b4_prefix[]lloc])])[
 
-b4_token_defines(b4_tokens)
+]b4_token_defines(b4_tokens)[
 
 /* Copy the first part of user declarations.  */
-b4_pre_prologue
+]b4_pre_prologue[
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
-# define YYDEBUG b4_debug
+# define YYDEBUG ]b4_debug[
 #endif
 
 /* Enabling verbose error messages.  */
@@ -183,16 +183,16 @@ b4_pre_prologue
 # undef YYERROR_VERBOSE
 # define YYERROR_VERBOSE 1
 #else
-# define YYERROR_VERBOSE b4_error_verbose
+# define YYERROR_VERBOSE ]b4_error_verbose[
 #endif
 
 #ifndef YYSTYPE
-m4_ifdef([b4_stype],
+]m4_ifdef([b4_stype],
 [b4_syncline([b4_stype_line], [b4_filename])
 typedef union b4_stype yystype;
 /* Line __line__ of __file__.  */
 b4_syncline([@oline@], [@ofile@])],
-[typedef int yystype;])
+[typedef int yystype;])[
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -205,15 +205,15 @@ typedef struct yyltype
   int last_line;
   int last_column;
 } yyltype;
-# define YYLTYPE b4_location_type
+# define YYLTYPE ]b4_location_type[
 # define YYLTYPE_IS_TRIVIAL 1
 #endif
 
 /* Copy the second part of user declarations.  */
-b4_post_prologue
+]b4_post_prologue[
 
 /* Line __line__ of __file__.  */
-b4_syncline([@oline@], [@ofile@])
+]b4_syncline([@oline@], [@ofile@])[
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -256,22 +256,22 @@ union yyalloc
 {
   short yyss;
   YYSTYPE yyvs;
-  b4_location_if([  YYLTYPE yyls;
+  ]b4_location_if([  YYLTYPE yyls;
 ])dnl
-};
+[};
 
 /* The size of the maximum gap between one aligned stack and the next.  */
 # define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)
 
 /* The size of an array large to enough to hold all stacks, each with
    N elements.  */
-b4_location_if(
+]b4_location_if(
 [# define YYSTACK_BYTES(N) \
      ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
       + 2 * YYSTACK_GAP_MAX)],
 [# define YYSTACK_BYTES(N) \
      ((N) * (sizeof (short) + sizeof (YYSTYPE))				\
-      + YYSTACK_GAP_MAX)])
+      + YYSTACK_GAP_MAX)])[
 
 /* Copy COUNT objects from FROM to TO.  The source and destination do
    not overlap.  */
@@ -285,7 +285,7 @@ b4_location_if(
 	{					\
 	  register YYSIZE_T yyi;		\
 	  for (yyi = 0; yyi < (Count); yyi++)	\
-	    (To)[[yyi]] = (From)[[yyi]];	\
+	    (To)[yyi] = (From)[yyi];		\
 	}					\
       while (0)
 #  endif
@@ -316,22 +316,22 @@ b4_location_if(
 #endif
 
 /* YYFINAL -- State number of the termination state. */
-#define YYFINAL  b4_final_state_number
+#define YYFINAL  ]b4_final_state_number[
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   b4_last
+#define YYLAST   ]b4_last[
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  b4_tokens_number
+#define YYNTOKENS  ]b4_tokens_number[
 /* YYNNTS -- Number of nonterminals. */
-#define YYNNTS  b4_nterms_number
+#define YYNNTS  ]b4_nterms_number[
 /* YYNRULES -- Number of rules. */
-#define YYNRULES  b4_rules_number
+#define YYNRULES  ]b4_rules_number[
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  b4_states_number
+#define YYNSTATES  ]b4_states_number[
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
-#define YYUNDEFTOK  b4_undef_token_number
-#define YYMAXUTOK   b4_user_token_number_max[
+#define YYUNDEFTOK  ]b4_undef_token_number[
+#define YYMAXUTOK   ]b4_user_token_number_max[
 
 #define YYTRANSLATE(YYX) 						\
   ((YYX <= 0) ? YYEOF :							\
@@ -441,7 +441,7 @@ static const b4_int_type_for([b4_check]) yycheck[[]] =
    symbol of state STATE-NUM.  */
 static const b4_int_type_for([b4_stos]) yystos[[]] =
 {
-  b4_stos
+  b4_stos[
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -489,7 +489,7 @@ do								\
     }								\
   else								\
     { 								\
-      yyerror (b4_yyerror_args"syntax error: cannot back up");	\
+      yyerror (]b4_yyerror_args["syntax error: cannot back up");\
       YYERROR;							\
     }								\
 while (0)
@@ -501,19 +501,19 @@ while (0)
    are run).  */
 
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)           \
-  Current.first_line   = Rhs[[1]].first_line;      \
-  Current.first_column = Rhs[[1]].first_column;    \
-  Current.last_line    = Rhs[[N]].last_line;       \
-  Current.last_column  = Rhs[[N]].last_column;
+# define YYLLOC_DEFAULT(Current, Rhs, N)         \
+  Current.first_line   = Rhs[1].first_line;      \
+  Current.first_column = Rhs[1].first_column;    \
+  Current.last_line    = Rhs[N].last_line;       \
+  Current.last_column  = Rhs[N].last_column;
 #endif
 
 /* YYLEX -- calling `yylex' with the right arguments.  */
 
 #ifdef YYLEX_PARAM
-# define YYLEX yylex (b4_pure_if([&yylval[]b4_location_if([, &yylloc]), ])YYLEX_PARAM)
+# define YYLEX yylex (]b4_pure_if([&yylval[]b4_location_if([, &yylloc]), ])[YYLEX_PARAM)
 #else
-# define YYLEX b4_c_function_call([yylex], [int], b4_lex_param)
+# define YYLEX ]b4_c_function_call([yylex], [int], b4_lex_param)[
 #endif
 
 /* Enable debugging if requested.  */
@@ -534,17 +534,29 @@ do {						\
   if (yydebug)					\
     yysymprint Args;				\
 } while (0)
+# define YYDSYMPRINTF(Title, Token, Value, Location)		\
+do {								\
+  if (yydebug)							\
+    {								\
+      YYFPRINTF (stderr, "%s ", Title);				\
+      yysymprint (stderr, 					\
+                  Token, Value]b4_location_if([, Location])[);	\
+      YYFPRINTF (stderr, "\n");					\
+    }								\
+} while (0)
+
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
 #else /* !YYDEBUG */
 # define YYDPRINTF(Args)
 # define YYDSYMPRINT(Args)
+# define YYDSYMPRINTF(Title, Token, Value, Location)
 #endif /* !YYDEBUG */
 
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
 #ifndef	YYINITDEPTH
-# define YYINITDEPTH b4_stack_depth_init
+# define YYINITDEPTH ]b4_stack_depth_init[
 #endif
 
 /* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
@@ -559,7 +571,7 @@ int yydebug;
 #endif
 
 #ifndef YYMAXDEPTH
-# define YYMAXDEPTH b4_stack_depth_max
+# define YYMAXDEPTH ]b4_stack_depth_max[
 #endif
 
 
@@ -620,9 +632,9 @@ yystpcpy (yydest, yysrc)
 
 
 #if YYDEBUG
-b4_yysymprint_generate([b4_c_function_def])
+]b4_yysymprint_generate([b4_c_function_def])[
 #endif /* YYDEBUG. */
-b4_yydestruct_generate([b4_c_function_def])
+]b4_yydestruct_generate([b4_c_function_def])
 
 
 /* Prevent warnings from -Wmissing-prototypes.  */
@@ -853,9 +865,7 @@ yybackup:
     {
       /* We have to keep this `#if YYDEBUG', since we use variables
 	 which are defined only if `YYDEBUG' is set.  */
-      YYDPRINTF ((stderr, "Next token is "));
-      YYDSYMPRINT ((stderr, yytoken, &yylval]b4_location_if([, &yyloc])[));
-      YYDPRINTF ((stderr, "\n"));
+      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
     }
 
   /* If the proper action on seeing token YYTOKEN is to reduce or to
@@ -876,8 +886,7 @@ yybackup:
     YYACCEPT;
 
   /* Shift the lookahead token.  */
-  YYDPRINTF ((stderr, "Shifting token %d (%s), ",
-	      yytoken, yytname[yytoken]));
+  YYDPRINTF ((stderr, "Shifting token %s, ", yytname[yytoken]));
 
   /* Discard the token being shifted unless it is eof.  */
   if (yytoken != YYEOF)
@@ -933,13 +942,13 @@ yyreduce:
     {
       int yyi;
 
-      YYFPRINTF (stderr, "Reducing via rule %d (line %d), ",
+      YYFPRINTF (stderr, "Reducing by rule %d (line %d), ",
 		 yyn - 1, yyrline[yyn]);
 
       /* Print the symbols being reduced, and their result.  */
       for (yyi = yyprhs[yyn]; 0 <= yyrhs[yyi]; yyi++)
 	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
-      YYFPRINTF (stderr, " -> %s\n", yytname[yyr1[yyn]]);
+      YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyn]]);
     }
 #endif
   switch (yyn)
@@ -1060,19 +1069,14 @@ yyerrlab1:
 	  /* Pop the rest of the stack.  */
 	  while (yyss < yyssp)
 	    {
-	      YYDPRINTF ((stderr, "Error: popping "));
-	      YYDSYMPRINT ((stderr,
-			    yystos[*yyssp],
-			    yyvsp]b4_location_if([, yylsp])[));
-	      YYDPRINTF ((stderr, "\n"));
+	      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
 	      yydestruct (yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
 	      YYPOPSTACK;
 	    }
 	  YYABORT;
         }
 
-      YYDPRINTF ((stderr, "Discarding token %d (%s).\n",
-		  yytoken, yytname[yytoken]));
+      YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
       yydestruct (yytoken, &yylval]b4_location_if([, &yylloc])[);
       yytoken = YYEMPTY;
     }
@@ -1100,11 +1104,7 @@ yyerrlab1:
       if (yyssp == yyss)
 	YYABORT;
 
-      YYDPRINTF ((stderr, "Error: popping "));
-      YYDSYMPRINT ((stderr,
-		    yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[));
-      YYDPRINTF ((stderr, "\n"));
-
+      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
       yydestruct (yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
       yyvsp--;
       yystate = *--yyssp;
