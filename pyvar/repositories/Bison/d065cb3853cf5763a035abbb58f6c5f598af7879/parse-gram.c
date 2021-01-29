@@ -1,8 +1,8 @@
-/* A Bison parser, made by GNU Bison 2.6.5.63-3ada.  */
+/* A Bison parser, made by GNU Bison 2.7.12-4996.  */
 
 /* Bison implementation for Yacc-like parsers in C
    
-      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
+      Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.
    
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.6.5.63-3ada"
+#define YYBISON_VERSION "2.7.12-4996"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -72,7 +72,7 @@
 #define yylloc          gram_lloc
 
 /* Copy the first part of user declarations.  */
-/* Line 360 of yacc.c  */
+/* Line 371 of yacc.c  */
 #line 1 "parse-gram.y"
 /* Bison Grammar Parser                             -*- C -*-
 
@@ -168,7 +168,7 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 #define YYTYPE_UINT16 uint_fast16_t
 #define YYTYPE_UINT8 uint_fast8_t
 
-/* Line 360 of yacc.c  */
+/* Line 371 of yacc.c  */
 #line 173 "parse-gram.c"
 
 # ifndef YY_NULL
@@ -189,8 +189,8 @@ current_lhs(symbol *sym, location loc, named_ref *ref)
 
 /* In a future release of Bison, this section will be replaced
    by #include "parse-gram.h".  */
-#ifndef YY_GRAM_Y_TAB_H_INCLUDED
-# define YY_GRAM_Y_TAB_H_INCLUDED
+#ifndef YY_GRAM__SRC_PARSE_GRAM_H_INCLUDED
+# define YY_GRAM__SRC_PARSE_GRAM_H_INCLUDED
 /* Enabling traces.  */
 #ifndef GRAM_DEBUG
 # if defined YYDEBUG
@@ -334,7 +334,7 @@ extern int gram_debug;
 #if ! defined GRAM_STYPE && ! defined GRAM_STYPE_IS_DECLARED
 typedef union GRAM_STYPE
 {
-/* Line 376 of yacc.c  */
+/* Line 387 of yacc.c  */
 #line 115 "parse-gram.y"
 
   symbol *symbol;
@@ -348,7 +348,7 @@ typedef union GRAM_STYPE
   named_ref *named_ref;
 
 
-/* Line 376 of yacc.c  */
+/* Line 387 of yacc.c  */
 #line 353 "parse-gram.c"
 } GRAM_STYPE;
 # define GRAM_STYPE_IS_TRIVIAL 1
@@ -384,11 +384,11 @@ int gram_parse ();
 #endif
 #endif /* ! YYPARSE_PARAM */
 
-#endif /* !YY_GRAM_Y_TAB_H_INCLUDED  */
+#endif /* !YY_GRAM__SRC_PARSE_GRAM_H_INCLUDED  */
 
 /* Copy the second part of user declarations.  */
 
-/* Line 379 of yacc.c  */
+/* Line 390 of yacc.c  */
 #line 393 "parse-gram.c"
 
 #ifdef short
@@ -450,6 +450,14 @@ typedef short int yytype_int16;
 # endif
 #endif
 
+#ifndef __attribute__
+/* This feature is available in gcc versions 2.5 and later.  */
+# if (! defined __GNUC__ || __GNUC__ < 2 \
+      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
+#  define __attribute__(Spec) /* empty */
+# endif
+#endif
+
 /* Suppress unused-variable warnings by "using" E.  */
 #if ! defined lint || defined __GNUC__
 # define YYUSE(E) ((void) (E))
@@ -457,6 +465,7 @@ typedef short int yytype_int16;
 # define YYUSE(E) /* empty */
 #endif
 
+
 /* Identity function, used to suppress warnings about constant conditions.  */
 #ifndef lint
 # define YYID(N) (N)
@@ -1004,14 +1013,46 @@ while (YYID (0))
 
 #ifndef YY_LOCATION_PRINT
 # if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
-#  define YY_LOCATION_PRINT(File, Loc)                                   \
-  do {                                                                   \
-    fprintf (File, "%d.%d", (Loc).first_line, (Loc).first_column);       \
-    if ((Loc).first_line < (Loc).last_line)                              \
-      fprintf (File, "-%d.%d", (Loc).last_line,  (Loc).last_column - 1); \
-    else if ((Loc).first_column < (Loc).last_column - 1)                 \
-      fprintf (File, "-%d", (Loc).last_column - 1);                      \
-  } while (0)
+
+/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */
+
+__attribute__((__unused__))
+#if (defined __STDC__ || defined __C99__FUNC__ \
+     || defined __cplusplus || defined _MSC_VER)
+static unsigned
+yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
+#else
+static unsigned
+yy_location_print_ (yyo, yylocp)
+    FILE *yyo;
+    YYLTYPE const * const yylocp;
+#endif
+{
+  unsigned res = 0;
+  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
+  if (0 <= yylocp->first_line)
+    {
+      res += fprintf (yyo, "%d", yylocp->first_line);
+      if (0 <= yylocp->first_column)
+        res += fprintf (yyo, ".%d", yylocp->first_column);
+    }
+  if (0 <= yylocp->last_line)
+    {
+      if (yylocp->first_line < yylocp->last_line)
+        {
+          res += fprintf (yyo, "-%d", yylocp->last_line);
+          if (0 <= end_col)
+            res += fprintf (yyo, ".%d", end_col);
+        }
+      else if (0 <= end_col && yylocp->first_column < end_col)
+        res += fprintf (yyo, "-%d", end_col);
+    }
+  return res;
+ }
+
+#  define YY_LOCATION_PRINT(File, Loc)          \
+  yy_location_print_ (File, &(Loc))
+
 # else
 #  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
 # endif
@@ -1083,133 +1124,134 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
   switch (yytype)
     {
       case 3: /* "string" */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 205 "parse-gram.y"
-	{ fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
-/* Line 812 of yacc.c  */
-#line 1091 "parse-gram.c"
-	break;
+        { fputs (quotearg_style (c_quoting_style, ((*yyvaluep).chars)), stderr); };
+/* Line 818 of yacc.c  */
+#line 1132 "parse-gram.c"
+        break;
       case 4: /* "integer" */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 217 "parse-gram.y"
-	{ fprintf (stderr, "%d", ((*yyvaluep).integer)); };
-/* Line 812 of yacc.c  */
-#line 1098 "parse-gram.c"
-	break;
+        { fprintf (stderr, "%d", ((*yyvaluep).integer)); };
+/* Line 818 of yacc.c  */
+#line 1139 "parse-gram.c"
+        break;
       case 43: /* "{...}" */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 207 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
-/* Line 812 of yacc.c  */
-#line 1105 "parse-gram.c"
-	break;
+        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).code)); };
+/* Line 818 of yacc.c  */
+#line 1146 "parse-gram.c"
+        break;
       case 44: /* "[identifier]" */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 212 "parse-gram.y"
-	{ fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); };
-/* Line 812 of yacc.c  */
-#line 1112 "parse-gram.c"
-	break;
+        { fprintf (stderr, "[%s]", ((*yyvaluep).uniqstr)); };
+/* Line 818 of yacc.c  */
+#line 1153 "parse-gram.c"
+        break;
       case 45: /* "char" */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 199 "parse-gram.y"
-	{ fputs (char_name (((*yyvaluep).character)), stderr); };
-/* Line 812 of yacc.c  */
-#line 1119 "parse-gram.c"
-	break;
+        { fputs (char_name (((*yyvaluep).character)), stderr); };
+/* Line 818 of yacc.c  */
+#line 1160 "parse-gram.c"
+        break;
       case 46: /* "epilogue" */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 207 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 812 of yacc.c  */
-#line 1126 "parse-gram.c"
-	break;
+        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
+/* Line 818 of yacc.c  */
+#line 1167 "parse-gram.c"
+        break;
       case 48: /* "identifier" */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 211 "parse-gram.y"
-	{ fputs (((*yyvaluep).uniqstr), stderr); };
-/* Line 812 of yacc.c  */
-#line 1133 "parse-gram.c"
-	break;
+        { fputs (((*yyvaluep).uniqstr), stderr); };
+/* Line 818 of yacc.c  */
+#line 1174 "parse-gram.c"
+        break;
       case 49: /* "identifier:" */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 213 "parse-gram.y"
-	{ fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
-/* Line 812 of yacc.c  */
-#line 1140 "parse-gram.c"
-	break;
+        { fprintf (stderr, "%s:", ((*yyvaluep).uniqstr)); };
+/* Line 818 of yacc.c  */
+#line 1181 "parse-gram.c"
+        break;
       case 52: /* "%{...%}" */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 207 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 812 of yacc.c  */
-#line 1147 "parse-gram.c"
-	break;
+        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
+/* Line 818 of yacc.c  */
+#line 1188 "parse-gram.c"
+        break;
       case 54: /* "type" */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 214 "parse-gram.y"
-	{ fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
-/* Line 812 of yacc.c  */
-#line 1154 "parse-gram.c"
-	break;
+        { fprintf (stderr, "<%s>", ((*yyvaluep).uniqstr)); };
+/* Line 818 of yacc.c  */
+#line 1195 "parse-gram.c"
+        break;
       case 71: /* symbol.prec */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 220 "parse-gram.y"
-	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 812 of yacc.c  */
-#line 1161 "parse-gram.c"
-	break;
+        { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
+/* Line 818 of yacc.c  */
+#line 1202 "parse-gram.c"
+        break;
       case 84: /* variable */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 211 "parse-gram.y"
-	{ fputs (((*yyvaluep).uniqstr), stderr); };
-/* Line 812 of yacc.c  */
-#line 1168 "parse-gram.c"
-	break;
+        { fputs (((*yyvaluep).uniqstr), stderr); };
+/* Line 818 of yacc.c  */
+#line 1209 "parse-gram.c"
+        break;
       case 85: /* content.opt */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 207 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 812 of yacc.c  */
-#line 1175 "parse-gram.c"
-	break;
+        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
+/* Line 818 of yacc.c  */
+#line 1216 "parse-gram.c"
+        break;
       case 86: /* braceless */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 207 "parse-gram.y"
-	{ fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
-/* Line 812 of yacc.c  */
-#line 1182 "parse-gram.c"
-	break;
+        { fprintf (stderr, "{\n%s\n}", ((*yyvaluep).chars)); };
+/* Line 818 of yacc.c  */
+#line 1223 "parse-gram.c"
+        break;
       case 87: /* id */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 220 "parse-gram.y"
-	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 812 of yacc.c  */
-#line 1189 "parse-gram.c"
-	break;
+        { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
+/* Line 818 of yacc.c  */
+#line 1230 "parse-gram.c"
+        break;
       case 88: /* id_colon */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 221 "parse-gram.y"
-	{ fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
-/* Line 812 of yacc.c  */
-#line 1196 "parse-gram.c"
-	break;
+        { fprintf (stderr, "%s:", ((*yyvaluep).symbol)->tag); };
+/* Line 818 of yacc.c  */
+#line 1237 "parse-gram.c"
+        break;
       case 89: /* symbol */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 220 "parse-gram.y"
-	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 812 of yacc.c  */
-#line 1203 "parse-gram.c"
-	break;
+        { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
+/* Line 818 of yacc.c  */
+#line 1244 "parse-gram.c"
+        break;
       case 90: /* string_as_id */
-/* Line 812 of yacc.c  */
+/* Line 818 of yacc.c  */
 #line 220 "parse-gram.y"
-	{ fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
-/* Line 812 of yacc.c  */
-#line 1210 "parse-gram.c"
-	break;
+        { fprintf (stderr, "%s", ((*yyvaluep).symbol)->tag); };
+/* Line 818 of yacc.c  */
+#line 1251 "parse-gram.c"
+        break;
+
       default:
-	break;
+        break;
     }
 }
 
@@ -1691,7 +1733,6 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 {
   YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
   YYSIZE_T yysize = yysize0;
-  YYSIZE_T yysize1;
   enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
   /* Internationalized format string. */
   const char *yyformat = YY_NULL;
@@ -1752,11 +1793,13 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                     break;
                   }
                 yyarg[yycount++] = yytname[yyx];
-                yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
-                if (! (yysize <= yysize1
-                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
-                  return 2;
-                yysize = yysize1;
+                {
+                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
+                  if (! (yysize <= yysize1
+                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+                    return 2;
+                  yysize = yysize1;
+                }
               }
         }
 # if GRAM_DEBUG
@@ -1780,10 +1823,12 @@ yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
 # undef YYCASE_
     }
 
-  yysize1 = yysize + yystrlen (yyformat);
-  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
-    return 2;
-  yysize = yysize1;
+  {
+    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
+    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
+      return 2;
+    yysize = yysize1;
+  }
 
   if (*yymsg_alloc < yysize)
     {
@@ -1841,12 +1886,7 @@ yydestruct (yymsg, yytype, yyvaluep, yylocationp)
     yymsg = "Deleting";
   YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);
 
-  switch (yytype)
-    {
-
-      default:
-	break;
-    }
+  YYUSE (yytype);
 }
 
 
@@ -1896,6 +1936,11 @@ int yychar;
 static YYSTYPE yyval_default;
 # define YY_INITIAL_VALUE(Value) = Value
 #endif
+static YYLTYPE yyloc_default
+# if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
+  = { 1, 1, 1, 1 }
+# endif
+;
 #ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
 # define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
 # define YY_IGNORE_MAYBE_UNINITIALIZED_END
@@ -1908,11 +1953,7 @@ static YYSTYPE yyval_default;
 YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);
 
 /* Location data for the lookahead symbol.  */
-YYLTYPE yylloc
-# if defined GRAM_LTYPE_IS_TRIVIAL && GRAM_LTYPE_IS_TRIVIAL
-  = { 1, 1, 1, 1 }
-# endif
-;
+YYLTYPE yylloc = yyloc_default;
 
 
     /* Number of syntax errors so far.  */
@@ -1995,7 +2036,7 @@ YYLTYPE yylloc
   yychar = YYEMPTY; /* Cause a token to be read.  */
 
 /* User initialization code.  */
-/* Line 1560 of yacc.c  */
+/* Line 1570 of yacc.c  */
 #line 107 "parse-gram.y"
 {
   /* Bison's grammar can initial empty locations, hence a default
@@ -2003,8 +2044,8 @@ YYLTYPE yylloc
   boundary_set (&yylloc.start, current_file, 1, 1);
   boundary_set (&yylloc.end, current_file, 1, 1);
 }
-/* Line 1560 of yacc.c  */
-#line 2008 "parse-gram.c"
+/* Line 1570 of yacc.c  */
+#line 2049 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2198,7 +2239,7 @@ yyreduce:
     switch (yyn)
       {
           case 6:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 246 "parse-gram.y"
     {
       code_props plain_code;
@@ -2212,13 +2253,13 @@ yyreduce:
     break;
 
   case 7:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 255 "parse-gram.y"
     { debug = true; }
     break;
 
   case 8:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 257 "parse-gram.y"
     {
       muscle_percent_define_insert ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars),
@@ -2227,13 +2268,13 @@ yyreduce:
     break;
 
   case 9:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 261 "parse-gram.y"
     { defines_flag = true; }
     break;
 
   case 10:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 263 "parse-gram.y"
     {
       defines_flag = true;
@@ -2242,37 +2283,37 @@ yyreduce:
     break;
 
   case 11:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 267 "parse-gram.y"
     { error_verbose = true; }
     break;
 
   case 12:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 268 "parse-gram.y"
     { expected_sr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 13:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 269 "parse-gram.y"
     { expected_rr_conflicts = (yyvsp[(2) - (2)].integer); }
     break;
 
   case 14:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 270 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 15:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 271 "parse-gram.y"
     { spec_file_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 16:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 273 "parse-gram.y"
     {
       nondeterministic_parser = true;
@@ -2281,7 +2322,7 @@ yyreduce:
     break;
 
   case 17:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 278 "parse-gram.y"
     {
       code_props action;
@@ -2294,67 +2335,67 @@ yyreduce:
     break;
 
   case 18:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 286 "parse-gram.y"
     { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
     break;
 
   case 19:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 287 "parse-gram.y"
     { add_param ("lex_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 20:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 288 "parse-gram.y"
     { locations_flag = true; }
     break;
 
   case 21:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 289 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 22:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 290 "parse-gram.y"
     { spec_name_prefix = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 23:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 291 "parse-gram.y"
     { no_lines_flag = true; }
     break;
 
   case 24:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 292 "parse-gram.y"
     { nondeterministic_parser = true; }
     break;
 
   case 25:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 293 "parse-gram.y"
     { spec_outfile = (yyvsp[(2) - (2)].chars); }
     break;
 
   case 26:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 294 "parse-gram.y"
     { spec_outfile = (yyvsp[(3) - (3)].chars); }
     break;
 
   case 27:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 295 "parse-gram.y"
     { add_param ("parse_param", (yyvsp[(2) - (2)].code), (yylsp[(2) - (2)])); }
     break;
 
   case 28:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 297 "parse-gram.y"
     {
       /* %pure-parser is deprecated in favor of `%define api.pure', so use
@@ -2373,13 +2414,13 @@ yyreduce:
     break;
 
   case 29:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 311 "parse-gram.y"
     { version_check (&(yylsp[(2) - (2)]), (yyvsp[(2) - (2)].chars)); }
     break;
 
   case 30:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 313 "parse-gram.y"
     {
       char const *skeleton_user = (yyvsp[(2) - (2)].chars);
@@ -2407,25 +2448,25 @@ yyreduce:
     break;
 
   case 31:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 336 "parse-gram.y"
     { token_table_flag = true; }
     break;
 
   case 32:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 337 "parse-gram.y"
     { report_flag |= report_states; }
     break;
 
   case 33:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 338 "parse-gram.y"
     { yacc_flag = true; }
     break;
 
   case 37:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 346 "parse-gram.y"
     {
       grammar_start_symbol_set ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]));
@@ -2433,7 +2474,7 @@ yyreduce:
     break;
 
   case 38:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 350 "parse-gram.y"
     {
       code_props code;
@@ -2449,7 +2490,7 @@ yyreduce:
     break;
 
   case 39:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 362 "parse-gram.y"
     {
       code_props code;
@@ -2465,7 +2506,7 @@ yyreduce:
     break;
 
   case 40:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 374 "parse-gram.y"
     {
       default_prec = true;
@@ -2473,7 +2514,7 @@ yyreduce:
     break;
 
   case 41:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 378 "parse-gram.y"
     {
       default_prec = false;
@@ -2481,7 +2522,7 @@ yyreduce:
     break;
 
   case 42:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 382 "parse-gram.y"
     {
       /* Do not invoke muscle_percent_code_grow here since it invokes
@@ -2492,7 +2533,7 @@ yyreduce:
     break;
 
   case 43:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 389 "parse-gram.y"
     {
       muscle_percent_code_grow ((yyvsp[(2) - (3)].uniqstr), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].chars), (yylsp[(3) - (3)]));
@@ -2501,19 +2542,19 @@ yyreduce:
     break;
 
   case 44:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 403 "parse-gram.y"
     {}
     break;
 
   case 45:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 404 "parse-gram.y"
     { muscle_code_grow ("union_name", (yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 46:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 409 "parse-gram.y"
     {
       union_seen = true;
@@ -2523,13 +2564,13 @@ yyreduce:
     break;
 
   case 47:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 420 "parse-gram.y"
     { current_class = nterm_sym; }
     break;
 
   case 48:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 421 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2538,13 +2579,13 @@ yyreduce:
     break;
 
   case 49:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 425 "parse-gram.y"
     { current_class = token_sym; }
     break;
 
   case 50:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 426 "parse-gram.y"
     {
       current_class = unknown_sym;
@@ -2553,7 +2594,7 @@ yyreduce:
     break;
 
   case 51:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 431 "parse-gram.y"
     {
       symbol_list *list;
@@ -2565,7 +2606,7 @@ yyreduce:
     break;
 
   case 52:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 442 "parse-gram.y"
     {
       symbol_list *list;
@@ -2581,109 +2622,109 @@ yyreduce:
     break;
 
   case 53:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 456 "parse-gram.y"
     { (yyval.assoc) = left_assoc; }
     break;
 
   case 54:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 457 "parse-gram.y"
     { (yyval.assoc) = right_assoc; }
     break;
 
   case 55:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 458 "parse-gram.y"
     { (yyval.assoc) = non_assoc; }
     break;
 
   case 56:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 462 "parse-gram.y"
     { current_type = NULL; }
     break;
 
   case 57:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 463 "parse-gram.y"
     { current_type = (yyvsp[(1) - (1)].uniqstr); tag_seen = true; }
     break;
 
   case 58:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 469 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 59:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 471 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 60:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 475 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (1)].symbol); }
     break;
 
   case 61:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 476 "parse-gram.y"
     { (yyval.symbol) = (yyvsp[(1) - (2)].symbol); symbol_user_token_number_set ((yyvsp[(1) - (2)].symbol), (yyvsp[(2) - (2)].integer), (yylsp[(2) - (2)])); }
     break;
 
   case 62:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 482 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 63:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 484 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), symbol_list_sym_new ((yyvsp[(2) - (2)].symbol), (yylsp[(2) - (2)]))); }
     break;
 
   case 64:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 488 "parse-gram.y"
     { (yyval.list) = (yyvsp[(1) - (1)].list); }
     break;
 
   case 65:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 489 "parse-gram.y"
     { (yyval.list) = symbol_list_prepend ((yyvsp[(1) - (2)].list), (yyvsp[(2) - (2)].list)); }
     break;
 
   case 66:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 493 "parse-gram.y"
     { (yyval.list) = symbol_list_sym_new ((yyvsp[(1) - (1)].symbol), (yylsp[(1) - (1)])); }
     break;
 
   case 67:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 494 "parse-gram.y"
     { (yyval.list) = symbol_list_type_new ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 68:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 495 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagged_new ((yylsp[(1) - (1)])); }
     break;
 
   case 69:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 496 "parse-gram.y"
     { (yyval.list) = symbol_list_default_tagless_new ((yylsp[(1) - (1)])); }
     break;
 
   case 70:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 502 "parse-gram.y"
     {
        current_type = (yyvsp[(1) - (1)].uniqstr);
@@ -2692,7 +2733,7 @@ yyreduce:
     break;
 
   case 71:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 507 "parse-gram.y"
     {
        symbol_class_set ((yyvsp[(1) - (1)].symbol), current_class, (yylsp[(1) - (1)]), true);
@@ -2701,7 +2742,7 @@ yyreduce:
     break;
 
   case 72:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 512 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2711,7 +2752,7 @@ yyreduce:
     break;
 
   case 73:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 518 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (2)].symbol), current_class, (yylsp[(1) - (2)]), true);
@@ -2721,7 +2762,7 @@ yyreduce:
     break;
 
   case 74:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 524 "parse-gram.y"
     {
       symbol_class_set ((yyvsp[(1) - (3)].symbol), current_class, (yylsp[(1) - (3)]), true);
@@ -2732,7 +2773,7 @@ yyreduce:
     break;
 
   case 81:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 554 "parse-gram.y"
     {
       yyerrok;
@@ -2740,13 +2781,13 @@ yyreduce:
     break;
 
   case 82:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 560 "parse-gram.y"
     { current_lhs ((yyvsp[(1) - (2)].symbol), (yylsp[(1) - (2)]), (yyvsp[(2) - (2)].named_ref)); }
     break;
 
   case 83:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 561 "parse-gram.y"
     {
     /* Free the current lhs. */
@@ -2755,86 +2796,86 @@ yyreduce:
     break;
 
   case 84:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 568 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(1) - (1)])); }
     break;
 
   case 85:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 569 "parse-gram.y"
     { grammar_current_rule_end ((yylsp[(3) - (3)])); }
     break;
 
   case 87:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 575 "parse-gram.y"
     { grammar_current_rule_begin (current_lhs_symbol, current_lhs_location,
 				  current_lhs_named_ref); }
     break;
 
   case 88:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 578 "parse-gram.y"
     { grammar_current_rule_symbol_append ((yyvsp[(2) - (3)].symbol), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 89:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 580 "parse-gram.y"
     { grammar_current_rule_action_append ((yyvsp[(2) - (3)].code), (yylsp[(2) - (3)]), (yyvsp[(3) - (3)].named_ref)); }
     break;
 
   case 90:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 582 "parse-gram.y"
     { grammar_current_rule_prec_set ((yyvsp[(3) - (3)].symbol), (yylsp[(3) - (3)])); }
     break;
 
   case 91:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 584 "parse-gram.y"
     { grammar_current_rule_dprec_set ((yyvsp[(3) - (3)].integer), (yylsp[(3) - (3)])); }
     break;
 
   case 92:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 586 "parse-gram.y"
     { grammar_current_rule_merge_set ((yyvsp[(3) - (3)].uniqstr), (yylsp[(3) - (3)])); }
     break;
 
   case 93:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 590 "parse-gram.y"
     { (yyval.named_ref) = 0; }
     break;
 
   case 94:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 592 "parse-gram.y"
     { (yyval.named_ref) = named_ref_new((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 96:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 604 "parse-gram.y"
     { (yyval.uniqstr) = uniqstr_new ((yyvsp[(1) - (1)].chars)); }
     break;
 
   case 97:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 609 "parse-gram.y"
     { (yyval.chars) = ""; }
     break;
 
   case 98:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 610 "parse-gram.y"
     { (yyval.chars) = (yyvsp[(1) - (1)].uniqstr); }
     break;
 
   case 100:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 621 "parse-gram.y"
     {
       code_props plain_code;
@@ -2847,13 +2888,13 @@ yyreduce:
     break;
 
   case 101:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 641 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 102:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 643 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (char_name ((yyvsp[(1) - (1)].character)), (yylsp[(1) - (1)]));
@@ -2863,13 +2904,13 @@ yyreduce:
     break;
 
   case 103:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 651 "parse-gram.y"
     { (yyval.symbol) = symbol_from_uniqstr ((yyvsp[(1) - (1)].uniqstr), (yylsp[(1) - (1)])); }
     break;
 
   case 106:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 663 "parse-gram.y"
     {
       (yyval.symbol) = symbol_get (quotearg_style (c_quoting_style, (yyvsp[(1) - (1)].chars)), (yylsp[(1) - (1)]));
@@ -2878,7 +2919,7 @@ yyreduce:
     break;
 
   case 108:
-/* Line 1778 of yacc.c  */
+/* Line 1787 of yacc.c  */
 #line 672 "parse-gram.y"
     {
       code_props plain_code;
@@ -2891,8 +2932,8 @@ yyreduce:
     break;
 
 
-/* Line 1778 of yacc.c  */
-#line 2896 "parse-gram.c"
+/* Line 1787 of yacc.c  */
+#line 2937 "parse-gram.c"
         default: break;
       }
     if (yychar_backup != yychar)
@@ -3142,7 +3183,7 @@ yyreturn:
 }
 
 
-/* Line 2041 of yacc.c  */
+/* Line 2050 of yacc.c  */
 #line 682 "parse-gram.y"
 
 
