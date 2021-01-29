@@ -1,9 +1,8 @@
-/* A Bison parser, made by GNU Bison 2.7.987-a2db-dirty.  */
+/* A Bison parser, made by GNU Bison 2.7.1016-4862c.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
-   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation,
-   Inc.
+   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -45,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.7.987-a2db-dirty"
+#define YYBISON_VERSION "2.7.1016-4862c"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -66,17 +65,15 @@
 #define yyparse         gram_parse
 #define yylex           gram_lex
 #define yyerror         gram_error
-#define yylval          gram_lval
-#define yychar          gram_char
 #define yydebug         gram_debug
 #define yynerrs         gram_nerrs
-#define yylloc          gram_lloc
+
 
 /* Copy the first part of user declarations.  */
-#line 1 "src/parse-gram.y" /* yacc.c:356  */
+#line 1 "src/parse-gram.y" /* yacc.c:357  */
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002-2012 Free Software Foundation, Inc.
+   Copyright (C) 2002-2013 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -129,7 +126,7 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-#line 132 "src/parse-gram.c" /* yacc.c:356  */
+#line 130 "src/parse-gram.c" /* yacc.c:357  */
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -167,7 +164,7 @@ static char const *char_name (char);
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-#line 223 "src/parse-gram.y" /* yacc.c:372  */
+#line 223 "src/parse-gram.y" /* yacc.c:373  */
 
 # ifndef PARAM_TYPE
 #  define PARAM_TYPE
@@ -181,7 +178,7 @@ extern int gram_debug;
 # endif
 
 
-#line 184 "src/parse-gram.c" /* yacc.c:372  */
+#line 182 "src/parse-gram.c" /* yacc.c:373  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -307,7 +304,7 @@ extern int gram_debug;
 typedef union GRAM_STYPE GRAM_STYPE;
 union GRAM_STYPE
 {
-#line 109 "src/parse-gram.y" /* yacc.c:372  */
+#line 109 "src/parse-gram.y" /* yacc.c:373  */
 
   assoc assoc;
   char *code;
@@ -319,14 +316,14 @@ union GRAM_STYPE
   uniqstr uniqstr;
   unsigned char character;
 
-#line 247 "src/parse-gram.y" /* yacc.c:372  */
+#line 247 "src/parse-gram.y" /* yacc.c:373  */
 
   param_type param;
 
-#line 423 "src/parse-gram.y" /* yacc.c:372  */
+#line 423 "src/parse-gram.y" /* yacc.c:373  */
 code_props_type code_type;
 
-#line 329 "src/parse-gram.c" /* yacc.c:372  */
+#line 327 "src/parse-gram.c" /* yacc.c:373  */
 };
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
@@ -354,9 +351,9 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 357 "src/parse-gram.c" /* yacc.c:375  */
+#line 355 "src/parse-gram.c" /* yacc.c:376  */
 /* Unqualified %code blocks.  */
-#line 58 "src/parse-gram.y" /* yacc.c:376  */
+#line 58 "src/parse-gram.y" /* yacc.c:377  */
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -388,7 +385,7 @@ int gram_parse (void);
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-#line 236 "src/parse-gram.y" /* yacc.c:376  */
+#line 236 "src/parse-gram.y" /* yacc.c:377  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -400,7 +397,7 @@ int gram_parse (void);
   static param_type current_param = param_none;
 
 
-#line 403 "src/parse-gram.c" /* yacc.c:376  */
+#line 401 "src/parse-gram.c" /* yacc.c:377  */
 
 #ifdef short
 # undef short
@@ -1001,7 +998,7 @@ static void
 yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
   FILE *yyo = yyoutput;
-  YYUSE(yyo);
+  YYUSE (yyo);
   YYUSE (yylocationp);
   if (!yyvaluep)
     return;
@@ -1012,73 +1009,73 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 196 "src/parse-gram.y" /* yacc.c:705  */
+#line 196 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-#line 1017 "src/parse-gram.c" /* yacc.c:705  */
+#line 1015 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 4: /* "integer"  */
-#line 209 "src/parse-gram.y" /* yacc.c:705  */
+#line 209 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1023 "src/parse-gram.c" /* yacc.c:705  */
+#line 1021 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 24: /* "%<flag>"  */
-#line 205 "src/parse-gram.y" /* yacc.c:705  */
+#line 205 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 1029 "src/parse-gram.c" /* yacc.c:705  */
+#line 1027 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 40: /* "{...}"  */
-#line 198 "src/parse-gram.y" /* yacc.c:705  */
+#line 198 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1035 "src/parse-gram.c" /* yacc.c:705  */
+#line 1033 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 42: /* "[identifier]"  */
-#line 203 "src/parse-gram.y" /* yacc.c:705  */
+#line 203 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 1041 "src/parse-gram.c" /* yacc.c:705  */
+#line 1039 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 43: /* "char"  */
-#line 190 "src/parse-gram.y" /* yacc.c:705  */
+#line 190 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 1047 "src/parse-gram.c" /* yacc.c:705  */
+#line 1045 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 44: /* "epilogue"  */
-#line 198 "src/parse-gram.y" /* yacc.c:705  */
+#line 198 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1053 "src/parse-gram.c" /* yacc.c:705  */
+#line 1051 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 46: /* "identifier"  */
-#line 202 "src/parse-gram.y" /* yacc.c:705  */
+#line 202 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1059 "src/parse-gram.c" /* yacc.c:705  */
+#line 1057 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 47: /* "identifier:"  */
-#line 204 "src/parse-gram.y" /* yacc.c:705  */
+#line 204 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1065 "src/parse-gram.c" /* yacc.c:705  */
+#line 1063 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 50: /* "%{...%}"  */
-#line 198 "src/parse-gram.y" /* yacc.c:705  */
+#line 198 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1071 "src/parse-gram.c" /* yacc.c:705  */
+#line 1069 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 52: /* "<tag>"  */
-#line 206 "src/parse-gram.y" /* yacc.c:705  */
+#line 206 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1077 "src/parse-gram.c" /* yacc.c:705  */
+#line 1075 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 55: /* "%param"  */
-#line 252 "src/parse-gram.y" /* yacc.c:705  */
+#line 252 "src/parse-gram.y" /* yacc.c:706  */
       {
   switch (((*yyvaluep).param))
     {
@@ -1091,67 +1088,67 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1094 "src/parse-gram.c" /* yacc.c:705  */
+#line 1092 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 64: /* code_props_type  */
-#line 424 "src/parse-gram.y" /* yacc.c:705  */
+#line 424 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1100 "src/parse-gram.c" /* yacc.c:705  */
+#line 1098 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 73: /* symbol.prec  */
-#line 212 "src/parse-gram.y" /* yacc.c:705  */
+#line 212 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1106 "src/parse-gram.c" /* yacc.c:705  */
+#line 1104 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 77: /* tag  */
-#line 206 "src/parse-gram.y" /* yacc.c:705  */
+#line 206 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1112 "src/parse-gram.c" /* yacc.c:705  */
+#line 1110 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 87: /* variable  */
-#line 202 "src/parse-gram.y" /* yacc.c:705  */
+#line 202 "src/parse-gram.y" /* yacc.c:706  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1118 "src/parse-gram.c" /* yacc.c:705  */
+#line 1116 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 88: /* content.opt  */
-#line 198 "src/parse-gram.y" /* yacc.c:705  */
+#line 198 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1124 "src/parse-gram.c" /* yacc.c:705  */
+#line 1122 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 89: /* braceless  */
-#line 198 "src/parse-gram.y" /* yacc.c:705  */
+#line 198 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1130 "src/parse-gram.c" /* yacc.c:705  */
+#line 1128 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 90: /* id  */
-#line 212 "src/parse-gram.y" /* yacc.c:705  */
+#line 212 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1136 "src/parse-gram.c" /* yacc.c:705  */
+#line 1134 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 91: /* id_colon  */
-#line 213 "src/parse-gram.y" /* yacc.c:705  */
+#line 213 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1142 "src/parse-gram.c" /* yacc.c:705  */
+#line 1140 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 92: /* symbol  */
-#line 212 "src/parse-gram.y" /* yacc.c:705  */
+#line 212 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1148 "src/parse-gram.c" /* yacc.c:705  */
+#line 1146 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
     case 93: /* string_as_id  */
-#line 212 "src/parse-gram.y" /* yacc.c:705  */
+#line 212 "src/parse-gram.y" /* yacc.c:706  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1154 "src/parse-gram.c" /* yacc.c:705  */
+#line 1152 "src/parse-gram.c" /* yacc.c:706  */
         break;
 
       default:
@@ -1727,7 +1724,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 static void
 yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
 {
-  YYUSE(yyvaluep);
+  YYUSE (yyvaluep);
   YYUSE (yylocationp);
   if (!yymsg)
     yymsg = "Deleting";
@@ -1868,14 +1865,14 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 101 "src/parse-gram.y" /* yacc.c:1450  */
+#line 101 "src/parse-gram.y" /* yacc.c:1451  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-#line 1878 "src/parse-gram.c" /* yacc.c:1450  */
+#line 1876 "src/parse-gram.c" /* yacc.c:1451  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2069,7 +2066,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 288 "src/parse-gram.y" /* yacc.c:1667  */
+#line 288 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2079,79 +2076,79 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2082 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2080 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 7:
-#line 298 "src/parse-gram.y" /* yacc.c:1667  */
+#line 298 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2090 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2088 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 8:
-#line 302 "src/parse-gram.y" /* yacc.c:1667  */
+#line 302 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2099 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2097 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 9:
-#line 306 "src/parse-gram.y" /* yacc.c:1667  */
+#line 306 "src/parse-gram.y" /* yacc.c:1668  */
     { defines_flag = true; }
-#line 2105 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2103 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 10:
-#line 308 "src/parse-gram.y" /* yacc.c:1667  */
+#line 308 "src/parse-gram.y" /* yacc.c:1668  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-#line 2114 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2112 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 11:
-#line 313 "src/parse-gram.y" /* yacc.c:1667  */
+#line 313 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2123 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2121 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 12:
-#line 317 "src/parse-gram.y" /* yacc.c:1667  */
+#line 317 "src/parse-gram.y" /* yacc.c:1668  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2129 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2127 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 13:
-#line 318 "src/parse-gram.y" /* yacc.c:1667  */
+#line 318 "src/parse-gram.y" /* yacc.c:1668  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2135 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2133 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 14:
-#line 319 "src/parse-gram.y" /* yacc.c:1667  */
+#line 319 "src/parse-gram.y" /* yacc.c:1668  */
     { spec_file_prefix = (yyvsp[0].chars); }
-#line 2141 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2139 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 15:
-#line 321 "src/parse-gram.y" /* yacc.c:1667  */
+#line 321 "src/parse-gram.y" /* yacc.c:1668  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2150 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2148 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 16:
-#line 326 "src/parse-gram.y" /* yacc.c:1667  */
+#line 326 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2160,59 +2157,59 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2163 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2161 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 17:
-#line 334 "src/parse-gram.y" /* yacc.c:1667  */
+#line 334 "src/parse-gram.y" /* yacc.c:1668  */
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-#line 2169 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2167 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 18:
-#line 335 "src/parse-gram.y" /* yacc.c:1667  */
+#line 335 "src/parse-gram.y" /* yacc.c:1668  */
     { spec_name_prefix = (yyvsp[0].chars); }
-#line 2175 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2173 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 19:
-#line 336 "src/parse-gram.y" /* yacc.c:1667  */
+#line 336 "src/parse-gram.y" /* yacc.c:1668  */
     { no_lines_flag = true; }
-#line 2181 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2179 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 20:
-#line 337 "src/parse-gram.y" /* yacc.c:1667  */
+#line 337 "src/parse-gram.y" /* yacc.c:1668  */
     { nondeterministic_parser = true; }
-#line 2187 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2185 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 21:
-#line 338 "src/parse-gram.y" /* yacc.c:1667  */
+#line 338 "src/parse-gram.y" /* yacc.c:1668  */
     { spec_outfile = (yyvsp[0].chars); }
-#line 2193 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2191 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 22:
-#line 339 "src/parse-gram.y" /* yacc.c:1667  */
+#line 339 "src/parse-gram.y" /* yacc.c:1668  */
     { current_param = (yyvsp[0].param); }
-#line 2199 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2197 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 23:
-#line 339 "src/parse-gram.y" /* yacc.c:1667  */
+#line 339 "src/parse-gram.y" /* yacc.c:1668  */
     { current_param = param_none; }
-#line 2205 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2203 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 24:
-#line 340 "src/parse-gram.y" /* yacc.c:1667  */
+#line 340 "src/parse-gram.y" /* yacc.c:1668  */
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-#line 2211 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2209 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 25:
-#line 342 "src/parse-gram.y" /* yacc.c:1667  */
+#line 342 "src/parse-gram.y" /* yacc.c:1668  */
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2236,49 +2233,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2239 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2237 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 26:
-#line 365 "src/parse-gram.y" /* yacc.c:1667  */
+#line 365 "src/parse-gram.y" /* yacc.c:1668  */
     { token_table_flag = true; }
-#line 2245 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2243 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 27:
-#line 366 "src/parse-gram.y" /* yacc.c:1667  */
+#line 366 "src/parse-gram.y" /* yacc.c:1668  */
     { report_flag |= report_states; }
-#line 2251 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2249 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 28:
-#line 367 "src/parse-gram.y" /* yacc.c:1667  */
+#line 367 "src/parse-gram.y" /* yacc.c:1668  */
     { yacc_flag = true; }
-#line 2257 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2255 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 30:
-#line 372 "src/parse-gram.y" /* yacc.c:1667  */
+#line 372 "src/parse-gram.y" /* yacc.c:1668  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2263 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2261 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 31:
-#line 373 "src/parse-gram.y" /* yacc.c:1667  */
+#line 373 "src/parse-gram.y" /* yacc.c:1668  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2269 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2267 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 34:
-#line 385 "src/parse-gram.y" /* yacc.c:1667  */
+#line 385 "src/parse-gram.y" /* yacc.c:1668  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2277 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2275 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 35:
-#line 389 "src/parse-gram.y" /* yacc.c:1667  */
+#line 389 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2290,111 +2287,111 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2293 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2291 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 36:
-#line 401 "src/parse-gram.y" /* yacc.c:1667  */
+#line 401 "src/parse-gram.y" /* yacc.c:1668  */
     {
       default_prec = true;
     }
-#line 2301 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2299 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 37:
-#line 405 "src/parse-gram.y" /* yacc.c:1667  */
+#line 405 "src/parse-gram.y" /* yacc.c:1668  */
     {
       default_prec = false;
     }
-#line 2309 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2307 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 38:
-#line 409 "src/parse-gram.y" /* yacc.c:1667  */
+#line 409 "src/parse-gram.y" /* yacc.c:1668  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2320 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2318 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 39:
-#line 416 "src/parse-gram.y" /* yacc.c:1667  */
+#line 416 "src/parse-gram.y" /* yacc.c:1668  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2329 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2327 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 40:
-#line 426 "src/parse-gram.y" /* yacc.c:1667  */
+#line 426 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.code_type) = destructor; }
-#line 2335 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2333 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 41:
-#line 427 "src/parse-gram.y" /* yacc.c:1667  */
+#line 427 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.code_type) = printer; }
-#line 2341 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2339 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 42:
-#line 437 "src/parse-gram.y" /* yacc.c:1667  */
+#line 437 "src/parse-gram.y" /* yacc.c:1668  */
     {}
-#line 2347 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2345 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 43:
-#line 438 "src/parse-gram.y" /* yacc.c:1667  */
+#line 438 "src/parse-gram.y" /* yacc.c:1668  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2353 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2351 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 44:
-#line 443 "src/parse-gram.y" /* yacc.c:1667  */
+#line 443 "src/parse-gram.y" /* yacc.c:1668  */
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2363 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2361 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 45:
-#line 454 "src/parse-gram.y" /* yacc.c:1667  */
+#line 454 "src/parse-gram.y" /* yacc.c:1668  */
     { current_class = nterm_sym; }
-#line 2369 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2367 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 46:
-#line 455 "src/parse-gram.y" /* yacc.c:1667  */
+#line 455 "src/parse-gram.y" /* yacc.c:1668  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2378 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2376 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 47:
-#line 459 "src/parse-gram.y" /* yacc.c:1667  */
+#line 459 "src/parse-gram.y" /* yacc.c:1668  */
     { current_class = token_sym; }
-#line 2384 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2382 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 48:
-#line 460 "src/parse-gram.y" /* yacc.c:1667  */
+#line 460 "src/parse-gram.y" /* yacc.c:1668  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2393 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2391 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 49:
-#line 465 "src/parse-gram.y" /* yacc.c:1667  */
+#line 465 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_list *list;
       tag_seen = true;
@@ -2402,11 +2399,11 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2405 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2403 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 50:
-#line 476 "src/parse-gram.y" /* yacc.c:1667  */
+#line 476 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_list *list;
       ++current_prec;
@@ -2418,276 +2415,276 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2421 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2419 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 51:
-#line 490 "src/parse-gram.y" /* yacc.c:1667  */
+#line 490 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = left_assoc; }
-#line 2427 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2425 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 52:
-#line 491 "src/parse-gram.y" /* yacc.c:1667  */
+#line 491 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = right_assoc; }
-#line 2433 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2431 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 53:
-#line 492 "src/parse-gram.y" /* yacc.c:1667  */
+#line 492 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = non_assoc; }
-#line 2439 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2437 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 54:
-#line 493 "src/parse-gram.y" /* yacc.c:1667  */
+#line 493 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2445 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2443 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 55:
-#line 497 "src/parse-gram.y" /* yacc.c:1667  */
+#line 497 "src/parse-gram.y" /* yacc.c:1668  */
     { current_type = NULL; }
-#line 2451 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2449 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 56:
-#line 498 "src/parse-gram.y" /* yacc.c:1667  */
+#line 498 "src/parse-gram.y" /* yacc.c:1668  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2457 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2455 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 57:
-#line 504 "src/parse-gram.y" /* yacc.c:1667  */
+#line 504 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2463 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2461 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 58:
-#line 506 "src/parse-gram.y" /* yacc.c:1667  */
+#line 506 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2469 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2467 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 59:
-#line 510 "src/parse-gram.y" /* yacc.c:1667  */
+#line 510 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.symbol) = (yyvsp[0].symbol); }
-#line 2475 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2473 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 60:
-#line 511 "src/parse-gram.y" /* yacc.c:1667  */
+#line 511 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-#line 2481 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2479 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 61:
-#line 517 "src/parse-gram.y" /* yacc.c:1667  */
+#line 517 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2487 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2485 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 62:
-#line 519 "src/parse-gram.y" /* yacc.c:1667  */
+#line 519 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2493 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2491 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 63:
-#line 523 "src/parse-gram.y" /* yacc.c:1667  */
+#line 523 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2499 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2497 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 64:
-#line 524 "src/parse-gram.y" /* yacc.c:1667  */
+#line 524 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2505 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2503 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 65:
-#line 528 "src/parse-gram.y" /* yacc.c:1667  */
+#line 528 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2511 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2509 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 66:
-#line 529 "src/parse-gram.y" /* yacc.c:1667  */
+#line 529 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2517 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2515 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 68:
-#line 534 "src/parse-gram.y" /* yacc.c:1667  */
+#line 534 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2523 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2521 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 69:
-#line 535 "src/parse-gram.y" /* yacc.c:1667  */
+#line 535 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2529 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2527 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 70:
-#line 541 "src/parse-gram.y" /* yacc.c:1667  */
+#line 541 "src/parse-gram.y" /* yacc.c:1668  */
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-#line 2538 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2536 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 71:
-#line 546 "src/parse-gram.y" /* yacc.c:1667  */
+#line 546 "src/parse-gram.y" /* yacc.c:1668  */
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-#line 2547 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2545 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 72:
-#line 551 "src/parse-gram.y" /* yacc.c:1667  */
+#line 551 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2557 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2555 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 73:
-#line 557 "src/parse-gram.y" /* yacc.c:1667  */
+#line 557 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2567 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2565 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 74:
-#line 563 "src/parse-gram.y" /* yacc.c:1667  */
+#line 563 "src/parse-gram.y" /* yacc.c:1668  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2578 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2576 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 81:
-#line 593 "src/parse-gram.y" /* yacc.c:1667  */
+#line 593 "src/parse-gram.y" /* yacc.c:1668  */
     {
       yyerrok;
     }
-#line 2586 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2584 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 82:
-#line 599 "src/parse-gram.y" /* yacc.c:1667  */
+#line 599 "src/parse-gram.y" /* yacc.c:1668  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2592 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2590 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 83:
-#line 600 "src/parse-gram.y" /* yacc.c:1667  */
+#line 600 "src/parse-gram.y" /* yacc.c:1668  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2601 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2599 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 84:
-#line 607 "src/parse-gram.y" /* yacc.c:1667  */
+#line 607 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2607 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2605 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 85:
-#line 608 "src/parse-gram.y" /* yacc.c:1667  */
+#line 608 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2613 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2611 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 87:
-#line 614 "src/parse-gram.y" /* yacc.c:1667  */
+#line 614 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2620 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2618 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 88:
-#line 617 "src/parse-gram.y" /* yacc.c:1667  */
+#line 617 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2626 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2624 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 89:
-#line 619 "src/parse-gram.y" /* yacc.c:1667  */
+#line 619 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2632 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2630 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 90:
-#line 621 "src/parse-gram.y" /* yacc.c:1667  */
+#line 621 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2638 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2636 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 91:
-#line 623 "src/parse-gram.y" /* yacc.c:1667  */
+#line 623 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2644 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2642 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 92:
-#line 625 "src/parse-gram.y" /* yacc.c:1667  */
+#line 625 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2650 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2648 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 93:
-#line 627 "src/parse-gram.y" /* yacc.c:1667  */
+#line 627 "src/parse-gram.y" /* yacc.c:1668  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2656 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2654 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 94:
-#line 631 "src/parse-gram.y" /* yacc.c:1667  */
+#line 631 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.named_ref) = 0; }
-#line 2662 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2660 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 95:
-#line 633 "src/parse-gram.y" /* yacc.c:1667  */
+#line 633 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2668 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2666 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 97:
-#line 644 "src/parse-gram.y" /* yacc.c:1667  */
+#line 644 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-#line 2674 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2672 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 98:
-#line 649 "src/parse-gram.y" /* yacc.c:1667  */
+#line 649 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.chars) = ""; }
-#line 2680 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2678 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 99:
-#line 650 "src/parse-gram.y" /* yacc.c:1667  */
+#line 650 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-#line 2686 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2684 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 101:
-#line 661 "src/parse-gram.y" /* yacc.c:1667  */
+#line 661 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2696,42 +2693,42 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-#line 2699 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2697 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 102:
-#line 681 "src/parse-gram.y" /* yacc.c:1667  */
+#line 681 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2705 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2703 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 103:
-#line 683 "src/parse-gram.y" /* yacc.c:1667  */
+#line 683 "src/parse-gram.y" /* yacc.c:1668  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2715 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2713 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 104:
-#line 691 "src/parse-gram.y" /* yacc.c:1667  */
+#line 691 "src/parse-gram.y" /* yacc.c:1668  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2721 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2719 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 107:
-#line 703 "src/parse-gram.y" /* yacc.c:1667  */
+#line 703 "src/parse-gram.y" /* yacc.c:1668  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2730 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2728 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
   case 109:
-#line 712 "src/parse-gram.y" /* yacc.c:1667  */
+#line 712 "src/parse-gram.y" /* yacc.c:1668  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2740,11 +2737,11 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2743 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2741 "src/parse-gram.c" /* yacc.c:1668  */
     break;
 
 
-#line 2747 "src/parse-gram.c" /* yacc.c:1667  */
+#line 2745 "src/parse-gram.c" /* yacc.c:1668  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2991,7 +2988,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 722 "src/parse-gram.y" /* yacc.c:1927  */
+#line 722 "src/parse-gram.y" /* yacc.c:1928  */
 
 
 /* Return the location of the left-hand side of a rule whose
