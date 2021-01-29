@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.3.2.147-dd3d0.  */
+/* A Bison parser, made by GNU Bison 3.3.2.153-f5a4-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.3.2.147-dd3d0"
+#define YYBISON_VERSION "3.3.2.153-f5a4-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -186,6 +186,10 @@
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
 
+  /* Add style to semantic values in traces.  */
+  static void tron (FILE *yyo);
+  static void troff (FILE *yyo);
+
   /** Add a lex-param and/or a parse-param.
    *
    * \param type  where to push this formal argument.
@@ -469,19 +473,19 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   283,   283,   292,   293,   297,   298,   304,   308,   313,
-     314,   319,   320,   321,   322,   323,   328,   333,   334,   335,
-     336,   337,   338,   338,   339,   340,   341,   342,   343,   344,
-     345,   349,   350,   359,   360,   364,   375,   379,   383,   391,
-     401,   402,   412,   413,   419,   432,   432,   437,   437,   442,
-     446,   456,   457,   458,   459,   463,   464,   469,   470,   474,
-     475,   479,   480,   481,   494,   503,   507,   511,   519,   520,
-     524,   537,   538,   550,   554,   558,   566,   568,   573,   580,
-     590,   594,   598,   606,   607,   615,   616,   622,   623,   624,
-     631,   631,   639,   640,   641,   646,   649,   651,   653,   655,
-     657,   659,   661,   663,   665,   670,   671,   680,   704,   705,
-     706,   707,   719,   721,   736,   741,   742,   747,   756,   757,
-     761,   762
+       0,   290,   290,   299,   300,   304,   305,   311,   315,   320,
+     321,   326,   327,   328,   329,   330,   335,   340,   341,   342,
+     343,   344,   345,   345,   346,   347,   348,   349,   350,   351,
+     352,   356,   357,   366,   367,   371,   382,   386,   390,   398,
+     408,   409,   419,   420,   426,   439,   439,   444,   444,   449,
+     453,   463,   464,   465,   466,   470,   471,   476,   477,   481,
+     482,   486,   487,   488,   501,   510,   514,   518,   526,   527,
+     531,   544,   545,   557,   561,   565,   573,   575,   580,   587,
+     597,   601,   605,   613,   614,   622,   623,   629,   630,   631,
+     638,   638,   646,   647,   648,   653,   656,   658,   660,   662,
+     664,   666,   668,   670,   672,   677,   678,   687,   711,   712,
+     713,   714,   726,   728,   743,   748,   749,   754,   763,   764,
+     768,   769
 };
 #endif
 
@@ -876,10 +880,13 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
   if (yytype < YYNTOKENS)
     YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
 # endif
+/* "%code pre-printer" blocks.  */
+tron (yyo);
+
   switch (yytype)
     {
     case 3: /* "string"  */
-      { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).STRING)), yyo); }
+      { fputs (((*yyvaluep).STRING), yyo); }
         break;
 
     case 20: /* "%error-verbose"  */
@@ -903,11 +910,11 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
         break;
 
     case 39: /* "{...}"  */
-      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_CODE)); }
+      { fputs (((*yyvaluep).BRACED_CODE), yyo); }
         break;
 
     case 40: /* "%?{...}"  */
-      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).BRACED_PREDICATE)); }
+      { fputs (((*yyvaluep).BRACED_PREDICATE), yyo); }
         break;
 
     case 41: /* "[identifier]"  */
@@ -919,7 +926,7 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
         break;
 
     case 44: /* "epilogue"  */
-      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).EPILOGUE)); }
+      { fputs (((*yyvaluep).EPILOGUE), yyo); }
         break;
 
     case 46: /* "identifier"  */
@@ -931,7 +938,7 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
         break;
 
     case 50: /* "%{...%}"  */
-      { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).PROLOGUE)); }
+      { fputs (((*yyvaluep).PROLOGUE), yyo); }
         break;
 
     case 52: /* "<tag>"  */
@@ -1055,6 +1062,9 @@ yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YY
       default:
         break;
     }
+/* "%code post-printer" blocks.  */
+troff (yyo);
+
 }
 
 
@@ -3038,3 +3048,13 @@ current_lhs (symbol *sym, location loc, named_ref *ref)
   free (current_lhs_named_ref);
   current_lhs_named_ref = ref;
 }
+
+static void tron (FILE *yyo)
+{
+  begin_use_class ("value", yyo);
+}
+
+static void troff (FILE *yyo)
+{
+  end_use_class ("value", yyo);
+}
