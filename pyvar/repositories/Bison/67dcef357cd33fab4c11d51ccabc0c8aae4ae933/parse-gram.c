@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.2.86-be13.  */
+/* A Bison parser, made by GNU Bison 3.4.2.115-5e16-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.2.86-be13"
+#define YYBISON_VERSION "3.4.2.115-5e16-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -232,12 +232,31 @@ typedef YYTYPE_INT16 yytype_int16;
 typedef short yytype_int16;
 #endif
 
+#ifndef YYPTRDIFF_T
+# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
+#  define YYPTRDIFF_T __PTRDIFF_TYPE__
+#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
+# elif defined ptrdiff_t && defined PTRDIFF_MAX
+#  define YYPTRDIFF_T ptrdiff_t
+#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
+# elif 199901 <= __STDC_VERSION__
+#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
+#  define YYPTRDIFF_T ptrdiff_t
+#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
+#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
+# else
+#  define YYPTRDIFF_T int
+#  include <limits.h> /* INFRINGES ON USER NAME SPACE */
+#  define YYPTRDIFF_MAXIMUM INT_MAX
+# endif
+#endif
+
 #ifndef YYSIZE_T
 # ifdef __SIZE_TYPE__
 #  define YYSIZE_T __SIZE_TYPE__
 # elif defined size_t
 #  define YYSIZE_T size_t
-# elif ! defined YYSIZE_T
+# elif 199901 <= __STDC_VERSION__
 #  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
 #  define YYSIZE_T size_t
 # else
@@ -245,7 +264,15 @@ typedef short yytype_int16;
 # endif
 #endif
 
-#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)
+#define YYSIZE_MAXIMUM ((YYPTRDIFF_T) (YYPTRDIFF_MAXIMUM < (YYSIZE_T) -1 \
+                                       ? YYPTRDIFF_MAXIMUM : (YYSIZE_T) -1))
+
+#define YYSIZEOF(X) ((YYPTRDIFF_T) sizeof (X))
+
+
+/* State numbers. */
+typedef yytype_uint8 yy_state_num;
+
 
 #ifndef YY_
 # if defined YYENABLE_NLS && YYENABLE_NLS
@@ -304,6 +331,18 @@ typedef short yytype_int16;
 #endif
 
 
+/* Suppress bogus -Wconversion warnings from GCC.  */
+#if 4 < __GNUC__ + (7 <= __GNUC_MINOR__)
+# define YY_CONVERT_INT_BEGIN \
+    _Pragma ("GCC diagnostic push") \
+    _Pragma ("GCC diagnostic ignored \"-Wconversion\"")
+# define YY_CONVERT_INT_END \
+    _Pragma ("GCC diagnostic pop")
+#else
+# define YY_CONVERT_INT_BEGIN
+# define YY_CONVERT_INT_END
+#endif
+
 #define YY_ASSERT(E) ((void) (0 && (E)))
 
 #if 1
@@ -359,18 +398,19 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
 {
-  yytype_int16 yyss_alloc;
+  yy_state_num yyss_alloc;
   YYSTYPE yyvs_alloc;
   YYLTYPE yyls_alloc;
 };
 
 /* The size of the maximum gap between one aligned stack and the next.  */
-# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)
+# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)
 
 /* The size of an array large to enough to hold all stacks, each with
    N elements.  */
 # define YYSTACK_BYTES(N) \
-     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
+     ((N) * (YYSIZEOF (yy_state_num) + YYSIZEOF (YYSTYPE) \
+             + YYSIZEOF (YYLTYPE)) \
       + 2 * YYSTACK_GAP_MAXIMUM)
 
 # define YYCOPY_NEEDED 1
@@ -383,11 +423,11 @@ union yyalloc
 # define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
     do                                                                  \
       {                                                                 \
-        YYSIZE_T yynewbytes;                                            \
+        YYPTRDIFF_T yynewbytes;                                         \
         YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
         Stack = &yyptr->Stack_alloc;                                    \
-        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
-        yyptr += yynewbytes / sizeof (*yyptr);                          \
+        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
+        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
       }                                                                 \
     while (0)
 
@@ -399,12 +439,12 @@ union yyalloc
 # ifndef YYCOPY
 #  if defined __GNUC__ && 1 < __GNUC__
 #   define YYCOPY(Dst, Src, Count) \
-      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
+      __builtin_memcpy (Dst, Src, (YYSIZE_T) (Count) * sizeof (*(Src)))
 #  else
 #   define YYCOPY(Dst, Src, Count)              \
       do                                        \
         {                                       \
-          YYSIZE_T yyi;                         \
+          YYPTRDIFF_T yyi;                      \
           for (yyi = 0; yyi < (Count); yyi++)   \
             (Dst)[yyi] = (Src)[yyi];            \
         }                                       \
@@ -430,13 +470,14 @@ union yyalloc
 #define YYUNDEFTOK  2
 #define YYMAXUTOK   314
 
+
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
 #define YYTRANSLATE(YYX) (YYX)
 
 #if GRAM_DEBUG
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
-static const yytype_uint16 yyrline[] =
+static const yytype_int16 yyrline[] =
 {
        0,   296,   296,   305,   306,   310,   311,   317,   321,   326,
      327,   332,   333,   334,   335,   336,   341,   346,   347,   348,
@@ -490,7 +531,7 @@ static const char *const yytname[] =
 # ifdef YYPRINT
 /* YYTOKNUM[NUM] -- (External) token number corresponding to the
    (internal) symbol number NUM (which must be that of a token).  */
-static const yytype_uint16 yytoknum[] =
+static const yytype_int16 yytoknum[] =
 {
        0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
@@ -501,14 +542,14 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -130
+#define YYPACT_NINF (-130)
 
-#define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-130)))
+#define yypact_value_is_default(Yyn) \
+  ((Yyn) == YYPACT_NINF)
 
-#define YYTABLE_NINF -122
+#define YYTABLE_NINF (-122)
 
-#define yytable_value_is_error(Yytable_value) \
+#define yytable_value_is_error(Yyn) \
   0
 
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
@@ -537,7 +578,7 @@ static const yytype_int16 yypact[] =
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
      Performed when YYTABLE does not specify something else to do.  Zero
      means the default is an error.  */
-static const yytype_uint8 yydefact[] =
+static const yytype_int8 yydefact[] =
 {
        3,     0,     0,     1,     0,    48,    46,     0,    41,    42,
       52,    53,    54,    55,     0,    37,     0,     9,    11,     0,
@@ -639,7 +680,7 @@ static const yytype_int16 yycheck[] =
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
      symbol of state STATE-NUM.  */
-static const yytype_uint8 yystos[] =
+static const yytype_int8 yystos[] =
 {
        0,    61,    62,     0,     1,     4,     5,     6,     7,     8,
        9,    10,    11,    12,    16,    17,    18,    19,    20,    21,
@@ -661,7 +702,7 @@ static const yytype_uint8 yystos[] =
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
-static const yytype_uint8 yyr1[] =
+static const yytype_int8 yyr1[] =
 {
        0,    60,    61,    62,    62,    63,    63,    63,    63,    63,
       63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
@@ -679,7 +720,7 @@ static const yytype_uint8 yyr1[] =
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
-static const yytype_uint8 yyr2[] =
+static const yytype_int8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
        2,     1,     2,     2,     2,     1,     2,     2,     2,     1,
@@ -1058,7 +1099,7 @@ yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE
 `------------------------------------------------------------------*/
 
 static void
-yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
+yy_stack_print (yy_state_num *yybottom, yy_state_num *yytop)
 {
   YYFPRINTF (stderr, "Stack now");
   for (; yybottom <= yytop; yybottom++)
@@ -1081,12 +1122,12 @@ do {                                                            \
 `------------------------------------------------*/
 
 static void
-yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
+yy_reduce_print (yy_state_num *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
 {
-  unsigned long yylno = yyrline[yyrule];
+  int yylno = yyrline[yyrule];
   int yynrhs = yyr2[yyrule];
   int yyi;
-  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
+  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
              yyrule - 1, yylno);
   /* The symbols being reduced.  */
   for (yyi = 0; yyi < yynrhs; yyi++)
@@ -1144,22 +1185,21 @@ int yydebug;
    using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
    required.  Return 1 if memory is exhausted.  */
 static int
-yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
+yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
 #if GRAM_DEBUG
                       char const *yydebug_prefix,
                       char const *yydebug_suffix,
 #endif
-                      yytype_int16 **yybottom,
-                      yytype_int16 *yybottom_no_free,
-                      yytype_int16 **yytop, yytype_int16 *yytop_empty)
+                      yy_state_num **yybottom,
+                      yy_state_num *yybottom_no_free,
+                      yy_state_num **yytop, yy_state_num *yytop_empty)
 {
-  YYSIZE_T yysize_old =
-    (YYSIZE_T) (*yytop == yytop_empty ? 0 : *yytop - *yybottom + 1);
-  YYSIZE_T yysize_new = yysize_old + yyadd;
+  YYPTRDIFF_T yysize_old = *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
+  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
   if (*yycapacity < yysize_new)
     {
-      YYSIZE_T yyalloc = 2 * yysize_new;
-      yytype_int16 *yybottom_new;
+      YYPTRDIFF_T yyalloc = 2 * yysize_new;
+      yy_state_num *yybottom_new;
       /* Use YYMAXDEPTH for maximum stack size given that the stack
          should never need to grow larger than the main state stack
          needs to grow without LAC.  */
@@ -1172,7 +1212,8 @@ yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
       yybottom_new =
-        (yytype_int16*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
+        (yy_state_num *) YYSTACK_ALLOC ((YYSIZE_T)
+                                        (yyalloc * YYSIZEOF (*yybottom_new)));
       if (!yybottom_new)
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
@@ -1272,11 +1313,11 @@ do {                                                                     \
    contents of either array, alter *YYES and *YYES_CAPACITY, and free
    any old *YYES other than YYESA.  */
 static int
-yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
-        YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
+yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
+        YYPTRDIFF_T *yyes_capacity, yy_state_num *yyssp, int yytoken)
 {
-  yytype_int16 *yyes_prev = yyssp;
-  yytype_int16 *yyesp = yyes_prev;
+  yy_state_num *yyes_prev = yyssp;
+  yy_state_num *yyesp = yyes_prev;
   YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
   if (yytoken == YYUNDEFTOK)
     {
@@ -1313,11 +1354,11 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
           yyrule = -yyrule;
         }
       {
-        YYSIZE_T yylen = yyr2[yyrule];
+        YYPTRDIFF_T yylen = yyr2[yyrule];
         YYDPRINTF ((stderr, " R%d", yyrule - 1));
         if (yyesp != yyes_prev)
           {
-            YYSIZE_T yysize = (YYSIZE_T) (yyesp - *yyes + 1);
+            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
             if (yylen < yysize)
               {
                 yyesp -= yylen;
@@ -1333,19 +1374,20 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
           yyesp = yyes_prev -= yylen;
       }
       {
-        yytype_int16 yystate;
+        int yystate;
         {
           const int yylhs = yyr1[yyrule] - YYNTOKENS;
           const int yyi = yypgoto[yylhs] + *yyesp;
-          yystate = ((yytype_int16)
-                     (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
-                      ? yytable[yyi]
-                      : yydefgoto[yylhs]));
+          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
+                     ? yytable[yyi]
+                     : yydefgoto[yylhs]);
         }
         if (yyesp == yyes_prev)
           {
             yyesp = *yyes;
+            YY_CONVERT_INT_BEGIN
             *yyesp = yystate;
+            YY_CONVERT_INT_END
           }
         else
           {
@@ -1358,9 +1400,11 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
                 YYDPRINTF ((stderr, "\n"));
                 return 2;
               }
+            YY_CONVERT_INT_BEGIN
             *++yyesp = yystate;
+            YY_CONVERT_INT_END
           }
-        YYDPRINTF ((stderr, " G%d", (int) yystate));
+        YYDPRINTF ((stderr, " G%d", yystate));
       }
     }
 }
@@ -1370,13 +1414,13 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
 
 # ifndef yystrlen
 #  if defined __GLIBC__ && defined _STRING_H
-#   define yystrlen strlen
+#   define yystrlen(S) ((YYPTRDIFF_T) strlen (S))
 #  else
 /* Return the length of YYSTR.  */
-static YYSIZE_T
+static YYPTRDIFF_T
 yystrlen (const char *yystr)
 {
-  YYSIZE_T yylen;
+  YYPTRDIFF_T yylen;
   for (yylen = 0; yystr[yylen]; yylen++)
     continue;
   return yylen;
@@ -1412,12 +1456,12 @@ yystpcpy (char *yydest, const char *yysrc)
    backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
    null, do not copy; instead, return the length of what the result
    would have been.  */
-static YYSIZE_T
+static YYPTRDIFF_T
 yytnamerr (char *yyres, const char *yystr)
 {
   if (*yystr == '"')
     {
-      YYSIZE_T yyn = 0;
+      YYPTRDIFF_T yyn = 0;
       char const *yyp = yystr;
 
       for (;;)
@@ -1451,7 +1495,7 @@ yytnamerr (char *yyres, const char *yystr)
   if (! yyres)
     return yystrlen (yystr);
 
-  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
+  return yystpcpy (yyres, yystr) - yyres;
 }
 # endif
 
@@ -1466,12 +1510,12 @@ yytnamerr (char *yyres, const char *yystr)
    required number of bytes is too large to store or if
    yy_lac returned 2.  */
 static int
-yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
-                yytype_int16 *yyesa, yytype_int16 **yyes,
-                YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
+yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
+                yy_state_num *yyesa, yy_state_num **yyes,
+                YYPTRDIFF_T *yyes_capacity, yy_state_num *yyssp, int yytoken)
 {
-  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
-  YYSIZE_T yysize = yysize0;
+  YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
+  YYPTRDIFF_T yysize = yysize0;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
   const char *yyformat = YY_NULLPTR;
@@ -1529,7 +1573,8 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                   }
                 yyarg[yycount++] = yytname[yyx];
                 {
-                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
+                  YYPTRDIFF_T yysize1 = yysize + yytnamerr (YY_NULLPTR,
+                                                            yytname[yyx]);
                   if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                     yysize = yysize1;
                   else
@@ -1560,7 +1605,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
     }
 
   {
-    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
+    YYPTRDIFF_T yysize1 = yysize + yystrlen (yyformat);
     if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
       yysize = yysize1;
     else
@@ -1700,9 +1745,9 @@ YYLTYPE yylloc = yyloc_default;
        to reallocate them elsewhere.  */
 
     /* The state stack.  */
-    yytype_int16 yyssa[YYINITDEPTH];
-    yytype_int16 *yyss;
-    yytype_int16 *yyssp;
+    yy_state_num yyssa[YYINITDEPTH];
+    yy_state_num *yyss;
+    yy_state_num *yyssp;
 
     /* The semantic value stack.  */
     YYSTYPE yyvsa[YYINITDEPTH];
@@ -1717,11 +1762,11 @@ YYLTYPE yylloc = yyloc_default;
     /* The locations where the error started and ended.  */
     YYLTYPE yyerror_range[3];
 
-    YYSIZE_T yystacksize;
+    YYPTRDIFF_T yystacksize;
 
-    yytype_int16 yyesa[20];
-    yytype_int16 *yyes;
-    YYSIZE_T yyes_capacity;
+    yy_state_num yyesa[20];
+    yy_state_num *yyes;
+    YYPTRDIFF_T yyes_capacity;
 
   int yy_lac_established = 0;
   int yyn;
@@ -1737,7 +1782,7 @@ YYLTYPE yylloc = yyloc_default;
   /* Buffer for error messages, and its allocated size.  */
   char yymsgbuf[128];
   char *yymsg = yymsgbuf;
-  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
+  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
 #endif
 
 #define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))
@@ -1791,7 +1836,9 @@ yynewstate:
 yysetstate:
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
   YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
-  *yyssp = (yytype_int16) yystate;
+  YY_CONVERT_INT_BEGIN
+  *yyssp = yystate;
+  YY_CONVERT_INT_END
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
@@ -1799,15 +1846,15 @@ yysetstate:
 #else
     {
       /* Get the current used size of the three stacks, in elements.  */
-      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);
+      YYPTRDIFF_T yysize = yyssp - yyss + 1;
 
 # if defined yyoverflow
       {
         /* Give user a chance to reallocate the stack.  Use copies of
            these so that the &'s don't force the real ones into
            memory.  */
+        yy_state_num *yyss1 = yyss;
         YYSTYPE *yyvs1 = yyvs;
-        yytype_int16 *yyss1 = yyss;
         YYLTYPE *yyls1 = yyls;
 
         /* Each stack pointer address is followed by the size of the
@@ -1815,9 +1862,9 @@ yysetstate:
            conditional around just the two extra args, but that might
            be undefined if yyoverflow is a macro.  */
         yyoverflow (YY_("memory exhausted"),
-                    &yyss1, yysize * sizeof (*yyssp),
-                    &yyvs1, yysize * sizeof (*yyvsp),
-                    &yyls1, yysize * sizeof (*yylsp),
+                    &yyss1, yysize * YYSIZEOF (*yyssp),
+                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
+                    &yyls1, yysize * YYSIZEOF (*yylsp),
                     &yystacksize);
         yyss = yyss1;
         yyvs = yyvs1;
@@ -1832,9 +1879,10 @@ yysetstate:
         yystacksize = YYMAXDEPTH;
 
       {
-        yytype_int16 *yyss1 = yyss;
+        yy_state_num *yyss1 = yyss;
         union yyalloc *yyptr =
-          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
+          (union yyalloc *) YYSTACK_ALLOC ((YYSIZE_T)
+                                           YYSTACK_BYTES (yystacksize));
         if (! yyptr)
           goto yyexhaustedlab;
         YYSTACK_RELOCATE (yyss_alloc, yyss);
@@ -1850,8 +1898,8 @@ yysetstate:
       yyvsp = yyvs + yysize - 1;
       yylsp = yyls + yysize - 1;
 
-      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
-                  (unsigned long) yystacksize));
+      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
+                  (long) yystacksize));
 
       if (yyss + yystacksize - 1 <= yyssp)
         YYABORT;
@@ -2457,7 +2505,7 @@ yyreduce:
         }
       if (muscle_percent_define_ifdef (var))
         {
-          unsigned indent = 0;
+          int indent = 0;
           complain_indent (&(yylsp[0]), complaint, &indent,
                            _("character literals cannot be used together"
                              " with %s"), var);
@@ -2565,7 +2613,7 @@ yyerrlab:
           {
             if (yymsg != yymsgbuf)
               YYSTACK_FREE (yymsg);
-            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
+            yymsg = (char *) YYSTACK_ALLOC ((YYSIZE_T) yymsg_alloc);
             if (!yymsg)
               {
                 yymsg = yymsgbuf;
@@ -2933,7 +2981,7 @@ handle_require (location const *loc, char const *version)
      is the same as "3.0". */
   errno = 0;
   char* cp = NULL;
-  unsigned long major = strtoul (version, &cp, 10);
+  long major = strtol (version, &cp, 10);
   if (errno || *cp != '.')
     {
       complain (loc, complaint, _("invalid version requirement: %s"),
@@ -2941,7 +2989,7 @@ handle_require (location const *loc, char const *version)
       return;
     }
   ++cp;
-  unsigned long minor = strtoul (cp, NULL, 10);
+  long minor = strtol (cp, NULL, 10);
   if (errno)
     {
       complain (loc, complaint, _("invalid version requirement: %s"),
