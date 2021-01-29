@@ -1,9 +1,8 @@
-/* A Bison parser, made by GNU Bison 3.0.  */
+/* A Bison parser, made by GNU Bison 3.0.2.13-975bb-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
-   Copyright (C) 1984, 1989-1990, 2000-2014 Free Software Foundation,
-   Inc.
+   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -45,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.0"
+#define YYBISON_VERSION "3.0.2.13-975bb-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -393,11 +392,30 @@ typedef short int yytype_int16;
 # endif
 #endif
 
-#ifndef __attribute__
-/* This feature is available in gcc versions 2.5 and later.  */
-# if (! defined __GNUC__ || __GNUC__ < 2 \
-      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
-#  define __attribute__(Spec) /* empty */
+#ifndef YY_ATTRIBUTE
+# if (defined __GNUC__                                               \
+      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
+     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
+#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
+# else
+#  define YY_ATTRIBUTE(Spec) /* empty */
+# endif
+#endif
+
+#ifndef YY_ATTRIBUTE_PURE
+# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
+#endif
+
+#ifndef YY_ATTRIBUTE_UNUSED
+# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
+#endif
+
+#if !defined _Noreturn \
+     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
+# if defined _MSC_VER && 1200 <= _MSC_VER
+#  define _Noreturn __declspec (noreturn)
+# else
+#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
 # endif
 #endif
 
@@ -916,7 +934,7 @@ do {                                            \
 
 /* Print *YYLOCP on YYO.  Private, do not rely on its existence. */
 
-__attribute__((__unused__))
+YY_ATTRIBUTE_UNUSED
 static unsigned
 yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
 {
@@ -984,73 +1002,73 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
           case 3: /* "string"  */
 #line 188 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).code)), yyo); }
-#line 987 "src/parse-gram.c" /* yacc.c:684  */
+#line 1006 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 23: /* "%<flag>"  */
 #line 196 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 993 "src/parse-gram.c" /* yacc.c:684  */
+#line 1012 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 39: /* "{...}"  */
 #line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 999 "src/parse-gram.c" /* yacc.c:684  */
+#line 1018 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 40: /* "%?{...}"  */
 #line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1005 "src/parse-gram.c" /* yacc.c:684  */
+#line 1024 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 41: /* "[identifier]"  */
 #line 194 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 1011 "src/parse-gram.c" /* yacc.c:684  */
+#line 1030 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 42: /* "char"  */
 #line 184 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 1017 "src/parse-gram.c" /* yacc.c:684  */
+#line 1036 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 43: /* "epilogue"  */
 #line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1023 "src/parse-gram.c" /* yacc.c:684  */
+#line 1042 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 45: /* "identifier"  */
 #line 193 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1029 "src/parse-gram.c" /* yacc.c:684  */
+#line 1048 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 46: /* "identifier:"  */
 #line 195 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1035 "src/parse-gram.c" /* yacc.c:684  */
+#line 1054 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 49: /* "%{...%}"  */
 #line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1041 "src/parse-gram.c" /* yacc.c:684  */
+#line 1060 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 51: /* "<tag>"  */
 #line 197 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1047 "src/parse-gram.c" /* yacc.c:684  */
+#line 1066 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 54: /* "integer"  */
 #line 201 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1053 "src/parse-gram.c" /* yacc.c:684  */
+#line 1072 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 55: /* "%param"  */
@@ -1067,31 +1085,31 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1070 "src/parse-gram.c" /* yacc.c:684  */
+#line 1089 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 65: /* code_props_type  */
 #line 410 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1076 "src/parse-gram.c" /* yacc.c:684  */
+#line 1095 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 74: /* symbol.prec  */
 #line 205 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1082 "src/parse-gram.c" /* yacc.c:684  */
+#line 1101 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 78: /* tag  */
 #line 197 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1088 "src/parse-gram.c" /* yacc.c:684  */
+#line 1107 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 88: /* variable  */
 #line 193 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1094 "src/parse-gram.c" /* yacc.c:684  */
+#line 1113 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 89: /* value  */
@@ -1104,31 +1122,31 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1107 "src/parse-gram.c" /* yacc.c:684  */
+#line 1126 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 90: /* id  */
 #line 205 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1113 "src/parse-gram.c" /* yacc.c:684  */
+#line 1132 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 91: /* id_colon  */
 #line 206 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1119 "src/parse-gram.c" /* yacc.c:684  */
+#line 1138 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 92: /* symbol  */
 #line 205 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1125 "src/parse-gram.c" /* yacc.c:684  */
+#line 1144 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 93: /* string_as_id  */
 #line 205 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1131 "src/parse-gram.c" /* yacc.c:684  */
+#line 1150 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
 
@@ -1830,7 +1848,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1833 "src/parse-gram.c" /* yacc.c:1429  */
+#line 1852 "src/parse-gram.c" /* yacc.c:1429  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2030,7 +2048,7 @@ yyreduce:
                         translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2033 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2052 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 7:
@@ -2038,7 +2056,7 @@ yyreduce:
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2041 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2060 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 8:
@@ -2047,13 +2065,13 @@ yyreduce:
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2050 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2069 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 9:
 #line 294 "src/parse-gram.y" /* yacc.c:1646  */
     { defines_flag = true; }
-#line 2056 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2075 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 10:
@@ -2062,7 +2080,7 @@ yyreduce:
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].code));
     }
-#line 2065 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2084 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 11:
@@ -2072,25 +2090,25 @@ yyreduce:
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2075 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2094 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 12:
 #line 306 "src/parse-gram.y" /* yacc.c:1646  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2081 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2100 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 13:
 #line 307 "src/parse-gram.y" /* yacc.c:1646  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2087 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2106 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 14:
 #line 308 "src/parse-gram.y" /* yacc.c:1646  */
     { spec_file_prefix = (yyvsp[0].code); }
-#line 2093 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2112 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 15:
@@ -2099,7 +2117,7 @@ yyreduce:
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2102 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2121 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 16:
@@ -2108,55 +2126,55 @@ yyreduce:
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].code), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2111 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2130 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 17:
 #line 319 "src/parse-gram.y" /* yacc.c:1646  */
     { language_argmatch ((yyvsp[0].code), grammar_prio, (yylsp[-1])); }
-#line 2117 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2136 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 18:
 #line 320 "src/parse-gram.y" /* yacc.c:1646  */
     { spec_name_prefix = (yyvsp[0].code); }
-#line 2123 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2142 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 19:
 #line 321 "src/parse-gram.y" /* yacc.c:1646  */
     { no_lines_flag = true; }
-#line 2129 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2148 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 20:
 #line 322 "src/parse-gram.y" /* yacc.c:1646  */
     { nondeterministic_parser = true; }
-#line 2135 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2154 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 21:
 #line 323 "src/parse-gram.y" /* yacc.c:1646  */
     { spec_outfile = (yyvsp[0].code); }
-#line 2141 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2160 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 22:
 #line 324 "src/parse-gram.y" /* yacc.c:1646  */
     { current_param = (yyvsp[0].param); }
-#line 2147 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2166 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 23:
 #line 324 "src/parse-gram.y" /* yacc.c:1646  */
     { current_param = param_none; }
-#line 2153 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2172 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 24:
 #line 325 "src/parse-gram.y" /* yacc.c:1646  */
     { version_check (&(yylsp[0]), (yyvsp[0].code)); }
-#line 2159 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2178 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 25:
@@ -2184,37 +2202,37 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2187 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2206 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 26:
 #line 350 "src/parse-gram.y" /* yacc.c:1646  */
     { token_table_flag = true; }
-#line 2193 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2212 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 27:
 #line 351 "src/parse-gram.y" /* yacc.c:1646  */
     { report_flag |= report_states; }
-#line 2199 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2218 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 28:
 #line 352 "src/parse-gram.y" /* yacc.c:1646  */
     { yacc_flag = true; }
-#line 2205 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2224 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 30:
 #line 357 "src/parse-gram.y" /* yacc.c:1646  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2211 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2230 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 31:
 #line 358 "src/parse-gram.y" /* yacc.c:1646  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2217 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2236 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 34:
@@ -2222,7 +2240,7 @@ yyreduce:
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2225 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2244 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 35:
@@ -2238,7 +2256,7 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2241 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2260 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 36:
@@ -2246,7 +2264,7 @@ yyreduce:
     {
       default_prec = true;
     }
-#line 2249 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2268 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 37:
@@ -2254,7 +2272,7 @@ yyreduce:
     {
       default_prec = false;
     }
-#line 2257 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2276 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 38:
@@ -2266,7 +2284,7 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2269 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2288 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 39:
@@ -2275,31 +2293,31 @@ yyreduce:
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2278 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2297 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 40:
 #line 412 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.code_type) = destructor; }
-#line 2284 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2303 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 41:
 #line 413 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.code_type) = printer; }
-#line 2290 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2309 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 42:
 #line 423 "src/parse-gram.y" /* yacc.c:1646  */
     {}
-#line 2296 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2315 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 43:
 #line 424 "src/parse-gram.y" /* yacc.c:1646  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2302 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2321 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 44:
@@ -2309,13 +2327,13 @@ yyreduce:
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2312 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2331 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 45:
 #line 440 "src/parse-gram.y" /* yacc.c:1646  */
     { current_class = nterm_sym; }
-#line 2318 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2337 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 46:
@@ -2324,13 +2342,13 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2327 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2346 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 47:
 #line 445 "src/parse-gram.y" /* yacc.c:1646  */
     { current_class = token_sym; }
-#line 2333 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2352 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 48:
@@ -2339,7 +2357,7 @@ yyreduce:
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2342 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2361 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 49:
@@ -2351,7 +2369,7 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2354 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2373 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 50:
@@ -2367,55 +2385,55 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2370 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2389 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 51:
 #line 476 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.assoc) = left_assoc; }
-#line 2376 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2395 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 52:
 #line 477 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.assoc) = right_assoc; }
-#line 2382 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2401 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 53:
 #line 478 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.assoc) = non_assoc; }
-#line 2388 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2407 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 54:
 #line 479 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2394 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2413 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 55:
 #line 483 "src/parse-gram.y" /* yacc.c:1646  */
     { current_type = NULL; }
-#line 2400 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2419 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 56:
 #line 484 "src/parse-gram.y" /* yacc.c:1646  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2406 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2425 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 57:
 #line 490 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2412 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2431 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 58:
 #line 492 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2418 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2437 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 59:
@@ -2424,7 +2442,7 @@ yyreduce:
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2427 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2446 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 60:
@@ -2434,55 +2452,55 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2437 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2456 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 61:
 #line 512 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2443 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2462 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 62:
 #line 514 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2449 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2468 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 63:
 #line 518 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2455 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2474 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 64:
 #line 519 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2461 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2480 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 65:
 #line 523 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2467 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2486 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 66:
 #line 524 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2473 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2492 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 68:
 #line 529 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2479 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2498 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 69:
 #line 530 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2485 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2504 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 70:
@@ -2491,7 +2509,7 @@ yyreduce:
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2494 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2513 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 71:
@@ -2500,7 +2518,7 @@ yyreduce:
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2503 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2522 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 72:
@@ -2510,7 +2528,7 @@ yyreduce:
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2513 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2532 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 73:
@@ -2520,7 +2538,7 @@ yyreduce:
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2523 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2542 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 74:
@@ -2531,7 +2549,7 @@ yyreduce:
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2534 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2553 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 81:
@@ -2539,13 +2557,13 @@ yyreduce:
     {
       yyerrok;
     }
-#line 2542 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2561 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 82:
 #line 594 "src/parse-gram.y" /* yacc.c:1646  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2548 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2567 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 83:
@@ -2554,116 +2572,116 @@ yyreduce:
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2557 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2576 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 84:
 #line 602 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2563 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2582 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 85:
 #line 603 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2569 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2588 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 87:
 #line 610 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2576 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2595 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 88:
 #line 613 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2582 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2601 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 89:
 #line 615 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2588 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2607 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 90:
 #line 617 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2594 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2613 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 91:
 #line 619 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2600 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2619 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 92:
 #line 621 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2606 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2625 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 93:
 #line 623 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2612 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2631 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 94:
 #line 625 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2618 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2637 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 95:
 #line 629 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.named_ref) = 0; }
-#line 2624 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2643 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 96:
 #line 630 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2630 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2649 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 98:
 #line 641 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].code)); }
-#line 2636 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2655 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 99:
 #line 666 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2642 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2661 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 100:
 #line 667 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2648 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2667 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 101:
 #line 668 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].code); }
-#line 2654 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2673 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 102:
 #line 669 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].code)); }
-#line 2660 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2679 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 103:
 #line 682 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2666 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2685 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 104:
@@ -2673,13 +2691,13 @@ yyreduce:
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2676 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2695 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 105:
 #line 692 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2682 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2701 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 108:
@@ -2688,7 +2706,7 @@ yyreduce:
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].code)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2691 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2710 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 110:
@@ -2697,11 +2715,11 @@ yyreduce:
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2700 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2719 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
 
-#line 2704 "src/parse-gram.c" /* yacc.c:1646  */
+#line 2723 "src/parse-gram.c" /* yacc.c:1646  */
         default: break;
       }
     if (yychar_backup != yychar)
