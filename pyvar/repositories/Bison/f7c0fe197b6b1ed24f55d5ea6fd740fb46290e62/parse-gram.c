@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.336-b5c21.  */
+/* A Bison parser, made by GNU Bison 2.4.343-83ea.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.336-b5c21"
+#define YYBISON_VERSION "2.4.343-83ea"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -104,10 +104,10 @@
 #include "getargs.h"
 #include "gram.h"
 #include "muscle-tab.h"
+#include "named-ref.h"
 #include "quotearg.h"
 #include "reader.h"
 #include "symlist.h"
-#include "named-ref.h"
 #include "scan-gram.h"
 #include "scan-code.h"
 
@@ -150,7 +150,7 @@ static int current_prec = 0;
 #define YYTYPE_UINT8 uint_fast8_t
 
 /* Line 191 of yacc.c  */
-#line 154 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 154 "../master/src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -312,7 +312,7 @@ typedef union YYSTYPE
 
 
 /* Line 216 of yacc.c  */
-#line 316 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 316 "../master/src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -336,7 +336,7 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 /* Line 266 of yacc.c  */
-#line 340 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 340 "../master/src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -623,8 +623,8 @@ static const yytype_uint16 yyrline[] =
      435,   440,   442,   447,   448,   452,   453,   454,   455,   460,
      465,   470,   476,   482,   493,   494,   503,   504,   510,   511,
      512,   519,   519,   524,   525,   526,   531,   533,   535,   537,
-     539,   541,   547,   549,   561,   562,   567,   568,   577,   597,
-     599,   608,   613,   614,   619,   626,   628
+     539,   541,   546,   548,   559,   560,   565,   566,   575,   595,
+     597,   606,   611,   612,   617,   624,   626
 };
 #endif
 
@@ -646,14 +646,15 @@ static const char *const yytname[] =
   "\"%token-table\"", "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"char\"",
   "\"epilogue\"", "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"",
   "\"|\"", "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"",
-  "\"[id]\"", "\"%union\"", "$accept", "input", "prologue_declarations",
-  "prologue_declaration", "grammar_declaration", "union_name",
-  "symbol_declaration", "$@1", "$@2", "precedence_declaration",
-  "precedence_declarator", "tag.opt", "symbols.prec", "symbol.prec",
-  "symbols.1", "generic_symlist", "generic_symlist_item", "symbol_def",
-  "symbol_defs.1", "grammar", "rules_or_grammar_declaration", "rules",
-  "$@3", "rhses.1", "rhs", "named_ref.opt", "variable", "content.opt",
-  "braceless", "id", "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
+  "\"[identifier]\"", "\"%union\"", "$accept", "input",
+  "prologue_declarations", "prologue_declaration", "grammar_declaration",
+  "union_name", "symbol_declaration", "$@1", "$@2",
+  "precedence_declaration", "precedence_declarator", "tag.opt",
+  "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
+  "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
+  "rules_or_grammar_declaration", "rules", "$@3", "rhses.1", "rhs",
+  "named_ref.opt", "variable", "content.opt", "braceless", "id",
+  "id_colon", "symbol", "string_as_id", "epilogue.opt", 0
 };
 #endif
 
@@ -987,7 +988,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 183 "parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
 /* Line 647 of yacc.c  */
-#line 991 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 992 "../master/src/parse-gram.c"
         break;
 
             case 4: // "integer"
@@ -996,7 +997,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 196 "parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 647 of yacc.c  */
-#line 1000 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1001 "../master/src/parse-gram.c"
         break;
 
             case 24: // "%<flag>"
@@ -1005,7 +1006,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 192 "parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1009 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1010 "../master/src/parse-gram.c"
         break;
 
             case 42: // "{...}"
@@ -1014,7 +1015,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 647 of yacc.c  */
-#line 1018 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1019 "../master/src/parse-gram.c"
         break;
 
             case 43: // "char"
@@ -1023,7 +1024,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 177 "parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 647 of yacc.c  */
-#line 1027 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1028 "../master/src/parse-gram.c"
         break;
 
             case 44: // "epilogue"
@@ -1032,7 +1033,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1036 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1037 "../master/src/parse-gram.c"
         break;
 
             case 46: // "identifier"
@@ -1041,7 +1042,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 190 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 647 of yacc.c  */
-#line 1045 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1046 "../master/src/parse-gram.c"
         break;
 
             case 47: // "identifier:"
@@ -1050,7 +1051,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 191 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1054 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1055 "../master/src/parse-gram.c"
         break;
 
             case 50: // "%{...%}"
@@ -1059,7 +1060,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1063 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1064 "../master/src/parse-gram.c"
         break;
 
             case 52: // "<tag>"
@@ -1068,7 +1069,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 193 "parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 647 of yacc.c  */
-#line 1072 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1073 "../master/src/parse-gram.c"
         break;
 
             case 83: // variable
@@ -1077,7 +1078,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 190 "parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 647 of yacc.c  */
-#line 1081 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1082 "../master/src/parse-gram.c"
         break;
 
             case 84: // content.opt
@@ -1086,7 +1087,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1090 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1091 "../master/src/parse-gram.c"
         break;
 
             case 85: // braceless
@@ -1095,7 +1096,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 185 "parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 647 of yacc.c  */
-#line 1099 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1100 "../master/src/parse-gram.c"
         break;
 
             case 86: // id
@@ -1104,7 +1105,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 199 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1108 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1109 "../master/src/parse-gram.c"
         break;
 
             case 87: // id_colon
@@ -1113,7 +1114,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 200 "parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1117 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1118 "../master/src/parse-gram.c"
         break;
 
             case 88: // symbol
@@ -1122,7 +1123,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 199 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1126 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1127 "../master/src/parse-gram.c"
         break;
 
             case 89: // string_as_id
@@ -1131,7 +1132,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 #line 199 "parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 647 of yacc.c  */
-#line 1135 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1136 "../master/src/parse-gram.c"
         break;
 
       default:
@@ -1653,7 +1654,7 @@ YYLTYPE yylloc;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 /* Line 1167 of yacc.c  */
-#line 1657 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1658 "../master/src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -1851,7 +1852,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1855 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1856 "../master/src/parse-gram.c"
     break;
 
   case 7:
@@ -1861,7 +1862,7 @@ yyreduce:
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
 /* Line 1380 of yacc.c  */
-#line 1865 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1866 "../master/src/parse-gram.c"
     break;
 
   case 8:
@@ -1872,7 +1873,7 @@ yyreduce:
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1380 of yacc.c  */
-#line 1876 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1877 "../master/src/parse-gram.c"
     break;
 
   case 9:
@@ -1880,7 +1881,7 @@ yyreduce:
 #line 241 "parse-gram.y"
     { defines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 1884 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1885 "../master/src/parse-gram.c"
     break;
 
   case 10:
@@ -1891,7 +1892,7 @@ yyreduce:
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
 /* Line 1380 of yacc.c  */
-#line 1895 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1896 "../master/src/parse-gram.c"
     break;
 
   case 11:
@@ -1902,7 +1903,7 @@ yyreduce:
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
 /* Line 1380 of yacc.c  */
-#line 1906 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1907 "../master/src/parse-gram.c"
     break;
 
   case 12:
@@ -1910,7 +1911,7 @@ yyreduce:
 #line 252 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1914 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1915 "../master/src/parse-gram.c"
     break;
 
   case 13:
@@ -1918,7 +1919,7 @@ yyreduce:
 #line 253 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1380 of yacc.c  */
-#line 1922 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1923 "../master/src/parse-gram.c"
     break;
 
   case 14:
@@ -1926,7 +1927,7 @@ yyreduce:
 #line 254 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1930 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1931 "../master/src/parse-gram.c"
     break;
 
   case 15:
@@ -1934,7 +1935,7 @@ yyreduce:
 #line 255 "parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1938 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1939 "../master/src/parse-gram.c"
     break;
 
   case 16:
@@ -1945,7 +1946,7 @@ yyreduce:
       glr_parser = true;
     }
 /* Line 1380 of yacc.c  */
-#line 1949 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1950 "../master/src/parse-gram.c"
     break;
 
   case 17:
@@ -1960,7 +1961,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 1964 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1965 "../master/src/parse-gram.c"
     break;
 
   case 18:
@@ -1968,7 +1969,7 @@ yyreduce:
 #line 270 "parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1380 of yacc.c  */
-#line 1972 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1973 "../master/src/parse-gram.c"
     break;
 
   case 19:
@@ -1976,7 +1977,7 @@ yyreduce:
 #line 271 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 1980 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1981 "../master/src/parse-gram.c"
     break;
 
   case 20:
@@ -1984,7 +1985,7 @@ yyreduce:
 #line 272 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1988 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1989 "../master/src/parse-gram.c"
     break;
 
   case 21:
@@ -1992,7 +1993,7 @@ yyreduce:
 #line 273 "parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 1996 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 1997 "../master/src/parse-gram.c"
     break;
 
   case 22:
@@ -2000,7 +2001,7 @@ yyreduce:
 #line 274 "parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2004 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2005 "../master/src/parse-gram.c"
     break;
 
   case 23:
@@ -2008,7 +2009,7 @@ yyreduce:
 #line 275 "parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1380 of yacc.c  */
-#line 2012 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2013 "../master/src/parse-gram.c"
     break;
 
   case 24:
@@ -2016,7 +2017,7 @@ yyreduce:
 #line 276 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2020 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2021 "../master/src/parse-gram.c"
     break;
 
   case 25:
@@ -2024,7 +2025,7 @@ yyreduce:
 #line 277 "parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1380 of yacc.c  */
-#line 2028 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2029 "../master/src/parse-gram.c"
     break;
 
   case 26:
@@ -2032,7 +2033,7 @@ yyreduce:
 #line 278 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2036 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2037 "../master/src/parse-gram.c"
     break;
 
   case 27:
@@ -2040,7 +2041,7 @@ yyreduce:
 #line 279 "parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2044 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2045 "../master/src/parse-gram.c"
     break;
 
   case 28:
@@ -2070,7 +2071,7 @@ yyreduce:
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
 /* Line 1380 of yacc.c  */
-#line 2074 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2075 "../master/src/parse-gram.c"
     break;
 
   case 29:
@@ -2078,7 +2079,7 @@ yyreduce:
 #line 304 "parse-gram.y"
     { token_table_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2082 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2083 "../master/src/parse-gram.c"
     break;
 
   case 30:
@@ -2086,7 +2087,7 @@ yyreduce:
 #line 305 "parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1380 of yacc.c  */
-#line 2090 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2091 "../master/src/parse-gram.c"
     break;
 
   case 31:
@@ -2094,7 +2095,7 @@ yyreduce:
 #line 306 "parse-gram.y"
     { yacc_flag = true; }
 /* Line 1380 of yacc.c  */
-#line 2098 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2099 "../master/src/parse-gram.c"
     break;
 
   case 35:
@@ -2104,7 +2105,7 @@ yyreduce:
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2108 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2109 "../master/src/parse-gram.c"
     break;
 
   case 36:
@@ -2117,7 +2118,7 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2121 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2122 "../master/src/parse-gram.c"
     break;
 
   case 37:
@@ -2130,7 +2131,7 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2134 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2135 "../master/src/parse-gram.c"
     break;
 
   case 38:
@@ -2140,7 +2141,7 @@ yyreduce:
       default_prec = true;
     }
 /* Line 1380 of yacc.c  */
-#line 2144 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2145 "../master/src/parse-gram.c"
     break;
 
   case 39:
@@ -2150,7 +2151,7 @@ yyreduce:
       default_prec = false;
     }
 /* Line 1380 of yacc.c  */
-#line 2154 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2155 "../master/src/parse-gram.c"
     break;
 
   case 40:
@@ -2163,7 +2164,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2167 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2168 "../master/src/parse-gram.c"
     break;
 
   case 41:
@@ -2174,7 +2175,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2178 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2179 "../master/src/parse-gram.c"
     break;
 
   case 42:
@@ -2182,7 +2183,7 @@ yyreduce:
 #line 361 "parse-gram.y"
     {}
 /* Line 1380 of yacc.c  */
-#line 2186 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2187 "../master/src/parse-gram.c"
     break;
 
   case 43:
@@ -2190,7 +2191,7 @@ yyreduce:
 #line 362 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2194 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2195 "../master/src/parse-gram.c"
     break;
 
   case 44:
@@ -2202,7 +2203,7 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2206 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2207 "../master/src/parse-gram.c"
     break;
 
   case 45:
@@ -2210,7 +2211,7 @@ yyreduce:
 #line 378 "parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1380 of yacc.c  */
-#line 2214 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2215 "../master/src/parse-gram.c"
     break;
 
   case 46:
@@ -2221,7 +2222,7 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2225 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2226 "../master/src/parse-gram.c"
     break;
 
   case 47:
@@ -2229,7 +2230,7 @@ yyreduce:
 #line 383 "parse-gram.y"
     { current_class = token_sym; }
 /* Line 1380 of yacc.c  */
-#line 2233 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2234 "../master/src/parse-gram.c"
     break;
 
   case 48:
@@ -2240,7 +2241,7 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2244 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2245 "../master/src/parse-gram.c"
     break;
 
   case 49:
@@ -2254,7 +2255,7 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
     }
 /* Line 1380 of yacc.c  */
-#line 2258 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2259 "../master/src/parse-gram.c"
     break;
 
   case 50:
@@ -2272,7 +2273,7 @@ yyreduce:
       current_type = NULL;
     }
 /* Line 1380 of yacc.c  */
-#line 2276 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2277 "../master/src/parse-gram.c"
     break;
 
   case 51:
@@ -2280,7 +2281,7 @@ yyreduce:
 #line 414 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2284 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2285 "../master/src/parse-gram.c"
     break;
 
   case 52:
@@ -2288,7 +2289,7 @@ yyreduce:
 #line 415 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2292 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2293 "../master/src/parse-gram.c"
     break;
 
   case 53:
@@ -2296,7 +2297,7 @@ yyreduce:
 #line 416 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2300 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2301 "../master/src/parse-gram.c"
     break;
 
   case 54:
@@ -2304,7 +2305,7 @@ yyreduce:
 #line 417 "parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1380 of yacc.c  */
-#line 2308 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2309 "../master/src/parse-gram.c"
     break;
 
   case 55:
@@ -2312,7 +2313,7 @@ yyreduce:
 #line 421 "parse-gram.y"
     { current_type = NULL; }
 /* Line 1380 of yacc.c  */
-#line 2316 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2317 "../master/src/parse-gram.c"
     break;
 
   case 56:
@@ -2320,7 +2321,7 @@ yyreduce:
 #line 422 "parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1380 of yacc.c  */
-#line 2324 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2325 "../master/src/parse-gram.c"
     break;
 
   case 57:
@@ -2328,7 +2329,7 @@ yyreduce:
 #line 428 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2332 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2333 "../master/src/parse-gram.c"
     break;
 
   case 58:
@@ -2336,7 +2337,7 @@ yyreduce:
 #line 430 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2340 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2341 "../master/src/parse-gram.c"
     break;
 
   case 59:
@@ -2344,7 +2345,7 @@ yyreduce:
 #line 434 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1380 of yacc.c  */
-#line 2348 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2349 "../master/src/parse-gram.c"
     break;
 
   case 60:
@@ -2352,7 +2353,7 @@ yyreduce:
 #line 435 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2356 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2357 "../master/src/parse-gram.c"
     break;
 
   case 61:
@@ -2360,7 +2361,7 @@ yyreduce:
 #line 441 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2364 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2365 "../master/src/parse-gram.c"
     break;
 
   case 62:
@@ -2368,7 +2369,7 @@ yyreduce:
 #line 443 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1380 of yacc.c  */
-#line 2372 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2373 "../master/src/parse-gram.c"
     break;
 
   case 63:
@@ -2376,7 +2377,7 @@ yyreduce:
 #line 447 "parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1380 of yacc.c  */
-#line 2380 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2381 "../master/src/parse-gram.c"
     break;
 
   case 64:
@@ -2384,7 +2385,7 @@ yyreduce:
 #line 448 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1380 of yacc.c  */
-#line 2388 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2389 "../master/src/parse-gram.c"
     break;
 
   case 65:
@@ -2392,7 +2393,7 @@ yyreduce:
 #line 452 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2396 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2397 "../master/src/parse-gram.c"
     break;
 
   case 66:
@@ -2400,7 +2401,7 @@ yyreduce:
 #line 453 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2404 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2405 "../master/src/parse-gram.c"
     break;
 
   case 67:
@@ -2408,7 +2409,7 @@ yyreduce:
 #line 454 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2412 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2413 "../master/src/parse-gram.c"
     break;
 
   case 68:
@@ -2416,7 +2417,7 @@ yyreduce:
 #line 455 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2420 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2421 "../master/src/parse-gram.c"
     break;
 
   case 69:
@@ -2427,7 +2428,7 @@ yyreduce:
        tag_seen = true;
      }
 /* Line 1380 of yacc.c  */
-#line 2431 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2432 "../master/src/parse-gram.c"
     break;
 
   case 70:
@@ -2438,7 +2439,7 @@ yyreduce:
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
      }
 /* Line 1380 of yacc.c  */
-#line 2442 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2443 "../master/src/parse-gram.c"
     break;
 
   case 71:
@@ -2450,7 +2451,7 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2454 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2455 "../master/src/parse-gram.c"
     break;
 
   case 72:
@@ -2462,7 +2463,7 @@ yyreduce:
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2466 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2467 "../master/src/parse-gram.c"
     break;
 
   case 73:
@@ -2475,7 +2476,7 @@ yyreduce:
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
 /* Line 1380 of yacc.c  */
-#line 2479 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2480 "../master/src/parse-gram.c"
     break;
 
   case 80:
@@ -2485,7 +2486,7 @@ yyreduce:
       yyerrok;
     }
 /* Line 1380 of yacc.c  */
-#line 2489 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2490 "../master/src/parse-gram.c"
     break;
 
   case 81:
@@ -2494,7 +2495,7 @@ yyreduce:
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
 /* Line 1380 of yacc.c  */
-#line 2498 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2499 "../master/src/parse-gram.c"
     break;
 
   case 83:
@@ -2502,7 +2503,7 @@ yyreduce:
 #line 524 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2506 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2507 "../master/src/parse-gram.c"
     break;
 
   case 84:
@@ -2510,7 +2511,7 @@ yyreduce:
 #line 525 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2514 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2515 "../master/src/parse-gram.c"
     break;
 
   case 86:
@@ -2519,7 +2520,7 @@ yyreduce:
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
 /* Line 1380 of yacc.c  */
-#line 2523 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2524 "../master/src/parse-gram.c"
     break;
 
   case 87:
@@ -2527,7 +2528,7 @@ yyreduce:
 #line 534 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1380 of yacc.c  */
-#line 2531 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2532 "../master/src/parse-gram.c"
     break;
 
   case 88:
@@ -2535,7 +2536,7 @@ yyreduce:
 #line 536 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1380 of yacc.c  */
-#line 2539 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2540 "../master/src/parse-gram.c"
     break;
 
   case 89:
@@ -2543,7 +2544,7 @@ yyreduce:
 #line 538 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2547 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2548 "../master/src/parse-gram.c"
     break;
 
   case 90:
@@ -2551,7 +2552,7 @@ yyreduce:
 #line 540 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2555 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2556 "../master/src/parse-gram.c"
     break;
 
   case 91:
@@ -2559,44 +2560,44 @@ yyreduce:
 #line 542 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2563 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2564 "../master/src/parse-gram.c"
     break;
 
   case 92:
 /* Line 1380 of yacc.c  */
-#line 547 "parse-gram.y"
+#line 546 "parse-gram.y"
     { (yyval.named_ref) = 0; }
 /* Line 1380 of yacc.c  */
-#line 2571 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2572 "../master/src/parse-gram.c"
     break;
 
   case 93:
 /* Line 1380 of yacc.c  */
-#line 550 "parse-gram.y"
+#line 548 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2579 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2580 "../master/src/parse-gram.c"
     break;
 
   case 95:
 /* Line 1380 of yacc.c  */
-#line 562 "parse-gram.y"
+#line 560 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1380 of yacc.c  */
-#line 2587 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2588 "../master/src/parse-gram.c"
     break;
 
   case 96:
 /* Line 1380 of yacc.c  */
-#line 567 "parse-gram.y"
+#line 565 "parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1380 of yacc.c  */
-#line 2595 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2596 "../master/src/parse-gram.c"
     break;
 
   case 98:
 /* Line 1380 of yacc.c  */
-#line 578 "parse-gram.y"
+#line 576 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2606,51 +2607,51 @@ yyreduce:
       (yyval.chars) = plain_code.code;
     }
 /* Line 1380 of yacc.c  */
-#line 2610 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2611 "../master/src/parse-gram.c"
     break;
 
   case 99:
 /* Line 1380 of yacc.c  */
-#line 598 "parse-gram.y"
+#line 596 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2618 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2619 "../master/src/parse-gram.c"
     break;
 
   case 100:
 /* Line 1380 of yacc.c  */
-#line 600 "parse-gram.y"
+#line 598 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
 /* Line 1380 of yacc.c  */
-#line 2630 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2631 "../master/src/parse-gram.c"
     break;
 
   case 101:
 /* Line 1380 of yacc.c  */
-#line 608 "parse-gram.y"
+#line 606 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1380 of yacc.c  */
-#line 2638 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2639 "../master/src/parse-gram.c"
     break;
 
   case 104:
 /* Line 1380 of yacc.c  */
-#line 620 "parse-gram.y"
+#line 618 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
 /* Line 1380 of yacc.c  */
-#line 2649 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2650 "../master/src/parse-gram.c"
     break;
 
   case 106:
 /* Line 1380 of yacc.c  */
-#line 629 "parse-gram.y"
+#line 627 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2660,12 +2661,12 @@ yyreduce:
       code_scanner_last_string_free ();
     }
 /* Line 1380 of yacc.c  */
-#line 2664 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2665 "../master/src/parse-gram.c"
     break;
 
 
 /* Line 1380 of yacc.c  */
-#line 2669 "/Users/akim/src/kernel/bison/src/parse-gram.c"
+#line 2670 "../master/src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2882,7 +2883,7 @@ yyreturn:
 }
 
 /* Line 1599 of yacc.c  */
-#line 639 "parse-gram.y"
+#line 637 "parse-gram.y"
 
 
 
