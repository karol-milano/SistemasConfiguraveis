@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.4.1.72-9d4b.  */
+/* A Bison parser, made by GNU Bison 3.4.2.86-be13.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.1.72-9d4b"
+#define YYBISON_VERSION "3.4.2.86-be13"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -179,6 +179,7 @@
   /* Handle a %yacc directive.  */
   static void handle_yacc (location const *loc);
 
+  /* Implementation of yyerror.  */
   static void gram_error (location const *, char const *);
 
   /* A string that describes a char (e.g., 'a' -> "'a'").  */
@@ -431,64 +432,25 @@ union yyalloc
 
 /* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
    as returned by yylex, with out-of-bounds checking.  */
-#define YYTRANSLATE(YYX)                                                \
-  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)
-
-/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
-   as returned by yylex.  */
-static const yytype_uint8 yytranslate[] =
-{
-       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
-       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
-       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
-      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
-      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
-      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
-      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
-      55,    56,    57,    58,    59
-};
+#define YYTRANSLATE(YYX) (YYX)
 
 #if GRAM_DEBUG
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   294,   294,   303,   304,   308,   309,   315,   319,   324,
-     325,   330,   331,   332,   333,   334,   339,   344,   345,   346,
-     347,   348,   349,   349,   350,   351,   352,   353,   354,   355,
-     356,   357,   361,   362,   371,   372,   376,   387,   391,   395,
-     403,   413,   414,   424,   425,   431,   444,   444,   449,   449,
-     454,   458,   468,   469,   470,   471,   475,   476,   481,   482,
-     486,   487,   491,   492,   493,   506,   515,   519,   523,   531,
-     532,   536,   549,   550,   562,   566,   570,   578,   580,   585,
-     592,   602,   606,   610,   618,   619,   627,   628,   634,   635,
-     636,   643,   643,   651,   652,   653,   658,   661,   663,   665,
-     667,   669,   671,   673,   675,   677,   682,   683,   692,   716,
-     717,   718,   719,   731,   733,   748,   753,   754,   759,   768,
-     769,   773,   774
+       0,   296,   296,   305,   306,   310,   311,   317,   321,   326,
+     327,   332,   333,   334,   335,   336,   341,   346,   347,   348,
+     349,   350,   351,   351,   352,   353,   354,   355,   356,   357,
+     358,   359,   363,   364,   373,   374,   378,   389,   393,   397,
+     405,   415,   416,   426,   427,   433,   446,   446,   451,   451,
+     456,   460,   470,   471,   472,   473,   477,   478,   483,   484,
+     488,   489,   493,   494,   495,   508,   517,   521,   525,   533,
+     534,   538,   551,   552,   564,   568,   572,   580,   582,   587,
+     594,   604,   608,   612,   620,   621,   629,   630,   636,   637,
+     638,   645,   645,   653,   654,   655,   660,   663,   665,   667,
+     669,   671,   673,   675,   677,   679,   684,   685,   694,   718,
+     719,   720,   721,   733,   735,   762,   767,   768,   773,   782,
+     783,   787,   788
 };
 #endif
 
@@ -508,19 +470,20 @@ static const char *const yytname[] =
   "\"%nondeterministic-parser\"", "\"%output\"", "\"%pure-parser\"",
   "\"%require\"", "\"%skeleton\"", "\"%start\"", "\"%token-table\"",
   "\"%verbose\"", "\"%yacc\"", "\"{...}\"", "\"%?{...}\"",
-  "\"[identifier]\"", "\"char\"", "\":\"", "\"epilogue\"", "\"=\"",
-  "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"", "\"%{...%}\"",
-  "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"integer\"", "\"%param\"",
-  "\"%union\"", "\"%empty\"", "$accept", "input", "prologue_declarations",
-  "prologue_declaration", "$@1", "params", "grammar_declaration",
-  "code_props_type", "union_name", "symbol_declaration", "$@2", "$@3",
-  "precedence_declarator", "tag.opt", "generic_symlist",
-  "generic_symlist_item", "tag", "nterm_decls", "token_decls",
-  "token_decl.1", "token_decl", "int.opt", "token_decls_for_prec",
-  "token_decl_for_prec.1", "token_decl_for_prec", "symbol_decls",
-  "symbol_decl.1", "grammar", "rules_or_grammar_declaration", "rules",
-  "$@4", "rhses.1", "rhs", "named_ref.opt", "variable", "value", "id",
-  "id_colon", "symbol", "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
+  "\"[identifier]\"", "\"character literal\"", "\":\"", "\"epilogue\"",
+  "\"=\"", "\"identifier\"", "\"identifier:\"", "\"%%\"", "\"|\"",
+  "\"%{...%}\"", "\";\"", "\"<tag>\"", "\"<*>\"", "\"<>\"", "\"integer\"",
+  "\"%param\"", "\"%union\"", "\"%empty\"", "$accept", "input",
+  "prologue_declarations", "prologue_declaration", "$@1", "params",
+  "grammar_declaration", "code_props_type", "union_name",
+  "symbol_declaration", "$@2", "$@3", "precedence_declarator", "tag.opt",
+  "generic_symlist", "generic_symlist_item", "tag", "nterm_decls",
+  "token_decls", "token_decl.1", "token_decl", "int.opt",
+  "token_decls_for_prec", "token_decl_for_prec.1", "token_decl_for_prec",
+  "symbol_decls", "symbol_decl.1", "grammar",
+  "rules_or_grammar_declaration", "rules", "$@4", "rhses.1", "rhs",
+  "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
+  "string_as_id", "string_as_id.opt", "epilogue.opt", YY_NULLPTR
 };
 #endif
 
@@ -925,7 +888,7 @@ tron (yyo);
          { fprintf (yyo, "[%s]", ((*yyvaluep).BRACKETED_ID)); }
         break;
 
-    case 43: /* "char"  */
+    case 43: /* "character literal"  */
          { fputs (char_name (((*yyvaluep).CHAR)), yyo); }
         break;
 
@@ -2485,12 +2448,24 @@ yyreduce:
 
   case 114:
     {
+      const char *var = "api.token.raw";
       if (current_class == nterm_sym)
         {
-          gram_error (&(yylsp[0]),
-                      _("character literals cannot be nonterminals"));
+          complain (&(yylsp[0]), complaint,
+                    _("character literals cannot be nonterminals"));
           YYERROR;
         }
+      if (muscle_percent_define_ifdef (var))
+        {
+          unsigned indent = 0;
+          complain_indent (&(yylsp[0]), complaint, &indent,
+                           _("character literals cannot be used together"
+                             " with %s"), var);
+          indent += SUB_INDENT;
+          location loc = muscle_percent_define_get_loc (var);
+          complain_indent (&loc, complaint, &indent,
+                           _("definition of %s"), var);
+        }
       (yyval.id) = symbol_get (char_name ((yyvsp[0].CHAR)), (yylsp[0]));
       symbol_class_set ((yyval.id), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.id), (yyvsp[0].CHAR), (yylsp[0]));
