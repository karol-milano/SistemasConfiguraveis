@@ -1,9 +1,9 @@
-/* A Bison parser, made by GNU Bison 3.2.1.108-19b4e.  */
+/* A Bison parser, made by GNU Bison 3.2.90.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
-   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software
-   Foundation, Inc.
+   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
+   Inc.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.2.1.108-19b4e"
+#define YYBISON_VERSION "3.2.90"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -68,7 +68,7 @@
   /* On column 0 to please syntax-check.  */
 #include <config.h>
 
-#line 71 "src/parse-gram.c" /* yacc.c:315  */
+#line 72 "src/parse-gram.c" /* yacc.c:315  */
 /* Substitute the type names.  */
 #define YYSTYPE         GRAM_STYPE
 #define YYLTYPE         GRAM_LTYPE
@@ -125,7 +125,7 @@ extern int gram_debug;
 
   #include "symlist.h"
   #include "symtab.h"
-#line 218 "src/parse-gram.y" /* yacc.c:352  */
+#line 225 "src/parse-gram.y" /* yacc.c:352  */
 
   typedef enum
   {
@@ -134,7 +134,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 660 "src/parse-gram.y" /* yacc.c:352  */
+#line 667 "src/parse-gram.y" /* yacc.c:352  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -143,7 +143,7 @@ extern int gram_debug;
     muscle_kind kind;
   } value_type;
 
-#line 146 "src/parse-gram.c" /* yacc.c:352  */
+#line 147 "src/parse-gram.c" /* yacc.c:352  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -270,6 +270,8 @@ union GRAM_STYPE
   symbol_list* yytype_83;
   /* "%<flag>"  */
   uniqstr PERCENT_FLAG;
+  /* "%name-prefix"  */
+  uniqstr PERCENT_NAME_PREFIX;
   /* "[identifier]"  */
   uniqstr BRACKETED_ID;
   /* "identifier"  */
@@ -288,7 +290,7 @@ union GRAM_STYPE
   unsigned char CHAR;
   /* value  */
   value_type value;
-#line 291 "src/parse-gram.c" /* yacc.c:352  */
+#line 294 "src/parse-gram.c" /* yacc.c:352  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -332,8 +334,9 @@ int gram_parse (void);
   #include "named-ref.h"
   #include "quotearg.h"
   #include "reader.h"
-  #include "scan-gram.h"
   #include "scan-code.h"
+  #include "scan-gram.h"
+  #include "vasnprintf.h"
   #include "xmemdup0.h"
 
   static int current_prec = 0;
@@ -370,6 +373,10 @@ int gram_parse (void);
      string from the scanner (should be CODE). */
   static char const *translate_code_braceless (char *code, location loc);
 
+  /* Handle a %name-prefix directive.  */
+  static void do_name_prefix (location const *loc,
+                              char const *directive, char const *value);
+
   /* Handle a %require directive.  */
   static void do_require (location const *loc, char const *version);
 
@@ -385,7 +392,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 228 "src/parse-gram.y" /* yacc.c:355  */
+#line 235 "src/parse-gram.y" /* yacc.c:355  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -396,7 +403,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 399 "src/parse-gram.c" /* yacc.c:355  */
+#line 407 "src/parse-gram.c" /* yacc.c:355  */
 
 #ifdef short
 # undef short
@@ -669,19 +676,19 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   260,   260,   269,   270,   274,   275,   281,   285,   290,
-     291,   296,   297,   298,   299,   304,   309,   310,   311,   312,
-     313,   314,   314,   315,   316,   317,   318,   319,   320,   321,
-     325,   326,   335,   336,   340,   351,   355,   359,   367,   377,
-     378,   388,   389,   395,   408,   408,   413,   413,   418,   422,
-     432,   433,   434,   435,   439,   440,   445,   446,   450,   451,
-     455,   456,   457,   470,   479,   483,   487,   495,   496,   500,
-     513,   514,   526,   530,   534,   542,   544,   549,   556,   566,
-     570,   574,   582,   583,   591,   592,   598,   599,   600,   607,
-     607,   615,   616,   617,   622,   625,   627,   629,   631,   633,
-     635,   637,   639,   641,   646,   647,   656,   680,   681,   682,
-     683,   695,   697,   712,   717,   718,   723,   732,   733,   737,
-     738
+       0,   267,   267,   276,   277,   281,   282,   288,   292,   297,
+     298,   303,   304,   305,   306,   311,   316,   317,   318,   319,
+     320,   321,   321,   322,   323,   324,   325,   326,   327,   328,
+     332,   333,   342,   343,   347,   358,   362,   366,   374,   384,
+     385,   395,   396,   402,   415,   415,   420,   420,   425,   429,
+     439,   440,   441,   442,   446,   447,   452,   453,   457,   458,
+     462,   463,   464,   477,   486,   490,   494,   502,   503,   507,
+     520,   521,   533,   537,   541,   549,   551,   556,   563,   573,
+     577,   581,   589,   590,   598,   599,   605,   606,   607,   614,
+     614,   622,   623,   624,   629,   632,   634,   636,   638,   640,
+     642,   644,   646,   648,   653,   654,   663,   687,   688,   689,
+     690,   702,   704,   719,   724,   725,   730,   739,   740,   744,
+     745
 };
 #endif
 
@@ -1076,79 +1083,85 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 190 "src/parse-gram.y" /* yacc.c:680  */
+#line 195 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).STRING)), yyo); }
-#line 1081 "src/parse-gram.c" /* yacc.c:680  */
+#line 1089 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 22: /* "%<flag>"  */
-#line 197 "src/parse-gram.y" /* yacc.c:680  */
+#line 204 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
-#line 1087 "src/parse-gram.c" /* yacc.c:680  */
+#line 1095 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 27: /* "%name-prefix"  */
+#line 201 "src/parse-gram.y" /* yacc.c:680  */
+      { fputs (((*yyvaluep).PERCENT_NAME_PREFIX), yyo); }
+#line 1101 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 38: /* "{...}"  */
-#line 191 "src/parse-gram.y" /* yacc.c:680  */
+#line 196 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_CODE)); }
-#line 1093 "src/parse-gram.c" /* yacc.c:680  */
+#line 1107 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 39: /* "%?{...}"  */
-#line 191 "src/parse-gram.y" /* yacc.c:680  */
+#line 196 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_PREDICATE)); }
-#line 1099 "src/parse-gram.c" /* yacc.c:680  */
+#line 1113 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 40: /* "[identifier]"  */
-#line 195 "src/parse-gram.y" /* yacc.c:680  */
+#line 202 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
-#line 1105 "src/parse-gram.c" /* yacc.c:680  */
+#line 1119 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 41: /* "char"  */
-#line 187 "src/parse-gram.y" /* yacc.c:680  */
+#line 192 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
-#line 1111 "src/parse-gram.c" /* yacc.c:680  */
+#line 1125 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 42: /* "epilogue"  */
-#line 191 "src/parse-gram.y" /* yacc.c:680  */
+#line 196 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).EPILOGUE)); }
-#line 1117 "src/parse-gram.c" /* yacc.c:680  */
+#line 1131 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 44: /* "identifier"  */
-#line 194 "src/parse-gram.y" /* yacc.c:680  */
+#line 201 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).ID), yyo); }
-#line 1123 "src/parse-gram.c" /* yacc.c:680  */
+#line 1137 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 45: /* "identifier:"  */
-#line 196 "src/parse-gram.y" /* yacc.c:680  */
+#line 203 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
-#line 1129 "src/parse-gram.c" /* yacc.c:680  */
+#line 1143 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 48: /* "%{...%}"  */
-#line 191 "src/parse-gram.y" /* yacc.c:680  */
+#line 196 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).PROLOGUE)); }
-#line 1135 "src/parse-gram.c" /* yacc.c:680  */
+#line 1149 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 50: /* "<tag>"  */
-#line 198 "src/parse-gram.y" /* yacc.c:680  */
+#line 205 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
-#line 1141 "src/parse-gram.c" /* yacc.c:680  */
+#line 1155 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 53: /* "integer"  */
-#line 201 "src/parse-gram.y" /* yacc.c:680  */
+#line 208 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
-#line 1147 "src/parse-gram.c" /* yacc.c:680  */
+#line 1161 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 54: /* "%param"  */
-#line 240 "src/parse-gram.y" /* yacc.c:680  */
+#line 247 "src/parse-gram.y" /* yacc.c:680  */
       {
   switch (((*yyvaluep).PERCENT_PARAM))
     {
@@ -1161,107 +1174,107 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1164 "src/parse-gram.c" /* yacc.c:680  */
+#line 1178 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 64: /* code_props_type  */
-#line 375 "src/parse-gram.y" /* yacc.c:680  */
+#line 382 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
-#line 1170 "src/parse-gram.c" /* yacc.c:680  */
+#line 1184 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 70: /* tag.opt  */
-#line 194 "src/parse-gram.y" /* yacc.c:680  */
+#line 201 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).yytype_70), yyo); }
-#line 1176 "src/parse-gram.c" /* yacc.c:680  */
+#line 1190 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 71: /* generic_symlist  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
-#line 1182 "src/parse-gram.c" /* yacc.c:680  */
+#line 1196 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 72: /* generic_symlist_item  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
-#line 1188 "src/parse-gram.c" /* yacc.c:680  */
+#line 1202 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 73: /* tag  */
-#line 198 "src/parse-gram.y" /* yacc.c:680  */
+#line 205 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
-#line 1194 "src/parse-gram.c" /* yacc.c:680  */
+#line 1208 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 74: /* nterm_decls  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
-#line 1200 "src/parse-gram.c" /* yacc.c:680  */
+#line 1214 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 75: /* token_decls  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
-#line 1206 "src/parse-gram.c" /* yacc.c:680  */
+#line 1220 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 76: /* token_decl.1  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).yytype_76), yyo); }
-#line 1212 "src/parse-gram.c" /* yacc.c:680  */
+#line 1226 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 77: /* token_decl  */
-#line 204 "src/parse-gram.y" /* yacc.c:680  */
+#line 211 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
-#line 1218 "src/parse-gram.c" /* yacc.c:680  */
+#line 1232 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 78: /* int.opt  */
-#line 201 "src/parse-gram.y" /* yacc.c:680  */
+#line 208 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%d", ((*yyvaluep).yytype_78)); }
-#line 1224 "src/parse-gram.c" /* yacc.c:680  */
+#line 1238 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 79: /* token_decls_for_prec  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
-#line 1230 "src/parse-gram.c" /* yacc.c:680  */
+#line 1244 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 80: /* token_decl_for_prec.1  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).yytype_80), yyo); }
-#line 1236 "src/parse-gram.c" /* yacc.c:680  */
+#line 1250 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 81: /* token_decl_for_prec  */
-#line 204 "src/parse-gram.y" /* yacc.c:680  */
+#line 211 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
-#line 1242 "src/parse-gram.c" /* yacc.c:680  */
+#line 1256 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 82: /* symbol_decls  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
-#line 1248 "src/parse-gram.c" /* yacc.c:680  */
+#line 1262 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 83: /* symbol_decl.1  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).yytype_83), yyo); }
-#line 1254 "src/parse-gram.c" /* yacc.c:680  */
+#line 1268 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 91: /* variable  */
-#line 194 "src/parse-gram.y" /* yacc.c:680  */
+#line 201 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).variable), yyo); }
-#line 1260 "src/parse-gram.c" /* yacc.c:680  */
+#line 1274 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 92: /* value  */
-#line 670 "src/parse-gram.y" /* yacc.c:680  */
+#line 677 "src/parse-gram.y" /* yacc.c:680  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1270,37 +1283,37 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1273 "src/parse-gram.c" /* yacc.c:680  */
+#line 1287 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 93: /* id  */
-#line 204 "src/parse-gram.y" /* yacc.c:680  */
+#line 211 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
-#line 1279 "src/parse-gram.c" /* yacc.c:680  */
+#line 1293 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 94: /* id_colon  */
-#line 205 "src/parse-gram.y" /* yacc.c:680  */
+#line 212 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
-#line 1285 "src/parse-gram.c" /* yacc.c:680  */
+#line 1299 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 95: /* symbol  */
-#line 204 "src/parse-gram.y" /* yacc.c:680  */
+#line 211 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
-#line 1291 "src/parse-gram.c" /* yacc.c:680  */
+#line 1305 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 96: /* string_as_id  */
-#line 204 "src/parse-gram.y" /* yacc.c:680  */
+#line 211 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
-#line 1297 "src/parse-gram.c" /* yacc.c:680  */
+#line 1311 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 97: /* string_as_id.opt  */
-#line 204 "src/parse-gram.y" /* yacc.c:680  */
+#line 211 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).yytype_97) ? ((*yyvaluep).yytype_97)->tag : "<NULL>"); }
-#line 1303 "src/parse-gram.c" /* yacc.c:680  */
+#line 1317 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
       default:
@@ -1885,57 +1898,57 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
   switch (yytype)
     {
     case 71: /* generic_symlist  */
-#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+#line 216 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).generic_symlist)); }
-#line 1889 "src/parse-gram.c" /* yacc.c:1253  */
+#line 1904 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
     case 72: /* generic_symlist_item  */
-#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+#line 216 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
-#line 1895 "src/parse-gram.c" /* yacc.c:1253  */
+#line 1910 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
     case 74: /* nterm_decls  */
-#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+#line 216 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).nterm_decls)); }
-#line 1901 "src/parse-gram.c" /* yacc.c:1253  */
+#line 1916 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
     case 75: /* token_decls  */
-#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+#line 216 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).token_decls)); }
-#line 1907 "src/parse-gram.c" /* yacc.c:1253  */
+#line 1922 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
     case 76: /* token_decl.1  */
-#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+#line 216 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).yytype_76)); }
-#line 1913 "src/parse-gram.c" /* yacc.c:1253  */
+#line 1928 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
     case 79: /* token_decls_for_prec  */
-#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+#line 216 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
-#line 1919 "src/parse-gram.c" /* yacc.c:1253  */
+#line 1934 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
     case 80: /* token_decl_for_prec.1  */
-#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+#line 216 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).yytype_80)); }
-#line 1925 "src/parse-gram.c" /* yacc.c:1253  */
+#line 1940 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
     case 82: /* symbol_decls  */
-#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+#line 216 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).symbol_decls)); }
-#line 1931 "src/parse-gram.c" /* yacc.c:1253  */
+#line 1946 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
     case 83: /* symbol_decl.1  */
-#line 209 "src/parse-gram.y" /* yacc.c:1253  */
+#line 216 "src/parse-gram.y" /* yacc.c:1254  */
       { symbol_list_free (((*yyvaluep).yytype_83)); }
-#line 1937 "src/parse-gram.c" /* yacc.c:1253  */
+#line 1952 "src/parse-gram.c" /* yacc.c:1254  */
         break;
 
       default:
@@ -2052,7 +2065,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 113 "src/parse-gram.y" /* yacc.c:1427  */
+#line 118 "src/parse-gram.y" /* yacc.c:1428  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -2060,7 +2073,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 2062 "src/parse-gram.c" /* yacc.c:1427  */
+#line 2077 "src/parse-gram.c" /* yacc.c:1428  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2259,183 +2272,183 @@ yyreduce:
     switch (yyn)
       {
   case 6:
-#line 276 "src/parse-gram.y" /* yacc.c:1648  */
+#line 283 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].PROLOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2267 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2282 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 7:
-#line 282 "src/parse-gram.y" /* yacc.c:1648  */
+#line 289 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_percent_define_ensure ((yyvsp[0].PERCENT_FLAG), (yylsp[0]), true);
     }
-#line 2275 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2290 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 8:
-#line 286 "src/parse-gram.y" /* yacc.c:1648  */
+#line 293 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_percent_define_insert ((yyvsp[-1].variable), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2284 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2299 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 9:
-#line 290 "src/parse-gram.y" /* yacc.c:1648  */
+#line 297 "src/parse-gram.y" /* yacc.c:1649  */
     { defines_flag = true; }
-#line 2290 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2305 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 10:
-#line 292 "src/parse-gram.y" /* yacc.c:1648  */
+#line 299 "src/parse-gram.y" /* yacc.c:1649  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].STRING));
     }
-#line 2299 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2314 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 11:
-#line 296 "src/parse-gram.y" /* yacc.c:1648  */
+#line 303 "src/parse-gram.y" /* yacc.c:1649  */
     { expected_sr_conflicts = (yyvsp[0].INT); }
-#line 2305 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2320 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 12:
-#line 297 "src/parse-gram.y" /* yacc.c:1648  */
+#line 304 "src/parse-gram.y" /* yacc.c:1649  */
     { expected_rr_conflicts = (yyvsp[0].INT); }
-#line 2311 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2326 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 13:
-#line 298 "src/parse-gram.y" /* yacc.c:1648  */
+#line 305 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_file_prefix = (yyvsp[0].STRING); }
-#line 2317 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2332 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 14:
-#line 300 "src/parse-gram.y" /* yacc.c:1648  */
+#line 307 "src/parse-gram.y" /* yacc.c:1649  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2326 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2341 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 15:
-#line 305 "src/parse-gram.y" /* yacc.c:1648  */
+#line 312 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].BRACED_CODE), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2335 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2350 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 16:
-#line 309 "src/parse-gram.y" /* yacc.c:1648  */
+#line 316 "src/parse-gram.y" /* yacc.c:1649  */
     { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
-#line 2341 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2356 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 17:
-#line 310 "src/parse-gram.y" /* yacc.c:1648  */
-    { spec_name_prefix = (yyvsp[0].STRING); }
-#line 2347 "src/parse-gram.c" /* yacc.c:1648  */
+#line 317 "src/parse-gram.y" /* yacc.c:1649  */
+    { do_name_prefix (&(yyloc), (yyvsp[-1].PERCENT_NAME_PREFIX), (yyvsp[0].STRING)); }
+#line 2362 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 18:
-#line 311 "src/parse-gram.y" /* yacc.c:1648  */
+#line 318 "src/parse-gram.y" /* yacc.c:1649  */
     { no_lines_flag = true; }
-#line 2353 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2368 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 19:
-#line 312 "src/parse-gram.y" /* yacc.c:1648  */
+#line 319 "src/parse-gram.y" /* yacc.c:1649  */
     { nondeterministic_parser = true; }
-#line 2359 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2374 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 20:
-#line 313 "src/parse-gram.y" /* yacc.c:1648  */
+#line 320 "src/parse-gram.y" /* yacc.c:1649  */
     { spec_outfile = (yyvsp[0].STRING); }
-#line 2365 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2380 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 21:
-#line 314 "src/parse-gram.y" /* yacc.c:1648  */
+#line 321 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = (yyvsp[0].PERCENT_PARAM); }
-#line 2371 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2386 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 22:
-#line 314 "src/parse-gram.y" /* yacc.c:1648  */
+#line 321 "src/parse-gram.y" /* yacc.c:1649  */
     { current_param = param_none; }
-#line 2377 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2392 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 23:
-#line 315 "src/parse-gram.y" /* yacc.c:1648  */
+#line 322 "src/parse-gram.y" /* yacc.c:1649  */
     { do_require (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2383 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2398 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 24:
-#line 316 "src/parse-gram.y" /* yacc.c:1648  */
+#line 323 "src/parse-gram.y" /* yacc.c:1649  */
     { do_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2389 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2404 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 25:
-#line 317 "src/parse-gram.y" /* yacc.c:1648  */
+#line 324 "src/parse-gram.y" /* yacc.c:1649  */
     { token_table_flag = true; }
-#line 2395 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2410 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 26:
-#line 318 "src/parse-gram.y" /* yacc.c:1648  */
+#line 325 "src/parse-gram.y" /* yacc.c:1649  */
     { report_flag |= report_states; }
-#line 2401 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2416 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 27:
-#line 319 "src/parse-gram.y" /* yacc.c:1648  */
+#line 326 "src/parse-gram.y" /* yacc.c:1649  */
     { yacc_flag = true; }
-#line 2407 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2422 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 28:
-#line 320 "src/parse-gram.y" /* yacc.c:1648  */
+#line 327 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = unknown_sym; yyerrok; }
-#line 2413 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2428 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 30:
-#line 325 "src/parse-gram.y" /* yacc.c:1648  */
+#line 332 "src/parse-gram.y" /* yacc.c:1649  */
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2419 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2434 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 31:
-#line 326 "src/parse-gram.y" /* yacc.c:1648  */
+#line 333 "src/parse-gram.y" /* yacc.c:1649  */
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2425 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2440 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 33:
-#line 337 "src/parse-gram.y" /* yacc.c:1648  */
+#line 344 "src/parse-gram.y" /* yacc.c:1649  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2433 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2448 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 34:
-#line 341 "src/parse-gram.y" /* yacc.c:1648  */
+#line 348 "src/parse-gram.y" /* yacc.c:1649  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].BRACED_CODE), (yylsp[-1]));
@@ -2446,27 +2459,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].generic_symlist));
       }
     }
-#line 2448 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2463 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 35:
-#line 352 "src/parse-gram.y" /* yacc.c:1648  */
+#line 359 "src/parse-gram.y" /* yacc.c:1649  */
     {
       default_prec = true;
     }
-#line 2456 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2471 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 36:
-#line 356 "src/parse-gram.y" /* yacc.c:1648  */
+#line 363 "src/parse-gram.y" /* yacc.c:1649  */
     {
       default_prec = false;
     }
-#line 2464 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2479 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 37:
-#line 360 "src/parse-gram.y" /* yacc.c:1648  */
+#line 367 "src/parse-gram.y" /* yacc.c:1649  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2474,207 +2487,207 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2476 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2491 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 38:
-#line 368 "src/parse-gram.y" /* yacc.c:1648  */
+#line 375 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_percent_code_grow ((yyvsp[-1].ID), (yylsp[-1]), translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2485 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2500 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 39:
-#line 377 "src/parse-gram.y" /* yacc.c:1648  */
+#line 384 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.code_props_type) = destructor; }
-#line 2491 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2506 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 40:
-#line 378 "src/parse-gram.y" /* yacc.c:1648  */
+#line 385 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.code_props_type) = printer; }
-#line 2497 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2512 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 41:
-#line 388 "src/parse-gram.y" /* yacc.c:1648  */
+#line 395 "src/parse-gram.y" /* yacc.c:1649  */
     {}
-#line 2503 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2518 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 42:
-#line 389 "src/parse-gram.y" /* yacc.c:1648  */
+#line 396 "src/parse-gram.y" /* yacc.c:1649  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2511 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2526 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 43:
-#line 396 "src/parse-gram.y" /* yacc.c:1648  */
+#line 403 "src/parse-gram.y" /* yacc.c:1649  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2521 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2536 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 44:
-#line 408 "src/parse-gram.y" /* yacc.c:1648  */
+#line 415 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = nterm_sym; }
-#line 2527 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2542 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 45:
-#line 409 "src/parse-gram.y" /* yacc.c:1648  */
+#line 416 "src/parse-gram.y" /* yacc.c:1649  */
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].nterm_decls));
     }
-#line 2536 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2551 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 46:
-#line 413 "src/parse-gram.y" /* yacc.c:1648  */
+#line 420 "src/parse-gram.y" /* yacc.c:1649  */
     { current_class = token_sym; }
-#line 2542 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2557 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 47:
-#line 414 "src/parse-gram.y" /* yacc.c:1648  */
+#line 421 "src/parse-gram.y" /* yacc.c:1649  */
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].token_decls));
     }
-#line 2551 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2566 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 48:
-#line 419 "src/parse-gram.y" /* yacc.c:1648  */
+#line 426 "src/parse-gram.y" /* yacc.c:1649  */
     {
       symbol_list_free ((yyvsp[0].symbol_decls));
     }
-#line 2559 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2574 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 49:
-#line 423 "src/parse-gram.y" /* yacc.c:1648  */
+#line 430 "src/parse-gram.y" /* yacc.c:1649  */
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].token_decls_for_prec); list; list = list->next)
         symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-1].precedence_declarator), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].token_decls_for_prec));
     }
-#line 2570 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2585 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 50:
-#line 432 "src/parse-gram.y" /* yacc.c:1648  */
+#line 439 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.precedence_declarator) = left_assoc; }
-#line 2576 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2591 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 51:
-#line 433 "src/parse-gram.y" /* yacc.c:1648  */
+#line 440 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.precedence_declarator) = right_assoc; }
-#line 2582 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2597 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 52:
-#line 434 "src/parse-gram.y" /* yacc.c:1648  */
+#line 441 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.precedence_declarator) = non_assoc; }
-#line 2588 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2603 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 53:
-#line 435 "src/parse-gram.y" /* yacc.c:1648  */
+#line 442 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.precedence_declarator) = precedence_assoc; }
-#line 2594 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2609 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 54:
-#line 439 "src/parse-gram.y" /* yacc.c:1648  */
+#line 446 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.yytype_70) = NULL; }
-#line 2600 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2615 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 55:
-#line 440 "src/parse-gram.y" /* yacc.c:1648  */
+#line 447 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.yytype_70) = (yyvsp[0].TAG); }
-#line 2606 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2621 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 57:
-#line 446 "src/parse-gram.y" /* yacc.c:1648  */
+#line 453 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
-#line 2612 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2627 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 58:
-#line 450 "src/parse-gram.y" /* yacc.c:1648  */
+#line 457 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2618 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2633 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 59:
-#line 451 "src/parse-gram.y" /* yacc.c:1648  */
+#line 458 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
-#line 2624 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2639 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 61:
-#line 456 "src/parse-gram.y" /* yacc.c:1648  */
+#line 463 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.tag) = uniqstr_new ("*"); }
-#line 2630 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2645 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 62:
-#line 457 "src/parse-gram.y" /* yacc.c:1648  */
+#line 464 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.tag) = uniqstr_new (""); }
-#line 2636 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2651 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 64:
-#line 480 "src/parse-gram.y" /* yacc.c:1648  */
+#line 487 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.token_decls) = (yyvsp[0].yytype_76);
     }
-#line 2644 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2659 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 65:
-#line 484 "src/parse-gram.y" /* yacc.c:1648  */
+#line 491 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_76), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2652 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2667 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 66:
-#line 488 "src/parse-gram.y" /* yacc.c:1648  */
+#line 495 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_76), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2660 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2675 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 67:
-#line 495 "src/parse-gram.y" /* yacc.c:1648  */
+#line 502 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.yytype_76) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
-#line 2666 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2681 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 68:
-#line 496 "src/parse-gram.y" /* yacc.c:1648  */
+#line 503 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.yytype_76) = symbol_list_append ((yyvsp[-1].yytype_76), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
-#line 2672 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2687 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 69:
-#line 501 "src/parse-gram.y" /* yacc.c:1648  */
+#line 508 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
@@ -2683,238 +2696,238 @@ yyreduce:
       if ((yyvsp[0].yytype_97))
         symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_97), (yylsp[0]));
     }
-#line 2685 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2700 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 70:
-#line 513 "src/parse-gram.y" /* yacc.c:1648  */
+#line 520 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.yytype_78) = -1; }
-#line 2691 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2706 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 72:
-#line 527 "src/parse-gram.y" /* yacc.c:1648  */
+#line 534 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.token_decls_for_prec) = (yyvsp[0].yytype_80);
     }
-#line 2699 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2714 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 73:
-#line 531 "src/parse-gram.y" /* yacc.c:1648  */
+#line 538 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_80), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2707 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2722 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 74:
-#line 535 "src/parse-gram.y" /* yacc.c:1648  */
+#line 542 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_80), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2715 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2730 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 75:
-#line 543 "src/parse-gram.y" /* yacc.c:1648  */
+#line 550 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.yytype_80) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
-#line 2721 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2736 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 76:
-#line 545 "src/parse-gram.y" /* yacc.c:1648  */
+#line 552 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.yytype_80) = symbol_list_append ((yyvsp[-1].yytype_80), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
-#line 2727 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2742 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 77:
-#line 550 "src/parse-gram.y" /* yacc.c:1648  */
+#line 557 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.token_decl_for_prec) = (yyvsp[-1].id);
       symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
       if (0 <= (yyvsp[0].yytype_78))
         symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_78), (yylsp[0]));
     }
-#line 2738 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2753 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 79:
-#line 567 "src/parse-gram.y" /* yacc.c:1648  */
+#line 574 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.symbol_decls) = (yyvsp[0].yytype_83);
     }
-#line 2746 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2761 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 80:
-#line 571 "src/parse-gram.y" /* yacc.c:1648  */
+#line 578 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_83), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2754 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2769 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 81:
-#line 575 "src/parse-gram.y" /* yacc.c:1648  */
+#line 582 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_83), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2762 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2777 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 82:
-#line 582 "src/parse-gram.y" /* yacc.c:1648  */
+#line 589 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.yytype_83) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2768 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2783 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 83:
-#line 583 "src/parse-gram.y" /* yacc.c:1648  */
+#line 590 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.yytype_83) = symbol_list_append ((yyvsp[-1].yytype_83), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2774 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2789 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 88:
-#line 601 "src/parse-gram.y" /* yacc.c:1648  */
+#line 608 "src/parse-gram.y" /* yacc.c:1649  */
     {
       yyerrok;
     }
-#line 2782 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2797 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 89:
-#line 607 "src/parse-gram.y" /* yacc.c:1648  */
+#line 614 "src/parse-gram.y" /* yacc.c:1649  */
     { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_90)); }
-#line 2788 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2803 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 90:
-#line 608 "src/parse-gram.y" /* yacc.c:1648  */
+#line 615 "src/parse-gram.y" /* yacc.c:1649  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2797 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2812 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 91:
-#line 615 "src/parse-gram.y" /* yacc.c:1648  */
+#line 622 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2803 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2818 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 92:
-#line 616 "src/parse-gram.y" /* yacc.c:1648  */
+#line 623 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2809 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2824 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 94:
-#line 623 "src/parse-gram.y" /* yacc.c:1648  */
+#line 630 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2816 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2831 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 95:
-#line 626 "src/parse-gram.y" /* yacc.c:1648  */
+#line 633 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_90)); }
-#line 2822 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2837 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 96:
-#line 628 "src/parse-gram.y" /* yacc.c:1648  */
+#line 635 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_90), (yyvsp[-2].yytype_70)); }
-#line 2828 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2843 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 97:
-#line 630 "src/parse-gram.y" /* yacc.c:1648  */
+#line 637 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
-#line 2834 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2849 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 98:
-#line 632 "src/parse-gram.y" /* yacc.c:1648  */
+#line 639 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2840 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2855 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 99:
-#line 634 "src/parse-gram.y" /* yacc.c:1648  */
+#line 641 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2846 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2861 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 100:
-#line 636 "src/parse-gram.y" /* yacc.c:1648  */
+#line 643 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
-#line 2852 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2867 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 101:
-#line 638 "src/parse-gram.y" /* yacc.c:1648  */
+#line 645 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
-#line 2858 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2873 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 102:
-#line 640 "src/parse-gram.y" /* yacc.c:1648  */
+#line 647 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2864 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2879 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 103:
-#line 642 "src/parse-gram.y" /* yacc.c:1648  */
+#line 649 "src/parse-gram.y" /* yacc.c:1649  */
     { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2870 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2885 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 104:
-#line 646 "src/parse-gram.y" /* yacc.c:1648  */
+#line 653 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.yytype_90) = 0; }
-#line 2876 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2891 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 105:
-#line 647 "src/parse-gram.y" /* yacc.c:1648  */
+#line 654 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.yytype_90) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
-#line 2882 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2897 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 107:
-#line 680 "src/parse-gram.y" /* yacc.c:1648  */
+#line 687 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2888 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2903 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 108:
-#line 681 "src/parse-gram.y" /* yacc.c:1648  */
+#line 688 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
-#line 2894 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2909 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 109:
-#line 682 "src/parse-gram.y" /* yacc.c:1648  */
+#line 689 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
-#line 2900 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2915 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 110:
-#line 683 "src/parse-gram.y" /* yacc.c:1648  */
+#line 690 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
-#line 2906 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2921 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 111:
-#line 696 "src/parse-gram.y" /* yacc.c:1648  */
+#line 703 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
-#line 2912 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2927 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 112:
-#line 698 "src/parse-gram.y" /* yacc.c:1648  */
+#line 705 "src/parse-gram.y" /* yacc.c:1649  */
     {
       if (current_class == nterm_sym)
         {
@@ -2926,41 +2939,41 @@ yyreduce:
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
     }
-#line 2928 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2943 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 113:
-#line 712 "src/parse-gram.y" /* yacc.c:1648  */
+#line 719 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
-#line 2934 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2949 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 116:
-#line 724 "src/parse-gram.y" /* yacc.c:1648  */
+#line 731 "src/parse-gram.y" /* yacc.c:1649  */
     {
       (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
-#line 2943 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2958 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 117:
-#line 732 "src/parse-gram.y" /* yacc.c:1648  */
+#line 739 "src/parse-gram.y" /* yacc.c:1649  */
     { (yyval.yytype_97) = NULL; }
-#line 2949 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2964 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
   case 120:
-#line 739 "src/parse-gram.y" /* yacc.c:1648  */
+#line 746 "src/parse-gram.y" /* yacc.c:1649  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2958 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2973 "src/parse-gram.c" /* yacc.c:1649  */
     break;
 
 
-#line 2962 "src/parse-gram.c" /* yacc.c:1648  */
+#line 2977 "src/parse-gram.c" /* yacc.c:1649  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3209,7 +3222,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 745 "src/parse-gram.y" /* yacc.c:1914  */
+#line 752 "src/parse-gram.y" /* yacc.c:1915  */
 
 
 /* Return the location of the left-hand side of a rule whose
@@ -3314,6 +3327,31 @@ add_param (param_type type, char *decl, location loc)
 }
 
 
+static void
+do_name_prefix (location const *loc,
+                char const *directive, char const *value)
+{
+  spec_name_prefix = value;
+
+  char buf1[1024];
+  size_t len1 = sizeof (buf1);
+  char *old = asnprintf (buf1, &len1, "%s\"%s\"", directive, value);
+  if (!old)
+    xalloc_die ();
+  char buf2[1024];
+  size_t len2 = sizeof (buf2);
+  char *new = asnprintf (buf2, &len2, "%%define api.prefix {%s}", value);
+  if (!new)
+    xalloc_die ();
+  bison_directive (loc, old);
+  deprecated_directive (loc, old, new);
+  if (old != buf1)
+    free (old);
+  if (new != buf2)
+    free (new);
+}
+
+
 static void
 do_require (location const *loc, char const *version)
 {
