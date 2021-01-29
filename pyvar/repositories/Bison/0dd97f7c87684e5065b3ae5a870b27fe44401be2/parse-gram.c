@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.3.2.93-9d04-dirty.  */
+/* A Bison parser, made by GNU Bison 3.3.2.122-5915.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.3.2.93-9d04-dirty"
+#define YYBISON_VERSION "3.3.2.122-5915"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -63,12 +63,10 @@
 #define YYPULL 1
 
 /* "%code top" blocks.  */
-#line 27 "src/parse-gram.y"
 
   /* On column 0 to please syntax-check.  */
 #include <config.h>
 
-#line 72 "src/parse-gram.c"
 /* Substitute the type names.  */
 #define YYSTYPE         GRAM_STYPE
 #define YYLTYPE         GRAM_LTYPE
@@ -105,7 +103,6 @@
 
 
 /* Unqualified %code blocks.  */
-#line 33 "src/parse-gram.y"
 
   #include "system.h"
   #include <errno.h>
@@ -188,7 +185,6 @@
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 250 "src/parse-gram.y"
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -199,7 +195,6 @@
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 203 "src/parse-gram.c"
 
 #ifdef short
 # undef short
@@ -882,103 +877,70 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 208 "src/parse-gram.y"
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).STRING)), yyo); }
-#line 888 "src/parse-gram.c"
         break;
 
     case 20: /* "%error-verbose"  */
-#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).PERCENT_ERROR_VERBOSE), yyo); }
-#line 894 "src/parse-gram.c"
         break;
 
     case 23: /* "%<flag>"  */
-#line 219 "src/parse-gram.y"
       { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
-#line 900 "src/parse-gram.c"
         break;
 
     case 24: /* "%file-prefix"  */
-#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).PERCENT_FILE_PREFIX), yyo); }
-#line 906 "src/parse-gram.c"
         break;
 
     case 28: /* "%name-prefix"  */
-#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).PERCENT_NAME_PREFIX), yyo); }
-#line 912 "src/parse-gram.c"
         break;
 
     case 38: /* "%yacc"  */
-#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).PERCENT_YACC), yyo); }
-#line 918 "src/parse-gram.c"
         break;
 
     case 39: /* "{...}"  */
-#line 209 "src/parse-gram.y"
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_CODE)); }
-#line 924 "src/parse-gram.c"
         break;
 
     case 40: /* "%?{...}"  */
-#line 209 "src/parse-gram.y"
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_PREDICATE)); }
-#line 930 "src/parse-gram.c"
         break;
 
     case 41: /* "[identifier]"  */
-#line 217 "src/parse-gram.y"
       { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
-#line 936 "src/parse-gram.c"
         break;
 
     case 42: /* "char"  */
-#line 205 "src/parse-gram.y"
       { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
-#line 942 "src/parse-gram.c"
         break;
 
     case 43: /* "epilogue"  */
-#line 209 "src/parse-gram.y"
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).EPILOGUE)); }
-#line 948 "src/parse-gram.c"
         break;
 
     case 45: /* "identifier"  */
-#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).ID), yyo); }
-#line 954 "src/parse-gram.c"
         break;
 
     case 46: /* "identifier:"  */
-#line 218 "src/parse-gram.y"
       { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
-#line 960 "src/parse-gram.c"
         break;
 
     case 49: /* "%{...%}"  */
-#line 209 "src/parse-gram.y"
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).PROLOGUE)); }
-#line 966 "src/parse-gram.c"
         break;
 
     case 51: /* "<tag>"  */
-#line 220 "src/parse-gram.y"
       { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
-#line 972 "src/parse-gram.c"
         break;
 
     case 54: /* "integer"  */
-#line 223 "src/parse-gram.y"
       { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
-#line 978 "src/parse-gram.c"
         break;
 
     case 55: /* "%param"  */
-#line 262 "src/parse-gram.y"
       {
   switch (((*yyvaluep).PERCENT_PARAM))
     {
@@ -991,107 +953,73 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 995 "src/parse-gram.c"
         break;
 
     case 65: /* code_props_type  */
-#line 398 "src/parse-gram.y"
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
-#line 1001 "src/parse-gram.c"
         break;
 
     case 71: /* tag.opt  */
-#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).yytype_71), yyo); }
-#line 1007 "src/parse-gram.c"
         break;
 
     case 72: /* generic_symlist  */
-#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).generic_symlist), yyo); }
-#line 1013 "src/parse-gram.c"
         break;
 
     case 73: /* generic_symlist_item  */
-#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).generic_symlist_item), yyo); }
-#line 1019 "src/parse-gram.c"
         break;
 
     case 74: /* tag  */
-#line 220 "src/parse-gram.y"
       { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
-#line 1025 "src/parse-gram.c"
         break;
 
     case 75: /* nterm_decls  */
-#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).nterm_decls), yyo); }
-#line 1031 "src/parse-gram.c"
         break;
 
     case 76: /* token_decls  */
-#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).token_decls), yyo); }
-#line 1037 "src/parse-gram.c"
         break;
 
     case 77: /* token_decl.1  */
-#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).yytype_77), yyo); }
-#line 1043 "src/parse-gram.c"
         break;
 
     case 78: /* token_decl  */
-#line 226 "src/parse-gram.y"
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl) ? ((*yyvaluep).token_decl)->tag : "<NULL>"); }
-#line 1049 "src/parse-gram.c"
         break;
 
     case 79: /* int.opt  */
-#line 223 "src/parse-gram.y"
       { fprintf (yyo, "%d", ((*yyvaluep).yytype_79)); }
-#line 1055 "src/parse-gram.c"
         break;
 
     case 80: /* token_decls_for_prec  */
-#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).token_decls_for_prec), yyo); }
-#line 1061 "src/parse-gram.c"
         break;
 
     case 81: /* token_decl_for_prec.1  */
-#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).yytype_81), yyo); }
-#line 1067 "src/parse-gram.c"
         break;
 
     case 82: /* token_decl_for_prec  */
-#line 226 "src/parse-gram.y"
       { fprintf (yyo, "%s", ((*yyvaluep).token_decl_for_prec) ? ((*yyvaluep).token_decl_for_prec)->tag : "<NULL>"); }
-#line 1073 "src/parse-gram.c"
         break;
 
     case 83: /* symbol_decls  */
-#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).symbol_decls), yyo); }
-#line 1079 "src/parse-gram.c"
         break;
 
     case 84: /* symbol_decl.1  */
-#line 232 "src/parse-gram.y"
       { symbol_list_syms_print (((*yyvaluep).yytype_84), yyo); }
-#line 1085 "src/parse-gram.c"
         break;
 
     case 92: /* variable  */
-#line 216 "src/parse-gram.y"
       { fputs (((*yyvaluep).variable), yyo); }
-#line 1091 "src/parse-gram.c"
         break;
 
     case 93: /* value  */
-#line 693 "src/parse-gram.y"
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1100,37 +1028,26 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1104 "src/parse-gram.c"
         break;
 
     case 94: /* id  */
-#line 226 "src/parse-gram.y"
       { fprintf (yyo, "%s", ((*yyvaluep).id) ? ((*yyvaluep).id)->tag : "<NULL>"); }
-#line 1110 "src/parse-gram.c"
         break;
 
     case 95: /* id_colon  */
-#line 227 "src/parse-gram.y"
       { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
-#line 1116 "src/parse-gram.c"
         break;
 
     case 96: /* symbol  */
-#line 226 "src/parse-gram.y"
       { fprintf (yyo, "%s", ((*yyvaluep).symbol) ? ((*yyvaluep).symbol)->tag : "<NULL>"); }
-#line 1122 "src/parse-gram.c"
         break;
 
     case 97: /* string_as_id  */
-#line 226 "src/parse-gram.y"
       { fprintf (yyo, "%s", ((*yyvaluep).string_as_id) ? ((*yyvaluep).string_as_id)->tag : "<NULL>"); }
-#line 1128 "src/parse-gram.c"
         break;
 
     case 98: /* string_as_id.opt  */
-#line 226 "src/parse-gram.y"
       { fprintf (yyo, "%s", ((*yyvaluep).yytype_98) ? ((*yyvaluep).yytype_98)->tag : "<NULL>"); }
-#line 1134 "src/parse-gram.c"
         break;
 
       default:
@@ -1718,57 +1635,39 @@ yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocatio
   switch (yytype)
     {
     case 72: /* generic_symlist  */
-#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).generic_symlist)); }
-#line 1724 "src/parse-gram.c"
         break;
 
     case 73: /* generic_symlist_item  */
-#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).generic_symlist_item)); }
-#line 1730 "src/parse-gram.c"
         break;
 
     case 75: /* nterm_decls  */
-#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).nterm_decls)); }
-#line 1736 "src/parse-gram.c"
         break;
 
     case 76: /* token_decls  */
-#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).token_decls)); }
-#line 1742 "src/parse-gram.c"
         break;
 
     case 77: /* token_decl.1  */
-#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).yytype_77)); }
-#line 1748 "src/parse-gram.c"
         break;
 
     case 80: /* token_decls_for_prec  */
-#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).token_decls_for_prec)); }
-#line 1754 "src/parse-gram.c"
         break;
 
     case 81: /* token_decl_for_prec.1  */
-#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).yytype_81)); }
-#line 1760 "src/parse-gram.c"
         break;
 
     case 83: /* symbol_decls  */
-#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).symbol_decls)); }
-#line 1766 "src/parse-gram.c"
         break;
 
     case 84: /* symbol_decl.1  */
-#line 231 "src/parse-gram.y"
       { symbol_list_free (((*yyvaluep).yytype_84)); }
-#line 1772 "src/parse-gram.c"
         break;
 
       default:
@@ -1885,7 +1784,6 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 130 "src/parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1893,7 +1791,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1897 "src/parse-gram.c"
+
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2092,189 +1990,134 @@ yyreduce:
     switch (yyn)
       {
   case 6:
-#line 298 "src/parse-gram.y"
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].PROLOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2102 "src/parse-gram.c"
     break;
 
   case 7:
-#line 304 "src/parse-gram.y"
     {
       muscle_percent_define_ensure ((yyvsp[0].PERCENT_FLAG), (yylsp[0]), true);
     }
-#line 2110 "src/parse-gram.c"
     break;
 
   case 8:
-#line 308 "src/parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[-1].variable), (yyloc), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2119 "src/parse-gram.c"
     break;
 
   case 9:
-#line 312 "src/parse-gram.y"
     { defines_flag = true; }
-#line 2125 "src/parse-gram.c"
     break;
 
   case 10:
-#line 314 "src/parse-gram.y"
     {
       defines_flag = true;
       spec_header_file = xstrdup ((yyvsp[0].STRING));
     }
-#line 2134 "src/parse-gram.c"
     break;
 
   case 11:
-#line 318 "src/parse-gram.y"
     { handle_error_verbose (&(yyloc), (yyvsp[0].PERCENT_ERROR_VERBOSE)); }
-#line 2140 "src/parse-gram.c"
     break;
 
   case 12:
-#line 319 "src/parse-gram.y"
     { expected_sr_conflicts = (yyvsp[0].INT); }
-#line 2146 "src/parse-gram.c"
     break;
 
   case 13:
-#line 320 "src/parse-gram.y"
     { expected_rr_conflicts = (yyvsp[0].INT); }
-#line 2152 "src/parse-gram.c"
     break;
 
   case 14:
-#line 321 "src/parse-gram.y"
     { handle_file_prefix (&(yyloc), &(yylsp[-1]), (yyvsp[-1].PERCENT_FILE_PREFIX), (yyvsp[0].STRING)); }
-#line 2158 "src/parse-gram.c"
     break;
 
   case 15:
-#line 323 "src/parse-gram.y"
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2167 "src/parse-gram.c"
     break;
 
   case 16:
-#line 328 "src/parse-gram.y"
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].BRACED_CODE), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2176 "src/parse-gram.c"
     break;
 
   case 17:
-#line 332 "src/parse-gram.y"
     { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
-#line 2182 "src/parse-gram.c"
     break;
 
   case 18:
-#line 333 "src/parse-gram.y"
     { handle_name_prefix (&(yyloc), (yyvsp[-1].PERCENT_NAME_PREFIX), (yyvsp[0].STRING)); }
-#line 2188 "src/parse-gram.c"
     break;
 
   case 19:
-#line 334 "src/parse-gram.y"
     { no_lines_flag = true; }
-#line 2194 "src/parse-gram.c"
     break;
 
   case 20:
-#line 335 "src/parse-gram.y"
     { nondeterministic_parser = true; }
-#line 2200 "src/parse-gram.c"
     break;
 
   case 21:
-#line 336 "src/parse-gram.y"
     { spec_outfile = (yyvsp[0].STRING); }
-#line 2206 "src/parse-gram.c"
     break;
 
   case 22:
-#line 337 "src/parse-gram.y"
     { current_param = (yyvsp[0].PERCENT_PARAM); }
-#line 2212 "src/parse-gram.c"
     break;
 
   case 23:
-#line 337 "src/parse-gram.y"
     { current_param = param_none; }
-#line 2218 "src/parse-gram.c"
     break;
 
   case 24:
-#line 338 "src/parse-gram.y"
     { handle_require (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2224 "src/parse-gram.c"
     break;
 
   case 25:
-#line 339 "src/parse-gram.y"
     { handle_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2230 "src/parse-gram.c"
     break;
 
   case 26:
-#line 340 "src/parse-gram.y"
     { token_table_flag = true; }
-#line 2236 "src/parse-gram.c"
     break;
 
   case 27:
-#line 341 "src/parse-gram.y"
     { report_flag |= report_states; }
-#line 2242 "src/parse-gram.c"
     break;
 
   case 28:
-#line 342 "src/parse-gram.y"
     { handle_yacc (&(yyloc), (yyvsp[0].PERCENT_YACC)); }
-#line 2248 "src/parse-gram.c"
     break;
 
   case 29:
-#line 343 "src/parse-gram.y"
     { current_class = unknown_sym; yyerrok; }
-#line 2254 "src/parse-gram.c"
     break;
 
   case 31:
-#line 348 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2260 "src/parse-gram.c"
     break;
 
   case 32:
-#line 349 "src/parse-gram.y"
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2266 "src/parse-gram.c"
     break;
 
   case 34:
-#line 360 "src/parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2274 "src/parse-gram.c"
     break;
 
   case 35:
-#line 364 "src/parse-gram.y"
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].BRACED_CODE), (yylsp[-1]));
@@ -2285,27 +2128,21 @@ yyreduce:
         symbol_list_free ((yyvsp[0].generic_symlist));
       }
     }
-#line 2289 "src/parse-gram.c"
     break;
 
   case 36:
-#line 375 "src/parse-gram.y"
     {
       default_prec = true;
     }
-#line 2297 "src/parse-gram.c"
     break;
 
   case 37:
-#line 379 "src/parse-gram.y"
     {
       default_prec = false;
     }
-#line 2305 "src/parse-gram.c"
     break;
 
   case 38:
-#line 383 "src/parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2313,207 +2150,149 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2317 "src/parse-gram.c"
     break;
 
   case 39:
-#line 391 "src/parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[-1].ID), (yylsp[-1]), translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2326 "src/parse-gram.c"
     break;
 
   case 40:
-#line 400 "src/parse-gram.y"
     { (yyval.code_props_type) = destructor; }
-#line 2332 "src/parse-gram.c"
     break;
 
   case 41:
-#line 401 "src/parse-gram.y"
     { (yyval.code_props_type) = printer; }
-#line 2338 "src/parse-gram.c"
     break;
 
   case 42:
-#line 411 "src/parse-gram.y"
     {}
-#line 2344 "src/parse-gram.c"
     break;
 
   case 43:
-#line 412 "src/parse-gram.y"
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2352 "src/parse-gram.c"
     break;
 
   case 44:
-#line 419 "src/parse-gram.y"
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2362 "src/parse-gram.c"
     break;
 
   case 45:
-#line 431 "src/parse-gram.y"
     { current_class = nterm_sym; }
-#line 2368 "src/parse-gram.c"
     break;
 
   case 46:
-#line 432 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].nterm_decls));
     }
-#line 2377 "src/parse-gram.c"
     break;
 
   case 47:
-#line 436 "src/parse-gram.y"
     { current_class = token_sym; }
-#line 2383 "src/parse-gram.c"
     break;
 
   case 48:
-#line 437 "src/parse-gram.y"
     {
       current_class = unknown_sym;
       symbol_list_free ((yyvsp[0].token_decls));
     }
-#line 2392 "src/parse-gram.c"
     break;
 
   case 49:
-#line 442 "src/parse-gram.y"
     {
       symbol_list_free ((yyvsp[0].symbol_decls));
     }
-#line 2400 "src/parse-gram.c"
     break;
 
   case 50:
-#line 446 "src/parse-gram.y"
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].token_decls_for_prec); list; list = list->next)
         symbol_precedence_set (list->content.sym, current_prec, (yyvsp[-1].precedence_declarator), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].token_decls_for_prec));
     }
-#line 2411 "src/parse-gram.c"
     break;
 
   case 51:
-#line 455 "src/parse-gram.y"
     { (yyval.precedence_declarator) = left_assoc; }
-#line 2417 "src/parse-gram.c"
     break;
 
   case 52:
-#line 456 "src/parse-gram.y"
     { (yyval.precedence_declarator) = right_assoc; }
-#line 2423 "src/parse-gram.c"
     break;
 
   case 53:
-#line 457 "src/parse-gram.y"
     { (yyval.precedence_declarator) = non_assoc; }
-#line 2429 "src/parse-gram.c"
     break;
 
   case 54:
-#line 458 "src/parse-gram.y"
     { (yyval.precedence_declarator) = precedence_assoc; }
-#line 2435 "src/parse-gram.c"
     break;
 
   case 55:
-#line 462 "src/parse-gram.y"
     { (yyval.yytype_71) = NULL; }
-#line 2441 "src/parse-gram.c"
     break;
 
   case 56:
-#line 463 "src/parse-gram.y"
     { (yyval.yytype_71) = (yyvsp[0].TAG); }
-#line 2447 "src/parse-gram.c"
     break;
 
   case 58:
-#line 469 "src/parse-gram.y"
     { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
-#line 2453 "src/parse-gram.c"
     break;
 
   case 59:
-#line 473 "src/parse-gram.y"
     { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2459 "src/parse-gram.c"
     break;
 
   case 60:
-#line 474 "src/parse-gram.y"
     { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
-#line 2465 "src/parse-gram.c"
     break;
 
   case 62:
-#line 479 "src/parse-gram.y"
     { (yyval.tag) = uniqstr_new ("*"); }
-#line 2471 "src/parse-gram.c"
     break;
 
   case 63:
-#line 480 "src/parse-gram.y"
     { (yyval.tag) = uniqstr_new (""); }
-#line 2477 "src/parse-gram.c"
     break;
 
   case 65:
-#line 503 "src/parse-gram.y"
     {
       (yyval.token_decls) = (yyvsp[0].yytype_77);
     }
-#line 2485 "src/parse-gram.c"
     break;
 
   case 66:
-#line 507 "src/parse-gram.y"
     {
       (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yytype_77), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2493 "src/parse-gram.c"
     break;
 
   case 67:
-#line 511 "src/parse-gram.y"
     {
       (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yytype_77), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2501 "src/parse-gram.c"
     break;
 
   case 68:
-#line 518 "src/parse-gram.y"
     { (yyval.yytype_77) = symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0])); }
-#line 2507 "src/parse-gram.c"
     break;
 
   case 69:
-#line 519 "src/parse-gram.y"
     { (yyval.yytype_77) = symbol_list_append ((yyvsp[-1].yytype_77), symbol_list_sym_new ((yyvsp[0].token_decl), (yylsp[0]))); }
-#line 2513 "src/parse-gram.c"
     break;
 
   case 70:
-#line 524 "src/parse-gram.y"
     {
       (yyval.token_decl) = (yyvsp[-2].id);
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
@@ -2522,238 +2301,168 @@ yyreduce:
       if ((yyvsp[0].yytype_98))
         symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_98), (yylsp[0]));
     }
-#line 2526 "src/parse-gram.c"
     break;
 
   case 71:
-#line 536 "src/parse-gram.y"
     { (yyval.yytype_79) = -1; }
-#line 2532 "src/parse-gram.c"
     break;
 
   case 73:
-#line 550 "src/parse-gram.y"
     {
       (yyval.token_decls_for_prec) = (yyvsp[0].yytype_81);
     }
-#line 2540 "src/parse-gram.c"
     break;
 
   case 74:
-#line 554 "src/parse-gram.y"
     {
       (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yytype_81), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2548 "src/parse-gram.c"
     break;
 
   case 75:
-#line 558 "src/parse-gram.y"
     {
       (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yytype_81), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2556 "src/parse-gram.c"
     break;
 
   case 76:
-#line 566 "src/parse-gram.y"
     { (yyval.yytype_81) = symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0])); }
-#line 2562 "src/parse-gram.c"
     break;
 
   case 77:
-#line 568 "src/parse-gram.y"
     { (yyval.yytype_81) = symbol_list_append ((yyvsp[-1].yytype_81), symbol_list_sym_new ((yyvsp[0].token_decl_for_prec), (yylsp[0]))); }
-#line 2568 "src/parse-gram.c"
     break;
 
   case 78:
-#line 573 "src/parse-gram.y"
     {
       (yyval.token_decl_for_prec) = (yyvsp[-1].id);
       symbol_class_set ((yyvsp[-1].id), token_sym, (yylsp[-1]), false);
       if (0 <= (yyvsp[0].yytype_79))
         symbol_user_token_number_set ((yyvsp[-1].id), (yyvsp[0].yytype_79), (yylsp[0]));
     }
-#line 2579 "src/parse-gram.c"
     break;
 
   case 80:
-#line 590 "src/parse-gram.y"
     {
       (yyval.symbol_decls) = (yyvsp[0].yytype_84);
     }
-#line 2587 "src/parse-gram.c"
     break;
 
   case 81:
-#line 594 "src/parse-gram.y"
     {
       (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yytype_84), (yyvsp[-1].TAG), (yylsp[-1]));
     }
-#line 2595 "src/parse-gram.c"
     break;
 
   case 82:
-#line 598 "src/parse-gram.y"
     {
       (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yytype_84), (yyvsp[-1].TAG), (yylsp[-1])));
     }
-#line 2603 "src/parse-gram.c"
     break;
 
   case 83:
-#line 605 "src/parse-gram.y"
     { (yyval.yytype_84) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2609 "src/parse-gram.c"
     break;
 
   case 84:
-#line 606 "src/parse-gram.y"
     { (yyval.yytype_84) = symbol_list_append ((yyvsp[-1].yytype_84), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2615 "src/parse-gram.c"
     break;
 
   case 89:
-#line 624 "src/parse-gram.y"
     {
       yyerrok;
     }
-#line 2623 "src/parse-gram.c"
     break;
 
   case 90:
-#line 630 "src/parse-gram.y"
     { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_91)); }
-#line 2629 "src/parse-gram.c"
     break;
 
   case 91:
-#line 631 "src/parse-gram.y"
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2638 "src/parse-gram.c"
     break;
 
   case 92:
-#line 638 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2644 "src/parse-gram.c"
     break;
 
   case 93:
-#line 639 "src/parse-gram.y"
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2650 "src/parse-gram.c"
     break;
 
   case 95:
-#line 646 "src/parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2657 "src/parse-gram.c"
     break;
 
   case 96:
-#line 649 "src/parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_91)); }
-#line 2663 "src/parse-gram.c"
     break;
 
   case 97:
-#line 651 "src/parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_91), (yyvsp[-2].yytype_71)); }
-#line 2669 "src/parse-gram.c"
     break;
 
   case 98:
-#line 653 "src/parse-gram.y"
     { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
-#line 2675 "src/parse-gram.c"
     break;
 
   case 99:
-#line 655 "src/parse-gram.y"
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2681 "src/parse-gram.c"
     break;
 
   case 100:
-#line 657 "src/parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2687 "src/parse-gram.c"
     break;
 
   case 101:
-#line 659 "src/parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
-#line 2693 "src/parse-gram.c"
     break;
 
   case 102:
-#line 661 "src/parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
-#line 2699 "src/parse-gram.c"
     break;
 
   case 103:
-#line 663 "src/parse-gram.y"
     { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2705 "src/parse-gram.c"
     break;
 
   case 104:
-#line 665 "src/parse-gram.y"
     { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2711 "src/parse-gram.c"
     break;
 
   case 105:
-#line 669 "src/parse-gram.y"
-    { (yyval.yytype_91) = 0; }
-#line 2717 "src/parse-gram.c"
+    { (yyval.yytype_91) = NULL; }
     break;
 
   case 106:
-#line 670 "src/parse-gram.y"
     { (yyval.yytype_91) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
-#line 2723 "src/parse-gram.c"
     break;
 
   case 108:
-#line 703 "src/parse-gram.y"
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2729 "src/parse-gram.c"
     break;
 
   case 109:
-#line 704 "src/parse-gram.y"
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
-#line 2735 "src/parse-gram.c"
     break;
 
   case 110:
-#line 705 "src/parse-gram.y"
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
-#line 2741 "src/parse-gram.c"
     break;
 
   case 111:
-#line 706 "src/parse-gram.y"
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
-#line 2747 "src/parse-gram.c"
     break;
 
   case 112:
-#line 719 "src/parse-gram.y"
     { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
-#line 2753 "src/parse-gram.c"
     break;
 
   case 113:
-#line 721 "src/parse-gram.y"
     {
       if (current_class == nterm_sym)
         {
@@ -2765,41 +2474,32 @@ yyreduce:
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
     }
-#line 2769 "src/parse-gram.c"
     break;
 
   case 114:
-#line 735 "src/parse-gram.y"
     { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
-#line 2775 "src/parse-gram.c"
     break;
 
   case 117:
-#line 747 "src/parse-gram.y"
     {
       (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
-#line 2784 "src/parse-gram.c"
     break;
 
   case 118:
-#line 755 "src/parse-gram.y"
     { (yyval.yytype_98) = NULL; }
-#line 2790 "src/parse-gram.c"
     break;
 
   case 121:
-#line 762 "src/parse-gram.y"
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2799 "src/parse-gram.c"
     break;
 
 
-#line 2803 "src/parse-gram.c"
+
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3048,7 +2748,6 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 768 "src/parse-gram.y"
 
 
 /* Return the location of the left-hand side of a rule whose
