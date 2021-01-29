@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.5.49-3790-dirty.  */
+/* A Bison parser, made by GNU Bison 3.5.1.51-6ada9.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.5.49-3790-dirty"
+#define YYBISON_VERSION "3.5.1.51-6ada9"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -505,19 +505,19 @@ union yyalloc
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_int16 yyrline[] =
 {
-       0,   294,   294,   303,   304,   308,   309,   315,   319,   324,
-     325,   330,   331,   332,   333,   334,   339,   344,   345,   346,
-     347,   348,   349,   349,   350,   351,   352,   353,   354,   355,
-     356,   357,   361,   362,   371,   372,   376,   387,   391,   395,
-     403,   413,   414,   424,   425,   431,   444,   444,   449,   449,
-     454,   458,   468,   469,   470,   471,   475,   476,   481,   482,
-     486,   487,   491,   492,   493,   506,   515,   519,   523,   531,
-     532,   536,   549,   550,   555,   556,   557,   575,   579,   583,
-     591,   593,   598,   605,   615,   619,   623,   631,   636,   648,
-     649,   655,   656,   657,   664,   664,   672,   673,   674,   679,
-     682,   684,   686,   688,   690,   692,   694,   696,   698,   703,
-     704,   713,   737,   738,   739,   740,   752,   754,   781,   786,
-     787,   792,   800,   801
+       0,   288,   288,   297,   298,   302,   303,   309,   313,   318,
+     319,   324,   325,   326,   327,   328,   333,   338,   339,   340,
+     341,   342,   343,   343,   344,   345,   346,   347,   348,   349,
+     350,   351,   355,   356,   365,   366,   370,   381,   385,   389,
+     397,   407,   408,   418,   419,   425,   438,   438,   443,   443,
+     448,   452,   462,   463,   464,   465,   469,   470,   475,   476,
+     480,   481,   485,   486,   487,   500,   509,   513,   517,   525,
+     526,   530,   543,   544,   549,   550,   551,   569,   573,   577,
+     585,   587,   592,   599,   609,   613,   617,   625,   630,   642,
+     643,   649,   650,   651,   658,   658,   666,   667,   668,   673,
+     676,   678,   680,   682,   684,   686,   688,   690,   692,   697,
+     698,   707,   731,   732,   733,   734,   746,   748,   775,   780,
+     781,   786,   794,   795
 };
 #endif
 
@@ -535,17 +535,18 @@ yysymbol_name (int yysymbol)
 {
   static const char *const yy_sname[] =
   {
-  "end of file", "error", "$undefined", "string", "translatable string",
-  "%token", "%nterm", "%type", "%destructor", "%printer", "%left",
-  "%right", "%nonassoc", "%precedence", "%prec", "%dprec", "%merge",
-  "%code", "%default-prec", "%define", "%defines", "%error-verbose",
-  "%expect", "%expect-rr", "%<flag>", "%file-prefix", "%glr-parser",
-  "%initial-action", "%language", "%name-prefix", "%no-default-prec",
-  "%no-lines", "%nondeterministic-parser", "%output", "%pure-parser",
-  "%require", "%skeleton", "%start", "%token-table", "%verbose", "%yacc",
-  "{...}", "%?{...}", "[identifier]", "character literal", ":", "epilogue",
-  "=", "identifier", "identifier:", "%%", "|", "%{...%}", ";", "<tag>",
-  "<*>", "<>", "integer", "%param", "%union", "%empty", "$accept", "input",
+  N_("end of file"), "error", "$undefined", N_("string"),
+  N_("translatable string"), "%token", "%nterm", "%type", "%destructor",
+  "%printer", "%left", "%right", "%nonassoc", "%precedence", "%prec",
+  "%dprec", "%merge", "%code", "%default-prec", "%define", "%defines",
+  "%error-verbose", "%expect", "%expect-rr", "%<flag>", "%file-prefix",
+  "%glr-parser", "%initial-action", "%language", "%name-prefix",
+  "%no-default-prec", "%no-lines", "%nondeterministic-parser", "%output",
+  "%pure-parser", "%require", "%skeleton", "%start", "%token-table",
+  "%verbose", "%yacc", "{...}", "%?{...}", N_("[identifier]"),
+  N_("character literal"), ":", N_("epilogue"), "=", N_("identifier"),
+  N_("identifier:"), "%%", "|", "%{...%}", ";", N_("<tag>"), "<*>", "<>",
+  N_("integer literal"), "%param", "%union", "%empty", "$accept", "input",
   "prologue_declarations", "prologue_declaration", "$@1", "params",
   "grammar_declaration", "code_props_type", "union_name",
   "symbol_declaration", "$@2", "$@3", "precedence_declarator", "tag.opt",
@@ -557,7 +558,21 @@ yysymbol_name (int yysymbol)
   "named_ref.opt", "variable", "value", "id", "id_colon", "symbol",
   "string_as_id", "epilogue.opt", YY_NULLPTR
   };
-  return yy_sname[yysymbol];
+  /* YYTRANSLATABLE[SYMBOL-NUM] -- Whether YYTNAME[SYMBOL-NUM] is
+     internationalizable.  */
+  static yytype_int8 yytranslatable[] =
+  {
+       1,     0,     0,     1,     1,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
+       0,     0,     0,     1,     1,     0,     1,     0,     1,     1,
+       0,     0,     0,     0,     1,     0,     0,     1,     0,     0,
+       0
+  };
+  return (yysymbol < YYNTOKENS && yytranslatable[yysymbol]
+          ? _(yy_sname[yysymbol])
+          : yy_sname[yysymbol]);
 }
 #endif
 
@@ -992,7 +1007,7 @@ tron (yyo);
          { fprintf (yyo, "<%s>", ((*yyvaluep).TAG)); }
         break;
 
-    case 57: /* "integer"  */
+    case 57: /* "integer literal"  */
          { fprintf (yyo, "%d", ((*yyvaluep).INT)); }
         break;
 
