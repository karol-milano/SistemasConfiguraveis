@@ -1,9 +1,8 @@
-/* A Bison parser, made by GNU Bison 2.4.579-a4d1b.  */
+/* A Bison parser, made by GNU Bison 2.4.676-eff9-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
-   Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation,
-   Inc.
+   Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -45,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.579-a4d1b"
+#define YYBISON_VERSION "2.4.676-eff9-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -77,7 +76,7 @@
 #line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002-2011 Free Software Foundation, Inc.
+   Copyright (C) 2002-2012 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -905,11 +904,12 @@ static const yytype_uint8 yyr2[] =
 
 #define YYBACKUP(Token, Value)                                  \
 do                                                              \
-  if (yychar == YYEMPTY && yylen == 1)                          \
+  if (yychar == YYEMPTY)                                        \
     {                                                           \
       yychar = (Token);                                         \
       yylval = (Value);                                         \
-      YYPOPSTACK (1);                                           \
+      YYPOPSTACK (yylen);                                       \
+      yystate = *yyssp;                                         \
       YY_LAC_DISCARD ("YYBACKUP");                              \
       goto yybackup;                                            \
     }                                                           \
@@ -1019,119 +1019,119 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     YYLTYPE const * const yylocationp;
 #endif
 {
+  YYUSE(yyoutput);
+  YYUSE (yylocationp);
+
   if (!yyvaluep)
     return;
-  YYUSE (yylocationp);
 # ifdef YYPRINT
   if (yytype < YYNTOKENS)
     YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
-# else
-  YYUSE (yyoutput);
 # endif
   switch (yytype)
     {
             case 3: // "string"
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 193 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
-/* Line 751 of yacc.c  */
-#line 1039 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1040 "src/parse-gram.c"
         break;
 
             case 4: // "integer"
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 206 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
-/* Line 751 of yacc.c  */
-#line 1048 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1049 "src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 202 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
-/* Line 751 of yacc.c  */
-#line 1057 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1058 "src/parse-gram.c"
         break;
 
             case 40: // "{...}"
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 195 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
-/* Line 751 of yacc.c  */
-#line 1066 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1067 "src/parse-gram.c"
         break;
 
             case 42: // "[identifier]"
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 200 "src/parse-gram.y"
         { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); }
-/* Line 751 of yacc.c  */
-#line 1075 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1076 "src/parse-gram.c"
         break;
 
             case 43: // "char"
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 187 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
-/* Line 751 of yacc.c  */
-#line 1084 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1085 "src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 195 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 751 of yacc.c  */
-#line 1093 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1094 "src/parse-gram.c"
         break;
 
             case 46: // "identifier"
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 199 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 751 of yacc.c  */
-#line 1102 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1103 "src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 201 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
-/* Line 751 of yacc.c  */
-#line 1111 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1112 "src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 195 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 751 of yacc.c  */
-#line 1120 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1121 "src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 203 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
-/* Line 751 of yacc.c  */
-#line 1129 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1130 "src/parse-gram.c"
         break;
 
             case 55: // "%param"
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 249 "src/parse-gram.y"
         {
   switch (((*yyvaluep).param))
@@ -1145,80 +1145,80 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case param_none: aver (false); break;
     }
 }
-/* Line 751 of yacc.c  */
-#line 1149 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1150 "src/parse-gram.c"
         break;
 
             case 72: // symbol.prec
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 209 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 751 of yacc.c  */
-#line 1158 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1159 "src/parse-gram.c"
         break;
 
             case 85: // variable
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 199 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
-/* Line 751 of yacc.c  */
-#line 1167 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1168 "src/parse-gram.c"
         break;
 
             case 86: // content.opt
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 195 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 751 of yacc.c  */
-#line 1176 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1177 "src/parse-gram.c"
         break;
 
             case 87: // braceless
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 195 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
-/* Line 751 of yacc.c  */
-#line 1185 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1186 "src/parse-gram.c"
         break;
 
             case 88: // id
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 209 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 751 of yacc.c  */
-#line 1194 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1195 "src/parse-gram.c"
         break;
 
             case 89: // id_colon
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 210 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
-/* Line 751 of yacc.c  */
-#line 1203 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1204 "src/parse-gram.c"
         break;
 
             case 90: // symbol
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 209 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 751 of yacc.c  */
-#line 1212 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1213 "src/parse-gram.c"
         break;
 
             case 91: // string_as_id
 
-/* Line 751 of yacc.c  */
+/* Line 752 of yacc.c  */
 #line 209 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
-/* Line 751 of yacc.c  */
-#line 1221 "src/parse-gram.c"
+/* Line 752 of yacc.c  */
+#line 1222 "src/parse-gram.c"
         break;
 
       default:
@@ -1849,7 +1849,7 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
     YYLTYPE *yylocationp;
 #endif
 {
-  YYUSE (yyvaluep);
+  YYUSE(yyvaluep);
   YYUSE (yylocationp);
 
   if (!yymsg)
@@ -2012,7 +2012,7 @@ YYLTYPE yylloc;
 #endif
 
 /* User initialization code.  */
-/* Line 1524 of yacc.c  */
+/* Line 1525 of yacc.c  */
 #line 98 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -2020,8 +2020,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1524 of yacc.c  */
-#line 2024 "src/parse-gram.c"
+/* Line 1525 of yacc.c  */
+#line 2025 "src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2214,7 +2214,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 285 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -2225,106 +2225,106 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1740 of yacc.c  */
-#line 2229 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2230 "src/parse-gram.c"
     break;
 
   case 7:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 295 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-/* Line 1740 of yacc.c  */
-#line 2239 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2240 "src/parse-gram.c"
     break;
 
   case 8:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 299 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1740 of yacc.c  */
-#line 2250 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2251 "src/parse-gram.c"
     break;
 
   case 9:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 303 "src/parse-gram.y"
     { defines_flag = true; }
-/* Line 1740 of yacc.c  */
-#line 2258 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2259 "src/parse-gram.c"
     break;
 
   case 10:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 305 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-/* Line 1740 of yacc.c  */
-#line 2269 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2270 "src/parse-gram.c"
     break;
 
   case 11:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 310 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-/* Line 1740 of yacc.c  */
-#line 2280 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2281 "src/parse-gram.c"
     break;
 
   case 12:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 314 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
-/* Line 1740 of yacc.c  */
-#line 2288 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2289 "src/parse-gram.c"
     break;
 
   case 13:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 315 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
-/* Line 1740 of yacc.c  */
-#line 2296 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2297 "src/parse-gram.c"
     break;
 
   case 14:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 316 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1740 of yacc.c  */
-#line 2304 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2305 "src/parse-gram.c"
     break;
 
   case 15:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 317 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
-/* Line 1740 of yacc.c  */
-#line 2312 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2313 "src/parse-gram.c"
     break;
 
   case 16:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 319 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-/* Line 1740 of yacc.c  */
-#line 2323 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2324 "src/parse-gram.c"
     break;
 
   case 17:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 324 "src/parse-gram.y"
     {
       code_props action;
@@ -2334,92 +2334,92 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1740 of yacc.c  */
-#line 2338 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2339 "src/parse-gram.c"
     break;
 
   case 18:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 332 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-/* Line 1740 of yacc.c  */
-#line 2346 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2347 "src/parse-gram.c"
     break;
 
   case 19:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 333 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1740 of yacc.c  */
-#line 2354 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2355 "src/parse-gram.c"
     break;
 
   case 20:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 334 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
-/* Line 1740 of yacc.c  */
-#line 2362 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2363 "src/parse-gram.c"
     break;
 
   case 21:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 335 "src/parse-gram.y"
     { no_lines_flag = true; }
-/* Line 1740 of yacc.c  */
-#line 2370 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2371 "src/parse-gram.c"
     break;
 
   case 22:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 336 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-/* Line 1740 of yacc.c  */
-#line 2378 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2379 "src/parse-gram.c"
     break;
 
   case 23:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 337 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1740 of yacc.c  */
-#line 2386 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2387 "src/parse-gram.c"
     break;
 
   case 24:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 338 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
-/* Line 1740 of yacc.c  */
-#line 2394 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2395 "src/parse-gram.c"
     break;
 
   case 25:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { current_param = (yyvsp[0].param); }
-/* Line 1740 of yacc.c  */
-#line 2402 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2403 "src/parse-gram.c"
     break;
 
   case 26:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 339 "src/parse-gram.y"
     { current_param = param_none; }
-/* Line 1740 of yacc.c  */
-#line 2410 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2411 "src/parse-gram.c"
     break;
 
   case 27:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 340 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-/* Line 1740 of yacc.c  */
-#line 2418 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2419 "src/parse-gram.c"
     break;
 
   case 28:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 342 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
@@ -2444,62 +2444,62 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-/* Line 1740 of yacc.c  */
-#line 2448 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2449 "src/parse-gram.c"
     break;
 
   case 29:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 365 "src/parse-gram.y"
     { token_table_flag = true; }
-/* Line 1740 of yacc.c  */
-#line 2456 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2457 "src/parse-gram.c"
     break;
 
   case 30:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 366 "src/parse-gram.y"
     { report_flag |= report_states; }
-/* Line 1740 of yacc.c  */
-#line 2464 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2465 "src/parse-gram.c"
     break;
 
   case 31:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 367 "src/parse-gram.y"
     { yacc_flag = true; }
-/* Line 1740 of yacc.c  */
-#line 2472 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2473 "src/parse-gram.c"
     break;
 
   case 33:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 372 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2480 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2481 "src/parse-gram.c"
     break;
 
   case 34:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 373 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2488 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2489 "src/parse-gram.c"
     break;
 
   case 37:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 385 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-/* Line 1740 of yacc.c  */
-#line 2498 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2499 "src/parse-gram.c"
     break;
 
   case 38:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 389 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2507,12 +2507,12 @@ yyreduce:
         symbol_list_destructor_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1740 of yacc.c  */
-#line 2511 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2512 "src/parse-gram.c"
     break;
 
   case 39:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 396 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2520,32 +2520,32 @@ yyreduce:
         symbol_list_printer_set (list, (yyvsp[-1].code), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1740 of yacc.c  */
-#line 2524 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2525 "src/parse-gram.c"
     break;
 
   case 40:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 403 "src/parse-gram.y"
     {
       default_prec = true;
     }
-/* Line 1740 of yacc.c  */
-#line 2534 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2535 "src/parse-gram.c"
     break;
 
   case 41:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 407 "src/parse-gram.y"
     {
       default_prec = false;
     }
-/* Line 1740 of yacc.c  */
-#line 2544 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2545 "src/parse-gram.c"
     break;
 
   case 42:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 411 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2553,89 +2553,89 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1740 of yacc.c  */
-#line 2557 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2558 "src/parse-gram.c"
     break;
 
   case 43:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 418 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1740 of yacc.c  */
-#line 2568 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2569 "src/parse-gram.c"
     break;
 
   case 44:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 432 "src/parse-gram.y"
     {}
-/* Line 1740 of yacc.c  */
-#line 2576 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2577 "src/parse-gram.c"
     break;
 
   case 45:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 433 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2584 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2585 "src/parse-gram.c"
     break;
 
   case 46:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 438 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1740 of yacc.c  */
-#line 2596 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2597 "src/parse-gram.c"
     break;
 
   case 47:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 449 "src/parse-gram.y"
     { current_class = nterm_sym; }
-/* Line 1740 of yacc.c  */
-#line 2604 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2605 "src/parse-gram.c"
     break;
 
   case 48:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 450 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1740 of yacc.c  */
-#line 2615 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2616 "src/parse-gram.c"
     break;
 
   case 49:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 454 "src/parse-gram.y"
     { current_class = token_sym; }
-/* Line 1740 of yacc.c  */
-#line 2623 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2624 "src/parse-gram.c"
     break;
 
   case 50:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 455 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-/* Line 1740 of yacc.c  */
-#line 2634 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2635 "src/parse-gram.c"
     break;
 
   case 51:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 460 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2644,12 +2644,12 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-/* Line 1740 of yacc.c  */
-#line 2648 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2649 "src/parse-gram.c"
     break;
 
   case 52:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 471 "src/parse-gram.y"
     {
       symbol_list *list;
@@ -2662,202 +2662,202 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-/* Line 1740 of yacc.c  */
-#line 2666 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2667 "src/parse-gram.c"
     break;
 
   case 53:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 485 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
-/* Line 1740 of yacc.c  */
-#line 2674 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2675 "src/parse-gram.c"
     break;
 
   case 54:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 486 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
-/* Line 1740 of yacc.c  */
-#line 2682 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2683 "src/parse-gram.c"
     break;
 
   case 55:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 487 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
-/* Line 1740 of yacc.c  */
-#line 2690 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2691 "src/parse-gram.c"
     break;
 
   case 56:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 488 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
-/* Line 1740 of yacc.c  */
-#line 2698 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2699 "src/parse-gram.c"
     break;
 
   case 57:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 492 "src/parse-gram.y"
     { current_type = NULL; }
-/* Line 1740 of yacc.c  */
-#line 2706 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2707 "src/parse-gram.c"
     break;
 
   case 58:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 493 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-/* Line 1740 of yacc.c  */
-#line 2714 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2715 "src/parse-gram.c"
     break;
 
   case 59:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 499 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2722 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2723 "src/parse-gram.c"
     break;
 
   case 60:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 501 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1740 of yacc.c  */
-#line 2730 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2731 "src/parse-gram.c"
     break;
 
   case 61:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 505 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
-/* Line 1740 of yacc.c  */
-#line 2738 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2739 "src/parse-gram.c"
     break;
 
   case 62:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 506 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2746 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2747 "src/parse-gram.c"
     break;
 
   case 63:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 512 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2754 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2755 "src/parse-gram.c"
     break;
 
   case 64:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 514 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-/* Line 1740 of yacc.c  */
-#line 2762 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2763 "src/parse-gram.c"
     break;
 
   case 65:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 518 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
-/* Line 1740 of yacc.c  */
-#line 2770 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2771 "src/parse-gram.c"
     break;
 
   case 66:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 519 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
-/* Line 1740 of yacc.c  */
-#line 2778 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2779 "src/parse-gram.c"
     break;
 
   case 67:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 523 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2786 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2787 "src/parse-gram.c"
     break;
 
   case 68:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 524 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2794 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2795 "src/parse-gram.c"
     break;
 
   case 69:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 525 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2802 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2803 "src/parse-gram.c"
     break;
 
   case 70:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 526 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2810 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2811 "src/parse-gram.c"
     break;
 
   case 71:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 532 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
      }
-/* Line 1740 of yacc.c  */
-#line 2821 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2822 "src/parse-gram.c"
     break;
 
   case 72:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 537 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
-/* Line 1740 of yacc.c  */
-#line 2832 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2833 "src/parse-gram.c"
     break;
 
   case 73:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 542 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-/* Line 1740 of yacc.c  */
-#line 2844 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2845 "src/parse-gram.c"
     break;
 
   case 74:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 548 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1740 of yacc.c  */
-#line 2856 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2857 "src/parse-gram.c"
     break;
 
   case 75:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 554 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
@@ -2865,154 +2865,154 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-/* Line 1740 of yacc.c  */
-#line 2869 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2870 "src/parse-gram.c"
     break;
 
   case 82:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 584 "src/parse-gram.y"
     {
       yyerrok;
     }
-/* Line 1740 of yacc.c  */
-#line 2879 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2880 "src/parse-gram.c"
     break;
 
   case 83:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 590 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1740 of yacc.c  */
-#line 2887 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2888 "src/parse-gram.c"
     break;
 
   case 84:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 591 "src/parse-gram.y"
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-/* Line 1740 of yacc.c  */
-#line 2898 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2899 "src/parse-gram.c"
     break;
 
   case 85:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 598 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2906 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2907 "src/parse-gram.c"
     break;
 
   case 86:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 599 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2914 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2915 "src/parse-gram.c"
     break;
 
   case 88:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 605 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-/* Line 1740 of yacc.c  */
-#line 2923 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2924 "src/parse-gram.c"
     break;
 
   case 89:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 608 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-/* Line 1740 of yacc.c  */
-#line 2931 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2932 "src/parse-gram.c"
     break;
 
   case 90:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 610 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-/* Line 1740 of yacc.c  */
-#line 2939 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2940 "src/parse-gram.c"
     break;
 
   case 91:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 612 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-/* Line 1740 of yacc.c  */
-#line 2947 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2948 "src/parse-gram.c"
     break;
 
   case 92:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 614 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2955 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2956 "src/parse-gram.c"
     break;
 
   case 93:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 616 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2963 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2964 "src/parse-gram.c"
     break;
 
   case 94:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 618 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2971 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2972 "src/parse-gram.c"
     break;
 
   case 95:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 622 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
-/* Line 1740 of yacc.c  */
-#line 2979 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2980 "src/parse-gram.c"
     break;
 
   case 96:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 624 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 2987 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2988 "src/parse-gram.c"
     break;
 
   case 98:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 635 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-/* Line 1740 of yacc.c  */
-#line 2995 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 2996 "src/parse-gram.c"
     break;
 
   case 99:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 640 "src/parse-gram.y"
     { (yyval.chars) = ""; }
-/* Line 1740 of yacc.c  */
-#line 3003 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3004 "src/parse-gram.c"
     break;
 
   case 100:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 641 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
-/* Line 1740 of yacc.c  */
-#line 3011 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3012 "src/parse-gram.c"
     break;
 
   case 102:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 652 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -3022,51 +3022,51 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-/* Line 1740 of yacc.c  */
-#line 3026 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3027 "src/parse-gram.c"
     break;
 
   case 103:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 672 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 3034 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3035 "src/parse-gram.c"
     break;
 
   case 104:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 674 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-/* Line 1740 of yacc.c  */
-#line 3046 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3047 "src/parse-gram.c"
     break;
 
   case 105:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 682 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-/* Line 1740 of yacc.c  */
-#line 3054 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3055 "src/parse-gram.c"
     break;
 
   case 108:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 694 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-/* Line 1740 of yacc.c  */
-#line 3065 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3066 "src/parse-gram.c"
     break;
 
   case 110:
-/* Line 1740 of yacc.c  */
+/* Line 1741 of yacc.c  */
 #line 703 "src/parse-gram.y"
     {
       code_props plain_code;
@@ -3076,13 +3076,13 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-/* Line 1740 of yacc.c  */
-#line 3080 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3081 "src/parse-gram.c"
     break;
 
 
-/* Line 1740 of yacc.c  */
-#line 3085 "src/parse-gram.c"
+/* Line 1741 of yacc.c  */
+#line 3086 "src/parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3329,7 +3329,7 @@ yyreturn:
   return YYID (yyresult);
 }
 
-/* Line 2000 of yacc.c  */
+/* Line 2001 of yacc.c  */
 #line 713 "src/parse-gram.y"
 
 
@@ -3425,7 +3425,7 @@ version_check (location const *loc, char const *version)
     {
       complain_at (*loc, "require bison %s, but have %s",
                    version, PACKAGE_VERSION);
-      exit (63);
+      exit (EX_CONFIG);
     }
 }
 
