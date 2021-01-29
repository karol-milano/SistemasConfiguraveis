@@ -70,58 +70,8 @@
 
 
 /* Copy the first part of user declarations.  */
-#line 1 "src/parse-gram.y" /* yacc.c:356  */
-/* Bison Grammar Parser                             -*- C -*-
 
-   Copyright (C) 2002-2013 Free Software Foundation, Inc.
-
-   This file is part of Bison, the GNU Compiler Compiler.
-
-   This program is free software: you can redistribute it and/or modify
-   it under the terms of the GNU General Public License as published by
-   the Free Software Foundation, either version 3 of the License, or
-   (at your option) any later version.
-
-   This program is distributed in the hope that it will be useful,
-   but WITHOUT ANY WARRANTY; without even the implied warranty of
-   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-   GNU General Public License for more details.
-
-   You should have received a copy of the GNU General Public License
-   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */
-
-#include <config.h>
-#include "system.h"
-
-#include "c-ctype.h"
-#include "complain.h"
-#include "conflicts.h"
-#include "files.h"
-#include "getargs.h"
-#include "gram.h"
-#include "named-ref.h"
-#include "quotearg.h"
-#include "reader.h"
-#include "symlist.h"
-#include "symtab.h"
-#include "scan-gram.h"
-#include "scan-code.h"
-#include "xmemdup0.h"
-
-#define YYLLOC_DEFAULT(Current, Rhs, N)  (Current) = lloc_default (Rhs, N)
-static YYLTYPE lloc_default (YYLTYPE const *, int);
-
-#define YY_LOCATION_PRINT(File, Loc) \
-          location_print (Loc, File)
-
-static void version_check (location const *loc, char const *version);
-
-static void gram_error (location const *, char const *);
-
-/* A string that describes a char (e.g., 'a' -> "'a'").  */
-static char const *char_name (char);
-
-#line 125 "src/parse-gram.c" /* yacc.c:356  */
+#line 75 "src/parse-gram.c" /* yacc.c:356  */
 
 # ifndef YY_NULL
 #  if defined __cplusplus && 201103L <= __cplusplus
@@ -159,7 +109,11 @@ static char const *char_name (char);
 extern int gram_debug;
 #endif
 /* "%code requires" blocks.  */
-#line 218 "src/parse-gram.y" /* yacc.c:372  */
+#line 21 "src/parse-gram.y" /* yacc.c:372  */
+
+#include "symlist.h"
+#include "symtab.h"
+#line 209 "src/parse-gram.y" /* yacc.c:372  */
 
   typedef enum
   {
@@ -168,10 +122,10 @@ extern int gram_debug;
     param_parse  = 1 << 1,
     param_both   = param_lex | param_parse
   } param_type;
-#line 649 "src/parse-gram.y" /* yacc.c:372  */
+#line 640 "src/parse-gram.y" /* yacc.c:372  */
 #include "muscle-tab.h"
 
-#line 175 "src/parse-gram.c" /* yacc.c:372  */
+#line 129 "src/parse-gram.c" /* yacc.c:372  */
 
 /* Token type.  */
 #ifndef GRAM_TOKENTYPE
@@ -242,29 +196,29 @@ extern int gram_debug;
 typedef union GRAM_STYPE GRAM_STYPE;
 union GRAM_STYPE
 {
-#line 170 "src/parse-gram.y" /* yacc.c:372  */
+#line 161 "src/parse-gram.y" /* yacc.c:372  */
 unsigned char character;
-#line 177 "src/parse-gram.y" /* yacc.c:372  */
+#line 168 "src/parse-gram.y" /* yacc.c:372  */
 
   char *code;
   char const *chars;
-#line 188 "src/parse-gram.y" /* yacc.c:372  */
+#line 179 "src/parse-gram.y" /* yacc.c:372  */
 uniqstr uniqstr;
-#line 196 "src/parse-gram.y" /* yacc.c:372  */
+#line 187 "src/parse-gram.y" /* yacc.c:372  */
 int integer;
-#line 200 "src/parse-gram.y" /* yacc.c:372  */
+#line 191 "src/parse-gram.y" /* yacc.c:372  */
 symbol *symbol;
-#line 205 "src/parse-gram.y" /* yacc.c:372  */
+#line 196 "src/parse-gram.y" /* yacc.c:372  */
 assoc assoc;
-#line 208 "src/parse-gram.y" /* yacc.c:372  */
+#line 199 "src/parse-gram.y" /* yacc.c:372  */
 symbol_list *list;
-#line 211 "src/parse-gram.y" /* yacc.c:372  */
+#line 202 "src/parse-gram.y" /* yacc.c:372  */
 named_ref *named_ref;
-#line 238 "src/parse-gram.y" /* yacc.c:372  */
+#line 229 "src/parse-gram.y" /* yacc.c:372  */
 param_type param;
-#line 413 "src/parse-gram.y" /* yacc.c:372  */
+#line 404 "src/parse-gram.y" /* yacc.c:372  */
 code_props_type code_type;
-#line 651 "src/parse-gram.y" /* yacc.c:372  */
+#line 642 "src/parse-gram.y" /* yacc.c:372  */
 
   struct
   {
@@ -272,7 +226,7 @@ code_props_type code_type;
     muscle_kind kind;
   } value;
 
-#line 276 "src/parse-gram.c" /* yacc.c:372  */
+#line 230 "src/parse-gram.c" /* yacc.c:372  */
 };
 # define GRAM_STYPE_IS_TRIVIAL 1
 # define GRAM_STYPE_IS_DECLARED 1
@@ -300,9 +254,25 @@ int gram_parse (void);
 
 /* Copy the second part of user declarations.  */
 
-#line 304 "src/parse-gram.c" /* yacc.c:375  */
+#line 258 "src/parse-gram.c" /* yacc.c:375  */
 /* Unqualified %code blocks.  */
-#line 53 "src/parse-gram.y" /* yacc.c:376  */
+#line 27 "src/parse-gram.y" /* yacc.c:376  */
+
+#include <config.h>
+#include "system.h"
+
+#include "c-ctype.h"
+#include "complain.h"
+#include "conflicts.h"
+#include "files.h"
+#include "getargs.h"
+#include "gram.h"
+#include "named-ref.h"
+#include "quotearg.h"
+#include "reader.h"
+#include "scan-gram.h"
+#include "scan-code.h"
+#include "xmemdup0.h"
 
   static int current_prec = 0;
   static location current_lhs_location;
@@ -314,26 +284,27 @@ int gram_parse (void);
   /** Set the new current left-hand side symbol, possibly common
    * to several right-hand side parts of rule.
    */
-  static
-  void
-  current_lhs (symbol *sym, location loc, named_ref *ref)
-  {
-    current_lhs_symbol = sym;
-    current_lhs_location = loc;
-    /* In order to simplify memory management, named references for lhs
-       are always assigned by deep copy into the current symbol_list
-       node.  This is because a single named-ref in the grammar may
-       result in several uses when the user factors lhs between several
-       rules using "|".  Therefore free the parser's original copy.  */
-    free (current_lhs_named_ref);
-    current_lhs_named_ref = ref;
-  }
+  static void current_lhs (symbol *sym, location loc, named_ref *ref);
+
+  #define YYLLOC_DEFAULT(Current, Rhs, N)         \
+    (Current) = lloc_default (Rhs, N)
+  static YYLTYPE lloc_default (YYLTYPE const *, int);
+
+  #define YY_LOCATION_PRINT(File, Loc)            \
+    location_print (Loc, File)
+
+  static void version_check (location const *loc, char const *version);
+
+  static void gram_error (location const *, char const *);
+
+  /* A string that describes a char (e.g., 'a' -> "'a'").  */
+  static char const *char_name (char);
 
   #define YYTYPE_INT16 int_fast16_t
   #define YYTYPE_INT8 int_fast8_t
   #define YYTYPE_UINT16 uint_fast16_t
   #define YYTYPE_UINT8 uint_fast8_t
-#line 228 "src/parse-gram.y" /* yacc.c:376  */
+#line 219 "src/parse-gram.y" /* yacc.c:376  */
 
   /** Add a lex-param and/or a parse-param.
    *
@@ -344,7 +315,7 @@ int gram_parse (void);
   static void add_param (param_type type, char *decl, location loc);
   static param_type current_param = param_none;
 
-#line 348 "src/parse-gram.c" /* yacc.c:376  */
+#line 319 "src/parse-gram.c" /* yacc.c:376  */
 
 #ifdef short
 # undef short
@@ -588,18 +559,18 @@ static const yytype_uint8 yytranslate[] =
   /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
 static const yytype_uint16 yyrline[] =
 {
-       0,   261,   261,   270,   271,   275,   276,   286,   290,   295,
-     296,   301,   307,   308,   309,   310,   315,   324,   325,   326,
-     327,   328,   329,   329,   330,   331,   355,   356,   357,   358,
-     362,   363,   372,   373,   374,   378,   390,   394,   398,   405,
-     416,   417,   427,   428,   432,   444,   444,   449,   449,   454,
-     465,   480,   481,   482,   483,   487,   488,   493,   495,   500,
-     505,   515,   517,   522,   523,   527,   528,   532,   533,   534,
-     539,   544,   549,   555,   561,   572,   573,   582,   583,   589,
-     590,   591,   598,   598,   606,   607,   608,   613,   616,   618,
-     620,   622,   624,   626,   628,   633,   634,   644,   645,   670,
-     671,   672,   673,   682,   702,   704,   713,   718,   719,   724,
-     732,   733
+       0,   252,   252,   261,   262,   266,   267,   277,   281,   286,
+     287,   292,   298,   299,   300,   301,   306,   315,   316,   317,
+     318,   319,   320,   320,   321,   322,   346,   347,   348,   349,
+     353,   354,   363,   364,   365,   369,   381,   385,   389,   396,
+     407,   408,   418,   419,   423,   435,   435,   440,   440,   445,
+     456,   471,   472,   473,   474,   478,   479,   484,   486,   491,
+     496,   506,   508,   513,   514,   518,   519,   523,   524,   525,
+     530,   535,   540,   546,   552,   563,   564,   573,   574,   580,
+     581,   582,   589,   589,   597,   598,   599,   604,   607,   609,
+     611,   613,   615,   617,   619,   624,   625,   635,   636,   661,
+     662,   663,   664,   673,   693,   695,   704,   709,   710,   715,
+     723,   724
 };
 #endif
 
@@ -971,73 +942,73 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
   switch (yytype)
     {
           case 3: /* "string"  */
-#line 183 "src/parse-gram.y" /* yacc.c:701  */
+#line 174 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), yyo); }
-#line 977 "src/parse-gram.c" /* yacc.c:701  */
+#line 948 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 23: /* "%<flag>"  */
-#line 193 "src/parse-gram.y" /* yacc.c:701  */
+#line 184 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%%%s", ((*yyvaluep).uniqstr)); }
-#line 983 "src/parse-gram.c" /* yacc.c:701  */
+#line 954 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 39: /* "{...}"  */
-#line 185 "src/parse-gram.y" /* yacc.c:701  */
+#line 176 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).code)); }
-#line 989 "src/parse-gram.c" /* yacc.c:701  */
+#line 960 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 41: /* "[identifier]"  */
-#line 191 "src/parse-gram.y" /* yacc.c:701  */
+#line 182 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "[%s]", ((*yyvaluep).uniqstr)); }
-#line 995 "src/parse-gram.c" /* yacc.c:701  */
+#line 966 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 42: /* "char"  */
-#line 172 "src/parse-gram.y" /* yacc.c:701  */
+#line 163 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (char_name (((*yyvaluep).character)), yyo); }
-#line 1001 "src/parse-gram.c" /* yacc.c:701  */
+#line 972 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 43: /* "epilogue"  */
-#line 185 "src/parse-gram.y" /* yacc.c:701  */
+#line 176 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1007 "src/parse-gram.c" /* yacc.c:701  */
+#line 978 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 45: /* "identifier"  */
-#line 190 "src/parse-gram.y" /* yacc.c:701  */
+#line 181 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1013 "src/parse-gram.c" /* yacc.c:701  */
+#line 984 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 46: /* "identifier:"  */
-#line 192 "src/parse-gram.y" /* yacc.c:701  */
+#line 183 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s:", ((*yyvaluep).uniqstr)); }
-#line 1019 "src/parse-gram.c" /* yacc.c:701  */
+#line 990 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 49: /* "%{...%}"  */
-#line 185 "src/parse-gram.y" /* yacc.c:701  */
+#line 176 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1025 "src/parse-gram.c" /* yacc.c:701  */
+#line 996 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 51: /* "<tag>"  */
-#line 194 "src/parse-gram.y" /* yacc.c:701  */
+#line 185 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1031 "src/parse-gram.c" /* yacc.c:701  */
+#line 1002 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 54: /* "integer"  */
-#line 198 "src/parse-gram.y" /* yacc.c:701  */
+#line 189 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%d", ((*yyvaluep).integer)); }
-#line 1037 "src/parse-gram.c" /* yacc.c:701  */
+#line 1008 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 55: /* "%param"  */
-#line 241 "src/parse-gram.y" /* yacc.c:701  */
+#line 232 "src/parse-gram.y" /* yacc.c:701  */
       {
   switch (((*yyvaluep).param))
     {
@@ -1050,35 +1021,35 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
       case param_none: aver (false); break;
     }
 }
-#line 1054 "src/parse-gram.c" /* yacc.c:701  */
+#line 1025 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 65: /* code_props_type  */
-#line 414 "src/parse-gram.y" /* yacc.c:701  */
+#line 405 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", code_props_type_string (((*yyvaluep).code_type))); }
-#line 1060 "src/parse-gram.c" /* yacc.c:701  */
+#line 1031 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 74: /* symbol.prec  */
-#line 202 "src/parse-gram.y" /* yacc.c:701  */
+#line 193 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1066 "src/parse-gram.c" /* yacc.c:701  */
+#line 1037 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 78: /* tag  */
-#line 194 "src/parse-gram.y" /* yacc.c:701  */
+#line 185 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "<%s>", ((*yyvaluep).uniqstr)); }
-#line 1072 "src/parse-gram.c" /* yacc.c:701  */
+#line 1043 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 88: /* variable  */
-#line 190 "src/parse-gram.y" /* yacc.c:701  */
+#line 181 "src/parse-gram.y" /* yacc.c:701  */
       { fputs (((*yyvaluep).uniqstr), yyo); }
-#line 1078 "src/parse-gram.c" /* yacc.c:701  */
+#line 1049 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 89: /* value  */
-#line 660 "src/parse-gram.y" /* yacc.c:701  */
+#line 651 "src/parse-gram.y" /* yacc.c:701  */
       {
   switch (((*yyvaluep).value).kind)
     {
@@ -1087,37 +1058,37 @@ yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvalue
     case muscle_string:  fprintf (yyo, "\"%s\"", ((*yyvaluep).value).chars); break;
     }
 }
-#line 1091 "src/parse-gram.c" /* yacc.c:701  */
+#line 1062 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 90: /* braceless  */
-#line 185 "src/parse-gram.y" /* yacc.c:701  */
+#line 176 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "{\n%s\n}", ((*yyvaluep).chars)); }
-#line 1097 "src/parse-gram.c" /* yacc.c:701  */
+#line 1068 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 91: /* id  */
-#line 202 "src/parse-gram.y" /* yacc.c:701  */
+#line 193 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1103 "src/parse-gram.c" /* yacc.c:701  */
+#line 1074 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 92: /* id_colon  */
-#line 203 "src/parse-gram.y" /* yacc.c:701  */
+#line 194 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s:", ((*yyvaluep).symbol)->tag); }
-#line 1109 "src/parse-gram.c" /* yacc.c:701  */
+#line 1080 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 93: /* symbol  */
-#line 202 "src/parse-gram.y" /* yacc.c:701  */
+#line 193 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1115 "src/parse-gram.c" /* yacc.c:701  */
+#line 1086 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
     case 94: /* string_as_id  */
-#line 202 "src/parse-gram.y" /* yacc.c:701  */
+#line 193 "src/parse-gram.y" /* yacc.c:701  */
       { fprintf (yyo, "%s", ((*yyvaluep).symbol)->tag); }
-#line 1121 "src/parse-gram.c" /* yacc.c:701  */
+#line 1092 "src/parse-gram.c" /* yacc.c:701  */
         break;
 
 
@@ -1829,7 +1800,7 @@ YYLTYPE yylloc = yyloc_default;
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-#line 96 "src/parse-gram.y" /* yacc.c:1446  */
+#line 87 "src/parse-gram.y" /* yacc.c:1446  */
 {
   /* Bison's grammar can initial empty locations, hence a default
      location is needed. */
@@ -1837,7 +1808,7 @@ YYLTYPE yylloc = yyloc_default;
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
 
-#line 1841 "src/parse-gram.c" /* yacc.c:1446  */
+#line 1812 "src/parse-gram.c" /* yacc.c:1446  */
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2031,7 +2002,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-#line 277 "src/parse-gram.y" /* yacc.c:1663  */
+#line 268 "src/parse-gram.y" /* yacc.c:1663  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2041,80 +2012,80 @@ yyreduce:
                         plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2045 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2016 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 7:
-#line 287 "src/parse-gram.y" /* yacc.c:1663  */
+#line 278 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_define_ensure ((yyvsp[0].uniqstr), (yylsp[0]), true);
     }
-#line 2053 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2024 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 8:
-#line 291 "src/parse-gram.y" /* yacc.c:1663  */
+#line 282 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_define_insert ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].value).kind, (yyvsp[0].value).chars,
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2062 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2033 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 9:
-#line 295 "src/parse-gram.y" /* yacc.c:1663  */
+#line 286 "src/parse-gram.y" /* yacc.c:1663  */
     { defines_flag = true; }
-#line 2068 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2039 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 10:
-#line 297 "src/parse-gram.y" /* yacc.c:1663  */
+#line 288 "src/parse-gram.y" /* yacc.c:1663  */
     {
       defines_flag = true;
       spec_defines_file = xstrdup ((yyvsp[0].chars));
     }
-#line 2077 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2048 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 11:
-#line 302 "src/parse-gram.y" /* yacc.c:1663  */
+#line 293 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_define_insert ("parse.error", (yylsp[0]), muscle_keyword,
                                     "verbose",
                                     MUSCLE_PERCENT_DEFINE_GRAMMAR_FILE);
     }
-#line 2087 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2058 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 12:
-#line 307 "src/parse-gram.y" /* yacc.c:1663  */
+#line 298 "src/parse-gram.y" /* yacc.c:1663  */
     { expected_sr_conflicts = (yyvsp[0].integer); }
-#line 2093 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2064 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 13:
-#line 308 "src/parse-gram.y" /* yacc.c:1663  */
+#line 299 "src/parse-gram.y" /* yacc.c:1663  */
     { expected_rr_conflicts = (yyvsp[0].integer); }
-#line 2099 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2070 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 14:
-#line 309 "src/parse-gram.y" /* yacc.c:1663  */
+#line 300 "src/parse-gram.y" /* yacc.c:1663  */
     { spec_file_prefix = (yyvsp[0].chars); }
-#line 2105 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2076 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 15:
-#line 311 "src/parse-gram.y" /* yacc.c:1663  */
+#line 302 "src/parse-gram.y" /* yacc.c:1663  */
     {
       nondeterministic_parser = true;
       glr_parser = true;
     }
-#line 2114 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2085 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 16:
-#line 316 "src/parse-gram.y" /* yacc.c:1663  */
+#line 307 "src/parse-gram.y" /* yacc.c:1663  */
     {
       code_props action;
       code_props_symbol_action_init (&action, (yyvsp[0].code), (yylsp[0]));
@@ -2123,59 +2094,59 @@ yyreduce:
       muscle_code_grow ("initial_action", action.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2127 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2098 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 17:
-#line 324 "src/parse-gram.y" /* yacc.c:1663  */
+#line 315 "src/parse-gram.y" /* yacc.c:1663  */
     { language_argmatch ((yyvsp[0].chars), grammar_prio, (yylsp[-1])); }
-#line 2133 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2104 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 18:
-#line 325 "src/parse-gram.y" /* yacc.c:1663  */
+#line 316 "src/parse-gram.y" /* yacc.c:1663  */
     { spec_name_prefix = (yyvsp[0].chars); }
-#line 2139 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2110 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 19:
-#line 326 "src/parse-gram.y" /* yacc.c:1663  */
+#line 317 "src/parse-gram.y" /* yacc.c:1663  */
     { no_lines_flag = true; }
-#line 2145 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2116 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 20:
-#line 327 "src/parse-gram.y" /* yacc.c:1663  */
+#line 318 "src/parse-gram.y" /* yacc.c:1663  */
     { nondeterministic_parser = true; }
-#line 2151 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2122 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 21:
-#line 328 "src/parse-gram.y" /* yacc.c:1663  */
+#line 319 "src/parse-gram.y" /* yacc.c:1663  */
     { spec_outfile = (yyvsp[0].chars); }
-#line 2157 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2128 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 22:
-#line 329 "src/parse-gram.y" /* yacc.c:1663  */
+#line 320 "src/parse-gram.y" /* yacc.c:1663  */
     { current_param = (yyvsp[0].param); }
-#line 2163 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2134 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 23:
-#line 329 "src/parse-gram.y" /* yacc.c:1663  */
+#line 320 "src/parse-gram.y" /* yacc.c:1663  */
     { current_param = param_none; }
-#line 2169 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2140 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 24:
-#line 330 "src/parse-gram.y" /* yacc.c:1663  */
+#line 321 "src/parse-gram.y" /* yacc.c:1663  */
     { version_check (&(yylsp[0]), (yyvsp[0].chars)); }
-#line 2175 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2146 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 25:
-#line 332 "src/parse-gram.y" /* yacc.c:1663  */
+#line 323 "src/parse-gram.y" /* yacc.c:1663  */
     {
       char const *skeleton_user = (yyvsp[0].chars);
       if (strchr (skeleton_user, '/'))
@@ -2199,49 +2170,49 @@ yyreduce:
         }
       skeleton_arg (skeleton_user, grammar_prio, (yylsp[-1]));
     }
-#line 2203 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2174 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 26:
-#line 355 "src/parse-gram.y" /* yacc.c:1663  */
+#line 346 "src/parse-gram.y" /* yacc.c:1663  */
     { token_table_flag = true; }
-#line 2209 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2180 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 27:
-#line 356 "src/parse-gram.y" /* yacc.c:1663  */
+#line 347 "src/parse-gram.y" /* yacc.c:1663  */
     { report_flag |= report_states; }
-#line 2215 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2186 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 28:
-#line 357 "src/parse-gram.y" /* yacc.c:1663  */
+#line 348 "src/parse-gram.y" /* yacc.c:1663  */
     { yacc_flag = true; }
-#line 2221 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2192 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 30:
-#line 362 "src/parse-gram.y" /* yacc.c:1663  */
+#line 353 "src/parse-gram.y" /* yacc.c:1663  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2227 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2198 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 31:
-#line 363 "src/parse-gram.y" /* yacc.c:1663  */
+#line 354 "src/parse-gram.y" /* yacc.c:1663  */
     { add_param (current_param, (yyvsp[0].code), (yylsp[0])); }
-#line 2233 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2204 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 34:
-#line 375 "src/parse-gram.y" /* yacc.c:1663  */
+#line 366 "src/parse-gram.y" /* yacc.c:1663  */
     {
       grammar_start_symbol_set ((yyvsp[0].symbol), (yylsp[0]));
     }
-#line 2241 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2212 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 35:
-#line 379 "src/parse-gram.y" /* yacc.c:1663  */
+#line 370 "src/parse-gram.y" /* yacc.c:1663  */
     {
       code_props code;
       code_props_symbol_action_init (&code, (yyvsp[-1].code), (yylsp[-1]));
@@ -2253,111 +2224,111 @@ yyreduce:
         symbol_list_free ((yyvsp[0].list));
       }
     }
-#line 2257 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2228 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 36:
-#line 391 "src/parse-gram.y" /* yacc.c:1663  */
+#line 382 "src/parse-gram.y" /* yacc.c:1663  */
     {
       default_prec = true;
     }
-#line 2265 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2236 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 37:
-#line 395 "src/parse-gram.y" /* yacc.c:1663  */
+#line 386 "src/parse-gram.y" /* yacc.c:1663  */
     {
       default_prec = false;
     }
-#line 2273 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2244 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 38:
-#line 399 "src/parse-gram.y" /* yacc.c:1663  */
+#line 390 "src/parse-gram.y" /* yacc.c:1663  */
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
          muscle_user_name_list_grow.  */
       muscle_code_grow ("percent_code()", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2284 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2255 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 39:
-#line 406 "src/parse-gram.y" /* yacc.c:1663  */
+#line 397 "src/parse-gram.y" /* yacc.c:1663  */
     {
       muscle_percent_code_grow ((yyvsp[-1].uniqstr), (yylsp[-1]), (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2293 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2264 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 40:
-#line 416 "src/parse-gram.y" /* yacc.c:1663  */
+#line 407 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.code_type) = destructor; }
-#line 2299 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2270 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 41:
-#line 417 "src/parse-gram.y" /* yacc.c:1663  */
+#line 408 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.code_type) = printer; }
-#line 2305 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2276 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 42:
-#line 427 "src/parse-gram.y" /* yacc.c:1663  */
+#line 418 "src/parse-gram.y" /* yacc.c:1663  */
     {}
-#line 2311 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2282 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 43:
-#line 428 "src/parse-gram.y" /* yacc.c:1663  */
+#line 419 "src/parse-gram.y" /* yacc.c:1663  */
     { muscle_code_grow ("union_name", (yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2317 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2288 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 44:
-#line 433 "src/parse-gram.y" /* yacc.c:1663  */
+#line 424 "src/parse-gram.y" /* yacc.c:1663  */
     {
       union_seen = true;
       muscle_code_grow ("union_members", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2327 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2298 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 45:
-#line 444 "src/parse-gram.y" /* yacc.c:1663  */
+#line 435 "src/parse-gram.y" /* yacc.c:1663  */
     { current_class = nterm_sym; }
-#line 2333 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2304 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 46:
-#line 445 "src/parse-gram.y" /* yacc.c:1663  */
+#line 436 "src/parse-gram.y" /* yacc.c:1663  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2342 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2313 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 47:
-#line 449 "src/parse-gram.y" /* yacc.c:1663  */
+#line 440 "src/parse-gram.y" /* yacc.c:1663  */
     { current_class = token_sym; }
-#line 2348 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2319 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 48:
-#line 450 "src/parse-gram.y" /* yacc.c:1663  */
+#line 441 "src/parse-gram.y" /* yacc.c:1663  */
     {
       current_class = unknown_sym;
       current_type = NULL;
     }
-#line 2357 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2328 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 49:
-#line 455 "src/parse-gram.y" /* yacc.c:1663  */
+#line 446 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_list *list;
       tag_seen = true;
@@ -2365,11 +2336,11 @@ yyreduce:
         symbol_type_set (list->content.sym, (yyvsp[-1].uniqstr), (yylsp[-1]));
       symbol_list_free ((yyvsp[0].list));
     }
-#line 2369 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2340 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 50:
-#line 466 "src/parse-gram.y" /* yacc.c:1663  */
+#line 457 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_list *list;
       ++current_prec;
@@ -2381,301 +2352,301 @@ yyreduce:
       symbol_list_free ((yyvsp[0].list));
       current_type = NULL;
     }
-#line 2385 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2356 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 51:
-#line 480 "src/parse-gram.y" /* yacc.c:1663  */
+#line 471 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = left_assoc; }
-#line 2391 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2362 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 52:
-#line 481 "src/parse-gram.y" /* yacc.c:1663  */
+#line 472 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = right_assoc; }
-#line 2397 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2368 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 53:
-#line 482 "src/parse-gram.y" /* yacc.c:1663  */
+#line 473 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = non_assoc; }
-#line 2403 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2374 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 54:
-#line 483 "src/parse-gram.y" /* yacc.c:1663  */
+#line 474 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.assoc) = precedence_assoc; }
-#line 2409 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2380 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 55:
-#line 487 "src/parse-gram.y" /* yacc.c:1663  */
+#line 478 "src/parse-gram.y" /* yacc.c:1663  */
     { current_type = NULL; }
-#line 2415 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2386 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 56:
-#line 488 "src/parse-gram.y" /* yacc.c:1663  */
+#line 479 "src/parse-gram.y" /* yacc.c:1663  */
     { current_type = (yyvsp[0].uniqstr); tag_seen = true; }
-#line 2421 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2392 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 57:
-#line 494 "src/parse-gram.y" /* yacc.c:1663  */
+#line 485 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2427 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2398 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 58:
-#line 496 "src/parse-gram.y" /* yacc.c:1663  */
+#line 487 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2433 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2404 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 59:
-#line 501 "src/parse-gram.y" /* yacc.c:1663  */
+#line 492 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = (yyvsp[0].symbol);
       symbol_class_set ((yyvsp[0].symbol), token_sym, (yylsp[0]), false);
     }
-#line 2442 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2413 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 60:
-#line 506 "src/parse-gram.y" /* yacc.c:1663  */
+#line 497 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = (yyvsp[-1].symbol);
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
       symbol_class_set ((yyvsp[-1].symbol), token_sym, (yylsp[-1]), false);
     }
-#line 2452 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2423 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 61:
-#line 516 "src/parse-gram.y" /* yacc.c:1663  */
+#line 507 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2458 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2429 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 62:
-#line 518 "src/parse-gram.y" /* yacc.c:1663  */
+#line 509 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0]))); }
-#line 2464 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2435 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 63:
-#line 522 "src/parse-gram.y" /* yacc.c:1663  */
+#line 513 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = (yyvsp[0].list); }
-#line 2470 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2441 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 64:
-#line 523 "src/parse-gram.y" /* yacc.c:1663  */
+#line 514 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_append ((yyvsp[-1].list), (yyvsp[0].list)); }
-#line 2476 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2447 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 65:
-#line 527 "src/parse-gram.y" /* yacc.c:1663  */
+#line 518 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_sym_new ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2482 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2453 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 66:
-#line 528 "src/parse-gram.y" /* yacc.c:1663  */
+#line 519 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.list) = symbol_list_type_new ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2488 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2459 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 68:
-#line 533 "src/parse-gram.y" /* yacc.c:1663  */
+#line 524 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.uniqstr) = uniqstr_new ("*"); }
-#line 2494 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2465 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 69:
-#line 534 "src/parse-gram.y" /* yacc.c:1663  */
+#line 525 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.uniqstr) = uniqstr_new (""); }
-#line 2500 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2471 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 70:
-#line 540 "src/parse-gram.y" /* yacc.c:1663  */
+#line 531 "src/parse-gram.y" /* yacc.c:1663  */
     {
       current_type = (yyvsp[0].uniqstr);
       tag_seen = true;
     }
-#line 2509 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2480 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 71:
-#line 545 "src/parse-gram.y" /* yacc.c:1663  */
+#line 536 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
     }
-#line 2518 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2489 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 72:
-#line 550 "src/parse-gram.y" /* yacc.c:1663  */
+#line 541 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_user_token_number_set ((yyvsp[-1].symbol), (yyvsp[0].integer), (yylsp[0]));
     }
-#line 2528 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2499 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 73:
-#line 556 "src/parse-gram.y" /* yacc.c:1663  */
+#line 547 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_class_set ((yyvsp[-1].symbol), current_class, (yylsp[-1]), true);
       symbol_type_set ((yyvsp[-1].symbol), current_type, (yylsp[-1]));
       symbol_make_alias ((yyvsp[-1].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2538 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2509 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 74:
-#line 562 "src/parse-gram.y" /* yacc.c:1663  */
+#line 553 "src/parse-gram.y" /* yacc.c:1663  */
     {
       symbol_class_set ((yyvsp[-2].symbol), current_class, (yylsp[-2]), true);
       symbol_type_set ((yyvsp[-2].symbol), current_type, (yylsp[-2]));
       symbol_user_token_number_set ((yyvsp[-2].symbol), (yyvsp[-1].integer), (yylsp[-1]));
       symbol_make_alias ((yyvsp[-2].symbol), (yyvsp[0].symbol), (yyloc));
     }
-#line 2549 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2520 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 81:
-#line 592 "src/parse-gram.y" /* yacc.c:1663  */
+#line 583 "src/parse-gram.y" /* yacc.c:1663  */
     {
       yyerrok;
     }
-#line 2557 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2528 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 82:
-#line 598 "src/parse-gram.y" /* yacc.c:1663  */
+#line 589 "src/parse-gram.y" /* yacc.c:1663  */
     { current_lhs ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2563 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2534 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 83:
-#line 599 "src/parse-gram.y" /* yacc.c:1663  */
+#line 590 "src/parse-gram.y" /* yacc.c:1663  */
     {
     /* Free the current lhs. */
     current_lhs (0, (yylsp[-3]), 0);
   }
-#line 2572 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2543 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 84:
-#line 606 "src/parse-gram.y" /* yacc.c:1663  */
+#line 597 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2578 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2549 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 85:
-#line 607 "src/parse-gram.y" /* yacc.c:1663  */
+#line 598 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_end ((yylsp[0])); }
-#line 2584 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2555 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 87:
-#line 614 "src/parse-gram.y" /* yacc.c:1663  */
+#line 605 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
                                   current_lhs_named_ref); }
-#line 2591 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2562 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 88:
-#line 617 "src/parse-gram.y" /* yacc.c:1663  */
+#line 608 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_symbol_append ((yyvsp[-1].symbol), (yylsp[-1]), (yyvsp[0].named_ref)); }
-#line 2597 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2568 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 89:
-#line 619 "src/parse-gram.y" /* yacc.c:1663  */
+#line 610 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
-#line 2603 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2574 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 90:
-#line 621 "src/parse-gram.y" /* yacc.c:1663  */
+#line 612 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
-#line 2609 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2580 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 91:
-#line 623 "src/parse-gram.y" /* yacc.c:1663  */
+#line 614 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_empty_set ((yylsp[0])); }
-#line 2615 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2586 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 92:
-#line 625 "src/parse-gram.y" /* yacc.c:1663  */
+#line 616 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_prec_set ((yyvsp[0].symbol), (yylsp[0])); }
-#line 2621 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2592 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 93:
-#line 627 "src/parse-gram.y" /* yacc.c:1663  */
+#line 618 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_dprec_set ((yyvsp[0].integer), (yylsp[0])); }
-#line 2627 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2598 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 94:
-#line 629 "src/parse-gram.y" /* yacc.c:1663  */
+#line 620 "src/parse-gram.y" /* yacc.c:1663  */
     { grammar_current_rule_merge_set ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2633 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2604 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 95:
-#line 633 "src/parse-gram.y" /* yacc.c:1663  */
+#line 624 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.named_ref) = 0; }
-#line 2639 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2610 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 96:
-#line 634 "src/parse-gram.y" /* yacc.c:1663  */
+#line 625 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.named_ref) = named_ref_new((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2645 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2616 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 98:
-#line 645 "src/parse-gram.y" /* yacc.c:1663  */
+#line 636 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[0].chars)); }
-#line 2651 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2622 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 99:
-#line 670 "src/parse-gram.y" /* yacc.c:1663  */
+#line 661 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = ""; }
-#line 2657 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2628 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 100:
-#line 671 "src/parse-gram.y" /* yacc.c:1663  */
+#line 662 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_keyword; (yyval.value).chars = (yyvsp[0].uniqstr); }
-#line 2663 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2634 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 101:
-#line 672 "src/parse-gram.y" /* yacc.c:1663  */
+#line 663 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_string;  (yyval.value).chars = (yyvsp[0].chars); }
-#line 2669 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2640 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 102:
-#line 673 "src/parse-gram.y" /* yacc.c:1663  */
+#line 664 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.value).kind = muscle_code;    (yyval.value).chars = (yyvsp[0].chars); }
-#line 2675 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2646 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 103:
-#line 683 "src/parse-gram.y" /* yacc.c:1663  */
+#line 674 "src/parse-gram.y" /* yacc.c:1663  */
     {
       code_props plain_code;
       (yyvsp[0].code)[strlen ((yyvsp[0].code)) - 1] = '\0';
@@ -2684,42 +2655,42 @@ yyreduce:
       gram_scanner_last_string_free ();
       (yyval.chars) = plain_code.code;
     }
-#line 2688 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2659 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 104:
-#line 703 "src/parse-gram.y" /* yacc.c:1663  */
+#line 694 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2694 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2665 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 105:
-#line 705 "src/parse-gram.y" /* yacc.c:1663  */
+#line 696 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[0].character)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
       symbol_user_token_number_set ((yyval.symbol), (yyvsp[0].character), (yylsp[0]));
     }
-#line 2704 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2675 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 106:
-#line 713 "src/parse-gram.y" /* yacc.c:1663  */
+#line 704 "src/parse-gram.y" /* yacc.c:1663  */
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[0].uniqstr), (yylsp[0])); }
-#line 2710 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2681 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 109:
-#line 725 "src/parse-gram.y" /* yacc.c:1663  */
+#line 716 "src/parse-gram.y" /* yacc.c:1663  */
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[0].chars)), (yylsp[0]));
       symbol_class_set ((yyval.symbol), token_sym, (yylsp[0]), false);
     }
-#line 2719 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2690 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
   case 111:
-#line 734 "src/parse-gram.y" /* yacc.c:1663  */
+#line 725 "src/parse-gram.y" /* yacc.c:1663  */
     {
       code_props plain_code;
       code_props_plain_init (&plain_code, (yyvsp[0].chars), (yylsp[0]));
@@ -2728,11 +2699,11 @@ yyreduce:
       muscle_code_grow ("epilogue", plain_code.code, (yylsp[0]));
       code_scanner_last_string_free ();
     }
-#line 2732 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2703 "src/parse-gram.c" /* yacc.c:1663  */
     break;
 
 
-#line 2736 "src/parse-gram.c" /* yacc.c:1663  */
+#line 2707 "src/parse-gram.c" /* yacc.c:1663  */
         default: break;
       }
     if (yychar_backup != yychar)
@@ -2979,7 +2950,7 @@ yyreturn:
 #endif
   return yyresult;
 }
-#line 744 "src/parse-gram.y" /* yacc.c:1923  */
+#line 735 "src/parse-gram.y" /* yacc.c:1923  */
 
 
 /* Return the location of the left-hand side of a rule whose
@@ -3093,3 +3064,18 @@ char_name (char c)
       return quotearg_style (escape_quoting_style, buf);
     }
 }
+
+static
+void
+current_lhs (symbol *sym, location loc, named_ref *ref)
+{
+  current_lhs_symbol = sym;
+  current_lhs_location = loc;
+  /* In order to simplify memory management, named references for lhs
+     are always assigned by deep copy into the current symbol_list
+     node.  This is because a single named-ref in the grammar may
+     result in several uses when the user factors lhs between several
+     rules using "|".  Therefore free the parser's original copy.  */
+  free (current_lhs_named_ref);
+  current_lhs_named_ref = ref;
+}
