@@ -125,7 +125,7 @@ extern int gram_debug;
 
   #include "symlist.h"
   #include "symtab.h"
-#line 234 "src/parse-gram.y" /* yacc.c:352  */
+#line 239 "src/parse-gram.y" /* yacc.c:352  */
 
   typedef enum
   {
@@ -134,7 +134,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 677 "src/parse-gram.y" /* yacc.c:352  */
+#line 682 "src/parse-gram.y" /* yacc.c:352  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -273,6 +273,8 @@ union GRAM_STYPE
   uniqstr PERCENT_ERROR_VERBOSE;
   /* "%<flag>"  */
   uniqstr PERCENT_FLAG;
+  /* "%file-prefix"  */
+  uniqstr PERCENT_FILE_PREFIX;
   /* "%name-prefix"  */
   uniqstr PERCENT_NAME_PREFIX;
   /* "%yacc"  */
@@ -295,7 +297,7 @@ union GRAM_STYPE
   unsigned char CHAR;
   /* value  */
   value_type value;
-#line 299 "src/parse-gram.c" /* yacc.c:352  */
+#line 301 "src/parse-gram.c" /* yacc.c:352  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -381,6 +383,11 @@ int gram_parse (void);
   /* Handle a %error-verbose directive.  */
   static void handle_error_verbose (location const *loc, char const *directive);
 
+  /* Handle a %file-prefix directive.  */
+  static void handle_file_prefix (location const *loc,
+                                  location const *dir_loc,
+                                  char const *directive, char const *value);
+
   /* Handle a %name-prefix directive.  */
   static void handle_name_prefix (location const *loc,
                                   char const *directive, char const *value);
@@ -403,7 +410,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 244 "src/parse-gram.y" /* yacc.c:355  */
+#line 249 "src/parse-gram.y" /* yacc.c:355  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -414,7 +421,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 418 "src/parse-gram.c" /* yacc.c:355  */
+#line 425 "src/parse-gram.c" /* yacc.c:355  */
 
 #ifdef short
 # undef short
@@ -687,19 +694,19 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   276,   276,   285,   286,   290,   291,   297,   301,   306,
-     307,   312,   313,   314,   315,   316,   321,   326,   327,   328,
-     329,   330,   331,   331,   332,   333,   334,   335,   336,   337,
-     338,   342,   343,   352,   353,   357,   368,   372,   376,   384,
-     394,   395,   405,   406,   412,   425,   425,   430,   430,   435,
-     439,   449,   450,   451,   452,   456,   457,   462,   463,   467,
-     468,   472,   473,   474,   487,   496,   500,   504,   512,   513,
-     517,   530,   531,   543,   547,   551,   559,   561,   566,   573,
-     583,   587,   591,   599,   600,   608,   609,   615,   616,   617,
-     624,   624,   632,   633,   634,   639,   642,   644,   646,   648,
-     650,   652,   654,   656,   658,   663,   664,   673,   697,   698,
-     699,   700,   712,   714,   729,   734,   735,   740,   749,   750,
-     754,   755
+       0,   281,   281,   290,   291,   295,   296,   302,   306,   311,
+     312,   317,   318,   319,   320,   321,   326,   331,   332,   333,
+     334,   335,   336,   336,   337,   338,   339,   340,   341,   342,
+     343,   347,   348,   357,   358,   362,   373,   377,   381,   389,
+     399,   400,   410,   411,   417,   430,   430,   435,   435,   440,
+     444,   454,   455,   456,   457,   461,   462,   467,   468,   472,
+     473,   477,   478,   479,   492,   501,   505,   509,   517,   518,
+     522,   535,   536,   548,   552,   556,   564,   566,   571,   578,
+     588,   592,   596,   604,   605,   613,   614,   620,   621,   622,
+     629,   629,   637,   638,   639,   644,   647,   649,   651,   653,
+     655,   657,   659,   661,   663,   668,   669,   678,   702,   703,
+     704,   705,   717,   719,   734,   739,   740,   745,   754,   755,
+     759,   760
 };
 #endif
 
@@ -1095,97 +1102,103 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 202 "src/parse-gram.y" /* yacc.c:680  */
+#line 207 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).STRING)), yyo); }
-#line 1101 "src/parse-gram.c" /* yacc.c:680  */
+#line 1108 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 20: /* "%error-verbose"  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 215 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).PERCENT_ERROR_VERBOSE), yyo); }
-#line 1107 "src/parse-gram.c" /* yacc.c:680  */
+#line 1114 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 23: /* "%<flag>"  */
-#line 213 "src/parse-gram.y" /* yacc.c:680  */
+#line 218 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
-#line 1113 "src/parse-gram.c" /* yacc.c:680  */
+#line 1120 "src/parse-gram.c" /* yacc.c:680  */
+        break;
+
+    case 24: /* "%file-prefix"  */
+#line 215 "src/parse-gram.y" /* yacc.c:680  */
+      { fputs (((*yyvaluep).PERCENT_FILE_PREFIX), yyo); }
+#line 1126 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 28: /* "%name-prefix"  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 215 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).PERCENT_NAME_PREFIX), yyo); }
-#line 1119 "src/parse-gram.c" /* yacc.c:680  */
+#line 1132 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 38: /* "%yacc"  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 215 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).PERCENT_YACC), yyo); }
-#line 1125 "src/parse-gram.c" /* yacc.c:680  */
+#line 1138 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 39: /* "{...}"  */
-#line 203 "src/parse-gram.y" /* yacc.c:680  */
+#line 208 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_CODE)); }
-#line 1131 "src/parse-gram.c" /* yacc.c:680  */
+#line 1144 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 40: /* "%?{...}"  */
-#line 203 "src/parse-gram.y" /* yacc.c:680  */
+#line 208 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_PREDICATE)); }
-#line 1137 "src/parse-gram.c" /* yacc.c:680  */
+#line 1150 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 41: /* "[identifier]"  */
-#line 211 "src/parse-gram.y" /* yacc.c:680  */
+#line 216 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
-#line 1143 "src/parse-gram.c" /* yacc.c:680  */
+#line 1156 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 42: /* "char"  */
-#line 199 "src/parse-gram.y" /* yacc.c:680  */
+#line 204 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
-#line 1149 "src/parse-gram.c" /* yacc.c:680  */
+#line 1162 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 43: /* "epilogue"  */
-#line 203 "src/parse-gram.y" /* yacc.c:680  */
+#line 208 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).EPILOGUE)); }
-#line 1155 "src/parse-gram.c" /* yacc.c:680  */
+#line 1168 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 45: /* "identifier"  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 215 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).ID), yyo); }
-#line 1161 "src/parse-gram.c" /* yacc.c:680  */
+#line 1174 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 46: /* "identifier:"  */
-#line 212 "src/parse-gram.y" /* yacc.c:680  */
+#line 217 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
-#line 1167 "src/parse-gram.c" /* yacc.c:680  */
+#line 1180 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 49: /* "%{...%}"  */
-#line 203 "src/parse-gram.y" /* yacc.c:680  */
+#line 208 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).PROLOGUE)); }
-#line 1173 "src/parse-gram.c" /* yacc.c:680  */
+#line 1186 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 51: /* "<tag>"  */
-#line 214 "src/parse-gram.y" /* yacc.c:680  */
+#line 219 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
-#line 1179 "src/parse-gram.c" /* yacc.c:680  */
+#line 1192 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 54: /* "integer"  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
+#line 222 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
-#line 1185 "src/parse-gram.c" /* yacc.c:680  */
+#line 1198 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 55: /* "%param"  */
-#line 256 "src/parse-gram.y" /* yacc.c:680  */
+#line 261 "src/parse-gram.y" /* yacc.c:680  */
       {
   switch (((*yyvaluep).PERCENT_PARAM))
     {
@@ -1198,107 +1211,107 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1202 "src/parse-gram.c" /* yacc.c:680  */
+#line 1215 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 65: /* code_props_type  */
-#line 392 "src/parse-gram.y" /* yacc.c:680  */
+#line 397 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
-#line 1208 "src/parse-gram.c" /* yacc.c:680  */
+#line 1221 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 71: /* tag.opt  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 215 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).yytype_71), yyo); }
-#line 1214 "src/parse-gram.c" /* yacc.c:680  */
+#line 1227 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 72: /* generic_symlist  */
-#line 226 "src/parse-gram.y" /* yacc.c:680  */
+#line 231 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
-#line 1220 "src/parse-gram.c" /* yacc.c:680  */
+#line 1233 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 73: /* generic_symlist_item  */
-#line 226 "src/parse-gram.y" /* yacc.c:680  */
+#line 231 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
-#line 1226 "src/parse-gram.c" /* yacc.c:680  */
+#line 1239 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 74: /* tag  */
-#line 214 "src/parse-gram.y" /* yacc.c:680  */
+#line 219 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
-#line 1232 "src/parse-gram.c" /* yacc.c:680  */
+#line 1245 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 75: /* nterm_decls  */
-#line 226 "src/parse-gram.y" /* yacc.c:680  */
+#line 231 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
-#line 1238 "src/parse-gram.c" /* yacc.c:680  */
+#line 1251 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 76: /* token_decls  */
-#line 226 "src/parse-gram.y" /* yacc.c:680  */
+#line 231 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
-#line 1244 "src/parse-gram.c" /* yacc.c:680  */
+#line 1257 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 77: /* token_decl.1  */
-#line 226 "src/parse-gram.y" /* yacc.c:680  */
+#line 231 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).yytype_77), yyo); }
-#line 1250 "src/parse-gram.c" /* yacc.c:680  */
+#line 1263 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 78: /* token_decl  */
-#line 220 "src/parse-gram.y" /* yacc.c:680  */
+#line 225 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
-#line 1256 "src/parse-gram.c" /* yacc.c:680  */
+#line 1269 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 79: /* int.opt  */
-#line 217 "src/parse-gram.y" /* yacc.c:680  */
+#line 222 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%d", ((*yyvaluep).yytype_79)); }
-#line 1262 "src/parse-gram.c" /* yacc.c:680  */
+#line 1275 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 80: /* token_decls_for_prec  */
-#line 226 "src/parse-gram.y" /* yacc.c:680  */
+#line 231 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
-#line 1268 "src/parse-gram.c" /* yacc.c:680  */
+#line 1281 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 81: /* token_decl_for_prec.1  */
-#line 226 "src/parse-gram.y" /* yacc.c:680  */
+#line 231 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).yytype_81), yyo); }
-#line 1274 "src/parse-gram.c" /* yacc.c:680  */
+#line 1287 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 82: /* token_decl_for_prec  */
-#line 220 "src/parse-gram.y" /* yacc.c:680  */
+#line 225 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
-#line 1280 "src/parse-gram.c" /* yacc.c:680  */
+#line 1293 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 83: /* symbol_decls  */
-#line 226 "src/parse-gram.y" /* yacc.c:680  */
+#line 231 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
-#line 1286 "src/parse-gram.c" /* yacc.c:680  */
+#line 1299 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 84: /* symbol_decl.1  */
-#line 226 "src/parse-gram.y" /* yacc.c:680  */
+#line 231 "src/parse-gram.y" /* yacc.c:680  */
       { symbol_list_syms_print (((*yyvaluep).yytype_84), yyo); }
-#line 1292 "src/parse-gram.c" /* yacc.c:680  */
+#line 1305 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 92: /* variable  */
-#line 210 "src/parse-gram.y" /* yacc.c:680  */
+#line 215 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).variable), yyo); }
-#line 1298 "src/parse-gram.c" /* yacc.c:680  */
+#line 1311 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 93: /* value  */
-#line 687 "src/parse-gram.y" /* yacc.c:680  */
+#line 692 "src/parse-gram.y" /* yacc.c:680  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1307,37 +1320,37 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1311 "src/parse-gram.c" /* yacc.c:680  */
+#line 1324 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 94: /* id  */
-#line 220 "src/parse-gram.y" /* yacc.c:680  */
+#line 225 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
-#line 1317 "src/parse-gram.c" /* yacc.c:680  */
+#line 1330 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 95: /* id_colon  */
-#line 221 "src/parse-gram.y" /* yacc.c:680  */
+#line 226 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
-#line 1323 "src/parse-gram.c" /* yacc.c:680  */
+#line 1336 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 96: /* symbol  */
-#line 220 "src/parse-gram.y" /* yacc.c:680  */
+#line 225 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
-#line 1329 "src/parse-gram.c" /* yacc.c:680  */
+#line 1342 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 97: /* string_as_id  */
-#line 220 "src/parse-gram.y" /* yacc.c:680  */
+#line 225 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
-#line 1335 "src/parse-gram.c" /* yacc.c:680  */
+#line 1348 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 98: /* string_as_id.opt  */
-#line 220 "src/parse-gram.y" /* yacc.c:680  */
+#line 225 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).yytype_98) ? ((*yyvaluep).yytype_98)->tag : "<NULL>"); }
-#line 1341 "src/parse-gram.c" /* yacc.c:680  */
+#line 1354 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
       default:
@@ -1925,57 +1938,57 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
   switch (yytype)
     {
     case 72: /* generic_symlist  */
-#line 225 "src/parse-gram.y" /* yacc.c:1257  */
+#line 230 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).generic_symlist)); }
-#line 1931 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1944 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 73: /* generic_symlist_item  */
-#line 225 "src/parse-gram.y" /* yacc.c:1257  */
+#line 230 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
-#line 1937 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1950 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 75: /* nterm_decls  */
-#line 225 "src/parse-gram.y" /* yacc.c:1257  */
+#line 230 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).nterm_decls)); }
-#line 1943 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1956 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 76: /* token_decls  */
-#line 225 "src/parse-gram.y" /* yacc.c:1257  */
+#line 230 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).token_decls)); }
-#line 1949 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1962 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 77: /* token_decl.1  */
-#line 225 "src/parse-gram.y" /* yacc.c:1257  */
+#line 230 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).yytype_77)); }
-#line 1955 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1968 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 80: /* token_decls_for_prec  */
-#line 225 "src/parse-gram.y" /* yacc.c:1257  */
+#line 230 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
-#line 1961 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1974 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 81: /* token_decl_for_prec.1  */
-#line 225 "src/parse-gram.y" /* yacc.c:1257  */
+#line 230 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).yytype_81)); }
-#line 1967 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1980 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 83: /* symbol_decls  */
-#line 225 "src/parse-gram.y" /* yacc.c:1257  */
+#line 230 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).symbol_decls)); }
-#line 1973 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1986 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
     case 84: /* symbol_decl.1  */
-#line 225 "src/parse-gram.y" /* yacc.c:1257  */
+#line 230 "src/parse-gram.y" /* yacc.c:1257  */
       { symbol_list_free (((*yyvaluep).yytype_84)); }
-#line 1979 "src/parse-gram.c" /* yacc.c:1257  */
+#line 1992 "src/parse-gram.c" /* yacc.c:1257  */
         break;
 
       default:
@@ -2092,7 +2105,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 124 "src/parse-gram.y" /* yacc.c:1431  */
+#line 129 "src/parse-gram.y" /* yacc.c:1431  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -2100,7 +2113,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 2104 "src/parse-gram.c" /* yacc.c:1431  */
+#line 2117 "src/parse-gram.c" /* yacc.c:1431  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2299,189 +2312,189 @@ yyreduce:
     switch (yyn)
       {
   case 6:
-#line 292 "src/parse-gram.y" /* yacc.c:1652  */
+#line 297 "src/parse-gram.y" /* yacc.c:1652  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].PROLOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2309 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2322 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 7:
-#line 298 "src/parse-gram.y" /* yacc.c:1652  */
+#line 303 "src/parse-gram.y" /* yacc.c:1652  */
     {
       muscle_percent_define_ensure ((yyvsp[0].PERCENT_FLAG), (yylsp[0]), true);
     }
-#line 2317 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2330 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 8:
-#line 302 "src/parse-gram.y" /* yacc.c:1652  */
+#line 307 "src/parse-gram.y" /* yacc.c:1652  */
     {
       muscle_percent_define_insert ((yyvsp[-1].variable), (yyloc), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2326 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2339 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 9:
-#line 306 "src/parse-gram.y" /* yacc.c:1652  */
+#line 311 "src/parse-gram.y" /* yacc.c:1652  */
     { defines_flag = true; }
-#line 2332 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2345 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 10:
-#line 308 "src/parse-gram.y" /* yacc.c:1652  */
+#line 313 "src/parse-gram.y" /* yacc.c:1652  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].STRING));
     }
-#line 2341 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2354 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 11:
-#line 312 "src/parse-gram.y" /* yacc.c:1652  */
+#line 317 "src/parse-gram.y" /* yacc.c:1652  */
     { handle_error_verbose (&(yyloc), (yyvsp[0].PERCENT_ERROR_VERBOSE)); }
-#line 2347 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2360 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 12:
-#line 313 "src/parse-gram.y" /* yacc.c:1652  */
+#line 318 "src/parse-gram.y" /* yacc.c:1652  */
     { expected_sr_conflicts = (yyvsp[0].INT); }
-#line 2353 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2366 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 13:
-#line 314 "src/parse-gram.y" /* yacc.c:1652  */
+#line 319 "src/parse-gram.y" /* yacc.c:1652  */
     { expected_rr_conflicts = (yyvsp[0].INT); }
-#line 2359 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2372 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 14:
-#line 315 "src/parse-gram.y" /* yacc.c:1652  */
-    { spec_file_prefix = (yyvsp[0].STRING); }
-#line 2365 "src/parse-gram.c" /* yacc.c:1652  */
+#line 320 "src/parse-gram.y" /* yacc.c:1652  */
+    { handle_file_prefix (&(yyloc), &(yylsp[-1]), (yyvsp[-1].PERCENT_FILE_PREFIX), (yyvsp[0].STRING)); }
+#line 2378 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 15:
-#line 317 "src/parse-gram.y" /* yacc.c:1652  */
+#line 322 "src/parse-gram.y" /* yacc.c:1652  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2374 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2387 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 16:
-#line 322 "src/parse-gram.y" /* yacc.c:1652  */
+#line 327 "src/parse-gram.y" /* yacc.c:1652  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].BRACED_CODE), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2383 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2396 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 17:
-#line 326 "src/parse-gram.y" /* yacc.c:1652  */
+#line 331 "src/parse-gram.y" /* yacc.c:1652  */
     { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
-#line 2389 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2402 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 18:
-#line 327 "src/parse-gram.y" /* yacc.c:1652  */
+#line 332 "src/parse-gram.y" /* yacc.c:1652  */
     { handle_name_prefix (&(yyloc), (yyvsp[-1].PERCENT_NAME_PREFIX), (yyvsp[0].STRING)); }
-#line 2395 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2408 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 19:
-#line 328 "src/parse-gram.y" /* yacc.c:1652  */
+#line 333 "src/parse-gram.y" /* yacc.c:1652  */
     { no_lines_flag = true; }
-#line 2401 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2414 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 20:
-#line 329 "src/parse-gram.y" /* yacc.c:1652  */
+#line 334 "src/parse-gram.y" /* yacc.c:1652  */
     { nondeterministic_parser = true; }
-#line 2407 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2420 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 21:
-#line 330 "src/parse-gram.y" /* yacc.c:1652  */
+#line 335 "src/parse-gram.y" /* yacc.c:1652  */
     { spec_outfile = (yyvsp[0].STRING); }
-#line 2413 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2426 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 22:
-#line 331 "src/parse-gram.y" /* yacc.c:1652  */
+#line 336 "src/parse-gram.y" /* yacc.c:1652  */
     { current_param = (yyvsp[0].PERCENT_PARAM); }
-#line 2419 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2432 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 23:
-#line 331 "src/parse-gram.y" /* yacc.c:1652  */
+#line 336 "src/parse-gram.y" /* yacc.c:1652  */
     { current_param = param_none; }
-#line 2425 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2438 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 24:
-#line 332 "src/parse-gram.y" /* yacc.c:1652  */
+#line 337 "src/parse-gram.y" /* yacc.c:1652  */
     { handle_require (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2431 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2444 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 25:
-#line 333 "src/parse-gram.y" /* yacc.c:1652  */
+#line 338 "src/parse-gram.y" /* yacc.c:1652  */
     { handle_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2437 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2450 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 26:
-#line 334 "src/parse-gram.y" /* yacc.c:1652  */
+#line 339 "src/parse-gram.y" /* yacc.c:1652  */
     { token_table_flag = true; }
-#line 2443 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2456 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 27:
-#line 335 "src/parse-gram.y" /* yacc.c:1652  */
+#line 340 "src/parse-gram.y" /* yacc.c:1652  */
     { report_flag |= report_states; }
-#line 2449 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2462 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 28:
-#line 336 "src/parse-gram.y" /* yacc.c:1652  */
+#line 341 "src/parse-gram.y" /* yacc.c:1652  */
     { handle_yacc (&(yyloc), (yyvsp[0].PERCENT_YACC)); }
-#line 2455 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2468 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 29:
-#line 337 "src/parse-gram.y" /* yacc.c:1652  */
+#line 342 "src/parse-gram.y" /* yacc.c:1652  */
     { current_class = unknown_sym; yyerrok; }
-#line 2461 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2474 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 31:
-#line 342 "src/parse-gram.y" /* yacc.c:1652  */
+#line 347 "src/parse-gram.y" /* yacc.c:1652  */
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2467 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2480 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 32:
-#line 343 "src/parse-gram.y" /* yacc.c:1652  */
+#line 348 "src/parse-gram.y" /* yacc.c:1652  */
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2473 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2486 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 34:
-#line 354 "src/parse-gram.y" /* yacc.c:1652  */
+#line 359 "src/parse-gram.y" /* yacc.c:1652  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2481 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2494 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 35:
-#line 358 "src/parse-gram.y" /* yacc.c:1652  */
+#line 363 "src/parse-gram.y" /* yacc.c:1652  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].BRACED_CODE), (yylsp[-1]));
@@ -2492,27 +2505,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].generic_symlist));
       }
     }
-#line 2496 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2509 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 36:
-#line 369 "src/parse-gram.y" /* yacc.c:1652  */
+#line 374 "src/parse-gram.y" /* yacc.c:1652  */
     {
       default_prec = true;
     }
-#line 2504 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2517 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 37:
-#line 373 "src/parse-gram.y" /* yacc.c:1652  */
+#line 378 "src/parse-gram.y" /* yacc.c:1652  */
     {
       default_prec = false;
     }
-#line 2512 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2525 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 38:
-#line 377 "src/parse-gram.y" /* yacc.c:1652  */
+#line 382 "src/parse-gram.y" /* yacc.c:1652  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2520,207 +2533,207 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2524 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2537 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 39:
-#line 385 "src/parse-gram.y" /* yacc.c:1652  */
+#line 390 "src/parse-gram.y" /* yacc.c:1652  */
     {
       muscle_percent_code_grow ((yyvsp[-1].ID), (yylsp[-1]), translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2533 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2546 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 40:
-#line 394 "src/parse-gram.y" /* yacc.c:1652  */
+#line 399 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.code_props_type) = destructor; }
-#line 2539 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2552 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 41:
-#line 395 "src/parse-gram.y" /* yacc.c:1652  */
+#line 400 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.code_props_type) = printer; }
-#line 2545 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2558 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 42:
-#line 405 "src/parse-gram.y" /* yacc.c:1652  */
+#line 410 "src/parse-gram.y" /* yacc.c:1652  */
     {}
-#line 2551 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2564 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 43:
-#line 406 "src/parse-gram.y" /* yacc.c:1652  */
+#line 411 "src/parse-gram.y" /* yacc.c:1652  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2559 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2572 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 44:
-#line 413 "src/parse-gram.y" /* yacc.c:1652  */
+#line 418 "src/parse-gram.y" /* yacc.c:1652  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2569 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2582 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 45:
-#line 425 "src/parse-gram.y" /* yacc.c:1652  */
+#line 430 "src/parse-gram.y" /* yacc.c:1652  */
     { current_class = nterm_sym; }
-#line 2575 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2588 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 46:
-#line 426 "src/parse-gram.y" /* yacc.c:1652  */
+#line 431 "src/parse-gram.y" /* yacc.c:1652  */
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].nterm_decls));
     }
-#line 2584 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2597 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 47:
-#line 430 "src/parse-gram.y" /* yacc.c:1652  */
+#line 435 "src/parse-gram.y" /* yacc.c:1652  */
     { current_class = token_sym; }
-#line 2590 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2603 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 48:
-#line 431 "src/parse-gram.y" /* yacc.c:1652  */
+#line 436 "src/parse-gram.y" /* yacc.c:1652  */
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].token_decls));
     }
-#line 2599 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2612 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 49:
-#line 436 "src/parse-gram.y" /* yacc.c:1652  */
+#line 441 "src/parse-gram.y" /* yacc.c:1652  */
     {
       symbol_list_free ((yyvsp[0].symbol_decls));
     }
-#line 2607 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2620 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 50:
-#line 440 "src/parse-gram.y" /* yacc.c:1652  */
+#line 445 "src/parse-gram.y" /* yacc.c:1652  */
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].token_decls_for_prec); list; list = list->next)
         symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-1].precedence_declarator), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].token_decls_for_prec));
     }
-#line 2618 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2631 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 51:
-#line 449 "src/parse-gram.y" /* yacc.c:1652  */
+#line 454 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.precedence_declarator) = left_assoc; }
-#line 2624 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2637 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 52:
-#line 450 "src/parse-gram.y" /* yacc.c:1652  */
+#line 455 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.precedence_declarator) = right_assoc; }
-#line 2630 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2643 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 53:
-#line 451 "src/parse-gram.y" /* yacc.c:1652  */
+#line 456 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.precedence_declarator) = non_assoc; }
-#line 2636 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2649 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 54:
-#line 452 "src/parse-gram.y" /* yacc.c:1652  */
+#line 457 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.precedence_declarator) = precedence_assoc; }
-#line 2642 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2655 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 55:
-#line 456 "src/parse-gram.y" /* yacc.c:1652  */
+#line 461 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_71) = NULL; }
-#line 2648 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2661 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 56:
-#line 457 "src/parse-gram.y" /* yacc.c:1652  */
+#line 462 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_71) = (yyvsp[0].TAG); }
-#line 2654 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2667 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 58:
-#line 463 "src/parse-gram.y" /* yacc.c:1652  */
+#line 468 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
-#line 2660 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2673 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 59:
-#line 467 "src/parse-gram.y" /* yacc.c:1652  */
+#line 472 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2666 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2679 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 60:
-#line 468 "src/parse-gram.y" /* yacc.c:1652  */
+#line 473 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
-#line 2672 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2685 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 62:
-#line 473 "src/parse-gram.y" /* yacc.c:1652  */
+#line 478 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.tag) = uniqstr_new ("*"); }
-#line 2678 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2691 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 63:
-#line 474 "src/parse-gram.y" /* yacc.c:1652  */
+#line 479 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.tag) = uniqstr_new (""); }
-#line 2684 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2697 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 65:
-#line 497 "src/parse-gram.y" /* yacc.c:1652  */
+#line 502 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decls) = (yyvsp[0].yytype_77);
     }
-#line 2692 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2705 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 66:
-#line 501 "src/parse-gram.y" /* yacc.c:1652  */
+#line 506 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_77), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2700 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2713 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 67:
-#line 505 "src/parse-gram.y" /* yacc.c:1652  */
+#line 510 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_77), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2708 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2721 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 68:
-#line 512 "src/parse-gram.y" /* yacc.c:1652  */
+#line 517 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_77) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
-#line 2714 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2727 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 69:
-#line 513 "src/parse-gram.y" /* yacc.c:1652  */
+#line 518 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_77) = symbol_list_append ((yyvsp[-1].yytype_77), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
-#line 2720 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2733 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 70:
-#line 518 "src/parse-gram.y" /* yacc.c:1652  */
+#line 523 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
@@ -2729,238 +2742,238 @@ yyreduce:
       if ((yyvsp[0].yytype_98))
         symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_98), (yylsp[0]));
     }
-#line 2733 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2746 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 71:
-#line 530 "src/parse-gram.y" /* yacc.c:1652  */
+#line 535 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_79) = -1; }
-#line 2739 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2752 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 73:
-#line 544 "src/parse-gram.y" /* yacc.c:1652  */
+#line 549 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decls_for_prec) = (yyvsp[0].yytype_81);
     }
-#line 2747 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2760 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 74:
-#line 548 "src/parse-gram.y" /* yacc.c:1652  */
+#line 553 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_81), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2755 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2768 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 75:
-#line 552 "src/parse-gram.y" /* yacc.c:1652  */
+#line 557 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_81), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2763 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2776 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 76:
-#line 560 "src/parse-gram.y" /* yacc.c:1652  */
+#line 565 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_81) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
-#line 2769 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2782 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 77:
-#line 562 "src/parse-gram.y" /* yacc.c:1652  */
+#line 567 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_81) = symbol_list_append ((yyvsp[-1].yytype_81), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
-#line 2775 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2788 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 78:
-#line 567 "src/parse-gram.y" /* yacc.c:1652  */
+#line 572 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.token_decl_for_prec) = (yyvsp[-1].id);
       symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
       if (0 <= (yyvsp[0].yytype_79))
         symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_79), (yylsp[0]));
     }
-#line 2786 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2799 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 80:
-#line 584 "src/parse-gram.y" /* yacc.c:1652  */
+#line 589 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.symbol_decls) = (yyvsp[0].yytype_84);
     }
-#line 2794 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2807 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 81:
-#line 588 "src/parse-gram.y" /* yacc.c:1652  */
+#line 593 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_84), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2802 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2815 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 82:
-#line 592 "src/parse-gram.y" /* yacc.c:1652  */
+#line 597 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_84), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2810 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2823 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 83:
-#line 599 "src/parse-gram.y" /* yacc.c:1652  */
+#line 604 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_84) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2816 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2829 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 84:
-#line 600 "src/parse-gram.y" /* yacc.c:1652  */
+#line 605 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_84) = symbol_list_append ((yyvsp[-1].yytype_84), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2822 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2835 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 89:
-#line 618 "src/parse-gram.y" /* yacc.c:1652  */
+#line 623 "src/parse-gram.y" /* yacc.c:1652  */
     {
       yyerrok;
     }
-#line 2830 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2843 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 90:
-#line 624 "src/parse-gram.y" /* yacc.c:1652  */
+#line 629 "src/parse-gram.y" /* yacc.c:1652  */
     { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_91)); }
-#line 2836 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2849 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 91:
-#line 625 "src/parse-gram.y" /* yacc.c:1652  */
+#line 630 "src/parse-gram.y" /* yacc.c:1652  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2845 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2858 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 92:
-#line 632 "src/parse-gram.y" /* yacc.c:1652  */
+#line 637 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2851 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2864 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 93:
-#line 633 "src/parse-gram.y" /* yacc.c:1652  */
+#line 638 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2857 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2870 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 95:
-#line 640 "src/parse-gram.y" /* yacc.c:1652  */
+#line 645 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2864 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2877 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 96:
-#line 643 "src/parse-gram.y" /* yacc.c:1652  */
+#line 648 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_91)); }
-#line 2870 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2883 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 97:
-#line 645 "src/parse-gram.y" /* yacc.c:1652  */
+#line 650 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_91), (yyvsp[-2].yytype_71)); }
-#line 2876 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2889 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 98:
-#line 647 "src/parse-gram.y" /* yacc.c:1652  */
+#line 652 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
-#line 2882 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2895 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 99:
-#line 649 "src/parse-gram.y" /* yacc.c:1652  */
+#line 654 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2888 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2901 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 100:
-#line 651 "src/parse-gram.y" /* yacc.c:1652  */
+#line 656 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2894 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2907 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 101:
-#line 653 "src/parse-gram.y" /* yacc.c:1652  */
+#line 658 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
-#line 2900 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2913 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 102:
-#line 655 "src/parse-gram.y" /* yacc.c:1652  */
+#line 660 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
-#line 2906 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2919 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 103:
-#line 657 "src/parse-gram.y" /* yacc.c:1652  */
+#line 662 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2912 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2925 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 104:
-#line 659 "src/parse-gram.y" /* yacc.c:1652  */
+#line 664 "src/parse-gram.y" /* yacc.c:1652  */
     { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2918 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2931 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 105:
-#line 663 "src/parse-gram.y" /* yacc.c:1652  */
+#line 668 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_91) = 0; }
-#line 2924 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2937 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 106:
-#line 664 "src/parse-gram.y" /* yacc.c:1652  */
+#line 669 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_91) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
-#line 2930 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2943 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 108:
-#line 697 "src/parse-gram.y" /* yacc.c:1652  */
+#line 702 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2936 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2949 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 109:
-#line 698 "src/parse-gram.y" /* yacc.c:1652  */
+#line 703 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
-#line 2942 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2955 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 110:
-#line 699 "src/parse-gram.y" /* yacc.c:1652  */
+#line 704 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
-#line 2948 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2961 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 111:
-#line 700 "src/parse-gram.y" /* yacc.c:1652  */
+#line 705 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
-#line 2954 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2967 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 112:
-#line 713 "src/parse-gram.y" /* yacc.c:1652  */
+#line 718 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
-#line 2960 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2973 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 113:
-#line 715 "src/parse-gram.y" /* yacc.c:1652  */
+#line 720 "src/parse-gram.y" /* yacc.c:1652  */
     {
       if (current_class == nterm_sym)
         {
@@ -2972,41 +2985,41 @@ yyreduce:
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
     }
-#line 2976 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2989 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 114:
-#line 729 "src/parse-gram.y" /* yacc.c:1652  */
+#line 734 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
-#line 2982 "src/parse-gram.c" /* yacc.c:1652  */
+#line 2995 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 117:
-#line 741 "src/parse-gram.y" /* yacc.c:1652  */
+#line 746 "src/parse-gram.y" /* yacc.c:1652  */
     {
       (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
-#line 2991 "src/parse-gram.c" /* yacc.c:1652  */
+#line 3004 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 118:
-#line 749 "src/parse-gram.y" /* yacc.c:1652  */
+#line 754 "src/parse-gram.y" /* yacc.c:1652  */
     { (yyval.yytype_98) = NULL; }
-#line 2997 "src/parse-gram.c" /* yacc.c:1652  */
+#line 3010 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
   case 121:
-#line 756 "src/parse-gram.y" /* yacc.c:1652  */
+#line 761 "src/parse-gram.y" /* yacc.c:1652  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 3006 "src/parse-gram.c" /* yacc.c:1652  */
+#line 3019 "src/parse-gram.c" /* yacc.c:1652  */
     break;
 
 
-#line 3010 "src/parse-gram.c" /* yacc.c:1652  */
+#line 3023 "src/parse-gram.c" /* yacc.c:1652  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3255,7 +3268,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 762 "src/parse-gram.y" /* yacc.c:1918  */
+#line 767 "src/parse-gram.y" /* yacc.c:1918  */
 
 
 /* Return the location of the left-hand side of a rule whose
@@ -3369,6 +3382,30 @@ handle_error_verbose (location const *loc, char const *directive)
 }
 
 
+static void
+handle_file_prefix (location const *loc,
+                    location const *dir_loc,
+                    char const *directive, char const *value)
+{
+  bison_directive (loc, directive);
+  bool warned = false;
+
+  if (location_empty (spec_file_prefix_loc))
+    {
+      spec_file_prefix_loc = *loc;
+      spec_file_prefix = value;
+    }
+  else
+    {
+      duplicate_directive (directive, spec_file_prefix_loc, *loc);
+      warned = true;
+    }
+
+  if (!warned
+      && STRNEQ (directive, "%file-prefix"))
+    deprecated_directive (dir_loc, directive, "%file-prefix");
+}
+
 static void
 handle_name_prefix (location const *loc,
                     char const *directive, char const *value)
