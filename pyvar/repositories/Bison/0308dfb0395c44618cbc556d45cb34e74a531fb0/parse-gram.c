@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.1.91.3-e0aef.  */
+/* A Bison parser, made by GNU Bison 3.1.91.31-00793.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -40,11 +40,14 @@
    define necessary library symbols; they are noted "INFRINGES ON
    USER NAME SPACE" below.  */
 
+/* Undocumented macros, especially those whose name start with YY_,
+   are private implementation details.  Do not rely on them.  */
+
 /* Identify Bison output.  */
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.1.91.3-e0aef"
+#define YYBISON_VERSION "3.1.91.31-00793"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -64,7 +67,7 @@
   /* On column 0 to please syntax-check.  */
 #include <config.h>
 
-#line 68 "src/parse-gram.c" /* yacc.c:316  */
+#line 71 "src/parse-gram.c" /* yacc.c:316  */
 /* Substitute the type names.  */
 #define YYSTYPE         GRAM_STYPE
 #define YYLTYPE         GRAM_LTYPE
@@ -133,7 +136,7 @@ extern int gram_debug;
 #line 645 "src/parse-gram.y" /* yacc.c:353  */
 #include "muscle-tab.h"
 
-#line 137 "src/parse-gram.c" /* yacc.c:353  */
+#line 140 "src/parse-gram.c" /* yacc.c:353  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -232,7 +235,7 @@ code_props_type code_type;
     muscle_kind kind;
   } value;
 
-#line 236 "src/parse-gram.c" /* yacc.c:353  */
+#line 239 "src/parse-gram.c" /* yacc.c:353  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -337,7 +340,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 341 "src/parse-gram.c" /* yacc.c:356  */
+#line 344 "src/parse-gram.c" /* yacc.c:356  */
 
 #ifdef short
 # undef short
@@ -412,15 +415,6 @@ typedef short yytype_int16;
 # define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
 #endif
 
-#if !defined _Noreturn \
-     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
-# if defined _MSC_VER && 1200 <= _MSC_VER
-#  define _Noreturn __declspec (noreturn)
-# else
-#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
-# endif
-#endif
-
 /* Suppress unused-variable warnings by "using" E.  */
 #if ! defined lint || defined __GNUC__
 # define YYUSE(E) ((void) (E))
@@ -937,10 +931,10 @@ do {                                            \
 /* Print *YYLOCP on YYO.  Private, do not rely on its existence. */
 
 YY_ATTRIBUTE_UNUSED
-static unsigned
+static int
 yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
 {
-  unsigned res = 0;
+  int res = 0;
   int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
   if (0 <= yylocp->first_line)
     {
@@ -1004,73 +998,73 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
           case 3: /* "string"  */
 #line 189 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).code)), yyo); }
-#line 1008 "src/parse-gram.c" /* yacc.c:681  */
+#line 1002 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 23: /* "%<flag>"  */
 #line 197 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 1014 "src/parse-gram.c" /* yacc.c:681  */
+#line 1008 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 39: /* "{...}"  */
 #line 190 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1020 "src/parse-gram.c" /* yacc.c:681  */
+#line 1014 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 40: /* "%?{...}"  */
 #line 190 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1026 "src/parse-gram.c" /* yacc.c:681  */
+#line 1020 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 41: /* "[identifier]"  */
 #line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 1032 "src/parse-gram.c" /* yacc.c:681  */
+#line 1026 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 42: /* "char"  */
 #line 185 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 1038 "src/parse-gram.c" /* yacc.c:681  */
+#line 1032 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 43: /* "epilogue"  */
 #line 190 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1044 "src/parse-gram.c" /* yacc.c:681  */
+#line 1038 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 45: /* "identifier"  */
 #line 194 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1050 "src/parse-gram.c" /* yacc.c:681  */
+#line 1044 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 46: /* "identifier:"  */
 #line 196 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1056 "src/parse-gram.c" /* yacc.c:681  */
+#line 1050 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 49: /* "%{...%}"  */
 #line 190 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1062 "src/parse-gram.c" /* yacc.c:681  */
+#line 1056 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 51: /* "<tag>"  */
 #line 198 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1068 "src/parse-gram.c" /* yacc.c:681  */
+#line 1062 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 54: /* "integer"  */
 #line 202 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1074 "src/parse-gram.c" /* yacc.c:681  */
+#line 1068 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 55: /* "%param"  */
@@ -1087,31 +1081,31 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1091 "src/parse-gram.c" /* yacc.c:681  */
+#line 1085 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 65: /* code_props_type  */
 #line 410 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1097 "src/parse-gram.c" /* yacc.c:681  */
+#line 1091 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 74: /* symbol.prec  */
 #line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1103 "src/parse-gram.c" /* yacc.c:681  */
+#line 1097 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 78: /* tag  */
 #line 198 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1109 "src/parse-gram.c" /* yacc.c:681  */
+#line 1103 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 88: /* variable  */
 #line 194 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1115 "src/parse-gram.c" /* yacc.c:681  */
+#line 1109 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 89: /* value  */
@@ -1124,31 +1118,31 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1128 "src/parse-gram.c" /* yacc.c:681  */
+#line 1122 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 90: /* id  */
 #line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1134 "src/parse-gram.c" /* yacc.c:681  */
+#line 1128 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 91: /* id_colon  */
 #line 207 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1140 "src/parse-gram.c" /* yacc.c:681  */
+#line 1134 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 92: /* symbol  */
 #line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1146 "src/parse-gram.c" /* yacc.c:681  */
+#line 1140 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 93: /* string_as_id  */
 #line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1152 "src/parse-gram.c" /* yacc.c:681  */
+#line 1146 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
 
@@ -1276,7 +1270,7 @@ yy_lac_stack_realloc (YYSIZE_T *yycapacity, YYSIZE_T yyadd,
                       yytype_int16 **yytop, yytype_int16 *yytop_empty)
 {
   YYSIZE_T yysize_old =
-    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
+    (YYSIZE_T) (*yytop == yytop_empty ? 0 : *yytop - *yybottom + 1);
   YYSIZE_T yysize_new = yysize_old + yyadd;
   if (*yycapacity < yysize_new)
     {
@@ -1439,7 +1433,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
         YYDPRINTF ((stderr, " R%d", yyrule - 1));
         if (yyesp != yyes_prev)
           {
-            YYSIZE_T yysize = yyesp - *yyes + 1;
+            YYSIZE_T yysize = (YYSIZE_T) (yyesp - *yyes + 1);
             if (yylen < yysize)
               {
                 yyesp -= yylen;
@@ -1455,15 +1449,14 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
           yyesp = yyes_prev -= yylen;
       }
       {
-        int yystate;
+        yytype_int16 yystate;
         {
-          int yylhs = yyr1[yyrule] - YYNTOKENS;
-          yystate = yypgoto[yylhs] + *yyesp;
-          if (yystate < 0 || YYLAST < yystate
-              || yycheck[yystate] != *yyesp)
-            yystate = yydefgoto[yylhs];
-          else
-            yystate = yytable[yystate];
+          const int yylhs = yyr1[yyrule] - YYNTOKENS;
+          const int yyi = yypgoto[yylhs] + *yyesp;
+          yystate = ((yytype_int16)
+                     (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
+                      ? yytable[yyi]
+                      : yydefgoto[yylhs]));
         }
         if (yyesp == yyes_prev)
           {
@@ -1483,7 +1476,7 @@ yy_lac (yytype_int16 *yyesa, yytype_int16 **yyes,
               }
             *++yyesp = yystate;
           }
-        YYDPRINTF ((stderr, " G%d", yystate));
+        YYDPRINTF ((stderr, " G%d", (int) yystate));
       }
     }
 }
@@ -1571,7 +1564,7 @@ yytnamerr (char *yyres, const char *yystr)
   if (! yyres)
     return yystrlen (yystr);
 
-  return yystpcpy (yyres, yystr) - yyres;
+  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
 }
 # endif
 
@@ -1843,7 +1836,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 109 "src/parse-gram.y" /* yacc.c:1430  */
+#line 109 "src/parse-gram.y" /* yacc.c:1429  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1851,7 +1844,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1855 "src/parse-gram.c" /* yacc.c:1430  */
+#line 1848 "src/parse-gram.c" /* yacc.c:1429  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -1864,12 +1857,12 @@ YYLTYPE yylloc = yyloc_default;
   yyssp++;
 
  yysetstate:
-  *yyssp = yystate;
+  *yyssp = (yytype_int16) yystate;
 
   if (yyss + yystacksize - 1 <= yyssp)
     {
       /* Get the current used size of the three stacks, in elements.  */
-      YYSIZE_T yysize = yyssp - yyss + 1;
+      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);
 
 #ifdef yyoverflow
       {
@@ -1889,10 +1882,9 @@ YYLTYPE yylloc = yyloc_default;
                     &yyvs1, yysize * sizeof (*yyvsp),
                     &yyls1, yysize * sizeof (*yylsp),
                     &yystacksize);
-
-        yyls = yyls1;
         yyss = yyss1;
         yyvs = yyvs1;
+        yyls = yyls1;
       }
 #else /* no yyoverflow */
 # ifndef YYSTACK_RELOCATE
@@ -2046,143 +2038,143 @@ yyreduce:
     switch (yyn)
       {
   case 6:
-#line 281 "src/parse-gram.y" /* yacc.c:1647  */
+#line 281 "src/parse-gram.y" /* yacc.c:1645  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2056 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2048 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 7:
-#line 287 "src/parse-gram.y" /* yacc.c:1647  */
+#line 287 "src/parse-gram.y" /* yacc.c:1645  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2064 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2056 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 8:
-#line 291 "src/parse-gram.y" /* yacc.c:1647  */
+#line 291 "src/parse-gram.y" /* yacc.c:1645  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2073 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2065 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 9:
-#line 295 "src/parse-gram.y" /* yacc.c:1647  */
+#line 295 "src/parse-gram.y" /* yacc.c:1645  */
     { defines_flag = true; }
-#line 2079 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2071 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 10:
-#line 297 "src/parse-gram.y" /* yacc.c:1647  */
+#line 297 "src/parse-gram.y" /* yacc.c:1645  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].code));
     }
-#line 2088 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2080 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 11:
-#line 302 "src/parse-gram.y" /* yacc.c:1647  */
+#line 302 "src/parse-gram.y" /* yacc.c:1645  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2098 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2090 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 12:
-#line 307 "src/parse-gram.y" /* yacc.c:1647  */
+#line 307 "src/parse-gram.y" /* yacc.c:1645  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2104 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2096 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 13:
-#line 308 "src/parse-gram.y" /* yacc.c:1647  */
+#line 308 "src/parse-gram.y" /* yacc.c:1645  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2110 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2102 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 14:
-#line 309 "src/parse-gram.y" /* yacc.c:1647  */
+#line 309 "src/parse-gram.y" /* yacc.c:1645  */
     { spec_file_prefix = (yyvsp[0].code); }
-#line 2116 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2108 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 15:
-#line 311 "src/parse-gram.y" /* yacc.c:1647  */
+#line 311 "src/parse-gram.y" /* yacc.c:1645  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2125 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2117 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 16:
-#line 316 "src/parse-gram.y" /* yacc.c:1647  */
+#line 316 "src/parse-gram.y" /* yacc.c:1645  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].code), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2134 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2126 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 17:
-#line 320 "src/parse-gram.y" /* yacc.c:1647  */
+#line 320 "src/parse-gram.y" /* yacc.c:1645  */
     { language_argmatch ((yyvsp[0].code), grammar_prio, (yylsp[-1])); }
-#line 2140 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2132 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 18:
-#line 321 "src/parse-gram.y" /* yacc.c:1647  */
+#line 321 "src/parse-gram.y" /* yacc.c:1645  */
     { spec_name_prefix = (yyvsp[0].code); }
-#line 2146 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2138 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 19:
-#line 322 "src/parse-gram.y" /* yacc.c:1647  */
+#line 322 "src/parse-gram.y" /* yacc.c:1645  */
     { no_lines_flag = true; }
-#line 2152 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2144 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 20:
-#line 323 "src/parse-gram.y" /* yacc.c:1647  */
+#line 323 "src/parse-gram.y" /* yacc.c:1645  */
     { nondeterministic_parser = true; }
-#line 2158 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2150 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 21:
-#line 324 "src/parse-gram.y" /* yacc.c:1647  */
+#line 324 "src/parse-gram.y" /* yacc.c:1645  */
     { spec_outfile = (yyvsp[0].code); }
-#line 2164 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2156 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 22:
-#line 325 "src/parse-gram.y" /* yacc.c:1647  */
+#line 325 "src/parse-gram.y" /* yacc.c:1645  */
     { current_param = (yyvsp[0].param); }
-#line 2170 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2162 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 23:
-#line 325 "src/parse-gram.y" /* yacc.c:1647  */
+#line 325 "src/parse-gram.y" /* yacc.c:1645  */
     { current_param = param_none; }
-#line 2176 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2168 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 24:
-#line 326 "src/parse-gram.y" /* yacc.c:1647  */
+#line 326 "src/parse-gram.y" /* yacc.c:1645  */
     { version_check (&(yylsp[0]), (yyvsp[0].code)); }
-#line 2182 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2174 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 25:
-#line 328 "src/parse-gram.y" /* yacc.c:1647  */
+#line 328 "src/parse-gram.y" /* yacc.c:1645  */
     {
       char const *skeleton_user = (yyvsp[0].code);
       if (strchr (skeleton_user, '/'))
@@ -2206,49 +2198,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2210 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2202 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 26:
-#line 351 "src/parse-gram.y" /* yacc.c:1647  */
+#line 351 "src/parse-gram.y" /* yacc.c:1645  */
     { token_table_flag = true; }
-#line 2216 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2208 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 27:
-#line 352 "src/parse-gram.y" /* yacc.c:1647  */
+#line 352 "src/parse-gram.y" /* yacc.c:1645  */
     { report_flag |= report_states; }
-#line 2222 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2214 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 28:
-#line 353 "src/parse-gram.y" /* yacc.c:1647  */
+#line 353 "src/parse-gram.y" /* yacc.c:1645  */
     { yacc_flag = true; }
-#line 2228 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2220 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 30:
-#line 358 "src/parse-gram.y" /* yacc.c:1647  */
+#line 358 "src/parse-gram.y" /* yacc.c:1645  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2234 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2226 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 31:
-#line 359 "src/parse-gram.y" /* yacc.c:1647  */
+#line 359 "src/parse-gram.y" /* yacc.c:1645  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2240 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2232 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 34:
-#line 371 "src/parse-gram.y" /* yacc.c:1647  */
+#line 371 "src/parse-gram.y" /* yacc.c:1645  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2248 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2240 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 35:
-#line 375 "src/parse-gram.y" /* yacc.c:1647  */
+#line 375 "src/parse-gram.y" /* yacc.c:1645  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2259,27 +2251,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2263 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2255 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 36:
-#line 386 "src/parse-gram.y" /* yacc.c:1647  */
+#line 386 "src/parse-gram.y" /* yacc.c:1645  */
     {
       default_prec = true;
     }
-#line 2271 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2263 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 37:
-#line 390 "src/parse-gram.y" /* yacc.c:1647  */
+#line 390 "src/parse-gram.y" /* yacc.c:1645  */
     {
       default_prec = false;
     }
-#line 2279 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2271 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 38:
-#line 394 "src/parse-gram.y" /* yacc.c:1647  */
+#line 394 "src/parse-gram.y" /* yacc.c:1645  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2287,97 +2279,97 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2291 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2283 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 39:
-#line 402 "src/parse-gram.y" /* yacc.c:1647  */
+#line 402 "src/parse-gram.y" /* yacc.c:1645  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2300 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2292 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 40:
-#line 412 "src/parse-gram.y" /* yacc.c:1647  */
+#line 412 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.code_type) = destructor; }
-#line 2306 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2298 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 41:
-#line 413 "src/parse-gram.y" /* yacc.c:1647  */
+#line 413 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.code_type) = printer; }
-#line 2312 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2304 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 42:
-#line 423 "src/parse-gram.y" /* yacc.c:1647  */
+#line 423 "src/parse-gram.y" /* yacc.c:1645  */
     {}
-#line 2318 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2310 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 43:
-#line 424 "src/parse-gram.y" /* yacc.c:1647  */
+#line 424 "src/parse-gram.y" /* yacc.c:1645  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].uniqstr),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2326 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2318 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 44:
-#line 431 "src/parse-gram.y" /* yacc.c:1647  */
+#line 431 "src/parse-gram.y" /* yacc.c:1645  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2336 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2328 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 45:
-#line 442 "src/parse-gram.y" /* yacc.c:1647  */
+#line 442 "src/parse-gram.y" /* yacc.c:1645  */
     { current_class = nterm_sym; }
-#line 2342 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2334 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 46:
-#line 443 "src/parse-gram.y" /* yacc.c:1647  */
+#line 443 "src/parse-gram.y" /* yacc.c:1645  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2351 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2343 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 47:
-#line 447 "src/parse-gram.y" /* yacc.c:1647  */
+#line 447 "src/parse-gram.y" /* yacc.c:1645  */
     { current_class = token_sym; }
-#line 2357 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2349 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 48:
-#line 448 "src/parse-gram.y" /* yacc.c:1647  */
+#line 448 "src/parse-gram.y" /* yacc.c:1645  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2366 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2358 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 49:
-#line 453 "src/parse-gram.y" /* yacc.c:1647  */
+#line 453 "src/parse-gram.y" /* yacc.c:1645  */
     {
       tag_seen = true;
       for (symbol_list *list = (yyvsp[0].list); list; list = list->next)
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2377 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2369 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 50:
-#line 463 "src/parse-gram.y" /* yacc.c:1647  */
+#line 463 "src/parse-gram.y" /* yacc.c:1645  */
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].list); list; list = list->next)
@@ -2388,341 +2380,341 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2392 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2384 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 51:
-#line 476 "src/parse-gram.y" /* yacc.c:1647  */
+#line 476 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.assoc) = left_assoc; }
-#line 2398 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2390 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 52:
-#line 477 "src/parse-gram.y" /* yacc.c:1647  */
+#line 477 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.assoc) = right_assoc; }
-#line 2404 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2396 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 53:
-#line 478 "src/parse-gram.y" /* yacc.c:1647  */
+#line 478 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.assoc) = non_assoc; }
-#line 2410 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2402 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 54:
-#line 479 "src/parse-gram.y" /* yacc.c:1647  */
+#line 479 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2416 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2408 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 55:
-#line 483 "src/parse-gram.y" /* yacc.c:1647  */
+#line 483 "src/parse-gram.y" /* yacc.c:1645  */
     { current_type = NULL; }
-#line 2422 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2414 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 56:
-#line 484 "src/parse-gram.y" /* yacc.c:1647  */
+#line 484 "src/parse-gram.y" /* yacc.c:1645  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2428 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2420 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 57:
-#line 490 "src/parse-gram.y" /* yacc.c:1647  */
+#line 490 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2434 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2426 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 58:
-#line 492 "src/parse-gram.y" /* yacc.c:1647  */
+#line 492 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2440 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2432 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 59:
-#line 497 "src/parse-gram.y" /* yacc.c:1647  */
+#line 497 "src/parse-gram.y" /* yacc.c:1645  */
     {
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2449 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2441 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 60:
-#line 502 "src/parse-gram.y" /* yacc.c:1647  */
+#line 502 "src/parse-gram.y" /* yacc.c:1645  */
     {
       (yyval.symbol) = (yyvsp[-1].symbol);
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2459 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2451 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 61:
-#line 512 "src/parse-gram.y" /* yacc.c:1647  */
+#line 512 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2465 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2457 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 62:
-#line 514 "src/parse-gram.y" /* yacc.c:1647  */
+#line 514 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2471 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2463 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 63:
-#line 518 "src/parse-gram.y" /* yacc.c:1647  */
+#line 518 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2477 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2469 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 64:
-#line 519 "src/parse-gram.y" /* yacc.c:1647  */
+#line 519 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2483 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2475 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 65:
-#line 523 "src/parse-gram.y" /* yacc.c:1647  */
+#line 523 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2489 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2481 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 66:
-#line 524 "src/parse-gram.y" /* yacc.c:1647  */
+#line 524 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2495 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2487 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 68:
-#line 529 "src/parse-gram.y" /* yacc.c:1647  */
+#line 529 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2501 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2493 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 69:
-#line 530 "src/parse-gram.y" /* yacc.c:1647  */
+#line 530 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2507 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2499 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 70:
-#line 536 "src/parse-gram.y" /* yacc.c:1647  */
+#line 536 "src/parse-gram.y" /* yacc.c:1645  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2516 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2508 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 71:
-#line 541 "src/parse-gram.y" /* yacc.c:1647  */
+#line 541 "src/parse-gram.y" /* yacc.c:1645  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2525 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2517 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 72:
-#line 546 "src/parse-gram.y" /* yacc.c:1647  */
+#line 546 "src/parse-gram.y" /* yacc.c:1645  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2535 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2527 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 73:
-#line 552 "src/parse-gram.y" /* yacc.c:1647  */
+#line 552 "src/parse-gram.y" /* yacc.c:1645  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2545 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2537 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 74:
-#line 558 "src/parse-gram.y" /* yacc.c:1647  */
+#line 558 "src/parse-gram.y" /* yacc.c:1645  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2556 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2548 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 81:
-#line 588 "src/parse-gram.y" /* yacc.c:1647  */
+#line 588 "src/parse-gram.y" /* yacc.c:1645  */
     {
       yyerrok;
     }
-#line 2564 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2556 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 82:
-#line 594 "src/parse-gram.y" /* yacc.c:1647  */
+#line 594 "src/parse-gram.y" /* yacc.c:1645  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2570 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2562 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 83:
-#line 595 "src/parse-gram.y" /* yacc.c:1647  */
+#line 595 "src/parse-gram.y" /* yacc.c:1645  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2579 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2571 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 84:
-#line 602 "src/parse-gram.y" /* yacc.c:1647  */
+#line 602 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2585 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2577 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 85:
-#line 603 "src/parse-gram.y" /* yacc.c:1647  */
+#line 603 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2591 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2583 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 87:
-#line 610 "src/parse-gram.y" /* yacc.c:1647  */
+#line 610 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2598 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2590 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 88:
-#line 613 "src/parse-gram.y" /* yacc.c:1647  */
+#line 613 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2604 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2596 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 89:
-#line 615 "src/parse-gram.y" /* yacc.c:1647  */
+#line 615 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), current_type); }
-#line 2610 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2602 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 90:
-#line 617 "src/parse-gram.y" /* yacc.c:1647  */
+#line 617 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_predicate_append ((yyvsp[0].code), (yylsp[0])); }
-#line 2616 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2608 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 91:
-#line 619 "src/parse-gram.y" /* yacc.c:1647  */
+#line 619 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2622 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2614 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 92:
-#line 621 "src/parse-gram.y" /* yacc.c:1647  */
+#line 621 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2628 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2620 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 93:
-#line 623 "src/parse-gram.y" /* yacc.c:1647  */
+#line 623 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2634 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2626 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 94:
-#line 625 "src/parse-gram.y" /* yacc.c:1647  */
+#line 625 "src/parse-gram.y" /* yacc.c:1645  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2640 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2632 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 95:
-#line 629 "src/parse-gram.y" /* yacc.c:1647  */
+#line 629 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.named_ref) = 0; }
-#line 2646 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2638 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 96:
-#line 630 "src/parse-gram.y" /* yacc.c:1647  */
+#line 630 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2652 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2644 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 98:
-#line 641 "src/parse-gram.y" /* yacc.c:1647  */
+#line 641 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].code)); }
-#line 2658 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2650 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 99:
-#line 666 "src/parse-gram.y" /* yacc.c:1647  */
+#line 666 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2664 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2656 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 100:
-#line 667 "src/parse-gram.y" /* yacc.c:1647  */
+#line 667 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2670 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2662 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 101:
-#line 668 "src/parse-gram.y" /* yacc.c:1647  */
+#line 668 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].code); }
-#line 2676 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2668 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 102:
-#line 669 "src/parse-gram.y" /* yacc.c:1647  */
+#line 669 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].code)); }
-#line 2682 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2674 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 103:
-#line 682 "src/parse-gram.y" /* yacc.c:1647  */
+#line 682 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2688 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2680 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 104:
-#line 684 "src/parse-gram.y" /* yacc.c:1647  */
+#line 684 "src/parse-gram.y" /* yacc.c:1645  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2698 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2690 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 105:
-#line 692 "src/parse-gram.y" /* yacc.c:1647  */
+#line 692 "src/parse-gram.y" /* yacc.c:1645  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2704 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2696 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 108:
-#line 704 "src/parse-gram.y" /* yacc.c:1647  */
+#line 704 "src/parse-gram.y" /* yacc.c:1645  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].code)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2713 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2705 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
   case 110:
-#line 713 "src/parse-gram.y" /* yacc.c:1647  */
+#line 713 "src/parse-gram.y" /* yacc.c:1645  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2722 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2714 "src/parse-gram.c" /* yacc.c:1645  */
     break;
 
 
-#line 2726 "src/parse-gram.c" /* yacc.c:1647  */
+#line 2718 "src/parse-gram.c" /* yacc.c:1645  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2751,14 +2743,13 @@ yyreduce:
   /* Now 'shift' the result of the reduction.  Determine what state
      that goes to, based on the state we popped back to and the rule
      number reduced by.  */
-
-  yyn = yyr1[yyn];
-
-  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
-  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
-    yystate = yytable[yystate];
-  else
-    yystate = yydefgoto[yyn - YYNTOKENS];
+  {
+    const int yylhs = yyr1[yyn] - YYNTOKENS;
+    const int yyi = yypgoto[yylhs] + *yyssp;
+    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
+               ? yytable[yyi]
+               : yydefgoto[yylhs]);
+  }
 
   goto yynewstate;
 
@@ -2968,7 +2959,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 719 "src/parse-gram.y" /* yacc.c:1906  */
+#line 719 "src/parse-gram.y" /* yacc.c:1903  */
 
 
 /* Return the location of the left-hand side of a rule whose
