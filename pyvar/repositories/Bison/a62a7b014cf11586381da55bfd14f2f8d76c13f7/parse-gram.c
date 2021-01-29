@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.7.90.  */
+/* A Bison parser, made by GNU Bison 3.0.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.7.90"
+#define YYBISON_VERSION "3.0"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -59,12 +59,12 @@
 #define YYPULL 1
 
 /* "%code top" blocks.  */
-#line 27 "src/parse-gram.y" /* yacc.c:333  */
+#line 27 "src/parse-gram.y" /* yacc.c:316  */
 
   /* On column 0 to please syntax-check.  */
 #include <config.h>
 
-#line 68 "src/parse-gram.c" /* yacc.c:333  */
+#line 68 "src/parse-gram.c" /* yacc.c:316  */
 /* Substitute the type names.  */
 #define YYSTYPE         GRAM_STYPE
 #define YYLTYPE         GRAM_LTYPE
@@ -78,7 +78,7 @@
 
 /* Copy the first part of user declarations.  */
 
-#line 82 "src/parse-gram.c" /* yacc.c:356  */
+#line 82 "src/parse-gram.c" /* yacc.c:339  */
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -116,11 +116,11 @@
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-#line 21 "src/parse-gram.y" /* yacc.c:372  */
+#line 21 "src/parse-gram.y" /* yacc.c:355  */
 
   #include "symlist.h"
   #include "symtab.h"
-#line 221 "src/parse-gram.y" /* yacc.c:372  */
+#line 221 "src/parse-gram.y" /* yacc.c:355  */
 
   typedef enum
   {
@@ -129,10 +129,10 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 645 "src/parse-gram.y" /* yacc.c:372  */
+#line 645 "src/parse-gram.y" /* yacc.c:355  */
 #include "muscle-tab.h"
 
-#line 136 "src/parse-gram.c" /* yacc.c:372  */
+#line 136 "src/parse-gram.c" /* yacc.c:355  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -203,27 +203,27 @@ extern int gram_debug;
 typedef union GRAM_STYPE GRAM_STYPE;
 union GRAM_STYPE
 {
-#line 182 "src/parse-gram.y" /* yacc.c:372  */
+#line 182 "src/parse-gram.y" /* yacc.c:355  */
 unsigned char character;
-#line 186 "src/parse-gram.y" /* yacc.c:372  */
+#line 186 "src/parse-gram.y" /* yacc.c:355  */
 char *code;
-#line 191 "src/parse-gram.y" /* yacc.c:372  */
+#line 191 "src/parse-gram.y" /* yacc.c:355  */
 uniqstr uniqstr;
-#line 199 "src/parse-gram.y" /* yacc.c:372  */
+#line 199 "src/parse-gram.y" /* yacc.c:355  */
 int integer;
-#line 203 "src/parse-gram.y" /* yacc.c:372  */
+#line 203 "src/parse-gram.y" /* yacc.c:355  */
 symbol *symbol;
-#line 208 "src/parse-gram.y" /* yacc.c:372  */
+#line 208 "src/parse-gram.y" /* yacc.c:355  */
 assoc assoc;
-#line 211 "src/parse-gram.y" /* yacc.c:372  */
+#line 211 "src/parse-gram.y" /* yacc.c:355  */
 symbol_list *list;
-#line 214 "src/parse-gram.y" /* yacc.c:372  */
+#line 214 "src/parse-gram.y" /* yacc.c:355  */
 named_ref *named_ref;
-#line 241 "src/parse-gram.y" /* yacc.c:372  */
+#line 241 "src/parse-gram.y" /* yacc.c:355  */
 param_type param;
-#line 409 "src/parse-gram.y" /* yacc.c:372  */
+#line 409 "src/parse-gram.y" /* yacc.c:355  */
 code_props_type code_type;
-#line 647 "src/parse-gram.y" /* yacc.c:372  */
+#line 647 "src/parse-gram.y" /* yacc.c:355  */
 
   struct
   {
@@ -231,7 +231,7 @@ code_props_type code_type;
     muscle_kind kind;
   } value;
 
-#line 235 "src/parse-gram.c" /* yacc.c:372  */
+#line 235 "src/parse-gram.c" /* yacc.c:355  */
 };
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
@@ -259,9 +259,9 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 263 "src/parse-gram.c" /* yacc.c:375  */
+#line 263 "src/parse-gram.c" /* yacc.c:358  */
 /* Unqualified %code blocks.  */
-#line 33 "src/parse-gram.y" /* yacc.c:376  */
+#line 33 "src/parse-gram.y" /* yacc.c:359  */
 
   #include "system.h"
 
@@ -324,7 +324,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 231 "src/parse-gram.y" /* yacc.c:376  */
+#line 231 "src/parse-gram.y" /* yacc.c:359  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -335,7 +335,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 339 "src/parse-gram.c" /* yacc.c:376  */
+#line 339 "src/parse-gram.c" /* yacc.c:359  */
 
 #ifdef short
 # undef short
@@ -407,6 +407,25 @@ typedef short int yytype_int16;
 # define YYUSE(E) /* empty */
 #endif
 
+#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
+/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
+# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
+    _Pragma ("GCC diagnostic push") \
+    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
+    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
+# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
+    _Pragma ("GCC diagnostic pop")
+#else
+# define YY_INITIAL_VALUE(Value) Value
+#endif
+#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
+# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
+# define YY_IGNORE_MAYBE_UNINITIALIZED_END
+#endif
+#ifndef YY_INITIAL_VALUE
+# define YY_INITIAL_VALUE(Value) /* Nothing. */
+#endif
+
 
 #if 1
 
@@ -943,9 +962,9 @@ do {                                                                      \
 } while (0)
 
 
-/*--------------------------------.
-| Print this symbol on YYOUTPUT.  |
-`--------------------------------*/
+/*----------------------------------------.
+| Print this symbol's value on YYOUTPUT.  |
+`----------------------------------------*/
 
 static void
 yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
@@ -962,79 +981,79 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
           case 3: /* "string"  */
-#line 188 "src/parse-gram.y" /* yacc.c:701  */
+#line 188 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).code)), yyo); }
-#line 968 "src/parse-gram.c" /* yacc.c:701  */
+#line 987 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 23: /* "%<flag>"  */
-#line 196 "src/parse-gram.y" /* yacc.c:701  */
+#line 196 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 974 "src/parse-gram.c" /* yacc.c:701  */
+#line 993 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 39: /* "{...}"  */
-#line 189 "src/parse-gram.y" /* yacc.c:701  */
+#line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 980 "src/parse-gram.c" /* yacc.c:701  */
+#line 999 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 40: /* "%?{...}"  */
-#line 189 "src/parse-gram.y" /* yacc.c:701  */
+#line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 986 "src/parse-gram.c" /* yacc.c:701  */
+#line 1005 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 41: /* "[identifier]"  */
-#line 194 "src/parse-gram.y" /* yacc.c:701  */
+#line 194 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 992 "src/parse-gram.c" /* yacc.c:701  */
+#line 1011 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 42: /* "char"  */
-#line 184 "src/parse-gram.y" /* yacc.c:701  */
+#line 184 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 998 "src/parse-gram.c" /* yacc.c:701  */
+#line 1017 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 43: /* "epilogue"  */
-#line 189 "src/parse-gram.y" /* yacc.c:701  */
+#line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1004 "src/parse-gram.c" /* yacc.c:701  */
+#line 1023 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 45: /* "identifier"  */
-#line 193 "src/parse-gram.y" /* yacc.c:701  */
+#line 193 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1010 "src/parse-gram.c" /* yacc.c:701  */
+#line 1029 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 46: /* "identifier:"  */
-#line 195 "src/parse-gram.y" /* yacc.c:701  */
+#line 195 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1016 "src/parse-gram.c" /* yacc.c:701  */
+#line 1035 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 49: /* "%{...%}"  */
-#line 189 "src/parse-gram.y" /* yacc.c:701  */
+#line 189 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 1022 "src/parse-gram.c" /* yacc.c:701  */
+#line 1041 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 51: /* "<tag>"  */
-#line 197 "src/parse-gram.y" /* yacc.c:701  */
+#line 197 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1028 "src/parse-gram.c" /* yacc.c:701  */
+#line 1047 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 54: /* "integer"  */
-#line 201 "src/parse-gram.y" /* yacc.c:701  */
+#line 201 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1034 "src/parse-gram.c" /* yacc.c:701  */
+#line 1053 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 55: /* "%param"  */
-#line 244 "src/parse-gram.y" /* yacc.c:701  */
+#line 244 "src/parse-gram.y" /* yacc.c:684  */
       {
   switch (((*yyvaluep).param))
     {
@@ -1047,35 +1066,35 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1051 "src/parse-gram.c" /* yacc.c:701  */
+#line 1070 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 65: /* code_props_type  */
-#line 410 "src/parse-gram.y" /* yacc.c:701  */
+#line 410 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1057 "src/parse-gram.c" /* yacc.c:701  */
+#line 1076 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 74: /* symbol.prec  */
-#line 205 "src/parse-gram.y" /* yacc.c:701  */
+#line 205 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1063 "src/parse-gram.c" /* yacc.c:701  */
+#line 1082 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 78: /* tag  */
-#line 197 "src/parse-gram.y" /* yacc.c:701  */
+#line 197 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1069 "src/parse-gram.c" /* yacc.c:701  */
+#line 1088 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 88: /* variable  */
-#line 193 "src/parse-gram.y" /* yacc.c:701  */
+#line 193 "src/parse-gram.y" /* yacc.c:684  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1075 "src/parse-gram.c" /* yacc.c:701  */
+#line 1094 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 89: /* value  */
-#line 656 "src/parse-gram.y" /* yacc.c:701  */
+#line 656 "src/parse-gram.y" /* yacc.c:684  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1084,31 +1103,31 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1088 "src/parse-gram.c" /* yacc.c:701  */
+#line 1107 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 90: /* id  */
-#line 205 "src/parse-gram.y" /* yacc.c:701  */
+#line 205 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1094 "src/parse-gram.c" /* yacc.c:701  */
+#line 1113 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 91: /* id_colon  */
-#line 206 "src/parse-gram.y" /* yacc.c:701  */
+#line 206 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1100 "src/parse-gram.c" /* yacc.c:701  */
+#line 1119 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 92: /* symbol  */
-#line 205 "src/parse-gram.y" /* yacc.c:701  */
+#line 205 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1106 "src/parse-gram.c" /* yacc.c:701  */
+#line 1125 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
     case 93: /* string_as_id  */
-#line 205 "src/parse-gram.y" /* yacc.c:701  */
+#line 205 "src/parse-gram.y" /* yacc.c:684  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1112 "src/parse-gram.c" /* yacc.c:701  */
+#line 1131 "src/parse-gram.c" /* yacc.c:684  */
         break;
 
 
@@ -1689,7 +1708,9 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
     yymsg = "Deleting";
   YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);
 
+  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
   YYUSE (yytype);
+  YY_IGNORE_MAYBE_UNINITIALIZED_END
 }
 
 
@@ -1706,40 +1727,20 @@ yyparse (void)
 int yychar;
 
 
-#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
-/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
-# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
-    _Pragma ("GCC diagnostic push") \
-    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
-    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
-# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
-    _Pragma ("GCC diagnostic pop")
-#else
+/* The semantic value of the lookahead symbol.  */
 /* Default value used for initialization, for pacifying older GCCs
    or non-GCC compilers.  */
-static YYSTYPE yyval_default;
-# define YY_INITIAL_VALUE(Value) = Value
-#endif
+YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
+YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);
+
+/* Location data for the lookahead symbol.  */
 static YYLTYPE yyloc_default
 # if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
   = { 1, 1, 1, 1 }
 # endif
 ;
-#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
-# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
-# define YY_IGNORE_MAYBE_UNINITIALIZED_END
-#endif
-#ifndef YY_INITIAL_VALUE
-# define YY_INITIAL_VALUE(Value) /* Nothing. */
-#endif
-
-/* The semantic value of the lookahead symbol.  */
-YYSTYPE yylval YY_INITIAL_VALUE (yyval_default);
-
-/* Location data for the lookahead symbol.  */
 YYLTYPE yylloc = yyloc_default;
 
-
     /* Number of syntax errors so far.  */
     int yynerrs;
 
@@ -1820,7 +1821,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 108 "src/parse-gram.y" /* yacc.c:1446  */
+#line 108 "src/parse-gram.y" /* yacc.c:1429  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1828,7 +1829,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1832 "src/parse-gram.c" /* yacc.c:1446  */
+#line 1833 "src/parse-gram.c" /* yacc.c:1429  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2022,143 +2023,143 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 280 "src/parse-gram.y" /* yacc.c:1663  */
+#line 280 "src/parse-gram.y" /* yacc.c:1646  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2032 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2033 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 7:
-#line 286 "src/parse-gram.y" /* yacc.c:1663  */
+#line 286 "src/parse-gram.y" /* yacc.c:1646  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2040 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2041 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 8:
-#line 290 "src/parse-gram.y" /* yacc.c:1663  */
+#line 290 "src/parse-gram.y" /* yacc.c:1646  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2049 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2050 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 9:
-#line 294 "src/parse-gram.y" /* yacc.c:1663  */
+#line 294 "src/parse-gram.y" /* yacc.c:1646  */
     { defines_flag = true; }
-#line 2055 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2056 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 10:
-#line 296 "src/parse-gram.y" /* yacc.c:1663  */
+#line 296 "src/parse-gram.y" /* yacc.c:1646  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].code));
     }
-#line 2064 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2065 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 11:
-#line 301 "src/parse-gram.y" /* yacc.c:1663  */
+#line 301 "src/parse-gram.y" /* yacc.c:1646  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2074 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2075 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 12:
-#line 306 "src/parse-gram.y" /* yacc.c:1663  */
+#line 306 "src/parse-gram.y" /* yacc.c:1646  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2080 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2081 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 13:
-#line 307 "src/parse-gram.y" /* yacc.c:1663  */
+#line 307 "src/parse-gram.y" /* yacc.c:1646  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2086 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2087 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 14:
-#line 308 "src/parse-gram.y" /* yacc.c:1663  */
+#line 308 "src/parse-gram.y" /* yacc.c:1646  */
     { spec_file_prefix = (yyvsp[0].code); }
-#line 2092 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2093 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 15:
-#line 310 "src/parse-gram.y" /* yacc.c:1663  */
+#line 310 "src/parse-gram.y" /* yacc.c:1646  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2101 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2102 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 16:
-#line 315 "src/parse-gram.y" /* yacc.c:1663  */
+#line 315 "src/parse-gram.y" /* yacc.c:1646  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].code), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2110 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2111 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 17:
-#line 319 "src/parse-gram.y" /* yacc.c:1663  */
+#line 319 "src/parse-gram.y" /* yacc.c:1646  */
     { language_argmatch ((yyvsp[0].code), grammar_prio, (yylsp[-1])); }
-#line 2116 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2117 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 18:
-#line 320 "src/parse-gram.y" /* yacc.c:1663  */
+#line 320 "src/parse-gram.y" /* yacc.c:1646  */
     { spec_name_prefix = (yyvsp[0].code); }
-#line 2122 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2123 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 19:
-#line 321 "src/parse-gram.y" /* yacc.c:1663  */
+#line 321 "src/parse-gram.y" /* yacc.c:1646  */
     { no_lines_flag = true; }
-#line 2128 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2129 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 20:
-#line 322 "src/parse-gram.y" /* yacc.c:1663  */
+#line 322 "src/parse-gram.y" /* yacc.c:1646  */
     { nondeterministic_parser = true; }
-#line 2134 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2135 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 21:
-#line 323 "src/parse-gram.y" /* yacc.c:1663  */
+#line 323 "src/parse-gram.y" /* yacc.c:1646  */
     { spec_outfile = (yyvsp[0].code); }
-#line 2140 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2141 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 22:
-#line 324 "src/parse-gram.y" /* yacc.c:1663  */
+#line 324 "src/parse-gram.y" /* yacc.c:1646  */
     { current_param = (yyvsp[0].param); }
-#line 2146 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2147 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 23:
-#line 324 "src/parse-gram.y" /* yacc.c:1663  */
+#line 324 "src/parse-gram.y" /* yacc.c:1646  */
     { current_param = param_none; }
-#line 2152 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2153 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 24:
-#line 325 "src/parse-gram.y" /* yacc.c:1663  */
+#line 325 "src/parse-gram.y" /* yacc.c:1646  */
     { version_check (&(yylsp[0]), (yyvsp[0].code)); }
-#line 2158 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2159 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 25:
-#line 327 "src/parse-gram.y" /* yacc.c:1663  */
+#line 327 "src/parse-gram.y" /* yacc.c:1646  */
     {
       char const *skeleton_user = (yyvsp[0].code);
       if (strchr (skeleton_user, '/'))
@@ -2182,49 +2183,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2186 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2187 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 26:
-#line 350 "src/parse-gram.y" /* yacc.c:1663  */
+#line 350 "src/parse-gram.y" /* yacc.c:1646  */
     { token_table_flag = true; }
-#line 2192 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2193 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 27:
-#line 351 "src/parse-gram.y" /* yacc.c:1663  */
+#line 351 "src/parse-gram.y" /* yacc.c:1646  */
     { report_flag |= report_states; }
-#line 2198 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2199 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 28:
-#line 352 "src/parse-gram.y" /* yacc.c:1663  */
+#line 352 "src/parse-gram.y" /* yacc.c:1646  */
     { yacc_flag = true; }
-#line 2204 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2205 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 30:
-#line 357 "src/parse-gram.y" /* yacc.c:1663  */
+#line 357 "src/parse-gram.y" /* yacc.c:1646  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2210 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2211 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 31:
-#line 358 "src/parse-gram.y" /* yacc.c:1663  */
+#line 358 "src/parse-gram.y" /* yacc.c:1646  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2216 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2217 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 34:
-#line 370 "src/parse-gram.y" /* yacc.c:1663  */
+#line 370 "src/parse-gram.y" /* yacc.c:1646  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2224 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2225 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 35:
-#line 374 "src/parse-gram.y" /* yacc.c:1663  */
+#line 374 "src/parse-gram.y" /* yacc.c:1646  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2236,27 +2237,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2240 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2241 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 36:
-#line 386 "src/parse-gram.y" /* yacc.c:1663  */
+#line 386 "src/parse-gram.y" /* yacc.c:1646  */
     {
       default_prec = true;
     }
-#line 2248 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2249 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 37:
-#line 390 "src/parse-gram.y" /* yacc.c:1663  */
+#line 390 "src/parse-gram.y" /* yacc.c:1646  */
     {
       default_prec = false;
     }
-#line 2256 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2257 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 38:
-#line 394 "src/parse-gram.y" /* yacc.c:1663  */
+#line 394 "src/parse-gram.y" /* yacc.c:1646  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2264,84 +2265,84 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2268 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2269 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 39:
-#line 402 "src/parse-gram.y" /* yacc.c:1663  */
+#line 402 "src/parse-gram.y" /* yacc.c:1646  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2277 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2278 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 40:
-#line 412 "src/parse-gram.y" /* yacc.c:1663  */
+#line 412 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.code_type) = destructor; }
-#line 2283 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2284 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 41:
-#line 413 "src/parse-gram.y" /* yacc.c:1663  */
+#line 413 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.code_type) = printer; }
-#line 2289 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2290 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 42:
-#line 423 "src/parse-gram.y" /* yacc.c:1663  */
+#line 423 "src/parse-gram.y" /* yacc.c:1646  */
     {}
-#line 2295 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2296 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 43:
-#line 424 "src/parse-gram.y" /* yacc.c:1663  */
+#line 424 "src/parse-gram.y" /* yacc.c:1646  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2301 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2302 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 44:
-#line 429 "src/parse-gram.y" /* yacc.c:1663  */
+#line 429 "src/parse-gram.y" /* yacc.c:1646  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].code), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2311 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2312 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 45:
-#line 440 "src/parse-gram.y" /* yacc.c:1663  */
+#line 440 "src/parse-gram.y" /* yacc.c:1646  */
     { current_class = nterm_sym; }
-#line 2317 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2318 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 46:
-#line 441 "src/parse-gram.y" /* yacc.c:1663  */
+#line 441 "src/parse-gram.y" /* yacc.c:1646  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2326 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2327 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 47:
-#line 445 "src/parse-gram.y" /* yacc.c:1663  */
+#line 445 "src/parse-gram.y" /* yacc.c:1646  */
     { current_class = token_sym; }
-#line 2332 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2333 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 48:
-#line 446 "src/parse-gram.y" /* yacc.c:1663  */
+#line 446 "src/parse-gram.y" /* yacc.c:1646  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2341 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2342 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 49:
-#line 451 "src/parse-gram.y" /* yacc.c:1663  */
+#line 451 "src/parse-gram.y" /* yacc.c:1646  */
     {
       symbol_list *list;
       tag_seen = true;
@@ -2349,11 +2350,11 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2353 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2354 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 50:
-#line 462 "src/parse-gram.y" /* yacc.c:1663  */
+#line 462 "src/parse-gram.y" /* yacc.c:1646  */
     {
       symbol_list *list;
       ++current_prec;
@@ -2365,341 +2366,341 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2369 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2370 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 51:
-#line 476 "src/parse-gram.y" /* yacc.c:1663  */
+#line 476 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.assoc) = left_assoc; }
-#line 2375 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2376 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 52:
-#line 477 "src/parse-gram.y" /* yacc.c:1663  */
+#line 477 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.assoc) = right_assoc; }
-#line 2381 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2382 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 53:
-#line 478 "src/parse-gram.y" /* yacc.c:1663  */
+#line 478 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.assoc) = non_assoc; }
-#line 2387 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2388 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 54:
-#line 479 "src/parse-gram.y" /* yacc.c:1663  */
+#line 479 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2393 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2394 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 55:
-#line 483 "src/parse-gram.y" /* yacc.c:1663  */
+#line 483 "src/parse-gram.y" /* yacc.c:1646  */
     { current_type = NULL; }
-#line 2399 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2400 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 56:
-#line 484 "src/parse-gram.y" /* yacc.c:1663  */
+#line 484 "src/parse-gram.y" /* yacc.c:1646  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2405 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2406 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 57:
-#line 490 "src/parse-gram.y" /* yacc.c:1663  */
+#line 490 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2411 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2412 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 58:
-#line 492 "src/parse-gram.y" /* yacc.c:1663  */
+#line 492 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2417 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2418 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 59:
-#line 497 "src/parse-gram.y" /* yacc.c:1663  */
+#line 497 "src/parse-gram.y" /* yacc.c:1646  */
     {
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2426 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2427 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 60:
-#line 502 "src/parse-gram.y" /* yacc.c:1663  */
+#line 502 "src/parse-gram.y" /* yacc.c:1646  */
     {
       (yyval.symbol) = (yyvsp[-1].symbol);
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2436 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2437 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 61:
-#line 512 "src/parse-gram.y" /* yacc.c:1663  */
+#line 512 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2442 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2443 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 62:
-#line 514 "src/parse-gram.y" /* yacc.c:1663  */
+#line 514 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2448 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2449 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 63:
-#line 518 "src/parse-gram.y" /* yacc.c:1663  */
+#line 518 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2454 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2455 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 64:
-#line 519 "src/parse-gram.y" /* yacc.c:1663  */
+#line 519 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2460 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2461 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 65:
-#line 523 "src/parse-gram.y" /* yacc.c:1663  */
+#line 523 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2466 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2467 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 66:
-#line 524 "src/parse-gram.y" /* yacc.c:1663  */
+#line 524 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2472 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2473 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 68:
-#line 529 "src/parse-gram.y" /* yacc.c:1663  */
+#line 529 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2478 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2479 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 69:
-#line 530 "src/parse-gram.y" /* yacc.c:1663  */
+#line 530 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2484 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2485 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 70:
-#line 536 "src/parse-gram.y" /* yacc.c:1663  */
+#line 536 "src/parse-gram.y" /* yacc.c:1646  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2493 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2494 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 71:
-#line 541 "src/parse-gram.y" /* yacc.c:1663  */
+#line 541 "src/parse-gram.y" /* yacc.c:1646  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2502 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2503 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 72:
-#line 546 "src/parse-gram.y" /* yacc.c:1663  */
+#line 546 "src/parse-gram.y" /* yacc.c:1646  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2512 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2513 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 73:
-#line 552 "src/parse-gram.y" /* yacc.c:1663  */
+#line 552 "src/parse-gram.y" /* yacc.c:1646  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2522 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2523 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 74:
-#line 558 "src/parse-gram.y" /* yacc.c:1663  */
+#line 558 "src/parse-gram.y" /* yacc.c:1646  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2533 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2534 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 81:
-#line 588 "src/parse-gram.y" /* yacc.c:1663  */
+#line 588 "src/parse-gram.y" /* yacc.c:1646  */
     {
       yyerrok;
     }
-#line 2541 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2542 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 82:
-#line 594 "src/parse-gram.y" /* yacc.c:1663  */
+#line 594 "src/parse-gram.y" /* yacc.c:1646  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2547 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2548 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 83:
-#line 595 "src/parse-gram.y" /* yacc.c:1663  */
+#line 595 "src/parse-gram.y" /* yacc.c:1646  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2556 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2557 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 84:
-#line 602 "src/parse-gram.y" /* yacc.c:1663  */
+#line 602 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2562 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2563 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 85:
-#line 603 "src/parse-gram.y" /* yacc.c:1663  */
+#line 603 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2568 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2569 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 87:
-#line 610 "src/parse-gram.y" /* yacc.c:1663  */
+#line 610 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2575 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2576 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 88:
-#line 613 "src/parse-gram.y" /* yacc.c:1663  */
+#line 613 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2581 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2582 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 89:
-#line 615 "src/parse-gram.y" /* yacc.c:1663  */
+#line 615 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2587 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2588 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 90:
-#line 617 "src/parse-gram.y" /* yacc.c:1663  */
+#line 617 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2593 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2594 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 91:
-#line 619 "src/parse-gram.y" /* yacc.c:1663  */
+#line 619 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2599 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2600 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 92:
-#line 621 "src/parse-gram.y" /* yacc.c:1663  */
+#line 621 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2605 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2606 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 93:
-#line 623 "src/parse-gram.y" /* yacc.c:1663  */
+#line 623 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2611 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2612 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 94:
-#line 625 "src/parse-gram.y" /* yacc.c:1663  */
+#line 625 "src/parse-gram.y" /* yacc.c:1646  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2617 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2618 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 95:
-#line 629 "src/parse-gram.y" /* yacc.c:1663  */
+#line 629 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.named_ref) = 0; }
-#line 2623 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2624 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 96:
-#line 630 "src/parse-gram.y" /* yacc.c:1663  */
+#line 630 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.named_ref) = named_ref_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2629 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2630 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 98:
-#line 641 "src/parse-gram.y" /* yacc.c:1663  */
+#line 641 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].code)); }
-#line 2635 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2636 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 99:
-#line 666 "src/parse-gram.y" /* yacc.c:1663  */
+#line 666 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2641 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2642 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 100:
-#line 667 "src/parse-gram.y" /* yacc.c:1663  */
+#line 667 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2647 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2648 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 101:
-#line 668 "src/parse-gram.y" /* yacc.c:1663  */
+#line 668 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].code); }
-#line 2653 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2654 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 102:
-#line 669 "src/parse-gram.y" /* yacc.c:1663  */
+#line 669 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].code)); }
-#line 2659 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2660 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 103:
-#line 682 "src/parse-gram.y" /* yacc.c:1663  */
+#line 682 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2665 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2666 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 104:
-#line 684 "src/parse-gram.y" /* yacc.c:1663  */
+#line 684 "src/parse-gram.y" /* yacc.c:1646  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2675 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2676 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 105:
-#line 692 "src/parse-gram.y" /* yacc.c:1663  */
+#line 692 "src/parse-gram.y" /* yacc.c:1646  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2681 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2682 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 108:
-#line 704 "src/parse-gram.y" /* yacc.c:1663  */
+#line 704 "src/parse-gram.y" /* yacc.c:1646  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].code)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2690 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2691 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
   case 110:
-#line 713 "src/parse-gram.y" /* yacc.c:1663  */
+#line 713 "src/parse-gram.y" /* yacc.c:1646  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].code), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2699 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2700 "src/parse-gram.c" /* yacc.c:1646  */
     break;
 
 
-#line 2703 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2704 "src/parse-gram.c" /* yacc.c:1646  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2946,7 +2947,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 719 "src/parse-gram.y" /* yacc.c:1923  */
+#line 719 "src/parse-gram.y" /* yacc.c:1906  */
 
 
 /* Return the location of the left-hand side of a rule whose
