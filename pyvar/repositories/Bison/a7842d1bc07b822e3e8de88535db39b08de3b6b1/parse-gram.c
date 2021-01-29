@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.1.222-4227c.  */
+/* A Bison parser, made by GNU Bison 3.1.91.3-e0aef.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.1.222-4227c"
+#define YYBISON_VERSION "3.1.91.3-e0aef"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -76,9 +76,6 @@
 #define yynerrs         gram_nerrs
 
 
-/* Copy the first part of user declarations.  */
-
-#line 82 "src/parse-gram.c" /* yacc.c:339  */
 
 # ifndef YY_NULLPTR
 #  if defined __cplusplus
@@ -120,11 +117,11 @@
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-#line 21 "src/parse-gram.y" /* yacc.c:355  */
+#line 21 "src/parse-gram.y" /* yacc.c:353  */
 
   #include "symlist.h"
   #include "symtab.h"
-#line 222 "src/parse-gram.y" /* yacc.c:355  */
+#line 222 "src/parse-gram.y" /* yacc.c:353  */
 
   typedef enum
   {
@@ -133,10 +130,10 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 645 "src/parse-gram.y" /* yacc.c:355  */
+#line 645 "src/parse-gram.y" /* yacc.c:353  */
 #include "muscle-tab.h"
 
-#line 140 "src/parse-gram.c" /* yacc.c:355  */
+#line 137 "src/parse-gram.c" /* yacc.c:353  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -207,27 +204,27 @@ extern int gram_debug;
 
 union GRAM_STYPE
 {
-#line 183 "src/parse-gram.y" /* yacc.c:355  */
+#line 183 "src/parse-gram.y" /* yacc.c:353  */
 unsigned char character;
-#line 187 "src/parse-gram.y" /* yacc.c:355  */
+#line 187 "src/parse-gram.y" /* yacc.c:353  */
 char *code;
-#line 192 "src/parse-gram.y" /* yacc.c:355  */
+#line 192 "src/parse-gram.y" /* yacc.c:353  */
 uniqstr uniqstr;
-#line 200 "src/parse-gram.y" /* yacc.c:355  */
+#line 200 "src/parse-gram.y" /* yacc.c:353  */
 int integer;
-#line 204 "src/parse-gram.y" /* yacc.c:355  */
+#line 204 "src/parse-gram.y" /* yacc.c:353  */
 symbol *symbol;
-#line 209 "src/parse-gram.y" /* yacc.c:355  */
+#line 209 "src/parse-gram.y" /* yacc.c:353  */
 assoc assoc;
-#line 212 "src/parse-gram.y" /* yacc.c:355  */
+#line 212 "src/parse-gram.y" /* yacc.c:353  */
 symbol_list *list;
-#line 215 "src/parse-gram.y" /* yacc.c:355  */
+#line 215 "src/parse-gram.y" /* yacc.c:353  */
 named_ref *named_ref;
-#line 242 "src/parse-gram.y" /* yacc.c:355  */
+#line 242 "src/parse-gram.y" /* yacc.c:353  */
 param_type param;
-#line 409 "src/parse-gram.y" /* yacc.c:355  */
+#line 409 "src/parse-gram.y" /* yacc.c:353  */
 code_props_type code_type;
-#line 647 "src/parse-gram.y" /* yacc.c:355  */
+#line 647 "src/parse-gram.y" /* yacc.c:353  */
 
   struct
   {
@@ -235,7 +232,7 @@ code_props_type code_type;
     muscle_kind kind;
   } value;
 
-#line 239 "src/parse-gram.c" /* yacc.c:355  */
+#line 236 "src/parse-gram.c" /* yacc.c:353  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -263,11 +260,9 @@ int gram_parse (void);
 
 #endif /* !YY_GRAM_SRC_PARSE_GRAM_H_INCLUDED  */
 
-/* Copy the second part of user declarations.  */
 
-#line 269 "src/parse-gram.c" /* yacc.c:358  */
 /* Unqualified %code blocks.  */
-#line 33 "src/parse-gram.y" /* yacc.c:359  */
+#line 33 "src/parse-gram.y" /* yacc.c:356  */
 
   #include "system.h"
   #include <errno.h>
@@ -331,7 +326,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 232 "src/parse-gram.y" /* yacc.c:359  */
+#line 232 "src/parse-gram.y" /* yacc.c:356  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -342,7 +337,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 346 "src/parse-gram.c" /* yacc.c:359  */
+#line 341 "src/parse-gram.c" /* yacc.c:356  */
 
 #ifdef short
 # undef short
@@ -988,98 +983,98 @@ do {                                                                      \
 } while (0)
 
 
-/*----------------------------------------.
-| Print this symbol's value on YYOUTPUT.  |
-`----------------------------------------*/
+/*-----------------------------------.
+| Print this symbol's value on YYO.  |
+`-----------------------------------*/
 
 static void
-yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
+yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
-  FILE *yyo = yyoutput;
-  YYUSE (yyo);
+  FILE *yyoutput = yyo;
+  YYUSE (yyoutput);
   YYUSE (yylocationp);
   if (!yyvaluep)
     return;
 # ifdef YYPRINT
   if (yytype < YYNTOKENS)
-    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
+    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
 # endif
   switch (yytype)
     {
           case 3: /* "string"  */
-#line 189 "src/parse-gram.y" /* yacc.c:684  */
+#line 189 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).code)), yyo); }
-#line 1013 "src/parse-gram.c" /* yacc.c:684  */
+#line 1008 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 23: /* "%<flag>"  */
-#line 197 "src/parse-gram.y" /* yacc.c:684  */
+#line 197 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 1019 "src/parse-gram.c" /* yacc.c:684  */
+#line 1014 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 39: /* "{...}"  */
-#line 190 "src/parse-gram.y" /* yacc.c:684  */
+#line 190 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1025 "src/parse-gram.c" /* yacc.c:684  */
+#line 1020 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 40: /* "%?{...}"  */
-#line 190 "src/parse-gram.y" /* yacc.c:684  */
+#line 190 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1031 "src/parse-gram.c" /* yacc.c:684  */
+#line 1026 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 41: /* "[identifier]"  */
-#line 195 "src/parse-gram.y" /* yacc.c:684  */
+#line 195 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 1037 "src/parse-gram.c" /* yacc.c:684  */
+#line 1032 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 42: /* "char"  */
-#line 185 "src/parse-gram.y" /* yacc.c:684  */
+#line 185 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 1043 "src/parse-gram.c" /* yacc.c:684  */
+#line 1038 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 43: /* "epilogue"  */
-#line 190 "src/parse-gram.y" /* yacc.c:684  */
+#line 190 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1049 "src/parse-gram.c" /* yacc.c:684  */
+#line 1044 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 45: /* "identifier"  */
-#line 194 "src/parse-gram.y" /* yacc.c:684  */
+#line 194 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1055 "src/parse-gram.c" /* yacc.c:684  */
+#line 1050 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 46: /* "identifier:"  */
-#line 196 "src/parse-gram.y" /* yacc.c:684  */
+#line 196 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1061 "src/parse-gram.c" /* yacc.c:684  */
+#line 1056 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 49: /* "%{...%}"  */
-#line 190 "src/parse-gram.y" /* yacc.c:684  */
+#line 190 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1067 "src/parse-gram.c" /* yacc.c:684  */
+#line 1062 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 51: /* "<tag>"  */
-#line 198 "src/parse-gram.y" /* yacc.c:684  */
+#line 198 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1073 "src/parse-gram.c" /* yacc.c:684  */
+#line 1068 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 54: /* "integer"  */
-#line 202 "src/parse-gram.y" /* yacc.c:684  */
+#line 202 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1079 "src/parse-gram.c" /* yacc.c:684  */
+#line 1074 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 55: /* "%param"  */
-#line 245 "src/parse-gram.y" /* yacc.c:684  */
+#line 245 "src/parse-gram.y" /* yacc.c:681  */
       {
   switch (((*yyvaluep).param))
     {
@@ -1092,35 +1087,35 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1096 "src/parse-gram.c" /* yacc.c:684  */
+#line 1091 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 65: /* code_props_type  */
-#line 410 "src/parse-gram.y" /* yacc.c:684  */
+#line 410 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1102 "src/parse-gram.c" /* yacc.c:684  */
+#line 1097 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 74: /* symbol.prec  */
-#line 206 "src/parse-gram.y" /* yacc.c:684  */
+#line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1108 "src/parse-gram.c" /* yacc.c:684  */
+#line 1103 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 78: /* tag  */
-#line 198 "src/parse-gram.y" /* yacc.c:684  */
+#line 198 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1114 "src/parse-gram.c" /* yacc.c:684  */
+#line 1109 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 88: /* variable  */
-#line 194 "src/parse-gram.y" /* yacc.c:684  */
+#line 194 "src/parse-gram.y" /* yacc.c:681  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1120 "src/parse-gram.c" /* yacc.c:684  */
+#line 1115 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 89: /* value  */
-#line 656 "src/parse-gram.y" /* yacc.c:684  */
+#line 656 "src/parse-gram.y" /* yacc.c:681  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1129,31 +1124,31 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1133 "src/parse-gram.c" /* yacc.c:684  */
+#line 1128 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 90: /* id  */
-#line 206 "src/parse-gram.y" /* yacc.c:684  */
+#line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1139 "src/parse-gram.c" /* yacc.c:684  */
+#line 1134 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 91: /* id_colon  */
-#line 207 "src/parse-gram.y" /* yacc.c:684  */
+#line 207 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1145 "src/parse-gram.c" /* yacc.c:684  */
+#line 1140 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 92: /* symbol  */
-#line 206 "src/parse-gram.y" /* yacc.c:684  */
+#line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1151 "src/parse-gram.c" /* yacc.c:684  */
+#line 1146 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
     case 93: /* string_as_id  */
-#line 206 "src/parse-gram.y" /* yacc.c:684  */
+#line 206 "src/parse-gram.y" /* yacc.c:681  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1157 "src/parse-gram.c" /* yacc.c:684  */
+#line 1152 "src/parse-gram.c" /* yacc.c:681  */
         break;
 
 
@@ -1163,20 +1158,20 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
 }
 
 
-/*--------------------------------.
-| Print this symbol on YYOUTPUT.  |
-`--------------------------------*/
+/*---------------------------.
+| Print this symbol on YYO.  |
+`---------------------------*/
 
 static void
-yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
+yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
 {
-  YYFPRINTF (yyoutput, "%s %s (",
+  YYFPRINTF (yyo, "%s %s (",
              yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);
 
-  YY_LOCATION_PRINT (yyoutput, *yylocationp);
-  YYFPRINTF (yyoutput, ": ");
-  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
-  YYFPRINTF (yyoutput, ")");
+  YY_LOCATION_PRINT (yyo, *yylocationp);
+  YYFPRINTF (yyo, ": ");
+  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
+  YYFPRINTF (yyo, ")");
 }
 
 /*------------------------------------------------------------------.
@@ -1848,7 +1843,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 109 "src/parse-gram.y" /* yacc.c:1433  */
+#line 109 "src/parse-gram.y" /* yacc.c:1430  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1856,7 +1851,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1860 "src/parse-gram.c" /* yacc.c:1433  */
+#line 1855 "src/parse-gram.c" /* yacc.c:1430  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2050,144 +2045,144 @@ yyreduce:
     int yychar_backup = yychar;
     switch (yyn)
       {
-          case 6:
-#line 281 "src/parse-gram.y" /* yacc.c:1651  */
+  case 6:
+#line 281 "src/parse-gram.y" /* yacc.c:1647  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2061 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2056 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 7:
-#line 287 "src/parse-gram.y" /* yacc.c:1651  */
+#line 287 "src/parse-gram.y" /* yacc.c:1647  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2069 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2064 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 8:
-#line 291 "src/parse-gram.y" /* yacc.c:1651  */
+#line 291 "src/parse-gram.y" /* yacc.c:1647  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2078 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2073 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 9:
-#line 295 "src/parse-gram.y" /* yacc.c:1651  */
+#line 295 "src/parse-gram.y" /* yacc.c:1647  */
     { defines_flag = true; }
-#line 2084 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2079 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 10:
-#line 297 "src/parse-gram.y" /* yacc.c:1651  */
+#line 297 "src/parse-gram.y" /* yacc.c:1647  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].code));
     }
-#line 2093 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2088 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 11:
-#line 302 "src/parse-gram.y" /* yacc.c:1651  */
+#line 302 "src/parse-gram.y" /* yacc.c:1647  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2103 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2098 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 12:
-#line 307 "src/parse-gram.y" /* yacc.c:1651  */
+#line 307 "src/parse-gram.y" /* yacc.c:1647  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2109 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2104 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 13:
-#line 308 "src/parse-gram.y" /* yacc.c:1651  */
+#line 308 "src/parse-gram.y" /* yacc.c:1647  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2115 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2110 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 14:
-#line 309 "src/parse-gram.y" /* yacc.c:1651  */
+#line 309 "src/parse-gram.y" /* yacc.c:1647  */
     { spec_file_prefix = (yyvsp[0].code); }
-#line 2121 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2116 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 15:
-#line 311 "src/parse-gram.y" /* yacc.c:1651  */
+#line 311 "src/parse-gram.y" /* yacc.c:1647  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2130 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2125 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 16:
-#line 316 "src/parse-gram.y" /* yacc.c:1651  */
+#line 316 "src/parse-gram.y" /* yacc.c:1647  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].code), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2139 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2134 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 17:
-#line 320 "src/parse-gram.y" /* yacc.c:1651  */
+#line 320 "src/parse-gram.y" /* yacc.c:1647  */
     { language_argmatch ((yyvsp[0].code), grammar_prio, (yylsp[-1])); }
-#line 2145 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2140 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 18:
-#line 321 "src/parse-gram.y" /* yacc.c:1651  */
+#line 321 "src/parse-gram.y" /* yacc.c:1647  */
     { spec_name_prefix = (yyvsp[0].code); }
-#line 2151 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2146 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 19:
-#line 322 "src/parse-gram.y" /* yacc.c:1651  */
+#line 322 "src/parse-gram.y" /* yacc.c:1647  */
     { no_lines_flag = true; }
-#line 2157 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2152 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 20:
-#line 323 "src/parse-gram.y" /* yacc.c:1651  */
+#line 323 "src/parse-gram.y" /* yacc.c:1647  */
     { nondeterministic_parser = true; }
-#line 2163 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2158 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 21:
-#line 324 "src/parse-gram.y" /* yacc.c:1651  */
+#line 324 "src/parse-gram.y" /* yacc.c:1647  */
     { spec_outfile = (yyvsp[0].code); }
-#line 2169 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2164 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 22:
-#line 325 "src/parse-gram.y" /* yacc.c:1651  */
+#line 325 "src/parse-gram.y" /* yacc.c:1647  */
     { current_param = (yyvsp[0].param); }
-#line 2175 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2170 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 23:
-#line 325 "src/parse-gram.y" /* yacc.c:1651  */
+#line 325 "src/parse-gram.y" /* yacc.c:1647  */
     { current_param = param_none; }
-#line 2181 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2176 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 24:
-#line 326 "src/parse-gram.y" /* yacc.c:1651  */
+#line 326 "src/parse-gram.y" /* yacc.c:1647  */
     { version_check (&(yylsp[0]), (yyvsp[0].code)); }
-#line 2187 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2182 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 25:
-#line 328 "src/parse-gram.y" /* yacc.c:1651  */
+#line 328 "src/parse-gram.y" /* yacc.c:1647  */
     {
       char const *skeleton_user = (yyvsp[0].code);
       if (strchr (skeleton_user, '/'))
@@ -2211,49 +2206,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2215 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2210 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 26:
-#line 351 "src/parse-gram.y" /* yacc.c:1651  */
+#line 351 "src/parse-gram.y" /* yacc.c:1647  */
     { token_table_flag = true; }
-#line 2221 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2216 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 27:
-#line 352 "src/parse-gram.y" /* yacc.c:1651  */
+#line 352 "src/parse-gram.y" /* yacc.c:1647  */
     { report_flag |= report_states; }
-#line 2227 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2222 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 28:
-#line 353 "src/parse-gram.y" /* yacc.c:1651  */
+#line 353 "src/parse-gram.y" /* yacc.c:1647  */
     { yacc_flag = true; }
-#line 2233 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2228 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 30:
-#line 358 "src/parse-gram.y" /* yacc.c:1651  */
+#line 358 "src/parse-gram.y" /* yacc.c:1647  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2239 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2234 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 31:
-#line 359 "src/parse-gram.y" /* yacc.c:1651  */
+#line 359 "src/parse-gram.y" /* yacc.c:1647  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2245 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2240 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 34:
-#line 371 "src/parse-gram.y" /* yacc.c:1651  */
+#line 371 "src/parse-gram.y" /* yacc.c:1647  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2253 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2248 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 35:
-#line 375 "src/parse-gram.y" /* yacc.c:1651  */
+#line 375 "src/parse-gram.y" /* yacc.c:1647  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2264,27 +2259,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2268 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2263 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 36:
-#line 386 "src/parse-gram.y" /* yacc.c:1651  */
+#line 386 "src/parse-gram.y" /* yacc.c:1647  */
     {
       default_prec = true;
     }
-#line 2276 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2271 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 37:
-#line 390 "src/parse-gram.y" /* yacc.c:1651  */
+#line 390 "src/parse-gram.y" /* yacc.c:1647  */
     {
       default_prec = false;
     }
-#line 2284 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2279 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 38:
-#line 394 "src/parse-gram.y" /* yacc.c:1651  */
+#line 394 "src/parse-gram.y" /* yacc.c:1647  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2292,97 +2287,97 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2296 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2291 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 39:
-#line 402 "src/parse-gram.y" /* yacc.c:1651  */
+#line 402 "src/parse-gram.y" /* yacc.c:1647  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2305 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2300 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 40:
-#line 412 "src/parse-gram.y" /* yacc.c:1651  */
+#line 412 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.code_type) = destructor; }
-#line 2311 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2306 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 41:
-#line 413 "src/parse-gram.y" /* yacc.c:1651  */
+#line 413 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.code_type) = printer; }
-#line 2317 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2312 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 42:
-#line 423 "src/parse-gram.y" /* yacc.c:1651  */
+#line 423 "src/parse-gram.y" /* yacc.c:1647  */
     {}
-#line 2323 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2318 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 43:
-#line 424 "src/parse-gram.y" /* yacc.c:1651  */
+#line 424 "src/parse-gram.y" /* yacc.c:1647  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].uniqstr),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2331 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2326 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 44:
-#line 431 "src/parse-gram.y" /* yacc.c:1651  */
+#line 431 "src/parse-gram.y" /* yacc.c:1647  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2341 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2336 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 45:
-#line 442 "src/parse-gram.y" /* yacc.c:1651  */
+#line 442 "src/parse-gram.y" /* yacc.c:1647  */
     { current_class = nterm_sym; }
-#line 2347 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2342 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 46:
-#line 443 "src/parse-gram.y" /* yacc.c:1651  */
+#line 443 "src/parse-gram.y" /* yacc.c:1647  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2356 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2351 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 47:
-#line 447 "src/parse-gram.y" /* yacc.c:1651  */
+#line 447 "src/parse-gram.y" /* yacc.c:1647  */
     { current_class = token_sym; }
-#line 2362 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2357 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 48:
-#line 448 "src/parse-gram.y" /* yacc.c:1651  */
+#line 448 "src/parse-gram.y" /* yacc.c:1647  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2371 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2366 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 49:
-#line 453 "src/parse-gram.y" /* yacc.c:1651  */
+#line 453 "src/parse-gram.y" /* yacc.c:1647  */
     {
       tag_seen = true;
       for (symbol_list *list = (yyvsp[0].list); list; list = list->next)
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2382 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2377 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 50:
-#line 463 "src/parse-gram.y" /* yacc.c:1651  */
+#line 463 "src/parse-gram.y" /* yacc.c:1647  */
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].list); list; list = list->next)
@@ -2393,341 +2388,341 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2397 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2392 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 51:
-#line 476 "src/parse-gram.y" /* yacc.c:1651  */
+#line 476 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.assoc) = left_assoc; }
-#line 2403 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2398 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 52:
-#line 477 "src/parse-gram.y" /* yacc.c:1651  */
+#line 477 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.assoc) = right_assoc; }
-#line 2409 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2404 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 53:
-#line 478 "src/parse-gram.y" /* yacc.c:1651  */
+#line 478 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.assoc) = non_assoc; }
-#line 2415 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2410 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 54:
-#line 479 "src/parse-gram.y" /* yacc.c:1651  */
+#line 479 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2421 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2416 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 55:
-#line 483 "src/parse-gram.y" /* yacc.c:1651  */
+#line 483 "src/parse-gram.y" /* yacc.c:1647  */
     { current_type = NULL; }
-#line 2427 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2422 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 56:
-#line 484 "src/parse-gram.y" /* yacc.c:1651  */
+#line 484 "src/parse-gram.y" /* yacc.c:1647  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2433 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2428 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 57:
-#line 490 "src/parse-gram.y" /* yacc.c:1651  */
+#line 490 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2439 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2434 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 58:
-#line 492 "src/parse-gram.y" /* yacc.c:1651  */
+#line 492 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2445 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2440 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 59:
-#line 497 "src/parse-gram.y" /* yacc.c:1651  */
+#line 497 "src/parse-gram.y" /* yacc.c:1647  */
     {
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2454 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2449 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 60:
-#line 502 "src/parse-gram.y" /* yacc.c:1651  */
+#line 502 "src/parse-gram.y" /* yacc.c:1647  */
     {
       (yyval.symbol) = (yyvsp[-1].symbol);
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2464 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2459 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 61:
-#line 512 "src/parse-gram.y" /* yacc.c:1651  */
+#line 512 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2470 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2465 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 62:
-#line 514 "src/parse-gram.y" /* yacc.c:1651  */
+#line 514 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2476 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2471 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 63:
-#line 518 "src/parse-gram.y" /* yacc.c:1651  */
+#line 518 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2482 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2477 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 64:
-#line 519 "src/parse-gram.y" /* yacc.c:1651  */
+#line 519 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2488 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2483 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 65:
-#line 523 "src/parse-gram.y" /* yacc.c:1651  */
+#line 523 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2494 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2489 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 66:
-#line 524 "src/parse-gram.y" /* yacc.c:1651  */
+#line 524 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2500 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2495 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 68:
-#line 529 "src/parse-gram.y" /* yacc.c:1651  */
+#line 529 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2506 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2501 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 69:
-#line 530 "src/parse-gram.y" /* yacc.c:1651  */
+#line 530 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2512 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2507 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 70:
-#line 536 "src/parse-gram.y" /* yacc.c:1651  */
+#line 536 "src/parse-gram.y" /* yacc.c:1647  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2521 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2516 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 71:
-#line 541 "src/parse-gram.y" /* yacc.c:1651  */
+#line 541 "src/parse-gram.y" /* yacc.c:1647  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2530 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2525 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 72:
-#line 546 "src/parse-gram.y" /* yacc.c:1651  */
+#line 546 "src/parse-gram.y" /* yacc.c:1647  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2540 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2535 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 73:
-#line 552 "src/parse-gram.y" /* yacc.c:1651  */
+#line 552 "src/parse-gram.y" /* yacc.c:1647  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2550 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2545 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 74:
-#line 558 "src/parse-gram.y" /* yacc.c:1651  */
+#line 558 "src/parse-gram.y" /* yacc.c:1647  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2561 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2556 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 81:
-#line 588 "src/parse-gram.y" /* yacc.c:1651  */
+#line 588 "src/parse-gram.y" /* yacc.c:1647  */
     {
       yyerrok;
     }
-#line 2569 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2564 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 82:
-#line 594 "src/parse-gram.y" /* yacc.c:1651  */
+#line 594 "src/parse-gram.y" /* yacc.c:1647  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2575 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2570 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 83:
-#line 595 "src/parse-gram.y" /* yacc.c:1651  */
+#line 595 "src/parse-gram.y" /* yacc.c:1647  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2584 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2579 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 84:
-#line 602 "src/parse-gram.y" /* yacc.c:1651  */
+#line 602 "src/parse-gram.y" /* yacc.c:1647  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2590 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2585 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 85:
-#line 603 "src/parse-gram.y" /* yacc.c:1651  */
+#line 603 "src/parse-gram.y" /* yacc.c:1647  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2596 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2591 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 87:
-#line 610 "src/parse-gram.y" /* yacc.c:1651  */
+#line 610 "src/parse-gram.y" /* yacc.c:1647  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2603 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2598 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 88:
-#line 613 "src/parse-gram.y" /* yacc.c:1651  */
+#line 613 "src/parse-gram.y" /* yacc.c:1647  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2609 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2604 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 89:
-#line 615 "src/parse-gram.y" /* yacc.c:1651  */
+#line 615 "src/parse-gram.y" /* yacc.c:1647  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), current_type); }
-#line 2615 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2610 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 90:
-#line 617 "src/parse-gram.y" /* yacc.c:1651  */
+#line 617 "src/parse-gram.y" /* yacc.c:1647  */
     { grammar_current_rule_predicate_append ((yyvsp[0].code), (yylsp[0])); }
-#line 2621 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2616 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 91:
-#line 619 "src/parse-gram.y" /* yacc.c:1651  */
+#line 619 "src/parse-gram.y" /* yacc.c:1647  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2627 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2622 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 92:
-#line 621 "src/parse-gram.y" /* yacc.c:1651  */
+#line 621 "src/parse-gram.y" /* yacc.c:1647  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2633 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2628 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 93:
-#line 623 "src/parse-gram.y" /* yacc.c:1651  */
+#line 623 "src/parse-gram.y" /* yacc.c:1647  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2639 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2634 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 94:
-#line 625 "src/parse-gram.y" /* yacc.c:1651  */
+#line 625 "src/parse-gram.y" /* yacc.c:1647  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2645 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2640 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 95:
-#line 629 "src/parse-gram.y" /* yacc.c:1651  */
+#line 629 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.named_ref) = 0; }
-#line 2651 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2646 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 96:
-#line 630 "src/parse-gram.y" /* yacc.c:1651  */
+#line 630 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2657 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2652 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 98:
-#line 641 "src/parse-gram.y" /* yacc.c:1651  */
+#line 641 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].code)); }
-#line 2663 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2658 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 99:
-#line 666 "src/parse-gram.y" /* yacc.c:1651  */
+#line 666 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2669 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2664 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 100:
-#line 667 "src/parse-gram.y" /* yacc.c:1651  */
+#line 667 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2675 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2670 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 101:
-#line 668 "src/parse-gram.y" /* yacc.c:1651  */
+#line 668 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].code); }
-#line 2681 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2676 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 102:
-#line 669 "src/parse-gram.y" /* yacc.c:1651  */
+#line 669 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].code)); }
-#line 2687 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2682 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 103:
-#line 682 "src/parse-gram.y" /* yacc.c:1651  */
+#line 682 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2693 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2688 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 104:
-#line 684 "src/parse-gram.y" /* yacc.c:1651  */
+#line 684 "src/parse-gram.y" /* yacc.c:1647  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2703 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2698 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 105:
-#line 692 "src/parse-gram.y" /* yacc.c:1651  */
+#line 692 "src/parse-gram.y" /* yacc.c:1647  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2709 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2704 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 108:
-#line 704 "src/parse-gram.y" /* yacc.c:1651  */
+#line 704 "src/parse-gram.y" /* yacc.c:1647  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].code)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2718 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2713 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
   case 110:
-#line 713 "src/parse-gram.y" /* yacc.c:1651  */
+#line 713 "src/parse-gram.y" /* yacc.c:1647  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2727 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2722 "src/parse-gram.c" /* yacc.c:1647  */
     break;
 
 
-#line 2731 "src/parse-gram.c" /* yacc.c:1651  */
+#line 2726 "src/parse-gram.c" /* yacc.c:1647  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2973,7 +2968,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 719 "src/parse-gram.y" /* yacc.c:1910  */
+#line 719 "src/parse-gram.y" /* yacc.c:1906  */
 
 
 /* Return the location of the left-hand side of a rule whose
