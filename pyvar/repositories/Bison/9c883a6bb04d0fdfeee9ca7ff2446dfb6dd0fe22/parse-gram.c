@@ -1,8 +1,8 @@
-/* A Bison parser, made by GNU Bison 2.5.66-427a.  */
+/* A Bison parser, made by GNU Bison 2.5.118-ae42b.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
-      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
+      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.5.66-427a"
+#define YYBISON_VERSION "2.5.118-ae42b"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -169,7 +169,15 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 
 
 /* Line 268 of yacc.c  */
-#line 173 "../../../src/parse-gram.c"
+#line 173 "parse-gram.c"
+
+# ifndef YY_NULL
+#  if defined __cplusplus && 201103L <= __cplusplus
+#   define YY_NULL nullptr
+#  else
+#   define YY_NULL 0
+#  endif
+# endif
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -319,7 +327,7 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 typedef union YYSTYPE
 {
 
-/* Line 293 of yacc.c  */
+/* Line 295 of yacc.c  */
 #line 113 "parse-gram.y"
 
   symbol *symbol;
@@ -334,8 +342,8 @@ typedef union YYSTYPE
 
 
 
-/* Line 293 of yacc.c  */
-#line 339 "../../../src/parse-gram.c"
+/* Line 295 of yacc.c  */
+#line 347 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -359,8 +367,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 343 of yacc.c  */
-#line 364 "../../../src/parse-gram.c"
+/* Line 345 of yacc.c  */
+#line 372 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -707,7 +715,7 @@ static const char *const yytname[] =
   "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
   "rules_or_grammar_declaration", "rules", "$@3", "rhses.1", "rhs",
   "named_ref.opt", "variable", "content.opt", "braceless", "id",
-  "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
+  "id_colon", "symbol", "string_as_id", "epilogue.opt", YY_NULL
 };
 #endif
 
@@ -1036,6 +1044,8 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     YYLTYPE const * const yylocationp;
 #endif
 {
+  FILE *yyo = yyoutput;
+  YYUSE (yyo);
   if (!yyvaluep)
     return;
   YYUSE (yylocationp);
@@ -1049,165 +1059,165 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 203 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 821 of yacc.c  */
-#line 1058 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1068 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 215 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 821 of yacc.c  */
-#line 1067 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1077 "parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 821 of yacc.c  */
-#line 1076 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1086 "parse-gram.c"
 	break;
       case 44: /* "\"[identifier]\"" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 210 "parse-gram.y"
 	{ fprintf (stderr, "[%s]", (yyvaluep->uniqstr)); };
 
-/* Line 821 of yacc.c  */
-#line 1085 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1095 "parse-gram.c"
 	break;
       case 45: /* "\"char\"" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 197 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 821 of yacc.c  */
-#line 1094 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1104 "parse-gram.c"
 	break;
       case 46: /* "\"epilogue\"" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 821 of yacc.c  */
-#line 1103 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1113 "parse-gram.c"
 	break;
       case 48: /* "\"identifier\"" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 209 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 821 of yacc.c  */
-#line 1112 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1122 "parse-gram.c"
 	break;
       case 49: /* "\"identifier:\"" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 211 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 821 of yacc.c  */
-#line 1121 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1131 "parse-gram.c"
 	break;
       case 52: /* "\"%{...%}\"" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 821 of yacc.c  */
-#line 1130 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1140 "parse-gram.c"
 	break;
       case 54: /* "\"type\"" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 212 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 821 of yacc.c  */
-#line 1139 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1149 "parse-gram.c"
 	break;
       case 71: /* "symbol.prec" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 218 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 821 of yacc.c  */
-#line 1148 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1158 "parse-gram.c"
 	break;
       case 84: /* "variable" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 209 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 821 of yacc.c  */
-#line 1157 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1167 "parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 821 of yacc.c  */
-#line 1166 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1176 "parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 205 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 821 of yacc.c  */
-#line 1175 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1185 "parse-gram.c"
 	break;
       case 87: /* "id" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 218 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 821 of yacc.c  */
-#line 1184 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1194 "parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 219 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 821 of yacc.c  */
-#line 1193 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1203 "parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 218 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 821 of yacc.c  */
-#line 1202 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1212 "parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
-/* Line 821 of yacc.c  */
+/* Line 823 of yacc.c  */
 #line 218 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 821 of yacc.c  */
-#line 1211 "../../../src/parse-gram.c"
+/* Line 823 of yacc.c  */
+#line 1221 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1690,12 +1700,12 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                 yytype_int16 *yyesa, yytype_int16 **yyes,
                 YYSIZE_T *yyes_capacity, yytype_int16 *yyssp, int yytoken)
 {
-  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
+  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
   YYSIZE_T yysize1;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
-  const char *yyformat = 0;
+  const char *yyformat = YY_NULL;
   /* Arguments of yyformat. */
   char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
   /* Number of reported tokens (one for the "unexpected", one per
@@ -1753,7 +1763,7 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                     break;
                   }
                 yyarg[yycount++] = yytname[yyx];
-                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
+                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
                 if (! (yysize <= yysize1
                        && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                   return 2;
@@ -1998,7 +2008,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1592 of yacc.c  */
+/* Line 1594 of yacc.c  */
 #line 105 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -2007,8 +2017,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1592 of yacc.c  */
-#line 2012 "../../../src/parse-gram.c"
+/* Line 1594 of yacc.c  */
+#line 2022 "parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2202,7 +2212,7 @@ yyreduce:
       {
           case 6:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 244 "parse-gram.y"
     {
       code_props plain_code;
@@ -2217,14 +2227,14 @@ yyreduce:
 
   case 7:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 253 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 255 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -2234,14 +2244,14 @@ yyreduce:
 
   case 9:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 259 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 261 "parse-gram.y"
     {
       defines_flag = true;
@@ -2251,42 +2261,42 @@ yyreduce:
 
   case 11:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 265 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 266 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 267 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 268 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 269 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 271 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2296,7 +2306,7 @@ yyreduce:
 
   case 17:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 276 "parse-gram.y"
     {
       code_props action;
@@ -2310,77 +2320,77 @@ yyreduce:
 
   case 18:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 284 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 285 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 286 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 287 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 288 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 289 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 290 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 291 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 292 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 293 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 295 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2400,14 +2410,14 @@ yyreduce:
 
   case 29:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 309 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 311 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2423,7 +2433,7 @@ yyreduce:
             xmalloc (dir_length + 1 + strlen (skeleton_user) + 1);
           if (dir_length > 0)
             {
-              strncpy (skeleton_build, current_file, dir_length);
+              memcpy (skeleton_build, current_file, dir_length);
               skeleton_build[dir_length++] = '/';
             }
           strcpy (skeleton_build + dir_length, skeleton_user);
@@ -2436,28 +2446,28 @@ yyreduce:
 
   case 31:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 334 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 335 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 336 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 344 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2466,7 +2476,7 @@ yyreduce:
 
   case 38:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 348 "parse-gram.y"
     {
       symbol_list *list;
@@ -2478,7 +2488,7 @@ yyreduce:
 
   case 39:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 355 "parse-gram.y"
     {
       symbol_list *list;
@@ -2490,7 +2500,7 @@ yyreduce:
 
   case 40:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 362 "parse-gram.y"
     {
       default_prec = true;
@@ -2499,7 +2509,7 @@ yyreduce:
 
   case 41:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 366 "parse-gram.y"
     {
       default_prec = false;
@@ -2508,7 +2518,7 @@ yyreduce:
 
   case 42:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 370 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2520,7 +2530,7 @@ yyreduce:
 
   case 43:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 377 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2530,21 +2540,21 @@ yyreduce:
 
   case 44:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 391 "parse-gram.y"
     {}
     break;
 
   case 45:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 392 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 397 "parse-gram.y"
     {
       union_seen = true;
@@ -2555,14 +2565,14 @@ yyreduce:
 
   case 47:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 408 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 409 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2572,14 +2582,14 @@ yyreduce:
 
   case 49:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 413 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 414 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2589,7 +2599,7 @@ yyreduce:
 
   case 51:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 419 "parse-gram.y"
     {
       symbol_list *list;
@@ -2602,7 +2612,7 @@ yyreduce:
 
   case 52:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 430 "parse-gram.y"
     {
       symbol_list *list;
@@ -2619,126 +2629,126 @@ yyreduce:
 
   case 53:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 444 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 445 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 446 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 450 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 451 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 459 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 463 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 464 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 470 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 472 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 476 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 477 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 481 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 482 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 483 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 484 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 490 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2748,7 +2758,7 @@ yyreduce:
 
   case 71:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 495 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2758,7 +2768,7 @@ yyreduce:
 
   case 72:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 500 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2769,7 +2779,7 @@ yyreduce:
 
   case 73:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 506 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2780,7 +2790,7 @@ yyreduce:
 
   case 74:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 512 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2792,7 +2802,7 @@ yyreduce:
 
   case 81:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 542 "parse-gram.y"
     {
       yyerrok;
@@ -2801,14 +2811,14 @@ yyreduce:
 
   case 82:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 548 "parse-gram.y"
     { current_lhs ((yyvsp[(1) - (2)].symbol), (yylsp[(1) - (2)]), (yyvsp[(2) - (2)].named_ref)); }
     break;
 
   case 83:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 549 "parse-gram.y"
     {
     /* Free the current lhs. */
@@ -2818,21 +2828,21 @@ yyreduce:
 
   case 84:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 556 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 557 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 563 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
 				  current_lhs_named_ref); }
@@ -2840,77 +2850,77 @@ yyreduce:
 
   case 88:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 566 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 568 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 570 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 572 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 574 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 578 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 580 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 592 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 597 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 598 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 609 "parse-gram.y"
     {
       code_props plain_code;
@@ -2924,14 +2934,14 @@ yyreduce:
 
   case 101:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 629 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 631 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2942,14 +2952,14 @@ yyreduce:
 
   case 103:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 639 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 651 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2959,7 +2969,7 @@ yyreduce:
 
   case 108:
 
-/* Line 1808 of yacc.c  */
+/* Line 1810 of yacc.c  */
 #line 660 "parse-gram.y"
     {
       code_props plain_code;
@@ -2973,8 +2983,8 @@ yyreduce:
 
 
 
-/* Line 1808 of yacc.c  */
-#line 2978 "../../../src/parse-gram.c"
+/* Line 1810 of yacc.c  */
+#line 2988 "parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3223,7 +3233,7 @@ yyreturn:
 
 
 
-/* Line 2069 of yacc.c  */
+/* Line 2071 of yacc.c  */
 #line 670 "parse-gram.y"
 
 
@@ -3291,16 +3301,8 @@ add_param (char const *type, char *decl, location loc)
     complain_at (loc, _("missing identifier in parameter declaration"));
   else
     {
-      char *name;
-      size_t name_len;
-
-      for (name_len = 1;
-	   memchr (alphanum, name_start[name_len], sizeof alphanum);
-	   name_len++)
-	continue;
-
-      name = xmalloc (name_len + 1);
-      memcpy (name, name_start, name_len);
+      size_t name_len = strspn (name_start, alphanum);
+      char *name = xmemdup (name_start, name_len + 1);
       name[name_len] = '\0';
       muscle_pair_list_grow (type, decl, name);
       free (name);
