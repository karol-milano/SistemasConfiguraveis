@@ -73,7 +73,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 191 of yacc.c  */
+/* Line 253 of yacc.c  */
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -128,7 +128,7 @@ static void gram_error (location const *, char const *);
 
 static char const *char_name (char);
 
-/* Line 191 of yacc.c  */
+/* Line 253 of yacc.c  */
 #line 133 "src/parse-gram.c"
 
 /* Enabling traces.  */
@@ -150,7 +150,7 @@ static char const *char_name (char);
 #endif
 
 /* "%code requires" blocks.  */
-/* Line 211 of yacc.c  */
+/* Line 273 of yacc.c  */
 #line 201 "src/parse-gram.y"
 
 # ifndef PARAM_TYPE
@@ -165,7 +165,7 @@ static char const *char_name (char);
 # endif
 
 
-/* Line 211 of yacc.c  */
+/* Line 273 of yacc.c  */
 #line 170 "src/parse-gram.c"
 
 /* Tokens.  */
@@ -292,7 +292,7 @@ static char const *char_name (char);
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 216 of yacc.c  */
+/* Line 278 of yacc.c  */
 #line 88 "src/parse-gram.y"
 
   assoc assoc;
@@ -305,13 +305,13 @@ typedef union YYSTYPE
   uniqstr uniqstr;
   unsigned char character;
 
-/* Line 216 of yacc.c  */
+/* Line 278 of yacc.c  */
 #line 225 "src/parse-gram.y"
 
   param_type param;
 
 
-/* Line 216 of yacc.c  */
+/* Line 278 of yacc.c  */
 #line 316 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
@@ -335,10 +335,10 @@ typedef struct YYLTYPE
 
 /* Copy the second part of user declarations.  */
 
-/* Line 266 of yacc.c  */
+/* Line 328 of yacc.c  */
 #line 340 "src/parse-gram.c"
 /* Unqualified %code blocks.  */
-/* Line 267 of yacc.c  */
+/* Line 329 of yacc.c  */
 #line 56 "src/parse-gram.y"
 
   static int current_prec = 0;
@@ -353,7 +353,7 @@ typedef struct YYLTYPE
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 267 of yacc.c  */
+/* Line 329 of yacc.c  */
 #line 214 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
@@ -366,7 +366,7 @@ typedef struct YYLTYPE
   static param_type current_param = param_none;
 
 
-/* Line 267 of yacc.c  */
+/* Line 329 of yacc.c  */
 #line 371 "src/parse-gram.c"
 
 #ifdef short
@@ -1026,97 +1026,97 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
             case 3: // "string"
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 175 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1034 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 188 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1043 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 184 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1052 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1061 "src/parse-gram.c"
         break;
 
             case 41: // "char"
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 169 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1070 "src/parse-gram.c"
         break;
 
             case 42: // "epilogue"
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1079 "src/parse-gram.c"
         break;
 
             case 44: // "identifier"
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 182 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1088 "src/parse-gram.c"
         break;
 
             case 45: // "identifier:"
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 183 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1097 "src/parse-gram.c"
         break;
 
             case 48: // "%{...%}"
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1106 "src/parse-gram.c"
         break;
 
             case 50: // "<tag>"
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 185 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1115 "src/parse-gram.c"
         break;
 
             case 54: // "%param"
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 230 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1130,70 +1130,70 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case param_none: aver (false); break;
     }
 }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1135 "src/parse-gram.c"
         break;
 
             case 84: // variable
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 182 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1144 "src/parse-gram.c"
         break;
 
             case 85: // content.opt
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1153 "src/parse-gram.c"
         break;
 
             case 86: // braceless
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1162 "src/parse-gram.c"
         break;
 
             case 87: // id
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1171 "src/parse-gram.c"
         break;
 
             case 88: // id_colon
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1180 "src/parse-gram.c"
         break;
 
             case 89: // symbol
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1189 "src/parse-gram.c"
         break;
 
             case 90: // string_as_id
 
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 653 of yacc.c  */
+/* Line 715 of yacc.c  */
 #line 1198 "src/parse-gram.c"
         break;
 
@@ -1568,6 +1568,7 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
     }
 }
 
+
 /* Prevent warnings from -Wmissing-prototypes.  */
 #ifdef YYPARSE_PARAM
 #if (defined __STDC__ || defined __C99__FUNC__ \
@@ -1586,12 +1587,9 @@ int yyparse ();
 #endif /* ! YYPARSE_PARAM */
 
 
-
-
-
-/*-------------------------.
-| yyparse or yypush_parse.  |
-`-------------------------*/
+/*----------.
+| yyparse.  |
+`----------*/
 
 #ifdef YYPARSE_PARAM
 #if (defined __STDC__ || defined __C99__FUNC__ \
@@ -1709,7 +1707,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1175 of yacc.c  */
+/* Line 1183 of yacc.c  */
 #line 80 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1717,8 +1715,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1175 of yacc.c  */
-#line 1722 "src/parse-gram.c"
+/* Line 1183 of yacc.c  */
+#line 1720 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1904,7 +1902,7 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 266 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -1915,106 +1913,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1388 of yacc.c  */
-#line 1920 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 1918 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 276 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1388 of yacc.c  */
-#line 1930 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 1928 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 280 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1388 of yacc.c  */
-#line 1941 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 1939 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 284 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1388 of yacc.c  */
-#line 1949 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 1947 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 286 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1388 of yacc.c  */
-#line 1960 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 1958 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 291 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1388 of yacc.c  */
-#line 1971 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 1969 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 295 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1388 of yacc.c  */
-#line 1979 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 1977 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 296 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1388 of yacc.c  */
-#line 1987 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 1985 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 297 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1388 of yacc.c  */
-#line 1995 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 1993 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 298 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1388 of yacc.c  */
-#line 2003 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2001 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 300 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1388 of yacc.c  */
-#line 2014 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2012 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 305 "src/parse-gram.y"
     {
       code_props action;
@@ -2024,92 +2022,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1388 of yacc.c  */
-#line 2029 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2027 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 313 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1388 of yacc.c  */
-#line 2037 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2035 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 314 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1388 of yacc.c  */
-#line 2045 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2043 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 315 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1388 of yacc.c  */
-#line 2053 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2051 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 316 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1388 of yacc.c  */
-#line 2061 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2059 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1388 of yacc.c  */
-#line 2069 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2067 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1388 of yacc.c  */
-#line 2077 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2075 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1388 of yacc.c  */
-#line 2085 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2083 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 320 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1388 of yacc.c  */
-#line 2093 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2091 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 320 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1388 of yacc.c  */
-#line 2101 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2099 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 321 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1388 of yacc.c  */
-#line 2109 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2107 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 323 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2134,62 +2132,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1388 of yacc.c  */
-#line 2139 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2137 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 346 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1388 of yacc.c  */
-#line 2147 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2145 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 347 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1388 of yacc.c  */
-#line 2155 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2153 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 348 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1388 of yacc.c  */
-#line 2163 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2161 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 353 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2171 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2169 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 354 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2179 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2177 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 366 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1388 of yacc.c  */
-#line 2189 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2187 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 370 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2197,12 +2195,12 @@ yyreduce:
 	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1388 of yacc.c  */
-#line 2202 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2200 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 377 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2210,32 +2208,32 @@ yyreduce:
 	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1388 of yacc.c  */
-#line 2215 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2213 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 384 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1388 of yacc.c  */
-#line 2225 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2223 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 388 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1388 of yacc.c  */
-#line 2235 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2233 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 392 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2243,89 +2241,89 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1388 of yacc.c  */
-#line 2248 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2246 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 399 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1388 of yacc.c  */
-#line 2259 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2257 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 413 "src/parse-gram.y"
     {}
-/* Line 1388 of yacc.c  */
-#line 2267 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2265 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 414 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2275 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2273 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 419 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1388 of yacc.c  */
-#line 2287 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2285 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 430 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1388 of yacc.c  */
-#line 2295 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2293 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 431 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1388 of yacc.c  */
-#line 2306 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2304 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 435 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1388 of yacc.c  */
-#line 2314 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2312 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 436 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1388 of yacc.c  */
-#line 2325 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2323 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 441 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2334,12 +2332,12 @@ yyreduce:
 	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1388 of yacc.c  */
-#line 2339 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2337 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 452 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2352,202 +2350,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1388 of yacc.c  */
-#line 2357 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2355 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 466 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1388 of yacc.c  */
-#line 2365 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2363 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 467 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1388 of yacc.c  */
-#line 2373 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2371 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 468 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1388 of yacc.c  */
-#line 2381 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2379 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 469 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1388 of yacc.c  */
-#line 2389 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2387 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 473 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1388 of yacc.c  */
-#line 2397 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2395 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 474 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1388 of yacc.c  */
-#line 2405 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2403 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 480 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2413 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2411 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 482 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1388 of yacc.c  */
-#line 2421 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2419 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 486 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1388 of yacc.c  */
-#line 2429 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2427 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 487 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2437 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2435 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 493 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2445 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2443 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 495 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1388 of yacc.c  */
-#line 2453 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2451 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 499 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1388 of yacc.c  */
-#line 2461 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2459 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 500 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1388 of yacc.c  */
-#line 2469 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2467 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 504 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2477 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2475 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 505 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2485 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2483 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2493 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2491 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 507 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2501 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2499 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 513 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1388 of yacc.c  */
-#line 2512 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2510 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 518 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1388 of yacc.c  */
-#line 2523 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2521 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 523 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1388 of yacc.c  */
-#line 2535 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2533 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 529 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1388 of yacc.c  */
-#line 2547 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2545 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 535 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2555,136 +2553,136 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1388 of yacc.c  */
-#line 2560 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2558 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 565 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1388 of yacc.c  */
-#line 2570 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2568 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 571 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
-/* Line 1388 of yacc.c  */
-#line 2579 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2577 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 576 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2587 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2585 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 577 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2595 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2593 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 583 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
-/* Line 1388 of yacc.c  */
-#line 2604 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2602 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 586 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1388 of yacc.c  */
-#line 2612 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2610 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 588 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1388 of yacc.c  */
-#line 2620 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2618 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 590 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2628 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2626 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 592 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2636 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2634 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 594 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2644 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2642 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 598 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1388 of yacc.c  */
-#line 2652 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2650 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 600 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2660 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2658 "src/parse-gram.c"
     break;
 
   case 97:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 612 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1388 of yacc.c  */
-#line 2668 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2666 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 617 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1388 of yacc.c  */
-#line 2676 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2674 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 618 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1388 of yacc.c  */
-#line 2684 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2682 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 629 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2694,51 +2692,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1388 of yacc.c  */
-#line 2699 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2697 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 649 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2707 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2705 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 651 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1388 of yacc.c  */
-#line 2719 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2717 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 659 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1388 of yacc.c  */
-#line 2727 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2725 "src/parse-gram.c"
     break;
 
   case 107:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 671 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1388 of yacc.c  */
-#line 2738 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2736 "src/parse-gram.c"
     break;
 
   case 109:
-/* Line 1388 of yacc.c  */
+/* Line 1396 of yacc.c  */
 #line 680 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2748,13 +2746,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1388 of yacc.c  */
-#line 2753 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2751 "src/parse-gram.c"
     break;
 
 
-/* Line 1388 of yacc.c  */
-#line 2758 "src/parse-gram.c"
+/* Line 1396 of yacc.c  */
+#line 2756 "src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2970,7 +2968,7 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1607 of yacc.c  */
+/* Line 1615 of yacc.c  */
 #line 690 "src/parse-gram.y"
 
 
