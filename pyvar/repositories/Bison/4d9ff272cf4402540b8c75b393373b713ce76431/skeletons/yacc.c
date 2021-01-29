@@ -112,18 +112,16 @@ m4_ifset([b4_parse_param], [b4_args(b4_parse_param), ])])
 
 # b4_int_type(MIN, MAX)
 # ---------------------
-# Return the smallest int type able to handle numbers ranging from
+# Return a narrow int type able to handle numbers ranging from
 # MIN to MAX (included).  Overwrite the version from c.m4, which
 # uses only C89 types, so that the user can override the shorter
 # types, and so that pre-C89 compilers are handled correctly.
 m4_define([b4_int_type],
-[m4_if(b4_ints_in($@,      [0],   [255]), [1], [yytype_uint8],
-       b4_ints_in($@,   [-128],   [127]), [1], [yytype_int8],
+[m4_if(b4_ints_in($@,   [-127],   [127]), [1], [yytype_int8],
+       b4_ints_in($@,      [0],   [255]), [1], [yytype_uint8],
 
+       b4_ints_in($@, [-32767], [32767]), [1], [yytype_int16],
        b4_ints_in($@,      [0], [65535]), [1], [yytype_uint16],
-       b4_ints_in($@, [-32768], [32767]), [1], [yytype_int16],
-
-       m4_eval([0 <= $1]),                [1], [unsigned],
 
                                                [int])])
 
@@ -246,11 +244,11 @@ m4_define([b4_declare_parser_state_variables], [b4_pure_if([[
     /* The locations where the error started and ended.  */
     YYLTYPE yyerror_range[3];]])[
 
-    YYSIZE_T yystacksize;]b4_lac_if([[
+    YYPTRDIFF_T yystacksize;]b4_lac_if([[
 
     yy_state_num yyesa@{]b4_percent_define_get([[parse.lac.es-capacity-initial]])[@};
     yy_state_num *yyes;
-    YYSIZE_T yyes_capacity;]])])
+    YYPTRDIFF_T yyes_capacity;]])])
 
 
 # _b4_declare_yyparse_push
@@ -427,12 +425,31 @@ typedef YYTYPE_INT16 yytype_int16;
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
@@ -440,7 +457,10 @@ typedef short yytype_int16;
 # endif
 #endif
 
-#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)
+#define YYSIZE_MAXIMUM ((YYPTRDIFF_T) (YYPTRDIFF_MAXIMUM < (YYSIZE_T) -1 \
+                                       ? YYPTRDIFF_MAXIMUM : (YYSIZE_T) -1))
+
+#define YYSIZEOF(X) ((YYPTRDIFF_T) sizeof (X))
 
 
 /* State numbers. */
@@ -554,16 +574,17 @@ union yyalloc
 };
 
 /* The size of the maximum gap between one aligned stack and the next.  */
-# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)
+# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)
 
 /* The size of an array large to enough to hold all stacks, each with
    N elements.  */
 ]b4_locations_if(
 [# define YYSTACK_BYTES(N) \
-     ((N) * (sizeof (yy_state_num) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
+     ((N) * (YYSIZEOF (yy_state_num) + YYSIZEOF (YYSTYPE) \
+             + YYSIZEOF (YYLTYPE)) \
       + 2 * YYSTACK_GAP_MAXIMUM)],
 [# define YYSTACK_BYTES(N) \
-     ((N) * (sizeof (yy_state_num) + sizeof (YYSTYPE)) \
+     ((N) * (YYSIZEOF (yy_state_num) + YYSIZEOF (YYSTYPE)) \
       + YYSTACK_GAP_MAXIMUM)])[
 
 # define YYCOPY_NEEDED 1
@@ -576,11 +597,11 @@ union yyalloc
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
 
@@ -592,12 +613,12 @@ union yyalloc
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
@@ -774,10 +795,10 @@ do {                                                            \
                    ])[[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,
                    b4_parse_param]))[
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
@@ -836,7 +857,7 @@ int yydebug;
    using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
    required.  Return 1 if memory is exhausted.  */
 static int
-yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
+yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
 #if ]b4_api_PREFIX[DEBUG
                       char const *yydebug_prefix,
                       char const *yydebug_suffix,
@@ -845,12 +866,11 @@ yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
                       yy_state_num *yybottom_no_free,
                       yy_state_num **yytop, yy_state_num *yytop_empty)
 {
-  YYSIZE_T yysize_old =
-    (YYSIZE_T) (*yytop == yytop_empty ? 0 : *yytop - *yybottom + 1);
-  YYSIZE_T yysize_new = yysize_old + yyadd;
+  YYPTRDIFF_T yysize_old = *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
+  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
   if (*yycapacity < yysize_new)
     {
-      YYSIZE_T yyalloc = 2 * yysize_new;
+      YYPTRDIFF_T yyalloc = 2 * yysize_new;
       yy_state_num *yybottom_new;
       /* Use YYMAXDEPTH for maximum stack size given that the stack
          should never need to grow larger than the main state stack
@@ -864,7 +884,8 @@ yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
       yybottom_new =
-        (yy_state_num*) YYSTACK_ALLOC (yyalloc * sizeof *yybottom_new);
+        (yy_state_num *) YYSTACK_ALLOC ((YYSIZE_T)
+                                        (yyalloc * YYSIZEOF (*yybottom_new)));
       if (!yybottom_new)
         {
           YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
@@ -881,8 +902,8 @@ yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
       *yybottom = yybottom_new;
       *yycapacity = yyalloc;]m4_if(b4_percent_define_get([[parse.lac.memory-trace]]),
                                    [full], [[
-      YYDPRINTF ((stderr, "%srealloc to %lu%s", yydebug_prefix,
-                  (unsigned long) yyalloc, yydebug_suffix));]])[
+      YYDPRINTF ((stderr, "%srealloc to %ld%s", yydebug_prefix,
+                  (long) yyalloc, yydebug_suffix));]])[
     }
   return 0;
 }
@@ -968,7 +989,7 @@ do {                                                                     \
    any old *YYES other than YYESA.  */
 static int
 yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
-        YYSIZE_T *yyes_capacity, yy_state_num *yyssp, int yytoken)
+        YYPTRDIFF_T *yyes_capacity, yy_state_num *yyssp, int yytoken)
 {
   yy_state_num *yyes_prev = yyssp;
   yy_state_num *yyesp = yyes_prev;
@@ -1008,11 +1029,11 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
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
@@ -1064,13 +1085,13 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
 
 # ifndef yystrlen
 #  if defined __GLIBC__ && defined _STRING_H
-#   define yystrlen strlen
+#   define yystrlen(S) ((YYPTRDIFF_T) strlen (S))
 #  else
 /* Return the length of YYSTR.  */
-]b4_function_define([yystrlen], [static YYSIZE_T],
+]b4_function_define([yystrlen], [static YYPTRDIFF_T],
    [[const char *yystr], [yystr]])[
 {
-  YYSIZE_T yylen;
+  YYPTRDIFF_T yylen;
   for (yylen = 0; yystr[yylen]; yylen++)
     continue;
   return yylen;
@@ -1106,12 +1127,12 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
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
@@ -1145,7 +1166,7 @@ yytnamerr (char *yyres, const char *yystr)
   if (! yyres)
     return yystrlen (yystr);
 
-  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
+  return yystpcpy (yyres, yystr) - yyres;
 }
 # endif
 
@@ -1160,12 +1181,12 @@ yytnamerr (char *yyres, const char *yystr)
    required number of bytes is too large to store]b4_lac_if([[ or if
    yy_lac returned 2]])[.  */
 static int
-yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
+yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                 ]b4_lac_if([[yy_state_num *yyesa, yy_state_num **yyes,
-                YYSIZE_T *yyes_capacity, ]])[yy_state_num *yyssp, int yytoken)
+                YYPTRDIFF_T *yyes_capacity, ]])[yy_state_num *yyssp, int yytoken)
 {
-  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
-  YYSIZE_T yysize = yysize0;
+  YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
+  YYPTRDIFF_T yysize = yysize0;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
   const char *yyformat = YY_NULLPTR;
@@ -1244,7 +1265,8 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                   }
                 yyarg[yycount++] = yytname[yyx];
                 {
-                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
+                  YYPTRDIFF_T yysize1 = yysize + yytnamerr (YY_NULLPTR,
+                                                            yytname[yyx]);
                   if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                     yysize = yysize1;
                   else
@@ -1275,7 +1297,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
     }
 
   {
-    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
+    YYPTRDIFF_T yysize1 = yysize + yystrlen (yyformat);
     if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
       yysize = yysize1;
     else
@@ -1456,7 +1478,7 @@ b4_function_define([[yyparse]], [[int]], b4_parse_param)[
   /* Buffer for error messages, and its allocated size.  */
   char yymsgbuf[128];
   char *yymsg = yymsgbuf;
-  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
+  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
 #endif
 
 #define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N)]b4_locations_if([, yylsp -= (N)])[)
@@ -1522,7 +1544,7 @@ yysetstate:
 #else
     {
       /* Get the current used size of the three stacks, in elements.  */
-      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);
+      YYPTRDIFF_T yysize = yyssp - yyss + 1;
 
 # if defined yyoverflow
       {
@@ -1538,9 +1560,9 @@ yysetstate:
            conditional around just the two extra args, but that might
            be undefined if yyoverflow is a macro.  */
         yyoverflow (YY_("memory exhausted"),
-                    &yyss1, yysize * sizeof (*yyssp),
-                    &yyvs1, yysize * sizeof (*yyvsp),]b4_locations_if([
-                    &yyls1, yysize * sizeof (*yylsp),])[
+                    &yyss1, yysize * YYSIZEOF (*yyssp),
+                    &yyvs1, yysize * YYSIZEOF (*yyvsp),]b4_locations_if([
+                    &yyls1, yysize * YYSIZEOF (*yylsp),])[
                     &yystacksize);
         yyss = yyss1;
         yyvs = yyvs1;]b4_locations_if([
@@ -1557,7 +1579,8 @@ yysetstate:
       {
         yy_state_num *yyss1 = yyss;
         union yyalloc *yyptr =
-          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
+          (union yyalloc *) YYSTACK_ALLOC ((YYSIZE_T)
+                                           YYSTACK_BYTES (yystacksize));
         if (! yyptr)
           goto yyexhaustedlab;
         YYSTACK_RELOCATE (yyss_alloc, yyss);
@@ -1573,8 +1596,8 @@ yysetstate:
       yyvsp = yyvs + yysize - 1;]b4_locations_if([
       yylsp = yyls + yysize - 1;])[
 
-      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
-                  (unsigned long) yystacksize));
+      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
+                  (long) yystacksize));
 
       if (yyss + yystacksize - 1 <= yyssp)
         YYABORT;
@@ -1788,7 +1811,7 @@ yyerrlab:
           {
             if (yymsg != yymsgbuf)
               YYSTACK_FREE (yymsg);
-            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
+            yymsg = (char *) YYSTACK_ALLOC ((YYSIZE_T) yymsg_alloc);
             if (!yymsg)
               {
                 yymsg = yymsgbuf;
