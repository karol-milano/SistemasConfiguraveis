@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.149-dcb5-dirty.  */
+/* A Bison parser, made by GNU Bison 2.4.150-0305.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.149-dcb5-dirty"
+#define YYBISON_VERSION "2.4.150-0305"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -150,7 +150,7 @@ static int current_prec = 0;
 
 
 /* Line 191 of yacc.c  */
-#line 154 "../../../src/parse-gram.c"
+#line 154 "../../src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -315,7 +315,7 @@ typedef union YYSTYPE
 
 
 /* Line 216 of yacc.c  */
-#line 319 "../../../src/parse-gram.c"
+#line 319 "../../src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -340,7 +340,7 @@ typedef struct YYLTYPE
 
 
 /* Line 266 of yacc.c  */
-#line 344 "../../../src/parse-gram.c"
+#line 344 "../../src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -568,14 +568,16 @@ union yyalloc
 /* YYNSTATES -- Number of states.  */
 #define YYNSTATES  144
 
-/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
+/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
+   by yylex, with out-of-bounds checking.  */
 #define YYUNDEFTOK  2
 #define YYMAXUTOK   312
 
 #define YYTRANSLATE(YYX)						\
   ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
 
-/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
+/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
+   as returned by yylex, without out-of-bounds checking.  */
 static const yytype_uint8 yytranslate[] =
 {
        0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
@@ -711,8 +713,8 @@ static const char *const yytname[] =
 #endif
 
 # ifdef YYPRINT
-/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
-   token YYLEX-NUM.  */
+/* YYTOKNUM[NUM] -- (External) token number corresponding to the
+   (internal) symbol number NUM (which must be that of a token).  */
 static const yytype_uint16 yytoknum[] =
 {
        0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
@@ -1041,147 +1043,147 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 181 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
 
-/* Line 717 of yacc.c  */
-#line 1050 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1052 "../../src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 192 "parse-gram.y"
 	{ fprintf (stderr, "%d", ((*yyvaluep).integer)); };
 
-/* Line 717 of yacc.c  */
-#line 1059 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1061 "../../src/parse-gram.c"
 	break;
       case 44: /* "\"{...}\"" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
 
-/* Line 717 of yacc.c  */
-#line 1068 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1070 "../../src/parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 175 "parse-gram.y"
 	{ fputs (char_name (((*yyvaluep).character)), stderr); };
 
-/* Line 717 of yacc.c  */
-#line 1077 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1079 "../../src/parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
-/* Line 717 of yacc.c  */
-#line 1086 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1088 "../../src/parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 188 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
 
-/* Line 717 of yacc.c  */
-#line 1095 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1097 "../../src/parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 189 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
 
-/* Line 717 of yacc.c  */
-#line 1104 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1106 "../../src/parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
-/* Line 717 of yacc.c  */
-#line 1113 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1115 "../../src/parse-gram.c"
 	break;
       case 54: /* "\"type\"" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 187 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
 
-/* Line 717 of yacc.c  */
-#line 1122 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1124 "../../src/parse-gram.c"
 	break;
       case 83: /* "variable" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 188 "parse-gram.y"
 	{ fputs (((*yyvaluep).uniqstr), stderr); };
 
-/* Line 717 of yacc.c  */
-#line 1131 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1133 "../../src/parse-gram.c"
 	break;
       case 84: /* "content.opt" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
-/* Line 717 of yacc.c  */
-#line 1140 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1142 "../../src/parse-gram.c"
 	break;
       case 85: /* "braceless" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 183 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
-/* Line 717 of yacc.c  */
-#line 1149 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1151 "../../src/parse-gram.c"
 	break;
       case 86: /* "id" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
-/* Line 717 of yacc.c  */
-#line 1158 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1160 "../../src/parse-gram.c"
 	break;
       case 87: /* "id_colon" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 196 "parse-gram.y"
 	{ fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
 
-/* Line 717 of yacc.c  */
-#line 1167 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1169 "../../src/parse-gram.c"
 	break;
       case 88: /* "symbol" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
-/* Line 717 of yacc.c  */
-#line 1176 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1178 "../../src/parse-gram.c"
 	break;
       case 89: /* "string_as_id" */
 
-/* Line 717 of yacc.c  */
+/* Line 719 of yacc.c  */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
-/* Line 717 of yacc.c  */
-#line 1185 "../../../src/parse-gram.c"
+/* Line 719 of yacc.c  */
+#line 1187 "../../src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1700,7 +1702,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1244 of yacc.c  */
+/* Line 1246 of yacc.c  */
 #line 84 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1709,8 +1711,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1244 of yacc.c  */
-#line 1714 "../../../src/parse-gram.c"
+/* Line 1246 of yacc.c  */
+#line 1716 "../../src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1897,7 +1899,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 219 "parse-gram.y"
     {
       code_props plain_code;
@@ -1909,121 +1911,121 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 
-/* Line 1457 of yacc.c  */
-#line 1914 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 1916 "../../src/parse-gram.c"
     break;
 
   case 7:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 228 "parse-gram.y"
     { debug_flag = true; }
 
-/* Line 1457 of yacc.c  */
-#line 1924 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 1926 "../../src/parse-gram.c"
     break;
 
   case 8:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 230 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
     }
 
-/* Line 1457 of yacc.c  */
-#line 1936 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 1938 "../../src/parse-gram.c"
     break;
 
   case 9:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 233 "parse-gram.y"
     { defines_flag = true; }
 
-/* Line 1457 of yacc.c  */
-#line 1946 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 1948 "../../src/parse-gram.c"
     break;
 
   case 10:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 235 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
     }
 
-/* Line 1457 of yacc.c  */
-#line 1959 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 1961 "../../src/parse-gram.c"
     break;
 
   case 11:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 239 "parse-gram.y"
     { error_verbose = true; }
 
-/* Line 1457 of yacc.c  */
-#line 1969 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 1971 "../../src/parse-gram.c"
     break;
 
   case 12:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 240 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
 
-/* Line 1457 of yacc.c  */
-#line 1979 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 1981 "../../src/parse-gram.c"
     break;
 
   case 13:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 241 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
 
-/* Line 1457 of yacc.c  */
-#line 1989 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 1991 "../../src/parse-gram.c"
     break;
 
   case 14:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 242 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
 
-/* Line 1457 of yacc.c  */
-#line 1999 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2001 "../../src/parse-gram.c"
     break;
 
   case 15:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
 
-/* Line 1457 of yacc.c  */
-#line 2009 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2011 "../../src/parse-gram.c"
     break;
 
   case 16:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 245 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
 
-/* Line 1457 of yacc.c  */
-#line 2022 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2024 "../../src/parse-gram.c"
     break;
 
   case 17:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 250 "parse-gram.y"
     {
       code_props action;
@@ -2034,113 +2036,113 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 
-/* Line 1457 of yacc.c  */
-#line 2039 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2041 "../../src/parse-gram.c"
     break;
 
   case 18:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 258 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2049 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2051 "../../src/parse-gram.c"
     break;
 
   case 19:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 259 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2059 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2061 "../../src/parse-gram.c"
     break;
 
   case 20:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 260 "parse-gram.y"
     { locations_flag = true; }
 
-/* Line 1457 of yacc.c  */
-#line 2069 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2071 "../../src/parse-gram.c"
     break;
 
   case 21:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 261 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
 
-/* Line 1457 of yacc.c  */
-#line 2079 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2081 "../../src/parse-gram.c"
     break;
 
   case 22:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 262 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
 
-/* Line 1457 of yacc.c  */
-#line 2089 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2091 "../../src/parse-gram.c"
     break;
 
   case 23:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 263 "parse-gram.y"
     { no_lines_flag = true; }
 
-/* Line 1457 of yacc.c  */
-#line 2099 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2101 "../../src/parse-gram.c"
     break;
 
   case 24:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 264 "parse-gram.y"
     { nondeterministic_parser = true; }
 
-/* Line 1457 of yacc.c  */
-#line 2109 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2111 "../../src/parse-gram.c"
     break;
 
   case 25:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 265 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
 
-/* Line 1457 of yacc.c  */
-#line 2119 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2121 "../../src/parse-gram.c"
     break;
 
   case 26:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 266 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
 
-/* Line 1457 of yacc.c  */
-#line 2129 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2131 "../../src/parse-gram.c"
     break;
 
   case 27:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 267 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2139 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2141 "../../src/parse-gram.c"
     break;
 
   case 28:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 269 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2155,23 +2157,23 @@ yyreduce:
         muscle_percent_define_insert ("api.pure", (yylsp[(1) - (1)]), "");
     }
 
-/* Line 1457 of yacc.c  */
-#line 2160 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2162 "../../src/parse-gram.c"
     break;
 
   case 29:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 281 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
 
-/* Line 1457 of yacc.c  */
-#line 2170 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2172 "../../src/parse-gram.c"
     break;
 
   case 30:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 283 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2197,55 +2199,55 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[(1) - (2)]));
     }
 
-/* Line 1457 of yacc.c  */
-#line 2202 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2204 "../../src/parse-gram.c"
     break;
 
   case 31:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 306 "parse-gram.y"
     { token_table_flag = true; }
 
-/* Line 1457 of yacc.c  */
-#line 2212 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2214 "../../src/parse-gram.c"
     break;
 
   case 32:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 307 "parse-gram.y"
     { report_flag |= report_states; }
 
-/* Line 1457 of yacc.c  */
-#line 2222 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2224 "../../src/parse-gram.c"
     break;
 
   case 33:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 308 "parse-gram.y"
     { yacc_flag = true; }
 
-/* Line 1457 of yacc.c  */
-#line 2232 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2234 "../../src/parse-gram.c"
     break;
 
   case 37:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 316 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
 
-/* Line 1457 of yacc.c  */
-#line 2244 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2246 "../../src/parse-gram.c"
     break;
 
   case 38:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 320 "parse-gram.y"
     {
       symbol_list *list;
@@ -2254,13 +2256,13 @@ yyreduce:
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
 
-/* Line 1457 of yacc.c  */
-#line 2259 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2261 "../../src/parse-gram.c"
     break;
 
   case 39:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 327 "parse-gram.y"
     {
       symbol_list *list;
@@ -2269,37 +2271,37 @@ yyreduce:
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
 
-/* Line 1457 of yacc.c  */
-#line 2274 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2276 "../../src/parse-gram.c"
     break;
 
   case 40:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 334 "parse-gram.y"
     {
       default_prec = true;
     }
 
-/* Line 1457 of yacc.c  */
-#line 2286 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2288 "../../src/parse-gram.c"
     break;
 
   case 41:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 338 "parse-gram.y"
     {
       default_prec = false;
     }
 
-/* Line 1457 of yacc.c  */
-#line 2298 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2300 "../../src/parse-gram.c"
     break;
 
   case 42:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 342 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2308,46 +2310,46 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 
-/* Line 1457 of yacc.c  */
-#line 2313 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2315 "../../src/parse-gram.c"
     break;
 
   case 43:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 349 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
     }
 
-/* Line 1457 of yacc.c  */
-#line 2326 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2328 "../../src/parse-gram.c"
     break;
 
   case 44:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 363 "parse-gram.y"
     {}
 
-/* Line 1457 of yacc.c  */
-#line 2336 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2338 "../../src/parse-gram.c"
     break;
 
   case 45:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 364 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2346 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2348 "../../src/parse-gram.c"
     break;
 
   case 46:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 369 "parse-gram.y"
     {
       union_seen = true;
@@ -2355,59 +2357,59 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 
-/* Line 1457 of yacc.c  */
-#line 2360 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2362 "../../src/parse-gram.c"
     break;
 
   case 47:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 380 "parse-gram.y"
     { current_class = nterm_sym; }
 
-/* Line 1457 of yacc.c  */
-#line 2370 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2372 "../../src/parse-gram.c"
     break;
 
   case 48:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 381 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 
-/* Line 1457 of yacc.c  */
-#line 2383 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2385 "../../src/parse-gram.c"
     break;
 
   case 49:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 385 "parse-gram.y"
     { current_class = token_sym; }
 
-/* Line 1457 of yacc.c  */
-#line 2393 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2395 "../../src/parse-gram.c"
     break;
 
   case 50:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 386 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
 
-/* Line 1457 of yacc.c  */
-#line 2406 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2408 "../../src/parse-gram.c"
     break;
 
   case 51:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 391 "parse-gram.y"
     {
       symbol_list *list;
@@ -2417,13 +2419,13 @@ yyreduce:
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
 
-/* Line 1457 of yacc.c  */
-#line 2422 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2424 "../../src/parse-gram.c"
     break;
 
   case 52:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 402 "parse-gram.y"
     {
       symbol_list *list;
@@ -2437,219 +2439,219 @@ yyreduce:
       current_type = NULL;
     }
 
-/* Line 1457 of yacc.c  */
-#line 2442 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2444 "../../src/parse-gram.c"
     break;
 
   case 53:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 416 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 
-/* Line 1457 of yacc.c  */
-#line 2452 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2454 "../../src/parse-gram.c"
     break;
 
   case 54:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 417 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 
-/* Line 1457 of yacc.c  */
-#line 2462 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2464 "../../src/parse-gram.c"
     break;
 
   case 55:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 418 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 
-/* Line 1457 of yacc.c  */
-#line 2472 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2474 "../../src/parse-gram.c"
     break;
 
   case 56:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 419 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 
-/* Line 1457 of yacc.c  */
-#line 2482 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2484 "../../src/parse-gram.c"
     break;
 
   case 57:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 423 "parse-gram.y"
     { current_type = NULL; }
 
-/* Line 1457 of yacc.c  */
-#line 2492 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2494 "../../src/parse-gram.c"
     break;
 
   case 58:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 424 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
 
-/* Line 1457 of yacc.c  */
-#line 2502 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2504 "../../src/parse-gram.c"
     break;
 
   case 59:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2512 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2514 "../../src/parse-gram.c"
     break;
 
   case 60:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 432 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
 
-/* Line 1457 of yacc.c  */
-#line 2522 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2524 "../../src/parse-gram.c"
     break;
 
   case 61:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 436 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
 
-/* Line 1457 of yacc.c  */
-#line 2532 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2534 "../../src/parse-gram.c"
     break;
 
   case 62:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 437 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2542 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2544 "../../src/parse-gram.c"
     break;
 
   case 63:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2552 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2554 "../../src/parse-gram.c"
     break;
 
   case 64:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
 
-/* Line 1457 of yacc.c  */
-#line 2562 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2564 "../../src/parse-gram.c"
     break;
 
   case 65:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 449 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
 
-/* Line 1457 of yacc.c  */
-#line 2572 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2574 "../../src/parse-gram.c"
     break;
 
   case 66:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 450 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
 
-/* Line 1457 of yacc.c  */
-#line 2582 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2584 "../../src/parse-gram.c"
     break;
 
   case 67:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2592 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2594 "../../src/parse-gram.c"
     break;
 
   case 68:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2602 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2604 "../../src/parse-gram.c"
     break;
 
   case 69:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 456 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2612 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2614 "../../src/parse-gram.c"
     break;
 
   case 70:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2622 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2624 "../../src/parse-gram.c"
     break;
 
   case 71:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 463 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
 
-/* Line 1457 of yacc.c  */
-#line 2635 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2637 "../../src/parse-gram.c"
     break;
 
   case 72:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 468 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
 
-/* Line 1457 of yacc.c  */
-#line 2648 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2650 "../../src/parse-gram.c"
     break;
 
   case 73:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 473 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2657,13 +2659,13 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)]));
     }
 
-/* Line 1457 of yacc.c  */
-#line 2662 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2664 "../../src/parse-gram.c"
     break;
 
   case 74:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 479 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2671,13 +2673,13 @@ yyreduce:
       symbol_make_alias ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].symbol), (yyloc));
     }
 
-/* Line 1457 of yacc.c  */
-#line 2676 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2678 "../../src/parse-gram.c"
     break;
 
   case 75:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 485 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2686,137 +2688,137 @@ yyreduce:
       symbol_make_alias ((yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].symbol), (yyloc));
     }
 
-/* Line 1457 of yacc.c  */
-#line 2691 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2693 "../../src/parse-gram.c"
     break;
 
   case 82:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 515 "parse-gram.y"
     {
       yyerrok;
     }
 
-/* Line 1457 of yacc.c  */
-#line 2703 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2705 "../../src/parse-gram.c"
     break;
 
   case 83:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 521 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
 
-/* Line 1457 of yacc.c  */
-#line 2713 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2715 "../../src/parse-gram.c"
     break;
 
   case 85:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 525 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2723 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2725 "../../src/parse-gram.c"
     break;
 
   case 86:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 526 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2733 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2735 "../../src/parse-gram.c"
     break;
 
   case 88:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 532 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
 
-/* Line 1457 of yacc.c  */
-#line 2743 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2745 "../../src/parse-gram.c"
     break;
 
   case 89:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 534 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2753 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2755 "../../src/parse-gram.c"
     break;
 
   case 90:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 536 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2763 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2765 "../../src/parse-gram.c"
     break;
 
   case 91:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 538 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2773 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2775 "../../src/parse-gram.c"
     break;
 
   case 92:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 540 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2783 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2785 "../../src/parse-gram.c"
     break;
 
   case 93:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 542 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2793 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2795 "../../src/parse-gram.c"
     break;
 
   case 95:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 552 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
 
-/* Line 1457 of yacc.c  */
-#line 2803 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2805 "../../src/parse-gram.c"
     break;
 
   case 96:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 558 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
 
-/* Line 1457 of yacc.c  */
-#line 2815 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2817 "../../src/parse-gram.c"
     break;
 
   case 98:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 571 "parse-gram.y"
     {
       code_props plain_code;
@@ -2827,23 +2829,23 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 
-/* Line 1457 of yacc.c  */
-#line 2832 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2834 "../../src/parse-gram.c"
     break;
 
   case 99:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 591 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2842 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2844 "../../src/parse-gram.c"
     break;
 
   case 100:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 593 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2851,36 +2853,36 @@ yyreduce:
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[(1) - (1)].character), (yylsp[(1) - (1)]));
     }
 
-/* Line 1457 of yacc.c  */
-#line 2856 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2858 "../../src/parse-gram.c"
     break;
 
   case 101:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 601 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
 
-/* Line 1457 of yacc.c  */
-#line 2866 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2868 "../../src/parse-gram.c"
     break;
 
   case 104:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 613 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
 
-/* Line 1457 of yacc.c  */
-#line 2879 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2881 "../../src/parse-gram.c"
     break;
 
   case 106:
 
-/* Line 1457 of yacc.c  */
+/* Line 1459 of yacc.c  */
 #line 622 "parse-gram.y"
     {
       code_props plain_code;
@@ -2891,14 +2893,14 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 
-/* Line 1457 of yacc.c  */
-#line 2896 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2898 "../../src/parse-gram.c"
     break;
 
 
 
-/* Line 1457 of yacc.c  */
-#line 2902 "../../../src/parse-gram.c"
+/* Line 1459 of yacc.c  */
+#line 2904 "../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -3116,7 +3118,7 @@ yyreturn:
 
 
 
-/* Line 1677 of yacc.c  */
+/* Line 1679 of yacc.c  */
 #line 632 "parse-gram.y"
 
 
