@@ -1,10 +1,9 @@
+/* A Bison parser, made by GNU Bison 2.3b.153-3d8d7.  */
 
-/* A Bison parser, made by GNU Bison 2.3b.21-d67c5-dirty.  */
-
-/* Skeleton implementation for Bison's Yacc-like parsers in C
+/* Implementation for Bison's Yacc-like parsers in C
    
-      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
-   Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006,
+   2007, 2008 Free Software Foundation, Inc.
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -46,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.3b.21-d67c5-dirty"
+#define YYBISON_VERSION "2.3b.153-3d8d7"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -75,7 +74,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 189 of yacc.c  */
+/* Line 191 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -150,8 +149,8 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 189 of yacc.c  */
-#line 155 "parse-gram.c"
+/* Line 191 of yacc.c  */
+#line 154 "../../../src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -299,7 +298,7 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 222 of yacc.c  */
+/* Line 216 of yacc.c  */
 #line 92 "parse-gram.y"
 
   symbol *symbol;
@@ -313,8 +312,8 @@ typedef union YYSTYPE
 
 
 
-/* Line 222 of yacc.c  */
-#line 318 "parse-gram.c"
+/* Line 216 of yacc.c  */
+#line 317 "../../../src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -338,8 +337,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 264 of yacc.c  */
-#line 343 "parse-gram.c"
+/* Line 266 of yacc.c  */
+#line 342 "../../../src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -1029,147 +1028,147 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 180 "parse-gram.y"
-	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
+	{ fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
 
-/* Line 715 of yacc.c  */
-#line 1038 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1037 "../../../src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 191 "parse-gram.y"
-	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
+	{ fprintf (stderr, "%d", ((*yyvaluep).integer)); };
 
-/* Line 715 of yacc.c  */
-#line 1047 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1046 "../../../src/parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 182 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
+	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
 
-/* Line 715 of yacc.c  */
-#line 1056 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1055 "../../../src/parse-gram.c"
 	break;
       case 44: /* "\"char\"" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 174 "parse-gram.y"
-	{ fputs (char_name ((yyvaluep->character)), stderr); };
+	{ fputs (char_name (((*yyvaluep).character)), stderr); };
 
-/* Line 715 of yacc.c  */
-#line 1065 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1064 "../../../src/parse-gram.c"
 	break;
       case 45: /* "\"epilogue\"" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 182 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
-/* Line 715 of yacc.c  */
-#line 1074 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1073 "../../../src/parse-gram.c"
 	break;
       case 47: /* "\"identifier\"" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 187 "parse-gram.y"
-	{ fputs ((yyvaluep->uniqstr), stderr); };
+	{ fputs (((*yyvaluep).uniqstr), stderr); };
 
-/* Line 715 of yacc.c  */
-#line 1083 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1082 "../../../src/parse-gram.c"
 	break;
       case 48: /* "\"identifier:\"" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 188 "parse-gram.y"
-	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
+	{ fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
 
-/* Line 715 of yacc.c  */
-#line 1092 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1091 "../../../src/parse-gram.c"
 	break;
       case 51: /* "\"%{...%}\"" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 182 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
-/* Line 715 of yacc.c  */
-#line 1101 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1100 "../../../src/parse-gram.c"
 	break;
       case 53: /* "\"type\"" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 186 "parse-gram.y"
-	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
+	{ fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
 
-/* Line 715 of yacc.c  */
-#line 1110 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1109 "../../../src/parse-gram.c"
 	break;
       case 82: /* "variable" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 187 "parse-gram.y"
-	{ fputs ((yyvaluep->uniqstr), stderr); };
+	{ fputs (((*yyvaluep).uniqstr), stderr); };
 
-/* Line 715 of yacc.c  */
-#line 1119 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1118 "../../../src/parse-gram.c"
 	break;
       case 83: /* "content.opt" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 182 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
-/* Line 715 of yacc.c  */
-#line 1128 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1127 "../../../src/parse-gram.c"
 	break;
       case 84: /* "braceless" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 182 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
+	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
 
-/* Line 715 of yacc.c  */
-#line 1137 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1136 "../../../src/parse-gram.c"
 	break;
       case 85: /* "id" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 194 "parse-gram.y"
-	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
-/* Line 715 of yacc.c  */
-#line 1146 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1145 "../../../src/parse-gram.c"
 	break;
       case 86: /* "id_colon" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 195 "parse-gram.y"
-	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
+	{ fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
 
-/* Line 715 of yacc.c  */
-#line 1155 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1154 "../../../src/parse-gram.c"
 	break;
       case 87: /* "symbol" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 194 "parse-gram.y"
-	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
-/* Line 715 of yacc.c  */
-#line 1164 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1163 "../../../src/parse-gram.c"
 	break;
       case 88: /* "string_as_id" */
 
-/* Line 715 of yacc.c  */
+/* Line 717 of yacc.c  */
 #line 194 "parse-gram.y"
-	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
+	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
 
-/* Line 715 of yacc.c  */
-#line 1173 "parse-gram.c"
+/* Line 717 of yacc.c  */
+#line 1172 "../../../src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1688,7 +1687,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 
-/* Line 1248 of yacc.c  */
+/* Line 1244 of yacc.c  */
 #line 84 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -1697,8 +1696,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1248 of yacc.c  */
-#line 1702 "parse-gram.c"
+/* Line 1244 of yacc.c  */
+#line 1701 "../../../src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1885,7 +1884,7 @@ yyreduce:
     {
         case 6:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 218 "parse-gram.y"
     {
       code_props plain_code;
@@ -1896,89 +1895,122 @@ yyreduce:
                         plain_code.code, (yylsp[(1) - (1)]));
       code_scanner_last_string_free ();
     }
+
+/* Line 1457 of yacc.c  */
+#line 1901 "../../../src/parse-gram.c"
     break;
 
   case 7:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 227 "parse-gram.y"
     { debug_flag = true; }
+
+/* Line 1457 of yacc.c  */
+#line 1911 "../../../src/parse-gram.c"
     break;
 
   case 8:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 229 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
     }
+
+/* Line 1457 of yacc.c  */
+#line 1923 "../../../src/parse-gram.c"
     break;
 
   case 9:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 232 "parse-gram.y"
     { defines_flag = true; }
+
+/* Line 1457 of yacc.c  */
+#line 1933 "../../../src/parse-gram.c"
     break;
 
   case 10:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 234 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
     }
+
+/* Line 1457 of yacc.c  */
+#line 1946 "../../../src/parse-gram.c"
     break;
 
   case 11:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 238 "parse-gram.y"
     { error_verbose = true; }
+
+/* Line 1457 of yacc.c  */
+#line 1956 "../../../src/parse-gram.c"
     break;
 
   case 12:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 239 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
+
+/* Line 1457 of yacc.c  */
+#line 1966 "../../../src/parse-gram.c"
     break;
 
   case 13:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 240 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
+
+/* Line 1457 of yacc.c  */
+#line 1976 "../../../src/parse-gram.c"
     break;
 
   case 14:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 241 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
+
+/* Line 1457 of yacc.c  */
+#line 1986 "../../../src/parse-gram.c"
     break;
 
   case 15:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 242 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
+
+/* Line 1457 of yacc.c  */
+#line 1996 "../../../src/parse-gram.c"
     break;
 
   case 16:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 244 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
+
+/* Line 1457 of yacc.c  */
+#line 2009 "../../../src/parse-gram.c"
     break;
 
   case 17:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 249 "parse-gram.y"
     {
       code_props action;
@@ -1988,81 +2020,114 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[(2) - (2)]));
       code_scanner_last_string_free ();
     }
+
+/* Line 1457 of yacc.c  */
+#line 2026 "../../../src/parse-gram.c"
     break;
 
   case 18:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 257 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2036 "../../../src/parse-gram.c"
     break;
 
   case 19:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 258 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2046 "../../../src/parse-gram.c"
     break;
 
   case 20:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 259 "parse-gram.y"
     { locations_flag = true; }
+
+/* Line 1457 of yacc.c  */
+#line 2056 "../../../src/parse-gram.c"
     break;
 
   case 21:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 260 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
+
+/* Line 1457 of yacc.c  */
+#line 2066 "../../../src/parse-gram.c"
     break;
 
   case 22:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 261 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
+
+/* Line 1457 of yacc.c  */
+#line 2076 "../../../src/parse-gram.c"
     break;
 
   case 23:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 262 "parse-gram.y"
     { no_lines_flag = true; }
+
+/* Line 1457 of yacc.c  */
+#line 2086 "../../../src/parse-gram.c"
     break;
 
   case 24:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 263 "parse-gram.y"
     { nondeterministic_parser = true; }
+
+/* Line 1457 of yacc.c  */
+#line 2096 "../../../src/parse-gram.c"
     break;
 
   case 25:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 264 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
+
+/* Line 1457 of yacc.c  */
+#line 2106 "../../../src/parse-gram.c"
     break;
 
   case 26:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 265 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
+
+/* Line 1457 of yacc.c  */
+#line 2116 "../../../src/parse-gram.c"
     break;
 
   case 27:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 266 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2126 "../../../src/parse-gram.c"
     break;
 
   case 28:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 268 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2076,18 +2141,24 @@ yyreduce:
       if (!muscle_percent_define_flag_if ("api.pure"))
         muscle_percent_define_insert ("api.pure", (yylsp[(1) - (1)]), "");
     }
+
+/* Line 1457 of yacc.c  */
+#line 2147 "../../../src/parse-gram.c"
     break;
 
   case 29:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 280 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
+
+/* Line 1457 of yacc.c  */
+#line 2157 "../../../src/parse-gram.c"
     break;
 
   case 30:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 282 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2112,41 +2183,56 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, 1, &(yylsp[(1) - (2)]));
     }
+
+/* Line 1457 of yacc.c  */
+#line 2189 "../../../src/parse-gram.c"
     break;
 
   case 31:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 305 "parse-gram.y"
     { token_table_flag = true; }
+
+/* Line 1457 of yacc.c  */
+#line 2199 "../../../src/parse-gram.c"
     break;
 
   case 32:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 306 "parse-gram.y"
     { report_flag |= report_states; }
+
+/* Line 1457 of yacc.c  */
+#line 2209 "../../../src/parse-gram.c"
     break;
 
   case 33:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 307 "parse-gram.y"
     { yacc_flag = true; }
+
+/* Line 1457 of yacc.c  */
+#line 2219 "../../../src/parse-gram.c"
     break;
 
   case 37:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 315 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
+
+/* Line 1457 of yacc.c  */
+#line 2231 "../../../src/parse-gram.c"
     break;
 
   case 38:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 319 "parse-gram.y"
     {
       symbol_list *list;
@@ -2154,11 +2240,14 @@ yyreduce:
 	symbol_list_destructor_set (list, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
+
+/* Line 1457 of yacc.c  */
+#line 2246 "../../../src/parse-gram.c"
     break;
 
   case 39:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 326 "parse-gram.y"
     {
       symbol_list *list;
@@ -2166,29 +2255,38 @@ yyreduce:
 	symbol_list_printer_set (list, (yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
+
+/* Line 1457 of yacc.c  */
+#line 2261 "../../../src/parse-gram.c"
     break;
 
   case 40:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 333 "parse-gram.y"
     {
       default_prec = true;
     }
+
+/* Line 1457 of yacc.c  */
+#line 2273 "../../../src/parse-gram.c"
     break;
 
   case 41:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 337 "parse-gram.y"
     {
       default_prec = false;
     }
+
+/* Line 1457 of yacc.c  */
+#line 2285 "../../../src/parse-gram.c"
     break;
 
   case 42:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 341 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2196,80 +2294,107 @@ yyreduce:
       muscle_code_grow ("percent_code()", (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
       code_scanner_last_string_free ();
     }
+
+/* Line 1457 of yacc.c  */
+#line 2300 "../../../src/parse-gram.c"
     break;
 
   case 43:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 348 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
     }
+
+/* Line 1457 of yacc.c  */
+#line 2313 "../../../src/parse-gram.c"
     break;
 
   case 44:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 362 "parse-gram.y"
     {}
+
+/* Line 1457 of yacc.c  */
+#line 2323 "../../../src/parse-gram.c"
     break;
 
   case 45:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 363 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2333 "../../../src/parse-gram.c"
     break;
 
   case 46:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 368 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
     }
+
+/* Line 1457 of yacc.c  */
+#line 2347 "../../../src/parse-gram.c"
     break;
 
   case 47:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 379 "parse-gram.y"
     { current_class = nterm_sym; }
+
+/* Line 1457 of yacc.c  */
+#line 2357 "../../../src/parse-gram.c"
     break;
 
   case 48:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 380 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
+
+/* Line 1457 of yacc.c  */
+#line 2370 "../../../src/parse-gram.c"
     break;
 
   case 49:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 384 "parse-gram.y"
     { current_class = token_sym; }
+
+/* Line 1457 of yacc.c  */
+#line 2380 "../../../src/parse-gram.c"
     break;
 
   case 50:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 385 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
+
+/* Line 1457 of yacc.c  */
+#line 2393 "../../../src/parse-gram.c"
     break;
 
   case 51:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 390 "parse-gram.y"
     {
       symbol_list *list;
@@ -2278,11 +2403,14 @@ yyreduce:
 	symbol_type_set (list->content.sym, (yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]));
       symbol_list_free ((yyvsp[(3) - (3)].list));
     }
+
+/* Line 1457 of yacc.c  */
+#line 2409 "../../../src/parse-gram.c"
     break;
 
   case 52:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 401 "parse-gram.y"
     {
       symbol_list *list;
@@ -2295,172 +2423,238 @@ yyreduce:
       symbol_list_free ((yyvsp[(3) - (3)].list));
       current_type = NULL;
     }
+
+/* Line 1457 of yacc.c  */
+#line 2429 "../../../src/parse-gram.c"
     break;
 
   case 53:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 415 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
+
+/* Line 1457 of yacc.c  */
+#line 2439 "../../../src/parse-gram.c"
     break;
 
   case 54:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 416 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
+
+/* Line 1457 of yacc.c  */
+#line 2449 "../../../src/parse-gram.c"
     break;
 
   case 55:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 417 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
+
+/* Line 1457 of yacc.c  */
+#line 2459 "../../../src/parse-gram.c"
     break;
 
   case 56:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 421 "parse-gram.y"
     { current_type = NULL; }
+
+/* Line 1457 of yacc.c  */
+#line 2469 "../../../src/parse-gram.c"
     break;
 
   case 57:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 422 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
+
+/* Line 1457 of yacc.c  */
+#line 2479 "../../../src/parse-gram.c"
     break;
 
   case 58:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 428 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2489 "../../../src/parse-gram.c"
     break;
 
   case 59:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
+
+/* Line 1457 of yacc.c  */
+#line 2499 "../../../src/parse-gram.c"
     break;
 
   case 60:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 434 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
+
+/* Line 1457 of yacc.c  */
+#line 2509 "../../../src/parse-gram.c"
     break;
 
   case 61:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 435 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2519 "../../../src/parse-gram.c"
     break;
 
   case 62:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2529 "../../../src/parse-gram.c"
     break;
 
   case 63:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
+
+/* Line 1457 of yacc.c  */
+#line 2539 "../../../src/parse-gram.c"
     break;
 
   case 64:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 447 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
+
+/* Line 1457 of yacc.c  */
+#line 2549 "../../../src/parse-gram.c"
     break;
 
   case 65:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 448 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
+
+/* Line 1457 of yacc.c  */
+#line 2559 "../../../src/parse-gram.c"
     break;
 
   case 66:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 452 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2569 "../../../src/parse-gram.c"
     break;
 
   case 67:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2579 "../../../src/parse-gram.c"
     break;
 
   case 68:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2589 "../../../src/parse-gram.c"
     break;
 
   case 69:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2599 "../../../src/parse-gram.c"
     break;
 
   case 70:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 461 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
      }
+
+/* Line 1457 of yacc.c  */
+#line 2612 "../../../src/parse-gram.c"
     break;
 
   case 71:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 466 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
      }
+
+/* Line 1457 of yacc.c  */
+#line 2625 "../../../src/parse-gram.c"
     break;
 
   case 72:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 471 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
       symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)]));
     }
+
+/* Line 1457 of yacc.c  */
+#line 2639 "../../../src/parse-gram.c"
     break;
 
   case 73:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 477 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
       symbol_make_alias ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].symbol), (yyloc));
     }
+
+/* Line 1457 of yacc.c  */
+#line 2653 "../../../src/parse-gram.c"
     break;
 
   case 74:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 483 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2468,99 +2662,138 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[(1) - (3)].symbol), (yyvsp[(2) - (3)].integer), (yylsp[(2) - (3)]));
       symbol_make_alias ((yyvsp[(1) - (3)].symbol), (yyvsp[(3) - (3)].symbol), (yyloc));
     }
+
+/* Line 1457 of yacc.c  */
+#line 2668 "../../../src/parse-gram.c"
     break;
 
   case 81:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 513 "parse-gram.y"
     {
       yyerrok;
     }
+
+/* Line 1457 of yacc.c  */
+#line 2680 "../../../src/parse-gram.c"
     break;
 
   case 82:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 519 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
+
+/* Line 1457 of yacc.c  */
+#line 2690 "../../../src/parse-gram.c"
     break;
 
   case 84:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 523 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2700 "../../../src/parse-gram.c"
     break;
 
   case 85:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 524 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2710 "../../../src/parse-gram.c"
     break;
 
   case 87:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 530 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
+
+/* Line 1457 of yacc.c  */
+#line 2720 "../../../src/parse-gram.c"
     break;
 
   case 88:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 532 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2730 "../../../src/parse-gram.c"
     break;
 
   case 89:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 534 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2740 "../../../src/parse-gram.c"
     break;
 
   case 90:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 536 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2750 "../../../src/parse-gram.c"
     break;
 
   case 91:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 538 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2760 "../../../src/parse-gram.c"
     break;
 
   case 92:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 540 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2770 "../../../src/parse-gram.c"
     break;
 
   case 94:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 550 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
+
+/* Line 1457 of yacc.c  */
+#line 2780 "../../../src/parse-gram.c"
     break;
 
   case 95:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 556 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
+
+/* Line 1457 of yacc.c  */
+#line 2792 "../../../src/parse-gram.c"
     break;
 
   case 97:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 569 "parse-gram.y"
     {
       code_props plain_code;
@@ -2570,46 +2803,61 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
+
+/* Line 1457 of yacc.c  */
+#line 2809 "../../../src/parse-gram.c"
     break;
 
   case 98:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 589 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2819 "../../../src/parse-gram.c"
     break;
 
   case 99:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 591 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[(1) - (1)].character), (yylsp[(1) - (1)]));
     }
+
+/* Line 1457 of yacc.c  */
+#line 2833 "../../../src/parse-gram.c"
     break;
 
   case 100:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 599 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2843 "../../../src/parse-gram.c"
     break;
 
   case 103:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 611 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
     }
+
+/* Line 1457 of yacc.c  */
+#line 2856 "../../../src/parse-gram.c"
     break;
 
   case 105:
 
-/* Line 1455 of yacc.c  */
+/* Line 1457 of yacc.c  */
 #line 620 "parse-gram.y"
     {
       code_props plain_code;
@@ -2619,12 +2867,15 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[(2) - (2)]));
       code_scanner_last_string_free ();
     }
+
+/* Line 1457 of yacc.c  */
+#line 2873 "../../../src/parse-gram.c"
     break;
 
 
 
-/* Line 1455 of yacc.c  */
-#line 2628 "parse-gram.c"
+/* Line 1457 of yacc.c  */
+#line 2879 "../../../src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2842,7 +3093,7 @@ yyreturn:
 
 
 
-/* Line 1675 of yacc.c  */
+/* Line 1677 of yacc.c  */
 #line 630 "parse-gram.y"
 
 
