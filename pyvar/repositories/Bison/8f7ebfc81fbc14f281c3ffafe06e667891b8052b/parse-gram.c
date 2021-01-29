@@ -244,6 +244,65 @@ static int current_prec = 0;
      PERCENT_UNION = 313
    };
 #endif
+/* Tokens.  */
+#define GRAM_EOF 0
+#define STRING 258
+#define INT 259
+#define PERCENT_TOKEN 260
+#define PERCENT_NTERM 261
+#define PERCENT_TYPE 262
+#define PERCENT_DESTRUCTOR 263
+#define PERCENT_PRINTER 264
+#define PERCENT_LEFT 265
+#define PERCENT_RIGHT 266
+#define PERCENT_NONASSOC 267
+#define PERCENT_PREC 268
+#define PERCENT_DPREC 269
+#define PERCENT_MERGE 270
+#define PERCENT_CODE 271
+#define PERCENT_DEBUG 272
+#define PERCENT_DEFAULT_PREC 273
+#define PERCENT_DEFINE 274
+#define PERCENT_DEFINES 275
+#define PERCENT_ERROR_VERBOSE 276
+#define PERCENT_EXPECT 277
+#define PERCENT_EXPECT_RR 278
+#define PERCENT_FILE_PREFIX 279
+#define PERCENT_GLR_PARSER 280
+#define PERCENT_INITIAL_ACTION 281
+#define PERCENT_LANGUAGE 282
+#define PERCENT_LEX_PARAM 283
+#define PERCENT_LOCATIONS 284
+#define PERCENT_NAME_PREFIX 285
+#define PERCENT_NO_DEFAULT_PREC 286
+#define PERCENT_NO_LINES 287
+#define PERCENT_NONDETERMINISTIC_PARSER 288
+#define PERCENT_OUTPUT 289
+#define PERCENT_PARSE_PARAM 290
+#define PERCENT_PURE_PARSER 291
+#define PERCENT_PUSH_PARSER 292
+#define PERCENT_PUSH_PULL_PARSER 293
+#define PERCENT_REQUIRE 294
+#define PERCENT_SKELETON 295
+#define PERCENT_START 296
+#define PERCENT_TOKEN_TABLE 297
+#define PERCENT_VERBOSE 298
+#define PERCENT_YACC 299
+#define BRACED_CODE 300
+#define CHAR 301
+#define EPILOGUE 302
+#define EQUAL 303
+#define ID 304
+#define ID_COLON 305
+#define PERCENT_PERCENT 306
+#define PIPE 307
+#define PROLOGUE 308
+#define SEMICOLON 309
+#define TYPE 310
+#define TYPE_TAG_ANY 311
+#define TYPE_TAG_NONE 312
+#define PERCENT_UNION 313
+
 
 
 
@@ -266,7 +325,7 @@ typedef union YYSTYPE
 
 
 /* Line 1537 of yacc.c  */
-#line 270 "parse-gram.c"
+#line 329 "parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -291,7 +350,7 @@ typedef struct YYLTYPE
 
 
 /* Line 1537 of yacc.c  */
-#line 295 "parse-gram.c"
+#line 354 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -986,7 +1045,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 1537 of yacc.c  */
-#line 990 "parse-gram.c"
+#line 1049 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
@@ -995,7 +1054,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 1537 of yacc.c  */
-#line 999 "parse-gram.c"
+#line 1058 "parse-gram.c"
 	break;
       case 45: /* "\"{...}\"" */
 
@@ -1004,7 +1063,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 1537 of yacc.c  */
-#line 1008 "parse-gram.c"
+#line 1067 "parse-gram.c"
 	break;
       case 46: /* "\"char\"" */
 
@@ -1013,7 +1072,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 1537 of yacc.c  */
-#line 1017 "parse-gram.c"
+#line 1076 "parse-gram.c"
 	break;
       case 47: /* "\"epilogue\"" */
 
@@ -1022,7 +1081,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 1537 of yacc.c  */
-#line 1026 "parse-gram.c"
+#line 1085 "parse-gram.c"
 	break;
       case 49: /* "\"identifier\"" */
 
@@ -1031,7 +1090,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 1537 of yacc.c  */
-#line 1035 "parse-gram.c"
+#line 1094 "parse-gram.c"
 	break;
       case 50: /* "\"identifier:\"" */
 
@@ -1040,7 +1099,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 1537 of yacc.c  */
-#line 1044 "parse-gram.c"
+#line 1103 "parse-gram.c"
 	break;
       case 53: /* "\"%{...%}\"" */
 
@@ -1049,7 +1108,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 1537 of yacc.c  */
-#line 1053 "parse-gram.c"
+#line 1112 "parse-gram.c"
 	break;
       case 55: /* "\"type\"" */
 
@@ -1058,7 +1117,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 1537 of yacc.c  */
-#line 1062 "parse-gram.c"
+#line 1121 "parse-gram.c"
 	break;
       case 82: /* "variable" */
 
@@ -1067,7 +1126,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 1537 of yacc.c  */
-#line 1071 "parse-gram.c"
+#line 1130 "parse-gram.c"
 	break;
       case 83: /* "content.opt" */
 
@@ -1076,7 +1135,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 1537 of yacc.c  */
-#line 1080 "parse-gram.c"
+#line 1139 "parse-gram.c"
 	break;
       case 84: /* "braceless" */
 
@@ -1085,7 +1144,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 1537 of yacc.c  */
-#line 1089 "parse-gram.c"
+#line 1148 "parse-gram.c"
 	break;
       case 85: /* "id" */
 
@@ -1094,7 +1153,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 1537 of yacc.c  */
-#line 1098 "parse-gram.c"
+#line 1157 "parse-gram.c"
 	break;
       case 86: /* "id_colon" */
 
@@ -1103,7 +1162,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 1537 of yacc.c  */
-#line 1107 "parse-gram.c"
+#line 1166 "parse-gram.c"
 	break;
       case 87: /* "symbol" */
 
@@ -1112,7 +1171,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 1537 of yacc.c  */
-#line 1116 "parse-gram.c"
+#line 1175 "parse-gram.c"
 	break;
       case 88: /* "string_as_id" */
 
@@ -1121,7 +1180,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 1537 of yacc.c  */
-#line 1125 "parse-gram.c"
+#line 1184 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1645,7 +1704,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1537 of yacc.c  */
-#line 1649 "parse-gram.c"
+#line 1708 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2535,7 +2594,7 @@ yyreduce:
 
 
 /* Line 1537 of yacc.c  */
-#line 2539 "parse-gram.c"
+#line 2598 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
