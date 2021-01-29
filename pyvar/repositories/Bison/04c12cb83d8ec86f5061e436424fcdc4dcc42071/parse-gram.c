@@ -1,7 +1,9 @@
 /* A Bison parser, made by GNU Bison 2.1b.  */
 
-/* Skeleton parser for Yacc-like parsing with Bison,
-   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006 Free Software Foundation, Inc.
+/* Skeleton implementation for Bison's Yacc-like parsers in C
+
+   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
+   Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -18,10 +20,18 @@
    Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.  */
 
-/* As a special exception, when this file is copied by Bison into a
-   Bison output file, you may use that output file without restriction.
-   This special exception was added by the Free Software Foundation
-   in version 1.24 of Bison.  */
+/* As a special exception, you may create a larger work that contains
+   part or all of the Bison parser skeleton and distribute that work
+   under terms of your choice, so long as that work isn't itself a
+   parser generator using the skeleton or a modified version thereof
+   as a parser skeleton.  Alternatively, if you modify or redistribute
+   the parser skeleton itself, you may (at your option) remove this
+   special exception, which will cause the skeleton and the resulting
+   Bison output files to be licensed under the GNU General Public
+   License without this special exception.
+
+   This special exception was added by the Free Software Foundation in
+   version 2.2 of Bison.  */
 
 /* C LALR(1) parser skeleton written by Richard Stallman, by
    simplifying the original so-called "semantic" parser.  */
@@ -276,8 +286,8 @@ typedef union YYSTYPE
   assoc assoc;
   uniqstr uniqstr;
 }
-/* Line 198 of yacc.c.  */
-#line 281 "parse-gram.c"
+/* Line 193 of yacc.c.  */
+#line 291 "parse-gram.c"
 	YYSTYPE;
 # define yystype YYSTYPE /* obsolescent; will be withdrawn */
 # define YYSTYPE_IS_DECLARED 1
@@ -301,8 +311,8 @@ typedef struct YYLTYPE
 /* Copy the second part of user declarations.  */
 
 
-/* Line 221 of yacc.c.  */
-#line 306 "parse-gram.c"
+/* Line 216 of yacc.c.  */
+#line 316 "parse-gram.c"
 
 #ifdef short
 # undef short
@@ -966,82 +976,82 @@ yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
       case 3: /* "\"string\"" */
 #line 180 "parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 970 "parse-gram.c"
+#line 980 "parse-gram.c"
 	break;
       case 4: /* "\"integer\"" */
 #line 193 "parse-gram.y"
 	{ fprintf (stderr, "%d", (yyvaluep->integer)); };
-#line 975 "parse-gram.c"
+#line 985 "parse-gram.c"
 	break;
       case 8: /* "\"%destructor {...}\"" */
 #line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 980 "parse-gram.c"
+#line 990 "parse-gram.c"
 	break;
       case 9: /* "\"%printer {...}\"" */
 #line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 985 "parse-gram.c"
+#line 995 "parse-gram.c"
 	break;
       case 10: /* "\"%union {...}\"" */
 #line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 990 "parse-gram.c"
+#line 1000 "parse-gram.c"
 	break;
       case 26: /* "\"%initial-action {...}\"" */
 #line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 995 "parse-gram.c"
+#line 1005 "parse-gram.c"
 	break;
       case 27: /* "\"%lex-param {...}\"" */
 #line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1000 "parse-gram.c"
+#line 1010 "parse-gram.c"
 	break;
       case 34: /* "\"%parse-param {...}\"" */
 #line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1005 "parse-gram.c"
+#line 1015 "parse-gram.c"
 	break;
       case 42: /* "\"type\"" */
 #line 191 "parse-gram.y"
 	{ fprintf (stderr, "<%s>", (yyvaluep->uniqstr)); };
-#line 1010 "parse-gram.c"
+#line 1020 "parse-gram.c"
 	break;
       case 46: /* "\"identifier\"" */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1015 "parse-gram.c"
+#line 1025 "parse-gram.c"
 	break;
       case 47: /* "\"identifier:\"" */
 #line 197 "parse-gram.y"
 	{ fprintf (stderr, "%s:", (yyvaluep->symbol)->tag); };
-#line 1020 "parse-gram.c"
+#line 1030 "parse-gram.c"
 	break;
       case 49: /* "\"%{...%}\"" */
 #line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1025 "parse-gram.c"
+#line 1035 "parse-gram.c"
 	break;
       case 50: /* "\"epilogue\"" */
 #line 182 "parse-gram.y"
 	{ fprintf (stderr, "{\n%s\n}", (yyvaluep->chars)); };
-#line 1030 "parse-gram.c"
+#line 1040 "parse-gram.c"
 	break;
       case 72: /* "symbol" */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1035 "parse-gram.c"
+#line 1045 "parse-gram.c"
 	break;
       case 75: /* "string_as_id" */
 #line 195 "parse-gram.y"
 	{ fprintf (stderr, "%s", (yyvaluep->symbol)->tag); };
-#line 1040 "parse-gram.c"
+#line 1050 "parse-gram.c"
 	break;
       case 76: /* "string_content" */
 #line 180 "parse-gram.y"
 	{ fprintf (stderr, "\"%s\"", (yyvaluep->chars)); };
-#line 1045 "parse-gram.c"
+#line 1055 "parse-gram.c"
 	break;
       default:
 	break;
@@ -1560,8 +1570,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 1083 of yacc.c.  */
-#line 1565 "parse-gram.c"
+/* Line 1078 of yacc.c.  */
+#line 1575 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2146,8 +2156,8 @@ yyreduce:
     break;
 
 
-/* Line 1272 of yacc.c.  */
-#line 2151 "parse-gram.c"
+/* Line 1267 of yacc.c.  */
+#line 2161 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
