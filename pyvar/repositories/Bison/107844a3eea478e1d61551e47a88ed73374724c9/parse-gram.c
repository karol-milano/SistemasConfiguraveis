@@ -73,7 +73,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 262 of yacc.c  */
+/* Line 269 of yacc.c  */
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -128,7 +128,7 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/* Line 262 of yacc.c  */
+/* Line 269 of yacc.c  */
 #line 133 "src/parse-gram.c"
 
 /* Enabling traces.  */
@@ -150,8 +150,8 @@ static char const *char_name (char);
 #endif
 
 /* "%code requires" blocks.  */
-/* Line 282 of yacc.c  */
-#line 202 "src/parse-gram.y"
+/* Line 289 of yacc.c  */
+#line 203 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
 #  define PARAM_TYPE
@@ -165,7 +165,7 @@ static char const *char_name (char);
 # endif
 
 
-/* Line 282 of yacc.c  */
+/* Line 289 of yacc.c  */
 #line 170 "src/parse-gram.c"
 
 /* Tokens.  */
@@ -294,8 +294,8 @@ static char const *char_name (char);
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 287 of yacc.c  */
-#line 88 "src/parse-gram.y"
+/* Line 294 of yacc.c  */
+#line 89 "src/parse-gram.y"
 
   assoc assoc;
   char *code;
@@ -307,13 +307,13 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 
-/* Line 287 of yacc.c  */
-#line 226 "src/parse-gram.y"
+/* Line 294 of yacc.c  */
+#line 227 "src/parse-gram.y"
 
   param_type param;
 
 
-/* Line 287 of yacc.c  */
+/* Line 294 of yacc.c  */
 #line 318 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -337,10 +337,10 @@ typedef struct YYLTYPE
 
 /* Copy the second part of user declarations.  */
 
-/* Line 337 of yacc.c  */
+/* Line 344 of yacc.c  */
 #line 342 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
-/* Line 338 of yacc.c  */
+/* Line 345 of yacc.c  */
 #line 56 "src/parse-gram.y"
 
   static int current_prec = 0;
@@ -355,8 +355,8 @@ typedef struct YYLTYPE
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 338 of yacc.c  */
-#line 215 "src/parse-gram.y"
+/* Line 345 of yacc.c  */
+#line 216 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -368,7 +368,7 @@ typedef struct YYLTYPE
   static param_type current_param = param_none;
 
 
-/* Line 338 of yacc.c  */
+/* Line 345 of yacc.c  */
 #line 373 "src/parse-gram.c"
 
 #ifdef short
@@ -455,34 +455,10 @@ YYID (yyi)
 }
 #endif
 
-#if ! defined yyoverflow || YYERROR_VERBOSE
+#if 1
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
 
-# ifdef YYSTACK_USE_ALLOCA
-#  if YYSTACK_USE_ALLOCA
-#   ifdef __GNUC__
-#    define YYSTACK_ALLOC __builtin_alloca
-#   elif defined __BUILTIN_VA_ARG_INCR
-#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
-#   elif defined _AIX
-#    define YYSTACK_ALLOC __alloca
-#   elif defined _MSC_VER
-#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
-#    define alloca _alloca
-#   else
-#    define YYSTACK_ALLOC alloca
-#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
-     || defined __cplusplus || defined _MSC_VER)
-#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
-#     ifndef EXIT_SUCCESS
-#      define EXIT_SUCCESS 0
-#     endif
-#    endif
-#   endif
-#  endif
-# endif
-
 # ifdef YYSTACK_ALLOC
    /* Pacify GCC's `empty if-body' warning.  */
 #  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
@@ -522,7 +498,8 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
 # endif
-#endif /* ! defined yyoverflow || YYERROR_VERBOSE */
+# define YYCOPY_NEEDED 1
+#endif
 
 
 #if (! defined yyoverflow \
@@ -547,23 +524,7 @@ union yyalloc
      ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
       + 2 * YYSTACK_GAP_MAXIMUM)
 
-/* Copy COUNT objects from FROM to TO.  The source and destination do
-   not overlap.  */
-# ifndef YYCOPY
-#  if defined __GNUC__ && 1 < __GNUC__
-#   define YYCOPY(To, From, Count) \
-      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
-#  else
-#   define YYCOPY(To, From, Count)		\
-      do					\
-	{					\
-	  YYSIZE_T yyi;				\
-	  for (yyi = 0; yyi < (Count); yyi++)	\
-	    (To)[yyi] = (From)[yyi];		\
-	}					\
-      while (YYID (0))
-#  endif
-# endif
+# define YYCOPY_NEEDED 1
 
 /* Relocate STACK from its old location to the new one.  The
    local variables YYSIZE and YYSTACKSIZE give the old and new number of
@@ -583,6 +544,26 @@ union yyalloc
 
 #endif
 
+#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
+/* Copy COUNT objects from FROM to TO.  The source and destination do
+   not overlap.  */
+# ifndef YYCOPY
+#  if defined __GNUC__ && 1 < __GNUC__
+#   define YYCOPY(To, From, Count) \
+      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
+#  else
+#   define YYCOPY(To, From, Count)		\
+      do					\
+	{					\
+	  YYSIZE_T yyi;				\
+	  for (yyi = 0; yyi < (Count); yyi++)	\
+	    (To)[yyi] = (From)[yyi];		\
+	}					\
+      while (YYID (0))
+#  endif
+# endif
+#endif /* !YYCOPY_NEEDED */
+
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
@@ -647,18 +628,18 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
 static const yytype_uint16 yyrline[] =
 {
-       0,   251,   251,   259,   261,   265,   266,   276,   280,   285,
-     286,   291,   296,   297,   298,   299,   300,   305,   314,   315,
-     316,   317,   318,   319,   320,   321,   321,   322,   323,   347,
-     348,   349,   350,   354,   355,   364,   365,   366,   370,   377,
-     384,   388,   392,   399,   414,   415,   419,   431,   431,   436,
-     436,   441,   452,   467,   468,   469,   470,   474,   475,   480,
-     482,   487,   488,   493,   495,   500,   501,   505,   506,   507,
-     508,   513,   518,   523,   529,   535,   546,   547,   556,   557,
-     563,   564,   565,   572,   572,   577,   578,   579,   584,   586,
-     588,   590,   592,   594,   596,   601,   603,   613,   614,   619,
-     620,   621,   630,   650,   652,   661,   666,   667,   672,   679,
-     681
+       0,   252,   252,   260,   262,   266,   267,   277,   281,   286,
+     287,   292,   297,   298,   299,   300,   301,   306,   315,   316,
+     317,   318,   319,   320,   321,   322,   322,   323,   324,   348,
+     349,   350,   351,   355,   356,   365,   366,   367,   371,   378,
+     385,   389,   393,   400,   415,   416,   420,   432,   432,   437,
+     437,   442,   453,   468,   469,   470,   471,   475,   476,   481,
+     483,   488,   489,   494,   496,   501,   502,   506,   507,   508,
+     509,   514,   519,   524,   530,   536,   547,   548,   557,   558,
+     564,   565,   566,   573,   573,   578,   579,   580,   585,   587,
+     589,   591,   593,   595,   597,   602,   604,   614,   615,   620,
+     621,   622,   631,   651,   653,   662,   667,   668,   673,   680,
+     682
 };
 #endif
 
@@ -912,6 +893,7 @@ do								\
       yychar = (Token);						\
       yylval = (Value);						\
       YYPOPSTACK (1);						\
+      YY_LAC_DISCARD ("YYBACKUP");				\
       goto yybackup;						\
     }								\
   else								\
@@ -1033,107 +1015,107 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
             case 3: // "string"
 
-/* Line 740 of yacc.c  */
-#line 175 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 176 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
-/* Line 740 of yacc.c  */
-#line 1041 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1023 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
-/* Line 740 of yacc.c  */
-#line 188 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 189 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
-/* Line 740 of yacc.c  */
-#line 1050 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1032 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
-/* Line 740 of yacc.c  */
-#line 184 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 185 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 740 of yacc.c  */
-#line 1059 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1041 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
 
-/* Line 740 of yacc.c  */
-#line 177 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 178 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 740 of yacc.c  */
-#line 1068 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1050 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
 
-/* Line 740 of yacc.c  */
-#line 182 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 183 "src/parse-gram.y"
         { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 740 of yacc.c  */
-#line 1077 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1059 "src/parse-gram.c"
         break;
 
             case 43: // "char"
 
-/* Line 740 of yacc.c  */
-#line 169 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 170 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
-/* Line 740 of yacc.c  */
-#line 1086 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1068 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
 
-/* Line 740 of yacc.c  */
-#line 177 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 178 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 740 of yacc.c  */
-#line 1095 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1077 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
 
-/* Line 740 of yacc.c  */
-#line 181 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 182 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 740 of yacc.c  */
-#line 1104 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1086 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
 
-/* Line 740 of yacc.c  */
-#line 183 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 184 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 740 of yacc.c  */
-#line 1113 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1095 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
 
-/* Line 740 of yacc.c  */
-#line 177 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 178 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 740 of yacc.c  */
-#line 1122 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1104 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
 
-/* Line 740 of yacc.c  */
-#line 185 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 186 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 740 of yacc.c  */
-#line 1131 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1113 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
 
-/* Line 740 of yacc.c  */
-#line 231 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 232 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
     {
@@ -1146,80 +1128,80 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case param_none: aver (false); break;
     }
 }
-/* Line 740 of yacc.c  */
-#line 1151 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1133 "src/parse-gram.c"
         break;
 
             case 72: // symbol.prec
 
-/* Line 740 of yacc.c  */
-#line 191 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 740 of yacc.c  */
-#line 1160 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1142 "src/parse-gram.c"
         break;
 
             case 85: // variable
 
-/* Line 740 of yacc.c  */
-#line 181 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 182 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 740 of yacc.c  */
-#line 1169 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1151 "src/parse-gram.c"
         break;
 
             case 86: // content.opt
 
-/* Line 740 of yacc.c  */
-#line 177 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 178 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 740 of yacc.c  */
-#line 1178 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1160 "src/parse-gram.c"
         break;
 
             case 87: // braceless
 
-/* Line 740 of yacc.c  */
-#line 177 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 178 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 740 of yacc.c  */
-#line 1187 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1169 "src/parse-gram.c"
         break;
 
             case 88: // id
 
-/* Line 740 of yacc.c  */
-#line 191 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 740 of yacc.c  */
-#line 1196 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1178 "src/parse-gram.c"
         break;
 
             case 89: // id_colon
 
-/* Line 740 of yacc.c  */
-#line 192 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 193 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 740 of yacc.c  */
-#line 1205 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1187 "src/parse-gram.c"
         break;
 
             case 90: // symbol
 
-/* Line 740 of yacc.c  */
-#line 191 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 740 of yacc.c  */
-#line 1214 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1196 "src/parse-gram.c"
         break;
 
             case 91: // string_as_id
 
-/* Line 740 of yacc.c  */
-#line 191 "src/parse-gram.y"
+/* Line 751 of yacc.c  */
+#line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 740 of yacc.c  */
-#line 1223 "src/parse-gram.c"
+/* Line 751 of yacc.c  */
+#line 1205 "src/parse-gram.c"
         break;
 
       default:
@@ -1355,6 +1337,239 @@ int yydebug;
 # define YYMAXDEPTH 10000
 #endif
 
+/* Given a state stack such that *YYBOTTOM is its bottom, such that
+   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
+   stack, and such that *YYCAPACITY is the maximum number of elements it
+   can hold without a reallocation, make sure there is enough room to
+   store YYADD more elements.  If not, allocate a new stack using
+   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
+   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
+   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
+   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
+   required.  Return 1 if memory is exhausted.  */
+static int
+yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
+#if YYDEBUG
+                      char const *yydebug_prefix,
+                      char const *yydebug_suffix,
+#endif
+                      yytype_int16 **yybottom,
+                      yytype_int16 *yybottom_no_free,
+                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
+{
+  YYSIZE_T yysize_old =
+    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
+  YYSIZE_T yysize_new = yysize_old + yyadd;
+  if (*yycapacity < yysize_new)
+    {
+      YYSIZE_T yyalloc = 2 * yysize_new;
+      yytype_int16 *yybottom_new;
+      /* Use YYMAXDEPTH for maximum stack size given that the stack
+         should never need to grow larger than the main state stack
+         needs to grow without LAC.  */
+      if (YYMAXDEPTH < yysize_new)
+        {
+          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
+                      yydebug_suffix));
+          return 1;
+        }
+      if (YYMAXDEPTH < yyalloc)
+        yyalloc = YYMAXDEPTH;
+      yybottom_new =
+        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
+      if (!yybottom_new)
+        {
+          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
+                      yydebug_suffix));
+          return 1;
+        }
+      if (*yytop != yytop_empty)
+        {
+          YYCOPY (yybottom_new, *yybottom, yysize_old);
+          *yytop = yybottom_new + (yysize_old - 1);
+        }
+      if (*yybottom != yybottom_no_free)
+        YYSTACK_FREE (*yybottom);
+      *yybottom = yybottom_new;
+      *yycapacity = yyalloc;
+    }
+  return 0;
+}
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
+#define YY_LAC_ESTABLISH                                         \
+do {                                                             \
+  if (!yy_lac_established)                                       \
+    {                                                            \
+      YYDPRINTF ((stderr,                                        \
+                  "LAC: initial context established for %s\n",   \
+                  yytname[yytoken]));                            \
+      yy_lac_established = 1;                                    \
+      {                                                          \
+        int yy_lac_status =                                      \
+          yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken); \
+        if (yy_lac_status == 2)                                  \
+          goto yyexhaustedlab;                                   \
+        if (yy_lac_status == 1)                                  \
+          goto yyerrlab;                                         \
+      }                                                          \
+    }                                                            \
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
+#endif
+
+/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
+   eventually (after perhaps some reductions) be shifted, return 1 if
+   not, or return 2 if memory is exhausted.  As preconditions and
+   postconditions: *YYES_CAPACITY is the allocated size of the array to
+   which *YYES points, and either *YYES = YYESA or *YYES points to an
+   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
+   contents of either array, alter *YYES and *YYES_CAPACITY, and free
+   any old *YYES other than YYESA.  */
+static int
+yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
+        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
+{
+  yytype_int16 *yyes_prev = yyssp;
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
+            YYSIZE_T yysize = yyesp - *yyes + 1;
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
+            yyesp = *yyes;
+            *yyesp = yystate;
+          }
+        else
+          {
+            if (yy_lac_stack_realloc (yyes_capacity, 1,
+#if YYDEBUG
+                                      " (", ")",
+#endif
+                                      yyes, yyesa, &yyesp, yyes_prev))
+              {
+                YYDPRINTF ((stderr, "\n"));
+                return 2;
+              }
+            *++yyesp = yystate;
+          }
+        YYDPRINTF ((stderr, " G%d", *yyesp));
+      }
+    }
+}
+
 
 #if YYERROR_VERBOSE
 
@@ -1459,15 +1674,18 @@ yytnamerr (char *yyres, const char *yystr)
 
 /* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
    about the unexpected token YYTOKEN for the state stack whose top is
-   YYSSP.
+   YYSSP.  In order to see if a particular token T is a
+   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).
 
    Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
    not large enough to hold the message.  In that case, also set
    *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
-   required number of bytes is too large to store.  */
+   required number of bytes is too large to store or if
+   yy_lac returned 2.  */
 static int
 yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
-                yytype_int16 *yyssp, int yytoken)
+                yytype_int16 *yyesa, yytype_int16 **yyes,
+                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
 {
   YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
@@ -1499,34 +1717,32 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
        consistent state with a default action.  There might have been a
        previous inconsistent state, consistent state with a non-default
        action, or user semantic action that manipulated yychar.
-     - Of course, the expected token list depends on states to have
-       correct lookahead information, and it depends on the parser not
-       to perform extra reductions after fetching a lookahead from the
-       scanner and before detecting a syntax error.  Thus, state merging
-       (from LALR or IELR) and default reductions corrupt the expected
-       token list.  However, the list is correct for canonical LR with
-       one exception: it will still contain any token that will not be
-       accepted due to an error action in a later state.
+       In the first two cases, it might appear that the current syntax
+       error should have been detected in the previous state when yy_lac
+       was invoked.  However, at that time, there might have been a
+       different syntax error that discarded a different initial context
+       during error recovery, leaving behind the current lookahead.
   */
   if (yytoken != YYEMPTY)
     {
       int yyn = yypact[*yyssp];
+      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
       yyarg[yycount++] = yytname[yytoken];
       if (!yypact_value_is_default (yyn))
         {
-          /* Start YYX at -YYN if negative to avoid negative indexes in
-             YYCHECK.  In other words, skip the first -YYN actions for
-             this state because they are default actions.  */
-          int yyxbegin = yyn < 0 ? -yyn : 0;
-          /* Stay within bounds of both yycheck and yytname.  */
-          int yychecklim = YYLAST - yyn + 1;
-          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
           int yyx;
 
-          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
-                && !yytable_value_is_error (yytable[yyx + yyn]))
+          for (yyx = 0; yyx < YYNTOKENS; ++yyx)
+            if (yyx != YYTERROR && yyx != YYUNDEFTOK)
               {
+                {
+                  int yy_lac_status = yy_lac (yyesa, yyes, yyes_capacity,
+                                              yyssp, yyx);
+                  if (yy_lac_status == 2)
+                    return 2;
+                  if (yy_lac_status == 1)
+                    continue;
+                }
                 if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                   {
                     yycount = 1;
@@ -1541,6 +1757,10 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 yysize = yysize1;
               }
         }
+# if YYDEBUG
+      else if (yydebug)
+        YYFPRINTF (stderr, "No expected tokens.\n");
+# endif
     }
 
   switch (yycount)
@@ -1715,6 +1935,11 @@ YYLTYPE yylloc;
 
     YYSIZE_T yystacksize;
 
+    yytype_int16 yyesa[20];
+    yytype_int16 *yyes;
+    YYSIZE_T yyes_capacity;
+
+  int yy_lac_established = 0;
   int yyn;
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
@@ -1743,6 +1968,11 @@ YYLTYPE yylloc;
   yyls = yylsa;
   yystacksize = YYINITDEPTH;
 
+  yyes = yyesa;
+  yyes_capacity = sizeof yyesa / sizeof *yyes;
+  if (YYMAXDEPTH < yyes_capacity)
+    yyes_capacity = YYMAXDEPTH;
+
   YYDPRINTF ((stderr, "Starting parse\n"));
 
   yystate = 0;
@@ -1765,16 +1995,16 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1430 of yacc.c  */
-#line 80 "src/parse-gram.y"
+/* Line 1525 of yacc.c  */
+#line 81 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1430 of yacc.c  */
-#line 1778 "src/parse-gram.c"
+/* Line 1525 of yacc.c  */
+#line 2008 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1900,12 +2130,16 @@ yybackup:
      detect an error, take that action.  */
   yyn += yytoken;
   if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
-    goto yydefault;
+    {
+      YY_LAC_ESTABLISH;
+      goto yydefault;
+    }
   yyn = yytable[yyn];
   if (yyn <= 0)
     {
       if (yytable_value_is_error (yyn))
         goto yyerrlab;
+      YY_LAC_ESTABLISH;
       yyn = -yyn;
       goto yyreduce;
     }
@@ -1920,6 +2154,7 @@ yybackup:
 
   /* Discard the shifted token.  */
   yychar = YYEMPTY;
+  YY_LAC_DISCARD ("shift");
 
   yystate = yyn;
   *++yyvsp = yylval;
@@ -1957,11 +2192,13 @@ yyreduce:
   /* Default location.  */
   YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
   YY_REDUCE_PRINT (yyn);
-  switch (yyn)
-    {
-        case 6:
-/* Line 1646 of yacc.c  */
-#line 267 "src/parse-gram.y"
+  {
+    int yychar_backup = yychar;
+    switch (yyn)
+      {
+          case 6:
+/* Line 1741 of yacc.c  */
+#line 268 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -1971,107 +2208,107 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1646 of yacc.c  */
-#line 1976 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2213 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1646 of yacc.c  */
-#line 277 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 278 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1646 of yacc.c  */
-#line 1986 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2223 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1646 of yacc.c  */
-#line 281 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 282 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1646 of yacc.c  */
-#line 1997 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2234 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1646 of yacc.c  */
-#line 285 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 286 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1646 of yacc.c  */
-#line 2005 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2242 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1646 of yacc.c  */
-#line 287 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 288 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1646 of yacc.c  */
-#line 2016 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2253 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1646 of yacc.c  */
-#line 292 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 293 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1646 of yacc.c  */
-#line 2027 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2264 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1646 of yacc.c  */
-#line 296 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 297 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1646 of yacc.c  */
-#line 2035 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2272 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1646 of yacc.c  */
-#line 297 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 298 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1646 of yacc.c  */
-#line 2043 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2280 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1646 of yacc.c  */
-#line 298 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 299 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1646 of yacc.c  */
-#line 2051 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2288 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1646 of yacc.c  */
-#line 299 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 300 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1646 of yacc.c  */
-#line 2059 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2296 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1646 of yacc.c  */
-#line 301 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 302 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1646 of yacc.c  */
-#line 2070 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2307 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1646 of yacc.c  */
-#line 306 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 307 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2080,93 +2317,93 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1646 of yacc.c  */
-#line 2085 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2322 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1646 of yacc.c  */
-#line 314 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 315 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1646 of yacc.c  */
-#line 2093 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2330 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1646 of yacc.c  */
-#line 315 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 316 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1646 of yacc.c  */
-#line 2101 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2338 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1646 of yacc.c  */
-#line 316 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 317 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1646 of yacc.c  */
-#line 2109 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2346 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1646 of yacc.c  */
-#line 317 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 318 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1646 of yacc.c  */
-#line 2117 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2354 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1646 of yacc.c  */
-#line 318 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 319 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1646 of yacc.c  */
-#line 2125 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2362 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1646 of yacc.c  */
-#line 319 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 320 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1646 of yacc.c  */
-#line 2133 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2370 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1646 of yacc.c  */
-#line 320 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 321 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1646 of yacc.c  */
-#line 2141 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2378 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1646 of yacc.c  */
-#line 321 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 322 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1646 of yacc.c  */
-#line 2149 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2386 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1646 of yacc.c  */
-#line 321 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 322 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1646 of yacc.c  */
-#line 2157 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2394 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1646 of yacc.c  */
-#line 322 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 323 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1646 of yacc.c  */
-#line 2165 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2402 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1646 of yacc.c  */
-#line 324 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 325 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2190,199 +2427,199 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1646 of yacc.c  */
-#line 2195 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2432 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1646 of yacc.c  */
-#line 347 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 348 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1646 of yacc.c  */
-#line 2203 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2440 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1646 of yacc.c  */
-#line 348 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 349 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1646 of yacc.c  */
-#line 2211 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2448 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1646 of yacc.c  */
-#line 349 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 350 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1646 of yacc.c  */
-#line 2219 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2456 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1646 of yacc.c  */
-#line 354 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 355 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2227 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2464 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1646 of yacc.c  */
-#line 355 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 356 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2235 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2472 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1646 of yacc.c  */
-#line 367 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 368 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1646 of yacc.c  */
-#line 2245 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2482 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1646 of yacc.c  */
-#line 371 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 372 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
 	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1646 of yacc.c  */
-#line 2258 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2495 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1646 of yacc.c  */
-#line 378 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 379 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
 	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1646 of yacc.c  */
-#line 2271 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2508 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1646 of yacc.c  */
-#line 385 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 386 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1646 of yacc.c  */
-#line 2281 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2518 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1646 of yacc.c  */
-#line 389 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 390 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1646 of yacc.c  */
-#line 2291 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2528 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1646 of yacc.c  */
-#line 393 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 394 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1646 of yacc.c  */
-#line 2304 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2541 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1646 of yacc.c  */
-#line 400 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 401 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1646 of yacc.c  */
-#line 2315 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2552 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1646 of yacc.c  */
-#line 414 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 415 "src/parse-gram.y"
     {}
-/* Line 1646 of yacc.c  */
-#line 2323 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2560 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1646 of yacc.c  */
-#line 415 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 416 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2331 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2568 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1646 of yacc.c  */
-#line 420 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 421 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1646 of yacc.c  */
-#line 2343 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2580 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1646 of yacc.c  */
-#line 431 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 432 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1646 of yacc.c  */
-#line 2351 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2588 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1646 of yacc.c  */
-#line 432 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 433 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1646 of yacc.c  */
-#line 2362 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2599 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1646 of yacc.c  */
-#line 436 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 437 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1646 of yacc.c  */
-#line 2370 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2607 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1646 of yacc.c  */
-#line 437 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 438 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1646 of yacc.c  */
-#line 2381 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2618 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1646 of yacc.c  */
-#line 442 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 443 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2390,13 +2627,13 @@ yyreduce:
 	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1646 of yacc.c  */
-#line 2395 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2632 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1646 of yacc.c  */
-#line 453 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 454 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2408,348 +2645,348 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1646 of yacc.c  */
-#line 2413 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2650 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1646 of yacc.c  */
-#line 467 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 468 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1646 of yacc.c  */
-#line 2421 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2658 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1646 of yacc.c  */
-#line 468 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 469 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1646 of yacc.c  */
-#line 2429 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2666 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1646 of yacc.c  */
-#line 469 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 470 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1646 of yacc.c  */
-#line 2437 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2674 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1646 of yacc.c  */
-#line 470 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 471 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1646 of yacc.c  */
-#line 2445 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2682 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1646 of yacc.c  */
-#line 474 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 475 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1646 of yacc.c  */
-#line 2453 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2690 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1646 of yacc.c  */
-#line 475 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 476 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1646 of yacc.c  */
-#line 2461 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2698 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1646 of yacc.c  */
-#line 481 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 482 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2469 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2706 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1646 of yacc.c  */
-#line 483 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 484 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1646 of yacc.c  */
-#line 2477 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2714 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1646 of yacc.c  */
-#line 487 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 488 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1646 of yacc.c  */
-#line 2485 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2722 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1646 of yacc.c  */
-#line 488 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 489 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2493 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2730 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1646 of yacc.c  */
-#line 494 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 495 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2501 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2738 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1646 of yacc.c  */
-#line 496 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 497 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1646 of yacc.c  */
-#line 2509 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2746 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1646 of yacc.c  */
-#line 500 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 501 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1646 of yacc.c  */
-#line 2517 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2754 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1646 of yacc.c  */
-#line 501 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 502 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1646 of yacc.c  */
-#line 2525 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2762 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1646 of yacc.c  */
-#line 505 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2533 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2770 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1646 of yacc.c  */
-#line 506 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 507 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2541 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2778 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1646 of yacc.c  */
-#line 507 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 508 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2549 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2786 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1646 of yacc.c  */
-#line 508 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 509 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2557 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2794 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1646 of yacc.c  */
-#line 514 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 515 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1646 of yacc.c  */
-#line 2568 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2805 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1646 of yacc.c  */
-#line 519 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 520 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1646 of yacc.c  */
-#line 2579 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2816 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1646 of yacc.c  */
-#line 524 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 525 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1646 of yacc.c  */
-#line 2591 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2828 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1646 of yacc.c  */
-#line 530 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 531 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1646 of yacc.c  */
-#line 2603 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2840 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1646 of yacc.c  */
-#line 536 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 537 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1646 of yacc.c  */
-#line 2616 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2853 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1646 of yacc.c  */
-#line 566 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 567 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1646 of yacc.c  */
-#line 2626 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2863 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1646 of yacc.c  */
-#line 572 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 573 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
-/* Line 1646 of yacc.c  */
-#line 2635 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2872 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1646 of yacc.c  */
-#line 577 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 578 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2643 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2880 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1646 of yacc.c  */
-#line 578 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 579 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2651 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2888 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1646 of yacc.c  */
-#line 584 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 585 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
-/* Line 1646 of yacc.c  */
-#line 2660 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2897 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1646 of yacc.c  */
-#line 587 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 588 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1646 of yacc.c  */
-#line 2668 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2905 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1646 of yacc.c  */
-#line 589 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 590 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1646 of yacc.c  */
-#line 2676 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2913 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1646 of yacc.c  */
-#line 591 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 592 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1646 of yacc.c  */
-#line 2684 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2921 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1646 of yacc.c  */
-#line 593 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 594 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2692 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2929 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1646 of yacc.c  */
-#line 595 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 596 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2700 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2937 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1646 of yacc.c  */
-#line 597 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 598 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2708 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2945 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1646 of yacc.c  */
-#line 601 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 602 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1646 of yacc.c  */
-#line 2716 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2953 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1646 of yacc.c  */
-#line 603 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 604 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2724 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2961 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1646 of yacc.c  */
-#line 614 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 615 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1646 of yacc.c  */
-#line 2732 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2969 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1646 of yacc.c  */
-#line 619 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 620 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1646 of yacc.c  */
-#line 2740 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2977 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1646 of yacc.c  */
-#line 620 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 621 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1646 of yacc.c  */
-#line 2748 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2985 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1646 of yacc.c  */
-#line 631 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 632 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2758,52 +2995,52 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1646 of yacc.c  */
-#line 2763 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3000 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1646 of yacc.c  */
-#line 651 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 652 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2771 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3008 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1646 of yacc.c  */
-#line 653 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 654 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1646 of yacc.c  */
-#line 2783 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3020 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1646 of yacc.c  */
-#line 661 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 662 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1646 of yacc.c  */
-#line 2791 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3028 "src/parse-gram.c"
     break;
 
   case 108:
-/* Line 1646 of yacc.c  */
-#line 673 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 674 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1646 of yacc.c  */
-#line 2802 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3039 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1646 of yacc.c  */
-#line 682 "src/parse-gram.y"
+/* Line 1741 of yacc.c  */
+#line 683 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2812,15 +3049,18 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1646 of yacc.c  */
-#line 2817 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3054 "src/parse-gram.c"
     break;
 
 
-/* Line 1646 of yacc.c  */
-#line 2822 "src/parse-gram.c"
-      default: break;
-    }
+/* Line 1741 of yacc.c  */
+#line 3059 "src/parse-gram.c"
+        default: break;
+      }
+    if (yychar_backup != yychar)
+      YY_LAC_DISCARD ("yychar change");
+  }
   /* User semantic actions sometimes alter yychar, and that requires
      that yytoken be updated with the new translation.  We take the
      approach of translating immediately before every use of yytoken.
@@ -2871,11 +3111,14 @@ yyerrlab:
 #if ! YYERROR_VERBOSE
       yyerror (YY_("syntax error"));
 #else
-# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, yyssp, \
-                                        yytoken)
+# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
+                                        yyesa, &yyes, &yyes_capacity, \
+                                        yyssp, yytoken)
       {
         char const *yymsgp = YY_("syntax error");
         int yysyntax_error_status;
+        if (yychar != YYEMPTY)
+          YY_LAC_ESTABLISH;
         yysyntax_error_status = YYSYNTAX_ERROR;
         if (yysyntax_error_status == 0)
           yymsgp = yymsg;
@@ -2983,6 +3226,10 @@ yyerrlab1:
       YY_STACK_PRINT (yyss, yyssp);
     }
 
+  /* If the stack popping above didn't lose the initial context for the
+     current lookahead token, the shift below will for sure.  */
+  YY_LAC_DISCARD ("error recovery");
+
   *++yyvsp = yylval;
 
   yyerror_range[2] = yylloc;
@@ -3012,7 +3259,7 @@ yyabortlab:
   yyresult = 1;
   goto yyreturn;
 
-#if !defined(yyoverflow) || YYERROR_VERBOSE
+#if 1
 /*-------------------------------------------------.
 | yyexhaustedlab -- memory exhaustion comes here.  |
 `-------------------------------------------------*/
@@ -3045,6 +3292,8 @@ yyreturn:
   if (yyss != yyssa)
     YYSTACK_FREE (yyss);
 #endif
+  if (yyes != yyesa)
+    YYSTACK_FREE (yyes);
 #if YYERROR_VERBOSE
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
@@ -3053,8 +3302,8 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1903 of yacc.c  */
-#line 692 "src/parse-gram.y"
+/* Line 2001 of yacc.c  */
+#line 693 "src/parse-gram.y"
 
 
 
