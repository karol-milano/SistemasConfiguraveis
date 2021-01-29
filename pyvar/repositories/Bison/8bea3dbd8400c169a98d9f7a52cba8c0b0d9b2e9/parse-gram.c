@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.82-67f8.  */
+/* A Bison parser, made by GNU Bison 2.4.1.86-ae09ec.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.82-67f8"
+#define YYBISON_VERSION "2.4.1.86-ae09ec"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -105,10 +105,10 @@
 #include "getargs.h"
 #include "gram.h"
 #include "muscle_tab.h"
+#include "named-ref.h"
 #include "quotearg.h"
 #include "reader.h"
 #include "symlist.h"
-#include "named-ref.h"
 #include "scan-gram.h"
 #include "scan-code.h"
 
@@ -152,7 +152,7 @@ static int current_prec = 0;
 
 
 /* Line 190 of yacc.c  */
-#line 156 "../../bison-2.5/src/parse-gram.c"
+#line 156 "../../branch-2.5/src/parse-gram.c"
 
 /* Enabling traces.  */
 #ifndef YYDEBUG
@@ -318,7 +318,7 @@ typedef union YYSTYPE
 
 
 /* Line 215 of yacc.c  */
-#line 322 "../../bison-2.5/src/parse-gram.c"
+#line 322 "../../branch-2.5/src/parse-gram.c"
 } YYSTYPE;
 # define YYSTYPE_IS_TRIVIAL 1
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
@@ -343,7 +343,7 @@ typedef struct YYLTYPE
 
 
 /* Line 265 of yacc.c  */
-#line 347 "../../bison-2.5/src/parse-gram.c"
+#line 347 "../../branch-2.5/src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -678,8 +678,8 @@ static const yytype_uint16 yyrline[] =
      442,   443,   448,   450,   455,   456,   460,   461,   462,   463,
      468,   473,   478,   484,   490,   501,   502,   511,   512,   518,
      519,   520,   527,   527,   532,   533,   534,   539,   541,   543,
-     545,   547,   549,   555,   557,   569,   570,   575,   576,   585,
-     605,   607,   616,   621,   622,   627,   634,   636
+     545,   547,   549,   554,   556,   567,   568,   573,   574,   583,
+     603,   605,   614,   619,   620,   625,   632,   634
 };
 #endif
 
@@ -701,9 +701,9 @@ static const char *const yytname[] =
   "\"%start\"", "\"%token-table\"", "\"%verbose\"", "\"%yacc\"",
   "\"{...}\"", "\"char\"", "\"epilogue\"", "\"=\"", "\"identifier\"",
   "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"", "\";\"", "\"type\"",
-  "\"<*>\"", "\"<>\"", "\"[id]\"", "\"%union\"", "$accept", "input",
-  "prologue_declarations", "prologue_declaration", "grammar_declaration",
-  "union_name", "symbol_declaration", "$@1", "$@2",
+  "\"<*>\"", "\"<>\"", "\"[identifier]\"", "\"%union\"", "$accept",
+  "input", "prologue_declarations", "prologue_declaration",
+  "grammar_declaration", "union_name", "symbol_declaration", "$@1", "$@2",
   "precedence_declaration", "precedence_declarator", "type.opt",
   "symbols.prec", "symbol.prec", "symbols.1", "generic_symlist",
   "generic_symlist_item", "symbol_def", "symbol_defs.1", "grammar",
@@ -1039,7 +1039,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (quotearg_style (c_quoting_style, (yyvaluep->chars)), stderr); };
 
 /* Line 716 of yacc.c  */
-#line 1043 "../../bison-2.5/src/parse-gram.c"
+#line 1043 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 
@@ -1048,7 +1048,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
 
 /* Line 716 of yacc.c  */
-#line 1052 "../../bison-2.5/src/parse-gram.c"
+#line 1052 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 43: /* "\"{...}\"" */
 
@@ -1057,7 +1057,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->code)); };
 
 /* Line 716 of yacc.c  */
-#line 1061 "../../bison-2.5/src/parse-gram.c"
+#line 1061 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 44: /* "\"char\"" */
 
@@ -1066,7 +1066,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs (char_name ((yyvaluep->character)), stderr); };
 
 /* Line 716 of yacc.c  */
-#line 1070 "../../bison-2.5/src/parse-gram.c"
+#line 1070 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 45: /* "\"epilogue\"" */
 
@@ -1075,7 +1075,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 716 of yacc.c  */
-#line 1079 "../../bison-2.5/src/parse-gram.c"
+#line 1079 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 47: /* "\"identifier\"" */
 
@@ -1084,7 +1084,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 716 of yacc.c  */
-#line 1088 "../../bison-2.5/src/parse-gram.c"
+#line 1088 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 48: /* "\"identifier:\"" */
 
@@ -1093,7 +1093,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", (yyvaluep->uniqstr)); };
 
 /* Line 716 of yacc.c  */
-#line 1097 "../../bison-2.5/src/parse-gram.c"
+#line 1097 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 51: /* "\"%{...%}\"" */
 
@@ -1102,7 +1102,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 716 of yacc.c  */
-#line 1106 "../../bison-2.5/src/parse-gram.c"
+#line 1106 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 53: /* "\"type\"" */
 
@@ -1111,7 +1111,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
 
 /* Line 716 of yacc.c  */
-#line 1115 "../../bison-2.5/src/parse-gram.c"
+#line 1115 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 84: /* "variable" */
 
@@ -1120,7 +1120,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fputs ((yyvaluep->uniqstr), stderr); };
 
 /* Line 716 of yacc.c  */
-#line 1124 "../../bison-2.5/src/parse-gram.c"
+#line 1124 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 85: /* "content.opt" */
 
@@ -1129,7 +1129,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 716 of yacc.c  */
-#line 1133 "../../bison-2.5/src/parse-gram.c"
+#line 1133 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 86: /* "braceless" */
 
@@ -1138,7 +1138,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
 
 /* Line 716 of yacc.c  */
-#line 1142 "../../bison-2.5/src/parse-gram.c"
+#line 1142 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 87: /* "id" */
 
@@ -1147,7 +1147,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 716 of yacc.c  */
-#line 1151 "../../bison-2.5/src/parse-gram.c"
+#line 1151 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 88: /* "id_colon" */
 
@@ -1156,7 +1156,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
 
 /* Line 716 of yacc.c  */
-#line 1160 "../../bison-2.5/src/parse-gram.c"
+#line 1160 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 89: /* "symbol" */
 
@@ -1165,7 +1165,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 716 of yacc.c  */
-#line 1169 "../../bison-2.5/src/parse-gram.c"
+#line 1169 "../../branch-2.5/src/parse-gram.c"
 	break;
       case 90: /* "string_as_id" */
 
@@ -1174,7 +1174,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
 
 /* Line 716 of yacc.c  */
-#line 1178 "../../bison-2.5/src/parse-gram.c"
+#line 1178 "../../branch-2.5/src/parse-gram.c"
 	break;
       default:
 	break;
@@ -1703,7 +1703,7 @@ YYLTYPE yylloc;
 }
 
 /* Line 1243 of yacc.c  */
-#line 1707 "../../bison-2.5/src/parse-gram.c"
+#line 1707 "../../branch-2.5/src/parse-gram.c"
   yylsp[0] = yylloc;
 
   goto yysetstate;
@@ -2555,35 +2555,35 @@ yyreduce:
   case 93:
 
 /* Line 1456 of yacc.c  */
-#line 555 "parse-gram.y"
+#line 554 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
 
 /* Line 1456 of yacc.c  */
-#line 558 "parse-gram.y"
+#line 556 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
 
 /* Line 1456 of yacc.c  */
-#line 570 "parse-gram.y"
+#line 568 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
 
 /* Line 1456 of yacc.c  */
-#line 575 "parse-gram.y"
+#line 573 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 99:
 
 /* Line 1456 of yacc.c  */
-#line 586 "parse-gram.y"
+#line 584 "parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[(1) - (1)].code)[strlen ((yyvsp[(1) - (1)].code)) - 1] = '\n';
@@ -2597,14 +2597,14 @@ yyreduce:
   case 100:
 
 /* Line 1456 of yacc.c  */
-#line 606 "parse-gram.y"
+#line 604 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 101:
 
 /* Line 1456 of yacc.c  */
-#line 608 "parse-gram.y"
+#line 606 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2615,14 +2615,14 @@ yyreduce:
   case 102:
 
 /* Line 1456 of yacc.c  */
-#line 616 "parse-gram.y"
+#line 614 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 105:
 
 /* Line 1456 of yacc.c  */
-#line 628 "parse-gram.y"
+#line 626 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[(1) - (1)]), false);
@@ -2632,7 +2632,7 @@ yyreduce:
   case 107:
 
 /* Line 1456 of yacc.c  */
-#line 637 "parse-gram.y"
+#line 635 "parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[(2) - (2)].chars), (yylsp[(2) - (2)]));
@@ -2646,7 +2646,7 @@ yyreduce:
 
 
 /* Line 1456 of yacc.c  */
-#line 2650 "../../bison-2.5/src/parse-gram.c"
+#line 2650 "../../branch-2.5/src/parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2865,7 +2865,7 @@ yyreturn:
 
 
 /* Line 1676 of yacc.c  */
-#line 647 "parse-gram.y"
+#line 645 "parse-gram.y"
 
 
 
