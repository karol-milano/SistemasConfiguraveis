@@ -1,7 +1,7 @@
 /* A Bison parser, made by GNU Bison 2.1a.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
-   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -172,10 +172,10 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "../../src/parse-gram.y"
+#line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
+   Copyright (C) 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -253,17 +253,19 @@ static int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 82 "../../src/parse-gram.y"
-typedef union YYSTYPE {
+typedef union YYSTYPE 
+#line 82 "parse-gram.y"
+{
   symbol *symbol;
   symbol_list *list;
   int integer;
   char *chars;
   assoc assoc;
   uniqstr uniqstr;
-} YYSTYPE;
-/* Line 196 of yacc.c.  */
-#line 267 "../../src/parse-gram.c"
+}
+/* Line 197 of yacc.c.  */
+#line 268 "parse-gram.c"
+	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -286,8 +288,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 219 of yacc.c.  */
-#line 291 "../../src/parse-gram.c"
+/* Line 220 of yacc.c.  */
+#line 293 "parse-gram.c"
 
 /* Define YYMODERN_C if this compiler supports C89 or better.  If
    __STDC__ is defined, the compiler is modern.  IBM xlc 7.0 when run
@@ -388,7 +390,7 @@ YYID (i)
        and a page size can be as small as 4096 bytes.  So we cannot safely
        invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
        to allow for a few compiler-allocated temporary stack slots.  */
-#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2005 */
+#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
 #  endif
 # else
 #  define YYSTACK_ALLOC YYMALLOC
@@ -587,12 +589,12 @@ static const unsigned short int yyrline[] =
        0,   192,   192,   200,   202,   206,   207,   208,   209,   210,
      211,   212,   213,   214,   215,   216,   221,   225,   226,   227,
      228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
-     238,   242,   243,   244,   248,   254,   261,   268,   272,   279,
-     279,   284,   284,   289,   299,   314,   315,   316,   320,   321,
-     327,   328,   333,   337,   342,   348,   354,   365,   366,   375,
-     376,   382,   383,   388,   395,   395,   399,   400,   401,   406,
-     407,   409,   411,   413,   415,   420,   421,   425,   431,   440,
-     445,   447
+     238,   242,   243,   244,   248,   264,   271,   278,   282,   289,
+     289,   294,   294,   299,   309,   324,   325,   326,   330,   331,
+     337,   338,   343,   347,   352,   358,   364,   375,   376,   385,
+     386,   392,   393,   394,   401,   401,   405,   406,   407,   412,
+     413,   415,   417,   419,   421,   426,   427,   431,   437,   446,
+     451,   453
 };
 #endif
 
@@ -923,94 +925,94 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "\"string\"" */
-#line 169 "../../src/parse-gram.y"
+#line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 929 "../../src/parse-gram.c"
+#line 931 "parse-gram.c"
         break;
       case 4: /* "\"integer\"" */
-#line 182 "../../src/parse-gram.y"
+#line 182 "parse-gram.y"
         { fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 934 "../../src/parse-gram.c"
+#line 936 "parse-gram.c"
         break;
       case 8: /* "\"%destructor {...}\"" */
-#line 171 "../../src/parse-gram.y"
+#line 171 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 939 "../../src/parse-gram.c"
+#line 941 "parse-gram.c"
         break;
       case 9: /* "\"%printer {...}\"" */
-#line 175 "../../src/parse-gram.y"
+#line 175 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 944 "../../src/parse-gram.c"
+#line 946 "parse-gram.c"
         break;
       case 10: /* "\"%union {...}\"" */
-#line 176 "../../src/parse-gram.y"
+#line 176 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 949 "../../src/parse-gram.c"
+#line 951 "parse-gram.c"
         break;
       case 26: /* "\"%initial-action {...}\"" */
-#line 172 "../../src/parse-gram.y"
+#line 172 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 954 "../../src/parse-gram.c"
+#line 956 "parse-gram.c"
         break;
       case 27: /* "\"%lex-param {...}\"" */
-#line 173 "../../src/parse-gram.y"
+#line 173 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 959 "../../src/parse-gram.c"
+#line 961 "parse-gram.c"
         break;
       case 34: /* "\"%parse-param {...}\"" */
-#line 174 "../../src/parse-gram.y"
+#line 174 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 964 "../../src/parse-gram.c"
+#line 966 "parse-gram.c"
         break;
       case 42: /* "\"type\"" */
-#line 180 "../../src/parse-gram.y"
+#line 180 "parse-gram.y"
         { fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 969 "../../src/parse-gram.c"
+#line 971 "parse-gram.c"
         break;
       case 46: /* "\"identifier\"" */
-#line 184 "../../src/parse-gram.y"
+#line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 974 "../../src/parse-gram.c"
+#line 976 "parse-gram.c"
         break;
       case 47: /* "\"identifier:\"" */
-#line 186 "../../src/parse-gram.y"
+#line 186 "parse-gram.y"
         { fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 979 "../../src/parse-gram.c"
+#line 981 "parse-gram.c"
         break;
       case 49: /* "\"%{...%}\"" */
-#line 178 "../../src/parse-gram.y"
+#line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 984 "../../src/parse-gram.c"
+#line 986 "parse-gram.c"
         break;
       case 50: /* "\"epilogue\"" */
-#line 178 "../../src/parse-gram.y"
+#line 178 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 989 "../../src/parse-gram.c"
+#line 991 "parse-gram.c"
         break;
       case 51: /* "\"{...}\"" */
-#line 177 "../../src/parse-gram.y"
+#line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 994 "../../src/parse-gram.c"
+#line 996 "parse-gram.c"
         break;
       case 72: /* "symbol" */
-#line 184 "../../src/parse-gram.y"
+#line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 999 "../../src/parse-gram.c"
+#line 1001 "parse-gram.c"
         break;
       case 73: /* "action" */
-#line 177 "../../src/parse-gram.y"
+#line 177 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1004 "../../src/parse-gram.c"
+#line 1006 "parse-gram.c"
         break;
       case 74: /* "string_as_id" */
-#line 184 "../../src/parse-gram.y"
+#line 184 "parse-gram.y"
         { fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1009 "../../src/parse-gram.c"
+#line 1011 "parse-gram.c"
         break;
       case 75: /* "string_content" */
-#line 169 "../../src/parse-gram.y"
+#line 169 "parse-gram.y"
         { fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1014 "../../src/parse-gram.c"
+#line 1016 "parse-gram.c"
         break;
       default:
         break;
@@ -1509,7 +1511,7 @@ YYLTYPE yylloc;
 
 
   /* User initialization code.  */
-#line 72 "../../src/parse-gram.y"
+#line 72 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1517,8 +1519,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 1087 of yacc.c.  */
-#line 1522 "../../src/parse-gram.c"
+/* Line 1088 of yacc.c.  */
+#line 1524 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1703,52 +1705,52 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 207 "../../src/parse-gram.y"
+#line 207 "parse-gram.y"
     { prologue_augment ((yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 7:
-#line 208 "../../src/parse-gram.y"
+#line 208 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 209 "../../src/parse-gram.y"
+#line 209 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (2)].chars), "1"); }
     break;
 
   case 9:
-#line 210 "../../src/parse-gram.y"
+#line 210 "parse-gram.y"
     { muscle_insert ((yyvsp[(2) - (3)].chars), (yyvsp[(3) - (3)].chars)); }
     break;
 
   case 10:
-#line 211 "../../src/parse-gram.y"
+#line 211 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 11:
-#line 212 "../../src/parse-gram.y"
+#line 212 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-#line 213 "../../src/parse-gram.y"
+#line 213 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-#line 214 "../../src/parse-gram.y"
+#line 214 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-#line 215 "../../src/parse-gram.y"
+#line 215 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 15:
-#line 217 "../../src/parse-gram.y"
+#line 217 "parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1756,95 +1758,105 @@ yyreduce:
     break;
 
   case 16:
-#line 222 "../../src/parse-gram.y"
+#line 222 "parse-gram.y"
     {
     muscle_code_grow ("initial_action", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
   }
     break;
 
   case 17:
-#line 225 "../../src/parse-gram.y"
+#line 225 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 18:
-#line 226 "../../src/parse-gram.y"
+#line 226 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 19:
-#line 227 "../../src/parse-gram.y"
+#line 227 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 20:
-#line 228 "../../src/parse-gram.y"
+#line 228 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 21:
-#line 229 "../../src/parse-gram.y"
+#line 229 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 22:
-#line 230 "../../src/parse-gram.y"
+#line 230 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-#line 231 "../../src/parse-gram.y"
+#line 231 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)])); }
     break;
 
   case 24:
-#line 232 "../../src/parse-gram.y"
+#line 232 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 25:
-#line 233 "../../src/parse-gram.y"
+#line 233 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 26:
-#line 234 "../../src/parse-gram.y"
+#line 234 "parse-gram.y"
     { skeleton = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 27:
-#line 235 "../../src/parse-gram.y"
+#line 235 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 28:
-#line 236 "../../src/parse-gram.y"
+#line 236 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 29:
-#line 237 "../../src/parse-gram.y"
+#line 237 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 33:
-#line 245 "../../src/parse-gram.y"
+#line 245 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
     break;
 
   case 34:
-#line 249 "../../src/parse-gram.y"
+#line 249 "parse-gram.y"
     {
+      char const *body = (yyvsp[(1) - (1)].chars);
+
+      if (typed)
+	{
+	  /* Concatenate the union bodies, turning the first one's
+	     trailing '}' into '\n', and omitting the second one's '{'.  */
+	  char *code = muscle_find ("stype");
+	  code[strlen (code) - 1] = '\n';
+	  body++;
+	}
+
       typed = true;
-      MUSCLE_INSERT_INT ("stype_line", (yylsp[(1) - (1)]).start.line);
-      muscle_insert ("stype", (yyvsp[(1) - (1)].chars));
+      muscle_code_grow ("stype", body, (yylsp[(1) - (1)]));
     }
     break;
 
   case 35:
-#line 255 "../../src/parse-gram.y"
+#line 265 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1854,7 +1866,7 @@ yyreduce:
     break;
 
   case 36:
-#line 262 "../../src/parse-gram.y"
+#line 272 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(2) - (2)].list); list; list = list->next)
@@ -1864,26 +1876,26 @@ yyreduce:
     break;
 
   case 37:
-#line 269 "../../src/parse-gram.y"
+#line 279 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 38:
-#line 273 "../../src/parse-gram.y"
+#line 283 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 39:
-#line 279 "../../src/parse-gram.y"
+#line 289 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 40:
-#line 280 "../../src/parse-gram.y"
+#line 290 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1891,12 +1903,12 @@ yyreduce:
     break;
 
   case 41:
-#line 284 "../../src/parse-gram.y"
+#line 294 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 42:
-#line 285 "../../src/parse-gram.y"
+#line 295 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1904,7 +1916,7 @@ yyreduce:
     break;
 
   case 43:
-#line 290 "../../src/parse-gram.y"
+#line 300 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -1914,7 +1926,7 @@ yyreduce:
     break;
 
   case 44:
-#line 300 "../../src/parse-gram.y"
+#line 310 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1929,173 +1941,165 @@ yyreduce:
     break;
 
   case 45:
-#line 314 "../../src/parse-gram.y"
+#line 324 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 46:
-#line 315 "../../src/parse-gram.y"
+#line 325 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 47:
-#line 316 "../../src/parse-gram.y"
+#line 326 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 48:
-#line 320 "../../src/parse-gram.y"
+#line 330 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 49:
-#line 321 "../../src/parse-gram.y"
+#line 331 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 50:
-#line 327 "../../src/parse-gram.y"
+#line 337 "parse-gram.y"
     { (yyval.list) = symbol_list_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 51:
-#line 328 "../../src/parse-gram.y"
+#line 338 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 52:
-#line 334 "../../src/parse-gram.y"
+#line 344 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
      }
     break;
 
   case 53:
-#line 338 "../../src/parse-gram.y"
+#line 348 "parse-gram.y"
     {
-       symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]));
+       symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
     break;
 
   case 54:
-#line 343 "../../src/parse-gram.y"
+#line 353 "parse-gram.y"
     {
-      symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]));
+      symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
       symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)]));
     }
     break;
 
   case 55:
-#line 349 "../../src/parse-gram.y"
+#line 359 "parse-gram.y"
     {
-      symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]));
+      symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
       symbol_make_alias ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].symbol), (yyloc));
     }
     break;
 
   case 56:
-#line 355 "../../src/parse-gram.y"
+#line 365 "parse-gram.y"
     {
-      symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]));
+      symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
       symbol_user_token_number_set ((yyvsp[(1) - (3)].symbol), (yyvsp[(2) - (3)].integer), (yylsp[(2) - (3)]));
       symbol_make_alias ((yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].symbol), (yyloc));
     }
     break;
 
-  case 62:
-#line 384 "../../src/parse-gram.y"
-    {
-      if (yacc_flag)
-	complain_at ((yyloc), _("POSIX forbids declarations in the grammar"));
-    }
-    break;
-
   case 63:
-#line 389 "../../src/parse-gram.y"
+#line 395 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 64:
-#line 395 "../../src/parse-gram.y"
+#line 401 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 66:
-#line 399 "../../src/parse-gram.y"
+#line 405 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
-#line 400 "../../src/parse-gram.y"
+#line 406 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 69:
-#line 406 "../../src/parse-gram.y"
+#line 412 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 70:
-#line 408 "../../src/parse-gram.y"
+#line 414 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 71:
-#line 410 "../../src/parse-gram.y"
+#line 416 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)])); }
     break;
 
   case 72:
-#line 412 "../../src/parse-gram.y"
+#line 418 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 73:
-#line 414 "../../src/parse-gram.y"
+#line 420 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 74:
-#line 416 "../../src/parse-gram.y"
+#line 422 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 75:
-#line 420 "../../src/parse-gram.y"
+#line 426 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 76:
-#line 421 "../../src/parse-gram.y"
+#line 427 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 77:
-#line 426 "../../src/parse-gram.y"
+#line 432 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 78:
-#line 432 "../../src/parse-gram.y"
+#line 438 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
-      symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]));
+      symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
     break;
 
   case 79:
-#line 441 "../../src/parse-gram.y"
+#line 447 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].chars); }
     break;
 
   case 81:
-#line 448 "../../src/parse-gram.y"
+#line 454 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       scanner_last_string_free ();
@@ -2103,8 +2107,8 @@ yyreduce:
     break;
 
 
-/* Line 1276 of yacc.c.  */
-#line 2108 "../../src/parse-gram.c"
+/* Line 1277 of yacc.c.  */
+#line 2112 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2323,7 +2327,7 @@ yyreturn:
 }
 
 
-#line 454 "../../src/parse-gram.y"
+#line 460 "parse-gram.y"
 
 
 
