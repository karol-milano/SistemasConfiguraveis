@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.294-184e3.  */
+/* A Bison parser, made by GNU Bison 2.4.305-d937.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.294-184e3"
+#define YYBISON_VERSION "2.4.305-d937"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -148,7 +148,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 191 of yacc.c  */
-#line 152 "../../src/parse-gram.c"
+#line 152 "src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -291,7 +291,7 @@ static int current_prec = 0;
 #if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
 typedef union YYSTYPE
 {
-/* Line 216 of yacc.c  */
+/* Line 224 of yacc.c  */
 #line 92 "parse-gram.y"
 
   symbol *symbol;
@@ -304,8 +304,8 @@ typedef union YYSTYPE
   unsigned char character;
 
 
-/* Line 216 of yacc.c  */
-#line 309 "../../src/parse-gram.c"
+/* Line 224 of yacc.c  */
+#line 309 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -329,7 +329,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 266 of yacc.c  */
-#line 333 "../../src/parse-gram.c"
+#line 333 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -688,9 +688,9 @@ static const yytype_int16 yypact[] =
      -93
 };
 
-  /* YYDEFACT[S] -- default rule to reduce with in state S when YYTABLE
-     does not specify something else to do.  Zero means the default is an
-     error.    */
+  /* YYDEFACT[S] -- default reduction number in state S.  Performed when
+     YYTABLE does not specify something else to do.  Zero means the default
+     is an error.    */
 static const yytype_uint8 yydefact[] =
 {
        3,     0,     0,     1,    46,    44,     0,     0,     0,    50,
@@ -983,7 +983,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 178 "parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
 /* Line 647 of yacc.c  */
-#line 987 "../../src/parse-gram.c"
+#line 987 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
@@ -992,7 +992,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 190 "parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 647 of yacc.c  */
-#line 996 "../../src/parse-gram.c"
+#line 996 "src/parse-gram.c"
         break;
 
             case 23: // "%<flag>"
@@ -1001,7 +1001,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 186 "parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1005 "../../src/parse-gram.c"
+#line 1005 "src/parse-gram.c"
         break;
 
             case 41: // "{...}"
@@ -1010,7 +1010,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 180 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 647 of yacc.c  */
-#line 1014 "../../src/parse-gram.c"
+#line 1014 "src/parse-gram.c"
         break;
 
             case 42: // "char"
@@ -1019,7 +1019,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 172 "parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 647 of yacc.c  */
-#line 1023 "../../src/parse-gram.c"
+#line 1023 "src/parse-gram.c"
         break;
 
             case 43: // "epilogue"
@@ -1028,7 +1028,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 180 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1032 "../../src/parse-gram.c"
+#line 1032 "src/parse-gram.c"
         break;
 
             case 45: // "identifier"
@@ -1037,7 +1037,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 184 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 647 of yacc.c  */
-#line 1041 "../../src/parse-gram.c"
+#line 1041 "src/parse-gram.c"
         break;
 
             case 46: // "identifier:"
@@ -1046,7 +1046,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 185 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1050 "../../src/parse-gram.c"
+#line 1050 "src/parse-gram.c"
         break;
 
             case 49: // "%{...%}"
@@ -1055,7 +1055,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 180 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1059 "../../src/parse-gram.c"
+#line 1059 "src/parse-gram.c"
         break;
 
             case 51: // "<tag>"
@@ -1064,7 +1064,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 187 "parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1068 "../../src/parse-gram.c"
+#line 1068 "src/parse-gram.c"
         break;
 
             case 80: // variable
@@ -1073,7 +1073,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 184 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 647 of yacc.c  */
-#line 1077 "../../src/parse-gram.c"
+#line 1077 "src/parse-gram.c"
         break;
 
             case 81: // content.opt
@@ -1082,7 +1082,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 180 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1086 "../../src/parse-gram.c"
+#line 1086 "src/parse-gram.c"
         break;
 
             case 82: // braceless
@@ -1091,7 +1091,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 180 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1095 "../../src/parse-gram.c"
+#line 1095 "src/parse-gram.c"
         break;
 
             case 83: // id
@@ -1100,7 +1100,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 193 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1104 "../../src/parse-gram.c"
+#line 1104 "src/parse-gram.c"
         break;
 
             case 84: // id_colon
@@ -1109,7 +1109,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 194 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1113 "../../src/parse-gram.c"
+#line 1113 "src/parse-gram.c"
         break;
 
             case 85: // symbol
@@ -1118,7 +1118,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 193 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1122 "../../src/parse-gram.c"
+#line 1122 "src/parse-gram.c"
         break;
 
             case 86: // string_as_id
@@ -1127,7 +1127,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 193 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1131 "../../src/parse-gram.c"
+#line 1131 "src/parse-gram.c"
         break;
 
       default:
@@ -1640,7 +1640,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1167 of yacc.c  */
+/* Line 1173 of yacc.c  */
 #line 84 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1648,8 +1648,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1167 of yacc.c  */
-#line 1653 "../../src/parse-gram.c"
+/* Line 1173 of yacc.c  */
+#line 1653 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1847,7 +1847,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1851 "../../src/parse-gram.c"
+#line 1851 "src/parse-gram.c"
     break;
 
   case 7:
@@ -1857,7 +1857,7 @@ yyreduce:
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1380 of yacc.c  */
-#line 1861 "../../src/parse-gram.c"
+#line 1861 "src/parse-gram.c"
     break;
 
   case 8:
@@ -1867,7 +1867,7 @@ yyreduce:
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars));
     }
 /* Line 1380 of yacc.c  */
-#line 1871 "../../src/parse-gram.c"
+#line 1871 "src/parse-gram.c"
     break;
 
   case 9:
@@ -1875,7 +1875,7 @@ yyreduce:
 #line 234 "parse-gram.y"
     { defines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1879 "../../src/parse-gram.c"
+#line 1879 "src/parse-gram.c"
     break;
 
   case 10:
@@ -1886,7 +1886,7 @@ yyreduce:
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1380 of yacc.c  */
-#line 1890 "../../src/parse-gram.c"
+#line 1890 "src/parse-gram.c"
     break;
 
   case 11:
@@ -1894,7 +1894,7 @@ yyreduce:
 #line 240 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1898 "../../src/parse-gram.c"
+#line 1898 "src/parse-gram.c"
     break;
 
   case 12:
@@ -1902,7 +1902,7 @@ yyreduce:
 #line 241 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1906 "../../src/parse-gram.c"
+#line 1906 "src/parse-gram.c"
     break;
 
   case 13:
@@ -1910,7 +1910,7 @@ yyreduce:
 #line 242 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1914 "../../src/parse-gram.c"
+#line 1914 "src/parse-gram.c"
     break;
 
   case 14:
@@ -1918,7 +1918,7 @@ yyreduce:
 #line 243 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1922 "../../src/parse-gram.c"
+#line 1922 "src/parse-gram.c"
     break;
 
   case 15:
@@ -1929,7 +1929,7 @@ yyreduce:
       glr_parser = true;
     }
 /* Line 1380 of yacc.c  */
-#line 1933 "../../src/parse-gram.c"
+#line 1933 "src/parse-gram.c"
     break;
 
   case 16:
@@ -1944,7 +1944,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1948 "../../src/parse-gram.c"
+#line 1948 "src/parse-gram.c"
     break;
 
   case 17:
@@ -1952,7 +1952,7 @@ yyreduce:
 #line 258 "parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1380 of yacc.c  */
-#line 1956 "../../src/parse-gram.c"
+#line 1956 "src/parse-gram.c"
     break;
 
   case 18:
@@ -1960,7 +1960,7 @@ yyreduce:
 #line 259 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 1964 "../../src/parse-gram.c"
+#line 1964 "src/parse-gram.c"
     break;
 
   case 19:
@@ -1968,7 +1968,7 @@ yyreduce:
 #line 260 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1972 "../../src/parse-gram.c"
+#line 1972 "src/parse-gram.c"
     break;
 
   case 20:
@@ -1976,7 +1976,7 @@ yyreduce:
 #line 261 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1980 "../../src/parse-gram.c"
+#line 1980 "src/parse-gram.c"
     break;
 
   case 21:
@@ -1984,7 +1984,7 @@ yyreduce:
 #line 262 "parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1988 "../../src/parse-gram.c"
+#line 1988 "src/parse-gram.c"
     break;
 
   case 22:
@@ -1992,7 +1992,7 @@ yyreduce:
 #line 263 "parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1380 of yacc.c  */
-#line 1996 "../../src/parse-gram.c"
+#line 1996 "src/parse-gram.c"
     break;
 
   case 23:
@@ -2000,7 +2000,7 @@ yyreduce:
 #line 264 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2004 "../../src/parse-gram.c"
+#line 2004 "src/parse-gram.c"
     break;
 
   case 24:
@@ -2008,7 +2008,7 @@ yyreduce:
 #line 265 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2012 "../../src/parse-gram.c"
+#line 2012 "src/parse-gram.c"
     break;
 
   case 25:
@@ -2016,7 +2016,7 @@ yyreduce:
 #line 266 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2020 "../../src/parse-gram.c"
+#line 2020 "src/parse-gram.c"
     break;
 
   case 26:
@@ -2024,7 +2024,7 @@ yyreduce:
 #line 267 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2028 "../../src/parse-gram.c"
+#line 2028 "src/parse-gram.c"
     break;
 
   case 27:
@@ -2054,7 +2054,7 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1380 of yacc.c  */
-#line 2058 "../../src/parse-gram.c"
+#line 2058 "src/parse-gram.c"
     break;
 
   case 28:
@@ -2062,7 +2062,7 @@ yyreduce:
 #line 292 "parse-gram.y"
     { token_table_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2066 "../../src/parse-gram.c"
+#line 2066 "src/parse-gram.c"
     break;
 
   case 29:
@@ -2070,7 +2070,7 @@ yyreduce:
 #line 293 "parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1380 of yacc.c  */
-#line 2074 "../../src/parse-gram.c"
+#line 2074 "src/parse-gram.c"
     break;
 
   case 30:
@@ -2078,7 +2078,7 @@ yyreduce:
 #line 294 "parse-gram.y"
     { yacc_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2082 "../../src/parse-gram.c"
+#line 2082 "src/parse-gram.c"
     break;
 
   case 34:
@@ -2088,7 +2088,7 @@ yyreduce:
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2092 "../../src/parse-gram.c"
+#line 2092 "src/parse-gram.c"
     break;
 
   case 35:
@@ -2101,7 +2101,7 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2105 "../../src/parse-gram.c"
+#line 2105 "src/parse-gram.c"
     break;
 
   case 36:
@@ -2114,7 +2114,7 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2118 "../../src/parse-gram.c"
+#line 2118 "src/parse-gram.c"
     break;
 
   case 37:
@@ -2124,7 +2124,7 @@ yyreduce:
       default_prec = true;
     }
 /* Line 1380 of yacc.c  */
-#line 2128 "../../src/parse-gram.c"
+#line 2128 "src/parse-gram.c"
     break;
 
   case 38:
@@ -2134,7 +2134,7 @@ yyreduce:
       default_prec = false;
     }
 /* Line 1380 of yacc.c  */
-#line 2138 "../../src/parse-gram.c"
+#line 2138 "src/parse-gram.c"
     break;
 
   case 39:
@@ -2147,7 +2147,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2151 "../../src/parse-gram.c"
+#line 2151 "src/parse-gram.c"
     break;
 
   case 40:
@@ -2158,7 +2158,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2162 "../../src/parse-gram.c"
+#line 2162 "src/parse-gram.c"
     break;
 
   case 41:
@@ -2166,7 +2166,7 @@ yyreduce:
 #line 349 "parse-gram.y"
     {}
 /* Line 1380 of yacc.c  */
-#line 2170 "../../src/parse-gram.c"
+#line 2170 "src/parse-gram.c"
     break;
 
   case 42:
@@ -2174,7 +2174,7 @@ yyreduce:
 #line 350 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2178 "../../src/parse-gram.c"
+#line 2178 "src/parse-gram.c"
     break;
 
   case 43:
@@ -2186,7 +2186,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2190 "../../src/parse-gram.c"
+#line 2190 "src/parse-gram.c"
     break;
 
   case 44:
@@ -2194,7 +2194,7 @@ yyreduce:
 #line 366 "parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1380 of yacc.c  */
-#line 2198 "../../src/parse-gram.c"
+#line 2198 "src/parse-gram.c"
     break;
 
   case 45:
@@ -2205,7 +2205,7 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2209 "../../src/parse-gram.c"
+#line 2209 "src/parse-gram.c"
     break;
 
   case 46:
@@ -2213,7 +2213,7 @@ yyreduce:
 #line 371 "parse-gram.y"
     { current_class = token_sym; }
 /* Line 1380 of yacc.c  */
-#line 2217 "../../src/parse-gram.c"
+#line 2217 "src/parse-gram.c"
     break;
 
   case 47:
@@ -2224,7 +2224,7 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2228 "../../src/parse-gram.c"
+#line 2228 "src/parse-gram.c"
     break;
 
   case 48:
@@ -2238,7 +2238,7 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2242 "../../src/parse-gram.c"
+#line 2242 "src/parse-gram.c"
     break;
 
   case 49:
@@ -2256,7 +2256,7 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2260 "../../src/parse-gram.c"
+#line 2260 "src/parse-gram.c"
     break;
 
   case 50:
@@ -2264,7 +2264,7 @@ yyreduce:
 #line 402 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2268 "../../src/parse-gram.c"
+#line 2268 "src/parse-gram.c"
     break;
 
   case 51:
@@ -2272,7 +2272,7 @@ yyreduce:
 #line 403 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2276 "../../src/parse-gram.c"
+#line 2276 "src/parse-gram.c"
     break;
 
   case 52:
@@ -2280,7 +2280,7 @@ yyreduce:
 #line 404 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2284 "../../src/parse-gram.c"
+#line 2284 "src/parse-gram.c"
     break;
 
   case 53:
@@ -2288,7 +2288,7 @@ yyreduce:
 #line 405 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2292 "../../src/parse-gram.c"
+#line 2292 "src/parse-gram.c"
     break;
 
   case 54:
@@ -2296,7 +2296,7 @@ yyreduce:
 #line 409 "parse-gram.y"
     { current_type = NULL; }
 /* Line 1380 of yacc.c  */
-#line 2300 "../../src/parse-gram.c"
+#line 2300 "src/parse-gram.c"
     break;
 
   case 55:
@@ -2304,7 +2304,7 @@ yyreduce:
 #line 410 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1380 of yacc.c  */
-#line 2308 "../../src/parse-gram.c"
+#line 2308 "src/parse-gram.c"
     break;
 
   case 56:
@@ -2312,7 +2312,7 @@ yyreduce:
 #line 416 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2316 "../../src/parse-gram.c"
+#line 2316 "src/parse-gram.c"
     break;
 
   case 57:
@@ -2320,7 +2320,7 @@ yyreduce:
 #line 418 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2324 "../../src/parse-gram.c"
+#line 2324 "src/parse-gram.c"
     break;
 
   case 58:
@@ -2328,7 +2328,7 @@ yyreduce:
 #line 422 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1380 of yacc.c  */
-#line 2332 "../../src/parse-gram.c"
+#line 2332 "src/parse-gram.c"
     break;
 
   case 59:
@@ -2336,7 +2336,7 @@ yyreduce:
 #line 423 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2340 "../../src/parse-gram.c"
+#line 2340 "src/parse-gram.c"
     break;
 
   case 60:
@@ -2344,7 +2344,7 @@ yyreduce:
 #line 429 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2348 "../../src/parse-gram.c"
+#line 2348 "src/parse-gram.c"
     break;
 
   case 61:
@@ -2352,7 +2352,7 @@ yyreduce:
 #line 431 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2356 "../../src/parse-gram.c"
+#line 2356 "src/parse-gram.c"
     break;
 
   case 62:
@@ -2360,7 +2360,7 @@ yyreduce:
 #line 435 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1380 of yacc.c  */
-#line 2364 "../../src/parse-gram.c"
+#line 2364 "src/parse-gram.c"
     break;
 
   case 63:
@@ -2368,7 +2368,7 @@ yyreduce:
 #line 436 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1380 of yacc.c  */
-#line 2372 "../../src/parse-gram.c"
+#line 2372 "src/parse-gram.c"
     break;
 
   case 64:
@@ -2376,7 +2376,7 @@ yyreduce:
 #line 440 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2380 "../../src/parse-gram.c"
+#line 2380 "src/parse-gram.c"
     break;
 
   case 65:
@@ -2384,7 +2384,7 @@ yyreduce:
 #line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2388 "../../src/parse-gram.c"
+#line 2388 "src/parse-gram.c"
     break;
 
   case 66:
@@ -2392,7 +2392,7 @@ yyreduce:
 #line 442 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2396 "../../src/parse-gram.c"
+#line 2396 "src/parse-gram.c"
     break;
 
   case 67:
@@ -2400,7 +2400,7 @@ yyreduce:
 #line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2404 "../../src/parse-gram.c"
+#line 2404 "src/parse-gram.c"
     break;
 
   case 68:
@@ -2411,7 +2411,7 @@ yyreduce:
        tag_seen = true;
      }
 /* Line 1380 of yacc.c  */
-#line 2415 "../../src/parse-gram.c"
+#line 2415 "src/parse-gram.c"
     break;
 
   case 69:
@@ -2422,7 +2422,7 @@ yyreduce:
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1380 of yacc.c  */
-#line 2426 "../../src/parse-gram.c"
+#line 2426 "src/parse-gram.c"
     break;
 
   case 70:
@@ -2434,7 +2434,7 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2438 "../../src/parse-gram.c"
+#line 2438 "src/parse-gram.c"
     break;
 
   case 71:
@@ -2446,7 +2446,7 @@ yyreduce:
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2450 "../../src/parse-gram.c"
+#line 2450 "src/parse-gram.c"
     break;
 
   case 72:
@@ -2459,7 +2459,7 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2463 "../../src/parse-gram.c"
+#line 2463 "src/parse-gram.c"
     break;
 
   case 79:
@@ -2469,7 +2469,7 @@ yyreduce:
       yyerrok;
     }
 /* Line 1380 of yacc.c  */
-#line 2473 "../../src/parse-gram.c"
+#line 2473 "src/parse-gram.c"
     break;
 
   case 80:
@@ -2477,7 +2477,7 @@ yyreduce:
 #line 507 "parse-gram.y"
     { current_lhs = (yyvsp[0].symbol); current_lhs_location = (yylsp[0]); }
 /* Line 1380 of yacc.c  */
-#line 2481 "../../src/parse-gram.c"
+#line 2481 "src/parse-gram.c"
     break;
 
   case 82:
@@ -2485,7 +2485,7 @@ yyreduce:
 #line 511 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2489 "../../src/parse-gram.c"
+#line 2489 "src/parse-gram.c"
     break;
 
   case 83:
@@ -2493,7 +2493,7 @@ yyreduce:
 #line 512 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2497 "../../src/parse-gram.c"
+#line 2497 "src/parse-gram.c"
     break;
 
   case 85:
@@ -2501,7 +2501,7 @@ yyreduce:
 #line 518 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
 /* Line 1380 of yacc.c  */
-#line 2505 "../../src/parse-gram.c"
+#line 2505 "src/parse-gram.c"
     break;
 
   case 86:
@@ -2509,7 +2509,7 @@ yyreduce:
 #line 520 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2513 "../../src/parse-gram.c"
+#line 2513 "src/parse-gram.c"
     break;
 
   case 87:
@@ -2517,7 +2517,7 @@ yyreduce:
 #line 522 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2521 "../../src/parse-gram.c"
+#line 2521 "src/parse-gram.c"
     break;
 
   case 88:
@@ -2525,7 +2525,7 @@ yyreduce:
 #line 524 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2529 "../../src/parse-gram.c"
+#line 2529 "src/parse-gram.c"
     break;
 
   case 89:
@@ -2533,7 +2533,7 @@ yyreduce:
 #line 526 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2537 "../../src/parse-gram.c"
+#line 2537 "src/parse-gram.c"
     break;
 
   case 90:
@@ -2541,7 +2541,7 @@ yyreduce:
 #line 528 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2545 "../../src/parse-gram.c"
+#line 2545 "src/parse-gram.c"
     break;
 
   case 92:
@@ -2549,7 +2549,7 @@ yyreduce:
 #line 538 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2553 "../../src/parse-gram.c"
+#line 2553 "src/parse-gram.c"
     break;
 
   case 93:
@@ -2557,7 +2557,7 @@ yyreduce:
 #line 543 "parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1380 of yacc.c  */
-#line 2561 "../../src/parse-gram.c"
+#line 2561 "src/parse-gram.c"
     break;
 
   case 95:
@@ -2572,7 +2572,7 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1380 of yacc.c  */
-#line 2576 "../../src/parse-gram.c"
+#line 2576 "src/parse-gram.c"
     break;
 
   case 96:
@@ -2580,7 +2580,7 @@ yyreduce:
 #line 574 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2584 "../../src/parse-gram.c"
+#line 2584 "src/parse-gram.c"
     break;
 
   case 97:
@@ -2592,7 +2592,7 @@ yyreduce:
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2596 "../../src/parse-gram.c"
+#line 2596 "src/parse-gram.c"
     break;
 
   case 98:
@@ -2600,7 +2600,7 @@ yyreduce:
 #line 584 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2604 "../../src/parse-gram.c"
+#line 2604 "src/parse-gram.c"
     break;
 
   case 101:
@@ -2611,7 +2611,7 @@ yyreduce:
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1380 of yacc.c  */
-#line 2615 "../../src/parse-gram.c"
+#line 2615 "src/parse-gram.c"
     break;
 
   case 103:
@@ -2626,12 +2626,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2630 "../../src/parse-gram.c"
+#line 2630 "src/parse-gram.c"
     break;
 
 
 /* Line 1380 of yacc.c  */
-#line 2635 "../../src/parse-gram.c"
+#line 2635 "src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
