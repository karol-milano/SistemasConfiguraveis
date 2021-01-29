@@ -74,7 +74,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 261 of yacc.c  */
+/* Line 268 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -151,7 +151,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 261 of yacc.c  */
+/* Line 268 of yacc.c  */
 #line 156 "parse-gram.c"
 
 /* Enabling traces.  */
@@ -302,8 +302,8 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 286 of yacc.c  */
-#line 94 "parse-gram.y"
+/* Line 293 of yacc.c  */
+#line 95 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -317,7 +317,7 @@ typedef union YYSTYPE
 
 
 
-/* Line 286 of yacc.c  */
+/* Line 293 of yacc.c  */
 #line 322 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -342,7 +342,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 336 of yacc.c  */
+/* Line 343 of yacc.c  */
 #line 347 "parse-gram.c"
 
 #ifdef short
@@ -429,34 +429,10 @@ YYID (yyi)
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
@@ -496,7 +472,8 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 #   endif
 #  endif
 # endif
-#endif /* ! defined yyoverflow || YYERROR_VERBOSE */
+# define YYCOPY_NEEDED 1
+#endif
 
 
 #if (! defined yyoverflow \
@@ -521,23 +498,7 @@ union yyalloc
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
@@ -557,6 +518,26 @@ union yyalloc
 
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
@@ -669,17 +650,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   209,   209,   217,   219,   223,   224,   234,   235,   240,
-     241,   246,   247,   248,   249,   250,   251,   256,   265,   266,
-     267,   268,   269,   270,   271,   272,   273,   274,   275,   290,
-     291,   315,   316,   317,   318,   322,   323,   324,   328,   335,
-     342,   346,   350,   357,   372,   373,   377,   389,   389,   394,
-     394,   399,   410,   425,   426,   427,   431,   432,   437,   439,
-     444,   445,   450,   452,   457,   458,   462,   463,   464,   465,
-     470,   475,   480,   486,   492,   503,   504,   513,   514,   520,
-     521,   522,   529,   529,   534,   535,   536,   541,   543,   545,
-     547,   549,   551,   556,   558,   569,   570,   575,   576,   577,
-     586,   606,   608,   617,   622,   623,   628,   635,   637
+       0,   210,   210,   218,   220,   224,   225,   235,   236,   241,
+     242,   247,   248,   249,   250,   251,   252,   257,   266,   267,
+     268,   269,   270,   271,   272,   273,   274,   275,   276,   291,
+     292,   316,   317,   318,   319,   323,   324,   325,   329,   336,
+     343,   347,   351,   358,   373,   374,   378,   390,   390,   395,
+     395,   400,   411,   426,   427,   428,   432,   433,   438,   440,
+     445,   446,   451,   453,   458,   459,   463,   464,   465,   466,
+     471,   476,   481,   487,   493,   504,   505,   514,   515,   521,
+     522,   523,   530,   530,   535,   536,   537,   542,   544,   546,
+     548,   550,   552,   557,   559,   570,   571,   576,   577,   578,
+     587,   607,   609,   618,   623,   624,   629,   636,   638
 };
 #endif
 
@@ -928,6 +909,7 @@ do								\
       yychar = (Token);						\
       yylval = (Value);						\
       YYPOPSTACK (1);						\
+      YY_LAC_DISCARD ("YYBACKUP");				\
       goto yybackup;						\
     }								\
   else								\
@@ -1049,165 +1031,165 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 808 of yacc.c  */
-#line 184 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 185 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 808 of yacc.c  */
-#line 1058 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1040 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 808 of yacc.c  */
-#line 196 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 197 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 808 of yacc.c  */
-#line 1067 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1049 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 808 of yacc.c  */
-#line 186 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 808 of yacc.c  */
-#line 1076 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1058 "parse-gram.c"
 	break;
       case 44: /* "\"[identifier]\"" */
 
-/* Line 808 of yacc.c  */
-#line 191 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 192 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
 
-/* Line 808 of yacc.c  */
-#line 1085 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1067 "parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
-/* Line 808 of yacc.c  */
-#line 178 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 179 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 808 of yacc.c  */
-#line 1094 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1076 "parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
-/* Line 808 of yacc.c  */
-#line 186 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 808 of yacc.c  */
-#line 1103 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1085 "parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
-/* Line 808 of yacc.c  */
-#line 190 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 191 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 808 of yacc.c  */
-#line 1112 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1094 "parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
-/* Line 808 of yacc.c  */
-#line 192 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 808 of yacc.c  */
-#line 1121 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1103 "parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
-/* Line 808 of yacc.c  */
-#line 186 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 808 of yacc.c  */
-#line 1130 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1112 "parse-gram.c"
 	break;
       case 54: /* "\"type\"" */
 
-/* Line 808 of yacc.c  */
-#line 193 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 194 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 808 of yacc.c  */
-#line 1139 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1121 "parse-gram.c"
 	break;
       case 71: /* "symbol.prec" */
 
-/* Line 808 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 808 of yacc.c  */
-#line 1148 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1130 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
-/* Line 808 of yacc.c  */
-#line 190 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 191 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 808 of yacc.c  */
-#line 1157 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1139 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
-/* Line 808 of yacc.c  */
-#line 186 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 808 of yacc.c  */
-#line 1166 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1148 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
-/* Line 808 of yacc.c  */
-#line 186 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 808 of yacc.c  */
-#line 1175 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1157 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
-/* Line 808 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 808 of yacc.c  */
-#line 1184 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1166 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
-/* Line 808 of yacc.c  */
-#line 200 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 201 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 808 of yacc.c  */
-#line 1193 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1175 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
-/* Line 808 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 808 of yacc.c  */
-#line 1202 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1184 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
-/* Line 808 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 819 of yacc.c  */
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 808 of yacc.c  */
-#line 1211 "parse-gram.c"
+/* Line 819 of yacc.c  */
+#line 1193 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1340,6 +1322,239 @@ int yydebug;
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
 
@@ -1444,15 +1659,18 @@ yytnamerr (char *yyres, const char *yystr)
 
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
@@ -1484,34 +1702,32 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
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
@@ -1526,6 +1742,10 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 yysize = yysize1;
               }
         }
+# if YYDEBUG
+      else if (yydebug)
+        YYFPRINTF (stderr, "No expected tokens.\n");
+# endif
     }
 
   switch (yycount)
@@ -1699,6 +1919,11 @@ YYLTYPE yylloc;
 
     YYSIZE_T yystacksize;
 
+    yytype_int16 yyesa[20];
+    yytype_int16 *yyes;
+    YYSIZE_T yyes_capacity;
+
+  int yy_lac_established = 0;
   int yyn;
   int yyresult;
   /* Lookahead token as an internal (translated) token number.  */
@@ -1727,6 +1952,11 @@ YYLTYPE yylloc;
   yyls = yylsa;
   yystacksize = YYINITDEPTH;
 
+  yyes = yyesa;
+  yyes_capacity = sizeof yyesa / sizeof *yyes;
+  if (YYMAXDEPTH < yyes_capacity)
+    yyes_capacity = YYMAXDEPTH;
+
   YYDPRINTF ((stderr, "Starting parse\n"));
 
   yystate = 0;
@@ -1750,8 +1980,8 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1496 of yacc.c  */
-#line 86 "parse-gram.y"
+/* Line 1590 of yacc.c  */
+#line 87 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1759,8 +1989,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1496 of yacc.c  */
-#line 1764 "parse-gram.c"
+/* Line 1590 of yacc.c  */
+#line 1994 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1886,12 +2116,16 @@ yybackup:
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
@@ -1906,6 +2140,7 @@ yybackup:
 
   /* Discard the shifted token.  */
   yychar = YYEMPTY;
+  YY_LAC_DISCARD ("shift");
 
   yystate = yyn;
   *++yyvsp = yylval;
@@ -1943,12 +2178,14 @@ yyreduce:
   /* Default location.  */
   YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
   YY_REDUCE_PRINT (yyn);
-  switch (yyn)
-    {
-        case 6:
+  {
+    int yychar_backup = yychar;
+    switch (yyn)
+      {
+          case 6:
 
-/* Line 1712 of yacc.c  */
-#line 225 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 226 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -1962,15 +2199,15 @@ yyreduce:
 
   case 7:
 
-/* Line 1712 of yacc.c  */
-#line 234 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 235 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1712 of yacc.c  */
-#line 236 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 237 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
@@ -1979,15 +2216,15 @@ yyreduce:
 
   case 9:
 
-/* Line 1712 of yacc.c  */
-#line 240 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 241 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1712 of yacc.c  */
-#line 242 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 243 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1996,43 +2233,43 @@ yyreduce:
 
   case 11:
 
-/* Line 1712 of yacc.c  */
-#line 246 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 247 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1712 of yacc.c  */
-#line 247 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 248 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1712 of yacc.c  */
-#line 248 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 249 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1712 of yacc.c  */
-#line 249 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 250 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1712 of yacc.c  */
-#line 250 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 251 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1712 of yacc.c  */
-#line 252 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 253 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -2041,8 +2278,8 @@ yyreduce:
 
   case 17:
 
-/* Line 1712 of yacc.c  */
-#line 257 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 258 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -2055,78 +2292,78 @@ yyreduce:
 
   case 18:
 
-/* Line 1712 of yacc.c  */
-#line 265 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 266 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1712 of yacc.c  */
-#line 266 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 267 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1712 of yacc.c  */
-#line 267 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 268 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1712 of yacc.c  */
-#line 268 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 269 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1712 of yacc.c  */
-#line 269 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 270 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1712 of yacc.c  */
-#line 270 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 271 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1712 of yacc.c  */
-#line 271 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 272 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1712 of yacc.c  */
-#line 272 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 273 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1712 of yacc.c  */
-#line 273 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 274 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1712 of yacc.c  */
-#line 274 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 275 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1712 of yacc.c  */
-#line 276 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 277 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
          `%define api.pure' in a backward-compatible manner here.  First, don't
@@ -2145,15 +2382,15 @@ yyreduce:
 
   case 29:
 
-/* Line 1712 of yacc.c  */
-#line 290 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 291 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1712 of yacc.c  */
-#line 292 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 293 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2181,29 +2418,29 @@ yyreduce:
 
   case 31:
 
-/* Line 1712 of yacc.c  */
-#line 315 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 316 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1712 of yacc.c  */
-#line 316 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 317 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1712 of yacc.c  */
-#line 317 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 318 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1712 of yacc.c  */
-#line 325 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 326 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2211,8 +2448,8 @@ yyreduce:
 
   case 38:
 
-/* Line 1712 of yacc.c  */
-#line 329 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 330 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2223,8 +2460,8 @@ yyreduce:
 
   case 39:
 
-/* Line 1712 of yacc.c  */
-#line 336 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 337 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2235,8 +2472,8 @@ yyreduce:
 
   case 40:
 
-/* Line 1712 of yacc.c  */
-#line 343 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 344 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2244,8 +2481,8 @@ yyreduce:
 
   case 41:
 
-/* Line 1712 of yacc.c  */
-#line 347 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 348 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2253,8 +2490,8 @@ yyreduce:
 
   case 42:
 
-/* Line 1712 of yacc.c  */
-#line 351 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 352 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2265,8 +2502,8 @@ yyreduce:
 
   case 43:
 
-/* Line 1712 of yacc.c  */
-#line 358 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 359 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2275,22 +2512,22 @@ yyreduce:
 
   case 44:
 
-/* Line 1712 of yacc.c  */
-#line 372 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 373 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1712 of yacc.c  */
-#line 373 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 374 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1712 of yacc.c  */
-#line 378 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 379 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2300,15 +2537,15 @@ yyreduce:
 
   case 47:
 
-/* Line 1712 of yacc.c  */
-#line 389 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 390 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1712 of yacc.c  */
-#line 390 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 391 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2317,15 +2554,15 @@ yyreduce:
 
   case 49:
 
-/* Line 1712 of yacc.c  */
-#line 394 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 395 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1712 of yacc.c  */
-#line 395 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 396 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2334,8 +2571,8 @@ yyreduce:
 
   case 51:
 
-/* Line 1712 of yacc.c  */
-#line 400 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 401 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2347,8 +2584,8 @@ yyreduce:
 
   case 52:
 
-/* Line 1712 of yacc.c  */
-#line 411 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 412 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2364,127 +2601,127 @@ yyreduce:
 
   case 53:
 
-/* Line 1712 of yacc.c  */
-#line 425 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 426 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1712 of yacc.c  */
-#line 426 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 427 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1712 of yacc.c  */
-#line 427 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 428 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1712 of yacc.c  */
-#line 431 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 432 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1712 of yacc.c  */
-#line 432 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 433 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1712 of yacc.c  */
-#line 438 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 439 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1712 of yacc.c  */
-#line 440 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1712 of yacc.c  */
-#line 444 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 445 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1712 of yacc.c  */
-#line 445 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 446 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1712 of yacc.c  */
-#line 451 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 452 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1712 of yacc.c  */
-#line 453 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1712 of yacc.c  */
-#line 457 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 458 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1712 of yacc.c  */
-#line 458 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 459 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1712 of yacc.c  */
-#line 462 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 463 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1712 of yacc.c  */
-#line 463 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 464 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1712 of yacc.c  */
-#line 464 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 465 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1712 of yacc.c  */
-#line 465 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 466 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1712 of yacc.c  */
-#line 471 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 472 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2493,8 +2730,8 @@ yyreduce:
 
   case 71:
 
-/* Line 1712 of yacc.c  */
-#line 476 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 477 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2503,8 +2740,8 @@ yyreduce:
 
   case 72:
 
-/* Line 1712 of yacc.c  */
-#line 481 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 482 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2514,8 +2751,8 @@ yyreduce:
 
   case 73:
 
-/* Line 1712 of yacc.c  */
-#line 487 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 488 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2525,8 +2762,8 @@ yyreduce:
 
   case 74:
 
-/* Line 1712 of yacc.c  */
-#line 493 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 494 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2537,8 +2774,8 @@ yyreduce:
 
   case 81:
 
-/* Line 1712 of yacc.c  */
-#line 523 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 524 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2546,108 +2783,108 @@ yyreduce:
 
   case 82:
 
-/* Line 1712 of yacc.c  */
-#line 529 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 530 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (2)].symbol); current_lhs_location = (yylsp[(1) - (2)]);
     current_lhs_named_ref = (yyvsp[(2) - (2)].named_ref); }
     break;
 
   case 84:
 
-/* Line 1712 of yacc.c  */
-#line 534 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 535 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1712 of yacc.c  */
-#line 535 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 536 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1712 of yacc.c  */
-#line 541 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 542 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
     break;
 
   case 88:
 
-/* Line 1712 of yacc.c  */
-#line 544 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 545 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1712 of yacc.c  */
-#line 546 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 547 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1712 of yacc.c  */
-#line 548 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 549 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1712 of yacc.c  */
-#line 550 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 551 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1712 of yacc.c  */
-#line 552 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 553 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1712 of yacc.c  */
-#line 556 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 557 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1712 of yacc.c  */
-#line 558 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 559 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1712 of yacc.c  */
-#line 570 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 571 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1712 of yacc.c  */
-#line 575 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 576 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1712 of yacc.c  */
-#line 576 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 577 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1712 of yacc.c  */
-#line 587 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 588 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2660,15 +2897,15 @@ yyreduce:
 
   case 101:
 
-/* Line 1712 of yacc.c  */
-#line 607 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 608 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1712 of yacc.c  */
-#line 609 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 610 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2678,15 +2915,15 @@ yyreduce:
 
   case 103:
 
-/* Line 1712 of yacc.c  */
-#line 617 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 618 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1712 of yacc.c  */
-#line 629 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 630 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2695,8 +2932,8 @@ yyreduce:
 
   case 108:
 
-/* Line 1712 of yacc.c  */
-#line 638 "parse-gram.y"
+/* Line 1806 of yacc.c  */
+#line 639 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2709,10 +2946,13 @@ yyreduce:
 
 
 
-/* Line 1712 of yacc.c  */
-#line 2714 "parse-gram.c"
-      default: break;
-    }
+/* Line 1806 of yacc.c  */
+#line 2951 "parse-gram.c"
+        default: break;
+      }
+    if (yychar_backup != yychar)
+      YY_LAC_DISCARD ("yychar change");
+  }
   /* User semantic actions sometimes alter yychar, and that requires
      that yytoken be updated with the new translation.  We take the
      approach of translating immediately before every use of yytoken.
@@ -2763,11 +3003,14 @@ yyerrlab:
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
@@ -2875,6 +3118,10 @@ yyerrlab1:
       YY_STACK_PRINT (yyss, yyssp);
     }
 
+  /* If the stack popping above didn't lose the initial context for the
+     current lookahead token, the shift below will for sure.  */
+  YY_LAC_DISCARD ("error recovery");
+
   *++yyvsp = yylval;
 
   yyerror_range[2] = yylloc;
@@ -2904,7 +3151,7 @@ yyabortlab:
   yyresult = 1;
   goto yyreturn;
 
-#if !defined(yyoverflow) || YYERROR_VERBOSE
+#if 1
 /*-------------------------------------------------.
 | yyexhaustedlab -- memory exhaustion comes here.  |
 `-------------------------------------------------*/
@@ -2937,6 +3184,8 @@ yyreturn:
   if (yyss != yyssa)
     YYSTACK_FREE (yyss);
 #endif
+  if (yyes != yyesa)
+    YYSTACK_FREE (yyes);
 #if YYERROR_VERBOSE
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
@@ -2947,8 +3196,8 @@ yyreturn:
 
 
 
-/* Line 1970 of yacc.c  */
-#line 648 "parse-gram.y"
+/* Line 2067 of yacc.c  */
+#line 649 "parse-gram.y"
 
 
 
