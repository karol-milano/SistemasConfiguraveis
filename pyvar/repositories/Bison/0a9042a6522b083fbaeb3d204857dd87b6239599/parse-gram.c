@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.6.5.977-6d58-dirty.  */
+/* A Bison parser, made by GNU Bison 2.7.980-6f0a6-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.5.977-6d58-dirty"
+#define YYBISON_VERSION "2.7.980-6f0a6-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -72,7 +72,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 355 of yacc.c  */
+/* Line 356 of yacc.c  */
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -129,7 +129,7 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/* Line 355 of yacc.c  */
+/* Line 356 of yacc.c  */
 #line 134 "src/parse-gram.c"
 
 # ifndef YY_NULL
@@ -152,7 +152,7 @@ static char const *char_name (char);
    by #include "src/parse-gram.h".  */
 #ifndef YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED
 # define YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED
-/* Enabling traces.  */
+/* Debug traces.  */
 #ifndef GRAM_DEBUG
 # if defined YYDEBUG
 #if YYDEBUG
@@ -168,7 +168,7 @@ static char const *char_name (char);
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-/* Line 371 of yacc.c  */
+/* Line 372 of yacc.c  */
 #line 223 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
@@ -183,14 +183,12 @@ extern int gram_debug;
 # endif
 
 
-/* Line 371 of yacc.c  */
+/* Line 372 of yacc.c  */
 #line 188 "src/parse-gram.c"
 
-/* Tokens.  */
+/* Token type.  */
 #ifndef GRAM_TOKENTYPE
 # define GRAM_TOKENTYPE
-  /* Put the tokens into the symbol table, so that GDB and other debuggers
-     know about them.  */
   enum gram_tokentype
   {
     GRAM_EOF = 0,
@@ -307,10 +305,12 @@ extern int gram_debug;
 #define PERCENT_PARAM 310
 #define PERCENT_UNION 311
 
+/* Value type.  */
 #if ! defined GRAM_STYPE && ! defined GRAM_STYPE_IS_DECLARED
-typedef union GRAM_STYPE
+typedef union GRAM_STYPE GRAM_STYPE;
+union GRAM_STYPE
 {
-/* Line 371 of yacc.c  */
+/* Line 372 of yacc.c  */
 #line 109 "src/parse-gram.y"
 
   assoc assoc;
@@ -323,45 +323,48 @@ typedef union GRAM_STYPE
   uniqstr uniqstr;
   unsigned char character;
 
-/* Line 371 of yacc.c  */
+/* Line 372 of yacc.c  */
 #line 247 "src/parse-gram.y"
 
   param_type param;
 
-/* Line 371 of yacc.c  */
+/* Line 372 of yacc.c  */
 #line 423 "src/parse-gram.y"
 code_props_type code_type;
 
-/* Line 371 of yacc.c  */
+/* Line 372 of yacc.c  */
 #line 337 "src/parse-gram.c"
-} GRAM_STYPE;
+};
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
 #endif
 
+/* Location type.  */
 #if ! defined GRAM_LTYPE && ! defined GRAM_LTYPE_IS_DECLARED
-typedef struct GRAM_LTYPE
+typedef struct GRAM_LTYPE GRAM_LTYPE;
+struct GRAM_LTYPE
 {
   int first_line;
   int first_column;
   int last_line;
   int last_column;
-} GRAM_LTYPE;
+};
 # define GRAM_LTYPE_IS_DECLARED 1
 # define GRAM_LTYPE_IS_TRIVIAL 1
 #endif
 
 
+
 int gram_parse (void);
 
 #endif /* !YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED  */
 
 /* Copy the second part of user declarations.  */
 
-/* Line 374 of yacc.c  */
-#line 363 "src/parse-gram.c"
-/* Unqualified %code blocks.  */
 /* Line 375 of yacc.c  */
+#line 366 "src/parse-gram.c"
+/* Unqualified %code blocks.  */
+/* Line 376 of yacc.c  */
 #line 58 "src/parse-gram.y"
 
   static int current_prec = 0;
@@ -394,7 +397,7 @@ int gram_parse (void);
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 375 of yacc.c  */
+/* Line 376 of yacc.c  */
 #line 236 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
@@ -407,8 +410,8 @@ int gram_parse (void);
   static param_type current_param = param_none;
 
 
-/* Line 375 of yacc.c  */
-#line 412 "src/parse-gram.c"
+/* Line 376 of yacc.c  */
+#line 415 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -640,7 +643,7 @@ static const yytype_uint8 yytranslate[] =
 };
 
 #if GRAM_DEBUG
-  /* YYRLINEYYN -- Source line where rule number YYN was defined.    */
+  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
        0,   272,   272,   280,   282,   286,   287,   297,   301,   306,
@@ -712,7 +715,7 @@ static const yytype_uint16 yytoknum[] =
   0
 
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
-     STATE-NUM.    */
+     STATE-NUM.  */
 static const yytype_int16 yypact[] =
 {
      -74,    40,   101,   -74,   -74,   -74,   -48,   -74,   -74,   -74,
@@ -732,9 +735,9 @@ static const yytype_int16 yypact[] =
      -74,   -74,   -74
 };
 
-  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
-     YYTABLE does not specify something else to do.  Zero means the default
-     is an error.    */
+  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
+     Performed when YYTABLE does not specify something else to do.  Zero
+     means the default is an error.  */
 static const yytype_uint8 yydefact[] =
 {
        3,     0,     0,     1,    47,    45,     0,    40,    41,    51,
@@ -754,7 +757,7 @@ static const yytype_uint8 yydefact[] =
       93,    89,    88
 };
 
-  /* YYPGOTO[NTERM-NUM].    */
+  /* YYPGOTO[NTERM-NUM].  */
 static const yytype_int16 yypgoto[] =
 {
      -74,   -74,   -74,   -74,   -74,   -74,   140,   -74,   -74,   -74,
@@ -763,7 +766,7 @@ static const yytype_int16 yypgoto[] =
      -74,   -74,   -46,     6,   -74,   -32,   -73,   -74
 };
 
-  /* YYDEFGOTO[NTERM-NUM].    */
+  /* YYDEFGOTO[NTERM-NUM].  */
 static const yytype_int16 yydefgoto[] =
 {
       -1,     1,     2,    41,    79,   104,    74,    43,    81,    44,
@@ -772,9 +775,9 @@ static const yytype_int16 yydefgoto[] =
       55,    95,    52,    69,    78,   112,    71,   100
 };
 
-  /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
-     positive, shift that token.  If negative, reduce the rule which
-     number is the opposite.  If YYTABLE_NINF, syntax error.    */
+  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
+     positive, shift that token.  If negative, reduce the rule whose
+     number is the opposite.  If YYTABLE_NINF, syntax error.  */
 static const yytype_int16 yytable[] =
 {
       70,  -108,    72,    53,    49,    92,     4,     5,     6,     7,
@@ -815,8 +818,8 @@ static const yytype_int16 yycheck[] =
       -1,    50,    51,    -1,    -1,    -1,    55,    56
 };
 
-  /* STOS_[STATE-NUM] -- The (internal number of the) accessing
-     symbol of state STATE-NUM.    */
+  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
+     symbol of state STATE-NUM.  */
 static const yytype_uint8 yystos[] =
 {
        0,    58,    59,     0,     5,     6,     7,     8,     9,    10,
@@ -836,7 +839,7 @@ static const yytype_uint8 yystos[] =
       52,    86,    86
 };
 
-  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.    */
+  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
 static const yytype_uint8 yyr1[] =
 {
        0,    57,    58,    59,    59,    60,    60,    60,    60,    60,
@@ -852,7 +855,7 @@ static const yytype_uint8 yyr1[] =
       88,    89,    90,    90,    91,    92,    92,    93,    94,    94
 };
 
-  /* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.    */
+  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
 static const yytype_uint8 yyr2[] =
 {
        0,     2,     4,     0,     2,     1,     1,     1,     3,     1,
@@ -937,27 +940,44 @@ while (0)
 
 #ifndef YY_LOCATION_PRINT
 # if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
+
+/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */
+
+__attribute__((__unused__))
+static unsigned
+yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
+{
+  unsigned res = 0;
+  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
+  if (0 <= yylocp->first_line)
+    {
+      res += fprintf (yyo, "%d", yylocp->first_line);
+      if (0 <= yylocp->first_column)
+        res += fprintf (yyo, ".%d", yylocp->first_column);
+    }
+  if (0 <= yylocp->last_line)
+    {
+      if (yylocp->first_line < yylocp->last_line)
+        {
+          res += fprintf (yyo, "-%d", yylocp->last_line);
+          if (0 <= end_col)
+            res += fprintf (yyo, ".%d", end_col);
+        }
+      else if (0 <= end_col && yylocp->first_column < end_col)
+        res += fprintf (yyo, "-%d", end_col);
+    }
+  return res;
+ }
+
 #  define YY_LOCATION_PRINT(File, Loc)                                   \
-  do {                                                                   \
-    fprintf (File, "%d.%d", (Loc).first_line, (Loc).first_column);       \
-    if ((Loc).first_line < (Loc).last_line)                              \
-      fprintf (File, "-%d.%d", (Loc).last_line,  (Loc).last_column - 1); \
-    else if ((Loc).first_column < (Loc).last_column - 1)                 \
-      fprintf (File, "-%d", (Loc).last_column - 1);                      \
-  } while (0)
+  yy_location_print_ (File, &(Loc))
+
 # else
 #  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 # endif
 #endif
 
 
-/* YYLEX -- calling `yylex' with the right arguments.  */
-#ifdef YYLEX_PARAM
-# define YYLEX yylex (&yylval, &yylloc, YYLEX_PARAM)
-#else
-# define YYLEX yylex (&yylval, &yylloc)
-#endif
-
 /* Enable debugging if requested.  */
 #if GRAM_DEBUG
 
@@ -1003,95 +1023,95 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
             case 3: // "string"
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 196 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-/* Line 711 of yacc.c  */
-#line 1011 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1031 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 209 "src/parse-gram.y"
         { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-/* Line 711 of yacc.c  */
-#line 1019 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1039 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 205 "src/parse-gram.y"
         { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 711 of yacc.c  */
-#line 1027 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1047 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 711 of yacc.c  */
-#line 1035 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1055 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 203 "src/parse-gram.y"
         { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 711 of yacc.c  */
-#line 1043 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1063 "src/parse-gram.c"
         break;
 
             case 43: // "char"
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 190 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), yyo); }
-/* Line 711 of yacc.c  */
-#line 1051 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1071 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 711 of yacc.c  */
-#line 1059 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1079 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 711 of yacc.c  */
-#line 1067 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1087 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 204 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 711 of yacc.c  */
-#line 1075 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1095 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 711 of yacc.c  */
-#line 1083 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1103 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 206 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 711 of yacc.c  */
-#line 1091 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1111 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 252 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1105,88 +1125,88 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-/* Line 711 of yacc.c  */
-#line 1110 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1130 "src/parse-gram.c"
         break;
 
             case 64: // code_props_type
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 424 "src/parse-gram.y"
         { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-/* Line 711 of yacc.c  */
-#line 1118 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1138 "src/parse-gram.c"
         break;
 
             case 73: // symbol.prec
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 711 of yacc.c  */
-#line 1126 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1146 "src/parse-gram.c"
         break;
 
             case 77: // tag
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 206 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 711 of yacc.c  */
-#line 1134 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1154 "src/parse-gram.c"
         break;
 
             case 87: // variable
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 711 of yacc.c  */
-#line 1142 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1162 "src/parse-gram.c"
         break;
 
             case 88: // content.opt
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 711 of yacc.c  */
-#line 1150 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1170 "src/parse-gram.c"
         break;
 
             case 89: // braceless
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 198 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 711 of yacc.c  */
-#line 1158 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1178 "src/parse-gram.c"
         break;
 
             case 90: // id
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 711 of yacc.c  */
-#line 1166 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1186 "src/parse-gram.c"
         break;
 
             case 91: // id_colon
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 213 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 711 of yacc.c  */
-#line 1174 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1194 "src/parse-gram.c"
         break;
 
             case 92: // symbol
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 711 of yacc.c  */
-#line 1182 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1202 "src/parse-gram.c"
         break;
 
             case 93: // string_as_id
-/* Line 711 of yacc.c  */
+/* Line 705 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 711 of yacc.c  */
-#line 1190 "src/parse-gram.c"
+/* Line 705 of yacc.c  */
+#line 1210 "src/parse-gram.c"
         break;
 
       default:
@@ -1631,7 +1651,6 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 {
   YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
-  YYSIZE_T yysize1;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
   const char *yyformat = YY_NULL;
@@ -1688,11 +1707,13 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                     break;
                   }
                 yyarg[yycount++] = yytname[yyx];
-                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
-                if (! (yysize <= yysize1
-                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
-                  return 2;
-                yysize = yysize1;
+                {
+                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
+                  if (! (yysize <= yysize1
+                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+                    return 2;
+                  yysize = yysize1;
+                }
               }
         }
 # if GRAM_DEBUG
@@ -1716,10 +1737,12 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 # undef YYCASE_
     }
 
-  yysize1 = yysize + yystrlen (yyformat);
-  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
-    return 2;
-  yysize = yysize1;
+  {
+    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
+    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+      return 2;
+    yysize = yysize1;
+  }
 
   if (*yymsg_alloc < yysize)
     {
@@ -1800,6 +1823,11 @@ int yychar;
 static YYSTYPE yyval_default;
 # define YY_INITIAL_VALUE(Value) = Value
 #endif
+static YYLTYPE yyloc_default
+# if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
+  = { 1, 1, 1, 1 }
+# endif
+;
 #ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
 # define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
 # define YY_IGNORE_MAYBE_UNINITIALIZED_END
@@ -1812,11 +1840,7 @@ static YYSTYPE yyval_default;
 YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);
 
 /* Location data for the lookahead symbol.  */
-YYLTYPE yylloc
-# if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
-  = { 1, 1, 1, 1 }
-# endif
-;
+YYLTYPE yylloc = yyloc_default;
 
 
     /* Number of syntax errors so far.  */
@@ -1899,7 +1923,7 @@ YYLTYPE yylloc
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-/* Line 1452 of yacc.c  */
+/* Line 1450 of yacc.c  */
 #line 101 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1907,8 +1931,8 @@ YYLTYPE yylloc
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1452 of yacc.c  */
-#line 1912 "src/parse-gram.c"
+/* Line 1450 of yacc.c  */
+#line 1936 "src/parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2015,7 +2039,7 @@ yybackup:
   if (yychar == YYEMPTY)
     {
       YYDPRINTF ((stderr, "Reading a token: "));
-      yychar = YYLEX;
+      yychar = yylex (&yylval, &yylloc);
     }
 
   if (yychar <= YYEOF)
@@ -2102,7 +2126,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 288 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2113,98 +2137,98 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1670 of yacc.c  */
-#line 2118 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2142 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 298 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1670 of yacc.c  */
-#line 2128 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2152 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 302 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1670 of yacc.c  */
-#line 2139 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2163 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 306 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1670 of yacc.c  */
-#line 2147 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2171 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 308 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1670 of yacc.c  */
-#line 2158 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2182 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 313 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1670 of yacc.c  */
-#line 2169 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2193 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1670 of yacc.c  */
-#line 2177 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2201 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1670 of yacc.c  */
-#line 2185 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2209 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1670 of yacc.c  */
-#line 2193 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2217 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 321 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1670 of yacc.c  */
-#line 2204 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2228 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 326 "src/parse-gram.y"
     {
       code_props action;
@@ -2214,76 +2238,76 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1670 of yacc.c  */
-#line 2219 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2243 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 334 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1670 of yacc.c  */
-#line 2227 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2251 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1670 of yacc.c  */
-#line 2235 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2259 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 336 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1670 of yacc.c  */
-#line 2243 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2267 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 337 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1670 of yacc.c  */
-#line 2251 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2275 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 338 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1670 of yacc.c  */
-#line 2259 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2283 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1670 of yacc.c  */
-#line 2267 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2291 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1670 of yacc.c  */
-#line 2275 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2299 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 340 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1670 of yacc.c  */
-#line 2283 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2307 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 342 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2308,62 +2332,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1670 of yacc.c  */
-#line 2313 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2337 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 365 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1670 of yacc.c  */
-#line 2321 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2345 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 366 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1670 of yacc.c  */
-#line 2329 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2353 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 367 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1670 of yacc.c  */
-#line 2337 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2361 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 372 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2345 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2369 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 373 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2353 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2377 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 385 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1670 of yacc.c  */
-#line 2363 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2387 "src/parse-gram.c"
     break;
 
   case 35:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 389 "src/parse-gram.y"
     {
       code_props code;
@@ -2376,32 +2400,32 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-/* Line 1670 of yacc.c  */
-#line 2381 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2405 "src/parse-gram.c"
     break;
 
   case 36:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 401 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1670 of yacc.c  */
-#line 2391 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2415 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 405 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1670 of yacc.c  */
-#line 2401 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2425 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 409 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2409,105 +2433,105 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1670 of yacc.c  */
-#line 2414 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2438 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 416 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1670 of yacc.c  */
-#line 2425 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2449 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 426 "src/parse-gram.y"
     { (yyval.code_type) = destructor; }
-/* Line 1670 of yacc.c  */
-#line 2433 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2457 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 427 "src/parse-gram.y"
     { (yyval.code_type) = printer; }
-/* Line 1670 of yacc.c  */
-#line 2441 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2465 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 437 "src/parse-gram.y"
     {}
-/* Line 1670 of yacc.c  */
-#line 2449 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2473 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 438 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2457 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2481 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 443 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1670 of yacc.c  */
-#line 2469 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2493 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 454 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1670 of yacc.c  */
-#line 2477 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2501 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 455 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1670 of yacc.c  */
-#line 2488 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2512 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 459 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1670 of yacc.c  */
-#line 2496 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2520 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 460 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1670 of yacc.c  */
-#line 2507 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2531 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 465 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2516,12 +2540,12 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1670 of yacc.c  */
-#line 2521 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2545 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 476 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2534,202 +2558,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1670 of yacc.c  */
-#line 2539 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2563 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 490 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1670 of yacc.c  */
-#line 2547 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2571 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 491 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1670 of yacc.c  */
-#line 2555 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2579 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 492 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1670 of yacc.c  */
-#line 2563 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2587 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 493 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1670 of yacc.c  */
-#line 2571 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2595 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 497 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1670 of yacc.c  */
-#line 2579 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2603 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 498 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1670 of yacc.c  */
-#line 2587 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2611 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 504 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2595 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2619 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1670 of yacc.c  */
-#line 2603 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2627 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 510 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1670 of yacc.c  */
-#line 2611 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2635 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 511 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2619 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2643 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 517 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2627 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2651 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 519 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1670 of yacc.c  */
-#line 2635 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2659 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 523 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1670 of yacc.c  */
-#line 2643 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2667 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 524 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1670 of yacc.c  */
-#line 2651 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2675 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 528 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2659 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2683 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 529 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2667 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2691 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 534 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-/* Line 1670 of yacc.c  */
-#line 2675 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2699 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 535 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new (""); }
-/* Line 1670 of yacc.c  */
-#line 2683 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2707 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 541 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1670 of yacc.c  */
-#line 2694 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2718 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 546 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1670 of yacc.c  */
-#line 2705 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2729 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 551 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1670 of yacc.c  */
-#line 2717 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2741 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 557 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1670 of yacc.c  */
-#line 2729 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2753 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 563 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2737,154 +2761,154 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1670 of yacc.c  */
-#line 2742 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2766 "src/parse-gram.c"
     break;
 
   case 81:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 593 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1670 of yacc.c  */
-#line 2752 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2776 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 599 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1670 of yacc.c  */
-#line 2760 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2784 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 600 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1670 of yacc.c  */
-#line 2771 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2795 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 607 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2779 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2803 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 608 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2787 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2811 "src/parse-gram.c"
     break;
 
   case 87:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 614 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1670 of yacc.c  */
-#line 2796 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2820 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 617 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1670 of yacc.c  */
-#line 2804 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2828 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 619 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1670 of yacc.c  */
-#line 2812 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2836 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 621 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1670 of yacc.c  */
-#line 2820 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2844 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 623 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2828 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2852 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 625 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2836 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2860 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 627 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2844 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2868 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 631 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1670 of yacc.c  */
-#line 2852 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2876 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 633 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2860 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2884 "src/parse-gram.c"
     break;
 
   case 97:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 644 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1670 of yacc.c  */
-#line 2868 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2892 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 649 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1670 of yacc.c  */
-#line 2876 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2900 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 650 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1670 of yacc.c  */
-#line 2884 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2908 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 661 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2894,51 +2918,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1670 of yacc.c  */
-#line 2899 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2923 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 681 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2907 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2931 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 683 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1670 of yacc.c  */
-#line 2919 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2943 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 691 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1670 of yacc.c  */
-#line 2927 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2951 "src/parse-gram.c"
     break;
 
   case 107:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 703 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1670 of yacc.c  */
-#line 2938 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2962 "src/parse-gram.c"
     break;
 
   case 109:
-/* Line 1670 of yacc.c  */
+/* Line 1667 of yacc.c  */
 #line 712 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2948,13 +2972,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1670 of yacc.c  */
-#line 2953 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2977 "src/parse-gram.c"
     break;
 
 
-/* Line 1670 of yacc.c  */
-#line 2958 "src/parse-gram.c"
+/* Line 1667 of yacc.c  */
+#line 2982 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3084,7 +3108,7 @@ yyerrorlab:
      goto yyerrorlab;
 
   yyerror_range[1] = yylsp[1-yylen];
-  /* Do not reclaim the symbols of the rule which action triggered
+  /* Do not reclaim the symbols of the rule whose action triggered
      this YYERROR.  */
   YYPOPSTACK (yylen);
   yylen = 0;
@@ -3179,7 +3203,7 @@ yyreturn:
       yydestruct ("Cleanup: discarding lookahead",
                   yytoken, &yylval, &yylloc);
     }
-  /* Do not reclaim the symbols of the rule which action triggered
+  /* Do not reclaim the symbols of the rule whose action triggered
      this YYABORT or YYACCEPT.  */
   YYPOPSTACK (yylen);
   YY_STACK_PRINT (yyss, yyssp);
@@ -3201,7 +3225,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-/* Line 1930 of yacc.c  */
+/* Line 1927 of yacc.c  */
 #line 722 "src/parse-gram.y"
 
 
