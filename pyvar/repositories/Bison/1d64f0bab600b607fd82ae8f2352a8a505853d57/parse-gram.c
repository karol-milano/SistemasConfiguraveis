@@ -1,7 +1,7 @@
-/* A Bison parser, made by GNU Bison 1.875.  */
+/* A Bison parser, made by GNU Bison 1.875a.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
-   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -157,7 +157,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 31 "parse-gram.y"
+#line 32 "parse-gram.y"
 
 #include "system.h"
 
@@ -212,7 +212,7 @@ int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 74 "parse-gram.y"
+#line 75 "parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -222,7 +222,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 225 "parse-gram.c"
+#line 226 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -246,7 +246,7 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 249 "parse-gram.c"
+#line 250 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -442,14 +442,14 @@ static const yysigned_char yyrhs[] =
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
 static const unsigned short yyrline[] =
 {
-       0,   160,   160,   168,   170,   174,   175,   176,   177,   178,
-     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
-     189,   190,   191,   192,   193,   194,   198,   199,   200,   204,
-     210,   217,   227,   227,   232,   232,   237,   247,   262,   263,
-     264,   268,   269,   275,   276,   281,   285,   290,   296,   302,
-     313,   314,   323,   324,   330,   331,   336,   340,   344,   344,
-     348,   349,   354,   355,   357,   359,   361,   363,   368,   369,
-     373,   379,   388,   395,   397
+       0,   161,   161,   169,   171,   175,   176,   177,   178,   179,
+     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
+     190,   191,   192,   193,   194,   195,   199,   200,   201,   205,
+     211,   218,   228,   228,   233,   233,   238,   248,   263,   264,
+     265,   269,   270,   276,   277,   282,   286,   291,   297,   303,
+     314,   315,   324,   325,   331,   332,   337,   341,   345,   345,
+     349,   350,   355,   356,   358,   360,   362,   364,   369,   370,
+     374,   380,   389,   396,   398
 };
 #endif
 
@@ -1249,109 +1249,109 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 175 "parse-gram.y"
+#line 176 "parse-gram.y"
     { prologue_augment (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 7:
-#line 176 "parse-gram.y"
+#line 177 "parse-gram.y"
     { debug_flag = 1; }
     break;
 
   case 8:
-#line 177 "parse-gram.y"
+#line 178 "parse-gram.y"
     { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
     break;
 
   case 9:
-#line 178 "parse-gram.y"
+#line 179 "parse-gram.y"
     { defines_flag = 1; }
     break;
 
   case 10:
-#line 179 "parse-gram.y"
+#line 180 "parse-gram.y"
     { error_verbose = 1; }
     break;
 
   case 11:
-#line 180 "parse-gram.y"
+#line 181 "parse-gram.y"
     { expected_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 181 "parse-gram.y"
+#line 182 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].chars; }
     break;
 
   case 13:
-#line 182 "parse-gram.y"
+#line 183 "parse-gram.y"
     { glr_parser = 1; }
     break;
 
   case 14:
-#line 183 "parse-gram.y"
+#line 184 "parse-gram.y"
     { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 15:
-#line 184 "parse-gram.y"
+#line 185 "parse-gram.y"
     { locations_flag = 1; }
     break;
 
   case 16:
-#line 185 "parse-gram.y"
+#line 186 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].chars; }
     break;
 
   case 17:
-#line 186 "parse-gram.y"
+#line 187 "parse-gram.y"
     { no_lines_flag = 1; }
     break;
 
   case 18:
-#line 187 "parse-gram.y"
+#line 188 "parse-gram.y"
     { spec_outfile = yyvsp[0].chars; }
     break;
 
   case 19:
-#line 188 "parse-gram.y"
+#line 189 "parse-gram.y"
     { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 20:
-#line 189 "parse-gram.y"
+#line 190 "parse-gram.y"
     { pure_parser = 1; }
     break;
 
   case 21:
-#line 190 "parse-gram.y"
+#line 191 "parse-gram.y"
     { skeleton = yyvsp[0].chars; }
     break;
 
   case 22:
-#line 191 "parse-gram.y"
+#line 192 "parse-gram.y"
     { token_table_flag = 1; }
     break;
 
   case 23:
-#line 192 "parse-gram.y"
+#line 193 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 24:
-#line 193 "parse-gram.y"
+#line 194 "parse-gram.y"
     { yacc_flag = 1; }
     break;
 
   case 28:
-#line 201 "parse-gram.y"
+#line 202 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 29:
-#line 205 "parse-gram.y"
+#line 206 "parse-gram.y"
     {
       typed = 1;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
@@ -1360,7 +1360,7 @@ yyreduce:
     break;
 
   case 30:
-#line 211 "parse-gram.y"
+#line 212 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1370,7 +1370,7 @@ yyreduce:
     break;
 
   case 31:
-#line 218 "parse-gram.y"
+#line 219 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1380,12 +1380,12 @@ yyreduce:
     break;
 
   case 32:
-#line 227 "parse-gram.y"
+#line 228 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 33:
-#line 228 "parse-gram.y"
+#line 229 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1393,12 +1393,12 @@ yyreduce:
     break;
 
   case 34:
-#line 232 "parse-gram.y"
+#line 233 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 35:
-#line 233 "parse-gram.y"
+#line 234 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1406,7 +1406,7 @@ yyreduce:
     break;
 
   case 36:
-#line 238 "parse-gram.y"
+#line 239 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1416,7 +1416,7 @@ yyreduce:
     break;
 
   case 37:
-#line 248 "parse-gram.y"
+#line 249 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1431,49 +1431,49 @@ yyreduce:
     break;
 
   case 38:
-#line 262 "parse-gram.y"
+#line 263 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 39:
-#line 263 "parse-gram.y"
+#line 264 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 40:
-#line 264 "parse-gram.y"
+#line 265 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 41:
-#line 268 "parse-gram.y"
+#line 269 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 42:
-#line 269 "parse-gram.y"
+#line 270 "parse-gram.y"
     { current_type = yyvsp[0].uniqstr; }
     break;
 
   case 43:
-#line 275 "parse-gram.y"
+#line 276 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 44:
-#line 276 "parse-gram.y"
+#line 277 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 45:
-#line 282 "parse-gram.y"
+#line 283 "parse-gram.y"
     {
        current_type = yyvsp[0].uniqstr;
      }
     break;
 
   case 46:
-#line 286 "parse-gram.y"
+#line 287 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
@@ -1481,7 +1481,7 @@ yyreduce:
     break;
 
   case 47:
-#line 291 "parse-gram.y"
+#line 292 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1490,7 +1490,7 @@ yyreduce:
     break;
 
   case 48:
-#line 297 "parse-gram.y"
+#line 298 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1499,7 +1499,7 @@ yyreduce:
     break;
 
   case 49:
-#line 303 "parse-gram.y"
+#line 304 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1509,7 +1509,7 @@ yyreduce:
     break;
 
   case 55:
-#line 332 "parse-gram.y"
+#line 333 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
@@ -1517,74 +1517,74 @@ yyreduce:
     break;
 
   case 56:
-#line 337 "parse-gram.y"
+#line 338 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 58:
-#line 344 "parse-gram.y"
+#line 345 "parse-gram.y"
     { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
   case 60:
-#line 348 "parse-gram.y"
+#line 349 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 61:
-#line 349 "parse-gram.y"
+#line 350 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 62:
-#line 354 "parse-gram.y"
+#line 355 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 63:
-#line 356 "parse-gram.y"
+#line 357 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 64:
-#line 358 "parse-gram.y"
+#line 359 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 65:
-#line 360 "parse-gram.y"
+#line 361 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 66:
-#line 362 "parse-gram.y"
+#line 363 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 67:
-#line 364 "parse-gram.y"
+#line 365 "parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
     break;
 
   case 68:
-#line 368 "parse-gram.y"
+#line 369 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 69:
-#line 369 "parse-gram.y"
+#line 370 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 70:
-#line 374 "parse-gram.y"
+#line 375 "parse-gram.y"
     { yyval.chars = yyvsp[0].chars; }
     break;
 
   case 71:
-#line 380 "parse-gram.y"
+#line 381 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
@@ -1592,7 +1592,7 @@ yyreduce:
     break;
 
   case 72:
-#line 389 "parse-gram.y"
+#line 390 "parse-gram.y"
     {
       yyval.chars = yyvsp[0].chars + 1;
       yyval.chars[strlen (yyval.chars) - 1] = '\0';
@@ -1600,7 +1600,7 @@ yyreduce:
     break;
 
   case 74:
-#line 398 "parse-gram.y"
+#line 399 "parse-gram.y"
     {
       epilogue_augment (yyvsp[0].chars, yylsp[0]);
       scanner_last_string_free ();
@@ -1611,7 +1611,7 @@ yyreduce:
     }
 
 /* Line 991 of yacc.c.  */
-#line 1614 "parse-gram.c"
+#line 1615 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1734,9 +1734,13 @@ yyerrlab:
 yyerrlab1:
 
   /* Suppress GCC warning that yyerrlab1 is unused when no action
-     invokes YYERROR.  */
+     invokes YYERROR.  MacOS 10.2.3's buggy "smart preprocessor"
+     insists on the trailing semicolon.  */
 #if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
-  __attribute__ ((__unused__))
+  /* GNU C++ (as of version 3.2.1) does not allow attributes on labels.  */
+# ifndef __cplusplus
+  __attribute__ ((__unused__));
+# endif
 #endif
 
   yylerrsp = yylsp;
@@ -1822,7 +1826,7 @@ yyreturn:
 }
 
 
-#line 404 "parse-gram.y"
+#line 405 "parse-gram.y"
 
 
 
@@ -1835,8 +1839,8 @@ static YYLTYPE
 lloc_default (YYLTYPE const *rhs, int n)
 {
   int i;
-  YYLTYPE r;
-  r.start = r.end = rhs[n].end;
+  YYLTYPE loc;
+  loc.start = loc.end = rhs[n].end;
 
   /* Ignore empty nonterminals the start of the the right-hand side.
      Do not bother to ignore them at the end of the right-hand side,
@@ -1844,11 +1848,11 @@ lloc_default (YYLTYPE const *rhs, int n)
   for (i = 1; i <= n; i++)
     if (! equal_boundaries (rhs[i].start, rhs[i].end))
       {
-	r.start = rhs[i].start;
+	loc.start = rhs[i].start;
 	break;
       }
 
-  return r;
+  return loc;
 }
 
 
