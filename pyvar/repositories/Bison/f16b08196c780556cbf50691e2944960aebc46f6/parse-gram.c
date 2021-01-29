@@ -6,10 +6,10 @@
       Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
    Free Software Foundation, Inc.
    
-   This program is free software; you can redistribute it and/or modify
+   This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
-   the Free Software Foundation; either version 2, or (at your option)
-   any later version.
+   the Free Software Foundation, either version 3 of the License, or
+   (at your option) any later version.
    
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
@@ -17,9 +17,7 @@
    GNU General Public License for more details.
    
    You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 51 Franklin Street, Fifth Floor,
-   Boston, MA 02110-1301, USA.  */
+   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 /* As a special exception, you may create a larger work that contains
    part or all of the Bison parser skeleton and distribute that work
@@ -77,7 +75,7 @@
 
 /* Copy the first part of user declarations.  */
 
-/* Line 1537 of yacc.c  */
+/* Line 22 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -86,9 +84,9 @@
 
    This file is part of Bison, the GNU Compiler Compiler.
 
-   This program is free software; you can redistribute it and/or modify
+   This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
-   the Free Software Foundation; either version 2 of the License, or
+   the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
 
    This program is distributed in the hope that it will be useful,
@@ -97,10 +95,7 @@
    GNU General Public License for more details.
 
    You should have received a copy of the GNU General Public License
-   along with this program; if not, write to the Free Software
-   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
-   02110-1301  USA
-*/
+   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
 
 #include <config.h>
 #include "system.h"
@@ -157,8 +152,8 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 
-/* Line 1537 of yacc.c  */
-#line 162 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 157 "parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -310,8 +305,8 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 
-/* Line 1537 of yacc.c  */
-#line 97 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 94 "parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -324,8 +319,8 @@ typedef union YYSTYPE
 
 
 
-/* Line 1537 of yacc.c  */
-#line 329 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 324 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -349,8 +344,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 1537 of yacc.c  */
-#line 354 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 349 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -675,17 +670,17 @@ static const yytype_int8 yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   210,   210,   218,   220,   224,   225,   235,   236,   240,
-     241,   246,   247,   248,   249,   250,   251,   256,   265,   266,
-     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
-     277,   278,   279,   303,   304,   305,   306,   310,   311,   312,
-     316,   323,   330,   334,   338,   345,   360,   361,   365,   377,
-     377,   382,   382,   387,   398,   413,   414,   415,   419,   420,
-     425,   427,   432,   433,   437,   438,   439,   440,   445,   450,
-     455,   461,   467,   478,   479,   488,   489,   495,   496,   497,
-     504,   504,   508,   509,   510,   515,   516,   518,   520,   522,
-     524,   534,   535,   541,   544,   553,   573,   575,   584,   589,
-     590,   595,   602,   604
+       0,   207,   207,   215,   217,   221,   222,   232,   233,   237,
+     238,   243,   244,   245,   246,   247,   248,   253,   262,   263,
+     264,   265,   266,   267,   268,   269,   270,   271,   272,   273,
+     274,   275,   276,   300,   301,   302,   303,   307,   308,   309,
+     313,   320,   327,   331,   335,   342,   357,   358,   362,   374,
+     374,   379,   379,   384,   395,   410,   411,   412,   416,   417,
+     422,   424,   429,   430,   434,   435,   436,   437,   442,   447,
+     452,   458,   464,   475,   476,   485,   486,   492,   493,   494,
+     501,   501,   505,   506,   507,   512,   513,   515,   517,   519,
+     521,   531,   532,   538,   541,   550,   570,   572,   581,   586,
+     587,   592,   599,   601
 };
 #endif
 
@@ -1040,147 +1035,147 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
     {
       case 3: /* "\"string\"" */
 
-/* Line 1537 of yacc.c  */
-#line 188 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 185 "parse-gram.y"
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
-/* Line 1537 of yacc.c  */
-#line 1049 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1044 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
-/* Line 1537 of yacc.c  */
-#line 199 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 196 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
-/* Line 1537 of yacc.c  */
-#line 1058 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1053 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 
-/* Line 1537 of yacc.c  */
-#line 190 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
-/* Line 1537 of yacc.c  */
-#line 1067 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1062 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 
-/* Line 1537 of yacc.c  */
-#line 182 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 179 "parse-gram.y"
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
-/* Line 1537 of yacc.c  */
-#line 1076 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1071 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 
-/* Line 1537 of yacc.c  */
-#line 190 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1537 of yacc.c  */
-#line 1085 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1080 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 
-/* Line 1537 of yacc.c  */
-#line 195 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 192 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 1537 of yacc.c  */
-#line 1094 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1089 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 
-/* Line 1537 of yacc.c  */
-#line 196 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 193 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
-/* Line 1537 of yacc.c  */
-#line 1103 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1098 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 
-/* Line 1537 of yacc.c  */
-#line 190 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1537 of yacc.c  */
-#line 1112 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1107 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 
-/* Line 1537 of yacc.c  */
-#line 194 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 191 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
-/* Line 1537 of yacc.c  */
-#line 1121 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1116 "parse-gram.c"
 	break;
       case 82: /* "variable" */
 
-/* Line 1537 of yacc.c  */
-#line 195 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 192 "parse-gram.y"
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
-/* Line 1537 of yacc.c  */
-#line 1130 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1125 "parse-gram.c"
 	break;
       case 83: /* "content.opt" */
 
-/* Line 1537 of yacc.c  */
-#line 190 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1537 of yacc.c  */
-#line 1139 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1134 "parse-gram.c"
 	break;
       case 84: /* "braceless" */
 
-/* Line 1537 of yacc.c  */
-#line 190 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 187 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
-/* Line 1537 of yacc.c  */
-#line 1148 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1143 "parse-gram.c"
 	break;
       case 85: /* "id" */
 
-/* Line 1537 of yacc.c  */
-#line 202 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1537 of yacc.c  */
-#line 1157 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1152 "parse-gram.c"
 	break;
       case 86: /* "id_colon" */
 
-/* Line 1537 of yacc.c  */
-#line 203 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 200 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
-/* Line 1537 of yacc.c  */
-#line 1166 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1161 "parse-gram.c"
 	break;
       case 87: /* "symbol" */
 
-/* Line 1537 of yacc.c  */
-#line 202 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1537 of yacc.c  */
-#line 1175 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1170 "parse-gram.c"
 	break;
       case 88: /* "string_as_id" */
 
-/* Line 1537 of yacc.c  */
-#line 202 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 199 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
-/* Line 1537 of yacc.c  */
-#line 1184 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1179 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1694,8 +1689,8 @@ YYLTYPE yylloc;
 
   /* User initialization code.  */
   
-/* Line 1537 of yacc.c  */
-#line 89 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 86 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1703,8 +1698,8 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-/* Line 1537 of yacc.c  */
-#line 1708 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 1703 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1889,8 +1884,8 @@ yyreduce:
     {
         case 6:
 
-/* Line 1537 of yacc.c  */
-#line 226 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 223 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(1) - (1)].chars), (yylsp[(1) - (1)]));
@@ -1904,15 +1899,15 @@ yyreduce:
 
   case 7:
 
-/* Line 1537 of yacc.c  */
-#line 235 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 232 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
 
-/* Line 1537 of yacc.c  */
-#line 237 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 234 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars));
     }
@@ -1920,15 +1915,15 @@ yyreduce:
 
   case 9:
 
-/* Line 1537 of yacc.c  */
-#line 240 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 237 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
 
-/* Line 1537 of yacc.c  */
-#line 242 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 239 "parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[(2) - (2)].chars));
@@ -1937,43 +1932,43 @@ yyreduce:
 
   case 11:
 
-/* Line 1537 of yacc.c  */
-#line 246 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 243 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
 
-/* Line 1537 of yacc.c  */
-#line 247 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 244 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
 
-/* Line 1537 of yacc.c  */
-#line 248 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 245 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
 
-/* Line 1537 of yacc.c  */
-#line 249 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 246 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
 
-/* Line 1537 of yacc.c  */
-#line 250 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 247 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
 
-/* Line 1537 of yacc.c  */
-#line 252 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 249 "parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1982,8 +1977,8 @@ yyreduce:
 
   case 17:
 
-/* Line 1537 of yacc.c  */
-#line 257 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 254 "parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)]));
@@ -1996,106 +1991,106 @@ yyreduce:
 
   case 18:
 
-/* Line 1537 of yacc.c  */
-#line 265 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 262 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
 
-/* Line 1537 of yacc.c  */
-#line 266 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 263 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
 
-/* Line 1537 of yacc.c  */
-#line 267 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 264 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
 
-/* Line 1537 of yacc.c  */
-#line 268 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 265 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
 
-/* Line 1537 of yacc.c  */
-#line 269 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 266 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
 
-/* Line 1537 of yacc.c  */
-#line 270 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 267 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
 
-/* Line 1537 of yacc.c  */
-#line 271 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 268 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
 
-/* Line 1537 of yacc.c  */
-#line 272 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 269 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
 
-/* Line 1537 of yacc.c  */
-#line 273 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 270 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
 
-/* Line 1537 of yacc.c  */
-#line 274 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 271 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
 
-/* Line 1537 of yacc.c  */
-#line 275 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 272 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 29:
 
-/* Line 1537 of yacc.c  */
-#line 276 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 273 "parse-gram.y"
     { push_parser = true; pull_parser = false; }
     break;
 
   case 30:
 
-/* Line 1537 of yacc.c  */
-#line 277 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 274 "parse-gram.y"
     { push_parser = true; pull_parser = true; }
     break;
 
   case 31:
 
-/* Line 1537 of yacc.c  */
-#line 278 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 275 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 32:
 
-/* Line 1537 of yacc.c  */
-#line 280 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 277 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
       if (strchr (skeleton_user, '/'))
@@ -2123,29 +2118,29 @@ yyreduce:
 
   case 33:
 
-/* Line 1537 of yacc.c  */
-#line 303 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 300 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 34:
 
-/* Line 1537 of yacc.c  */
-#line 304 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 301 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 35:
 
-/* Line 1537 of yacc.c  */
-#line 305 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 302 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 39:
 
-/* Line 1537 of yacc.c  */
-#line 313 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 310 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
     }
@@ -2153,8 +2148,8 @@ yyreduce:
 
   case 40:
 
-/* Line 1537 of yacc.c  */
-#line 317 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 314 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2165,8 +2160,8 @@ yyreduce:
 
   case 41:
 
-/* Line 1537 of yacc.c  */
-#line 324 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 321 "parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[(3) - (3)].list); list; list = list->next)
@@ -2177,8 +2172,8 @@ yyreduce:
 
   case 42:
 
-/* Line 1537 of yacc.c  */
-#line 331 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 328 "parse-gram.y"
     {
       default_prec = true;
     }
@@ -2186,8 +2181,8 @@ yyreduce:
 
   case 43:
 
-/* Line 1537 of yacc.c  */
-#line 335 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 332 "parse-gram.y"
     {
       default_prec = false;
     }
@@ -2195,8 +2190,8 @@ yyreduce:
 
   case 44:
 
-/* Line 1537 of yacc.c  */
-#line 339 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 336 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2207,8 +2202,8 @@ yyreduce:
 
   case 45:
 
-/* Line 1537 of yacc.c  */
-#line 346 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 343 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
       code_scanner_last_string_free ();
@@ -2217,22 +2212,22 @@ yyreduce:
 
   case 46:
 
-/* Line 1537 of yacc.c  */
-#line 360 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 357 "parse-gram.y"
     {}
     break;
 
   case 47:
 
-/* Line 1537 of yacc.c  */
-#line 361 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 358 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 48:
 
-/* Line 1537 of yacc.c  */
-#line 366 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 363 "parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2242,15 +2237,15 @@ yyreduce:
 
   case 49:
 
-/* Line 1537 of yacc.c  */
-#line 377 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 374 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 50:
 
-/* Line 1537 of yacc.c  */
-#line 378 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 375 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2259,15 +2254,15 @@ yyreduce:
 
   case 51:
 
-/* Line 1537 of yacc.c  */
-#line 382 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 379 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 52:
 
-/* Line 1537 of yacc.c  */
-#line 383 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 380 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2276,8 +2271,8 @@ yyreduce:
 
   case 53:
 
-/* Line 1537 of yacc.c  */
-#line 388 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 385 "parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2289,8 +2284,8 @@ yyreduce:
 
   case 54:
 
-/* Line 1537 of yacc.c  */
-#line 399 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 396 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2306,99 +2301,99 @@ yyreduce:
 
   case 55:
 
-/* Line 1537 of yacc.c  */
-#line 413 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 410 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 56:
 
-/* Line 1537 of yacc.c  */
-#line 414 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 411 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 57:
 
-/* Line 1537 of yacc.c  */
-#line 415 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 412 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 58:
 
-/* Line 1537 of yacc.c  */
-#line 419 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 416 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 59:
 
-/* Line 1537 of yacc.c  */
-#line 420 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 417 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 60:
 
-/* Line 1537 of yacc.c  */
-#line 426 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 423 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 61:
 
-/* Line 1537 of yacc.c  */
-#line 428 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 425 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 62:
 
-/* Line 1537 of yacc.c  */
-#line 432 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 429 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 63:
 
-/* Line 1537 of yacc.c  */
-#line 433 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 64:
 
-/* Line 1537 of yacc.c  */
-#line 437 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 434 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 65:
 
-/* Line 1537 of yacc.c  */
-#line 438 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 435 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 66:
 
-/* Line 1537 of yacc.c  */
-#line 439 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 436 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 67:
 
-/* Line 1537 of yacc.c  */
-#line 440 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 437 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 68:
 
-/* Line 1537 of yacc.c  */
-#line 446 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 443 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
        tag_seen = true;
@@ -2407,8 +2402,8 @@ yyreduce:
 
   case 69:
 
-/* Line 1537 of yacc.c  */
-#line 451 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 448 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
        symbol_type_set ((yyvsp[(1) - (1)].symbol), current_type, (yylsp[(1) - (1)]));
@@ -2417,8 +2412,8 @@ yyreduce:
 
   case 70:
 
-/* Line 1537 of yacc.c  */
-#line 456 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 453 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2428,8 +2423,8 @@ yyreduce:
 
   case 71:
 
-/* Line 1537 of yacc.c  */
-#line 462 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 459 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
       symbol_type_set ((yyvsp[(1) - (2)].symbol), current_type, (yylsp[(1) - (2)]));
@@ -2439,8 +2434,8 @@ yyreduce:
 
   case 72:
 
-/* Line 1537 of yacc.c  */
-#line 468 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 465 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
       symbol_type_set ((yyvsp[(1) - (3)].symbol), current_type, (yylsp[(1) - (3)]));
@@ -2451,8 +2446,8 @@ yyreduce:
 
   case 79:
 
-/* Line 1537 of yacc.c  */
-#line 498 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 495 "parse-gram.y"
     {
       yyerrok;
     }
@@ -2460,78 +2455,78 @@ yyreduce:
 
   case 80:
 
-/* Line 1537 of yacc.c  */
-#line 504 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 501 "parse-gram.y"
     { current_lhs = (yyvsp[(1) - (1)].symbol); current_lhs_location = (yylsp[(1) - (1)]); }
     break;
 
   case 82:
 
-/* Line 1537 of yacc.c  */
-#line 508 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 505 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 83:
 
-/* Line 1537 of yacc.c  */
-#line 509 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 506 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 85:
 
-/* Line 1537 of yacc.c  */
-#line 515 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 512 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 86:
 
-/* Line 1537 of yacc.c  */
-#line 517 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 514 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)])); }
     break;
 
   case 87:
 
-/* Line 1537 of yacc.c  */
-#line 519 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 516 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 88:
 
-/* Line 1537 of yacc.c  */
-#line 521 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 518 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 89:
 
-/* Line 1537 of yacc.c  */
-#line 523 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 520 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 90:
 
-/* Line 1537 of yacc.c  */
-#line 525 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 522 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
 
-/* Line 1537 of yacc.c  */
-#line 535 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 532 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 93:
 
-/* Line 1537 of yacc.c  */
-#line 541 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 538 "parse-gram.y"
     {
       (yyval.chars) = "";
     }
@@ -2539,8 +2534,8 @@ yyreduce:
 
   case 95:
 
-/* Line 1537 of yacc.c  */
-#line 554 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 551 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2553,15 +2548,15 @@ yyreduce:
 
   case 96:
 
-/* Line 1537 of yacc.c  */
-#line 574 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 571 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 97:
 
-/* Line 1537 of yacc.c  */
-#line 576 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 573 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2571,15 +2566,15 @@ yyreduce:
 
   case 98:
 
-/* Line 1537 of yacc.c  */
-#line 584 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 581 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 101:
 
-/* Line 1537 of yacc.c  */
-#line 596 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 593 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2588,8 +2583,8 @@ yyreduce:
 
   case 103:
 
-/* Line 1537 of yacc.c  */
-#line 605 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 602 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2602,8 +2597,8 @@ yyreduce:
 
 
 
-/* Line 1537 of yacc.c  */
-#line 2607 "parse-gram.c"
+/* Line 22 of yacc.c  */
+#line 2602 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2783,7 +2778,7 @@ yyabortlab:
   yyresult = 1;
   goto yyreturn;
 
-#ifndef yyoverflow
+#if !defined(yyoverflow) || YYERROR_VERBOSE
 /*-------------------------------------------------.
 | yyexhaustedlab -- memory exhaustion comes here.  |
 `-------------------------------------------------*/
@@ -2821,8 +2816,8 @@ yyreturn:
 
 
 
-/* Line 1537 of yacc.c  */
-#line 615 "parse-gram.y"
+/* Line 22 of yacc.c  */
+#line 612 "parse-gram.y"
 
 
 
