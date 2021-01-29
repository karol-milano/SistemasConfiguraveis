@@ -1,7 +1,7 @@
 /* A Bison parser, made by GNU Bison 1.875c.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
-   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -167,7 +167,7 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 32 "../../src/parse-gram.y"
+#line 32 "parse-gram.y"
 
 #include "system.h"
 
@@ -219,7 +219,7 @@ int current_prec = 0;
 #endif
 
 #if ! defined (YYSTYPE) && ! defined (YYSTYPE_IS_DECLARED)
-#line 80 "../../src/parse-gram.y"
+#line 80 "parse-gram.y"
 typedef union YYSTYPE {
   symbol *symbol;
   symbol_list *list;
@@ -229,7 +229,7 @@ typedef union YYSTYPE {
   uniqstr uniqstr;
 } YYSTYPE;
 /* Line 191 of yacc.c.  */
-#line 233 "../../src/parse-gram.c"
+#line 233 "parse-gram.c"
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
 # define YYSTYPE_IS_TRIVIAL 1
@@ -253,7 +253,7 @@ typedef struct YYLTYPE
 
 
 /* Line 214 of yacc.c.  */
-#line 257 "../../src/parse-gram.c"
+#line 257 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -302,7 +302,7 @@ typedef struct YYLTYPE
 /* A type that is properly aligned for any stack member.  */
 union yyalloc
 {
-  short yyss;
+  short int yyss;
   YYSTYPE yyvs;
     YYLTYPE yyls;
 };
@@ -313,7 +313,7 @@ union yyalloc
 /* The size of an array large to enough to hold all stacks, each with
    N elements.  */
 # define YYSTACK_BYTES(N) \
-     ((N) * (sizeof (short) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
+     ((N) * (sizeof (short int) + sizeof (YYSTYPE) + sizeof (YYLTYPE))	\
       + 2 * YYSTACK_GAP_MAXIMUM)
 
 /* Copy COUNT objects from FROM to TO.  The source and destination do
@@ -355,7 +355,7 @@ union yyalloc
 #if defined (__STDC__) || defined (__cplusplus)
    typedef signed char yysigned_char;
 #else
-   typedef short yysigned_char;
+   typedef short int yysigned_char;
 #endif
 
 /* YYFINAL -- State number of the termination state. */
@@ -457,7 +457,7 @@ static const yysigned_char yyrhs[] =
 };
 
 /* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
-static const unsigned short yyrline[] =
+static const unsigned short int yyrline[] =
 {
        0,   173,   173,   181,   183,   187,   188,   189,   190,   191,
      192,   193,   194,   195,   196,   201,   205,   206,   207,   208,
@@ -499,7 +499,7 @@ static const char *const yytname[] =
 # ifdef YYPRINT
 /* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
    token YYLEX-NUM.  */
-static const unsigned short yytoknum[] =
+static const unsigned short int yytoknum[] =
 {
        0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
      265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
@@ -761,12 +761,12 @@ do {								\
 
 #if defined (__STDC__) || defined (__cplusplus)
 static void
-yy_stack_print (short *bottom, short *top)
+yy_stack_print (short int *bottom, short int *top)
 #else
 static void
 yy_stack_print (bottom, top)
-    short *bottom;
-    short *top;
+    short int *bottom;
+    short int *top;
 #endif
 {
   YYFPRINTF (stderr, "Stack now");
@@ -1039,9 +1039,9 @@ YYLTYPE yylloc;
      to reallocate them elsewhere.  */
 
   /* The state stack.  */
-  short	yyssa[YYINITDEPTH];
-  short *yyss = yyssa;
-  register short *yyssp;
+  short int yyssa[YYINITDEPTH];
+  short int *yyss = yyssa;
+  register short int *yyssp;
 
   /* The semantic value stack.  */
   YYSTYPE yyvsa[YYINITDEPTH];
@@ -1084,7 +1084,7 @@ YYLTYPE yylloc;
   yylsp = yyls;
 
   /* User initialization code. */
-  #line 70 "../../src/parse-gram.y"
+  #line 70 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1093,7 +1093,7 @@ YYLTYPE yylloc;
   (*yylsp).start.column = (*yylsp).end.column = 0;
 }
 /* Line 818 of yacc.c.  */
-#line 1097 "../../src/parse-gram.c"
+#line 1097 "parse-gram.c"
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -1119,7 +1119,7 @@ YYLTYPE yylloc;
 	   these so that the &'s don't force the real ones into
 	   memory.  */
 	YYSTYPE *yyvs1 = yyvs;
-	short *yyss1 = yyss;
+	short int *yyss1 = yyss;
 	YYLTYPE *yyls1 = yyls;
 
 	/* Each stack pointer address is followed by the size of the
@@ -1147,7 +1147,7 @@ YYLTYPE yylloc;
 	yystacksize = YYMAXDEPTH;
 
       {
-	short *yyss1 = yyss;
+	short int *yyss1 = yyss;
 	union yyalloc *yyptr =
 	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
 	if (! yyptr)
@@ -1281,47 +1281,47 @@ yyreduce:
   switch (yyn)
     {
         case 6:
-#line 188 "../../src/parse-gram.y"
+#line 188 "parse-gram.y"
     { prologue_augment (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 7:
-#line 189 "../../src/parse-gram.y"
+#line 189 "parse-gram.y"
     { debug_flag = true; }
     break;
 
   case 8:
-#line 190 "../../src/parse-gram.y"
+#line 190 "parse-gram.y"
     { muscle_insert (yyvsp[-1].chars, yyvsp[0].chars); }
     break;
 
   case 9:
-#line 191 "../../src/parse-gram.y"
+#line 191 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-#line 192 "../../src/parse-gram.y"
+#line 192 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 11:
-#line 193 "../../src/parse-gram.y"
+#line 193 "parse-gram.y"
     { expected_sr_conflicts = yyvsp[0].integer; }
     break;
 
   case 12:
-#line 194 "../../src/parse-gram.y"
+#line 194 "parse-gram.y"
     { expected_rr_conflicts = yyvsp[0].integer; }
     break;
 
   case 13:
-#line 195 "../../src/parse-gram.y"
+#line 195 "parse-gram.y"
     { spec_file_prefix = yyvsp[0].chars; }
     break;
 
   case 14:
-#line 197 "../../src/parse-gram.y"
+#line 197 "parse-gram.y"
     {
     nondeterministic_parser = true;
     glr_parser = true;
@@ -1329,81 +1329,81 @@ yyreduce:
     break;
 
   case 15:
-#line 202 "../../src/parse-gram.y"
+#line 202 "parse-gram.y"
     {
     muscle_code_grow ("initial_action", yyvsp[0].chars, yylsp[0]);
   }
     break;
 
   case 16:
-#line 205 "../../src/parse-gram.y"
+#line 205 "parse-gram.y"
     { add_param ("lex_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 17:
-#line 206 "../../src/parse-gram.y"
+#line 206 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 18:
-#line 207 "../../src/parse-gram.y"
+#line 207 "parse-gram.y"
     { spec_name_prefix = yyvsp[0].chars; }
     break;
 
   case 19:
-#line 208 "../../src/parse-gram.y"
+#line 208 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 20:
-#line 209 "../../src/parse-gram.y"
+#line 209 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 21:
-#line 210 "../../src/parse-gram.y"
+#line 210 "parse-gram.y"
     { spec_outfile = yyvsp[0].chars; }
     break;
 
   case 22:
-#line 211 "../../src/parse-gram.y"
+#line 211 "parse-gram.y"
     { add_param ("parse_param", yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 23:
-#line 212 "../../src/parse-gram.y"
+#line 212 "parse-gram.y"
     { pure_parser = true; }
     break;
 
   case 24:
-#line 213 "../../src/parse-gram.y"
+#line 213 "parse-gram.y"
     { skeleton = yyvsp[0].chars; }
     break;
 
   case 25:
-#line 214 "../../src/parse-gram.y"
+#line 214 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 26:
-#line 215 "../../src/parse-gram.y"
+#line 215 "parse-gram.y"
     { report_flag = report_states; }
     break;
 
   case 27:
-#line 216 "../../src/parse-gram.y"
+#line 216 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 31:
-#line 224 "../../src/parse-gram.y"
+#line 224 "parse-gram.y"
     {
       grammar_start_symbol_set (yyvsp[0].symbol, yylsp[0]);
     }
     break;
 
   case 32:
-#line 228 "../../src/parse-gram.y"
+#line 228 "parse-gram.y"
     {
       typed = true;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
@@ -1412,7 +1412,7 @@ yyreduce:
     break;
 
   case 33:
-#line 234 "../../src/parse-gram.y"
+#line 234 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1422,7 +1422,7 @@ yyreduce:
     break;
 
   case 34:
-#line 241 "../../src/parse-gram.y"
+#line 241 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1432,26 +1432,26 @@ yyreduce:
     break;
 
   case 35:
-#line 248 "../../src/parse-gram.y"
+#line 248 "parse-gram.y"
     {
       default_prec = true;
     }
     break;
 
   case 36:
-#line 252 "../../src/parse-gram.y"
+#line 252 "parse-gram.y"
     {
       default_prec = false;
     }
     break;
 
   case 37:
-#line 258 "../../src/parse-gram.y"
+#line 258 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 38:
-#line 259 "../../src/parse-gram.y"
+#line 259 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1459,12 +1459,12 @@ yyreduce:
     break;
 
   case 39:
-#line 263 "../../src/parse-gram.y"
+#line 263 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 40:
-#line 264 "../../src/parse-gram.y"
+#line 264 "parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -1472,7 +1472,7 @@ yyreduce:
     break;
 
   case 41:
-#line 269 "../../src/parse-gram.y"
+#line 269 "parse-gram.y"
     {
       symbol_list *list;
       for (list = yyvsp[0].list; list; list = list->next)
@@ -1482,7 +1482,7 @@ yyreduce:
     break;
 
   case 42:
-#line 279 "../../src/parse-gram.y"
+#line 279 "parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -1497,49 +1497,49 @@ yyreduce:
     break;
 
   case 43:
-#line 293 "../../src/parse-gram.y"
+#line 293 "parse-gram.y"
     { yyval.assoc = left_assoc; }
     break;
 
   case 44:
-#line 294 "../../src/parse-gram.y"
+#line 294 "parse-gram.y"
     { yyval.assoc = right_assoc; }
     break;
 
   case 45:
-#line 295 "../../src/parse-gram.y"
+#line 295 "parse-gram.y"
     { yyval.assoc = non_assoc; }
     break;
 
   case 46:
-#line 299 "../../src/parse-gram.y"
+#line 299 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 47:
-#line 300 "../../src/parse-gram.y"
+#line 300 "parse-gram.y"
     { current_type = yyvsp[0].uniqstr; }
     break;
 
   case 48:
-#line 306 "../../src/parse-gram.y"
+#line 306 "parse-gram.y"
     { yyval.list = symbol_list_new (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 49:
-#line 307 "../../src/parse-gram.y"
+#line 307 "parse-gram.y"
     { yyval.list = symbol_list_prepend (yyvsp[-1].list, yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 50:
-#line 313 "../../src/parse-gram.y"
+#line 313 "parse-gram.y"
     {
        current_type = yyvsp[0].uniqstr;
      }
     break;
 
   case 51:
-#line 317 "../../src/parse-gram.y"
+#line 317 "parse-gram.y"
     {
        symbol_class_set (yyvsp[0].symbol, current_class, yylsp[0]);
        symbol_type_set (yyvsp[0].symbol, current_type, yylsp[0]);
@@ -1547,7 +1547,7 @@ yyreduce:
     break;
 
   case 52:
-#line 322 "../../src/parse-gram.y"
+#line 322 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1556,7 +1556,7 @@ yyreduce:
     break;
 
   case 53:
-#line 328 "../../src/parse-gram.y"
+#line 328 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-1].symbol, current_class, yylsp[-1]);
       symbol_type_set (yyvsp[-1].symbol, current_type, yylsp[-1]);
@@ -1565,7 +1565,7 @@ yyreduce:
     break;
 
   case 54:
-#line 334 "../../src/parse-gram.y"
+#line 334 "parse-gram.y"
     {
       symbol_class_set (yyvsp[-2].symbol, current_class, yylsp[-2]);
       symbol_type_set (yyvsp[-2].symbol, current_type, yylsp[-2]);
@@ -1575,7 +1575,7 @@ yyreduce:
     break;
 
   case 60:
-#line 363 "../../src/parse-gram.y"
+#line 363 "parse-gram.y"
     {
       if (yacc_flag)
 	complain_at (yyloc, _("POSIX forbids declarations in the grammar"));
@@ -1583,74 +1583,74 @@ yyreduce:
     break;
 
   case 61:
-#line 368 "../../src/parse-gram.y"
+#line 368 "parse-gram.y"
     {
       yyerrok;
     }
     break;
 
   case 62:
-#line 374 "../../src/parse-gram.y"
+#line 374 "parse-gram.y"
     { current_lhs = yyvsp[0].symbol; current_lhs_location = yylsp[0]; }
     break;
 
   case 64:
-#line 378 "../../src/parse-gram.y"
+#line 378 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 65:
-#line 379 "../../src/parse-gram.y"
+#line 379 "parse-gram.y"
     { grammar_rule_end (yylsp[0]); }
     break;
 
   case 67:
-#line 385 "../../src/parse-gram.y"
+#line 385 "parse-gram.y"
     { grammar_rule_begin (current_lhs, current_lhs_location); }
     break;
 
   case 68:
-#line 387 "../../src/parse-gram.y"
+#line 387 "parse-gram.y"
     { grammar_current_rule_symbol_append (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 69:
-#line 389 "../../src/parse-gram.y"
+#line 389 "parse-gram.y"
     { grammar_current_rule_action_append (yyvsp[0].chars, yylsp[0]); }
     break;
 
   case 70:
-#line 391 "../../src/parse-gram.y"
+#line 391 "parse-gram.y"
     { grammar_current_rule_prec_set (yyvsp[0].symbol, yylsp[0]); }
     break;
 
   case 71:
-#line 393 "../../src/parse-gram.y"
+#line 393 "parse-gram.y"
     { grammar_current_rule_dprec_set (yyvsp[0].integer, yylsp[0]); }
     break;
 
   case 72:
-#line 395 "../../src/parse-gram.y"
+#line 395 "parse-gram.y"
     { grammar_current_rule_merge_set (yyvsp[0].uniqstr, yylsp[0]); }
     break;
 
   case 73:
-#line 399 "../../src/parse-gram.y"
+#line 399 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 74:
-#line 400 "../../src/parse-gram.y"
+#line 400 "parse-gram.y"
     { yyval.symbol = yyvsp[0].symbol; }
     break;
 
   case 75:
-#line 405 "../../src/parse-gram.y"
+#line 405 "parse-gram.y"
     { yyval.chars = yyvsp[0].chars; }
     break;
 
   case 76:
-#line 411 "../../src/parse-gram.y"
+#line 411 "parse-gram.y"
     {
       yyval.symbol = symbol_get (yyvsp[0].chars, yylsp[0]);
       symbol_class_set (yyval.symbol, token_sym, yylsp[0]);
@@ -1658,7 +1658,7 @@ yyreduce:
     break;
 
   case 77:
-#line 420 "../../src/parse-gram.y"
+#line 420 "parse-gram.y"
     {
       yyval.chars = yyvsp[0].chars + 1;
       yyval.chars[strlen (yyval.chars) - 1] = '\0';
@@ -1666,7 +1666,7 @@ yyreduce:
     break;
 
   case 79:
-#line 429 "../../src/parse-gram.y"
+#line 429 "parse-gram.y"
     {
       muscle_code_grow ("epilogue", yyvsp[0].chars, yylsp[0]);
       scanner_last_string_free ();
@@ -1677,7 +1677,7 @@ yyreduce:
     }
 
 /* Line 1010 of yacc.c.  */
-#line 1681 "../../src/parse-gram.c"
+#line 1681 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
@@ -1906,7 +1906,7 @@ yyreturn:
 }
 
 
-#line 435 "../../src/parse-gram.y"
+#line 435 "parse-gram.y"
 
 
 
