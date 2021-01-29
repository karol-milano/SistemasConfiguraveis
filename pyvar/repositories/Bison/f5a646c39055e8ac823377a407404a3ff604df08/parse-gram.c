@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.2.90.11-ccb3-dirty.  */
+/* A Bison parser, made by GNU Bison 3.2.90.23-0bbcb-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.2.90.11-ccb3-dirty"
+#define YYBISON_VERSION "3.2.90.23-0bbcb-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -125,7 +125,7 @@ extern int gram_debug;
 
   #include "symlist.h"
   #include "symtab.h"
-#line 230 "src/parse-gram.y" /* yacc.c:352  */
+#line 234 "src/parse-gram.y" /* yacc.c:352  */
 
   typedef enum
   {
@@ -134,7 +134,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 673 "src/parse-gram.y" /* yacc.c:352  */
+#line 677 "src/parse-gram.y" /* yacc.c:352  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -275,6 +275,8 @@ union GRAM_STYPE
   uniqstr PERCENT_FLAG;
   /* "%name-prefix"  */
   uniqstr PERCENT_NAME_PREFIX;
+  /* "%yacc"  */
+  uniqstr PERCENT_YACC;
   /* "[identifier]"  */
   uniqstr BRACKETED_ID;
   /* "identifier"  */
@@ -293,7 +295,7 @@ union GRAM_STYPE
   unsigned char CHAR;
   /* value  */
   value_type value;
-#line 297 "src/parse-gram.c" /* yacc.c:352  */
+#line 299 "src/parse-gram.c" /* yacc.c:352  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -377,17 +379,20 @@ int gram_parse (void);
   static char const *translate_code_braceless (char *code, location loc);
 
   /* Handle a %error-verbose directive.  */
-  static void do_error_verbose (location const *loc, char const *directive);
+  static void handle_error_verbose (location const *loc, char const *directive);
 
   /* Handle a %name-prefix directive.  */
-  static void do_name_prefix (location const *loc,
-                              char const *directive, char const *value);
+  static void handle_name_prefix (location const *loc,
+                                  char const *directive, char const *value);
 
   /* Handle a %require directive.  */
-  static void do_require (location const *loc, char const *version);
+  static void handle_require (location const *loc, char const *version);
 
   /* Handle a %skeleton directive.  */
-  static void do_skeleton (location const *loc, char const *skel);
+  static void handle_skeleton (location const *loc, char const *skel);
+
+  /* Handle a %yacc directive.  */
+  static void handle_yacc (location const *loc, char const *directive);
 
   static void gram_error (location const *, char const *);
 
@@ -398,7 +403,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 240 "src/parse-gram.y" /* yacc.c:355  */
+#line 244 "src/parse-gram.y" /* yacc.c:355  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -409,7 +414,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 413 "src/parse-gram.c" /* yacc.c:355  */
+#line 418 "src/parse-gram.c" /* yacc.c:355  */
 
 #ifdef short
 # undef short
@@ -682,19 +687,19 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   272,   272,   281,   282,   286,   287,   293,   297,   302,
-     303,   308,   309,   310,   311,   312,   317,   322,   323,   324,
-     325,   326,   327,   327,   328,   329,   330,   331,   332,   333,
-     334,   338,   339,   348,   349,   353,   364,   368,   372,   380,
-     390,   391,   401,   402,   408,   421,   421,   426,   426,   431,
-     435,   445,   446,   447,   448,   452,   453,   458,   459,   463,
-     464,   468,   469,   470,   483,   492,   496,   500,   508,   509,
-     513,   526,   527,   539,   543,   547,   555,   557,   562,   569,
-     579,   583,   587,   595,   596,   604,   605,   611,   612,   613,
-     620,   620,   628,   629,   630,   635,   638,   640,   642,   644,
-     646,   648,   650,   652,   654,   659,   660,   669,   693,   694,
-     695,   696,   708,   710,   725,   730,   731,   736,   745,   746,
-     750,   751
+       0,   276,   276,   285,   286,   290,   291,   297,   301,   306,
+     307,   312,   313,   314,   315,   316,   321,   326,   327,   328,
+     329,   330,   331,   331,   332,   333,   334,   335,   336,   337,
+     338,   342,   343,   352,   353,   357,   368,   372,   376,   384,
+     394,   395,   405,   406,   412,   425,   425,   430,   430,   435,
+     439,   449,   450,   451,   452,   456,   457,   462,   463,   467,
+     468,   472,   473,   474,   487,   496,   500,   504,   512,   513,
+     517,   530,   531,   543,   547,   551,   559,   561,   566,   573,
+     583,   587,   591,   599,   600,   608,   609,   615,   616,   617,
+     624,   624,   632,   633,   634,   639,   642,   644,   646,   648,
+     650,   652,   654,   656,   658,   663,   664,   673,   697,   698,
+     699,   700,   712,   714,   729,   734,   735,   740,   749,   750,
+     754,   755
 };
 #endif
 
@@ -1090,91 +1095,97 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 199 "src/parse-gram.y" /* yacc.c:680  */
+#line 202 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).STRING)), yyo); }
-#line 1096 "src/parse-gram.c" /* yacc.c:680  */
+#line 1101 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 20: /* "%error-verbose"  */
-#line 206 "src/parse-gram.y" /* yacc.c:680  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).PERCENT_ERROR_VERBOSE), yyo); }
-#line 1102 "src/parse-gram.c" /* yacc.c:680  */
+#line 1107 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 23: /* "%<flag>"  */
-#line 209 "src/parse-gram.y" /* yacc.c:680  */
+#line 213 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
-#line 1108 "src/parse-gram.c" /* yacc.c:680  */
+#line 1113 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 28: /* "%name-prefix"  */
-#line 206 "src/parse-gram.y" /* yacc.c:680  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).PERCENT_NAME_PREFIX), yyo); }
-#line 1114 "src/parse-gram.c" /* yacc.c:680  */
+#line 1119 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 38: /* "%yacc"  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
+      { fputs (((*yyvaluep).PERCENT_YACC), yyo); }
+#line 1125 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 39: /* "{...}"  */
-#line 200 "src/parse-gram.y" /* yacc.c:680  */
+#line 203 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_CODE)); }
-#line 1120 "src/parse-gram.c" /* yacc.c:680  */
+#line 1131 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 40: /* "%?{...}"  */
-#line 200 "src/parse-gram.y" /* yacc.c:680  */
+#line 203 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_PREDICATE)); }
-#line 1126 "src/parse-gram.c" /* yacc.c:680  */
+#line 1137 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 41: /* "[identifier]"  */
-#line 207 "src/parse-gram.y" /* yacc.c:680  */
+#line 211 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
-#line 1132 "src/parse-gram.c" /* yacc.c:680  */
+#line 1143 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 42: /* "char"  */
-#line 196 "src/parse-gram.y" /* yacc.c:680  */
+#line 199 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
-#line 1138 "src/parse-gram.c" /* yacc.c:680  */
+#line 1149 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 43: /* "epilogue"  */
-#line 200 "src/parse-gram.y" /* yacc.c:680  */
+#line 203 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).EPILOGUE)); }
-#line 1144 "src/parse-gram.c" /* yacc.c:680  */
+#line 1155 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 45: /* "identifier"  */
-#line 206 "src/parse-gram.y" /* yacc.c:680  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).ID), yyo); }
-#line 1150 "src/parse-gram.c" /* yacc.c:680  */
+#line 1161 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 46: /* "identifier:"  */
-#line 208 "src/parse-gram.y" /* yacc.c:680  */
+#line 212 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
-#line 1156 "src/parse-gram.c" /* yacc.c:680  */
+#line 1167 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 49: /* "%{...%}"  */
-#line 200 "src/parse-gram.y" /* yacc.c:680  */
+#line 203 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).PROLOGUE)); }
-#line 1162 "src/parse-gram.c" /* yacc.c:680  */
+#line 1173 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 51: /* "<tag>"  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 214 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
-#line 1168 "src/parse-gram.c" /* yacc.c:680  */
+#line 1179 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 54: /* "integer"  */
-#line 213 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
-#line 1174 "src/parse-gram.c" /* yacc.c:680  */
+#line 1185 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 55: /* "%param"  */
-#line 252 "src/parse-gram.y" /* yacc.c:680  */
+#line 256 "src/parse-gram.y" /* yacc.c:680  */
       {
   switch (((*yyvaluep).PERCENT_PARAM))
     {
@@ -1187,107 +1198,107 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1191 "src/parse-gram.c" /* yacc.c:680  */
+#line 1202 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 65: /* code_props_type  */
-#line 388 "src/parse-gram.y" /* yacc.c:680  */
+#line 392 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
-#line 1197 "src/parse-gram.c" /* yacc.c:680  */
+#line 1208 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 71: /* tag.opt  */
-#line 206 "src/parse-gram.y" /* yacc.c:680  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).yytype_71), yyo); }
-#line 1203 "src/parse-gram.c" /* yacc.c:680  */
+#line 1214 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 72: /* generic_symlist  */
-#line 222 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
-#line 1209 "src/parse-gram.c" /* yacc.c:680  */
+#line 1220 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 73: /* generic_symlist_item  */
-#line 222 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
-#line 1215 "src/parse-gram.c" /* yacc.c:680  */
+#line 1226 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 74: /* tag  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 214 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
-#line 1221 "src/parse-gram.c" /* yacc.c:680  */
+#line 1232 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 75: /* nterm_decls  */
-#line 222 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
-#line 1227 "src/parse-gram.c" /* yacc.c:680  */
+#line 1238 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 76: /* token_decls  */
-#line 222 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
-#line 1233 "src/parse-gram.c" /* yacc.c:680  */
+#line 1244 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 77: /* token_decl.1  */
-#line 222 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).yytype_77), yyo); }
-#line 1239 "src/parse-gram.c" /* yacc.c:680  */
+#line 1250 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 78: /* token_decl  */
-#line 216 "src/parse-gram.y" /* yacc.c:680  */
+#line 220 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
-#line 1245 "src/parse-gram.c" /* yacc.c:680  */
+#line 1256 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 79: /* int.opt  */
-#line 213 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%d", ((*yyvaluep).yytype_79)); }
-#line 1251 "src/parse-gram.c" /* yacc.c:680  */
+#line 1262 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 80: /* token_decls_for_prec  */
-#line 222 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
-#line 1257 "src/parse-gram.c" /* yacc.c:680  */
+#line 1268 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 81: /* token_decl_for_prec.1  */
-#line 222 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).yytype_81), yyo); }
-#line 1263 "src/parse-gram.c" /* yacc.c:680  */
+#line 1274 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 82: /* token_decl_for_prec  */
-#line 216 "src/parse-gram.y" /* yacc.c:680  */
+#line 220 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
-#line 1269 "src/parse-gram.c" /* yacc.c:680  */
+#line 1280 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 83: /* symbol_decls  */
-#line 222 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
-#line 1275 "src/parse-gram.c" /* yacc.c:680  */
+#line 1286 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 84: /* symbol_decl.1  */
-#line 222 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).yytype_84), yyo); }
-#line 1281 "src/parse-gram.c" /* yacc.c:680  */
+#line 1292 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 92: /* variable  */
-#line 206 "src/parse-gram.y" /* yacc.c:680  */
+#line 210 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).variable), yyo); }
-#line 1287 "src/parse-gram.c" /* yacc.c:680  */
+#line 1298 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 93: /* value  */
-#line 683 "src/parse-gram.y" /* yacc.c:680  */
+#line 687 "src/parse-gram.y" /* yacc.c:680  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1296,37 +1307,37 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1300 "src/parse-gram.c" /* yacc.c:680  */
+#line 1311 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 94: /* id  */
-#line 216 "src/parse-gram.y" /* yacc.c:680  */
+#line 220 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
-#line 1306 "src/parse-gram.c" /* yacc.c:680  */
+#line 1317 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 95: /* id_colon  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
+#line 221 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
-#line 1312 "src/parse-gram.c" /* yacc.c:680  */
+#line 1323 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 96: /* symbol  */
-#line 216 "src/parse-gram.y" /* yacc.c:680  */
+#line 220 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
-#line 1318 "src/parse-gram.c" /* yacc.c:680  */
+#line 1329 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 97: /* string_as_id  */
-#line 216 "src/parse-gram.y" /* yacc.c:680  */
+#line 220 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
-#line 1324 "src/parse-gram.c" /* yacc.c:680  */
+#line 1335 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 98: /* string_as_id.opt  */
-#line 216 "src/parse-gram.y" /* yacc.c:680  */
+#line 220 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).yytype_98) ? ((*yyvaluep).yytype_98)->tag : "<NULL>"); }
-#line 1330 "src/parse-gram.c" /* yacc.c:680  */
+#line 1341 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
       default:
@@ -1729,7 +1740,10 @@ yytnamerr (char *yyres, const char *yystr)
           case '\\':
             if (*++yyp != '\\')
               goto do_not_strip_quotes;
-            /* Fall through.  */
+            else
+              goto append;
+
+          append:
           default:
             if (yyres)
               yyres[yyn] = *yyp;
@@ -1911,57 +1925,57 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
   switch (yytype)
     {
     case 72: /* generic_symlist  */
-#line 221 "src/parse-gram.y" /* yacc.c:1254  */
+#line 225 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).generic_symlist)); }
-#line 1917 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1931 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 73: /* generic_symlist_item  */
-#line 221 "src/parse-gram.y" /* yacc.c:1254  */
+#line 225 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
-#line 1923 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1937 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 75: /* nterm_decls  */
-#line 221 "src/parse-gram.y" /* yacc.c:1254  */
+#line 225 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).nterm_decls)); }
-#line 1929 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1943 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 76: /* token_decls  */
-#line 221 "src/parse-gram.y" /* yacc.c:1254  */
+#line 225 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).token_decls)); }
-#line 1935 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1949 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 77: /* token_decl.1  */
-#line 221 "src/parse-gram.y" /* yacc.c:1254  */
+#line 225 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).yytype_77)); }
-#line 1941 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1955 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 80: /* token_decls_for_prec  */
-#line 221 "src/parse-gram.y" /* yacc.c:1254  */
+#line 225 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
-#line 1947 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1961 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 81: /* token_decl_for_prec.1  */
-#line 221 "src/parse-gram.y" /* yacc.c:1254  */
+#line 225 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).yytype_81)); }
-#line 1953 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1967 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 83: /* symbol_decls  */
-#line 221 "src/parse-gram.y" /* yacc.c:1254  */
+#line 225 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).symbol_decls)); }
-#line 1959 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1973 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 84: /* symbol_decl.1  */
-#line 221 "src/parse-gram.y" /* yacc.c:1254  */
+#line 225 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).yytype_84)); }
-#line 1965 "src/parse-gram.c" /* yacc.c:1254  */
+#line 1979 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
       default:
@@ -2078,7 +2092,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 121 "src/parse-gram.y" /* yacc.c:1428  */
+#line 124 "src/parse-gram.y" /* yacc.c:1431  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -2086,7 +2100,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 2090 "src/parse-gram.c" /* yacc.c:1428  */
+#line 2104 "src/parse-gram.c" /* yacc.c:1431  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2285,189 +2299,189 @@ yyreduce:
     switch (yyn)
       {
   case 6:
-#line 288 "src/parse-gram.y" /* yacc.c:1649  */
+#line 292 "src/parse-gram.y" /* yacc.c:1652  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].PROLOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2295 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2309 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 7:
-#line 294 "src/parse-gram.y" /* yacc.c:1649  */
+#line 298 "src/parse-gram.y" /* yacc.c:1652  */
     {
       muscle_percent_define_ensure ((yyvsp[0].PERCENT_FLAG), (yylsp[0]), true);
     }
-#line 2303 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2317 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 8:
-#line 298 "src/parse-gram.y" /* yacc.c:1649  */
+#line 302 "src/parse-gram.y" /* yacc.c:1652  */
     {
       muscle_percent_define_insert ((yyvsp[-1].variable), (yyloc), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2312 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2326 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 9:
-#line 302 "src/parse-gram.y" /* yacc.c:1649  */
+#line 306 "src/parse-gram.y" /* yacc.c:1652  */
     { defines_flag = true; }
-#line 2318 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2332 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 10:
-#line 304 "src/parse-gram.y" /* yacc.c:1649  */
+#line 308 "src/parse-gram.y" /* yacc.c:1652  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].STRING));
     }
-#line 2327 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2341 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 11:
-#line 308 "src/parse-gram.y" /* yacc.c:1649  */
-    { do_error_verbose (&(yyloc), (yyvsp[0].PERCENT_ERROR_VERBOSE)); }
-#line 2333 "src/parse-gram.c" /* yacc.c:1649  */
+#line 312 "src/parse-gram.y" /* yacc.c:1652  */
+    { handle_error_verbose (&(yyloc), (yyvsp[0].PERCENT_ERROR_VERBOSE)); }
+#line 2347 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 12:
-#line 309 "src/parse-gram.y" /* yacc.c:1649  */
+#line 313 "src/parse-gram.y" /* yacc.c:1652  */
     { expected_sr_conflicts = (yyvsp[0].INT); }
-#line 2339 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2353 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 13:
-#line 310 "src/parse-gram.y" /* yacc.c:1649  */
+#line 314 "src/parse-gram.y" /* yacc.c:1652  */
     { expected_rr_conflicts = (yyvsp[0].INT); }
-#line 2345 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2359 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 14:
-#line 311 "src/parse-gram.y" /* yacc.c:1649  */
+#line 315 "src/parse-gram.y" /* yacc.c:1652  */
     { spec_file_prefix = (yyvsp[0].STRING); }
-#line 2351 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2365 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 15:
-#line 313 "src/parse-gram.y" /* yacc.c:1649  */
+#line 317 "src/parse-gram.y" /* yacc.c:1652  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2360 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2374 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 16:
-#line 318 "src/parse-gram.y" /* yacc.c:1649  */
+#line 322 "src/parse-gram.y" /* yacc.c:1652  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].BRACED_CODE), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2369 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2383 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 17:
-#line 322 "src/parse-gram.y" /* yacc.c:1649  */
+#line 326 "src/parse-gram.y" /* yacc.c:1652  */
     { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
-#line 2375 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2389 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 18:
-#line 323 "src/parse-gram.y" /* yacc.c:1649  */
-    { do_name_prefix (&(yyloc), (yyvsp[-1].PERCENT_NAME_PREFIX), (yyvsp[0].STRING)); }
-#line 2381 "src/parse-gram.c" /* yacc.c:1649  */
+#line 327 "src/parse-gram.y" /* yacc.c:1652  */
+    { handle_name_prefix (&(yyloc), (yyvsp[-1].PERCENT_NAME_PREFIX), (yyvsp[0].STRING)); }
+#line 2395 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 19:
-#line 324 "src/parse-gram.y" /* yacc.c:1649  */
+#line 328 "src/parse-gram.y" /* yacc.c:1652  */
     { no_lines_flag = true; }
-#line 2387 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2401 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 20:
-#line 325 "src/parse-gram.y" /* yacc.c:1649  */
+#line 329 "src/parse-gram.y" /* yacc.c:1652  */
     { nondeterministic_parser = true; }
-#line 2393 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2407 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 21:
-#line 326 "src/parse-gram.y" /* yacc.c:1649  */
+#line 330 "src/parse-gram.y" /* yacc.c:1652  */
     { spec_outfile = (yyvsp[0].STRING); }
-#line 2399 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2413 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 22:
-#line 327 "src/parse-gram.y" /* yacc.c:1649  */
+#line 331 "src/parse-gram.y" /* yacc.c:1652  */
     { current_param = (yyvsp[0].PERCENT_PARAM); }
-#line 2405 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2419 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 23:
-#line 327 "src/parse-gram.y" /* yacc.c:1649  */
+#line 331 "src/parse-gram.y" /* yacc.c:1652  */
     { current_param = param_none; }
-#line 2411 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2425 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 24:
-#line 328 "src/parse-gram.y" /* yacc.c:1649  */
-    { do_require (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2417 "src/parse-gram.c" /* yacc.c:1649  */
+#line 332 "src/parse-gram.y" /* yacc.c:1652  */
+    { handle_require (&(yylsp[0]), (yyvsp[0].STRING)); }
+#line 2431 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 25:
-#line 329 "src/parse-gram.y" /* yacc.c:1649  */
-    { do_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2423 "src/parse-gram.c" /* yacc.c:1649  */
+#line 333 "src/parse-gram.y" /* yacc.c:1652  */
+    { handle_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
+#line 2437 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 26:
-#line 330 "src/parse-gram.y" /* yacc.c:1649  */
+#line 334 "src/parse-gram.y" /* yacc.c:1652  */
     { token_table_flag = true; }
-#line 2429 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2443 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 27:
-#line 331 "src/parse-gram.y" /* yacc.c:1649  */
+#line 335 "src/parse-gram.y" /* yacc.c:1652  */
     { report_flag |= report_states; }
-#line 2435 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2449 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 28:
-#line 332 "src/parse-gram.y" /* yacc.c:1649  */
-    { yacc_flag = true; }
-#line 2441 "src/parse-gram.c" /* yacc.c:1649  */
+#line 336 "src/parse-gram.y" /* yacc.c:1652  */
+    { handle_yacc (&(yyloc), (yyvsp[0].PERCENT_YACC)); }
+#line 2455 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 29:
-#line 333 "src/parse-gram.y" /* yacc.c:1649  */
+#line 337 "src/parse-gram.y" /* yacc.c:1652  */
     { current_class = unknown_sym; yyerrok; }
-#line 2447 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2461 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 31:
-#line 338 "src/parse-gram.y" /* yacc.c:1649  */
+#line 342 "src/parse-gram.y" /* yacc.c:1652  */
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2453 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2467 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 32:
-#line 339 "src/parse-gram.y" /* yacc.c:1649  */
+#line 343 "src/parse-gram.y" /* yacc.c:1652  */
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2459 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2473 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 34:
-#line 350 "src/parse-gram.y" /* yacc.c:1649  */
+#line 354 "src/parse-gram.y" /* yacc.c:1652  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2467 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2481 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 35:
-#line 354 "src/parse-gram.y" /* yacc.c:1649  */
+#line 358 "src/parse-gram.y" /* yacc.c:1652  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].BRACED_CODE), (yylsp[-1]));
@@ -2478,27 +2492,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].generic_symlist));
       }
     }
-#line 2482 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2496 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 36:
-#line 365 "src/parse-gram.y" /* yacc.c:1649  */
+#line 369 "src/parse-gram.y" /* yacc.c:1652  */
     {
       default_prec = true;
     }
-#line 2490 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2504 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 37:
-#line 369 "src/parse-gram.y" /* yacc.c:1649  */
+#line 373 "src/parse-gram.y" /* yacc.c:1652  */
     {
       default_prec = false;
     }
-#line 2498 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2512 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 38:
-#line 373 "src/parse-gram.y" /* yacc.c:1649  */
+#line 377 "src/parse-gram.y" /* yacc.c:1652  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2506,207 +2520,207 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2510 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2524 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 39:
-#line 381 "src/parse-gram.y" /* yacc.c:1649  */
+#line 385 "src/parse-gram.y" /* yacc.c:1652  */
     {
       muscle_percent_code_grow ((yyvsp[-1].ID), (yylsp[-1]), translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2519 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2533 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 40:
-#line 390 "src/parse-gram.y" /* yacc.c:1649  */
+#line 394 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.code_props_type) = destructor; }
-#line 2525 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2539 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 41:
-#line 391 "src/parse-gram.y" /* yacc.c:1649  */
+#line 395 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.code_props_type) = printer; }
-#line 2531 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2545 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 42:
-#line 401 "src/parse-gram.y" /* yacc.c:1649  */
+#line 405 "src/parse-gram.y" /* yacc.c:1652  */
     {}
-#line 2537 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2551 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 43:
-#line 402 "src/parse-gram.y" /* yacc.c:1649  */
+#line 406 "src/parse-gram.y" /* yacc.c:1652  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2545 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2559 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 44:
-#line 409 "src/parse-gram.y" /* yacc.c:1649  */
+#line 413 "src/parse-gram.y" /* yacc.c:1652  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2555 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2569 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 45:
-#line 421 "src/parse-gram.y" /* yacc.c:1649  */
+#line 425 "src/parse-gram.y" /* yacc.c:1652  */
     { current_class = nterm_sym; }
-#line 2561 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2575 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 46:
-#line 422 "src/parse-gram.y" /* yacc.c:1649  */
+#line 426 "src/parse-gram.y" /* yacc.c:1652  */
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].nterm_decls));
     }
-#line 2570 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2584 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 47:
-#line 426 "src/parse-gram.y" /* yacc.c:1649  */
+#line 430 "src/parse-gram.y" /* yacc.c:1652  */
     { current_class = token_sym; }
-#line 2576 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2590 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 48:
-#line 427 "src/parse-gram.y" /* yacc.c:1649  */
+#line 431 "src/parse-gram.y" /* yacc.c:1652  */
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].token_decls));
     }
-#line 2585 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2599 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 49:
-#line 432 "src/parse-gram.y" /* yacc.c:1649  */
+#line 436 "src/parse-gram.y" /* yacc.c:1652  */
     {
       symbol_list_free ((yyvsp[0].symbol_decls));
     }
-#line 2593 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2607 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 50:
-#line 436 "src/parse-gram.y" /* yacc.c:1649  */
+#line 440 "src/parse-gram.y" /* yacc.c:1652  */
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].token_decls_for_prec); list; list = list->next)
         symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-1].precedence_declarator), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].token_decls_for_prec));
     }
-#line 2604 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2618 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 51:
-#line 445 "src/parse-gram.y" /* yacc.c:1649  */
+#line 449 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.precedence_declarator) = left_assoc; }
-#line 2610 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2624 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 52:
-#line 446 "src/parse-gram.y" /* yacc.c:1649  */
+#line 450 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.precedence_declarator) = right_assoc; }
-#line 2616 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2630 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 53:
-#line 447 "src/parse-gram.y" /* yacc.c:1649  */
+#line 451 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.precedence_declarator) = non_assoc; }
-#line 2622 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2636 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 54:
-#line 448 "src/parse-gram.y" /* yacc.c:1649  */
+#line 452 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.precedence_declarator) = precedence_assoc; }
-#line 2628 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2642 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 55:
-#line 452 "src/parse-gram.y" /* yacc.c:1649  */
+#line 456 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_71) = NULL; }
-#line 2634 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2648 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 56:
-#line 453 "src/parse-gram.y" /* yacc.c:1649  */
+#line 457 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_71) = (yyvsp[0].TAG); }
-#line 2640 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2654 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 58:
-#line 459 "src/parse-gram.y" /* yacc.c:1649  */
+#line 463 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
-#line 2646 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2660 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 59:
-#line 463 "src/parse-gram.y" /* yacc.c:1649  */
+#line 467 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2652 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2666 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 60:
-#line 464 "src/parse-gram.y" /* yacc.c:1649  */
+#line 468 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
-#line 2658 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2672 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 62:
-#line 469 "src/parse-gram.y" /* yacc.c:1649  */
+#line 473 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.tag) = uniqstr_new ("*"); }
-#line 2664 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2678 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 63:
-#line 470 "src/parse-gram.y" /* yacc.c:1649  */
+#line 474 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.tag) = uniqstr_new (""); }
-#line 2670 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2684 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 65:
-#line 493 "src/parse-gram.y" /* yacc.c:1649  */
+#line 497 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decls) = (yyvsp[0].yytype_77);
     }
-#line 2678 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2692 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 66:
-#line 497 "src/parse-gram.y" /* yacc.c:1649  */
+#line 501 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_77), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2686 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2700 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 67:
-#line 501 "src/parse-gram.y" /* yacc.c:1649  */
+#line 505 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_77), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2694 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2708 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 68:
-#line 508 "src/parse-gram.y" /* yacc.c:1649  */
+#line 512 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_77) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
-#line 2700 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2714 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 69:
-#line 509 "src/parse-gram.y" /* yacc.c:1649  */
+#line 513 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_77) = symbol_list_append ((yyvsp[-1].yytype_77), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
-#line 2706 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2720 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 70:
-#line 514 "src/parse-gram.y" /* yacc.c:1649  */
+#line 518 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
@@ -2715,238 +2729,238 @@ yyreduce:
       if ((yyvsp[0].yytype_98))
         symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_98), (yylsp[0]));
     }
-#line 2719 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2733 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 71:
-#line 526 "src/parse-gram.y" /* yacc.c:1649  */
+#line 530 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_79) = -1; }
-#line 2725 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2739 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 73:
-#line 540 "src/parse-gram.y" /* yacc.c:1649  */
+#line 544 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decls_for_prec) = (yyvsp[0].yytype_81);
     }
-#line 2733 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2747 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 74:
-#line 544 "src/parse-gram.y" /* yacc.c:1649  */
+#line 548 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_81), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2741 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2755 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 75:
-#line 548 "src/parse-gram.y" /* yacc.c:1649  */
+#line 552 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_81), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2749 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2763 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 76:
-#line 556 "src/parse-gram.y" /* yacc.c:1649  */
+#line 560 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_81) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
-#line 2755 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2769 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 77:
-#line 558 "src/parse-gram.y" /* yacc.c:1649  */
+#line 562 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_81) = symbol_list_append ((yyvsp[-1].yytype_81), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
-#line 2761 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2775 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 78:
-#line 563 "src/parse-gram.y" /* yacc.c:1649  */
+#line 567 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decl_for_prec) = (yyvsp[-1].id);
       symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
       if (0 <= (yyvsp[0].yytype_79))
         symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_79), (yylsp[0]));
     }
-#line 2772 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2786 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 80:
-#line 580 "src/parse-gram.y" /* yacc.c:1649  */
+#line 584 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.symbol_decls) = (yyvsp[0].yytype_84);
     }
-#line 2780 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2794 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 81:
-#line 584 "src/parse-gram.y" /* yacc.c:1649  */
+#line 588 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_84), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2788 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2802 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 82:
-#line 588 "src/parse-gram.y" /* yacc.c:1649  */
+#line 592 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_84), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2796 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2810 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 83:
-#line 595 "src/parse-gram.y" /* yacc.c:1649  */
+#line 599 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_84) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2802 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2816 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 84:
-#line 596 "src/parse-gram.y" /* yacc.c:1649  */
+#line 600 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_84) = symbol_list_append ((yyvsp[-1].yytype_84), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2808 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2822 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 89:
-#line 614 "src/parse-gram.y" /* yacc.c:1649  */
+#line 618 "src/parse-gram.y" /* yacc.c:1652  */
     {
       yyerrok;
     }
-#line 2816 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2830 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 90:
-#line 620 "src/parse-gram.y" /* yacc.c:1649  */
+#line 624 "src/parse-gram.y" /* yacc.c:1652  */
     { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_91)); }
-#line 2822 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2836 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 91:
-#line 621 "src/parse-gram.y" /* yacc.c:1649  */
+#line 625 "src/parse-gram.y" /* yacc.c:1652  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2831 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2845 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 92:
-#line 628 "src/parse-gram.y" /* yacc.c:1649  */
+#line 632 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2837 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2851 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 93:
-#line 629 "src/parse-gram.y" /* yacc.c:1649  */
+#line 633 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2843 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2857 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 95:
-#line 636 "src/parse-gram.y" /* yacc.c:1649  */
+#line 640 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2850 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2864 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 96:
-#line 639 "src/parse-gram.y" /* yacc.c:1649  */
+#line 643 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_91)); }
-#line 2856 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2870 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 97:
-#line 641 "src/parse-gram.y" /* yacc.c:1649  */
+#line 645 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_91), (yyvsp[-2].yytype_71)); }
-#line 2862 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2876 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 98:
-#line 643 "src/parse-gram.y" /* yacc.c:1649  */
+#line 647 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
-#line 2868 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2882 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 99:
-#line 645 "src/parse-gram.y" /* yacc.c:1649  */
+#line 649 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2874 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2888 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 100:
-#line 647 "src/parse-gram.y" /* yacc.c:1649  */
+#line 651 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2880 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2894 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 101:
-#line 649 "src/parse-gram.y" /* yacc.c:1649  */
+#line 653 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
-#line 2886 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2900 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 102:
-#line 651 "src/parse-gram.y" /* yacc.c:1649  */
+#line 655 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
-#line 2892 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2906 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 103:
-#line 653 "src/parse-gram.y" /* yacc.c:1649  */
+#line 657 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2898 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2912 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 104:
-#line 655 "src/parse-gram.y" /* yacc.c:1649  */
+#line 659 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2904 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2918 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 105:
-#line 659 "src/parse-gram.y" /* yacc.c:1649  */
+#line 663 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_91) = 0; }
-#line 2910 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2924 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 106:
-#line 660 "src/parse-gram.y" /* yacc.c:1649  */
+#line 664 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_91) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
-#line 2916 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2930 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 108:
-#line 693 "src/parse-gram.y" /* yacc.c:1649  */
+#line 697 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2922 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2936 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 109:
-#line 694 "src/parse-gram.y" /* yacc.c:1649  */
+#line 698 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
-#line 2928 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2942 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 110:
-#line 695 "src/parse-gram.y" /* yacc.c:1649  */
+#line 699 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
-#line 2934 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2948 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 111:
-#line 696 "src/parse-gram.y" /* yacc.c:1649  */
+#line 700 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
-#line 2940 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2954 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 112:
-#line 709 "src/parse-gram.y" /* yacc.c:1649  */
+#line 713 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
-#line 2946 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2960 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 113:
-#line 711 "src/parse-gram.y" /* yacc.c:1649  */
+#line 715 "src/parse-gram.y" /* yacc.c:1652  */
     {
       if (current_class == nterm_sym)
         {
@@ -2958,41 +2972,41 @@ yyreduce:
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
     }
-#line 2962 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2976 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 114:
-#line 725 "src/parse-gram.y" /* yacc.c:1649  */
+#line 729 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
-#line 2968 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2982 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 117:
-#line 737 "src/parse-gram.y" /* yacc.c:1649  */
+#line 741 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
-#line 2977 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2991 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 118:
-#line 745 "src/parse-gram.y" /* yacc.c:1649  */
+#line 749 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_98) = NULL; }
-#line 2983 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2997 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 121:
-#line 752 "src/parse-gram.y" /* yacc.c:1649  */
+#line 756 "src/parse-gram.y" /* yacc.c:1652  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2992 "src/parse-gram.c" /* yacc.c:1649  */
+#line 3006 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
 
-#line 2996 "src/parse-gram.c" /* yacc.c:1649  */
+#line 3010 "src/parse-gram.c" /* yacc.c:1652  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3241,7 +3255,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 758 "src/parse-gram.y" /* yacc.c:1915  */
+#line 762 "src/parse-gram.y" /* yacc.c:1918  */
 
 
 /* Return the location of the left-hand side of a rule whose
@@ -3347,7 +3361,7 @@ add_param (param_type type, char *decl, location loc)
 
 
 static void
-do_error_verbose (location const *loc, char const *directive)
+handle_error_verbose (location const *loc, char const *directive)
 {
   bison_directive (loc, directive);
   muscle_percent_define_insert (directive, *loc, muscle_keyword, "",
@@ -3356,8 +3370,8 @@ do_error_verbose (location const *loc, char const *directive)
 
 
 static void
-do_name_prefix (location const *loc,
-                char const *directive, char const *value)
+handle_name_prefix (location const *loc,
+                    char const *directive, char const *value)
 {
   spec_name_prefix = value;
 
@@ -3381,7 +3395,7 @@ do_name_prefix (location const *loc,
 
 
 static void
-do_require (location const *loc, char const *version)
+handle_require (location const *loc, char const *version)
 {
   /* Changes of behavior are only on minor version changes, so "3.0.5"
      is the same as "3.0". */
@@ -3419,7 +3433,7 @@ do_require (location const *loc, char const *version)
 }
 
 static void
-do_skeleton (location const *loc, char const *skel)
+handle_skeleton (location const *loc, char const *skel)
 {
   char const *skeleton_user = skel;
   if (strchr (skeleton_user, '/'))
@@ -3443,6 +3457,25 @@ do_skeleton (location const *loc, char const *skel)
   skeleton_arg (skeleton_user, grammar_prio, *loc);
 }
 
+static void
+handle_yacc (location const *loc, char const *directive)
+{
+  bison_directive (loc, directive);
+  bool warned = false;
+
+  if (location_empty (yacc_loc))
+    yacc_loc = *loc;
+  else
+    {
+      duplicate_directive (directive, yacc_loc, *loc);
+      warned = true;
+    }
+
+  if (!warned
+      && STRNEQ (directive, "%fixed-output-files")
+      && STRNEQ (directive, "%yacc"))
+    deprecated_directive (loc, directive, "%fixed-output-files");
+}
 
 static void
 gram_error (location const *loc, char const *msg)
