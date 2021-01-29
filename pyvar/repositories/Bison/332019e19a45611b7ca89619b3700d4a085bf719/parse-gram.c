@@ -111,9 +111,9 @@ extern int gram_debug;
 /* "%code requires" blocks.  */
 #line 21 "src/parse-gram.y" /* yacc.c:372  */
 
-#include "symlist.h"
-#include "symtab.h"
-#line 209 "src/parse-gram.y" /* yacc.c:372  */
+  #include "symlist.h"
+  #include "symtab.h"
+#line 216 "src/parse-gram.y" /* yacc.c:372  */
 
   typedef enum
   {
@@ -196,25 +196,23 @@ extern int gram_debug;
 typedef union GRAM_STYPE GRAM_STYPE;
 union GRAM_STYPE
 {
-#line 161 "src/parse-gram.y" /* yacc.c:372  */
+#line 177 "src/parse-gram.y" /* yacc.c:372  */
 unsigned char character;
-#line 168 "src/parse-gram.y" /* yacc.c:372  */
-
-  char *code;
-  char const *chars;
-#line 179 "src/parse-gram.y" /* yacc.c:372  */
+#line 181 "src/parse-gram.y" /* yacc.c:372  */
+char *code;
+#line 186 "src/parse-gram.y" /* yacc.c:372  */
 uniqstr uniqstr;
-#line 187 "src/parse-gram.y" /* yacc.c:372  */
+#line 194 "src/parse-gram.y" /* yacc.c:372  */
 int integer;
-#line 191 "src/parse-gram.y" /* yacc.c:372  */
+#line 198 "src/parse-gram.y" /* yacc.c:372  */
 symbol *symbol;
-#line 196 "src/parse-gram.y" /* yacc.c:372  */
+#line 203 "src/parse-gram.y" /* yacc.c:372  */
 assoc assoc;
-#line 199 "src/parse-gram.y" /* yacc.c:372  */
+#line 206 "src/parse-gram.y" /* yacc.c:372  */
 symbol_list *list;
-#line 202 "src/parse-gram.y" /* yacc.c:372  */
+#line 209 "src/parse-gram.y" /* yacc.c:372  */
 named_ref *named_ref;
-#line 229 "src/parse-gram.y" /* yacc.c:372  */
+#line 236 "src/parse-gram.y" /* yacc.c:372  */
 param_type param;
 #line 404 "src/parse-gram.y" /* yacc.c:372  */
 code_props_type code_type;
@@ -226,7 +224,7 @@ code_props_type code_type;
     muscle_kind kind;
   } value;
 
-#line 230 "src/parse-gram.c" /* yacc.c:372  */
+#line 228 "src/parse-gram.c" /* yacc.c:372  */
 };
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
@@ -254,25 +252,25 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 258 "src/parse-gram.c" /* yacc.c:375  */
+#line 256 "src/parse-gram.c" /* yacc.c:375  */
 /* Unqualified %code blocks.  */
 #line 27 "src/parse-gram.y" /* yacc.c:376  */
 
-#include <config.h>
-#include "system.h"
-
-#include "c-ctype.h"
-#include "complain.h"
-#include "conflicts.h"
-#include "files.h"
-#include "getargs.h"
-#include "gram.h"
-#include "named-ref.h"
-#include "quotearg.h"
-#include "reader.h"
-#include "scan-gram.h"
-#include "scan-code.h"
-#include "xmemdup0.h"
+  #include <config.h>
+  #include "system.h"
+
+  #include "c-ctype.h"
+  #include "complain.h"
+  #include "conflicts.h"
+  #include "files.h"
+  #include "getargs.h"
+  #include "gram.h"
+  #include "named-ref.h"
+  #include "quotearg.h"
+  #include "reader.h"
+  #include "scan-gram.h"
+  #include "scan-code.h"
+  #include "xmemdup0.h"
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -293,6 +291,22 @@ int gram_parse (void);
   #define YY_LOCATION_PRINT(File, Loc)            \
     location_print (Loc, File)
 
+  /* Strip initial '{' and final '}' (must be first and last characters).
+     Return the result.  */
+  static char *strip_braces (char *code);
+
+  /* Convert CODE by calling code_props_plain_init if PLAIN, otherwise
+     code_props_symbol_action_init.  Call
+     gram_scanner_last_string_free to release the latest string from
+     the scanner (should be CODE). */
+  static char const *translate_code (char *code, location loc, bool plain);
+
+  /* Convert CODE by calling code_props_plain_init after having
+     stripped the first and last characters (expected to be '{', and
+     '}').  Call gram_scanner_last_string_free to release the latest
+     string from the scanner (should be CODE). */
+  static char const *translate_code_braceless (char *code, location loc);
+
   static void version_check (location const *loc, char const *version);
 
   static void gram_error (location const *, char const *);
@@ -304,7 +318,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 219 "src/parse-gram.y" /* yacc.c:376  */
+#line 226 "src/parse-gram.y" /* yacc.c:376  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -315,7 +329,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 319 "src/parse-gram.c" /* yacc.c:376  */
+#line 333 "src/parse-gram.c" /* yacc.c:376  */
 
 #ifdef short
 # undef short
@@ -498,16 +512,16 @@ union yyalloc
 /* YYFINAL -- State number of the termination state.  */
 #define YYFINAL  3
 /* YYLAST -- Last index in YYTABLE.  */
-#define YYLAST   165
+#define YYLAST   164
 
 /* YYNTOKENS -- Number of terminals.  */
 #define YYNTOKENS  58
 /* YYNNTS -- Number of nonterminals.  */
-#define YYNNTS  38
+#define YYNNTS  37
 /* YYNRULES -- Number of rules.  */
-#define YYNRULES  111
+#define YYNRULES  110
 /* YYNSTATES -- Number of states.  */
-#define YYNSTATES  145
+#define YYNSTATES  144
 
 /* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
    by yylex, with out-of-bounds checking.  */
@@ -559,18 +573,18 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   252,   252,   261,   262,   266,   267,   277,   281,   286,
-     287,   292,   298,   299,   300,   301,   306,   315,   316,   317,
-     318,   319,   320,   320,   321,   322,   346,   347,   348,   349,
-     353,   354,   363,   364,   365,   369,   381,   385,   389,   396,
+       0,   259,   259,   268,   269,   273,   274,   280,   284,   289,
+     290,   295,   301,   302,   303,   304,   309,   314,   315,   316,
+     317,   318,   319,   319,   320,   321,   345,   346,   347,   348,
+     352,   353,   362,   363,   364,   368,   380,   384,   388,   396,
      407,   408,   418,   419,   423,   435,   435,   440,   440,   445,
      456,   471,   472,   473,   474,   478,   479,   484,   486,   491,
      496,   506,   508,   513,   514,   518,   519,   523,   524,   525,
      530,   535,   540,   546,   552,   563,   564,   573,   574,   580,
      581,   582,   589,   589,   597,   598,   599,   604,   607,   609,
      611,   613,   615,   617,   619,   624,   625,   635,   636,   661,
-     662,   663,   664,   673,   693,   695,   704,   709,   710,   715,
-     723,   724
+     662,   663,   664,   676,   678,   687,   692,   693,   698,   706,
+     707
 };
 #endif
 
@@ -600,7 +614,7 @@ static const char *const yytname[] =
   "symbols.1", "generic_symlist", "generic_symlist_item", "tag",
   "symbol_def", "symbol_defs.1", "grammar", "rules_or_grammar_declaration",
   "rules", "$@4", "rhses.1", "rhs", "named_ref.opt", "variable", "value",
-  "braceless", "id", "id_colon", "symbol", "string_as_id", "epilogue.opt", YY_NULL
+  "id", "id_colon", "symbol", "string_as_id", "epilogue.opt", YY_NULL
 };
 #endif
 
@@ -618,12 +632,12 @@ static const yytype_uint16 yytoknum[] =
 };
 # endif
 
-#define YYPACT_NINF -115
+#define YYPACT_NINF -113
 
 #define yypact_value_is_default(Yystate) \
-  (!!((Yystate) == (-115)))
+  (!!((Yystate) == (-113)))
 
-#define YYTABLE_NINF -111
+#define YYTABLE_NINF -110
 
 #define yytable_value_is_error(Yytable_value) \
   0
@@ -632,21 +646,21 @@ static const yytype_uint16 yytoknum[] =
      STATE-NUM.  */
 static const yytype_int8 yypact[] =
 {
-    -115,    16,   109,  -115,  -115,  -115,   -28,  -115,  -115,  -115,
-    -115,  -115,  -115,   -14,  -115,    25,    23,  -115,   -27,   -20,
-    -115,    39,  -115,     7,    48,    71,  -115,  -115,  -115,    72,
-      73,    74,    -2,  -115,  -115,  -115,    56,  -115,  -115,  -115,
-      33,  -115,  -115,    40,  -115,  -115,    37,    54,    54,    -2,
-    -115,    50,  -115,  -115,  -115,     2,  -115,  -115,  -115,  -115,
-    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,
-    -115,  -115,    51,  -115,    53,     3,  -115,  -115,    49,    65,
-    -115,    50,    42,  -115,    -2,  -115,  -115,    54,    -1,    54,
-      -2,  -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,    63,
-    -115,  -115,  -115,  -115,  -115,    69,  -115,  -115,  -115,  -115,
-      42,  -115,  -115,  -115,    -2,  -115,    38,  -115,   106,  -115,
-    -115,  -115,  -115,  -115,  -115,  -115,  -115,  -115,   -15,    41,
-    -115,  -115,    -2,    57,    59,    49,  -115,  -115,    49,    41,
-    -115,  -115,  -115,  -115,  -115
+    -113,    16,   108,  -113,  -113,  -113,   -27,  -113,  -113,  -113,
+    -113,  -113,  -113,   -24,  -113,    23,    24,  -113,   -21,   -15,
+    -113,    29,  -113,     3,    38,    42,  -113,  -113,  -113,    44,
+      47,    71,    31,  -113,  -113,  -113,    55,  -113,  -113,  -113,
+      30,  -113,  -113,    39,  -113,  -113,    26,   -22,   -22,    31,
+    -113,    48,  -113,  -113,     1,  -113,  -113,  -113,  -113,  -113,
+    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,
+    -113,    45,  -113,    50,     2,  -113,  -113,    57,    49,  -113,
+      52,    41,  -113,    31,  -113,  -113,   -22,    -2,   -22,    31,
+    -113,  -113,  -113,  -113,  -113,  -113,  -113,  -113,    46,  -113,
+    -113,  -113,  -113,  -113,    63,  -113,  -113,  -113,  -113,    41,
+    -113,  -113,  -113,    31,  -113,    51,  -113,   100,  -113,  -113,
+    -113,  -113,  -113,  -113,  -113,  -113,  -113,   -20,    40,  -113,
+    -113,    31,    53,    58,    57,  -113,  -113,    57,    40,  -113,
+    -113,  -113,  -113,  -113
 };
 
   /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
@@ -659,34 +673,34 @@ static const yytype_uint8 yydefact[] =
        7,     0,    15,     0,     0,     0,    37,    19,    20,     0,
        0,     0,     0,    26,    27,    28,     0,     6,    29,    22,
       42,     4,     5,     0,    33,    32,    55,     0,     0,     0,
-     103,     0,    38,    98,    97,    99,    10,    12,    13,    14,
-      16,    17,    18,    21,    24,    25,   109,   105,   104,   107,
-      34,   108,     0,   106,     0,     0,    77,    79,    95,     0,
-      43,     0,     0,    56,     0,    70,    75,    48,    71,    46,
-      49,    61,    39,   101,   100,     8,   102,    81,    80,     0,
-      78,     2,    96,    82,    31,    23,    44,    67,    68,    69,
-      35,    63,    66,    65,    50,    57,    59,    76,    72,    73,
-      62,   111,    87,    30,    64,    58,    60,    74,    83,    84,
-      87,    86,     0,     0,     0,    95,    90,    91,    95,    85,
-      92,    93,    94,    89,    88
+      38,     0,    98,    97,    99,    10,    12,    13,    14,    16,
+      17,    18,    21,    24,    25,   108,   104,   103,   106,    34,
+     107,     0,   105,     0,     0,    77,    79,    95,     0,    43,
+       0,     0,    56,     0,    70,    75,    48,    71,    46,    49,
+      61,    39,   101,   102,   100,     8,    81,    80,     0,    78,
+       2,    96,    82,    31,    23,    44,    67,    68,    69,    35,
+      63,    66,    65,    50,    57,    59,    76,    72,    73,    62,
+     110,    87,    30,    64,    58,    60,    74,    83,    84,    87,
+      86,     0,     0,     0,    95,    90,    91,    95,    85,    92,
+      93,    94,    89,    88
 };
 
   /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int8 yypgoto[] =
 {
-    -115,  -115,  -115,  -115,  -115,  -115,   120,  -115,  -115,  -115,
-    -115,  -115,  -115,  -115,  -115,  -115,     9,  -115,  -115,    14,
-    -115,   -50,   100,  -115,    75,  -115,  -115,  -115,    19,  -114,
-    -115,  -115,   -33,   -18,  -115,   -32,   -82,  -115
+    -113,  -113,  -113,  -113,  -113,  -113,   102,  -113,  -113,  -113,
+    -113,  -113,  -113,  -113,  -113,  -113,     8,  -113,  -113,    13,
+    -113,   -50,    75,  -113,    73,  -113,  -113,  -113,    19,  -112,
+    -113,  -113,    22,  -113,   -32,   -82,  -113
 };
 
   /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
-      -1,     1,     2,    41,    79,   105,    74,    43,    81,    44,
-      48,    47,    45,    46,    84,   114,   115,    90,   110,   111,
-     112,    86,    87,    75,    76,    77,   122,   128,   129,   103,
-      55,    95,    52,    69,    78,   113,    71,   101
+      -1,     1,     2,    41,    78,   104,    73,    43,    80,    44,
+      48,    47,    45,    46,    83,   113,   114,    89,   109,   110,
+     111,    85,    86,    74,    75,    76,   121,   127,   128,   102,
+      54,    95,    68,    77,   112,    70,   100
 };
 
   /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
@@ -694,44 +708,44 @@ static const yytype_int16 yydefgoto[] =
      number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
-      70,    66,    66,  -110,    72,    93,   119,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,     3,    91,    92,    13,
-      14,   143,    96,    49,   144,    50,    56,    57,    53,    88,
-      88,    51,    26,   130,    58,   131,   127,   117,    32,   117,
-      67,    50,    59,    68,    66,    66,    60,    94,   106,    73,
-      99,    61,   116,   118,   132,   133,   134,    72,   120,    40,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,    88,
-      54,    88,    13,    14,    62,    63,    64,    65,    80,    82,
-     135,   136,   116,    67,    67,    26,    68,    68,    83,    50,
-     102,    32,   126,   107,   108,   109,    67,   138,   137,    68,
-     140,    97,    73,    98,   104,    85,   121,   138,   123,    66,
-     142,   141,    40,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,    42,   125,   124,    13,    14,    15,    16,    17,
-      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
-      28,    29,    30,    31,    32,    33,    34,    35,    89,   139,
-     100,     0,     0,     0,     0,     0,    36,     0,    37,    38,
-       0,     0,     0,     0,    39,    40
+      69,    65,  -109,    71,    92,   118,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    50,     3,    90,    13,    14,
+      66,    51,   142,    67,    49,   143,    52,    55,   129,    84,
+     130,    26,    58,    56,    65,   126,   116,    32,   116,    57,
+      93,    60,    59,    65,    65,    61,    94,    62,    72,    98,
+      63,   115,   117,   131,   132,   133,    71,   119,    40,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,    53,    87,
+      87,    13,    14,    66,    64,    79,    67,    82,    81,   134,
+     135,   115,    66,    66,    26,    67,    67,    91,   103,   120,
+      32,   105,   106,   107,   108,    96,   137,   136,   101,   139,
+      97,    72,   122,    65,    42,   125,   137,   140,    87,   141,
+      87,    40,     4,     5,     6,     7,     8,     9,    10,    11,
+      12,   124,   123,    88,    13,    14,    15,    16,    17,    18,
+      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
+      29,    30,    31,    32,    33,    34,    35,    99,   138,     0,
+       0,     0,     0,     0,     0,    36,     0,    37,    38,     0,
+       0,     0,     0,    39,    40
 };
 
 static const yytype_int16 yycheck[] =
 {
-      32,     3,     3,     0,     1,     3,    88,     4,     5,     6,
-       7,     8,     9,    10,    11,    12,     0,    49,    51,    16,
-      17,   135,    55,    51,   138,    39,     3,    54,     3,    47,
-      48,    45,    29,    48,    54,    50,   118,    87,    35,    89,
-      42,    39,     3,    45,     3,     3,    39,    45,    81,    46,
-      47,     3,    84,    54,    13,    14,    15,     1,    90,    56,
-       4,     5,     6,     7,     8,     9,    10,    11,    12,    87,
-      45,    89,    16,    17,     3,     3,     3,     3,    45,    39,
-      39,    40,   114,    42,    42,    29,    45,    45,    51,    39,
-      41,    35,    54,    51,    52,    53,    42,   129,    57,    45,
-     132,    50,    46,    50,    39,    51,    43,   139,    39,     3,
-      51,    54,    56,     4,     5,     6,     7,     8,     9,    10,
-      11,    12,     2,   114,   110,    16,    17,    18,    19,    20,
-      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
-      31,    32,    33,    34,    35,    36,    37,    38,    48,   130,
-      75,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
-      -1,    -1,    -1,    -1,    55,    56
+      32,     3,     0,     1,     3,    87,     4,     5,     6,     7,
+       8,     9,    10,    11,    12,    39,     0,    49,    16,    17,
+      42,    45,   134,    45,    51,   137,     3,     3,    48,    51,
+      50,    29,     3,    54,     3,   117,    86,    35,    88,    54,
+      39,     3,    39,     3,     3,     3,    45,     3,    46,    47,
+       3,    83,    54,    13,    14,    15,     1,    89,    56,     4,
+       5,     6,     7,     8,     9,    10,    11,    12,    45,    47,
+      48,    16,    17,    42,     3,    45,    45,    51,    39,    39,
+      40,   113,    42,    42,    29,    45,    45,    39,    39,    43,
+      35,    39,    51,    52,    53,    50,   128,    57,    41,   131,
+      50,    46,    39,     3,     2,    54,   138,    54,    86,    51,
+      88,    56,     4,     5,     6,     7,     8,     9,    10,    11,
+      12,   113,   109,    48,    16,    17,    18,    19,    20,    21,
+      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
+      32,    33,    34,    35,    36,    37,    38,    74,   129,    -1,
+      -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,    -1,
+      -1,    -1,    -1,    55,    56
 };
 
   /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
@@ -743,16 +757,16 @@ static const yytype_uint8 yystos[] =
       23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
       33,    34,    35,    36,    37,    38,    47,    49,    50,    55,
       56,    61,    64,    65,    67,    70,    71,    69,    68,    51,
-      39,    45,    90,     3,    45,    88,     3,    54,    54,     3,
-      39,     3,     3,     3,     3,     3,     3,    42,    45,    91,
-      93,    94,     1,    46,    64,    81,    82,    83,    92,    62,
-      45,    66,    39,    51,    72,    51,    79,    80,    91,    80,
-      75,    93,    90,     3,    45,    89,    90,    50,    50,    47,
-      82,    95,    41,    87,    39,    63,    90,    51,    52,    53,
-      76,    77,    78,    93,    73,    74,    93,    79,    54,    94,
-      93,    43,    84,    39,    77,    74,    54,    94,    85,    86,
-      48,    50,    13,    14,    15,    39,    40,    57,    93,    86,
-      93,    54,    51,    87,    87
+      39,    45,     3,    45,    88,     3,    54,    54,     3,    39,
+       3,     3,     3,     3,     3,     3,    42,    45,    90,    92,
+      93,     1,    46,    64,    81,    82,    83,    91,    62,    45,
+      66,    39,    51,    72,    51,    79,    80,    90,    80,    75,
+      92,    39,     3,    39,    45,    89,    50,    50,    47,    82,
+      94,    41,    87,    39,    63,    39,    51,    52,    53,    76,
+      77,    78,    92,    73,    74,    92,    79,    54,    93,    92,
+      43,    84,    39,    77,    74,    54,    93,    85,    86,    48,
+      50,    13,    14,    15,    39,    40,    57,    92,    86,    92,
+      54,    51,    87,    87
 };
 
   /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
@@ -768,8 +782,8 @@ static const yytype_uint8 yyr1[] =
       79,    79,    79,    79,    79,    80,    80,    81,    81,    82,
       82,    82,    84,    83,    85,    85,    85,    86,    86,    86,
       86,    86,    86,    86,    86,    87,    87,    88,    88,    89,
-      89,    89,    89,    90,    91,    91,    92,    93,    93,    94,
-      95,    95
+      89,    89,    89,    90,    90,    91,    92,    92,    93,    94,
+      94
 };
 
   /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
@@ -785,8 +799,8 @@ static const yytype_uint8 yyr2[] =
        1,     1,     2,     2,     3,     1,     2,     1,     2,     1,
        2,     2,     0,     4,     1,     3,     2,     0,     3,     3,
        2,     2,     3,     3,     3,     0,     1,     1,     1,     0,
-       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
-       0,     2
+       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
+       2
 };
 
 
@@ -942,73 +956,79 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
           case 3: /* "string"  */
-#line 174 "src/parse-gram.y" /* yacc.c:701  */
-      { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-#line 948 "src/parse-gram.c" /* yacc.c:701  */
+#line 183 "src/parse-gram.y" /* yacc.c:701  */
+      { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).code)), yyo); }
+#line 962 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 23: /* "%<flag>"  */
-#line 184 "src/parse-gram.y" /* yacc.c:701  */
+#line 191 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 954 "src/parse-gram.c" /* yacc.c:701  */
+#line 968 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 39: /* "{...}"  */
-#line 176 "src/parse-gram.y" /* yacc.c:701  */
+#line 184 "src/parse-gram.y" /* yacc.c:701  */
+      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
+#line 974 "src/parse-gram.c" /* yacc.c:701  */
+        break;
+
+    case 40: /* "%?{...}"  */
+#line 184 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 960 "src/parse-gram.c" /* yacc.c:701  */
+#line 980 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 41: /* "[identifier]"  */
-#line 182 "src/parse-gram.y" /* yacc.c:701  */
+#line 189 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 966 "src/parse-gram.c" /* yacc.c:701  */
+#line 986 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 42: /* "char"  */
-#line 163 "src/parse-gram.y" /* yacc.c:701  */
+#line 179 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 972 "src/parse-gram.c" /* yacc.c:701  */
+#line 992 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 43: /* "epilogue"  */
-#line 176 "src/parse-gram.y" /* yacc.c:701  */
-      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 978 "src/parse-gram.c" /* yacc.c:701  */
+#line 184 "src/parse-gram.y" /* yacc.c:701  */
+      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
+#line 998 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 45: /* "identifier"  */
-#line 181 "src/parse-gram.y" /* yacc.c:701  */
+#line 188 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 984 "src/parse-gram.c" /* yacc.c:701  */
+#line 1004 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 46: /* "identifier:"  */
-#line 183 "src/parse-gram.y" /* yacc.c:701  */
+#line 190 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 990 "src/parse-gram.c" /* yacc.c:701  */
+#line 1010 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 49: /* "%{...%}"  */
-#line 176 "src/parse-gram.y" /* yacc.c:701  */
-      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 996 "src/parse-gram.c" /* yacc.c:701  */
+#line 184 "src/parse-gram.y" /* yacc.c:701  */
+      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
+#line 1016 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 51: /* "<tag>"  */
-#line 185 "src/parse-gram.y" /* yacc.c:701  */
+#line 192 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1002 "src/parse-gram.c" /* yacc.c:701  */
+#line 1022 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 54: /* "integer"  */
-#line 189 "src/parse-gram.y" /* yacc.c:701  */
+#line 196 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1008 "src/parse-gram.c" /* yacc.c:701  */
+#line 1028 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 55: /* "%param"  */
-#line 232 "src/parse-gram.y" /* yacc.c:701  */
+#line 239 "src/parse-gram.y" /* yacc.c:701  */
       {
   switch (((*yyvaluep).param))
     {
@@ -1021,31 +1041,31 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1025 "src/parse-gram.c" /* yacc.c:701  */
+#line 1045 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 65: /* code_props_type  */
 #line 405 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1031 "src/parse-gram.c" /* yacc.c:701  */
+#line 1051 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 74: /* symbol.prec  */
-#line 193 "src/parse-gram.y" /* yacc.c:701  */
+#line 200 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1037 "src/parse-gram.c" /* yacc.c:701  */
+#line 1057 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 78: /* tag  */
-#line 185 "src/parse-gram.y" /* yacc.c:701  */
+#line 192 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1043 "src/parse-gram.c" /* yacc.c:701  */
+#line 1063 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 88: /* variable  */
-#line 181 "src/parse-gram.y" /* yacc.c:701  */
+#line 188 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1049 "src/parse-gram.c" /* yacc.c:701  */
+#line 1069 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 89: /* value  */
@@ -1058,37 +1078,31 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1062 "src/parse-gram.c" /* yacc.c:701  */
-        break;
-
-    case 90: /* braceless  */
-#line 176 "src/parse-gram.y" /* yacc.c:701  */
-      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1068 "src/parse-gram.c" /* yacc.c:701  */
+#line 1082 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
-    case 91: /* id  */
-#line 193 "src/parse-gram.y" /* yacc.c:701  */
+    case 90: /* id  */
+#line 200 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1074 "src/parse-gram.c" /* yacc.c:701  */
+#line 1088 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
-    case 92: /* id_colon  */
-#line 194 "src/parse-gram.y" /* yacc.c:701  */
+    case 91: /* id_colon  */
+#line 201 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1080 "src/parse-gram.c" /* yacc.c:701  */
+#line 1094 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
-    case 93: /* symbol  */
-#line 193 "src/parse-gram.y" /* yacc.c:701  */
+    case 92: /* symbol  */
+#line 200 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1086 "src/parse-gram.c" /* yacc.c:701  */
+#line 1100 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
-    case 94: /* string_as_id  */
-#line 193 "src/parse-gram.y" /* yacc.c:701  */
+    case 93: /* string_as_id  */
+#line 200 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1092 "src/parse-gram.c" /* yacc.c:701  */
+#line 1106 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
 
@@ -1800,7 +1814,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 87 "src/parse-gram.y" /* yacc.c:1446  */
+#line 103 "src/parse-gram.y" /* yacc.c:1446  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1808,7 +1822,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1812 "src/parse-gram.c" /* yacc.c:1446  */
+#line 1826 "src/parse-gram.c" /* yacc.c:1446  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2002,153 +2016,145 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 268 "src/parse-gram.y" /* yacc.c:1663  */
+#line 275 "src/parse-gram.y" /* yacc.c:1663  */
     {
-      code_props plain_code;
-      code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
-      code_props_translate_code (&plain_code);
-      gram_scanner_last_string_free ();
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
-                        plain_code.code, (yylsp[0]));
+                        translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2016 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2026 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 7:
-#line 278 "src/parse-gram.y" /* yacc.c:1663  */
+#line 281 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2024 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2034 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 8:
-#line 282 "src/parse-gram.y" /* yacc.c:1663  */
+#line 285 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2033 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2043 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 9:
-#line 286 "src/parse-gram.y" /* yacc.c:1663  */
+#line 289 "src/parse-gram.y" /* yacc.c:1663  */
     { defines_flag = true; }
-#line 2039 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2049 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 10:
-#line 288 "src/parse-gram.y" /* yacc.c:1663  */
+#line 291 "src/parse-gram.y" /* yacc.c:1663  */
     {
       defines_flag = true;
-      spec_defines_file = xstrdup ((yyvsp[0].chars));
+      spec_defines_file = xstrdup ((yyvsp[0].code));
     }
-#line 2048 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2058 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 11:
-#line 293 "src/parse-gram.y" /* yacc.c:1663  */
+#line 296 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2058 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2068 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 12:
-#line 298 "src/parse-gram.y" /* yacc.c:1663  */
+#line 301 "src/parse-gram.y" /* yacc.c:1663  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2064 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2074 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 13:
-#line 299 "src/parse-gram.y" /* yacc.c:1663  */
+#line 302 "src/parse-gram.y" /* yacc.c:1663  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2070 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2080 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 14:
-#line 300 "src/parse-gram.y" /* yacc.c:1663  */
-    { spec_file_prefix = (yyvsp[0].chars); }
-#line 2076 "src/parse-gram.c" /* yacc.c:1663  */
+#line 303 "src/parse-gram.y" /* yacc.c:1663  */
+    { spec_file_prefix = (yyvsp[0].code); }
+#line 2086 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 15:
-#line 302 "src/parse-gram.y" /* yacc.c:1663  */
+#line 305 "src/parse-gram.y" /* yacc.c:1663  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2085 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2095 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 16:
-#line 307 "src/parse-gram.y" /* yacc.c:1663  */
+#line 310 "src/parse-gram.y" /* yacc.c:1663  */
     {
-      code_props action;
-      code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
-      code_props_translate_code (&action);
-      gram_scanner_last_string_free ();
-      muscle_code_grow ("initial_action", action.code, (yylsp[0]));
+      muscle_code_grow ("initial_action", translate_code ((yyvsp[0].code), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2098 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2104 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 17:
-#line 315 "src/parse-gram.y" /* yacc.c:1663  */
-    { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-#line 2104 "src/parse-gram.c" /* yacc.c:1663  */
+#line 314 "src/parse-gram.y" /* yacc.c:1663  */
+    { language_argmatch ((yyvsp[0].code), grammar_prio, (yylsp[-1])); }
+#line 2110 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 18:
-#line 316 "src/parse-gram.y" /* yacc.c:1663  */
-    { spec_name_prefix = (yyvsp[0].chars); }
-#line 2110 "src/parse-gram.c" /* yacc.c:1663  */
+#line 315 "src/parse-gram.y" /* yacc.c:1663  */
+    { spec_name_prefix = (yyvsp[0].code); }
+#line 2116 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 19:
-#line 317 "src/parse-gram.y" /* yacc.c:1663  */
+#line 316 "src/parse-gram.y" /* yacc.c:1663  */
     { no_lines_flag = true; }
-#line 2116 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2122 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 20:
-#line 318 "src/parse-gram.y" /* yacc.c:1663  */
+#line 317 "src/parse-gram.y" /* yacc.c:1663  */
     { nondeterministic_parser = true; }
-#line 2122 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2128 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 21:
-#line 319 "src/parse-gram.y" /* yacc.c:1663  */
-    { spec_outfile = (yyvsp[0].chars); }
-#line 2128 "src/parse-gram.c" /* yacc.c:1663  */
+#line 318 "src/parse-gram.y" /* yacc.c:1663  */
+    { spec_outfile = (yyvsp[0].code); }
+#line 2134 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 22:
-#line 320 "src/parse-gram.y" /* yacc.c:1663  */
+#line 319 "src/parse-gram.y" /* yacc.c:1663  */
     { current_param = (yyvsp[0].param); }
-#line 2134 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2140 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 23:
-#line 320 "src/parse-gram.y" /* yacc.c:1663  */
+#line 319 "src/parse-gram.y" /* yacc.c:1663  */
     { current_param = param_none; }
-#line 2140 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2146 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 24:
-#line 321 "src/parse-gram.y" /* yacc.c:1663  */
-    { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-#line 2146 "src/parse-gram.c" /* yacc.c:1663  */
+#line 320 "src/parse-gram.y" /* yacc.c:1663  */
+    { version_check (&(yylsp[0]), (yyvsp[0].code)); }
+#line 2152 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 25:
-#line 323 "src/parse-gram.y" /* yacc.c:1663  */
+#line 322 "src/parse-gram.y" /* yacc.c:1663  */
     {
-      char const *skeleton_user = (yyvsp[0].chars);
+      char const *skeleton_user = (yyvsp[0].code);
       if (strchr (skeleton_user, '/'))
         {
           size_t dir_length = strlen (current_file);
@@ -2170,49 +2176,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2174 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2180 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 26:
-#line 346 "src/parse-gram.y" /* yacc.c:1663  */
+#line 345 "src/parse-gram.y" /* yacc.c:1663  */
     { token_table_flag = true; }
-#line 2180 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2186 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 27:
-#line 347 "src/parse-gram.y" /* yacc.c:1663  */
+#line 346 "src/parse-gram.y" /* yacc.c:1663  */
     { report_flag |= report_states; }
-#line 2186 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2192 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 28:
-#line 348 "src/parse-gram.y" /* yacc.c:1663  */
+#line 347 "src/parse-gram.y" /* yacc.c:1663  */
     { yacc_flag = true; }
-#line 2192 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2198 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 30:
-#line 353 "src/parse-gram.y" /* yacc.c:1663  */
+#line 352 "src/parse-gram.y" /* yacc.c:1663  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2198 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2204 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 31:
-#line 354 "src/parse-gram.y" /* yacc.c:1663  */
+#line 353 "src/parse-gram.y" /* yacc.c:1663  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2204 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2210 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 34:
-#line 366 "src/parse-gram.y" /* yacc.c:1663  */
+#line 365 "src/parse-gram.y" /* yacc.c:1663  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2212 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2218 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 35:
-#line 370 "src/parse-gram.y" /* yacc.c:1663  */
+#line 369 "src/parse-gram.y" /* yacc.c:1663  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2224,83 +2230,84 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2228 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2234 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 36:
-#line 382 "src/parse-gram.y" /* yacc.c:1663  */
+#line 381 "src/parse-gram.y" /* yacc.c:1663  */
     {
       default_prec = true;
     }
-#line 2236 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2242 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 37:
-#line 386 "src/parse-gram.y" /* yacc.c:1663  */
+#line 385 "src/parse-gram.y" /* yacc.c:1663  */
     {
       default_prec = false;
     }
-#line 2244 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2250 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 38:
-#line 390 "src/parse-gram.y" /* yacc.c:1663  */
+#line 389 "src/parse-gram.y" /* yacc.c:1663  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
-      muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
+      muscle_code_grow ("percent_code()",
+                        translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2255 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2262 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 39:
 #line 397 "src/parse-gram.y" /* yacc.c:1663  */
     {
-      muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
+      muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2264 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2271 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 40:
 #line 407 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.code_type) = destructor; }
-#line 2270 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2277 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 41:
 #line 408 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.code_type) = printer; }
-#line 2276 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2283 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 42:
 #line 418 "src/parse-gram.y" /* yacc.c:1663  */
     {}
-#line 2282 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2289 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 43:
 #line 419 "src/parse-gram.y" /* yacc.c:1663  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2288 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2295 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 44:
 #line 424 "src/parse-gram.y" /* yacc.c:1663  */
     {
       union_seen = true;
-      muscle_code_grow ("union_members", (yyvsp[0].chars), (yylsp[0]));
+      muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2298 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2305 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 45:
 #line 435 "src/parse-gram.y" /* yacc.c:1663  */
     { current_class = nterm_sym; }
-#line 2304 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2311 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 46:
@@ -2309,13 +2316,13 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2313 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2320 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 47:
 #line 440 "src/parse-gram.y" /* yacc.c:1663  */
     { current_class = token_sym; }
-#line 2319 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2326 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 48:
@@ -2324,7 +2331,7 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2328 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2335 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 49:
@@ -2336,7 +2343,7 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2340 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2347 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 50:
@@ -2352,55 +2359,55 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2356 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2363 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 51:
 #line 471 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = left_assoc; }
-#line 2362 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2369 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 52:
 #line 472 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = right_assoc; }
-#line 2368 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2375 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 53:
 #line 473 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = non_assoc; }
-#line 2374 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2381 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 54:
 #line 474 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2380 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2387 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 55:
 #line 478 "src/parse-gram.y" /* yacc.c:1663  */
     { current_type = NULL; }
-#line 2386 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2393 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 56:
 #line 479 "src/parse-gram.y" /* yacc.c:1663  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2392 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2399 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 57:
 #line 485 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2398 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2405 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 58:
 #line 487 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2404 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2411 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 59:
@@ -2409,7 +2416,7 @@ yyreduce:
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2413 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2420 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 60:
@@ -2419,55 +2426,55 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2423 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2430 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 61:
 #line 507 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2429 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2436 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 62:
 #line 509 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2435 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2442 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 63:
 #line 513 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2441 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2448 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 64:
 #line 514 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2447 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2454 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 65:
 #line 518 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2453 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2460 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 66:
 #line 519 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2459 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2466 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 68:
 #line 524 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2465 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2472 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 69:
 #line 525 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2471 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2478 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 70:
@@ -2476,7 +2483,7 @@ yyreduce:
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2480 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2487 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 71:
@@ -2485,7 +2492,7 @@ yyreduce:
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2489 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2496 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 72:
@@ -2495,7 +2502,7 @@ yyreduce:
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2499 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2506 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 73:
@@ -2505,7 +2512,7 @@ yyreduce:
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2509 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2516 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 74:
@@ -2516,7 +2523,7 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2520 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2527 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 81:
@@ -2524,13 +2531,13 @@ yyreduce:
     {
       yyerrok;
     }
-#line 2528 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2535 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 82:
 #line 589 "src/parse-gram.y" /* yacc.c:1663  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2534 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2541 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 83:
@@ -2539,171 +2546,154 @@ yyreduce:
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2543 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2550 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 84:
 #line 597 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2549 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2556 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 85:
 #line 598 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2555 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2562 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 87:
 #line 605 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2562 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2569 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 88:
 #line 608 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2568 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2575 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 89:
 #line 610 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2574 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2581 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 90:
 #line 612 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2580 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2587 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 91:
 #line 614 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2586 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2593 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 92:
 #line 616 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2592 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2599 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 93:
 #line 618 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2598 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2605 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 94:
 #line 620 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2604 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2611 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 95:
 #line 624 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.named_ref) = 0; }
-#line 2610 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2617 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 96:
 #line 625 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2616 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2623 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 98:
 #line 636 "src/parse-gram.y" /* yacc.c:1663  */
-    { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-#line 2622 "src/parse-gram.c" /* yacc.c:1663  */
+    { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].code)); }
+#line 2629 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 99:
 #line 661 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2628 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2635 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 100:
 #line 662 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2634 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2641 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 101:
 #line 663 "src/parse-gram.y" /* yacc.c:1663  */
-    { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].chars); }
-#line 2640 "src/parse-gram.c" /* yacc.c:1663  */
+    { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].code); }
+#line 2647 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 102:
 #line 664 "src/parse-gram.y" /* yacc.c:1663  */
-    { (yyval.value).kind = muscle_code;    (yyval.value).chars = (yyvsp[0].chars); }
-#line 2646 "src/parse-gram.c" /* yacc.c:1663  */
+    { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].code)); }
+#line 2653 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 103:
-#line 674 "src/parse-gram.y" /* yacc.c:1663  */
-    {
-      code_props plain_code;
-      (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\0';
-      code_props_plain_init (&plain_code, (yyvsp[0].code)+1, (yylsp[0]));
-      code_props_translate_code (&plain_code);
-      gram_scanner_last_string_free ();
-      (yyval.chars) = plain_code.code;
-    }
+#line 677 "src/parse-gram.y" /* yacc.c:1663  */
+    { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 #line 2659 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 104:
-#line 694 "src/parse-gram.y" /* yacc.c:1663  */
-    { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2665 "src/parse-gram.c" /* yacc.c:1663  */
-    break;
-
-  case 105:
-#line 696 "src/parse-gram.y" /* yacc.c:1663  */
+#line 679 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2675 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2669 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
-  case 106:
-#line 704 "src/parse-gram.y" /* yacc.c:1663  */
+  case 105:
+#line 687 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2681 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2675 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
-  case 109:
-#line 716 "src/parse-gram.y" /* yacc.c:1663  */
+  case 108:
+#line 699 "src/parse-gram.y" /* yacc.c:1663  */
     {
-      (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
+      (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].code)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2690 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2684 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
-  case 111:
-#line 725 "src/parse-gram.y" /* yacc.c:1663  */
+  case 110:
+#line 708 "src/parse-gram.y" /* yacc.c:1663  */
     {
-      code_props plain_code;
-      code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
-      code_props_translate_code (&plain_code);
-      gram_scanner_last_string_free ();
-      muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
+      muscle_code_grow ("epilogue", translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2703 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2693 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
 
-#line 2707 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2697 "src/parse-gram.c" /* yacc.c:1663  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2950,7 +2940,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 735 "src/parse-gram.y" /* yacc.c:1923  */
+#line 714 "src/parse-gram.y" /* yacc.c:1923  */
 
 
 /* Return the location of the left-hand side of a rule whose
@@ -2982,6 +2972,33 @@ lloc_default (YYLTYPE const *rhs, int n)
   return loc;
 }
 
+static
+char *strip_braces (char *code)
+{
+  code[strlen(code) - 1] = 0;
+  return code + 1;
+}
+
+static
+char const *
+translate_code (char *code, location loc, bool plain)
+{
+  code_props plain_code;
+  if (plain)
+    code_props_plain_init (&plain_code, code, loc);
+  else
+    code_props_symbol_action_init (&plain_code, code, loc);
+  code_props_translate_code (&plain_code);
+  gram_scanner_last_string_free ();
+  return plain_code.code;
+}
+
+static
+char const *
+translate_code_braceless (char *code, location loc)
+{
+  return translate_code (strip_braces (code), loc, true);
+}
 
 static void
 add_param (param_type type, char *decl, location loc)
