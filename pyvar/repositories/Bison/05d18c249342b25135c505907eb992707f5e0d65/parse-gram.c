@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 1.75c.  */
+/* A Bison parser, made by GNU Bison 1.75d.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
@@ -99,14 +99,13 @@
      TYPE = 291,
      EQUAL = 292,
      SEMICOLON = 293,
-     COLON = 294,
-     COMMA = 295,
-     PIPE = 296,
-     ID = 297,
-     PERCENT_PERCENT = 298,
-     PROLOGUE = 299,
-     EPILOGUE = 300,
-     BRACED_CODE = 301
+     PIPE = 294,
+     ID = 295,
+     ID_COLON = 296,
+     PERCENT_PERCENT = 297,
+     PROLOGUE = 298,
+     EPILOGUE = 299,
+     BRACED_CODE = 300
    };
 #endif
 #define GRAM_EOF 0
@@ -146,14 +145,13 @@
 #define TYPE 291
 #define EQUAL 292
 #define SEMICOLON 293
-#define COLON 294
-#define COMMA 295
-#define PIPE 296
-#define ID 297
-#define PERCENT_PERCENT 298
-#define PROLOGUE 299
-#define EPILOGUE 300
-#define BRACED_CODE 301
+#define PIPE 294
+#define ID 295
+#define ID_COLON 296
+#define PERCENT_PERCENT 297
+#define PROLOGUE 298
+#define EPILOGUE 299
+#define BRACED_CODE 300
 
 
 
@@ -162,57 +160,43 @@
 #line 31 "parse-gram.y"
 
 #include "system.h"
+
 #include "complain.h"
-#include "muscle_tab.h"
+#include "conflicts.h"
 #include "files.h"
 #include "getargs.h"
-#include "output.h"
-#include "symlist.h"
 #include "gram.h"
+#include "muscle_tab.h"
+#include "output.h"
 #include "reader.h"
-#include "conflicts.h"
+#include "symlist.h"
 
 /* Produce verbose syntax errors.  */
 #define YYERROR_VERBOSE 1
-#define YYLLOC_DEFAULT(Current, Rhs, N)			\
-do {							\
-  if (N)						\
-  {							\
-    Current.first_column  = Rhs[1].first_column;	\
-    Current.first_line    = Rhs[1].first_line;		\
-    Current.last_column   = Rhs[N].last_column;		\
-    Current.last_line     = Rhs[N].last_line;		\
-  }							\
-  else							\
-  {							\
-    Current = Rhs[0];					\
-  }							\
-} while (0)
 
-/* Pass the control structure to YYPARSE and YYLEX. */
-#define YYPARSE_PARAM gram_control
-#define YYLEX_PARAM gram_control
-/* YYPARSE receives GRAM_CONTROL as a void *.  Provide a
-   correctly typed access to it.  */
-#define yycontrol ((gram_control_t *) gram_control)
+#define YYLLOC_DEFAULT(Current, Rhs, N)  (Current) = lloc_default (Rhs, N)
+static YYLTYPE lloc_default (YYLTYPE const *, int);
 
 /* Request detailed syntax error messages, and pass them to GRAM_ERROR.
-   FIXME: depends on the undocumented availability of YYLLOC.t */
+   FIXME: depends on the undocumented availability of YYLLOC.  */
 #undef  yyerror
 #define yyerror(Msg) \
         gram_error (&yylloc, Msg)
+static void gram_error (location const *, char const *);
 
 #define YYPRINT(File, Type, Value) \
-        yyprint (File, Type, &Value)
-static void yyprint (FILE *file, int type, const yystype *value);
+	print_token_value (File, Type, &Value)
+static void print_token_value (FILE *, int, YYSTYPE const *);
+
+static void add_param (char const *, char const *, location);
 
 symbol_class current_class = unknown_sym;
-struniq_t current_type = 0;
-symbol_t *current_lhs;
-location_t current_lhs_location;
-assoc_t current_assoc;
+uniqstr current_type = 0;
+symbol *current_lhs;
+location current_lhs_location;
+assoc current_assoc;
 int current_prec = 0;
-braced_code_t current_braced_code = action_braced_code;
+braced_code current_braced_code = action_braced_code;
 
 
 /* Enabling traces.  */
@@ -229,17 +213,17 @@ braced_code_t current_braced_code = action_braced_code;
 #endif
 
 #ifndef YYSTYPE
-#line 89 "parse-gram.y"
+#line 75 "parse-gram.y"
 typedef union {
-  symbol_t *symbol;
-  symbol_list_t *list;
+  symbol *symbol;
+  symbol_list *list;
   int integer;
-  char *string;
-  assoc_t assoc;
-  struniq_t struniq;
+  char *chars;
+  assoc assoc;
+  uniqstr uniqstr;
 } yystype;
-/* Line 195 of /usr/local/share/bison/yacc.c.  */
-#line 242 "parse-gram.c"
+/* Line 195 of yacc.c.  */
+#line 226 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -259,8 +243,8 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line __line__ of __file__.  */
-#line 263 "parse-gram.c"
+/* Line 215 of yacc.c.  */
+#line 247 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -307,13 +291,13 @@ union yyalloc
 };
 
 /* The size of the maximum gap between one aligned stack and the next.  */
-# define YYSTACK_GAP_MAX (sizeof (union yyalloc) - 1)
+# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)
 
 /* The size of an array large to enough to hold all stacks, each with
    N elements.  */
 # define YYSTACK_BYTES(N) \
      ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
-      + 2 * YYSTACK_GAP_MAX)
+      + 2 * YYSTACK_GAP_MAXIMUM)
 
 /* Copy COUNT objects from FROM to TO.  The source and destination do
    not overlap.  */
@@ -344,7 +328,7 @@ union yyalloc
 	YYSIZE_T yynewbytes;						\
 	YYCOPY (&yyptr->Stack, Stack, yysize);				\
 	Stack = &yyptr->Stack;						\
-	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAX;	\
+	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
 	yyptr += yynewbytes / sizeof (*yyptr);				\
       }									\
     while (0)
@@ -360,20 +344,20 @@ union yyalloc
 /* YYFINAL -- State number of the termination state. */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   152
+#define YYLAST   153
 
 /* YYNTOKENS -- Number of terminals. */
-#define YYNTOKENS  47
+#define YYNTOKENS  46
 /* YYNNTS -- Number of nonterminals. */
-#define YYNNTS  29
+#define YYNNTS  28
 /* YYNRULES -- Number of rules. */
 #define YYNRULES  77
 /* YYNRULES -- Number of states. */
-#define YYNSTATES  116
+#define YYNSTATES  109
 
 /* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
 #define YYUNDEFTOK  2
-#define YYMAXUTOK   301
+#define YYMAXUTOK   300
 
 #define YYTRANSLATE(YYX) 						\
   ((YYX <= 0) ? YYEOF :							\
@@ -412,7 +396,7 @@ static const unsigned char yytranslate[] =
       15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
       35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46
+      45
 };
 
 #if YYDEBUG
@@ -420,53 +404,52 @@ static const unsigned char yytranslate[] =
    YYRHS.  */
 static const unsigned char yyprhs[] =
 {
-       0,     0,     3,     8,     9,    13,    15,    17,    19,    23,
-      25,    27,    30,    34,    36,    41,    43,    47,    49,    53,
-      58,    60,    63,    65,    67,    69,    71,    73,    76,    79,
-      80,    85,    86,    91,    92,    96,    97,   101,   105,   109,
-     111,   113,   115,   116,   118,   120,   123,   125,   127,   130,
-     133,   137,   139,   142,   144,   147,   149,   152,   155,   156,
-     162,   164,   168,   169,   172,   175,   179,   183,   187,   189,
-     191,   193,   195,   197,   199,   200,   203,   204
+       0,     0,     3,     8,     9,    12,    14,    16,    18,    22,
+      24,    26,    29,    33,    35,    38,    40,    44,    46,    50,
+      53,    55,    58,    60,    62,    64,    66,    68,    70,    73,
+      76,    77,    82,    83,    88,    89,    93,    94,    98,   102,
+     106,   108,   110,   112,   113,   115,   117,   120,   122,   124,
+     127,   130,   134,   136,   139,   141,   144,   146,   148,   151,
+     153,   154,   158,   160,   164,   165,   168,   171,   175,   179,
+     183,   185,   187,   189,   191,   193,   195,   196
 };
 
 /* YYRHS -- A `-1'-separated list of the rules' RHS. */
 static const yysigned_char yyrhs[] =
 {
-      48,     0,    -1,    49,    43,    63,    74,    -1,    -1,    49,
-      50,    75,    -1,    51,    -1,    44,    -1,    17,    -1,    18,
-      72,    72,    -1,    19,    -1,    20,    -1,    21,     4,    -1,
-      22,    37,    72,    -1,    23,    -1,    24,    73,    40,    73,
-      -1,    25,    -1,    26,    37,    72,    -1,    27,    -1,    28,
-      37,    72,    -1,    29,    73,    40,    73,    -1,    30,    -1,
-      31,    72,    -1,    33,    -1,    34,    -1,    35,    -1,    57,
-      -1,    54,    -1,    32,    69,    -1,    10,    46,    -1,    -1,
-       8,    52,    46,    60,    -1,    -1,     9,    53,    46,    60,
-      -1,    -1,     6,    55,    62,    -1,    -1,     5,    56,    62,
-      -1,     7,    36,    60,    -1,    58,    59,    60,    -1,    11,
-      -1,    12,    -1,    13,    -1,    -1,    36,    -1,    69,    -1,
-      60,    69,    -1,    36,    -1,    42,    -1,    42,     4,    -1,
-      42,    71,    -1,    42,     4,    71,    -1,    61,    -1,    62,
-      61,    -1,    64,    -1,    63,    64,    -1,    65,    -1,    51,
-      38,    -1,     1,    38,    -1,    -1,    42,    39,    66,    67,
-      38,    -1,    68,    -1,    67,    41,    68,    -1,    -1,    68,
-      69,    -1,    68,    70,    -1,    68,    14,    69,    -1,    68,
-      15,     4,    -1,    68,    16,    36,    -1,    42,    -1,    71,
-      -1,    46,    -1,     3,    -1,     3,    -1,    46,    -1,    -1,
-      43,    45,    -1,    -1,    38,    -1
+      47,     0,    -1,    48,    42,    62,    73,    -1,    -1,    48,
+      49,    -1,    50,    -1,    43,    -1,    17,    -1,    18,    71,
+      71,    -1,    19,    -1,    20,    -1,    21,     4,    -1,    22,
+      37,    71,    -1,    23,    -1,    24,    72,    -1,    25,    -1,
+      26,    37,    71,    -1,    27,    -1,    28,    37,    71,    -1,
+      29,    72,    -1,    30,    -1,    31,    71,    -1,    33,    -1,
+      34,    -1,    35,    -1,    38,    -1,    56,    -1,    53,    -1,
+      32,    68,    -1,    10,    45,    -1,    -1,     8,    51,    45,
+      59,    -1,    -1,     9,    52,    45,    59,    -1,    -1,     6,
+      54,    61,    -1,    -1,     5,    55,    61,    -1,     7,    36,
+      59,    -1,    57,    58,    59,    -1,    11,    -1,    12,    -1,
+      13,    -1,    -1,    36,    -1,    68,    -1,    59,    68,    -1,
+      36,    -1,    40,    -1,    40,     4,    -1,    40,    70,    -1,
+      40,     4,    70,    -1,    60,    -1,    61,    60,    -1,    63,
+      -1,    62,    63,    -1,    64,    -1,    50,    -1,     1,    38,
+      -1,    38,    -1,    -1,    41,    65,    66,    -1,    67,    -1,
+      66,    39,    67,    -1,    -1,    67,    68,    -1,    67,    69,
+      -1,    67,    14,    68,    -1,    67,    15,     4,    -1,    67,
+      16,    36,    -1,    40,    -1,    70,    -1,    45,    -1,     3,
+      -1,     3,    -1,    45,    -1,    -1,    42,    44,    -1
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   170,   170,   182,   184,   187,   189,   190,   191,   192,
-     193,   194,   195,   196,   197,   202,   203,   204,   205,   206,
-     211,   212,   213,   214,   215,   218,   220,   221,   225,   232,
-     231,   242,   241,   254,   253,   259,   259,   264,   273,   288,
-     290,   291,   294,   296,   301,   303,   307,   312,   317,   323,
-     329,   339,   342,   351,   353,   359,   361,   366,   373,   372,
-     377,   379,   382,   385,   387,   389,   391,   393,   397,   399,
-     402,   408,   417,   426,   434,   436,   443,   445
+       0,   156,   156,   164,   166,   170,   171,   172,   173,   174,
+     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
+     185,   186,   187,   188,   189,   190,   194,   195,   196,   200,
+     207,   206,   217,   216,   229,   229,   234,   234,   239,   249,
+     264,   265,   266,   270,   271,   277,   278,   283,   287,   292,
+     298,   304,   315,   316,   325,   326,   332,   333,   338,   342,
+     346,   346,   350,   351,   356,   357,   359,   361,   363,   365,
+     370,   371,   375,   381,   390,   399,   406,   408
 };
 #endif
 
@@ -484,14 +467,14 @@ static const char *const yytname[] =
   "\"%locations\"", "\"%name-prefix\"", "\"%no-lines\"", "\"%output\"", 
   "\"%parse-param\"", "\"%pure-parser\"", "\"%skeleton\"", "\"%start\"", 
   "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"type\"", "\"=\"", 
-  "\";\"", "\":\"", "\",\"", "\"|\"", "\"identifier\"", "\"%%\"", 
+  "\";\"", "\"|\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", 
   "\"%{...%}\"", "\"epilogue\"", "\"{...}\"", "$accept", "input", 
   "declarations", "declaration", "grammar_declaration", "@1", "@2", 
   "symbol_declaration", "@3", "@4", "precedence_declaration", 
   "precedence_declarator", "type.opt", "symbols.1", "symbol_def", 
   "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules", 
   "@5", "rhses.1", "rhs", "symbol", "action", "string_as_id", 
-  "string_content", "code_content", "epilogue.opt", "semi_colon.opt", 0
+  "string_content", "code_content", "epilogue.opt", 0
 };
 #endif
 
@@ -504,34 +487,34 @@ static const unsigned short yytoknum[] =
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
      275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
-     295,   296,   297,   298,   299,   300,   301
+     295,   296,   297,   298,   299,   300
 };
 # endif
 
 /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const unsigned char yyr1[] =
 {
-       0,    47,    48,    49,    49,    50,    50,    50,    50,    50,
-      50,    50,    50,    50,    50,    50,    50,    50,    50,    50,
-      50,    50,    50,    50,    50,    51,    51,    51,    51,    52,
-      51,    53,    51,    55,    54,    56,    54,    54,    57,    58,
-      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
-      61,    62,    62,    63,    63,    64,    64,    64,    66,    65,
-      67,    67,    68,    68,    68,    68,    68,    68,    69,    69,
-      70,    71,    72,    73,    74,    74,    75,    75
+       0,    46,    47,    48,    48,    49,    49,    49,    49,    49,
+      49,    49,    49,    49,    49,    49,    49,    49,    49,    49,
+      49,    49,    49,    49,    49,    49,    50,    50,    50,    50,
+      51,    50,    52,    50,    54,    53,    55,    53,    53,    56,
+      57,    57,    57,    58,    58,    59,    59,    60,    60,    60,
+      60,    60,    61,    61,    62,    62,    63,    63,    63,    63,
+      65,    64,    66,    66,    67,    67,    67,    67,    67,    67,
+      68,    68,    69,    70,    71,    72,    73,    73
 };
 
 /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
 static const unsigned char yyr2[] =
 {
-       0,     2,     4,     0,     3,     1,     1,     1,     3,     1,
-       1,     2,     3,     1,     4,     1,     3,     1,     3,     4,
-       1,     2,     1,     1,     1,     1,     1,     2,     2,     0,
-       4,     0,     4,     0,     3,     0,     3,     3,     3,     1,
-       1,     1,     0,     1,     1,     2,     1,     1,     2,     2,
-       3,     1,     2,     1,     2,     1,     2,     2,     0,     5,
-       1,     3,     0,     2,     2,     3,     3,     3,     1,     1,
-       1,     1,     1,     1,     0,     2,     0,     1
+       0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
+       1,     2,     3,     1,     2,     1,     3,     1,     3,     2,
+       1,     2,     1,     1,     1,     1,     1,     1,     2,     2,
+       0,     4,     0,     4,     0,     3,     0,     3,     3,     3,
+       1,     1,     1,     0,     1,     1,     2,     1,     1,     2,
+       2,     3,     1,     2,     1,     2,     1,     1,     2,     1,
+       0,     3,     1,     3,     0,     2,     2,     3,     3,     3,
+       1,     1,     1,     1,     1,     1,     0,     2
 };
 
 /* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
@@ -539,116 +522,113 @@ static const unsigned char yyr2[] =
    means the default is an error.  */
 static const unsigned char yydefact[] =
 {
-       3,     0,     0,     1,    35,    33,     0,    29,    31,     0,
-      39,    40,    41,     7,     0,     9,    10,     0,     0,    13,
+       3,     0,     0,     1,    36,    34,     0,    30,    32,     0,
+      40,    41,    42,     7,     0,     9,    10,     0,     0,    13,
        0,    15,     0,    17,     0,     0,    20,     0,     0,    22,
-      23,    24,     0,     6,    76,     5,    26,    25,    42,     0,
-       0,     0,     0,     0,    28,    72,     0,    11,     0,    73,
-       0,     0,     0,     0,    21,    71,    68,    27,    69,     0,
-       0,     0,     0,    53,    55,    77,     4,    43,     0,    46,
-      47,    51,    36,    34,    37,    44,     0,     0,     8,    12,
-       0,    16,    18,     0,    57,    58,    56,     0,    54,     2,
-      38,    48,    49,    52,    45,    30,    32,    14,    19,    62,
-      75,    50,     0,    60,    59,    62,     0,     0,     0,    70,
-      63,    64,    61,    65,    66,    67
+      23,    24,    25,     0,     6,     4,     5,    27,    26,    43,
+       0,     0,     0,     0,     0,    29,    74,     0,    11,     0,
+      75,    14,     0,     0,    19,    21,    73,    70,    28,    71,
+       0,    59,    60,    57,     0,    54,    56,    44,     0,    47,
+      48,    52,    37,    35,    38,    45,     0,     0,     8,    12,
+      16,    18,    58,    64,     0,    55,     2,    39,    49,    50,
+      53,    46,    31,    33,    61,    62,    77,    51,    64,     0,
+       0,     0,    72,    65,    66,    63,    67,    68,    69
 };
 
 /* YYDEFGOTO[NTERM-NUM]. */
 static const yysigned_char yydefgoto[] =
 {
-      -1,     1,     2,    34,    61,    42,    43,    36,    40,    39,
-      37,    38,    68,    74,    71,    72,    62,    63,    64,    99,
-     102,   103,    75,   111,    58,    46,    50,    89,    66
+      -1,     1,     2,    35,    63,    43,    44,    37,    41,    40,
+      38,    39,    68,    74,    71,    72,    64,    65,    66,    83,
+      94,    95,    75,   104,    59,    47,    51,    86
 };
 
 /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    STATE-NUM.  */
-#define YYPACT_NINF -66
+#define YYPACT_NINF -67
 static const yysigned_char yypact[] =
 {
-     -66,     6,   108,   -66,   -66,   -66,   -16,   -66,   -66,   -21,
-     -66,   -66,   -66,   -66,    19,   -66,   -66,    32,     5,   -66,
-       3,   -66,    10,   -66,    11,     3,   -66,    19,     1,   -66,
-     -66,   -66,    80,   -66,    12,   -66,   -66,   -66,    16,   -19,
-     -19,     1,     7,     8,   -66,   -66,    19,   -66,    19,   -66,
-      18,    19,    19,    20,   -66,   -66,   -66,   -66,   -66,    13,
-      24,    17,     2,   -66,   -66,   -66,   -66,   -66,     1,   -66,
-      29,   -66,   -19,   -19,     1,   -66,     1,     1,   -66,   -66,
-       3,   -66,   -66,     3,   -66,   -66,   -66,    21,   -66,   -66,
-       1,    61,   -66,   -66,   -66,     1,     1,   -66,   -66,   -66,
-     -66,   -66,   -17,    15,   -66,   -66,     1,    65,    34,   -66,
-     -66,   -66,    15,   -66,   -66,   -66
+     -67,     5,   110,   -67,   -67,   -67,   -17,   -67,   -67,   -14,
+     -67,   -67,   -67,   -67,    29,   -67,   -67,    30,    -1,   -67,
+     -10,   -67,     4,   -67,     7,   -10,   -67,    29,     0,   -67,
+     -67,   -67,   -67,    73,   -67,   -67,   -67,   -67,   -67,     2,
+     -20,   -20,     0,    -8,     3,   -67,   -67,    29,   -67,    29,
+     -67,   -67,    29,    29,   -67,   -67,   -67,   -67,   -67,   -67,
+      11,   -67,   -67,   -67,     1,   -67,   -67,   -67,     0,   -67,
+      14,   -67,   -20,   -20,     0,   -67,     0,     0,   -67,   -67,
+     -67,   -67,   -67,   -67,     9,   -67,   -67,     0,    51,   -67,
+     -67,   -67,     0,     0,    16,    12,   -67,   -67,   -67,     0,
+      52,    22,   -67,   -67,   -67,    12,   -67,   -67,   -67
 };
 
 /* YYPGOTO[NTERM-NUM].  */
 static const yysigned_char yypgoto[] =
 {
-     -66,   -66,   -66,   -66,    63,   -66,   -66,   -66,   -66,   -66,
-     -66,   -66,   -66,   -49,   -34,    31,   -66,    14,   -66,   -66,
-     -66,   -33,   -28,   -66,   -65,   -11,   -24,   -66,   -66
+     -67,   -67,   -67,   -67,    58,   -67,   -67,   -67,   -67,   -67,
+     -67,   -67,   -67,   -47,   -49,    20,   -67,     6,   -67,   -67,
+     -67,   -36,   -28,   -67,   -66,    -2,    38,   -67
 };
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
    number is the opposite.  If zero, do what YYDEFACT says.
    If YYTABLE_NINF, syntax error.  */
-#define YYTABLE_NINF -75
+#define YYTABLE_NINF -77
 static const yysigned_char yytable[] =
 {
-      57,    53,   -74,    59,    55,    92,     3,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,    54,    69,    55,    90,
-      41,   104,    45,    70,   105,    44,   101,    95,    96,   106,
-     107,   108,    55,    91,    28,    78,    47,    79,    93,    93,
-      81,    82,    48,    56,    60,    87,    94,    51,    52,    49,
-      65,    84,    67,    76,    77,    86,    97,    56,    80,    98,
-      83,   109,    94,    85,    55,    35,   100,    94,    94,   114,
-     115,    73,   112,     0,     0,   110,    88,     0,   113,     0,
-       0,    59,     0,     0,   110,     4,     5,     6,     7,     8,
-       9,    10,    11,    12,     0,     0,     0,     0,     0,     0,
+      58,   -76,    60,    56,    89,     3,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    56,    69,    56,    88,    42,
+      70,    87,    97,    90,    90,    55,    99,   100,   101,    92,
+      93,    45,    46,    28,    48,    50,    49,    76,    67,    61,
+      57,    52,    62,    84,    53,    78,    91,    79,    77,    82,
+      80,    81,    57,    96,    56,    98,   107,   102,   108,    91,
+      36,    73,   105,    54,    91,    91,     0,   103,     0,     0,
+      85,   106,     0,     0,    60,     0,     0,   103,     4,     5,
+       6,     7,     8,     9,    10,    11,    12,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
-       0,     0,    28,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    60,     0,     0,    13,    14,    15,    16,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    31,     0,     0,     0,     0,     0,     0,
-       0,    32,    33
+       0,     0,     0,     0,     0,    28,     0,     0,     0,     0,
+       0,    61,     0,     0,    62,     4,     5,     6,     7,     8,
+       9,    10,    11,    12,     0,     0,     0,    13,    14,    15,
+      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
+      26,    27,    28,    29,    30,    31,     0,     0,    32,     0,
+       0,     0,    33,    34
 };
 
 static const yysigned_char yycheck[] =
 {
-      28,    25,     0,     1,     3,    70,     0,     5,     6,     7,
-       8,     9,    10,    11,    12,    13,    27,    36,     3,    68,
-      36,    38,     3,    42,    41,    46,    91,    76,    77,    14,
-      15,    16,     3,     4,    32,    46,     4,    48,    72,    73,
-      51,    52,    37,    42,    42,    43,    74,    37,    37,    46,
-      38,    38,    36,    46,    46,    38,    80,    42,    40,    83,
-      40,    46,    90,    39,     3,     2,    45,    95,    96,     4,
-      36,    40,   105,    -1,    -1,   103,    62,    -1,   106,    -1,
-      -1,     1,    -1,    -1,   112,     5,     6,     7,     8,     9,
-      10,    11,    12,    13,    -1,    -1,    -1,    -1,    -1,    -1,
+      28,     0,     1,     3,    70,     0,     5,     6,     7,     8,
+       9,    10,    11,    12,    13,     3,    36,     3,     4,    36,
+      40,    68,    88,    72,    73,    27,    14,    15,    16,    76,
+      77,    45,     3,    32,     4,    45,    37,    45,    36,    38,
+      40,    37,    41,    42,    37,    47,    74,    49,    45,    38,
+      52,    53,    40,    44,     3,    39,     4,    45,    36,    87,
+       2,    41,    98,    25,    92,    93,    -1,    95,    -1,    -1,
+      64,    99,    -1,    -1,     1,    -1,    -1,   105,     5,     6,
+       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    -1,
       -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    -1,    32,     5,     6,     7,     8,     9,    10,    11,
-      12,    13,    42,    -1,    -1,    17,    18,    19,    20,    21,
-      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
-      32,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
-      -1,    43,    44
+      -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    -1,    -1,
+      -1,    38,    -1,    -1,    41,     5,     6,     7,     8,     9,
+      10,    11,    12,    13,    -1,    -1,    -1,    17,    18,    19,
+      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
+      30,    31,    32,    33,    34,    35,    -1,    -1,    38,    -1,
+      -1,    -1,    42,    43
 };
 
 /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
    symbol of state STATE-NUM.  */
 static const unsigned char yystos[] =
 {
-       0,    48,    49,     0,     5,     6,     7,     8,     9,    10,
+       0,    47,    48,     0,     5,     6,     7,     8,     9,    10,
       11,    12,    13,    17,    18,    19,    20,    21,    22,    23,
       24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
-      34,    35,    43,    44,    50,    51,    54,    57,    58,    56,
-      55,    36,    52,    53,    46,     3,    72,     4,    37,    46,
-      73,    37,    37,    73,    72,     3,    42,    69,    71,     1,
-      42,    51,    63,    64,    65,    38,    75,    36,    59,    36,
-      42,    61,    62,    62,    60,    69,    46,    46,    72,    72,
-      40,    72,    72,    40,    38,    39,    38,    43,    64,    74,
-      60,     4,    71,    61,    69,    60,    60,    73,    73,    66,
-      45,    71,    67,    68,    38,    41,    14,    15,    16,    46,
-      69,    70,    68,    69,     4,    36
+      34,    35,    38,    42,    43,    49,    50,    53,    56,    57,
+      55,    54,    36,    51,    52,    45,     3,    71,     4,    37,
+      45,    72,    37,    37,    72,    71,     3,    40,    68,    70,
+       1,    38,    41,    50,    62,    63,    64,    36,    58,    36,
+      40,    60,    61,    61,    59,    68,    45,    45,    71,    71,
+      71,    71,    38,    65,    42,    63,    73,    59,     4,    70,
+      60,    68,    59,    59,    66,    67,    44,    70,    39,    14,
+      15,    16,    45,    68,    69,    67,    68,     4,    36
 };
 
 #if ! defined (YYSIZE_T) && defined (__SIZE_TYPE__)
@@ -736,11 +716,13 @@ do {						\
   if (yydebug)					\
     YYFPRINTF Args;				\
 } while (0)
+
 # define YYDSYMPRINT(Args)			\
 do {						\
   if (yydebug)					\
     yysymprint Args;				\
 } while (0)
+
 # define YYDSYMPRINTF(Title, Token, Value, Location)		\
 do {								\
   if (yydebug)							\
@@ -752,6 +734,63 @@ do {								\
     }								\
 } while (0)
 
+/*------------------------------------------------------------------.
+| yy_stack_print -- Print the state stack from its BOTTOM up to its |
+| TOP (cinluded).                                                   |
+`------------------------------------------------------------------*/
+
+#if defined (__STDC__) || defined (__cplusplus)
+static void
+yy_stack_print (short *bottom, short *top)
+#else
+static void
+yy_stack_print (bottom, top)
+    short *bottom;
+    short *top;
+#endif
+{
+  YYFPRINTF (stderr, "Stack now");
+  for (/* Nothing. */; bottom <= top; ++bottom)
+    YYFPRINTF (stderr, " %d", *bottom);
+  YYFPRINTF (stderr, "\n");
+}
+
+# define YY_STACK_PRINT(Bottom, Top)				\
+do {								\
+  if (yydebug)							\
+    yy_stack_print ((Bottom), (Top));				\
+} while (0)
+
+
+/*------------------------------------------------.
+| Report that the YYRULE is going to be reduced.  |
+`------------------------------------------------*/
+
+#if defined (__STDC__) || defined (__cplusplus)
+static void
+yy_reduce_print (int yyrule)
+#else
+static void
+yy_reduce_print (yyrule)
+    int yyrule;
+#endif
+{
+  int yyi;
+  unsigned int yylineno = yyrline[yyrule];
+  YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
+             yyrule - 1, yylineno);
+  /* Print the symbols being reduced, and their result.  */
+  for (yyi = yyprhs[yyrule]; 0 <= yyrhs[yyi]; yyi++)
+    YYFPRINTF (stderr, "%s ", yytname [yyrhs[yyi]]);
+  YYFPRINTF (stderr, "-> %s\n", yytname [yyr1[yyrule]]);
+}
+
+# define YY_REDUCE_PRINT(Rule)		\
+do {					\
+  if (yydebug)				\
+    yy_reduce_print (Rule);		\
+} while (0)
+
 /* Nonzero means print parse trace.  It is left uninitialized so that
    multiple parsers can coexist.  */
 int yydebug;
@@ -759,8 +798,11 @@ int yydebug;
 # define YYDPRINTF(Args)
 # define YYDSYMPRINT(Args)
 # define YYDSYMPRINTF(Title, Token, Value, Location)
+# define YY_STACK_PRINT(Bottom, Top)
+# define YY_REDUCE_PRINT(Rule)
 #endif /* !YYDEBUG */
 
+
 /* YYINITDEPTH -- initial size of the parser's stacks.  */
 #ifndef	YYINITDEPTH
 # define YYINITDEPTH 200
@@ -839,17 +881,17 @@ yystpcpy (yydest, yysrc)
 
 
 #if YYDEBUG
-/*-----------------------------.
-| Print this symbol on YYOUT.  |
-`-----------------------------*/
+/*--------------------------------.
+| Print this symbol on YYOUTPUT.  |
+`--------------------------------*/
 
 #if defined (__STDC__) || defined (__cplusplus)
 static void
-yysymprint (FILE *yyout, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
+yysymprint (FILE *yyoutput, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 #else
 static void
-yysymprint (yyout, yytype, yyvaluep, yylocationp)
-    FILE *yyout;
+yysymprint (yyoutput, yytype, yyvaluep, yylocationp)
+    FILE *yyoutput;
     int yytype;
     YYSTYPE *yyvaluep;
     YYLTYPE *yylocationp;
@@ -861,23 +903,23 @@ yysymprint (yyout, yytype, yyvaluep, yylocationp)
 
   if (yytype < YYNTOKENS)
     {
-      YYFPRINTF (yyout, "token %s (", yytname[yytype]);
+      YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
 # ifdef YYPRINT
-      YYPRINT (yyout, yytoknum[yytype], *yyvaluep);
+      YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
 # endif
     }
   else
-    YYFPRINTF (yyout, "nterm %s (", yytname[yytype]);
+    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);
 
   switch (yytype)
     {
       default:
         break;
     }
-  YYFPRINTF (yyout, ")");
+  YYFPRINTF (yyoutput, ")");
 }
 
-#endif /* YYDEBUG. */
+#endif /* ! YYDEBUG */
 /*-----------------------------------------------.
 | Release the memory associated to this symbol.  |
 `-----------------------------------------------*/
@@ -920,7 +962,7 @@ int yyparse (void);
 #else
 int yyparse ();
 #endif
-#endif
+#endif /* ! YYPARSE_PARAM */
 
 
 
@@ -1133,8 +1175,6 @@ yybackup:
     }
   else
     {
-      /* We have to keep this `#if YYDEBUG', since we use variables
-	 which are defined only if `YYDEBUG' is set.  */
       YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
     }
 
@@ -1203,221 +1243,192 @@ yyreduce:
 
   /* Default location. */
   YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
-
-#if YYDEBUG
-  /* We have to keep this `#if YYDEBUG', since we use variables which
-     are defined only if `YYDEBUG' is set.  */
-  if (yydebug)
-    {
-      int yyi;
-
-      YYFPRINTF (stderr, "Reducing by rule %d (line %d), ",
-		 yyn - 1, yyrline[yyn]);
-
-      /* Print the symbols being reduced, and their result.  */
-      for (yyi = yyprhs[yyn]; 0 <= yyrhs[yyi]; yyi++)
-	YYFPRINTF (stderr, "%s ", yytname[yyrhs[yyi]]);
-      YYFPRINTF (stderr, "-> %s\n", yytname[yyr1[yyn]]);
-    }
-#endif
+  YY_REDUCE_PRINT (yyn);
   switch (yyn)
     {
-        case 2:
-#line 172 "parse-gram.y"
-    {
-      yycontrol->errcode = 0;
-    }
-    break;
-
-  case 6:
-#line 189 "parse-gram.y"
-    { prologue_augment (yyvsp[0].string, yylsp[0]); }
+        case 6:
+#line 171 "parse-gram.y"
+    { prologue_augment (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 7:
-#line 190 "parse-gram.y"
+#line 172 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 191 "parse-gram.y"
-    { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
+#line 173 "parse-gram.y"
+    { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
     break;
 
   case 9:
-#line 192 "parse-gram.y"
+#line 174 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 193 "parse-gram.y"
+#line 175 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 194 "parse-gram.y"
+#line 176 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 195 "parse-gram.y"
-    { spec_file_prefix = yyvsp[0].string; }
+#line 177 "parse-gram.y"
+    { spec_file_prefix = yyvsp[0].chars; }
     break;
 
   case 13:
-#line 196 "parse-gram.y"
+#line 178 "parse-gram.y"
     { glr_parser = 1; }
     break;
 
   case 14:
-#line 198 "parse-gram.y"
-    {
-			     muscle_pair_list_grow ("lex_param", yyvsp[-2].string, yyvsp[0].string);
-			     scanner_last_string_free ();
-			   }
+#line 179 "parse-gram.y"
+    { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 15:
-#line 202 "parse-gram.y"
+#line 180 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 16:
-#line 203 "parse-gram.y"
-    { spec_name_prefix = yyvsp[0].string; }
+#line 181 "parse-gram.y"
+    { spec_name_prefix = yyvsp[0].chars; }
     break;
 
   case 17:
-#line 204 "parse-gram.y"
+#line 182 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 18:
-#line 205 "parse-gram.y"
-    { spec_outfile = yyvsp[0].string; }
+#line 183 "parse-gram.y"
+    { spec_outfile = yyvsp[0].chars; }
     break;
 
   case 19:
-#line 207 "parse-gram.y"
-    {
-			     muscle_pair_list_grow ("parse_param", yyvsp[-2].string, yyvsp[0].string);
-			     scanner_last_string_free ();
-			   }
+#line 184 "parse-gram.y"
+    { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 20:
-#line 211 "parse-gram.y"
+#line 185 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 21:
-#line 212 "parse-gram.y"
-    { skeleton = yyvsp[0].string; }
+#line 186 "parse-gram.y"
+    { skeleton = yyvsp[0].chars; }
     break;
 
   case 22:
-#line 213 "parse-gram.y"
+#line 187 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 23:
-#line 214 "parse-gram.y"
+#line 188 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 24:
-#line 215 "parse-gram.y"
+#line 189 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
-  case 27:
-#line 222 "parse-gram.y"
+  case 28:
+#line 197 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
-  case 28:
-#line 226 "parse-gram.y"
+  case 29:
+#line 201 "parse-gram.y"
     {
       typed = 1;
-      MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
-      muscle_insert ("stype", yyvsp[0].string);
+      MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
+      muscle_insert ("stype", yyvsp[0].chars);
     }
     break;
 
-  case 29:
-#line 232 "parse-gram.y"
+  case 30:
+#line 207 "parse-gram.y"
     { current_braced_code = destructor_braced_code; }
     break;
 
-  case 30:
-#line 234 "parse-gram.y"
+  case 31:
+#line 209 "parse-gram.y"
     {
-      symbol_list_t *list;
+      symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
-	symbol_destructor_set (list->sym, yyvsp[-1].string, yylsp[-1]);
+	symbol_destructor_set (list->sym, yyvsp[-1].chars, yylsp[-1]);
       symbol_list_free (yyvsp[0].list);
       current_braced_code = action_braced_code;
     }
     break;
 
-  case 31:
-#line 242 "parse-gram.y"
+  case 32:
+#line 217 "parse-gram.y"
     { current_braced_code = printer_braced_code; }
     break;
 
-  case 32:
-#line 244 "parse-gram.y"
+  case 33:
+#line 219 "parse-gram.y"
     {
-      symbol_list_t *list;
+      symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
-	symbol_printer_set (list->sym, yyvsp[-1].string, list->location);
+	symbol_printer_set (list->sym, yyvsp[-1].chars, list->location);
       symbol_list_free (yyvsp[0].list);
       current_braced_code = action_braced_code;
     }
     break;
 
-  case 33:
-#line 254 "parse-gram.y"
+  case 34:
+#line 229 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
-  case 34:
-#line 255 "parse-gram.y"
+  case 35:
+#line 230 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 35:
-#line 259 "parse-gram.y"
+  case 36:
+#line 234 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
-  case 36:
-#line 260 "parse-gram.y"
+  case 37:
+#line 235 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
     break;
 
-  case 37:
-#line 265 "parse-gram.y"
+  case 38:
+#line 240 "parse-gram.y"
     {
-      symbol_list_t *list;
+      symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
-	symbol_type_set (list->sym, yyvsp[-1].struniq, yylsp[-1]);
+	symbol_type_set (list->sym, yyvsp[-1].uniqstr, yylsp[-1]);
       symbol_list_free (yyvsp[0].list);
     }
     break;
 
-  case 38:
-#line 275 "parse-gram.y"
+  case 39:
+#line 250 "parse-gram.y"
     {
-      symbol_list_t *list;
+      symbol_list *list;
       ++current_prec;
       for (list = yyvsp[0].list; list; list = list->next)
 	{
@@ -1429,58 +1440,58 @@ yyreduce:
     }
     break;
 
-  case 39:
-#line 289 "parse-gram.y"
+  case 40:
+#line 264 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
-  case 40:
-#line 290 "parse-gram.y"
+  case 41:
+#line 265 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
-  case 41:
-#line 291 "parse-gram.y"
+  case 42:
+#line 266 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
-  case 42:
-#line 295 "parse-gram.y"
+  case 43:
+#line 270 "parse-gram.y"
     { current_type = NULL; }
     break;
 
-  case 43:
-#line 296 "parse-gram.y"
-    { current_type = yyvsp[0].struniq; }
+  case 44:
+#line 271 "parse-gram.y"
+    { current_type = yyvsp[0].uniqstr; }
     break;
 
-  case 44:
-#line 302 "parse-gram.y"
+  case 45:
+#line 277 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 45:
-#line 303 "parse-gram.y"
+  case 46:
+#line 278 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 46:
-#line 309 "parse-gram.y"
+  case 47:
+#line 284 "parse-gram.y"
     {
-       current_type = yyvsp[0].struniq;
+       current_type = yyvsp[0].uniqstr;
      }
     break;
 
-  case 47:
-#line 313 "parse-gram.y"
+  case 48:
+#line 288 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
      }
     break;
 
-  case 48:
-#line 318 "parse-gram.y"
+  case 49:
+#line 293 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1488,8 +1499,8 @@ yyreduce:
     }
     break;
 
-  case 49:
-#line 324 "parse-gram.y"
+  case 50:
+#line 299 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1497,8 +1508,8 @@ yyreduce:
     }
     break;
 
-  case 50:
-#line 330 "parse-gram.y"
+  case 51:
+#line 305 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1507,124 +1518,109 @@ yyreduce:
     }
     break;
 
-  case 51:
-#line 341 "parse-gram.y"
-    {;}
-    break;
-
-  case 52:
-#line 343 "parse-gram.y"
-    {;}
-    break;
-
-  case 56:
-#line 362 "parse-gram.y"
+  case 57:
+#line 334 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
     }
     break;
 
-  case 57:
-#line 367 "parse-gram.y"
+  case 58:
+#line 339 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
-  case 58:
-#line 373 "parse-gram.y"
-    { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
-    break;
-
-  case 59:
-#line 374 "parse-gram.y"
-    {;}
+  case 60:
+#line 346 "parse-gram.y"
+    { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
-  case 60:
-#line 378 "parse-gram.y"
+  case 62:
+#line 350 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 61:
-#line 379 "parse-gram.y"
+  case 63:
+#line 351 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
-  case 62:
-#line 384 "parse-gram.y"
+  case 64:
+#line 356 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
-  case 63:
-#line 386 "parse-gram.y"
+  case 65:
+#line 358 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 64:
-#line 388 "parse-gram.y"
-    { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
+  case 66:
+#line 360 "parse-gram.y"
+    { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
     break;
 
-  case 65:
-#line 390 "parse-gram.y"
+  case 67:
+#line 362 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
-  case 66:
-#line 392 "parse-gram.y"
+  case 68:
+#line 364 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
-  case 67:
-#line 394 "parse-gram.y"
-    { grammar_current_rule_merge_set (yyvsp[0].struniq, yylsp[0]); }
+  case 69:
+#line 366 "parse-gram.y"
+    { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
     break;
 
-  case 68:
-#line 398 "parse-gram.y"
+  case 70:
+#line 370 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 69:
-#line 399 "parse-gram.y"
+  case 71:
+#line 371 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
-  case 70:
-#line 404 "parse-gram.y"
-    { yyval.string = yyvsp[0].string; }
+  case 72:
+#line 376 "parse-gram.y"
+    { yyval.chars = yyvsp[0].chars; }
     break;
 
-  case 71:
-#line 410 "parse-gram.y"
+  case 73:
+#line 382 "parse-gram.y"
     {
-      yyval.symbol = symbol_get (yyvsp[0].string, yylsp[0]);
+      yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
     }
     break;
 
-  case 72:
-#line 419 "parse-gram.y"
+  case 74:
+#line 391 "parse-gram.y"
     {
-      yyval.string = yyvsp[0].string + 1;
-      yyval.string[strlen (yyval.string) - 1] = '\0';
+      yyval.chars = yyvsp[0].chars + 1;
+      yyval.chars[strlen (yyval.chars) - 1] = '\0';
     }
     break;
 
-  case 73:
-#line 428 "parse-gram.y"
+  case 75:
+#line 400 "parse-gram.y"
     {
-      yyval.string = yyvsp[0].string + 1;
-      yyval.string[strlen (yyval.string) - 1] = '\0';
+      yyval.chars = yyvsp[0].chars + 1;
+      yyval.chars[strlen (yyval.chars) - 1] = '\0';
     }
     break;
 
-  case 75:
-#line 437 "parse-gram.y"
+  case 77:
+#line 409 "parse-gram.y"
     {
-      epilogue_augment (yyvsp[0].string, yylsp[0]);
+      epilogue_augment (yyvsp[0].chars, yylsp[0]);
       scanner_last_string_free ();
     }
     break;
@@ -1632,23 +1628,14 @@ yyreduce:
 
     }
 
-/* Line 959 of /usr/local/share/bison/yacc.c.  */
-#line 1636 "parse-gram.c"
+/* Line 991 of yacc.c.  */
+#line 1632 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
   yylsp -= yylen;
 
-#if YYDEBUG
-  if (yydebug)
-    {
-      short *yyssp1 = yyss - 1;
-      YYFPRINTF (stderr, "state stack now");
-      while (yyssp1 != yyssp)
-	YYFPRINTF (stderr, " %d", *++yyssp1);
-      YYFPRINTF (stderr, "\n");
-    }
-#endif
+  YY_STACK_PRINT (yyss, yyssp);
 
   *++yyvsp = yyval;
   *++yylsp = yyloc;
@@ -1725,13 +1712,7 @@ yyerrlab:
 #endif /* YYERROR_VERBOSE */
 	yyerror ("syntax error");
     }
-  goto yyerrlab1;
 
-
-/*----------------------------------------------------.
-| yyerrlab1 -- error raised explicitly by an action.  |
-`----------------------------------------------------*/
-yyerrlab1:
   if (yyerrstatus == 3)
     {
       /* If just tried and failed to reuse lookahead token after an
@@ -1759,7 +1740,13 @@ yyerrlab1:
 
   /* Else will try to reuse lookahead token after shifting the error
      token.  */
+  goto yyerrlab1;
 
+
+/*----------------------------------------------------.
+| yyerrlab1 -- error raised explicitly by an action.  |
+`----------------------------------------------------*/
+yyerrlab1:
   yyerrstatus = 3;	/* Each real token shifted decrements this.  */
 
   for (;;)
@@ -1785,17 +1772,7 @@ yyerrlab1:
       yyvsp--;
       yystate = *--yyssp;
       yylsp--;
-
-#if YYDEBUG
-      if (yydebug)
-	{
-	  short *yyssp1 = yyss - 1;
-	  YYFPRINTF (stderr, "Error: state stack now");
-	  while (yyssp1 != yyssp)
-	    YYFPRINTF (stderr, " %d", *++yyssp1);
-	  YYFPRINTF (stderr, "\n");
-	}
-#endif
+      YY_STACK_PRINT (yyss, yyssp);
     }
 
   if (yyn == YYFINAL)
@@ -1843,15 +1820,87 @@ yyreturn:
 }
 
 
-#line 447 "parse-gram.y"
+#line 415 "parse-gram.y"
+
+
+
+/* Return the location of the left-hand side of a rule whose
+   right-hand side is RHS[1] ... RHS[N].  Ignore empty nonterminals in
+   the right-hand side, and return an empty location equal to the end
+   boundary of RHS[0] if the right-hand side is empty.  */
+
+static YYLTYPE
+lloc_default (YYLTYPE const *rhs, int n)
+{
+  int i;
+  int j;
+  YYLTYPE r;
+  r.start = r.end = rhs[n].end;
+
+  for (i = 1; i <= n; i++)
+    if (! equal_boundaries (rhs[i].start, rhs[i].end))
+      {
+	r.start = rhs[i].start;
+
+	for (j = n; i < j; j--)
+	  if (! equal_boundaries (rhs[j].start, rhs[j].end))
+	    break;
+	r.end = rhs[j].end;
+
+	break;
+      }
+
+  return r;
+}
+
+
+/* Add a lex-param or a parse-param (depending on TYPE) with
+   declaration DECL and location LOC.  */
+
+static void
+add_param (char const *type, char const *decl, location loc)
+{
+  static char const alphanum[] =
+    "0123456789"
+    "abcdefghijklmnopqrstuvwxyz"
+    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
+    "_";
+  char const *alpha = alphanum + 10;
+  char const *name_start = NULL;
+  char const *p;
+
+  for (p = decl; *p; p++)
+    if ((p == decl || ! strchr (alphanum, p[-1])) && strchr (alpha, p[0]))
+      name_start = p;
+
+  if (! name_start)
+    complain_at (loc, _("missing identifier in parameter declaration"));
+  else
+    {
+      char *name;
+      size_t name_len;
+
+      for (name_len = 1;
+	   name_start[name_len] && strchr (alphanum, name_start[name_len]);
+	   name_len++)
+	continue;
+
+      name = xmalloc (name_len + 1);
+      memcpy (name, name_start, name_len);
+      name[name_len] = '\0';
+      muscle_pair_list_grow (type, decl, name);
+      free (name);
+    }
+
+  scanner_last_string_free ();
+}
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
 `------------------------------------------------------------------*/
 
 static void
-yyprint (FILE *file,
-         int type, const yystype *value)
+print_token_value (FILE *file, int type, YYSTYPE const *value)
 {
   fputc (' ', file);
   switch (type)
@@ -1865,17 +1914,17 @@ yyprint (FILE *file,
       break;
 
     case STRING:
-      fprintf (file, " = \"%s\"", value->string);
+      fprintf (file, " = \"%s\"", value->chars);
       break;
 
     case TYPE:
-      fprintf (file, " = <%s>", value->struniq);
+      fprintf (file, " = <%s>", value->uniqstr);
       break;
 
     case BRACED_CODE:
     case PROLOGUE:
     case EPILOGUE:
-      fprintf (file, " = {{ %s }}", value->string);
+      fprintf (file, " = {{ %s }}", value->chars);
       break;
 
     default:
@@ -1884,9 +1933,9 @@ yyprint (FILE *file,
     }
 }
 
-void
-gram_error (location_t *yylloc, const char *msg)
+static void
+gram_error (location const *loc, char const *msg)
 {
-  complain_at (*yylloc, "%s", msg);
+  complain_at (*loc, "%s", msg);
 }
 
