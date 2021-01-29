@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.2.1.100-30b99-dirty.  */
+/* A Bison parser, made by GNU Bison 3.2.1.94-fe97.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -47,7 +47,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.2.1.100-30b99-dirty"
+#define YYBISON_VERSION "3.2.1.94-fe97"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -62,12 +62,12 @@
 #define YYPULL 1
 
 /* "%code top" blocks.  */
-#line 27 "src/parse-gram.y" /* yacc.c:316  */
+#line 27 "src/parse-gram.y" /* yacc.c:315  */
 
   /* On column 0 to please syntax-check.  */
 #include <config.h>
 
-#line 71 "src/parse-gram.c" /* yacc.c:316  */
+#line 71 "src/parse-gram.c" /* yacc.c:315  */
 /* Substitute the type names.  */
 #define YYSTYPE         GRAM_STYPE
 #define YYLTYPE         GRAM_LTYPE
@@ -120,11 +120,11 @@
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-#line 21 "src/parse-gram.y" /* yacc.c:353  */
+#line 21 "src/parse-gram.y" /* yacc.c:352  */
 
   #include "symlist.h"
   #include "symtab.h"
-#line 218 "src/parse-gram.y" /* yacc.c:353  */
+#line 218 "src/parse-gram.y" /* yacc.c:352  */
 
   typedef enum
   {
@@ -133,7 +133,7 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 620 "src/parse-gram.y" /* yacc.c:353  */
+#line 606 "src/parse-gram.y" /* yacc.c:352  */
 
   #include "muscle-tab.h"
   typedef struct
@@ -142,7 +142,7 @@ extern int gram_debug;
     muscle_kind kind;
   } value_type;
 
-#line 146 "src/parse-gram.c" /* yacc.c:353  */
+#line 146 "src/parse-gram.c" /* yacc.c:352  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -275,7 +275,7 @@ union GRAM_STYPE
   unsigned char CHAR;
   /* value  */
   value_type value;
-#line 279 "src/parse-gram.c" /* yacc.c:353  */
+#line 279 "src/parse-gram.c" /* yacc.c:352  */
 };
 
 typedef union GRAM_STYPE GRAM_STYPE;
@@ -305,7 +305,7 @@ int gram_parse (void);
 
 
 /* Unqualified %code blocks.  */
-#line 33 "src/parse-gram.y" /* yacc.c:356  */
+#line 33 "src/parse-gram.y" /* yacc.c:355  */
 
   #include "system.h"
   #include <errno.h>
@@ -373,7 +373,7 @@ int gram_parse (void);
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 228 "src/parse-gram.y" /* yacc.c:356  */
+#line 228 "src/parse-gram.y" /* yacc.c:355  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -384,7 +384,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 388 "src/parse-gram.c" /* yacc.c:356  */
+#line 388 "src/parse-gram.c" /* yacc.c:355  */
 
 #ifdef short
 # undef short
@@ -664,11 +664,11 @@ static const yytype_uint16 yyrline[] =
      378,   379,   389,   390,   396,   408,   408,   413,   413,   418,
      428,   441,   442,   443,   444,   448,   449,   454,   456,   461,
      466,   476,   478,   483,   484,   488,   489,   493,   494,   495,
-     500,   505,   532,   533,   538,   539,   551,   552,   558,   559,
-     560,   567,   567,   575,   576,   577,   582,   585,   587,   589,
-     591,   593,   595,   597,   599,   601,   606,   607,   616,   640,
-     641,   642,   643,   655,   657,   672,   677,   678,   683,   692,
-     693,   697,   698
+     500,   505,   518,   519,   524,   525,   537,   538,   544,   545,
+     546,   553,   553,   561,   562,   563,   568,   571,   573,   575,
+     577,   579,   581,   583,   585,   587,   592,   593,   602,   626,
+     627,   628,   629,   641,   643,   658,   663,   664,   669,   678,
+     679,   683,   684
 };
 #endif
 
@@ -1050,79 +1050,79 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
   switch (yytype)
     {
     case 3: /* "string"  */
-#line 191 "src/parse-gram.y" /* yacc.c:681  */
+#line 191 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).STRING)), yyo); }
-#line 1056 "src/parse-gram.c" /* yacc.c:681  */
+#line 1056 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 22: /* "%<flag>"  */
-#line 198 "src/parse-gram.y" /* yacc.c:681  */
+#line 198 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).PERCENT_FLAG)); }
-#line 1062 "src/parse-gram.c" /* yacc.c:681  */
+#line 1062 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 38: /* "{...}"  */
-#line 192 "src/parse-gram.y" /* yacc.c:681  */
+#line 192 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_CODE)); }
-#line 1068 "src/parse-gram.c" /* yacc.c:681  */
+#line 1068 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 39: /* "%?{...}"  */
-#line 192 "src/parse-gram.y" /* yacc.c:681  */
+#line 192 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_PREDICATE)); }
-#line 1074 "src/parse-gram.c" /* yacc.c:681  */
+#line 1074 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 40: /* "[identifier]"  */
-#line 196 "src/parse-gram.y" /* yacc.c:681  */
+#line 196 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
-#line 1080 "src/parse-gram.c" /* yacc.c:681  */
+#line 1080 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 41: /* "char"  */
-#line 188 "src/parse-gram.y" /* yacc.c:681  */
+#line 188 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
-#line 1086 "src/parse-gram.c" /* yacc.c:681  */
+#line 1086 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 42: /* "epilogue"  */
-#line 192 "src/parse-gram.y" /* yacc.c:681  */
+#line 192 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).EPILOGUE)); }
-#line 1092 "src/parse-gram.c" /* yacc.c:681  */
+#line 1092 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 44: /* "identifier"  */
-#line 195 "src/parse-gram.y" /* yacc.c:681  */
+#line 195 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).ID), yyo); }
-#line 1098 "src/parse-gram.c" /* yacc.c:681  */
+#line 1098 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 45: /* "identifier:"  */
-#line 197 "src/parse-gram.y" /* yacc.c:681  */
+#line 197 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s:", ((*yyvaluep).ID_COLON)); }
-#line 1104 "src/parse-gram.c" /* yacc.c:681  */
+#line 1104 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 48: /* "%{...%}"  */
-#line 192 "src/parse-gram.y" /* yacc.c:681  */
+#line 192 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).PROLOGUE)); }
-#line 1110 "src/parse-gram.c" /* yacc.c:681  */
+#line 1110 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 50: /* "<tag>"  */
-#line 199 "src/parse-gram.y" /* yacc.c:681  */
+#line 199 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
-#line 1116 "src/parse-gram.c" /* yacc.c:681  */
+#line 1116 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 53: /* "integer"  */
-#line 202 "src/parse-gram.y" /* yacc.c:681  */
+#line 202 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
-#line 1122 "src/parse-gram.c" /* yacc.c:681  */
+#line 1122 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 54: /* "%param"  */
-#line 240 "src/parse-gram.y" /* yacc.c:681  */
+#line 240 "src/parse-gram.y" /* yacc.c:680  */
       {
   switch (((*yyvaluep).PERCENT_PARAM))
     {
@@ -1135,47 +1135,47 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       case param_none: aver (false); break;
     }
 }
-#line 1139 "src/parse-gram.c" /* yacc.c:681  */
+#line 1139 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 64: /* code_props_type  */
-#line 376 "src/parse-gram.y" /* yacc.c:681  */
+#line 376 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_props_type))); }
-#line 1145 "src/parse-gram.c" /* yacc.c:681  */
+#line 1145 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 71: /* tag.opt  */
-#line 195 "src/parse-gram.y" /* yacc.c:681  */
+#line 195 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).yytype_71), yyo); }
-#line 1151 "src/parse-gram.c" /* yacc.c:681  */
+#line 1151 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 73: /* symbol.prec  */
-#line 205 "src/parse-gram.y" /* yacc.c:681  */
+#line 205 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).yytype_73)->tag); }
-#line 1157 "src/parse-gram.c" /* yacc.c:681  */
+#line 1157 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 77: /* tag  */
-#line 199 "src/parse-gram.y" /* yacc.c:681  */
+#line 199 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).tag)); }
-#line 1163 "src/parse-gram.c" /* yacc.c:681  */
+#line 1163 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 79: /* int.opt  */
-#line 202 "src/parse-gram.y" /* yacc.c:681  */
+#line 202 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%d", ((*yyvaluep).yytype_79)); }
-#line 1169 "src/parse-gram.c" /* yacc.c:681  */
+#line 1169 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 88: /* variable  */
-#line 195 "src/parse-gram.y" /* yacc.c:681  */
+#line 195 "src/parse-gram.y" /* yacc.c:680  */
       { fputs (((*yyvaluep).variable), yyo); }
-#line 1175 "src/parse-gram.c" /* yacc.c:681  */
+#line 1175 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 89: /* value  */
-#line 630 "src/parse-gram.y" /* yacc.c:681  */
+#line 616 "src/parse-gram.y" /* yacc.c:680  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1184,37 +1184,37 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1188 "src/parse-gram.c" /* yacc.c:681  */
+#line 1188 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 90: /* id  */
-#line 205 "src/parse-gram.y" /* yacc.c:681  */
+#line 205 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).id)->tag); }
-#line 1194 "src/parse-gram.c" /* yacc.c:681  */
+#line 1194 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 91: /* id_colon  */
-#line 206 "src/parse-gram.y" /* yacc.c:681  */
+#line 206 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s:", ((*yyvaluep).id_colon)->tag); }
-#line 1200 "src/parse-gram.c" /* yacc.c:681  */
+#line 1200 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 92: /* symbol  */
-#line 205 "src/parse-gram.y" /* yacc.c:681  */
+#line 205 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1206 "src/parse-gram.c" /* yacc.c:681  */
+#line 1206 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 93: /* string_as_id  */
-#line 205 "src/parse-gram.y" /* yacc.c:681  */
+#line 205 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).string_as_id)->tag); }
-#line 1212 "src/parse-gram.c" /* yacc.c:681  */
+#line 1212 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
     case 94: /* string_as_id.opt  */
-#line 205 "src/parse-gram.y" /* yacc.c:681  */
+#line 205 "src/parse-gram.y" /* yacc.c:680  */
       { fprintf (yyo, "%s", ((*yyvaluep).yytype_94)->tag); }
-#line 1218 "src/parse-gram.c" /* yacc.c:681  */
+#line 1218 "src/parse-gram.c" /* yacc.c:680  */
         break;
 
       default:
@@ -1907,7 +1907,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 114 "src/parse-gram.y" /* yacc.c:1428  */
+#line 114 "src/parse-gram.y" /* yacc.c:1427  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1915,7 +1915,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1919 "src/parse-gram.c" /* yacc.c:1428  */
+#line 1919 "src/parse-gram.c" /* yacc.c:1427  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2114,183 +2114,183 @@ yyreduce:
     switch (yyn)
       {
   case 6:
-#line 276 "src/parse-gram.y" /* yacc.c:1649  */
+#line 276 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_code_grow (union_seen ? "post_prologue" : "pre_prologue",
                         translate_code ((yyvsp[0].PROLOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2124 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2124 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 7:
-#line 282 "src/parse-gram.y" /* yacc.c:1649  */
+#line 282 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_percent_define_ensure ((yyvsp[0].PERCENT_FLAG), (yylsp[0]), true);
     }
-#line 2132 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2132 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 8:
-#line 286 "src/parse-gram.y" /* yacc.c:1649  */
+#line 286 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_percent_define_insert ((yyvsp[-1].variable), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2141 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2141 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 9:
-#line 290 "src/parse-gram.y" /* yacc.c:1649  */
+#line 290 "src/parse-gram.y" /* yacc.c:1648  */
     { defines_flag = true; }
-#line 2147 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2147 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 10:
-#line 292 "src/parse-gram.y" /* yacc.c:1649  */
+#line 292 "src/parse-gram.y" /* yacc.c:1648  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].STRING));
     }
-#line 2156 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2156 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 11:
-#line 296 "src/parse-gram.y" /* yacc.c:1649  */
+#line 296 "src/parse-gram.y" /* yacc.c:1648  */
     { expected_sr_conflicts = (yyvsp[0].INT); }
-#line 2162 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2162 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 12:
-#line 297 "src/parse-gram.y" /* yacc.c:1649  */
+#line 297 "src/parse-gram.y" /* yacc.c:1648  */
     { expected_rr_conflicts = (yyvsp[0].INT); }
-#line 2168 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2168 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 13:
-#line 298 "src/parse-gram.y" /* yacc.c:1649  */
+#line 298 "src/parse-gram.y" /* yacc.c:1648  */
     { spec_file_prefix = (yyvsp[0].STRING); }
-#line 2174 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2174 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 14:
-#line 300 "src/parse-gram.y" /* yacc.c:1649  */
+#line 300 "src/parse-gram.y" /* yacc.c:1648  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2183 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2183 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 15:
-#line 305 "src/parse-gram.y" /* yacc.c:1649  */
+#line 305 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_code_grow ("initial_action", translate_code ((yyvsp[0].BRACED_CODE), (yylsp[0]), false), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2192 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2192 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 16:
-#line 309 "src/parse-gram.y" /* yacc.c:1649  */
+#line 309 "src/parse-gram.y" /* yacc.c:1648  */
     { language_argmatch ((yyvsp[0].STRING), grammar_prio, (yylsp[-1])); }
-#line 2198 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2198 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 17:
-#line 310 "src/parse-gram.y" /* yacc.c:1649  */
+#line 310 "src/parse-gram.y" /* yacc.c:1648  */
     { spec_name_prefix = (yyvsp[0].STRING); }
-#line 2204 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2204 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 18:
-#line 311 "src/parse-gram.y" /* yacc.c:1649  */
+#line 311 "src/parse-gram.y" /* yacc.c:1648  */
     { no_lines_flag = true; }
-#line 2210 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2210 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 19:
-#line 312 "src/parse-gram.y" /* yacc.c:1649  */
+#line 312 "src/parse-gram.y" /* yacc.c:1648  */
     { nondeterministic_parser = true; }
-#line 2216 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2216 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 20:
-#line 313 "src/parse-gram.y" /* yacc.c:1649  */
+#line 313 "src/parse-gram.y" /* yacc.c:1648  */
     { spec_outfile = (yyvsp[0].STRING); }
-#line 2222 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2222 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 21:
-#line 314 "src/parse-gram.y" /* yacc.c:1649  */
+#line 314 "src/parse-gram.y" /* yacc.c:1648  */
     { current_param = (yyvsp[0].PERCENT_PARAM); }
-#line 2228 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2228 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 22:
-#line 314 "src/parse-gram.y" /* yacc.c:1649  */
+#line 314 "src/parse-gram.y" /* yacc.c:1648  */
     { current_param = param_none; }
-#line 2234 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2234 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 23:
-#line 315 "src/parse-gram.y" /* yacc.c:1649  */
+#line 315 "src/parse-gram.y" /* yacc.c:1648  */
     { do_require (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2240 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2240 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 24:
-#line 316 "src/parse-gram.y" /* yacc.c:1649  */
+#line 316 "src/parse-gram.y" /* yacc.c:1648  */
     { do_skeleton (&(yylsp[0]), (yyvsp[0].STRING)); }
-#line 2246 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2246 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 25:
-#line 317 "src/parse-gram.y" /* yacc.c:1649  */
+#line 317 "src/parse-gram.y" /* yacc.c:1648  */
     { token_table_flag = true; }
-#line 2252 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2252 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 26:
-#line 318 "src/parse-gram.y" /* yacc.c:1649  */
+#line 318 "src/parse-gram.y" /* yacc.c:1648  */
     { report_flag |= report_states; }
-#line 2258 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2258 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 27:
-#line 319 "src/parse-gram.y" /* yacc.c:1649  */
+#line 319 "src/parse-gram.y" /* yacc.c:1648  */
     { yacc_flag = true; }
-#line 2264 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2264 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 28:
-#line 320 "src/parse-gram.y" /* yacc.c:1649  */
+#line 320 "src/parse-gram.y" /* yacc.c:1648  */
     { current_class = unknown_sym; yyerrok; }
-#line 2270 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2270 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 30:
-#line 325 "src/parse-gram.y" /* yacc.c:1649  */
+#line 325 "src/parse-gram.y" /* yacc.c:1648  */
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2276 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2276 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 31:
-#line 326 "src/parse-gram.y" /* yacc.c:1649  */
+#line 326 "src/parse-gram.y" /* yacc.c:1648  */
     { add_param (current_param, (yyvsp[0].BRACED_CODE), (yylsp[0])); }
-#line 2282 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2282 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 34:
-#line 338 "src/parse-gram.y" /* yacc.c:1649  */
+#line 338 "src/parse-gram.y" /* yacc.c:1648  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2290 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2290 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 35:
-#line 342 "src/parse-gram.y" /* yacc.c:1649  */
+#line 342 "src/parse-gram.y" /* yacc.c:1648  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].BRACED_CODE), (yylsp[-1]));
@@ -2301,27 +2301,27 @@ yyreduce:
         symbol_list_free ((yyvsp[0].generic_symlist));
       }
     }
-#line 2305 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2305 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 36:
-#line 353 "src/parse-gram.y" /* yacc.c:1649  */
+#line 353 "src/parse-gram.y" /* yacc.c:1648  */
     {
       default_prec = true;
     }
-#line 2313 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2313 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 37:
-#line 357 "src/parse-gram.y" /* yacc.c:1649  */
+#line 357 "src/parse-gram.y" /* yacc.c:1648  */
     {
       default_prec = false;
     }
-#line 2321 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2321 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 38:
-#line 361 "src/parse-gram.y" /* yacc.c:1649  */
+#line 361 "src/parse-gram.y" /* yacc.c:1648  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
@@ -2329,97 +2329,97 @@ yyreduce:
                         translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2333 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2333 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 39:
-#line 369 "src/parse-gram.y" /* yacc.c:1649  */
+#line 369 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_percent_code_grow ((yyvsp[-1].ID), (yylsp[-1]), translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2342 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2342 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 40:
-#line 378 "src/parse-gram.y" /* yacc.c:1649  */
+#line 378 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.code_props_type) = destructor; }
-#line 2348 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2348 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 41:
-#line 379 "src/parse-gram.y" /* yacc.c:1649  */
+#line 379 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.code_props_type) = printer; }
-#line 2354 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2354 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 42:
-#line 389 "src/parse-gram.y" /* yacc.c:1649  */
+#line 389 "src/parse-gram.y" /* yacc.c:1648  */
     {}
-#line 2360 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2360 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 43:
-#line 390 "src/parse-gram.y" /* yacc.c:1649  */
+#line 390 "src/parse-gram.y" /* yacc.c:1648  */
     { muscle_percent_define_insert ("api.value.union.name",
                                          (yylsp[0]), muscle_keyword, (yyvsp[0].ID),
                                          MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE); }
-#line 2368 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2368 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 44:
-#line 397 "src/parse-gram.y" /* yacc.c:1649  */
+#line 397 "src/parse-gram.y" /* yacc.c:1648  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", translate_code_braceless ((yyvsp[0].BRACED_CODE), (yylsp[0])), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2378 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2378 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 45:
-#line 408 "src/parse-gram.y" /* yacc.c:1649  */
+#line 408 "src/parse-gram.y" /* yacc.c:1648  */
     { current_class = nterm_sym; }
-#line 2384 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2384 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 46:
-#line 409 "src/parse-gram.y" /* yacc.c:1649  */
+#line 409 "src/parse-gram.y" /* yacc.c:1648  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2393 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2393 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 47:
-#line 413 "src/parse-gram.y" /* yacc.c:1649  */
+#line 413 "src/parse-gram.y" /* yacc.c:1648  */
     { current_class = token_sym; }
-#line 2399 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2399 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 48:
-#line 414 "src/parse-gram.y" /* yacc.c:1649  */
+#line 414 "src/parse-gram.y" /* yacc.c:1648  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2408 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2408 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 49:
-#line 419 "src/parse-gram.y" /* yacc.c:1649  */
+#line 419 "src/parse-gram.y" /* yacc.c:1648  */
     {
       tag_seen = true;
       for (symbol_list *list = (yyvsp[0].yytype_74); list; list = list->next)
         symbol_type_set (list->content.sym, (yyvsp[-1].TAG), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].yytype_74));
     }
-#line 2419 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2419 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 50:
-#line 429 "src/parse-gram.y" /* yacc.c:1649  */
+#line 429 "src/parse-gram.y" /* yacc.c:1648  */
     {
       ++current_prec;
       for (symbol_list *list = (yyvsp[0].yytype_72); list; list = list->next)
@@ -2429,300 +2429,286 @@ yyreduce:
         }
       symbol_list_free ((yyvsp[0].yytype_72));
     }
-#line 2433 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2433 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 51:
-#line 441 "src/parse-gram.y" /* yacc.c:1649  */
+#line 441 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.precedence_declarator) = left_assoc; }
-#line 2439 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2439 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 52:
-#line 442 "src/parse-gram.y" /* yacc.c:1649  */
+#line 442 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.precedence_declarator) = right_assoc; }
-#line 2445 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2445 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 53:
-#line 443 "src/parse-gram.y" /* yacc.c:1649  */
+#line 443 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.precedence_declarator) = non_assoc; }
-#line 2451 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2451 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 54:
-#line 444 "src/parse-gram.y" /* yacc.c:1649  */
+#line 444 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.precedence_declarator) = precedence_assoc; }
-#line 2457 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2457 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 55:
-#line 448 "src/parse-gram.y" /* yacc.c:1649  */
+#line 448 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_71) = NULL; }
-#line 2463 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2463 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 56:
-#line 449 "src/parse-gram.y" /* yacc.c:1649  */
+#line 449 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_71) = (yyvsp[0].TAG); tag_seen = true; }
-#line 2469 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2469 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 57:
-#line 455 "src/parse-gram.y" /* yacc.c:1649  */
+#line 455 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_72) = symbol_list_sym_new ((yyvsp[0].yytype_73), (yylsp[0])); }
-#line 2475 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2475 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 58:
-#line 457 "src/parse-gram.y" /* yacc.c:1649  */
+#line 457 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_72) = symbol_list_append ((yyvsp[-1].yytype_72), symbol_list_sym_new ((yyvsp[0].yytype_73), (yylsp[0]))); }
-#line 2481 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2481 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 59:
-#line 462 "src/parse-gram.y" /* yacc.c:1649  */
+#line 462 "src/parse-gram.y" /* yacc.c:1648  */
     {
       (yyval.yytype_73) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2490 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2490 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 60:
-#line 467 "src/parse-gram.y" /* yacc.c:1649  */
+#line 467 "src/parse-gram.y" /* yacc.c:1648  */
     {
       (yyval.yytype_73) = (yyvsp[-1].symbol);
-      symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].INT), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
+      symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].INT), (yylsp[0]));
     }
-#line 2500 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2500 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 61:
-#line 477 "src/parse-gram.y" /* yacc.c:1649  */
+#line 477 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_74) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2506 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2506 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 62:
-#line 479 "src/parse-gram.y" /* yacc.c:1649  */
+#line 479 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_74) = symbol_list_append ((yyvsp[-1].yytype_74), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2512 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2512 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 64:
-#line 484 "src/parse-gram.y" /* yacc.c:1649  */
+#line 484 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.generic_symlist) = symbol_list_append ((yyvsp[-1].generic_symlist), (yyvsp[0].generic_symlist_item)); }
-#line 2518 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2518 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 65:
-#line 488 "src/parse-gram.y" /* yacc.c:1649  */
+#line 488 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.generic_symlist_item) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2524 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2524 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 66:
-#line 489 "src/parse-gram.y" /* yacc.c:1649  */
+#line 489 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.generic_symlist_item) = symbol_list_type_new ((yyvsp[0].tag), (yylsp[0])); }
-#line 2530 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2530 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 68:
-#line 494 "src/parse-gram.y" /* yacc.c:1649  */
+#line 494 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.tag) = uniqstr_new ("*"); }
-#line 2536 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2536 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 69:
-#line 495 "src/parse-gram.y" /* yacc.c:1649  */
+#line 495 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.tag) = uniqstr_new (""); }
-#line 2542 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2542 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 70:
-#line 501 "src/parse-gram.y" /* yacc.c:1649  */
+#line 501 "src/parse-gram.y" /* yacc.c:1648  */
     {
       current_type = (yyvsp[0].TAG);
       tag_seen = true;
     }
-#line 2551 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2551 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 71:
-#line 506 "src/parse-gram.y" /* yacc.c:1649  */
+#line 506 "src/parse-gram.y" /* yacc.c:1648  */
     {
       symbol_class_set ((yyvsp[-2].id), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].id), current_type, (yylsp[-2]));
       if (0 <= (yyvsp[-1].yytype_79))
-        {
-          if (current_class != token_sym)
-            gram_error (&(yylsp[-1]),
-                        _("non-terminals cannot be given an explicit number"));
-          else
-            symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_79), (yylsp[-1]));
-        }
+        symbol_user_token_number_set ((yyvsp[-2].id), (yyvsp[-1].yytype_79), (yylsp[-1]));
       if ((yyvsp[0].yytype_94))
-        {
-          if (current_class != token_sym)
-            gram_error (&(yylsp[0]),
-                        _("non-terminals cannot be given a string alias"));
-          else
-            symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_94), (yylsp[0]));
-        }
-      if (current_class != token_sym && (0 <= (yyvsp[-1].yytype_79) || (yyvsp[0].yytype_94)))
-        YYERROR;
+        symbol_make_alias ((yyvsp[-2].id), (yyvsp[0].yytype_94), (yylsp[0]));
     }
-#line 2578 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2564 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 72:
-#line 532 "src/parse-gram.y" /* yacc.c:1649  */
+#line 518 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_79) = -1; }
-#line 2584 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2570 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 80:
-#line 561 "src/parse-gram.y" /* yacc.c:1649  */
+#line 547 "src/parse-gram.y" /* yacc.c:1648  */
     {
       yyerrok;
     }
-#line 2592 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2578 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 81:
-#line 567 "src/parse-gram.y" /* yacc.c:1649  */
+#line 553 "src/parse-gram.y" /* yacc.c:1648  */
     { current_lhs ((yyvsp[-1].id_colon), (yylsp[-1]), (yyvsp[0].yytype_87)); }
-#line 2598 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2584 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 82:
-#line 568 "src/parse-gram.y" /* yacc.c:1649  */
+#line 554 "src/parse-gram.y" /* yacc.c:1648  */
     {
       /* Free the current lhs. */
       current_lhs (0, (yylsp[-3]), 0);
     }
-#line 2607 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2593 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 83:
-#line 575 "src/parse-gram.y" /* yacc.c:1649  */
+#line 561 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2613 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2599 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 84:
-#line 576 "src/parse-gram.y" /* yacc.c:1649  */
+#line 562 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2619 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2605 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 86:
-#line 583 "src/parse-gram.y" /* yacc.c:1649  */
+#line 569 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2626 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2612 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 87:
-#line 586 "src/parse-gram.y" /* yacc.c:1649  */
+#line 572 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].yytype_87)); }
-#line 2632 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2618 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 88:
-#line 588 "src/parse-gram.y" /* yacc.c:1649  */
+#line 574 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_action_append ((yyvsp[-1].BRACED_CODE), (yylsp[-1]), (yyvsp[0].yytype_87), (yyvsp[-2].yytype_71)); }
-#line 2638 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2624 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 89:
-#line 590 "src/parse-gram.y" /* yacc.c:1649  */
+#line 576 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_predicate_append ((yyvsp[0].BRACED_PREDICATE), (yylsp[0])); }
-#line 2644 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2630 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 90:
-#line 592 "src/parse-gram.y" /* yacc.c:1649  */
+#line 578 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2650 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2636 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 91:
-#line 594 "src/parse-gram.y" /* yacc.c:1649  */
+#line 580 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2656 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2642 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 92:
-#line 596 "src/parse-gram.y" /* yacc.c:1649  */
+#line 582 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_dprec_set ((yyvsp[0].INT), (yylsp[0])); }
-#line 2662 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2648 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 93:
-#line 598 "src/parse-gram.y" /* yacc.c:1649  */
+#line 584 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_merge_set ((yyvsp[0].TAG), (yylsp[0])); }
-#line 2668 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2654 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 94:
-#line 600 "src/parse-gram.y" /* yacc.c:1649  */
+#line 586 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_expect_sr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2674 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2660 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 95:
-#line 602 "src/parse-gram.y" /* yacc.c:1649  */
+#line 588 "src/parse-gram.y" /* yacc.c:1648  */
     { grammar_current_rule_expect_rr ((yyvsp[0].INT), (yylsp[0])); }
-#line 2680 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2666 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 96:
-#line 606 "src/parse-gram.y" /* yacc.c:1649  */
+#line 592 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_87) = 0; }
-#line 2686 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2672 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 97:
-#line 607 "src/parse-gram.y" /* yacc.c:1649  */
+#line 593 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_87) = named_ref_new ((yyvsp[0].BRACKETED_ID), (yylsp[0])); }
-#line 2692 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2678 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 99:
-#line 640 "src/parse-gram.y" /* yacc.c:1649  */
+#line 626 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2698 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2684 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 100:
-#line 641 "src/parse-gram.y" /* yacc.c:1649  */
+#line 627 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].ID); }
-#line 2704 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2690 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 101:
-#line 642 "src/parse-gram.y" /* yacc.c:1649  */
+#line 628 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].STRING); }
-#line 2710 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2696 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 102:
-#line 643 "src/parse-gram.y" /* yacc.c:1649  */
+#line 629 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = strip_braces ((yyvsp[0].BRACED_CODE)); }
-#line 2716 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2702 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 103:
-#line 656 "src/parse-gram.y" /* yacc.c:1649  */
+#line 642 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.id) = symbol_from_uniqstr ((yyvsp[0].ID), (yylsp[0])); }
-#line 2722 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2708 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 104:
-#line 658 "src/parse-gram.y" /* yacc.c:1649  */
+#line 644 "src/parse-gram.y" /* yacc.c:1648  */
     {
       if (current_class == nterm_sym)
         {
@@ -2734,41 +2720,41 @@ yyreduce:
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
     }
-#line 2738 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2724 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 105:
-#line 672 "src/parse-gram.y" /* yacc.c:1649  */
+#line 658 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.id_colon) = symbol_from_uniqstr ((yyvsp[0].ID_COLON), (yylsp[0])); }
-#line 2744 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2730 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 108:
-#line 684 "src/parse-gram.y" /* yacc.c:1649  */
+#line 670 "src/parse-gram.y" /* yacc.c:1648  */
     {
       (yyval.string_as_id) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].STRING)), (yylsp[0]));
       symbol_class_set ((yyval.string_as_id), token_sym, (yylsp[0]), false);
     }
-#line 2753 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2739 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 109:
-#line 692 "src/parse-gram.y" /* yacc.c:1649  */
+#line 678 "src/parse-gram.y" /* yacc.c:1648  */
     { (yyval.yytype_94) = NULL; }
-#line 2759 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2745 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 112:
-#line 699 "src/parse-gram.y" /* yacc.c:1649  */
+#line 685 "src/parse-gram.y" /* yacc.c:1648  */
     {
       muscle_code_grow ("epilogue", translate_code ((yyvsp[0].EPILOGUE), (yylsp[0]), true), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2768 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2754 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
 
-#line 2772 "src/parse-gram.c" /* yacc.c:1649  */
+#line 2758 "src/parse-gram.c" /* yacc.c:1648  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3017,7 +3003,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 705 "src/parse-gram.y" /* yacc.c:1915  */
+#line 691 "src/parse-gram.y" /* yacc.c:1914  */
 
 
 /* Return the location of the left-hand side of a rule whose
