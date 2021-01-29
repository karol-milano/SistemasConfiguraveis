@@ -68,6 +68,7 @@
 #include "files.h"
 #include "getargs.h"
 #include "output.h"
+#include "symlist.h"
 #include "gram.h"
 #include "reader.h"
 #include "conflicts.h"
@@ -222,16 +223,16 @@ int current_prec = 0;
 #endif
 
 #ifndef YYSTYPE
-#line 89 "parse-gram.y"
+#line 90 "parse-gram.y"
 typedef union {
   symbol_t *symbol;
-  symbol_list *list;
+  symbol_list_t *list;
   int integer;
   char *string;
   associativity assoc;
 } yystype;
 /* Line 199 of /usr/local/share/bison/bison.simple.  */
-#line 235 "parse-gram.c"
+#line 236 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -252,7 +253,7 @@ typedef struct yyltype
 
 
 /* Line 219 of /usr/local/share/bison/bison.simple.  */
-#line 256 "parse-gram.c"
+#line 257 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -447,13 +448,13 @@ static const signed char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   151,   151,   164,   166,   169,   171,   172,   173,   174,
-     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
-     185,   186,   189,   191,   192,   196,   204,   204,   210,   210,
-     215,   224,   239,   241,   242,   245,   247,   252,   254,   258,
-     263,   268,   274,   280,   290,   293,   302,   304,   310,   312,
-     315,   315,   320,   322,   325,   328,   330,   332,   336,   338,
-     339,   342,   348,   357,   365,   370,   376,   378
+       0,   152,   152,   165,   167,   170,   172,   173,   174,   175,
+     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
+     186,   187,   190,   192,   193,   197,   205,   205,   211,   211,
+     216,   225,   240,   242,   243,   246,   248,   253,   255,   259,
+     264,   269,   275,   281,   291,   294,   303,   305,   311,   313,
+     316,   316,   321,   323,   326,   329,   331,   333,   337,   339,
+     340,   343,   349,   358,   366,   371,   377,   379
 };
 #endif
 
@@ -1183,7 +1184,7 @@ yyreduce:
   switch (yyn)
     {
         case 2:
-#line 153 "parse-gram.y"
+#line 154 "parse-gram.y"
     {
       yycontrol->errcode = 0;
       epilogue_set (yyvsp[0].string, yylsp[0]);
@@ -1191,94 +1192,94 @@ yyreduce:
     break;
 
   case 6:
-#line 171 "parse-gram.y"
+#line 172 "parse-gram.y"
     { prologue_augment (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 7:
-#line 172 "parse-gram.y"
+#line 173 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 173 "parse-gram.y"
+#line 174 "parse-gram.y"
     { muscle_insert (yyvsp[-1].string, yyvsp[0].string); }
     break;
 
   case 9:
-#line 174 "parse-gram.y"
+#line 175 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 175 "parse-gram.y"
+#line 176 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 176 "parse-gram.y"
+#line 177 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 177 "parse-gram.y"
+#line 178 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].string; }
     break;
 
   case 13:
-#line 178 "parse-gram.y"
+#line 179 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 14:
-#line 179 "parse-gram.y"
+#line 180 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].string; }
     break;
 
   case 15:
-#line 180 "parse-gram.y"
+#line 181 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 16:
-#line 181 "parse-gram.y"
+#line 182 "parse-gram.y"
     { spec_outfile = yyvsp[0].string; }
     break;
 
   case 17:
-#line 182 "parse-gram.y"
+#line 183 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 18:
-#line 183 "parse-gram.y"
+#line 184 "parse-gram.y"
     { skeleton = yyvsp[0].string; }
     break;
 
   case 19:
-#line 184 "parse-gram.y"
+#line 185 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 20:
-#line 185 "parse-gram.y"
+#line 186 "parse-gram.y"
     { report_flag = 1; }
     break;
 
   case 21:
-#line 186 "parse-gram.y"
+#line 187 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 24:
-#line 193 "parse-gram.y"
+#line 194 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 25:
-#line 197 "parse-gram.y"
+#line 198 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].first_line);
@@ -1287,12 +1288,12 @@ yyreduce:
     break;
 
   case 26:
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 27:
-#line 206 "parse-gram.y"
+#line 207 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1300,12 +1301,12 @@ yyreduce:
     break;
 
   case 28:
-#line 210 "parse-gram.y"
+#line 211 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 29:
-#line 211 "parse-gram.y"
+#line 212 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1313,74 +1314,74 @@ yyreduce:
     break;
 
   case 30:
-#line 216 "parse-gram.y"
+#line 217 "parse-gram.y"
     {
-      symbol_list *list;
+      symbol_list_t *list;
       for (list = yyvsp[0].list; list; list = list->next)
 	symbol_type_set (list->sym, list->location, yyvsp[-1].string);
-      LIST_FREE (symbol_list, yyvsp[0].list);
+      LIST_FREE (symbol_list_t, yyvsp[0].list);
     }
     break;
 
   case 31:
-#line 226 "parse-gram.y"
+#line 227 "parse-gram.y"
     {
-      symbol_list *list;
+      symbol_list_t *list;
       ++current_prec;
       for (list = yyvsp[0].list; list; list = list->next)
 	{
 	  symbol_type_set (list->sym, list->location, current_type);
 	  symbol_precedence_set (list->sym, list->location, current_prec, yyvsp[-2].assoc);
 	}
-      LIST_FREE (symbol_list, yyvsp[0].list);
+      LIST_FREE (symbol_list_t, yyvsp[0].list);
       current_type = NULL;
     }
     break;
 
   case 32:
-#line 240 "parse-gram.y"
+#line 241 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 33:
-#line 241 "parse-gram.y"
+#line 242 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 34:
-#line 242 "parse-gram.y"
+#line 243 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 35:
-#line 246 "parse-gram.y"
+#line 247 "parse-gram.y"
     { current_type = NULL;}
     break;
 
   case 36:
-#line 247 "parse-gram.y"
+#line 248 "parse-gram.y"
     { current_type = yyvsp[0].string; }
     break;
 
   case 37:
-#line 253 "parse-gram.y"
+#line 254 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 38:
-#line 254 "parse-gram.y"
+#line 255 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 39:
-#line 260 "parse-gram.y"
+#line 261 "parse-gram.y"
     {
        current_type = yyvsp[0].string;
      }
     break;
 
   case 40:
-#line 264 "parse-gram.y"
+#line 265 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class);
        symbol_type_set (yyvsp[0].symbol, yylsp[0], current_type);
@@ -1388,7 +1389,7 @@ yyreduce:
     break;
 
   case 41:
-#line 269 "parse-gram.y"
+#line 270 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, yylsp[-1], current_type);
@@ -1397,7 +1398,7 @@ yyreduce:
     break;
 
   case 42:
-#line 275 "parse-gram.y"
+#line 276 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class);
       symbol_type_set (yyvsp[-1].symbol, yylsp[-1], current_type);
@@ -1406,7 +1407,7 @@ yyreduce:
     break;
 
   case 43:
-#line 281 "parse-gram.y"
+#line 282 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class);
       symbol_type_set (yyvsp[-2].symbol, yylsp[-2], current_type);
@@ -1416,77 +1417,77 @@ yyreduce:
     break;
 
   case 44:
-#line 292 "parse-gram.y"
+#line 293 "parse-gram.y"
     {;}
     break;
 
   case 45:
-#line 294 "parse-gram.y"
+#line 295 "parse-gram.y"
     {;}
     break;
 
   case 50:
-#line 316 "parse-gram.y"
+#line 317 "parse-gram.y"
     { current_lhs = yyvsp[-1].symbol; current_lhs_location = yylsp[-1]; }
     break;
 
   case 51:
-#line 317 "parse-gram.y"
+#line 318 "parse-gram.y"
     {;}
     break;
 
   case 52:
-#line 321 "parse-gram.y"
+#line 322 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 53:
-#line 322 "parse-gram.y"
+#line 323 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 54:
-#line 327 "parse-gram.y"
+#line 328 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 55:
-#line 329 "parse-gram.y"
+#line 330 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 56:
-#line 331 "parse-gram.y"
+#line 332 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 57:
-#line 333 "parse-gram.y"
+#line 334 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol); }
     break;
 
   case 58:
-#line 337 "parse-gram.y"
+#line 338 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 59:
-#line 338 "parse-gram.y"
+#line 339 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 60:
-#line 339 "parse-gram.y"
+#line 340 "parse-gram.y"
     { yyval.symbol = getsym (yyvsp[0].string, yylsp[0]); }
     break;
 
   case 61:
-#line 344 "parse-gram.y"
+#line 345 "parse-gram.y"
     { yyval.string = yyvsp[0].string; }
     break;
 
   case 62:
-#line 350 "parse-gram.y"
+#line 351 "parse-gram.y"
     {
       yyval.symbol = getsym (yyvsp[0].string, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym);
@@ -1494,7 +1495,7 @@ yyreduce:
     break;
 
   case 63:
-#line 359 "parse-gram.y"
+#line 360 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string + 1;
       yyval.string[strlen (yyval.string) - 1] = '\0';
@@ -1502,14 +1503,14 @@ yyreduce:
     break;
 
   case 64:
-#line 367 "parse-gram.y"
+#line 368 "parse-gram.y"
     {
       yyval.string = xstrdup ("");
     }
     break;
 
   case 65:
-#line 371 "parse-gram.y"
+#line 372 "parse-gram.y"
     {
       yyval.string = yyvsp[0].string;
     }
@@ -1519,7 +1520,7 @@ yyreduce:
     }
 
 /* Line 1012 of /usr/local/share/bison/bison.simple.  */
-#line 1523 "parse-gram.c"
+#line 1524 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1740,7 +1741,7 @@ yyreturn:
   return yyresult;
 }
 
-#line 380 "parse-gram.y"
+#line 381 "parse-gram.y"
 
 /*------------------------------------------------------------------.
 | When debugging the parser, display tokens' locations and values.  |
