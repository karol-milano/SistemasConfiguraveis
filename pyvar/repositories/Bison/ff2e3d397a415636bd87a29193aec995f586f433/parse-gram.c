@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.7.1127-02879-dirty.  */
+/* A Bison parser, made by GNU Bison 2.7.1164-a174b-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.7.1127-02879-dirty"
+#define YYBISON_VERSION "2.7.1164-a174b-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -168,11 +168,10 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-
 #line 649 "src/parse-gram.y" /* yacc.c:372  */
 #include "muscle-tab.h"
 
-#line 176 "src/parse-gram.c" /* yacc.c:372  */
+#line 175 "src/parse-gram.c" /* yacc.c:372  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -249,7 +248,6 @@ unsigned char character;
 
   char *code;
   char const *chars;
-
 #line 188 "src/parse-gram.y" /* yacc.c:372  */
 uniqstr uniqstr;
 #line 196 "src/parse-gram.y" /* yacc.c:372  */
@@ -274,8 +272,7 @@ code_props_type code_type;
     muscle_kind kind;
   } value;
 
-
-#line 279 "src/parse-gram.c" /* yacc.c:372  */
+#line 276 "src/parse-gram.c" /* yacc.c:372  */
 };
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
@@ -303,7 +300,7 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 307 "src/parse-gram.c" /* yacc.c:375  */
+#line 304 "src/parse-gram.c" /* yacc.c:375  */
 /* Unqualified %code blocks.  */
 #line 53 "src/parse-gram.y" /* yacc.c:376  */
 
@@ -336,7 +333,6 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-
 #line 228 "src/parse-gram.y" /* yacc.c:376  */
 
   /** Add a lex-param and/or a parse-param.
@@ -348,8 +344,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-
-#line 353 "src/parse-gram.c" /* yacc.c:376  */
+#line 348 "src/parse-gram.c" /* yacc.c:376  */
 
 #ifdef short
 # undef short
@@ -406,13 +401,22 @@ typedef short int yytype_int16;
 # endif
 #endif
 
+#ifndef __attribute__
+/* This feature is available in gcc versions 2.5 and later.  */
+# if (! defined __GNUC__ || __GNUC__ < 2 \
+      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
+#  define __attribute__(Spec) /* empty */
+# endif
+#endif
+
 /* Suppress unused-variable warnings by "using" E.  */
-#ifdef __GNUC__
+#if ! defined lint || defined __GNUC__
 # define YYUSE(E) ((void) (E))
 #else
 # define YYUSE(E) /* empty */
 #endif
 
+
 #if 1
 
 /* The parser invokes alloca or malloc; define the necessary symbols.  */
@@ -966,74 +970,74 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
 # endif
   switch (yytype)
     {
-    case 3: /* "string"  */
-#line 183 "src/parse-gram.y" /* yacc.c:706  */
+          case 3: /* "string"  */
+#line 183 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-#line 973 "src/parse-gram.c" /* yacc.c:706  */
+#line 977 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 23: /* "%<flag>"  */
-#line 193 "src/parse-gram.y" /* yacc.c:706  */
+#line 193 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 979 "src/parse-gram.c" /* yacc.c:706  */
+#line 983 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 39: /* "{...}"  */
-#line 185 "src/parse-gram.y" /* yacc.c:706  */
+#line 185 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 985 "src/parse-gram.c" /* yacc.c:706  */
+#line 989 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 41: /* "[identifier]"  */
-#line 191 "src/parse-gram.y" /* yacc.c:706  */
+#line 191 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 991 "src/parse-gram.c" /* yacc.c:706  */
+#line 995 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 42: /* "char"  */
-#line 172 "src/parse-gram.y" /* yacc.c:706  */
+#line 172 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 997 "src/parse-gram.c" /* yacc.c:706  */
+#line 1001 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 43: /* "epilogue"  */
-#line 185 "src/parse-gram.y" /* yacc.c:706  */
+#line 185 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1003 "src/parse-gram.c" /* yacc.c:706  */
+#line 1007 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 45: /* "identifier"  */
-#line 190 "src/parse-gram.y" /* yacc.c:706  */
+#line 190 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1009 "src/parse-gram.c" /* yacc.c:706  */
+#line 1013 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 46: /* "identifier:"  */
-#line 192 "src/parse-gram.y" /* yacc.c:706  */
+#line 192 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1015 "src/parse-gram.c" /* yacc.c:706  */
+#line 1019 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 49: /* "%{...%}"  */
-#line 185 "src/parse-gram.y" /* yacc.c:706  */
+#line 185 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1021 "src/parse-gram.c" /* yacc.c:706  */
+#line 1025 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 51: /* "<tag>"  */
-#line 194 "src/parse-gram.y" /* yacc.c:706  */
+#line 194 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1027 "src/parse-gram.c" /* yacc.c:706  */
+#line 1031 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 54: /* "integer"  */
-#line 198 "src/parse-gram.y" /* yacc.c:706  */
+#line 198 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1033 "src/parse-gram.c" /* yacc.c:706  */
+#line 1037 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 55: /* "%param"  */
-#line 241 "src/parse-gram.y" /* yacc.c:706  */
+#line 241 "src/parse-gram.y" /* yacc.c:701  */
       {
   switch (((*yyvaluep).param))
     {
@@ -1046,35 +1050,35 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1050 "src/parse-gram.c" /* yacc.c:706  */
+#line 1054 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 65: /* code_props_type  */
-#line 414 "src/parse-gram.y" /* yacc.c:706  */
+#line 414 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1056 "src/parse-gram.c" /* yacc.c:706  */
+#line 1060 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 74: /* symbol.prec  */
-#line 202 "src/parse-gram.y" /* yacc.c:706  */
+#line 202 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1062 "src/parse-gram.c" /* yacc.c:706  */
+#line 1066 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 78: /* tag  */
-#line 194 "src/parse-gram.y" /* yacc.c:706  */
+#line 194 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1068 "src/parse-gram.c" /* yacc.c:706  */
+#line 1072 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 88: /* variable  */
-#line 190 "src/parse-gram.y" /* yacc.c:706  */
+#line 190 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1074 "src/parse-gram.c" /* yacc.c:706  */
+#line 1078 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 89: /* value  */
-#line 660 "src/parse-gram.y" /* yacc.c:706  */
+#line 660 "src/parse-gram.y" /* yacc.c:701  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1083,39 +1087,40 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1087 "src/parse-gram.c" /* yacc.c:706  */
+#line 1091 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 90: /* braceless  */
-#line 185 "src/parse-gram.y" /* yacc.c:706  */
+#line 185 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1093 "src/parse-gram.c" /* yacc.c:706  */
+#line 1097 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 91: /* id  */
-#line 202 "src/parse-gram.y" /* yacc.c:706  */
+#line 202 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1099 "src/parse-gram.c" /* yacc.c:706  */
+#line 1103 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 92: /* id_colon  */
-#line 203 "src/parse-gram.y" /* yacc.c:706  */
+#line 203 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1105 "src/parse-gram.c" /* yacc.c:706  */
+#line 1109 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 93: /* symbol  */
-#line 202 "src/parse-gram.y" /* yacc.c:706  */
+#line 202 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1111 "src/parse-gram.c" /* yacc.c:706  */
+#line 1115 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 94: /* string_as_id  */
-#line 202 "src/parse-gram.y" /* yacc.c:706  */
+#line 202 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1117 "src/parse-gram.c" /* yacc.c:706  */
+#line 1121 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
+
       default:
         break;
     }
@@ -1693,11 +1698,7 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
     yymsg = "Deleting";
   YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);
 
-  switch (yytype)
-    {
-      default:
-        break;
-    }
+  YYUSE (yytype);
 }
 
 
@@ -1828,14 +1829,15 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 96 "src/parse-gram.y" /* yacc.c:1451  */
+#line 96 "src/parse-gram.y" /* yacc.c:1446  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-#line 1839 "src/parse-gram.c" /* yacc.c:1451  */
+
+#line 1841 "src/parse-gram.c" /* yacc.c:1446  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2029,7 +2031,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 277 "src/parse-gram.y" /* yacc.c:1668  */
+#line 277 "src/parse-gram.y" /* yacc.c:1663  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2039,80 +2041,80 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2043 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2045 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 7:
-#line 287 "src/parse-gram.y" /* yacc.c:1668  */
+#line 287 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2051 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2053 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 8:
-#line 291 "src/parse-gram.y" /* yacc.c:1668  */
+#line 291 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2060 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2062 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 9:
-#line 295 "src/parse-gram.y" /* yacc.c:1668  */
+#line 295 "src/parse-gram.y" /* yacc.c:1663  */
     { defines_flag = true; }
-#line 2066 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2068 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 10:
-#line 297 "src/parse-gram.y" /* yacc.c:1668  */
+#line 297 "src/parse-gram.y" /* yacc.c:1663  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-#line 2075 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2077 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 11:
-#line 302 "src/parse-gram.y" /* yacc.c:1668  */
+#line 302 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2085 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2087 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 12:
-#line 307 "src/parse-gram.y" /* yacc.c:1668  */
+#line 307 "src/parse-gram.y" /* yacc.c:1663  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2091 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2093 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 13:
-#line 308 "src/parse-gram.y" /* yacc.c:1668  */
+#line 308 "src/parse-gram.y" /* yacc.c:1663  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2097 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2099 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 14:
-#line 309 "src/parse-gram.y" /* yacc.c:1668  */
+#line 309 "src/parse-gram.y" /* yacc.c:1663  */
     { spec_file_prefix = (yyvsp[0].chars); }
-#line 2103 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2105 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 15:
-#line 311 "src/parse-gram.y" /* yacc.c:1668  */
+#line 311 "src/parse-gram.y" /* yacc.c:1663  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2112 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2114 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 16:
-#line 316 "src/parse-gram.y" /* yacc.c:1668  */
+#line 316 "src/parse-gram.y" /* yacc.c:1663  */
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2121,59 +2123,59 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2125 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2127 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 17:
-#line 324 "src/parse-gram.y" /* yacc.c:1668  */
+#line 324 "src/parse-gram.y" /* yacc.c:1663  */
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-#line 2131 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2133 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 18:
-#line 325 "src/parse-gram.y" /* yacc.c:1668  */
+#line 325 "src/parse-gram.y" /* yacc.c:1663  */
     { spec_name_prefix = (yyvsp[0].chars); }
-#line 2137 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2139 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 19:
-#line 326 "src/parse-gram.y" /* yacc.c:1668  */
+#line 326 "src/parse-gram.y" /* yacc.c:1663  */
     { no_lines_flag = true; }
-#line 2143 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2145 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 20:
-#line 327 "src/parse-gram.y" /* yacc.c:1668  */
+#line 327 "src/parse-gram.y" /* yacc.c:1663  */
     { nondeterministic_parser = true; }
-#line 2149 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2151 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 21:
-#line 328 "src/parse-gram.y" /* yacc.c:1668  */
+#line 328 "src/parse-gram.y" /* yacc.c:1663  */
     { spec_outfile = (yyvsp[0].chars); }
-#line 2155 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2157 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 22:
-#line 329 "src/parse-gram.y" /* yacc.c:1668  */
+#line 329 "src/parse-gram.y" /* yacc.c:1663  */
     { current_param = (yyvsp[0].param); }
-#line 2161 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2163 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 23:
-#line 329 "src/parse-gram.y" /* yacc.c:1668  */
+#line 329 "src/parse-gram.y" /* yacc.c:1663  */
     { current_param = param_none; }
-#line 2167 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2169 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 24:
-#line 330 "src/parse-gram.y" /* yacc.c:1668  */
+#line 330 "src/parse-gram.y" /* yacc.c:1663  */
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-#line 2173 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2175 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 25:
-#line 332 "src/parse-gram.y" /* yacc.c:1668  */
+#line 332 "src/parse-gram.y" /* yacc.c:1663  */
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2197,49 +2199,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2201 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2203 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 26:
-#line 355 "src/parse-gram.y" /* yacc.c:1668  */
+#line 355 "src/parse-gram.y" /* yacc.c:1663  */
     { token_table_flag = true; }
-#line 2207 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2209 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 27:
-#line 356 "src/parse-gram.y" /* yacc.c:1668  */
+#line 356 "src/parse-gram.y" /* yacc.c:1663  */
     { report_flag |= report_states; }
-#line 2213 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2215 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 28:
-#line 357 "src/parse-gram.y" /* yacc.c:1668  */
+#line 357 "src/parse-gram.y" /* yacc.c:1663  */
     { yacc_flag = true; }
-#line 2219 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2221 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 30:
-#line 362 "src/parse-gram.y" /* yacc.c:1668  */
+#line 362 "src/parse-gram.y" /* yacc.c:1663  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2225 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2227 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 31:
-#line 363 "src/parse-gram.y" /* yacc.c:1668  */
+#line 363 "src/parse-gram.y" /* yacc.c:1663  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2231 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2233 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 34:
-#line 375 "src/parse-gram.y" /* yacc.c:1668  */
+#line 375 "src/parse-gram.y" /* yacc.c:1663  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2239 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2241 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 35:
-#line 379 "src/parse-gram.y" /* yacc.c:1668  */
+#line 379 "src/parse-gram.y" /* yacc.c:1663  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2251,111 +2253,111 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2255 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2257 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 36:
-#line 391 "src/parse-gram.y" /* yacc.c:1668  */
+#line 391 "src/parse-gram.y" /* yacc.c:1663  */
     {
       default_prec = true;
     }
-#line 2263 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2265 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 37:
-#line 395 "src/parse-gram.y" /* yacc.c:1668  */
+#line 395 "src/parse-gram.y" /* yacc.c:1663  */
     {
       default_prec = false;
     }
-#line 2271 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2273 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 38:
-#line 399 "src/parse-gram.y" /* yacc.c:1668  */
+#line 399 "src/parse-gram.y" /* yacc.c:1663  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2282 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2284 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 39:
-#line 406 "src/parse-gram.y" /* yacc.c:1668  */
+#line 406 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2291 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2293 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 40:
-#line 416 "src/parse-gram.y" /* yacc.c:1668  */
+#line 416 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.code_type) = destructor; }
-#line 2297 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2299 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 41:
-#line 417 "src/parse-gram.y" /* yacc.c:1668  */
+#line 417 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.code_type) = printer; }
-#line 2303 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2305 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 42:
-#line 427 "src/parse-gram.y" /* yacc.c:1668  */
+#line 427 "src/parse-gram.y" /* yacc.c:1663  */
     {}
-#line 2309 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2311 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 43:
-#line 428 "src/parse-gram.y" /* yacc.c:1668  */
+#line 428 "src/parse-gram.y" /* yacc.c:1663  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2315 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2317 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 44:
-#line 433 "src/parse-gram.y" /* yacc.c:1668  */
+#line 433 "src/parse-gram.y" /* yacc.c:1663  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2325 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2327 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 45:
-#line 444 "src/parse-gram.y" /* yacc.c:1668  */
+#line 444 "src/parse-gram.y" /* yacc.c:1663  */
     { current_class = nterm_sym; }
-#line 2331 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2333 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 46:
-#line 445 "src/parse-gram.y" /* yacc.c:1668  */
+#line 445 "src/parse-gram.y" /* yacc.c:1663  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2340 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2342 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 47:
-#line 449 "src/parse-gram.y" /* yacc.c:1668  */
+#line 449 "src/parse-gram.y" /* yacc.c:1663  */
     { current_class = token_sym; }
-#line 2346 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2348 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 48:
-#line 450 "src/parse-gram.y" /* yacc.c:1668  */
+#line 450 "src/parse-gram.y" /* yacc.c:1663  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2355 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2357 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 49:
-#line 455 "src/parse-gram.y" /* yacc.c:1668  */
+#line 455 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_list *list;
       tag_seen = true;
@@ -2363,11 +2365,11 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2367 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2369 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 50:
-#line 466 "src/parse-gram.y" /* yacc.c:1668  */
+#line 466 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_list *list;
       ++current_prec;
@@ -2379,301 +2381,301 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2383 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2385 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 51:
-#line 480 "src/parse-gram.y" /* yacc.c:1668  */
+#line 480 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = left_assoc; }
-#line 2389 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2391 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 52:
-#line 481 "src/parse-gram.y" /* yacc.c:1668  */
+#line 481 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = right_assoc; }
-#line 2395 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2397 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 53:
-#line 482 "src/parse-gram.y" /* yacc.c:1668  */
+#line 482 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = non_assoc; }
-#line 2401 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2403 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 54:
-#line 483 "src/parse-gram.y" /* yacc.c:1668  */
+#line 483 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2407 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2409 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 55:
-#line 487 "src/parse-gram.y" /* yacc.c:1668  */
+#line 487 "src/parse-gram.y" /* yacc.c:1663  */
     { current_type = NULL; }
-#line 2413 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2415 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 56:
-#line 488 "src/parse-gram.y" /* yacc.c:1668  */
+#line 488 "src/parse-gram.y" /* yacc.c:1663  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2419 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2421 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 57:
-#line 494 "src/parse-gram.y" /* yacc.c:1668  */
+#line 494 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2425 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2427 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 58:
-#line 496 "src/parse-gram.y" /* yacc.c:1668  */
+#line 496 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2431 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2433 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 59:
-#line 501 "src/parse-gram.y" /* yacc.c:1668  */
+#line 501 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2440 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2442 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 60:
-#line 506 "src/parse-gram.y" /* yacc.c:1668  */
+#line 506 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = (yyvsp[-1].symbol);
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2450 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2452 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 61:
-#line 516 "src/parse-gram.y" /* yacc.c:1668  */
+#line 516 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2456 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2458 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 62:
-#line 518 "src/parse-gram.y" /* yacc.c:1668  */
+#line 518 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2462 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2464 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 63:
-#line 522 "src/parse-gram.y" /* yacc.c:1668  */
+#line 522 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2468 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2470 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 64:
-#line 523 "src/parse-gram.y" /* yacc.c:1668  */
+#line 523 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2474 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2476 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 65:
-#line 527 "src/parse-gram.y" /* yacc.c:1668  */
+#line 527 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2480 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2482 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 66:
-#line 528 "src/parse-gram.y" /* yacc.c:1668  */
+#line 528 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2486 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2488 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 68:
-#line 533 "src/parse-gram.y" /* yacc.c:1668  */
+#line 533 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2492 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2494 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 69:
-#line 534 "src/parse-gram.y" /* yacc.c:1668  */
+#line 534 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2498 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2500 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 70:
-#line 540 "src/parse-gram.y" /* yacc.c:1668  */
+#line 540 "src/parse-gram.y" /* yacc.c:1663  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2507 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2509 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 71:
-#line 545 "src/parse-gram.y" /* yacc.c:1668  */
+#line 545 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2516 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2518 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 72:
-#line 550 "src/parse-gram.y" /* yacc.c:1668  */
+#line 550 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2526 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2528 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 73:
-#line 556 "src/parse-gram.y" /* yacc.c:1668  */
+#line 556 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2536 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2538 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 74:
-#line 562 "src/parse-gram.y" /* yacc.c:1668  */
+#line 562 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2547 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2549 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 81:
-#line 592 "src/parse-gram.y" /* yacc.c:1668  */
+#line 592 "src/parse-gram.y" /* yacc.c:1663  */
     {
       yyerrok;
     }
-#line 2555 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2557 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 82:
-#line 598 "src/parse-gram.y" /* yacc.c:1668  */
+#line 598 "src/parse-gram.y" /* yacc.c:1663  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2561 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2563 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 83:
-#line 599 "src/parse-gram.y" /* yacc.c:1668  */
+#line 599 "src/parse-gram.y" /* yacc.c:1663  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2570 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2572 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 84:
-#line 606 "src/parse-gram.y" /* yacc.c:1668  */
+#line 606 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2576 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2578 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 85:
-#line 607 "src/parse-gram.y" /* yacc.c:1668  */
+#line 607 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2582 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2584 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 87:
-#line 614 "src/parse-gram.y" /* yacc.c:1668  */
+#line 614 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2589 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2591 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 88:
-#line 617 "src/parse-gram.y" /* yacc.c:1668  */
+#line 617 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2595 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2597 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 89:
-#line 619 "src/parse-gram.y" /* yacc.c:1668  */
+#line 619 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2601 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2603 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 90:
-#line 621 "src/parse-gram.y" /* yacc.c:1668  */
+#line 621 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2607 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2609 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 91:
-#line 623 "src/parse-gram.y" /* yacc.c:1668  */
+#line 623 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2613 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2615 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 92:
-#line 625 "src/parse-gram.y" /* yacc.c:1668  */
+#line 625 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2619 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2621 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 93:
-#line 627 "src/parse-gram.y" /* yacc.c:1668  */
+#line 627 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2625 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2627 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 94:
-#line 629 "src/parse-gram.y" /* yacc.c:1668  */
+#line 629 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2631 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2633 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 95:
-#line 633 "src/parse-gram.y" /* yacc.c:1668  */
+#line 633 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.named_ref) = 0; }
-#line 2637 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2639 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 96:
-#line 634 "src/parse-gram.y" /* yacc.c:1668  */
+#line 634 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2643 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2645 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 98:
-#line 645 "src/parse-gram.y" /* yacc.c:1668  */
+#line 645 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-#line 2649 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2651 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 99:
-#line 670 "src/parse-gram.y" /* yacc.c:1668  */
+#line 670 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2655 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2657 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 100:
-#line 671 "src/parse-gram.y" /* yacc.c:1668  */
+#line 671 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2661 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2663 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 101:
-#line 672 "src/parse-gram.y" /* yacc.c:1668  */
+#line 672 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].chars); }
-#line 2667 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2669 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 102:
-#line 673 "src/parse-gram.y" /* yacc.c:1668  */
+#line 673 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = (yyvsp[0].chars); }
-#line 2673 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2675 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 103:
-#line 683 "src/parse-gram.y" /* yacc.c:1668  */
+#line 683 "src/parse-gram.y" /* yacc.c:1663  */
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\0';
@@ -2682,42 +2684,42 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-#line 2686 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2688 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 104:
-#line 703 "src/parse-gram.y" /* yacc.c:1668  */
+#line 703 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2692 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2694 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 105:
-#line 705 "src/parse-gram.y" /* yacc.c:1668  */
+#line 705 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2702 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2704 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 106:
-#line 713 "src/parse-gram.y" /* yacc.c:1668  */
+#line 713 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2708 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2710 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 109:
-#line 725 "src/parse-gram.y" /* yacc.c:1668  */
+#line 725 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2717 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2719 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 111:
-#line 734 "src/parse-gram.y" /* yacc.c:1668  */
+#line 734 "src/parse-gram.y" /* yacc.c:1663  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2726,11 +2728,11 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2730 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2732 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
 
-#line 2734 "src/parse-gram.c" /* yacc.c:1668  */
+#line 2736 "src/parse-gram.c" /* yacc.c:1663  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2977,7 +2979,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 744 "src/parse-gram.y" /* yacc.c:1928  */
+#line 744 "src/parse-gram.y" /* yacc.c:1923  */
 
 
 /* Return the location of the left-hand side of a rule whose
