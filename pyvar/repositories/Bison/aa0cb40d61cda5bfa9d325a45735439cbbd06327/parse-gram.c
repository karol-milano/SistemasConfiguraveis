@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.388-53f03.  */
+/* A Bison parser, made by GNU Bison 2.4.390-0aaa.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.388-53f03"
+#define YYBISON_VERSION "2.4.390-0aaa"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -680,8 +680,7 @@ static const yytype_uint16 yytoknum[] =
 #define YYTABLE_NINF -106
 
 #define yytable_value_is_error(yytable_value) \
-  (YYID (0) \
-  || ((yytable_value) == (0)))
+  YYID (0)
 
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
      STATE-NUM.    */
@@ -746,7 +745,7 @@ static const yytype_int16 yydefgoto[] =
 
   /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
      positive, shift that token.  If negative, reduce the rule which
-     number is the opposite.  If zero or YYTABLE_NINF, syntax error.    */
+     number is the opposite.  If YYTABLE_NINF, syntax error.    */
 static const yytype_int16 yytable[] =
 {
       77,  -105,    79,    73,   104,     3,     4,     5,     6,     7,
@@ -990,155 +989,155 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
             case 3: // "string"
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 183 "parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
-/* Line 654 of yacc.c  */
-#line 998 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 997 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 196 "parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
-/* Line 654 of yacc.c  */
-#line 1007 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1006 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 192 "parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 654 of yacc.c  */
-#line 1016 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1015 "src/parse-gram.c"
         break;
 
             case 42: // "{...}"
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 654 of yacc.c  */
-#line 1025 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1024 "src/parse-gram.c"
         break;
 
             case 43: // "char"
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 177 "parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
-/* Line 654 of yacc.c  */
-#line 1034 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1033 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 654 of yacc.c  */
-#line 1043 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1042 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 190 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 654 of yacc.c  */
-#line 1052 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1051 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 191 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 654 of yacc.c  */
-#line 1061 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1060 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 654 of yacc.c  */
-#line 1070 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1069 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 193 "parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 654 of yacc.c  */
-#line 1079 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1078 "src/parse-gram.c"
         break;
 
             case 83: // variable
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 190 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 654 of yacc.c  */
-#line 1088 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1087 "src/parse-gram.c"
         break;
 
             case 84: // content.opt
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 654 of yacc.c  */
-#line 1097 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1096 "src/parse-gram.c"
         break;
 
             case 85: // braceless
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 654 of yacc.c  */
-#line 1106 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1105 "src/parse-gram.c"
         break;
 
             case 86: // id
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 199 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 654 of yacc.c  */
-#line 1115 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1114 "src/parse-gram.c"
         break;
 
             case 87: // id_colon
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 200 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 654 of yacc.c  */
-#line 1124 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1123 "src/parse-gram.c"
         break;
 
             case 88: // symbol
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 199 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 654 of yacc.c  */
-#line 1133 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1132 "src/parse-gram.c"
         break;
 
             case 89: // string_as_id
 
-/* Line 654 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 199 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 654 of yacc.c  */
-#line 1142 "src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1141 "src/parse-gram.c"
         break;
 
       default:
@@ -1653,7 +1652,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1176 of yacc.c  */
+/* Line 1175 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1661,8 +1660,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1176 of yacc.c  */
-#line 1666 "src/parse-gram.c"
+/* Line 1175 of yacc.c  */
+#line 1665 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1848,7 +1847,7 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 223 "parse-gram.y"
     {
       code_props plain_code;
@@ -1859,106 +1858,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1389 of yacc.c  */
-#line 1864 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1863 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 233 "parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1389 of yacc.c  */
-#line 1874 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1873 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 237 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1389 of yacc.c  */
-#line 1885 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1884 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 241 "parse-gram.y"
     { defines_flag = true; }
-/* Line 1389 of yacc.c  */
-#line 1893 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1892 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 243 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1389 of yacc.c  */
-#line 1904 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1903 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 248 "parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1389 of yacc.c  */
-#line 1915 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1914 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 252 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1389 of yacc.c  */
-#line 1923 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1922 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 253 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1389 of yacc.c  */
-#line 1931 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1930 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 254 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1389 of yacc.c  */
-#line 1939 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1938 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 255 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1389 of yacc.c  */
-#line 1947 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1946 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 257 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1389 of yacc.c  */
-#line 1958 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1957 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 262 "parse-gram.y"
     {
       code_props action;
@@ -1968,92 +1967,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1389 of yacc.c  */
-#line 1973 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1972 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 270 "parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1389 of yacc.c  */
-#line 1981 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1980 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 271 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 1989 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1988 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 272 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1389 of yacc.c  */
-#line 1997 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1996 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 273 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1389 of yacc.c  */
-#line 2005 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2004 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 274 "parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1389 of yacc.c  */
-#line 2013 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2012 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 275 "parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1389 of yacc.c  */
-#line 2021 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2020 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 276 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1389 of yacc.c  */
-#line 2029 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2028 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 277 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1389 of yacc.c  */
-#line 2037 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2036 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 278 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2045 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2044 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 279 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1389 of yacc.c  */
-#line 2053 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2052 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 281 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2078,46 +2077,46 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1389 of yacc.c  */
-#line 2083 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2082 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 304 "parse-gram.y"
     { token_table_flag = true; }
-/* Line 1389 of yacc.c  */
-#line 2091 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2090 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 305 "parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1389 of yacc.c  */
-#line 2099 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2098 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 306 "parse-gram.y"
     { yacc_flag = true; }
-/* Line 1389 of yacc.c  */
-#line 2107 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2106 "src/parse-gram.c"
     break;
 
   case 35:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 314 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1389 of yacc.c  */
-#line 2117 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2116 "src/parse-gram.c"
     break;
 
   case 36:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 318 "parse-gram.y"
     {
       symbol_list *list;
@@ -2125,12 +2124,12 @@ yyreduce:
 	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1389 of yacc.c  */
-#line 2130 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2129 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 325 "parse-gram.y"
     {
       symbol_list *list;
@@ -2138,32 +2137,32 @@ yyreduce:
 	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1389 of yacc.c  */
-#line 2143 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2142 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 332 "parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1389 of yacc.c  */
-#line 2153 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2152 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 336 "parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1389 of yacc.c  */
-#line 2163 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2162 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 340 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2171,89 +2170,89 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1389 of yacc.c  */
-#line 2176 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2175 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 347 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1389 of yacc.c  */
-#line 2187 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2186 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 361 "parse-gram.y"
     {}
-/* Line 1389 of yacc.c  */
-#line 2195 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2194 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 362 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2203 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2202 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 367 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1389 of yacc.c  */
-#line 2215 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2214 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 378 "parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1389 of yacc.c  */
-#line 2223 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2222 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 379 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1389 of yacc.c  */
-#line 2234 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2233 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 383 "parse-gram.y"
     { current_class = token_sym; }
-/* Line 1389 of yacc.c  */
-#line 2242 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2241 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 384 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1389 of yacc.c  */
-#line 2253 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2252 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 389 "parse-gram.y"
     {
       symbol_list *list;
@@ -2262,12 +2261,12 @@ yyreduce:
 	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1389 of yacc.c  */
-#line 2267 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2266 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 400 "parse-gram.y"
     {
       symbol_list *list;
@@ -2280,202 +2279,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1389 of yacc.c  */
-#line 2285 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2284 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 414 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1389 of yacc.c  */
-#line 2293 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2292 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 415 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1389 of yacc.c  */
-#line 2301 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2300 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 416 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1389 of yacc.c  */
-#line 2309 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2308 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 417 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1389 of yacc.c  */
-#line 2317 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2316 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 421 "parse-gram.y"
     { current_type = NULL; }
-/* Line 1389 of yacc.c  */
-#line 2325 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2324 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 422 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1389 of yacc.c  */
-#line 2333 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2332 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 428 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2341 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2340 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1389 of yacc.c  */
-#line 2349 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2348 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 434 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1389 of yacc.c  */
-#line 2357 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2356 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 435 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2365 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2364 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2373 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2372 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1389 of yacc.c  */
-#line 2381 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2380 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 447 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1389 of yacc.c  */
-#line 2389 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2388 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 448 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1389 of yacc.c  */
-#line 2397 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2396 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 452 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2405 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2404 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2413 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2412 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2421 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2420 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2429 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2428 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 461 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1389 of yacc.c  */
-#line 2440 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2439 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 466 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1389 of yacc.c  */
-#line 2451 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2450 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 471 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1389 of yacc.c  */
-#line 2463 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2462 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 477 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1389 of yacc.c  */
-#line 2475 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2474 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 483 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2483,128 +2482,128 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1389 of yacc.c  */
-#line 2488 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2487 "src/parse-gram.c"
     break;
 
   case 80:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 513 "parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1389 of yacc.c  */
-#line 2498 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2497 "src/parse-gram.c"
     break;
 
   case 81:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 519 "parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
-/* Line 1389 of yacc.c  */
-#line 2507 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2506 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 524 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2515 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2514 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 525 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2523 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2522 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 531 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
-/* Line 1389 of yacc.c  */
-#line 2532 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2531 "src/parse-gram.c"
     break;
 
   case 87:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 534 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1389 of yacc.c  */
-#line 2540 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2539 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 536 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1389 of yacc.c  */
-#line 2548 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2547 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 538 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2556 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2555 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 540 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2564 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2563 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 542 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2572 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2571 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 546 "parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1389 of yacc.c  */
-#line 2580 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2579 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 548 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2588 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2587 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 560 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1389 of yacc.c  */
-#line 2596 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2595 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 565 "parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1389 of yacc.c  */
-#line 2604 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2603 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 576 "parse-gram.y"
     {
       code_props plain_code;
@@ -2614,51 +2613,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1389 of yacc.c  */
-#line 2619 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2618 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 596 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2627 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2626 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 598 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1389 of yacc.c  */
-#line 2639 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2638 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 606 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1389 of yacc.c  */
-#line 2647 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2646 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 618 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1389 of yacc.c  */
-#line 2658 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2657 "src/parse-gram.c"
     break;
 
   case 106:
-/* Line 1389 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 627 "parse-gram.y"
     {
       code_props plain_code;
@@ -2668,13 +2667,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1389 of yacc.c  */
-#line 2673 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2672 "src/parse-gram.c"
     break;
 
 
-/* Line 1389 of yacc.c  */
-#line 2678 "src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2677 "src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2890,7 +2889,7 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1608 of yacc.c  */
+/* Line 1607 of yacc.c  */
 #line 637 "parse-gram.y"
 
 
