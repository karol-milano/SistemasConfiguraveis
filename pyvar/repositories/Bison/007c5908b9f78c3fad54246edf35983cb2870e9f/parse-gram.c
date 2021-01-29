@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.5.1.885-485b-dirty.  */
+/* A Bison parser, made by GNU Bison 2.5.1.899-d02b0-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.5.1.885-485b-dirty"
+#define YYBISON_VERSION "2.5.1.899-d02b0-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -913,21 +913,6 @@ static const yytype_uint8 yyr2[] =
 #define YYERROR         goto yyerrorlab
 
 
-/* Like YYERROR except do call yyerror.  This remains here temporarily
-   to ease the transition to the new meaning of YYERROR, for GCC.
-   Once GCC version 2 has supplanted version 1, this can go.  However,
-   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
-   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
-   discussed.  */
-
-#define YYFAIL          goto yyerrlab
-#if defined YYFAIL
-  /* This is here to suppress warnings from the GCC cpp's
-     -Wunused-macros.  Normally we don't worry about that warning, but
-     some users do, and we want to make it easy for users to remove
-     YYFAIL uses, which will produce warnings from Bison 2.5.  */
-#endif
-
 #define YYRECOVERING()  (!!yyerrstatus)
 
 #define YYBACKUP(Token, Value)                                  \
@@ -1059,95 +1044,95 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
             case 3: // "string"
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 195 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-/* Line 740 of yacc.c  */
-#line 1067 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1052 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 208 "src/parse-gram.y"
         { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-/* Line 740 of yacc.c  */
-#line 1075 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1060 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 204 "src/parse-gram.y"
         { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 740 of yacc.c  */
-#line 1083 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1068 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 740 of yacc.c  */
-#line 1091 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1076 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 740 of yacc.c  */
-#line 1099 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1084 "src/parse-gram.c"
         break;
 
             case 43: // "char"
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 189 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), yyo); }
-/* Line 740 of yacc.c  */
-#line 1107 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1092 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 740 of yacc.c  */
-#line 1115 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1100 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 201 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 740 of yacc.c  */
-#line 1123 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1108 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 203 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 740 of yacc.c  */
-#line 1131 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1116 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 740 of yacc.c  */
-#line 1139 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1124 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 205 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 740 of yacc.c  */
-#line 1147 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1132 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 251 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1161,88 +1146,88 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case param_none: aver (false); break;
     }
 }
-/* Line 740 of yacc.c  */
-#line 1166 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1151 "src/parse-gram.c"
         break;
 
             case 64: // code_props_type
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 421 "src/parse-gram.y"
         { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-/* Line 740 of yacc.c  */
-#line 1174 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1159 "src/parse-gram.c"
         break;
 
             case 73: // symbol.prec
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 740 of yacc.c  */
-#line 1182 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1167 "src/parse-gram.c"
         break;
 
             case 77: // tag
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 205 "src/parse-gram.y"
         { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 740 of yacc.c  */
-#line 1190 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1175 "src/parse-gram.c"
         break;
 
             case 87: // variable
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 201 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), yyo); }
-/* Line 740 of yacc.c  */
-#line 1198 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1183 "src/parse-gram.c"
         break;
 
             case 88: // content.opt
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 740 of yacc.c  */
-#line 1206 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1191 "src/parse-gram.c"
         break;
 
             case 89: // braceless
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 197 "src/parse-gram.y"
         { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 740 of yacc.c  */
-#line 1214 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1199 "src/parse-gram.c"
         break;
 
             case 90: // id
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 740 of yacc.c  */
-#line 1222 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1207 "src/parse-gram.c"
         break;
 
             case 91: // id_colon
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 212 "src/parse-gram.y"
         { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 740 of yacc.c  */
-#line 1230 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1215 "src/parse-gram.c"
         break;
 
             case 92: // symbol
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 740 of yacc.c  */
-#line 1238 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1223 "src/parse-gram.c"
         break;
 
             case 93: // string_as_id
-/* Line 740 of yacc.c  */
+/* Line 725 of yacc.c  */
 #line 211 "src/parse-gram.y"
         { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 740 of yacc.c  */
-#line 1246 "src/parse-gram.c"
+/* Line 725 of yacc.c  */
+#line 1231 "src/parse-gram.c"
         break;
 
       default:
@@ -1741,10 +1726,6 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
   int yycount = 0;
 
   /* There are many possibilities here to consider:
-     - Assume YYFAIL is not used.  It's too flawed to consider.  See
-       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
-       for details.  YYERROR is fine as it does not invoke this
-       function.
      - If this state is a consistent state with a default action, then
        the only way this function was invoked is if the default action
        is an error action.  In that case, don't check for expected
@@ -2019,7 +2000,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1505 of yacc.c  */
+/* Line 1486 of yacc.c  */
 #line 100 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -2027,8 +2008,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1505 of yacc.c  */
-#line 2032 "src/parse-gram.c"
+/* Line 1486 of yacc.c  */
+#line 2013 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2221,7 +2202,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 287 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2232,106 +2213,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1721 of yacc.c  */
-#line 2237 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2218 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 297 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1721 of yacc.c  */
-#line 2247 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2228 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 301 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1721 of yacc.c  */
-#line 2258 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2239 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 305 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1721 of yacc.c  */
-#line 2266 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2247 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 307 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1721 of yacc.c  */
-#line 2277 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2258 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 312 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1721 of yacc.c  */
-#line 2288 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2269 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 316 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1721 of yacc.c  */
-#line 2296 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2277 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1721 of yacc.c  */
-#line 2304 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2285 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 318 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1721 of yacc.c  */
-#line 2312 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2293 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 319 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1721 of yacc.c  */
-#line 2320 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2301 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 321 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1721 of yacc.c  */
-#line 2331 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2312 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 326 "src/parse-gram.y"
     {
       code_props action;
@@ -2341,92 +2322,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1721 of yacc.c  */
-#line 2346 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2327 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 334 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1721 of yacc.c  */
-#line 2354 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2335 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 335 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1721 of yacc.c  */
-#line 2362 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2343 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 336 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1721 of yacc.c  */
-#line 2370 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2351 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 337 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1721 of yacc.c  */
-#line 2378 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2359 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 338 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1721 of yacc.c  */
-#line 2386 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2367 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1721 of yacc.c  */
-#line 2394 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2375 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 340 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1721 of yacc.c  */
-#line 2402 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2383 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 341 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1721 of yacc.c  */
-#line 2410 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2391 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 341 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1721 of yacc.c  */
-#line 2418 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2399 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 342 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1721 of yacc.c  */
-#line 2426 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2407 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 344 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2451,62 +2432,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1721 of yacc.c  */
-#line 2456 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2437 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 367 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1721 of yacc.c  */
-#line 2464 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2445 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 368 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1721 of yacc.c  */
-#line 2472 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2453 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 369 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1721 of yacc.c  */
-#line 2480 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2461 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 374 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2488 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2469 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 375 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2496 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2477 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 387 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1721 of yacc.c  */
-#line 2506 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2487 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 391 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2514,32 +2495,32 @@ yyreduce:
         symbol_list_code_props_set (list, (yyvsp[-2].code_type), (yylsp[-1]), (yyvsp[-1].code));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1721 of yacc.c  */
-#line 2519 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2500 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 398 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1721 of yacc.c  */
-#line 2529 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2510 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 402 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1721 of yacc.c  */
-#line 2539 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2520 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 406 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2547,105 +2528,105 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1721 of yacc.c  */
-#line 2552 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2533 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 413 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1721 of yacc.c  */
-#line 2563 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2544 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 423 "src/parse-gram.y"
     { (yyval.code_type) = destructor; }
-/* Line 1721 of yacc.c  */
-#line 2571 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2552 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 424 "src/parse-gram.y"
     { (yyval.code_type) = printer; }
-/* Line 1721 of yacc.c  */
-#line 2579 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2560 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 434 "src/parse-gram.y"
     {}
-/* Line 1721 of yacc.c  */
-#line 2587 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2568 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 435 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2595 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2576 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 440 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1721 of yacc.c  */
-#line 2607 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2588 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 451 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1721 of yacc.c  */
-#line 2615 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2596 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 452 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1721 of yacc.c  */
-#line 2626 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2607 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 456 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1721 of yacc.c  */
-#line 2634 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2615 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 457 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1721 of yacc.c  */
-#line 2645 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2626 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 462 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2654,12 +2635,12 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1721 of yacc.c  */
-#line 2659 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2640 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 473 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2672,202 +2653,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1721 of yacc.c  */
-#line 2677 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2658 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 487 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1721 of yacc.c  */
-#line 2685 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2666 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 488 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1721 of yacc.c  */
-#line 2693 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2674 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 489 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1721 of yacc.c  */
-#line 2701 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2682 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 490 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1721 of yacc.c  */
-#line 2709 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2690 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 494 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1721 of yacc.c  */
-#line 2717 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2698 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 495 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1721 of yacc.c  */
-#line 2725 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2706 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 501 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2733 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2714 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 503 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1721 of yacc.c  */
-#line 2741 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2722 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 507 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1721 of yacc.c  */
-#line 2749 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2730 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 508 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2757 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2738 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 514 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2765 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2746 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 516 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1721 of yacc.c  */
-#line 2773 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2754 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 520 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1721 of yacc.c  */
-#line 2781 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2762 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 521 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1721 of yacc.c  */
-#line 2789 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2770 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 525 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2797 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2778 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 526 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2805 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2786 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 531 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-/* Line 1721 of yacc.c  */
-#line 2813 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2794 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 532 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new (""); }
-/* Line 1721 of yacc.c  */
-#line 2821 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2802 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 538 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1721 of yacc.c  */
-#line 2832 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2813 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 543 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1721 of yacc.c  */
-#line 2843 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2824 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 548 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1721 of yacc.c  */
-#line 2855 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2836 "src/parse-gram.c"
     break;
 
   case 76:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 554 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1721 of yacc.c  */
-#line 2867 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2848 "src/parse-gram.c"
     break;
 
   case 77:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 560 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2875,154 +2856,154 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1721 of yacc.c  */
-#line 2880 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2861 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 590 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1721 of yacc.c  */
-#line 2890 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2871 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 596 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1721 of yacc.c  */
-#line 2898 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2879 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 597 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1721 of yacc.c  */
-#line 2909 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2890 "src/parse-gram.c"
     break;
 
   case 87:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 604 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2917 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2898 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 605 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2925 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2906 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 611 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1721 of yacc.c  */
-#line 2934 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2915 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 614 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1721 of yacc.c  */
-#line 2942 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2923 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 616 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1721 of yacc.c  */
-#line 2950 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2931 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 618 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1721 of yacc.c  */
-#line 2958 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2939 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 620 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2966 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2947 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 622 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2974 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2955 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 624 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2982 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2963 "src/parse-gram.c"
     break;
 
   case 97:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 628 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1721 of yacc.c  */
-#line 2990 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2971 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 630 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 2998 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2979 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 641 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1721 of yacc.c  */
-#line 3006 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2987 "src/parse-gram.c"
     break;
 
   case 101:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 646 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1721 of yacc.c  */
-#line 3014 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 2995 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 647 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1721 of yacc.c  */
-#line 3022 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 3003 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 658 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -3032,51 +3013,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1721 of yacc.c  */
-#line 3037 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 3018 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 678 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 3045 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 3026 "src/parse-gram.c"
     break;
 
   case 106:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 680 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1721 of yacc.c  */
-#line 3057 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 3038 "src/parse-gram.c"
     break;
 
   case 107:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 688 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1721 of yacc.c  */
-#line 3065 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 3046 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 700 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1721 of yacc.c  */
-#line 3076 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 3057 "src/parse-gram.c"
     break;
 
   case 112:
-/* Line 1721 of yacc.c  */
+/* Line 1702 of yacc.c  */
 #line 709 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -3086,13 +3067,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1721 of yacc.c  */
-#line 3091 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 3072 "src/parse-gram.c"
     break;
 
 
-/* Line 1721 of yacc.c  */
-#line 3096 "src/parse-gram.c"
+/* Line 1702 of yacc.c  */
+#line 3077 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3133,9 +3114,9 @@ yyreduce:
   goto yynewstate;
 
 
-/*------------------------------------.
-| yyerrlab -- here on detecting error |
-`------------------------------------*/
+/*--------------------------------------.
+| yyerrlab -- here on detecting error.  |
+`--------------------------------------*/
 yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
@@ -3339,7 +3320,7 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 1981 of yacc.c  */
+/* Line 1962 of yacc.c  */
 #line 719 "src/parse-gram.y"
 
 
