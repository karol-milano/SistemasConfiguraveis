@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.343-83ea.  */
+/* A Bison parser, made by GNU Bison 2.4.386-e6c849.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.343-83ea"
+#define YYBISON_VERSION "2.4.386-e6c849"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -150,7 +150,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 191 of yacc.c  */
-#line 154 "../master/src/parse-gram.c"
+#line 154 "src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -312,7 +312,7 @@ typedef union YYSTYPE
 
 
 /* Line 216 of yacc.c  */
-#line 316 "../master/src/parse-gram.c"
+#line 316 "src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -336,7 +336,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 266 of yacc.c  */
-#line 340 "../master/src/parse-gram.c"
+#line 340 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -674,8 +674,14 @@ static const yytype_uint16 yytoknum[] =
 
 #define YYPACT_NINF -53
 
+#define yyis_pact_ninf(yystate) \
+  ((yystate) == (-53))
+
 #define YYTABLE_NINF -106
 
+#define yyis_table_ninf(yytable_value) \
+  YYID (0)
+
   /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
      STATE-NUM.    */
 static const yytype_int16 yypact[] =
@@ -984,155 +990,155 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
             case 3: // "string"
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 183 "parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
-/* Line 647 of yacc.c  */
-#line 992 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 998 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 196 "parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
-/* Line 647 of yacc.c  */
-#line 1001 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1007 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 192 "parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 647 of yacc.c  */
-#line 1010 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1016 "src/parse-gram.c"
         break;
 
             case 42: // "{...}"
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 647 of yacc.c  */
-#line 1019 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1025 "src/parse-gram.c"
         break;
 
             case 43: // "char"
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 177 "parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
-/* Line 647 of yacc.c  */
-#line 1028 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1034 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 647 of yacc.c  */
-#line 1037 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1043 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 190 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 647 of yacc.c  */
-#line 1046 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1052 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 191 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 647 of yacc.c  */
-#line 1055 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1061 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 647 of yacc.c  */
-#line 1064 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1070 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 193 "parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 647 of yacc.c  */
-#line 1073 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1079 "src/parse-gram.c"
         break;
 
             case 83: // variable
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 190 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 647 of yacc.c  */
-#line 1082 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1088 "src/parse-gram.c"
         break;
 
             case 84: // content.opt
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 647 of yacc.c  */
-#line 1091 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1097 "src/parse-gram.c"
         break;
 
             case 85: // braceless
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 647 of yacc.c  */
-#line 1100 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1106 "src/parse-gram.c"
         break;
 
             case 86: // id
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 199 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 647 of yacc.c  */
-#line 1109 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1115 "src/parse-gram.c"
         break;
 
             case 87: // id_colon
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 200 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 647 of yacc.c  */
-#line 1118 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1124 "src/parse-gram.c"
         break;
 
             case 88: // symbol
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 199 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 647 of yacc.c  */
-#line 1127 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1133 "src/parse-gram.c"
         break;
 
             case 89: // string_as_id
 
-/* Line 647 of yacc.c  */
+/* Line 653 of yacc.c  */
 #line 199 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 647 of yacc.c  */
-#line 1136 "../master/src/parse-gram.c"
+/* Line 653 of yacc.c  */
+#line 1142 "src/parse-gram.c"
         break;
 
       default:
@@ -1398,7 +1404,8 @@ yysyntax_error (char *yyresult, int yystate, int yytoken)
       char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
 
       /* Start YYX at -YYN if negative to avoid negative indexes in
-	 YYCHECK.  */
+	 YYCHECK.  In other words, skip the first -YYN actions for this
+	 state because they are default actions.  */
       int yyxbegin = yyn < 0 ? -yyn : 0;
 
       /* Stay within bounds of both yycheck and yytname.  */
@@ -1412,7 +1419,8 @@ yysyntax_error (char *yyresult, int yystate, int yytoken)
       yyarg[yycount++] = yytname[yytoken];
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
+	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
+	    && !yyis_table_ninf (yytable[yyx + yyn]))
 	  {
 	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 	      {
@@ -1645,7 +1653,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1167 of yacc.c  */
+/* Line 1175 of yacc.c  */
 #line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1653,8 +1661,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1167 of yacc.c  */
-#line 1658 "../master/src/parse-gram.c"
+/* Line 1175 of yacc.c  */
+#line 1666 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1753,7 +1761,7 @@ yybackup:
 
   /* First try to decide what to do without reference to lookahead token.  */
   yyn = yypact[yystate];
-  if (yyn == YYPACT_NINF)
+  if (yyis_pact_ninf (yyn))
     goto yydefault;
 
   /* Not known => get a lookahead token if don't already have one.  */
@@ -1784,7 +1792,7 @@ yybackup:
   yyn = yytable[yyn];
   if (yyn <= 0)
     {
-      if (yyn == 0 || yyn == YYTABLE_NINF)
+      if (yyn == 0 || yyis_table_ninf (yyn))
 	goto yyerrlab;
       yyn = -yyn;
       goto yyreduce;
@@ -1840,7 +1848,7 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 223 "parse-gram.y"
     {
       code_props plain_code;
@@ -1851,106 +1859,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1380 of yacc.c  */
-#line 1856 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1864 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 233 "parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1380 of yacc.c  */
-#line 1866 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1874 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 237 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1380 of yacc.c  */
-#line 1877 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1885 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 241 "parse-gram.y"
     { defines_flag = true; }
-/* Line 1380 of yacc.c  */
-#line 1885 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1893 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 243 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1380 of yacc.c  */
-#line 1896 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1904 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 248 "parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1380 of yacc.c  */
-#line 1907 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1915 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 252 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1380 of yacc.c  */
-#line 1915 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1923 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 253 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1380 of yacc.c  */
-#line 1923 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1931 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 254 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1380 of yacc.c  */
-#line 1931 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1939 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 255 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1380 of yacc.c  */
-#line 1939 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1947 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 257 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1380 of yacc.c  */
-#line 1950 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1958 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 262 "parse-gram.y"
     {
       code_props action;
@@ -1960,92 +1968,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1380 of yacc.c  */
-#line 1965 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1973 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 270 "parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1380 of yacc.c  */
-#line 1973 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1981 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 271 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 1981 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1989 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 272 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1380 of yacc.c  */
-#line 1989 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 1997 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 273 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1380 of yacc.c  */
-#line 1997 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2005 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 274 "parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1380 of yacc.c  */
-#line 2005 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2013 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 275 "parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1380 of yacc.c  */
-#line 2013 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2021 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 276 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1380 of yacc.c  */
-#line 2021 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2029 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 277 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1380 of yacc.c  */
-#line 2029 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2037 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 278 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2037 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2045 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 279 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1380 of yacc.c  */
-#line 2045 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2053 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 281 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2070,46 +2078,46 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1380 of yacc.c  */
-#line 2075 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2083 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 304 "parse-gram.y"
     { token_table_flag = true; }
-/* Line 1380 of yacc.c  */
-#line 2083 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2091 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 305 "parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1380 of yacc.c  */
-#line 2091 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2099 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 306 "parse-gram.y"
     { yacc_flag = true; }
-/* Line 1380 of yacc.c  */
-#line 2099 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2107 "src/parse-gram.c"
     break;
 
   case 35:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 314 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1380 of yacc.c  */
-#line 2109 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2117 "src/parse-gram.c"
     break;
 
   case 36:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 318 "parse-gram.y"
     {
       symbol_list *list;
@@ -2117,12 +2125,12 @@ yyreduce:
 	symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1380 of yacc.c  */
-#line 2122 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2130 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 325 "parse-gram.y"
     {
       symbol_list *list;
@@ -2130,32 +2138,32 @@ yyreduce:
 	symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1380 of yacc.c  */
-#line 2135 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2143 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 332 "parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1380 of yacc.c  */
-#line 2145 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2153 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 336 "parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1380 of yacc.c  */
-#line 2155 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2163 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 340 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2163,89 +2171,89 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1380 of yacc.c  */
-#line 2168 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2176 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 347 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1380 of yacc.c  */
-#line 2179 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2187 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 361 "parse-gram.y"
     {}
-/* Line 1380 of yacc.c  */
-#line 2187 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2195 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 362 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2195 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2203 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 367 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1380 of yacc.c  */
-#line 2207 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2215 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 378 "parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1380 of yacc.c  */
-#line 2215 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2223 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 379 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1380 of yacc.c  */
-#line 2226 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2234 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 383 "parse-gram.y"
     { current_class = token_sym; }
-/* Line 1380 of yacc.c  */
-#line 2234 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2242 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 384 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1380 of yacc.c  */
-#line 2245 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2253 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 389 "parse-gram.y"
     {
       symbol_list *list;
@@ -2254,12 +2262,12 @@ yyreduce:
 	symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1380 of yacc.c  */
-#line 2259 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2267 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 400 "parse-gram.y"
     {
       symbol_list *list;
@@ -2272,202 +2280,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1380 of yacc.c  */
-#line 2277 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2285 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 414 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1380 of yacc.c  */
-#line 2285 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2293 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 415 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1380 of yacc.c  */
-#line 2293 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2301 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 416 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1380 of yacc.c  */
-#line 2301 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2309 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 417 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1380 of yacc.c  */
-#line 2309 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2317 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 421 "parse-gram.y"
     { current_type = NULL; }
-/* Line 1380 of yacc.c  */
-#line 2317 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2325 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 422 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1380 of yacc.c  */
-#line 2325 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2333 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 428 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2333 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2341 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1380 of yacc.c  */
-#line 2341 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2349 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 434 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1380 of yacc.c  */
-#line 2349 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2357 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 435 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2357 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2365 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2365 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2373 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1380 of yacc.c  */
-#line 2373 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2381 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 447 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1380 of yacc.c  */
-#line 2381 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2389 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 448 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1380 of yacc.c  */
-#line 2389 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2397 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 452 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2397 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2405 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2405 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2413 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2413 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2421 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2421 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2429 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 461 "parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1380 of yacc.c  */
-#line 2432 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2440 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 466 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1380 of yacc.c  */
-#line 2443 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2451 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 471 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1380 of yacc.c  */
-#line 2455 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2463 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 477 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1380 of yacc.c  */
-#line 2467 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2475 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 483 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2475,128 +2483,128 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1380 of yacc.c  */
-#line 2480 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2488 "src/parse-gram.c"
     break;
 
   case 80:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 513 "parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1380 of yacc.c  */
-#line 2490 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2498 "src/parse-gram.c"
     break;
 
   case 81:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 519 "parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
-/* Line 1380 of yacc.c  */
-#line 2499 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2507 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 524 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2507 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2515 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 525 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2515 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2523 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 531 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
-/* Line 1380 of yacc.c  */
-#line 2524 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2532 "src/parse-gram.c"
     break;
 
   case 87:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 534 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1380 of yacc.c  */
-#line 2532 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2540 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 536 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1380 of yacc.c  */
-#line 2540 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2548 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 538 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2548 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2556 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 540 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2556 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2564 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 542 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2564 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2572 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 546 "parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1380 of yacc.c  */
-#line 2572 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2580 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 548 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2580 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2588 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 560 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1380 of yacc.c  */
-#line 2588 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2596 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 565 "parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1380 of yacc.c  */
-#line 2596 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2604 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 576 "parse-gram.y"
     {
       code_props plain_code;
@@ -2606,51 +2614,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1380 of yacc.c  */
-#line 2611 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2619 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 596 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2619 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2627 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 598 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1380 of yacc.c  */
-#line 2631 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2639 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 606 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1380 of yacc.c  */
-#line 2639 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2647 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 618 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1380 of yacc.c  */
-#line 2650 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2658 "src/parse-gram.c"
     break;
 
   case 106:
-/* Line 1380 of yacc.c  */
+/* Line 1388 of yacc.c  */
 #line 627 "parse-gram.y"
     {
       code_props plain_code;
@@ -2660,13 +2668,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1380 of yacc.c  */
-#line 2665 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2673 "src/parse-gram.c"
     break;
 
 
-/* Line 1380 of yacc.c  */
-#line 2670 "../master/src/parse-gram.c"
+/* Line 1388 of yacc.c  */
+#line 2678 "src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2794,7 +2802,7 @@ yyerrlab1:
   for (;;)
     {
       yyn = yypact[yystate];
-      if (yyn != YYPACT_NINF)
+      if (!yyis_pact_ninf (yyn))
 	{
 	  yyn += YYTERROR;
 	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
@@ -2882,7 +2890,7 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1599 of yacc.c  */
+/* Line 1607 of yacc.c  */
 #line 637 "parse-gram.y"
 
 
