@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.395-7910-dirty.  */
+/* A Bison parser, made by GNU Bison 2.3b.445-2755.  */
 
 /* Implementation for Bison's Yacc-like parsers in C
 
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.395-7910-dirty"
+#define YYBISON_VERSION "2.3b.445-2755"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -74,7 +74,7 @@
 
 /* Copy the first part of user declarations.  */
 /* Line 191 of yacc.c  */
-#line 1 "parse-gram.y"
+#line 1 "src/parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
    Copyright (C) 2002, 2003, 2004, 2005, 2006, 2007, 2008, 2009 Free Software
@@ -298,7 +298,7 @@ static int current_prec = 0;
 typedef union YYSTYPE
 {
 /* Line 216 of yacc.c  */
-#line 94 "parse-gram.y"
+#line 94 "src/parse-gram.y"
 
   symbol *symbol;
   symbol_list *list;
@@ -990,7 +990,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 3: // "string"
 
 /* Line 653 of yacc.c  */
-#line 183 "parse-gram.y"
+#line 183 "src/parse-gram.y"
         { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); }
 /* Line 653 of yacc.c  */
 #line 997 "src/parse-gram.c"
@@ -999,7 +999,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 4: // "integer"
 
 /* Line 653 of yacc.c  */
-#line 196 "parse-gram.y"
+#line 196 "src/parse-gram.y"
         { fprintf (stderr, "%d", ((*yyvaluep).integer)); }
 /* Line 653 of yacc.c  */
 #line 1006 "src/parse-gram.c"
@@ -1008,7 +1008,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 24: // "%<flag>"
 
 /* Line 653 of yacc.c  */
-#line 192 "parse-gram.y"
+#line 192 "src/parse-gram.y"
         { fprintf (stderr, "%%%s", ((*yyvaluep).uniqstr)); }
 /* Line 653 of yacc.c  */
 #line 1015 "src/parse-gram.c"
@@ -1017,7 +1017,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 42: // "{...}"
 
 /* Line 653 of yacc.c  */
-#line 185 "parse-gram.y"
+#line 185 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); }
 /* Line 653 of yacc.c  */
 #line 1024 "src/parse-gram.c"
@@ -1026,7 +1026,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 43: // "char"
 
 /* Line 653 of yacc.c  */
-#line 177 "parse-gram.y"
+#line 177 "src/parse-gram.y"
         { fputs (char_name (((*yyvaluep).character)), stderr); }
 /* Line 653 of yacc.c  */
 #line 1033 "src/parse-gram.c"
@@ -1035,7 +1035,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 44: // "epilogue"
 
 /* Line 653 of yacc.c  */
-#line 185 "parse-gram.y"
+#line 185 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
 #line 1042 "src/parse-gram.c"
@@ -1044,7 +1044,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 46: // "identifier"
 
 /* Line 653 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 190 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 653 of yacc.c  */
 #line 1051 "src/parse-gram.c"
@@ -1053,7 +1053,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 47: // "identifier:"
 
 /* Line 653 of yacc.c  */
-#line 191 "parse-gram.y"
+#line 191 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); }
 /* Line 653 of yacc.c  */
 #line 1060 "src/parse-gram.c"
@@ -1062,7 +1062,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 50: // "%{...%}"
 
 /* Line 653 of yacc.c  */
-#line 185 "parse-gram.y"
+#line 185 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
 #line 1069 "src/parse-gram.c"
@@ -1071,7 +1071,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 52: // "<tag>"
 
 /* Line 653 of yacc.c  */
-#line 193 "parse-gram.y"
+#line 193 "src/parse-gram.y"
         { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); }
 /* Line 653 of yacc.c  */
 #line 1078 "src/parse-gram.c"
@@ -1080,7 +1080,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 83: // variable
 
 /* Line 653 of yacc.c  */
-#line 190 "parse-gram.y"
+#line 190 "src/parse-gram.y"
         { fputs (((*yyvaluep).uniqstr), stderr); }
 /* Line 653 of yacc.c  */
 #line 1087 "src/parse-gram.c"
@@ -1089,7 +1089,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 84: // content.opt
 
 /* Line 653 of yacc.c  */
-#line 185 "parse-gram.y"
+#line 185 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
 #line 1096 "src/parse-gram.c"
@@ -1098,7 +1098,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 85: // braceless
 
 /* Line 653 of yacc.c  */
-#line 185 "parse-gram.y"
+#line 185 "src/parse-gram.y"
         { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); }
 /* Line 653 of yacc.c  */
 #line 1105 "src/parse-gram.c"
@@ -1107,7 +1107,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 86: // id
 
 /* Line 653 of yacc.c  */
-#line 199 "parse-gram.y"
+#line 199 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
 #line 1114 "src/parse-gram.c"
@@ -1116,7 +1116,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 87: // id_colon
 
 /* Line 653 of yacc.c  */
-#line 200 "parse-gram.y"
+#line 200 "src/parse-gram.y"
         { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
 #line 1123 "src/parse-gram.c"
@@ -1125,7 +1125,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 88: // symbol
 
 /* Line 653 of yacc.c  */
-#line 199 "parse-gram.y"
+#line 199 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
 #line 1132 "src/parse-gram.c"
@@ -1134,7 +1134,7 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
             case 89: // string_as_id
 
 /* Line 653 of yacc.c  */
-#line 199 "parse-gram.y"
+#line 199 "src/parse-gram.y"
         { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); }
 /* Line 653 of yacc.c  */
 #line 1141 "src/parse-gram.c"
@@ -1653,7 +1653,7 @@ YYLTYPE yylloc;
 
 /* User initialization code.  */
 /* Line 1175 of yacc.c  */
-#line 86 "parse-gram.y"
+#line 86 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1848,7 +1848,7 @@ yyreduce:
     {
         case 6:
 /* Line 1388 of yacc.c  */
-#line 223 "parse-gram.y"
+#line 223 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -1864,7 +1864,7 @@ yyreduce:
 
   case 7:
 /* Line 1388 of yacc.c  */
-#line 233 "parse-gram.y"
+#line 233 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
@@ -1874,7 +1874,7 @@ yyreduce:
 
   case 8:
 /* Line 1388 of yacc.c  */
-#line 237 "parse-gram.y"
+#line 237 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars),
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
@@ -1885,7 +1885,7 @@ yyreduce:
 
   case 9:
 /* Line 1388 of yacc.c  */
-#line 241 "parse-gram.y"
+#line 241 "src/parse-gram.y"
     { defines_flag = true; }
 /* Line 1388 of yacc.c  */
 #line 1892 "src/parse-gram.c"
@@ -1893,7 +1893,7 @@ yyreduce:
 
   case 10:
 /* Line 1388 of yacc.c  */
-#line 243 "parse-gram.y"
+#line 243 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
@@ -1904,7 +1904,7 @@ yyreduce:
 
   case 11:
 /* Line 1388 of yacc.c  */
-#line 248 "parse-gram.y"
+#line 248 "src/parse-gram.y"
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
@@ -1915,7 +1915,7 @@ yyreduce:
 
   case 12:
 /* Line 1388 of yacc.c  */
-#line 252 "parse-gram.y"
+#line 252 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].integer); }
 /* Line 1388 of yacc.c  */
 #line 1922 "src/parse-gram.c"
@@ -1923,7 +1923,7 @@ yyreduce:
 
   case 13:
 /* Line 1388 of yacc.c  */
-#line 253 "parse-gram.y"
+#line 253 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].integer); }
 /* Line 1388 of yacc.c  */
 #line 1930 "src/parse-gram.c"
@@ -1931,7 +1931,7 @@ yyreduce:
 
   case 14:
 /* Line 1388 of yacc.c  */
-#line 254 "parse-gram.y"
+#line 254 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
 #line 1938 "src/parse-gram.c"
@@ -1939,7 +1939,7 @@ yyreduce:
 
   case 15:
 /* Line 1388 of yacc.c  */
-#line 255 "parse-gram.y"
+#line 255 "src/parse-gram.y"
     { spec_file_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
 #line 1946 "src/parse-gram.c"
@@ -1947,7 +1947,7 @@ yyreduce:
 
   case 16:
 /* Line 1388 of yacc.c  */
-#line 257 "parse-gram.y"
+#line 257 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
@@ -1958,7 +1958,7 @@ yyreduce:
 
   case 17:
 /* Line 1388 of yacc.c  */
-#line 262 "parse-gram.y"
+#line 262 "src/parse-gram.y"
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -1973,7 +1973,7 @@ yyreduce:
 
   case 18:
 /* Line 1388 of yacc.c  */
-#line 270 "parse-gram.y"
+#line 270 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
 /* Line 1388 of yacc.c  */
 #line 1980 "src/parse-gram.c"
@@ -1981,7 +1981,7 @@ yyreduce:
 
   case 19:
 /* Line 1388 of yacc.c  */
-#line 271 "parse-gram.y"
+#line 271 "src/parse-gram.y"
     { add_param ("lex_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 1988 "src/parse-gram.c"
@@ -1989,7 +1989,7 @@ yyreduce:
 
   case 20:
 /* Line 1388 of yacc.c  */
-#line 272 "parse-gram.y"
+#line 272 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
 #line 1996 "src/parse-gram.c"
@@ -1997,7 +1997,7 @@ yyreduce:
 
   case 21:
 /* Line 1388 of yacc.c  */
-#line 273 "parse-gram.y"
+#line 273 "src/parse-gram.y"
     { spec_name_prefix = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
 #line 2004 "src/parse-gram.c"
@@ -2005,7 +2005,7 @@ yyreduce:
 
   case 22:
 /* Line 1388 of yacc.c  */
-#line 274 "parse-gram.y"
+#line 274 "src/parse-gram.y"
     { no_lines_flag = true; }
 /* Line 1388 of yacc.c  */
 #line 2012 "src/parse-gram.c"
@@ -2013,7 +2013,7 @@ yyreduce:
 
   case 23:
 /* Line 1388 of yacc.c  */
-#line 275 "parse-gram.y"
+#line 275 "src/parse-gram.y"
     { nondeterministic_parser = true; }
 /* Line 1388 of yacc.c  */
 #line 2020 "src/parse-gram.c"
@@ -2021,7 +2021,7 @@ yyreduce:
 
   case 24:
 /* Line 1388 of yacc.c  */
-#line 276 "parse-gram.y"
+#line 276 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
 #line 2028 "src/parse-gram.c"
@@ -2029,7 +2029,7 @@ yyreduce:
 
   case 25:
 /* Line 1388 of yacc.c  */
-#line 277 "parse-gram.y"
+#line 277 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].chars); }
 /* Line 1388 of yacc.c  */
 #line 2036 "src/parse-gram.c"
@@ -2037,7 +2037,7 @@ yyreduce:
 
   case 26:
 /* Line 1388 of yacc.c  */
-#line 278 "parse-gram.y"
+#line 278 "src/parse-gram.y"
     { add_param ("parse_param", (yyvsp[0].code), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2044 "src/parse-gram.c"
@@ -2045,7 +2045,7 @@ yyreduce:
 
   case 27:
 /* Line 1388 of yacc.c  */
-#line 279 "parse-gram.y"
+#line 279 "src/parse-gram.y"
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
 /* Line 1388 of yacc.c  */
 #line 2052 "src/parse-gram.c"
@@ -2053,7 +2053,7 @@ yyreduce:
 
   case 28:
 /* Line 1388 of yacc.c  */
-#line 281 "parse-gram.y"
+#line 281 "src/parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2083,7 +2083,7 @@ yyreduce:
 
   case 29:
 /* Line 1388 of yacc.c  */
-#line 304 "parse-gram.y"
+#line 304 "src/parse-gram.y"
     { token_table_flag = true; }
 /* Line 1388 of yacc.c  */
 #line 2090 "src/parse-gram.c"
@@ -2091,7 +2091,7 @@ yyreduce:
 
   case 30:
 /* Line 1388 of yacc.c  */
-#line 305 "parse-gram.y"
+#line 305 "src/parse-gram.y"
     { report_flag |= report_states; }
 /* Line 1388 of yacc.c  */
 #line 2098 "src/parse-gram.c"
@@ -2099,7 +2099,7 @@ yyreduce:
 
   case 31:
 /* Line 1388 of yacc.c  */
-#line 306 "parse-gram.y"
+#line 306 "src/parse-gram.y"
     { yacc_flag = true; }
 /* Line 1388 of yacc.c  */
 #line 2106 "src/parse-gram.c"
@@ -2107,7 +2107,7 @@ yyreduce:
 
   case 35:
 /* Line 1388 of yacc.c  */
-#line 314 "parse-gram.y"
+#line 314 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
@@ -2117,7 +2117,7 @@ yyreduce:
 
   case 36:
 /* Line 1388 of yacc.c  */
-#line 318 "parse-gram.y"
+#line 318 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2130,7 +2130,7 @@ yyreduce:
 
   case 37:
 /* Line 1388 of yacc.c  */
-#line 325 "parse-gram.y"
+#line 325 "src/parse-gram.y"
     {
       symbol_list *list;
       for (list = (yyvsp[0].list); list; list = list->next)
@@ -2143,7 +2143,7 @@ yyreduce:
 
   case 38:
 /* Line 1388 of yacc.c  */
-#line 332 "parse-gram.y"
+#line 332 "src/parse-gram.y"
     {
       default_prec = true;
     }
@@ -2153,7 +2153,7 @@ yyreduce:
 
   case 39:
 /* Line 1388 of yacc.c  */
-#line 336 "parse-gram.y"
+#line 336 "src/parse-gram.y"
     {
       default_prec = false;
     }
@@ -2163,7 +2163,7 @@ yyreduce:
 
   case 40:
 /* Line 1388 of yacc.c  */
-#line 340 "parse-gram.y"
+#line 340 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2176,7 +2176,7 @@ yyreduce:
 
   case 41:
 /* Line 1388 of yacc.c  */
-#line 347 "parse-gram.y"
+#line 347 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
@@ -2187,7 +2187,7 @@ yyreduce:
 
   case 42:
 /* Line 1388 of yacc.c  */
-#line 361 "parse-gram.y"
+#line 361 "src/parse-gram.y"
     {}
 /* Line 1388 of yacc.c  */
 #line 2194 "src/parse-gram.c"
@@ -2195,7 +2195,7 @@ yyreduce:
 
   case 43:
 /* Line 1388 of yacc.c  */
-#line 362 "parse-gram.y"
+#line 362 "src/parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2202 "src/parse-gram.c"
@@ -2203,7 +2203,7 @@ yyreduce:
 
   case 44:
 /* Line 1388 of yacc.c  */
-#line 367 "parse-gram.y"
+#line 367 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
@@ -2215,7 +2215,7 @@ yyreduce:
 
   case 45:
 /* Line 1388 of yacc.c  */
-#line 378 "parse-gram.y"
+#line 378 "src/parse-gram.y"
     { current_class = nterm_sym; }
 /* Line 1388 of yacc.c  */
 #line 2222 "src/parse-gram.c"
@@ -2223,7 +2223,7 @@ yyreduce:
 
   case 46:
 /* Line 1388 of yacc.c  */
-#line 379 "parse-gram.y"
+#line 379 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2234,7 +2234,7 @@ yyreduce:
 
   case 47:
 /* Line 1388 of yacc.c  */
-#line 383 "parse-gram.y"
+#line 383 "src/parse-gram.y"
     { current_class = token_sym; }
 /* Line 1388 of yacc.c  */
 #line 2241 "src/parse-gram.c"
@@ -2242,7 +2242,7 @@ yyreduce:
 
   case 48:
 /* Line 1388 of yacc.c  */
-#line 384 "parse-gram.y"
+#line 384 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       current_type = NULL;
@@ -2253,7 +2253,7 @@ yyreduce:
 
   case 49:
 /* Line 1388 of yacc.c  */
-#line 389 "parse-gram.y"
+#line 389 "src/parse-gram.y"
     {
       symbol_list *list;
       tag_seen = true;
@@ -2267,7 +2267,7 @@ yyreduce:
 
   case 50:
 /* Line 1388 of yacc.c  */
-#line 400 "parse-gram.y"
+#line 400 "src/parse-gram.y"
     {
       symbol_list *list;
       ++current_prec;
@@ -2285,7 +2285,7 @@ yyreduce:
 
   case 51:
 /* Line 1388 of yacc.c  */
-#line 414 "parse-gram.y"
+#line 414 "src/parse-gram.y"
     { (yyval.assoc) = left_assoc; }
 /* Line 1388 of yacc.c  */
 #line 2292 "src/parse-gram.c"
@@ -2293,7 +2293,7 @@ yyreduce:
 
   case 52:
 /* Line 1388 of yacc.c  */
-#line 415 "parse-gram.y"
+#line 415 "src/parse-gram.y"
     { (yyval.assoc) = right_assoc; }
 /* Line 1388 of yacc.c  */
 #line 2300 "src/parse-gram.c"
@@ -2301,7 +2301,7 @@ yyreduce:
 
   case 53:
 /* Line 1388 of yacc.c  */
-#line 416 "parse-gram.y"
+#line 416 "src/parse-gram.y"
     { (yyval.assoc) = non_assoc; }
 /* Line 1388 of yacc.c  */
 #line 2308 "src/parse-gram.c"
@@ -2309,7 +2309,7 @@ yyreduce:
 
   case 54:
 /* Line 1388 of yacc.c  */
-#line 417 "parse-gram.y"
+#line 417 "src/parse-gram.y"
     { (yyval.assoc) = precedence_assoc; }
 /* Line 1388 of yacc.c  */
 #line 2316 "src/parse-gram.c"
@@ -2317,7 +2317,7 @@ yyreduce:
 
   case 55:
 /* Line 1388 of yacc.c  */
-#line 421 "parse-gram.y"
+#line 421 "src/parse-gram.y"
     { current_type = NULL; }
 /* Line 1388 of yacc.c  */
 #line 2324 "src/parse-gram.c"
@@ -2325,7 +2325,7 @@ yyreduce:
 
   case 56:
 /* Line 1388 of yacc.c  */
-#line 422 "parse-gram.y"
+#line 422 "src/parse-gram.y"
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
 /* Line 1388 of yacc.c  */
 #line 2332 "src/parse-gram.c"
@@ -2333,7 +2333,7 @@ yyreduce:
 
   case 57:
 /* Line 1388 of yacc.c  */
-#line 428 "parse-gram.y"
+#line 428 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2340 "src/parse-gram.c"
@@ -2341,7 +2341,7 @@ yyreduce:
 
   case 58:
 /* Line 1388 of yacc.c  */
-#line 430 "parse-gram.y"
+#line 430 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1388 of yacc.c  */
 #line 2348 "src/parse-gram.c"
@@ -2349,7 +2349,7 @@ yyreduce:
 
   case 59:
 /* Line 1388 of yacc.c  */
-#line 434 "parse-gram.y"
+#line 434 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[0].symbol); }
 /* Line 1388 of yacc.c  */
 #line 2356 "src/parse-gram.c"
@@ -2357,7 +2357,7 @@ yyreduce:
 
   case 60:
 /* Line 1388 of yacc.c  */
-#line 435 "parse-gram.y"
+#line 435 "src/parse-gram.y"
     { (yyval.symbol) = (yyvsp[-1].symbol); symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2364 "src/parse-gram.c"
@@ -2365,7 +2365,7 @@ yyreduce:
 
   case 61:
 /* Line 1388 of yacc.c  */
-#line 441 "parse-gram.y"
+#line 441 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2372 "src/parse-gram.c"
@@ -2373,7 +2373,7 @@ yyreduce:
 
   case 62:
 /* Line 1388 of yacc.c  */
-#line 443 "parse-gram.y"
+#line 443 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
 /* Line 1388 of yacc.c  */
 #line 2380 "src/parse-gram.c"
@@ -2381,7 +2381,7 @@ yyreduce:
 
   case 63:
 /* Line 1388 of yacc.c  */
-#line 447 "parse-gram.y"
+#line 447 "src/parse-gram.y"
     { (yyval.list) = (yyvsp[0].list); }
 /* Line 1388 of yacc.c  */
 #line 2388 "src/parse-gram.c"
@@ -2389,7 +2389,7 @@ yyreduce:
 
   case 64:
 /* Line 1388 of yacc.c  */
-#line 448 "parse-gram.y"
+#line 448 "src/parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[-1].list), (yyvsp[0].list)); }
 /* Line 1388 of yacc.c  */
 #line 2396 "src/parse-gram.c"
@@ -2397,7 +2397,7 @@ yyreduce:
 
   case 65:
 /* Line 1388 of yacc.c  */
-#line 452 "parse-gram.y"
+#line 452 "src/parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2404 "src/parse-gram.c"
@@ -2405,7 +2405,7 @@ yyreduce:
 
   case 66:
 /* Line 1388 of yacc.c  */
-#line 453 "parse-gram.y"
+#line 453 "src/parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2412 "src/parse-gram.c"
@@ -2413,7 +2413,7 @@ yyreduce:
 
   case 67:
 /* Line 1388 of yacc.c  */
-#line 454 "parse-gram.y"
+#line 454 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2420 "src/parse-gram.c"
@@ -2421,7 +2421,7 @@ yyreduce:
 
   case 68:
 /* Line 1388 of yacc.c  */
-#line 455 "parse-gram.y"
+#line 455 "src/parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2428 "src/parse-gram.c"
@@ -2429,7 +2429,7 @@ yyreduce:
 
   case 69:
 /* Line 1388 of yacc.c  */
-#line 461 "parse-gram.y"
+#line 461 "src/parse-gram.y"
     {
        current_type = (yyvsp[0].uniqstr);
        tag_seen = true;
@@ -2440,7 +2440,7 @@ yyreduce:
 
   case 70:
 /* Line 1388 of yacc.c  */
-#line 466 "parse-gram.y"
+#line 466 "src/parse-gram.y"
     {
        symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
        symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
@@ -2451,7 +2451,7 @@ yyreduce:
 
   case 71:
 /* Line 1388 of yacc.c  */
-#line 471 "parse-gram.y"
+#line 471 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -2463,7 +2463,7 @@ yyreduce:
 
   case 72:
 /* Line 1388 of yacc.c  */
-#line 477 "parse-gram.y"
+#line 477 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
@@ -2475,7 +2475,7 @@ yyreduce:
 
   case 73:
 /* Line 1388 of yacc.c  */
-#line 483 "parse-gram.y"
+#line 483 "src/parse-gram.y"
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
@@ -2488,7 +2488,7 @@ yyreduce:
 
   case 80:
 /* Line 1388 of yacc.c  */
-#line 513 "parse-gram.y"
+#line 513 "src/parse-gram.y"
     {
       yyerrok;
     }
@@ -2498,7 +2498,7 @@ yyreduce:
 
   case 81:
 /* Line 1388 of yacc.c  */
-#line 519 "parse-gram.y"
+#line 519 "src/parse-gram.y"
     { current_lhs = (yyvsp[-1].symbol); current_lhs_location = (yylsp[-1]);
     current_lhs_named_ref = (yyvsp[0].named_ref); }
 /* Line 1388 of yacc.c  */
@@ -2507,7 +2507,7 @@ yyreduce:
 
   case 83:
 /* Line 1388 of yacc.c  */
-#line 524 "parse-gram.y"
+#line 524 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2514 "src/parse-gram.c"
@@ -2515,7 +2515,7 @@ yyreduce:
 
   case 84:
 /* Line 1388 of yacc.c  */
-#line 525 "parse-gram.y"
+#line 525 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2522 "src/parse-gram.c"
@@ -2523,7 +2523,7 @@ yyreduce:
 
   case 86:
 /* Line 1388 of yacc.c  */
-#line 531 "parse-gram.y"
+#line 531 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs, current_lhs_location,
 				  current_lhs_named_ref); }
 /* Line 1388 of yacc.c  */
@@ -2532,7 +2532,7 @@ yyreduce:
 
   case 87:
 /* Line 1388 of yacc.c  */
-#line 534 "parse-gram.y"
+#line 534 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1388 of yacc.c  */
 #line 2539 "src/parse-gram.c"
@@ -2540,7 +2540,7 @@ yyreduce:
 
   case 88:
 /* Line 1388 of yacc.c  */
-#line 536 "parse-gram.y"
+#line 536 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
 /* Line 1388 of yacc.c  */
 #line 2547 "src/parse-gram.c"
@@ -2548,7 +2548,7 @@ yyreduce:
 
   case 89:
 /* Line 1388 of yacc.c  */
-#line 538 "parse-gram.y"
+#line 538 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2555 "src/parse-gram.c"
@@ -2556,7 +2556,7 @@ yyreduce:
 
   case 90:
 /* Line 1388 of yacc.c  */
-#line 540 "parse-gram.y"
+#line 540 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2563 "src/parse-gram.c"
@@ -2564,7 +2564,7 @@ yyreduce:
 
   case 91:
 /* Line 1388 of yacc.c  */
-#line 542 "parse-gram.y"
+#line 542 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2571 "src/parse-gram.c"
@@ -2572,7 +2572,7 @@ yyreduce:
 
   case 92:
 /* Line 1388 of yacc.c  */
-#line 546 "parse-gram.y"
+#line 546 "src/parse-gram.y"
     { (yyval.named_ref) = 0; }
 /* Line 1388 of yacc.c  */
 #line 2579 "src/parse-gram.c"
@@ -2580,7 +2580,7 @@ yyreduce:
 
   case 93:
 /* Line 1388 of yacc.c  */
-#line 548 "parse-gram.y"
+#line 548 "src/parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2587 "src/parse-gram.c"
@@ -2588,7 +2588,7 @@ yyreduce:
 
   case 95:
 /* Line 1388 of yacc.c  */
-#line 560 "parse-gram.y"
+#line 560 "src/parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
 /* Line 1388 of yacc.c  */
 #line 2595 "src/parse-gram.c"
@@ -2596,7 +2596,7 @@ yyreduce:
 
   case 96:
 /* Line 1388 of yacc.c  */
-#line 565 "parse-gram.y"
+#line 565 "src/parse-gram.y"
     { (yyval.chars) = ""; }
 /* Line 1388 of yacc.c  */
 #line 2603 "src/parse-gram.c"
@@ -2604,7 +2604,7 @@ yyreduce:
 
   case 97:
 /* Line 1388 of yacc.c  */
-#line 566 "parse-gram.y"
+#line 566 "src/parse-gram.y"
     { (yyval.chars) = (yyvsp[0].uniqstr); }
 /* Line 1388 of yacc.c  */
 #line 2611 "src/parse-gram.c"
@@ -2612,7 +2612,7 @@ yyreduce:
 
   case 99:
 /* Line 1388 of yacc.c  */
-#line 577 "parse-gram.y"
+#line 577 "src/parse-gram.y"
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\n';
@@ -2627,7 +2627,7 @@ yyreduce:
 
   case 100:
 /* Line 1388 of yacc.c  */
-#line 597 "parse-gram.y"
+#line 597 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2634 "src/parse-gram.c"
@@ -2635,7 +2635,7 @@ yyreduce:
 
   case 101:
 /* Line 1388 of yacc.c  */
-#line 599 "parse-gram.y"
+#line 599 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
@@ -2647,7 +2647,7 @@ yyreduce:
 
   case 102:
 /* Line 1388 of yacc.c  */
-#line 607 "parse-gram.y"
+#line 607 "src/parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
 /* Line 1388 of yacc.c  */
 #line 2654 "src/parse-gram.c"
@@ -2655,7 +2655,7 @@ yyreduce:
 
   case 105:
 /* Line 1388 of yacc.c  */
-#line 619 "parse-gram.y"
+#line 619 "src/parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
@@ -2666,7 +2666,7 @@ yyreduce:
 
   case 107:
 /* Line 1388 of yacc.c  */
-#line 628 "parse-gram.y"
+#line 628 "src/parse-gram.y"
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2898,7 +2898,7 @@ yyreturn:
 }
 
 /* Line 1607 of yacc.c  */
-#line 638 "parse-gram.y"
+#line 638 "src/parse-gram.y"
 
 
 
