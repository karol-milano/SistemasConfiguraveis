@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.456-ea2e.  */
+/* A Bison parser, made by GNU Bison 2.4.457-4395a.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.456-ea2e"
+#define YYBISON_VERSION "2.4.457-4395a"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -906,7 +906,6 @@ do								\
     {								\
       yychar = (Token);						\
       yylval = (Value);						\
-      yytoken = YYTRANSLATE (yychar);				\
       YYPOPSTACK (1);						\
       goto yybackup;						\
     }								\
@@ -1029,106 +1028,106 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
             case 3: // "string"
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 175 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
-/* Line 731 of yacc.c  */
-#line 1037 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1036 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 188 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
-/* Line 731 of yacc.c  */
-#line 1046 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1045 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 184 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 731 of yacc.c  */
-#line 1055 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1054 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 731 of yacc.c  */
-#line 1064 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1063 "src/parse-gram.c"
         break;
 
             case 41: // "[identifier]"
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 182 "src/parse-gram.y"
         { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 731 of yacc.c  */
-#line 1073 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1072 "src/parse-gram.c"
         break;
 
             case 42: // "char"
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 169 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
-/* Line 731 of yacc.c  */
-#line 1082 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1081 "src/parse-gram.c"
         break;
 
             case 43: // "epilogue"
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 731 of yacc.c  */
-#line 1091 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1090 "src/parse-gram.c"
         break;
 
             case 45: // "identifier"
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 181 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 731 of yacc.c  */
-#line 1100 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1099 "src/parse-gram.c"
         break;
 
             case 46: // "identifier:"
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 183 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 731 of yacc.c  */
-#line 1109 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1108 "src/parse-gram.c"
         break;
 
             case 49: // "%{...%}"
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 731 of yacc.c  */
-#line 1118 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1117 "src/parse-gram.c"
         break;
 
             case 51: // "<tag>"
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 185 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 731 of yacc.c  */
-#line 1127 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1126 "src/parse-gram.c"
         break;
 
             case 54: // "%param"
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 231 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1142,80 +1141,80 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case param_none: aver (false); break;
     }
 }
-/* Line 731 of yacc.c  */
-#line 1147 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1146 "src/parse-gram.c"
         break;
 
             case 71: // symbol.prec
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 731 of yacc.c  */
-#line 1156 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1155 "src/parse-gram.c"
         break;
 
             case 84: // variable
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 181 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 731 of yacc.c  */
-#line 1165 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1164 "src/parse-gram.c"
         break;
 
             case 85: // content.opt
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 731 of yacc.c  */
-#line 1174 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1173 "src/parse-gram.c"
         break;
 
             case 86: // braceless
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 177 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 731 of yacc.c  */
-#line 1183 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1182 "src/parse-gram.c"
         break;
 
             case 87: // id
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 731 of yacc.c  */
-#line 1192 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1191 "src/parse-gram.c"
         break;
 
             case 88: // id_colon
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 192 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 731 of yacc.c  */
-#line 1201 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1200 "src/parse-gram.c"
         break;
 
             case 89: // symbol
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 731 of yacc.c  */
-#line 1210 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1209 "src/parse-gram.c"
         break;
 
             case 90: // string_as_id
 
-/* Line 731 of yacc.c  */
+/* Line 730 of yacc.c  */
 #line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 731 of yacc.c  */
-#line 1219 "src/parse-gram.c"
+/* Line 730 of yacc.c  */
+#line 1218 "src/parse-gram.c"
         break;
 
       default:
@@ -1745,7 +1744,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1216 of yacc.c  */
+/* Line 1215 of yacc.c  */
 #line 80 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1753,8 +1752,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1216 of yacc.c  */
-#line 1758 "src/parse-gram.c"
+/* Line 1215 of yacc.c  */
+#line 1757 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1940,7 +1939,7 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 267 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -1951,106 +1950,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1429 of yacc.c  */
-#line 1956 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 1955 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 277 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1429 of yacc.c  */
-#line 1966 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 1965 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 281 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1429 of yacc.c  */
-#line 1977 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 1976 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 285 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1429 of yacc.c  */
-#line 1985 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 1984 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 287 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1429 of yacc.c  */
-#line 1996 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 1995 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 292 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1429 of yacc.c  */
-#line 2007 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2006 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 296 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1429 of yacc.c  */
-#line 2015 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2014 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 297 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1429 of yacc.c  */
-#line 2023 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2022 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 298 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1429 of yacc.c  */
-#line 2031 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2030 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 299 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1429 of yacc.c  */
-#line 2039 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2038 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 301 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1429 of yacc.c  */
-#line 2050 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2049 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 306 "src/parse-gram.y"
     {
       code_props action;
@@ -2060,92 +2059,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1429 of yacc.c  */
-#line 2065 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2064 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 314 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1429 of yacc.c  */
-#line 2073 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2072 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 315 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1429 of yacc.c  */
-#line 2081 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2080 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 316 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1429 of yacc.c  */
-#line 2089 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2088 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1429 of yacc.c  */
-#line 2097 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2096 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1429 of yacc.c  */
-#line 2105 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2104 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1429 of yacc.c  */
-#line 2113 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2112 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 320 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1429 of yacc.c  */
-#line 2121 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2120 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 321 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1429 of yacc.c  */
-#line 2129 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2128 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 321 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1429 of yacc.c  */
-#line 2137 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2136 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 322 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1429 of yacc.c  */
-#line 2145 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2144 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 324 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2170,62 +2169,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1429 of yacc.c  */
-#line 2175 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2174 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 347 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1429 of yacc.c  */
-#line 2183 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2182 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 348 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1429 of yacc.c  */
-#line 2191 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2190 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 349 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1429 of yacc.c  */
-#line 2199 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2198 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 354 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2207 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2206 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 355 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2215 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2214 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 367 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1429 of yacc.c  */
-#line 2225 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2224 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 371 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2233,12 +2232,12 @@ yyreduce:
 	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1429 of yacc.c  */
-#line 2238 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2237 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 378 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2246,32 +2245,32 @@ yyreduce:
 	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1429 of yacc.c  */
-#line 2251 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2250 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 385 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1429 of yacc.c  */
-#line 2261 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2260 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 389 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1429 of yacc.c  */
-#line 2271 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2270 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 393 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2279,89 +2278,89 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1429 of yacc.c  */
-#line 2284 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2283 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 400 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1429 of yacc.c  */
-#line 2295 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2294 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 414 "src/parse-gram.y"
     {}
-/* Line 1429 of yacc.c  */
-#line 2303 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2302 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 415 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2311 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2310 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 420 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1429 of yacc.c  */
-#line 2323 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2322 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 431 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1429 of yacc.c  */
-#line 2331 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2330 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 432 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1429 of yacc.c  */
-#line 2342 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2341 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 436 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1429 of yacc.c  */
-#line 2350 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2349 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 437 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1429 of yacc.c  */
-#line 2361 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2360 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 442 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2370,12 +2369,12 @@ yyreduce:
 	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1429 of yacc.c  */
-#line 2375 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2374 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 453 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2388,202 +2387,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1429 of yacc.c  */
-#line 2393 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2392 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 467 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1429 of yacc.c  */
-#line 2401 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2400 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 468 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1429 of yacc.c  */
-#line 2409 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2408 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 469 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1429 of yacc.c  */
-#line 2417 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2416 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 470 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1429 of yacc.c  */
-#line 2425 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2424 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 474 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1429 of yacc.c  */
-#line 2433 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2432 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 475 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1429 of yacc.c  */
-#line 2441 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2440 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 481 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2449 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2448 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 483 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1429 of yacc.c  */
-#line 2457 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2456 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 487 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1429 of yacc.c  */
-#line 2465 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2464 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 488 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2473 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2472 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 494 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2481 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2480 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 496 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1429 of yacc.c  */
-#line 2489 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2488 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 500 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1429 of yacc.c  */
-#line 2497 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2496 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 501 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1429 of yacc.c  */
-#line 2505 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2504 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 505 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2513 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2512 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2521 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2520 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 507 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2529 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2528 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 508 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2537 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2536 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 514 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1429 of yacc.c  */
-#line 2548 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2547 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 519 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1429 of yacc.c  */
-#line 2559 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2558 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 524 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1429 of yacc.c  */
-#line 2571 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2570 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 530 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1429 of yacc.c  */
-#line 2583 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2582 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 536 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2591,136 +2590,136 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1429 of yacc.c  */
-#line 2596 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2595 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 566 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1429 of yacc.c  */
-#line 2606 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2605 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 572 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
-/* Line 1429 of yacc.c  */
-#line 2615 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2614 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 577 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2623 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2622 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 578 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2631 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2630 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 584 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
-/* Line 1429 of yacc.c  */
-#line 2640 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2639 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 587 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1429 of yacc.c  */
-#line 2648 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2647 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 589 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1429 of yacc.c  */
-#line 2656 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2655 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 591 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2664 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2663 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 593 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2672 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2671 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 595 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2680 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2679 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 599 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1429 of yacc.c  */
-#line 2688 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2687 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 601 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2696 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2695 "src/parse-gram.c"
     break;
 
   case 97:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 613 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1429 of yacc.c  */
-#line 2704 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2703 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 618 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1429 of yacc.c  */
-#line 2712 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2711 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 619 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1429 of yacc.c  */
-#line 2720 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2719 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 630 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2730,51 +2729,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1429 of yacc.c  */
-#line 2735 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2734 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 650 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2743 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2742 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 652 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1429 of yacc.c  */
-#line 2755 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2754 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 660 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1429 of yacc.c  */
-#line 2763 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2762 "src/parse-gram.c"
     break;
 
   case 107:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 672 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1429 of yacc.c  */
-#line 2774 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2773 "src/parse-gram.c"
     break;
 
   case 109:
-/* Line 1429 of yacc.c  */
+/* Line 1428 of yacc.c  */
 #line 681 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2784,15 +2783,26 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1429 of yacc.c  */
-#line 2789 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2788 "src/parse-gram.c"
     break;
 
 
-/* Line 1429 of yacc.c  */
-#line 2794 "src/parse-gram.c"
+/* Line 1428 of yacc.c  */
+#line 2793 "src/parse-gram.c"
       default: break;
     }
+  /* User semantic actions sometimes alter yychar, and that requires
+     that yytoken be updated with the new translation.  We take the
+     approach of translating immediately before every use of yytoken.
+     One alternative is translating here after every semantic action,
+     but that translation would be missed if the semantic action invokes
+     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
+     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
+     incorrect destructor might then be invoked immediately.  In the
+     case of YYERROR or YYBACKUP, subsequent parser actions might lead
+     to an incorrect destructor call or verbose syntax error message
+     before the lookahead is translated.  */
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
 
   YYPOPSTACK (yylen);
@@ -2821,6 +2831,10 @@ yyreduce:
 | yyerrlab -- here on detecting error |
 `------------------------------------*/
 yyerrlab:
+  /* Make sure we have latest lookahead translation.  See comments at
+     user semantic actions for why this is necessary.  */
+  yytoken = YYTRANSLATE (yychar);
+
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
     {
@@ -2973,8 +2987,13 @@ yyexhaustedlab:
 
 yyreturn:
   if (yychar != YYEMPTY)
-     yydestruct ("Cleanup: discarding lookahead",
-		 yytoken, &yylval, &yylloc);
+    {
+      /* Make sure we have latest lookahead translation.  See comments at
+         user semantic actions for why this is necessary.  */
+      yytoken = YYTRANSLATE (yychar);
+      yydestruct ("Cleanup: discarding lookahead",
+                  yytoken, &yylval, &yylloc);
+    }
   /* Do not reclaim the symbols of the rule which action triggered
      this YYABORT or YYACCEPT.  */
   YYPOPSTACK (yylen);
@@ -2997,7 +3016,7 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1639 of yacc.c  */
+/* Line 1658 of yacc.c  */
 #line 691 "src/parse-gram.y"
 
 
