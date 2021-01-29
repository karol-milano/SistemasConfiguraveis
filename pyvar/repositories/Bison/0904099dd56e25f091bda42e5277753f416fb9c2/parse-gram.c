@@ -72,8 +72,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 356 of yacc.c  */
-#line 1 "src/parse-gram.y"
+#line 1 "src/parse-gram.y" /* yacc.c:356  */
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002-2012 Free Software Foundation, Inc.
@@ -129,8 +128,7 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/* Line 356 of yacc.c  */
-#line 134 "src/parse-gram.c"
+#line 132 "src/parse-gram.c" /* yacc.c:356  */
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -168,8 +166,7 @@ static char const *char_name (char);
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-/* Line 372 of yacc.c  */
-#line 223 "src/parse-gram.y"
+#line 223 "src/parse-gram.y" /* yacc.c:372  */
 
 # ifndef PARAM_TYPE
 #  define PARAM_TYPE
@@ -183,8 +180,7 @@ extern int gram_debug;
 # endif
 
 
-/* Line 372 of yacc.c  */
-#line 188 "src/parse-gram.c"
+#line 184 "src/parse-gram.c" /* yacc.c:372  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -310,8 +306,7 @@ extern int gram_debug;
 typedef union GRAM_STYPE GRAM_STYPE;
 union GRAM_STYPE
 {
-/* Line 372 of yacc.c  */
-#line 109 "src/parse-gram.y"
+#line 109 "src/parse-gram.y" /* yacc.c:372  */
 
   assoc assoc;
   char *code;
@@ -323,17 +318,14 @@ union GRAM_STYPE
   uniqstr uniqstr;
   unsigned char character;
 
-/* Line 372 of yacc.c  */
-#line 247 "src/parse-gram.y"
+#line 247 "src/parse-gram.y" /* yacc.c:372  */
 
   param_type param;
 
-/* Line 372 of yacc.c  */
-#line 423 "src/parse-gram.y"
+#line 423 "src/parse-gram.y" /* yacc.c:372  */
 code_props_type code_type;
 
-/* Line 372 of yacc.c  */
-#line 337 "src/parse-gram.c"
+#line 329 "src/parse-gram.c" /* yacc.c:372  */
 };
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
@@ -361,11 +353,9 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-/* Line 375 of yacc.c  */
-#line 366 "src/parse-gram.c"
+#line 357 "src/parse-gram.c" /* yacc.c:375  */
 /* Unqualified %code blocks.  */
-/* Line 376 of yacc.c  */
-#line 58 "src/parse-gram.y"
+#line 58 "src/parse-gram.y" /* yacc.c:376  */
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -397,8 +387,7 @@ int gram_parse (void);
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 376 of yacc.c  */
-#line 236 "src/parse-gram.y"
+#line 236 "src/parse-gram.y" /* yacc.c:376  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -410,8 +399,7 @@ int gram_parse (void);
   static param_type current_param = param_none;
 
 
-/* Line 376 of yacc.c  */
-#line 415 "src/parse-gram.c"
+#line 403 "src/parse-gram.c" /* yacc.c:376  */
 
 #ifdef short
 # undef short
@@ -1023,96 +1011,73 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
     case 3: /* "string"  */
-/* Line 705 of yacc.c  */
-#line 196 "src/parse-gram.y"
+#line 196 "src/parse-gram.y" /* yacc.c:705  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-/* Line 705 of yacc.c  */
-#line 1031 "src/parse-gram.c"
+#line 1017 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 4: /* "integer"  */
-/* Line 705 of yacc.c  */
-#line 209 "src/parse-gram.y"
+#line 209 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-/* Line 705 of yacc.c  */
-#line 1039 "src/parse-gram.c"
+#line 1023 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 24: /* "%<flag>"  */
-/* Line 705 of yacc.c  */
-#line 205 "src/parse-gram.y"
+#line 205 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 705 of yacc.c  */
-#line 1047 "src/parse-gram.c"
+#line 1029 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 40: /* "{...}"  */
-/* Line 705 of yacc.c  */
-#line 198 "src/parse-gram.y"
+#line 198 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 705 of yacc.c  */
-#line 1055 "src/parse-gram.c"
+#line 1035 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 42: /* "[identifier]"  */
-/* Line 705 of yacc.c  */
-#line 203 "src/parse-gram.y"
+#line 203 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 705 of yacc.c  */
-#line 1063 "src/parse-gram.c"
+#line 1041 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 43: /* "char"  */
-/* Line 705 of yacc.c  */
-#line 190 "src/parse-gram.y"
+#line 190 "src/parse-gram.y" /* yacc.c:705  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-/* Line 705 of yacc.c  */
-#line 1071 "src/parse-gram.c"
+#line 1047 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 44: /* "epilogue"  */
-/* Line 705 of yacc.c  */
-#line 198 "src/parse-gram.y"
+#line 198 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 705 of yacc.c  */
-#line 1079 "src/parse-gram.c"
+#line 1053 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 46: /* "identifier"  */
-/* Line 705 of yacc.c  */
-#line 202 "src/parse-gram.y"
+#line 202 "src/parse-gram.y" /* yacc.c:705  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 705 of yacc.c  */
-#line 1087 "src/parse-gram.c"
+#line 1059 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 47: /* "identifier:"  */
-/* Line 705 of yacc.c  */
-#line 204 "src/parse-gram.y"
+#line 204 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 705 of yacc.c  */
-#line 1095 "src/parse-gram.c"
+#line 1065 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 50: /* "%{...%}"  */
-/* Line 705 of yacc.c  */
-#line 198 "src/parse-gram.y"
+#line 198 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 705 of yacc.c  */
-#line 1103 "src/parse-gram.c"
+#line 1071 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 52: /* "<tag>"  */
-/* Line 705 of yacc.c  */
-#line 206 "src/parse-gram.y"
+#line 206 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 705 of yacc.c  */
-#line 1111 "src/parse-gram.c"
+#line 1077 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 55: /* "%param"  */
-/* Line 705 of yacc.c  */
-#line 252 "src/parse-gram.y"
+#line 252 "src/parse-gram.y" /* yacc.c:705  */
       {
   switch (((*yyvaluep).param))
     {
@@ -1125,88 +1090,67 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-/* Line 705 of yacc.c  */
-#line 1130 "src/parse-gram.c"
+#line 1094 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 64: /* code_props_type  */
-/* Line 705 of yacc.c  */
-#line 424 "src/parse-gram.y"
+#line 424 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-/* Line 705 of yacc.c  */
-#line 1138 "src/parse-gram.c"
+#line 1100 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 73: /* symbol.prec  */
-/* Line 705 of yacc.c  */
-#line 212 "src/parse-gram.y"
+#line 212 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 705 of yacc.c  */
-#line 1146 "src/parse-gram.c"
+#line 1106 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 77: /* tag  */
-/* Line 705 of yacc.c  */
-#line 206 "src/parse-gram.y"
+#line 206 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 705 of yacc.c  */
-#line 1154 "src/parse-gram.c"
+#line 1112 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 87: /* variable  */
-/* Line 705 of yacc.c  */
-#line 202 "src/parse-gram.y"
+#line 202 "src/parse-gram.y" /* yacc.c:705  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 705 of yacc.c  */
-#line 1162 "src/parse-gram.c"
+#line 1118 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 88: /* content.opt  */
-/* Line 705 of yacc.c  */
-#line 198 "src/parse-gram.y"
+#line 198 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 705 of yacc.c  */
-#line 1170 "src/parse-gram.c"
+#line 1124 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 89: /* braceless  */
-/* Line 705 of yacc.c  */
-#line 198 "src/parse-gram.y"
+#line 198 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 705 of yacc.c  */
-#line 1178 "src/parse-gram.c"
+#line 1130 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 90: /* id  */
-/* Line 705 of yacc.c  */
-#line 212 "src/parse-gram.y"
+#line 212 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 705 of yacc.c  */
-#line 1186 "src/parse-gram.c"
+#line 1136 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 91: /* id_colon  */
-/* Line 705 of yacc.c  */
-#line 213 "src/parse-gram.y"
+#line 213 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 705 of yacc.c  */
-#line 1194 "src/parse-gram.c"
+#line 1142 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 92: /* symbol  */
-/* Line 705 of yacc.c  */
-#line 212 "src/parse-gram.y"
+#line 212 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 705 of yacc.c  */
-#line 1202 "src/parse-gram.c"
+#line 1148 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
     case 93: /* string_as_id  */
-/* Line 705 of yacc.c  */
-#line 212 "src/parse-gram.y"
+#line 212 "src/parse-gram.y" /* yacc.c:705  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 705 of yacc.c  */
-#line 1210 "src/parse-gram.c"
+#line 1154 "src/parse-gram.c" /* yacc.c:705  */
         break;
 
       default:
@@ -1923,16 +1867,14 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-/* Line 1450 of yacc.c  */
-#line 101 "src/parse-gram.y"
+#line 101 "src/parse-gram.y" /* yacc.c:1450  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1450 of yacc.c  */
-#line 1936 "src/parse-gram.c"
+#line 1878 "src/parse-gram.c" /* yacc.c:1450  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2126,8 +2068,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1667 of yacc.c  */
-#line 288 "src/parse-gram.y"
+#line 288 "src/parse-gram.y" /* yacc.c:1667  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2137,99 +2078,79 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1667 of yacc.c  */
-#line 2142 "src/parse-gram.c"
+#line 2082 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 7:
-/* Line 1667 of yacc.c  */
-#line 298 "src/parse-gram.y"
+#line 298 "src/parse-gram.y" /* yacc.c:1667  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1667 of yacc.c  */
-#line 2152 "src/parse-gram.c"
+#line 2090 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 8:
-/* Line 1667 of yacc.c  */
-#line 302 "src/parse-gram.y"
+#line 302 "src/parse-gram.y" /* yacc.c:1667  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1667 of yacc.c  */
-#line 2163 "src/parse-gram.c"
+#line 2099 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 9:
-/* Line 1667 of yacc.c  */
-#line 306 "src/parse-gram.y"
+#line 306 "src/parse-gram.y" /* yacc.c:1667  */
     { defines_flag = true; }
-/* Line 1667 of yacc.c  */
-#line 2171 "src/parse-gram.c"
+#line 2105 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 10:
-/* Line 1667 of yacc.c  */
-#line 308 "src/parse-gram.y"
+#line 308 "src/parse-gram.y" /* yacc.c:1667  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1667 of yacc.c  */
-#line 2182 "src/parse-gram.c"
+#line 2114 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 11:
-/* Line 1667 of yacc.c  */
-#line 313 "src/parse-gram.y"
+#line 313 "src/parse-gram.y" /* yacc.c:1667  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1667 of yacc.c  */
-#line 2193 "src/parse-gram.c"
+#line 2123 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 12:
-/* Line 1667 of yacc.c  */
-#line 317 "src/parse-gram.y"
+#line 317 "src/parse-gram.y" /* yacc.c:1667  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1667 of yacc.c  */
-#line 2201 "src/parse-gram.c"
+#line 2129 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 13:
-/* Line 1667 of yacc.c  */
-#line 318 "src/parse-gram.y"
+#line 318 "src/parse-gram.y" /* yacc.c:1667  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1667 of yacc.c  */
-#line 2209 "src/parse-gram.c"
+#line 2135 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 14:
-/* Line 1667 of yacc.c  */
-#line 319 "src/parse-gram.y"
+#line 319 "src/parse-gram.y" /* yacc.c:1667  */
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1667 of yacc.c  */
-#line 2217 "src/parse-gram.c"
+#line 2141 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 15:
-/* Line 1667 of yacc.c  */
-#line 321 "src/parse-gram.y"
+#line 321 "src/parse-gram.y" /* yacc.c:1667  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1667 of yacc.c  */
-#line 2228 "src/parse-gram.c"
+#line 2150 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 16:
-/* Line 1667 of yacc.c  */
-#line 326 "src/parse-gram.y"
+#line 326 "src/parse-gram.y" /* yacc.c:1667  */
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2238,77 +2159,59 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1667 of yacc.c  */
-#line 2243 "src/parse-gram.c"
+#line 2163 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 17:
-/* Line 1667 of yacc.c  */
-#line 334 "src/parse-gram.y"
+#line 334 "src/parse-gram.y" /* yacc.c:1667  */
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1667 of yacc.c  */
-#line 2251 "src/parse-gram.c"
+#line 2169 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 18:
-/* Line 1667 of yacc.c  */
-#line 335 "src/parse-gram.y"
+#line 335 "src/parse-gram.y" /* yacc.c:1667  */
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1667 of yacc.c  */
-#line 2259 "src/parse-gram.c"
+#line 2175 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 19:
-/* Line 1667 of yacc.c  */
-#line 336 "src/parse-gram.y"
+#line 336 "src/parse-gram.y" /* yacc.c:1667  */
     { no_lines_flag = true; }
-/* Line 1667 of yacc.c  */
-#line 2267 "src/parse-gram.c"
+#line 2181 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 20:
-/* Line 1667 of yacc.c  */
-#line 337 "src/parse-gram.y"
+#line 337 "src/parse-gram.y" /* yacc.c:1667  */
     { nondeterministic_parser = true; }
-/* Line 1667 of yacc.c  */
-#line 2275 "src/parse-gram.c"
+#line 2187 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 21:
-/* Line 1667 of yacc.c  */
-#line 338 "src/parse-gram.y"
+#line 338 "src/parse-gram.y" /* yacc.c:1667  */
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1667 of yacc.c  */
-#line 2283 "src/parse-gram.c"
+#line 2193 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 22:
-/* Line 1667 of yacc.c  */
-#line 339 "src/parse-gram.y"
+#line 339 "src/parse-gram.y" /* yacc.c:1667  */
     { current_param = (yyvsp[0].param); }
-/* Line 1667 of yacc.c  */
-#line 2291 "src/parse-gram.c"
+#line 2199 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 23:
-/* Line 1667 of yacc.c  */
-#line 339 "src/parse-gram.y"
+#line 339 "src/parse-gram.y" /* yacc.c:1667  */
     { current_param = param_none; }
-/* Line 1667 of yacc.c  */
-#line 2299 "src/parse-gram.c"
+#line 2205 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 24:
-/* Line 1667 of yacc.c  */
-#line 340 "src/parse-gram.y"
+#line 340 "src/parse-gram.y" /* yacc.c:1667  */
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1667 of yacc.c  */
-#line 2307 "src/parse-gram.c"
+#line 2211 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 25:
-/* Line 1667 of yacc.c  */
-#line 342 "src/parse-gram.y"
+#line 342 "src/parse-gram.y" /* yacc.c:1667  */
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2332,63 +2235,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1667 of yacc.c  */
-#line 2337 "src/parse-gram.c"
+#line 2239 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 26:
-/* Line 1667 of yacc.c  */
-#line 365 "src/parse-gram.y"
+#line 365 "src/parse-gram.y" /* yacc.c:1667  */
     { token_table_flag = true; }
-/* Line 1667 of yacc.c  */
-#line 2345 "src/parse-gram.c"
+#line 2245 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 27:
-/* Line 1667 of yacc.c  */
-#line 366 "src/parse-gram.y"
+#line 366 "src/parse-gram.y" /* yacc.c:1667  */
     { report_flag |= report_states; }
-/* Line 1667 of yacc.c  */
-#line 2353 "src/parse-gram.c"
+#line 2251 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 28:
-/* Line 1667 of yacc.c  */
-#line 367 "src/parse-gram.y"
+#line 367 "src/parse-gram.y" /* yacc.c:1667  */
     { yacc_flag = true; }
-/* Line 1667 of yacc.c  */
-#line 2361 "src/parse-gram.c"
+#line 2257 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 30:
-/* Line 1667 of yacc.c  */
-#line 372 "src/parse-gram.y"
+#line 372 "src/parse-gram.y" /* yacc.c:1667  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2369 "src/parse-gram.c"
+#line 2263 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 31:
-/* Line 1667 of yacc.c  */
-#line 373 "src/parse-gram.y"
+#line 373 "src/parse-gram.y" /* yacc.c:1667  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2377 "src/parse-gram.c"
+#line 2269 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 34:
-/* Line 1667 of yacc.c  */
-#line 385 "src/parse-gram.y"
+#line 385 "src/parse-gram.y" /* yacc.c:1667  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1667 of yacc.c  */
-#line 2387 "src/parse-gram.c"
+#line 2277 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 35:
-/* Line 1667 of yacc.c  */
-#line 389 "src/parse-gram.y"
+#line 389 "src/parse-gram.y" /* yacc.c:1667  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2400,139 +2289,111 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-/* Line 1667 of yacc.c  */
-#line 2405 "src/parse-gram.c"
+#line 2293 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 36:
-/* Line 1667 of yacc.c  */
-#line 401 "src/parse-gram.y"
+#line 401 "src/parse-gram.y" /* yacc.c:1667  */
     {
       default_prec = true;
     }
-/* Line 1667 of yacc.c  */
-#line 2415 "src/parse-gram.c"
+#line 2301 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 37:
-/* Line 1667 of yacc.c  */
-#line 405 "src/parse-gram.y"
+#line 405 "src/parse-gram.y" /* yacc.c:1667  */
     {
       default_prec = false;
     }
-/* Line 1667 of yacc.c  */
-#line 2425 "src/parse-gram.c"
+#line 2309 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 38:
-/* Line 1667 of yacc.c  */
-#line 409 "src/parse-gram.y"
+#line 409 "src/parse-gram.y" /* yacc.c:1667  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1667 of yacc.c  */
-#line 2438 "src/parse-gram.c"
+#line 2320 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 39:
-/* Line 1667 of yacc.c  */
-#line 416 "src/parse-gram.y"
+#line 416 "src/parse-gram.y" /* yacc.c:1667  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1667 of yacc.c  */
-#line 2449 "src/parse-gram.c"
+#line 2329 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 40:
-/* Line 1667 of yacc.c  */
-#line 426 "src/parse-gram.y"
+#line 426 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.code_type) = destructor; }
-/* Line 1667 of yacc.c  */
-#line 2457 "src/parse-gram.c"
+#line 2335 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 41:
-/* Line 1667 of yacc.c  */
-#line 427 "src/parse-gram.y"
+#line 427 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.code_type) = printer; }
-/* Line 1667 of yacc.c  */
-#line 2465 "src/parse-gram.c"
+#line 2341 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 42:
-/* Line 1667 of yacc.c  */
-#line 437 "src/parse-gram.y"
+#line 437 "src/parse-gram.y" /* yacc.c:1667  */
     {}
-/* Line 1667 of yacc.c  */
-#line 2473 "src/parse-gram.c"
+#line 2347 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 43:
-/* Line 1667 of yacc.c  */
-#line 438 "src/parse-gram.y"
+#line 438 "src/parse-gram.y" /* yacc.c:1667  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2481 "src/parse-gram.c"
+#line 2353 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 44:
-/* Line 1667 of yacc.c  */
-#line 443 "src/parse-gram.y"
+#line 443 "src/parse-gram.y" /* yacc.c:1667  */
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1667 of yacc.c  */
-#line 2493 "src/parse-gram.c"
+#line 2363 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 45:
-/* Line 1667 of yacc.c  */
-#line 454 "src/parse-gram.y"
+#line 454 "src/parse-gram.y" /* yacc.c:1667  */
     { current_class = nterm_sym; }
-/* Line 1667 of yacc.c  */
-#line 2501 "src/parse-gram.c"
+#line 2369 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 46:
-/* Line 1667 of yacc.c  */
-#line 455 "src/parse-gram.y"
+#line 455 "src/parse-gram.y" /* yacc.c:1667  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1667 of yacc.c  */
-#line 2512 "src/parse-gram.c"
+#line 2378 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 47:
-/* Line 1667 of yacc.c  */
-#line 459 "src/parse-gram.y"
+#line 459 "src/parse-gram.y" /* yacc.c:1667  */
     { current_class = token_sym; }
-/* Line 1667 of yacc.c  */
-#line 2520 "src/parse-gram.c"
+#line 2384 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 48:
-/* Line 1667 of yacc.c  */
-#line 460 "src/parse-gram.y"
+#line 460 "src/parse-gram.y" /* yacc.c:1667  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1667 of yacc.c  */
-#line 2531 "src/parse-gram.c"
+#line 2393 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 49:
-/* Line 1667 of yacc.c  */
-#line 465 "src/parse-gram.y"
+#line 465 "src/parse-gram.y" /* yacc.c:1667  */
     {
       symbol_list *list;
       tag_seen = true;
@@ -2540,13 +2401,11 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1667 of yacc.c  */
-#line 2545 "src/parse-gram.c"
+#line 2405 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 50:
-/* Line 1667 of yacc.c  */
-#line 476 "src/parse-gram.y"
+#line 476 "src/parse-gram.y" /* yacc.c:1667  */
     {
       symbol_list *list;
       ++current_prec;
@@ -2558,358 +2417,276 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1667 of yacc.c  */
-#line 2563 "src/parse-gram.c"
+#line 2421 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 51:
-/* Line 1667 of yacc.c  */
-#line 490 "src/parse-gram.y"
+#line 490 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.assoc) = left_assoc; }
-/* Line 1667 of yacc.c  */
-#line 2571 "src/parse-gram.c"
+#line 2427 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 52:
-/* Line 1667 of yacc.c  */
-#line 491 "src/parse-gram.y"
+#line 491 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.assoc) = right_assoc; }
-/* Line 1667 of yacc.c  */
-#line 2579 "src/parse-gram.c"
+#line 2433 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 53:
-/* Line 1667 of yacc.c  */
-#line 492 "src/parse-gram.y"
+#line 492 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.assoc) = non_assoc; }
-/* Line 1667 of yacc.c  */
-#line 2587 "src/parse-gram.c"
+#line 2439 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 54:
-/* Line 1667 of yacc.c  */
-#line 493 "src/parse-gram.y"
+#line 493 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1667 of yacc.c  */
-#line 2595 "src/parse-gram.c"
+#line 2445 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 55:
-/* Line 1667 of yacc.c  */
-#line 497 "src/parse-gram.y"
+#line 497 "src/parse-gram.y" /* yacc.c:1667  */
     { current_type = NULL; }
-/* Line 1667 of yacc.c  */
-#line 2603 "src/parse-gram.c"
+#line 2451 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 56:
-/* Line 1667 of yacc.c  */
-#line 498 "src/parse-gram.y"
+#line 498 "src/parse-gram.y" /* yacc.c:1667  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1667 of yacc.c  */
-#line 2611 "src/parse-gram.c"
+#line 2457 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 57:
-/* Line 1667 of yacc.c  */
-#line 504 "src/parse-gram.y"
+#line 504 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2619 "src/parse-gram.c"
+#line 2463 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 58:
-/* Line 1667 of yacc.c  */
-#line 506 "src/parse-gram.y"
+#line 506 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1667 of yacc.c  */
-#line 2627 "src/parse-gram.c"
+#line 2469 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 59:
-/* Line 1667 of yacc.c  */
-#line 510 "src/parse-gram.y"
+#line 510 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1667 of yacc.c  */
-#line 2635 "src/parse-gram.c"
+#line 2475 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 60:
-/* Line 1667 of yacc.c  */
-#line 511 "src/parse-gram.y"
+#line 511 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2643 "src/parse-gram.c"
+#line 2481 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 61:
-/* Line 1667 of yacc.c  */
-#line 517 "src/parse-gram.y"
+#line 517 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2651 "src/parse-gram.c"
+#line 2487 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 62:
-/* Line 1667 of yacc.c  */
-#line 519 "src/parse-gram.y"
+#line 519 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1667 of yacc.c  */
-#line 2659 "src/parse-gram.c"
+#line 2493 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 63:
-/* Line 1667 of yacc.c  */
-#line 523 "src/parse-gram.y"
+#line 523 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1667 of yacc.c  */
-#line 2667 "src/parse-gram.c"
+#line 2499 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 64:
-/* Line 1667 of yacc.c  */
-#line 524 "src/parse-gram.y"
+#line 524 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1667 of yacc.c  */
-#line 2675 "src/parse-gram.c"
+#line 2505 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 65:
-/* Line 1667 of yacc.c  */
-#line 528 "src/parse-gram.y"
+#line 528 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2683 "src/parse-gram.c"
+#line 2511 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 66:
-/* Line 1667 of yacc.c  */
-#line 529 "src/parse-gram.y"
+#line 529 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2691 "src/parse-gram.c"
+#line 2517 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 68:
-/* Line 1667 of yacc.c  */
-#line 534 "src/parse-gram.y"
+#line 534 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-/* Line 1667 of yacc.c  */
-#line 2699 "src/parse-gram.c"
+#line 2523 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 69:
-/* Line 1667 of yacc.c  */
-#line 535 "src/parse-gram.y"
+#line 535 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-/* Line 1667 of yacc.c  */
-#line 2707 "src/parse-gram.c"
+#line 2529 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 70:
-/* Line 1667 of yacc.c  */
-#line 541 "src/parse-gram.y"
+#line 541 "src/parse-gram.y" /* yacc.c:1667  */
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1667 of yacc.c  */
-#line 2718 "src/parse-gram.c"
+#line 2538 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 71:
-/* Line 1667 of yacc.c  */
-#line 546 "src/parse-gram.y"
+#line 546 "src/parse-gram.y" /* yacc.c:1667  */
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1667 of yacc.c  */
-#line 2729 "src/parse-gram.c"
+#line 2547 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 72:
-/* Line 1667 of yacc.c  */
-#line 551 "src/parse-gram.y"
+#line 551 "src/parse-gram.y" /* yacc.c:1667  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1667 of yacc.c  */
-#line 2741 "src/parse-gram.c"
+#line 2557 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 73:
-/* Line 1667 of yacc.c  */
-#line 557 "src/parse-gram.y"
+#line 557 "src/parse-gram.y" /* yacc.c:1667  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1667 of yacc.c  */
-#line 2753 "src/parse-gram.c"
+#line 2567 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 74:
-/* Line 1667 of yacc.c  */
-#line 563 "src/parse-gram.y"
+#line 563 "src/parse-gram.y" /* yacc.c:1667  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1667 of yacc.c  */
-#line 2766 "src/parse-gram.c"
+#line 2578 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 81:
-/* Line 1667 of yacc.c  */
-#line 593 "src/parse-gram.y"
+#line 593 "src/parse-gram.y" /* yacc.c:1667  */
     {
       yyerrok;
     }
-/* Line 1667 of yacc.c  */
-#line 2776 "src/parse-gram.c"
+#line 2586 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 82:
-/* Line 1667 of yacc.c  */
-#line 599 "src/parse-gram.y"
+#line 599 "src/parse-gram.y" /* yacc.c:1667  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1667 of yacc.c  */
-#line 2784 "src/parse-gram.c"
+#line 2592 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 83:
-/* Line 1667 of yacc.c  */
-#line 600 "src/parse-gram.y"
+#line 600 "src/parse-gram.y" /* yacc.c:1667  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1667 of yacc.c  */
-#line 2795 "src/parse-gram.c"
+#line 2601 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 84:
-/* Line 1667 of yacc.c  */
-#line 607 "src/parse-gram.y"
+#line 607 "src/parse-gram.y" /* yacc.c:1667  */
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2803 "src/parse-gram.c"
+#line 2607 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 85:
-/* Line 1667 of yacc.c  */
-#line 608 "src/parse-gram.y"
+#line 608 "src/parse-gram.y" /* yacc.c:1667  */
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2811 "src/parse-gram.c"
+#line 2613 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 87:
-/* Line 1667 of yacc.c  */
-#line 614 "src/parse-gram.y"
+#line 614 "src/parse-gram.y" /* yacc.c:1667  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1667 of yacc.c  */
-#line 2820 "src/parse-gram.c"
+#line 2620 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 88:
-/* Line 1667 of yacc.c  */
-#line 617 "src/parse-gram.y"
+#line 617 "src/parse-gram.y" /* yacc.c:1667  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1667 of yacc.c  */
-#line 2828 "src/parse-gram.c"
+#line 2626 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 89:
-/* Line 1667 of yacc.c  */
-#line 619 "src/parse-gram.y"
+#line 619 "src/parse-gram.y" /* yacc.c:1667  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1667 of yacc.c  */
-#line 2836 "src/parse-gram.c"
+#line 2632 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 90:
-/* Line 1667 of yacc.c  */
-#line 621 "src/parse-gram.y"
+#line 621 "src/parse-gram.y" /* yacc.c:1667  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1667 of yacc.c  */
-#line 2844 "src/parse-gram.c"
+#line 2638 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 91:
-/* Line 1667 of yacc.c  */
-#line 623 "src/parse-gram.y"
+#line 623 "src/parse-gram.y" /* yacc.c:1667  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2852 "src/parse-gram.c"
+#line 2644 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 92:
-/* Line 1667 of yacc.c  */
-#line 625 "src/parse-gram.y"
+#line 625 "src/parse-gram.y" /* yacc.c:1667  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2860 "src/parse-gram.c"
+#line 2650 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 93:
-/* Line 1667 of yacc.c  */
-#line 627 "src/parse-gram.y"
+#line 627 "src/parse-gram.y" /* yacc.c:1667  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2868 "src/parse-gram.c"
+#line 2656 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 94:
-/* Line 1667 of yacc.c  */
-#line 631 "src/parse-gram.y"
+#line 631 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.named_ref) = 0; }
-/* Line 1667 of yacc.c  */
-#line 2876 "src/parse-gram.c"
+#line 2662 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 95:
-/* Line 1667 of yacc.c  */
-#line 633 "src/parse-gram.y"
+#line 633 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2884 "src/parse-gram.c"
+#line 2668 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 97:
-/* Line 1667 of yacc.c  */
-#line 644 "src/parse-gram.y"
+#line 644 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1667 of yacc.c  */
-#line 2892 "src/parse-gram.c"
+#line 2674 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 98:
-/* Line 1667 of yacc.c  */
-#line 649 "src/parse-gram.y"
+#line 649 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.chars) = ""; }
-/* Line 1667 of yacc.c  */
-#line 2900 "src/parse-gram.c"
+#line 2680 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 99:
-/* Line 1667 of yacc.c  */
-#line 650 "src/parse-gram.y"
+#line 650 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1667 of yacc.c  */
-#line 2908 "src/parse-gram.c"
+#line 2686 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 101:
-/* Line 1667 of yacc.c  */
-#line 661 "src/parse-gram.y"
+#line 661 "src/parse-gram.y" /* yacc.c:1667  */
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2918,52 +2695,42 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1667 of yacc.c  */
-#line 2923 "src/parse-gram.c"
+#line 2699 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 102:
-/* Line 1667 of yacc.c  */
-#line 681 "src/parse-gram.y"
+#line 681 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2931 "src/parse-gram.c"
+#line 2705 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 103:
-/* Line 1667 of yacc.c  */
-#line 683 "src/parse-gram.y"
+#line 683 "src/parse-gram.y" /* yacc.c:1667  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1667 of yacc.c  */
-#line 2943 "src/parse-gram.c"
+#line 2715 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 104:
-/* Line 1667 of yacc.c  */
-#line 691 "src/parse-gram.y"
+#line 691 "src/parse-gram.y" /* yacc.c:1667  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1667 of yacc.c  */
-#line 2951 "src/parse-gram.c"
+#line 2721 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 107:
-/* Line 1667 of yacc.c  */
-#line 703 "src/parse-gram.y"
+#line 703 "src/parse-gram.y" /* yacc.c:1667  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1667 of yacc.c  */
-#line 2962 "src/parse-gram.c"
+#line 2730 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
   case 109:
-/* Line 1667 of yacc.c  */
-#line 712 "src/parse-gram.y"
+#line 712 "src/parse-gram.y" /* yacc.c:1667  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2972,13 +2739,11 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1667 of yacc.c  */
-#line 2977 "src/parse-gram.c"
+#line 2743 "src/parse-gram.c" /* yacc.c:1667  */
     break;
 
 
-/* Line 1667 of yacc.c  */
-#line 2982 "src/parse-gram.c"
+#line 2747 "src/parse-gram.c" /* yacc.c:1667  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3225,8 +2990,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-/* Line 1927 of yacc.c  */
-#line 722 "src/parse-gram.y"
+#line 722 "src/parse-gram.y" /* yacc.c:1927  */
 
 
 /* Return the location of the left-hand side of a rule whose
