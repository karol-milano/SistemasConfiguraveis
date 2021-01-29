@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.7.4.133-f40c-dirty.  */
+/* A Bison parser, made by GNU Bison 3.7.4.169-6482.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 30704
 
 /* Bison version string.  */
-#define YYBISON_VERSION "3.7.4.133-f40c-dirty"
+#define YYBISON_VERSION "3.7.4.169-6482"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -643,7 +643,7 @@ union yyalloc
 #define YYTRANSLATE(YYX) YY_CAST (yysymbol_kind_t, YYX)
 
 #if GRAM_DEBUG
-  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
+/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_int16 yyrline[] =
 {
        0,   310,   310,   319,   320,   324,   325,   331,   335,   340,
@@ -741,8 +741,8 @@ static const yytype_int16 yytoknum[] =
 #define yytable_value_is_error(Yyn) \
   0
 
-  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
-     STATE-NUM.  */
+/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
+   STATE-NUM.  */
 static const yytype_int16 yypact[] =
 {
     -148,    13,   113,  -148,   -27,  -148,  -148,  -148,  -148,  -148,
@@ -764,9 +764,9 @@ static const yytype_int16 yypact[] =
      180,  -148,  -148,  -148,  -148,  -148,    37,  -148,  -148
 };
 
-  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
-     Performed when YYTABLE does not specify something else to do.  Zero
-     means the default is an error.  */
+/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
+   Performed when YYTABLE does not specify something else to do.  Zero
+   means the default is an error.  */
 static const yytype_int8 yydefact[] =
 {
        3,     0,     0,     1,     0,    47,    45,    49,    40,    41,
@@ -788,7 +788,7 @@ static const yytype_int8 yydefact[] =
       99,   106,   107,   108,   109,   110,   111,   102,   103
 };
 
-  /* YYPGOTO[NTERM-NUM].  */
+/* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
     -148,  -148,  -148,  -148,  -148,  -148,   109,  -148,  -148,  -148,
@@ -798,7 +798,7 @@ static const yytype_int16 yypgoto[] =
     -148,   -48,   -38,  -148
 };
 
-  /* YYDEFGOTO[NTERM-NUM].  */
+/* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_uint8 yydefgoto[] =
 {
        0,     1,     2,    43,    81,   115,    76,    45,    83,    46,
@@ -808,9 +808,9 @@ static const yytype_uint8 yydefgoto[] =
       80,    72,    73,   111
 };
 
-  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
-     positive, shift that token.  If negative, reduce the rule whose
-     number is the opposite.  If YYTABLE_NINF, syntax error.  */
+/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
+   positive, shift that token.  If negative, reduce the rule whose
+   number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
       89,   100,    95,    95,   126,   102,   131,    68,    52,    90,
@@ -869,8 +869,8 @@ static const yytype_int16 yycheck[] =
       60
 };
 
-  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
-     symbol of state STATE-NUM.  */
+/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
+   state STATE-NUM.  */
 static const yytype_int8 yystos[] =
 {
        0,    62,    63,     0,     1,     5,     6,     7,     8,     9,
@@ -892,7 +892,7 @@ static const yytype_int8 yystos[] =
       96,   102,    57,    54,    57,    57,    41,    97,    97
 };
 
-  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
+/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
 static const yytype_int8 yyr1[] =
 {
        0,    61,    62,    63,    63,    64,    64,    64,    64,    64,
@@ -910,7 +910,7 @@ static const yytype_int8 yyr1[] =
      101,   102,   102,   103,   104,   104
 };
 
-  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
+/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
 static const yytype_int8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     2,
