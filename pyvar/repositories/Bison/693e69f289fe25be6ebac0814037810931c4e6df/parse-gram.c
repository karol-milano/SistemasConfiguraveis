@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.2.169-2644f.  */
+/* A Bison parser, made by GNU Bison 3.4.2.189-f435.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.2.169-2644f"
+#define YYBISON_VERSION "3.4.2.189-f435"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -113,6 +113,7 @@
   #include "files.h"
   #include "getargs.h"
   #include "gram.h"
+  #include "intprops.h"
   #include "named-ref.h"
   #include "quotearg.h"
   #include "reader.h"
@@ -208,13 +209,10 @@
    so that the code can choose integer types of a good width.  */
 
 #ifndef __PTRDIFF_MAX__
-# ifndef INT_MAX
-#  include <limits.h> /* INFRINGES ON USER NAME SPACE */
-# endif
-# ifndef PTRDIFF_MAX
-#  if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
-#   include <stdint.h> /* INFRINGES ON USER NAME SPACE */
-#  endif
+# include <limits.h> /* INFRINGES ON USER NAME SPACE */
+# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
+#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
+#  define YY_STDINT_H
 # endif
 #endif
 
@@ -225,7 +223,7 @@
 
 #ifdef __INT_LEAST8_MAX__
 typedef __INT_LEAST8_TYPE__ yytype_int8;
-#elif defined INT_LEAST8_MAX
+#elif defined YY_STDINT_H
 typedef int_least8_t yytype_int8;
 #else
 typedef signed char yytype_int8;
@@ -233,7 +231,7 @@ typedef signed char yytype_int8;
 
 #ifdef __INT_LEAST16_MAX__
 typedef __INT_LEAST16_TYPE__ yytype_int16;
-#elif defined INT_LEAST16_MAX
+#elif defined YY_STDINT_H
 typedef int_least16_t yytype_int16;
 #else
 typedef short yytype_int16;
@@ -241,7 +239,7 @@ typedef short yytype_int16;
 
 #if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
 typedef __UINT_LEAST8_TYPE__ yytype_uint8;
-#elif (!defined __UINT_LEAST8_MAX__ && defined UINT_LEAST8_MAX \
+#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
        && UINT_LEAST8_MAX <= INT_MAX)
 typedef uint_least8_t yytype_uint8;
 #elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
@@ -252,7 +250,7 @@ typedef short yytype_uint8;
 
 #if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
 typedef __UINT_LEAST16_TYPE__ yytype_uint16;
-#elif (!defined __UINT_LEAST16_MAX__ && defined UINT_LEAST16_MAX \
+#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
        && UINT_LEAST16_MAX <= INT_MAX)
 typedef uint_least16_t yytype_uint16;
 #elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
@@ -295,10 +293,11 @@ typedef int yytype_uint16;
 
 #define YYSIZEOF(X) ((YYPTRDIFF_T) sizeof (X))
 
+/* Stored state numbers (used for stacks). */
+typedef yytype_uint8 yy_state_t;
 
-/* State numbers. */
-typedef yytype_uint8 yy_state_num;
-
+/* State numbers in computations.  */
+typedef int yy_state_fast_t;
 
 #ifndef YY_
 # if defined YYENABLE_NLS && YYENABLE_NLS
@@ -312,22 +311,20 @@ typedef yytype_uint8 yy_state_num;
 # endif
 #endif
 
-#ifndef YY_ATTRIBUTE
-# if (defined __GNUC__                                               \
-      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
-     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
-#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
+#ifndef YY_ATTRIBUTE_PURE
+# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
+#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
 # else
-#  define YY_ATTRIBUTE(Spec) /* empty */
+#  define YY_ATTRIBUTE_PURE
 # endif
 #endif
 
-#ifndef YY_ATTRIBUTE_PURE
-# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
-#endif
-
 #ifndef YY_ATTRIBUTE_UNUSED
-# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
+# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
+#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
+# else
+#  define YY_ATTRIBUTE_UNUSED
+# endif
 #endif
 
 /* Suppress unused-variable warnings by "using" E.  */
@@ -412,7 +409,7 @@ void free (void *); /* INFRINGES ON USER NAME SPACE */
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
 {
-  yy_state_num yyss_alloc;
+  yy_state_t yyss_alloc;
   YYSTYPE yyvs_alloc;
   YYLTYPE yyls_alloc;
 };
@@ -423,7 +420,7 @@ union yyalloc
 /* The size of an array large to enough to hold all stacks, each with
    N elements.  */
 # define YYSTACK_BYTES(N) \
-     ((N) * (YYSIZEOF (yy_state_num) + YYSIZEOF (YYSTYPE) \
+     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
              + YYSIZEOF (YYLTYPE)) \
       + 2 * YYSTACK_GAP_MAXIMUM)
 
@@ -493,19 +490,19 @@ union yyalloc
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_int16 yyrline[] =
 {
-       0,   291,   291,   300,   301,   305,   306,   312,   316,   321,
-     322,   327,   328,   329,   330,   331,   336,   341,   342,   343,
-     344,   345,   346,   346,   347,   348,   349,   350,   351,   352,
-     353,   354,   358,   359,   368,   369,   373,   384,   388,   392,
-     400,   410,   411,   421,   422,   428,   441,   441,   446,   446,
-     451,   455,   465,   466,   467,   468,   472,   473,   478,   479,
-     483,   484,   488,   489,   490,   503,   512,   516,   520,   528,
-     529,   533,   546,   547,   559,   563,   567,   575,   577,   582,
-     589,   599,   603,   607,   615,   616,   624,   625,   631,   632,
-     633,   640,   640,   648,   649,   650,   655,   658,   660,   662,
-     664,   666,   668,   670,   672,   674,   679,   680,   689,   713,
-     714,   715,   716,   728,   730,   757,   762,   763,   768,   777,
-     778,   782,   783
+       0,   292,   292,   301,   302,   306,   307,   313,   317,   322,
+     323,   328,   329,   330,   331,   332,   337,   342,   343,   344,
+     345,   346,   347,   347,   348,   349,   350,   351,   352,   353,
+     354,   355,   359,   360,   369,   370,   374,   385,   389,   393,
+     401,   411,   412,   422,   423,   429,   442,   442,   447,   447,
+     452,   456,   466,   467,   468,   469,   473,   474,   479,   480,
+     484,   485,   489,   490,   491,   504,   513,   517,   521,   529,
+     530,   534,   547,   548,   560,   564,   568,   576,   578,   583,
+     590,   600,   604,   608,   616,   617,   625,   626,   632,   633,
+     634,   641,   641,   649,   650,   651,   656,   659,   661,   663,
+     665,   667,   669,   671,   673,   675,   680,   681,   690,   714,
+     715,   716,   717,   729,   731,   758,   763,   764,   769,   778,
+     779,   783,   784
 };
 #endif
 
@@ -1113,7 +1110,7 @@ yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE
 `------------------------------------------------------------------*/
 
 static void
-yy_stack_print (yy_state_num *yybottom, yy_state_num *yytop)
+yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
 {
   YYFPRINTF (stderr, "Stack now");
   for (; yybottom <= yytop; yybottom++)
@@ -1136,7 +1133,7 @@ do {                                                            \
 `------------------------------------------------*/
 
 static void
-yy_reduce_print (yy_state_num *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
+yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
 {
   int yylno = yyrline[yyrule];
   int yynrhs = yyr2[yyrule];
@@ -1204,9 +1201,9 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
                       char const *yydebug_prefix,
                       char const *yydebug_suffix,
 #endif
-                      yy_state_num **yybottom,
-                      yy_state_num *yybottom_no_free,
-                      yy_state_num **yytop, yy_state_num *yytop_empty)
+                      yy_state_t **yybottom,
+                      yy_state_t *yybottom_no_free,
+                      yy_state_t **yytop, yy_state_t *yytop_empty)
 {
   YYPTRDIFF_T yysize_old =
     *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
@@ -1214,7 +1211,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
   if (*yycapacity < yysize_new)
     {
       YYPTRDIFF_T yyalloc = 2 * yysize_new;
-      yy_state_num *yybottom_new;
+      yy_state_t *yybottom_new;
       /* Use YYMAXDEPTH for maximum stack size given that the stack
          should never need to grow larger than the main state stack
          needs to grow without LAC.  */
@@ -1227,7 +1224,7 @@ yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
       if (YYMAXDEPTH < yyalloc)
         yyalloc = YYMAXDEPTH;
       yybottom_new =
-        (yy_state_num *) YYSTACK_ALLOC ((YYSIZE_T)
+        (yy_state_t *) YYSTACK_ALLOC ((YYSIZE_T)
                                         (yyalloc * YYSIZEOF (*yybottom_new)));
       if (!yybottom_new)
         {
@@ -1328,11 +1325,11 @@ do {                                                                     \
    contents of either array, alter *YYES and *YYES_CAPACITY, and free
    any old *YYES other than YYESA.  */
 static int
-yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
-        YYPTRDIFF_T *yyes_capacity, yy_state_num *yyssp, int yytoken)
+yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
+        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, int yytoken)
 {
-  yy_state_num *yyes_prev = yyssp;
-  yy_state_num *yyesp = yyes_prev;
+  yy_state_t *yyes_prev = yyssp;
+  yy_state_t *yyesp = yyes_prev;
   YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yytname[yytoken]));
   if (yytoken == YYUNDEFTOK)
     {
@@ -1389,7 +1386,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
           yyesp = yyes_prev -= yylen;
       }
       {
-        int yystate;
+        yy_state_fast_t yystate;
         {
           const int yylhs = yyr1[yyrule] - YYNTOKENS;
           const int yyi = yypgoto[yylhs] + *yyesp;
@@ -1400,7 +1397,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
         if (yyesp == yyes_prev)
           {
             yyesp = *yyes;
-            *yyesp = (yy_state_num) yystate;
+            *yyesp = (yy_state_t) yystate;
           }
         else
           {
@@ -1413,7 +1410,7 @@ yy_lac (yy_state_num *yyesa, yy_state_num **yyes,
                 YYDPRINTF ((stderr, "\n"));
                 return 2;
               }
-            *++yyesp = (yy_state_num) yystate;
+            *++yyesp = (yy_state_t) yystate;
           }
         YYDPRINTF ((stderr, " G%d", yystate));
       }
@@ -1522,8 +1519,8 @@ yytnamerr (char *yyres, const char *yystr)
    yy_lac returned 2.  */
 static int
 yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
-                yy_state_num *yyesa, yy_state_num **yyes,
-                YYPTRDIFF_T *yyes_capacity, yy_state_num *yyssp, int yytoken)
+                yy_state_t *yyesa, yy_state_t **yyes,
+                YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, int yytoken)
 {
   YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
   YYPTRDIFF_T yysize = yysize0;
@@ -1743,7 +1740,7 @@ YYLTYPE yylloc = yyloc_default;
     /* Number of syntax errors so far.  */
     int yynerrs;
 
-    int yystate;
+    yy_state_fast_t yystate;
     /* Number of tokens to shift before error messages enabled.  */
     int yyerrstatus;
 
@@ -1756,9 +1753,9 @@ YYLTYPE yylloc = yyloc_default;
        to reallocate them elsewhere.  */
 
     /* The state stack.  */
-    yy_state_num yyssa[YYINITDEPTH];
-    yy_state_num *yyss;
-    yy_state_num *yyssp;
+    yy_state_t yyssa[YYINITDEPTH];
+    yy_state_t *yyss;
+    yy_state_t *yyssp;
 
     /* The semantic value stack.  */
     YYSTYPE yyvsa[YYINITDEPTH];
@@ -1775,8 +1772,8 @@ YYLTYPE yylloc = yyloc_default;
 
     YYPTRDIFF_T yystacksize;
 
-    yy_state_num yyesa[20];
-    yy_state_num *yyes;
+    yy_state_t yyesa[20];
+    yy_state_t *yyes;
     YYPTRDIFF_T yyes_capacity;
 
   int yy_lac_established = 0;
@@ -1847,7 +1844,7 @@ yynewstate:
 yysetstate:
   YYDPRINTF ((stderr, "Entering state %d\n", yystate));
   YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
-   *yyssp = (yy_state_num) yystate;
+   *yyssp = (yy_state_t) yystate;
 
   if (yyss + yystacksize - 1 <= yyssp)
 #if !defined yyoverflow && !defined YYSTACK_RELOCATE
@@ -1862,7 +1859,7 @@ yysetstate:
         /* Give user a chance to reallocate the stack.  Use copies of
            these so that the &'s don't force the real ones into
            memory.  */
-        yy_state_num *yyss1 = yyss;
+        yy_state_t *yyss1 = yyss;
         YYSTYPE *yyvs1 = yyvs;
         YYLTYPE *yyls1 = yyls;
 
@@ -1888,7 +1885,7 @@ yysetstate:
         yystacksize = YYMAXDEPTH;
 
       {
-        yy_state_num *yyss1 = yyss;
+        yy_state_t *yyss1 = yyss;
         union yyalloc *yyptr =
           (union yyalloc *) YYSTACK_ALLOC ((YYSIZE_T)
                                            YYSTACK_BYTES (yystacksize));
@@ -1978,16 +1975,15 @@ yybackup:
 
   /* Shift the lookahead token.  */
   YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
-
-  /* Discard the shifted token.  */
-  yychar = YYEMPTY;
-  YY_LAC_DISCARD ("shift");
-
   yystate = yyn;
   YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   *++yyvsp = yylval;
   YY_IGNORE_MAYBE_UNINITIALIZED_END
   *++yylsp = yylloc;
+
+  /* Discard the shifted token.  */
+  yychar = YYEMPTY;
+  YY_LAC_DISCARD ("shift");
   goto yynewstate;
 
 
@@ -2989,23 +2985,24 @@ handle_require (location const *loc, char const *version)
   /* Changes of behavior are only on minor version changes, so "3.0.5"
      is the same as "3.0". */
   errno = 0;
-  char* cp = NULL;
+  char *cp = NULL, *cp1;
   long major = strtol (version, &cp, 10);
-  if (errno || *cp != '.')
+  if (errno || cp == version || *cp != '.' || major < 0)
     {
       complain (loc, complaint, _("invalid version requirement: %s"),
                 version);
       return;
     }
   ++cp;
-  long minor = strtol (cp, NULL, 10);
-  if (errno)
+  long minor = strtol (cp, &cp1, 10);
+  if (errno || cp1 == cp || ! (0 <= minor && minor < 100)
+      || INT_MULTIPLY_WRAPV (major, 100, &required_version)
+      || INT_ADD_WRAPV (minor, required_version, &required_version))
     {
       complain (loc, complaint, _("invalid version requirement: %s"),
                 version);
       return;
     }
-  required_version = major * 100 + minor;
   /* Pretend to be at least 3.4, to check features published in 3.4
      while developping it.  */
   const char* api_version = "3.4";
