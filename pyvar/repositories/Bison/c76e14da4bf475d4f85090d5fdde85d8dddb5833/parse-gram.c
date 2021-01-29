@@ -1,9 +1,7 @@
-/* A Bison parser, made from parse-gram.y
-   by GNU bison 1.49b.  */
+/* A Bison parser, made from parse-gram.y, by GNU bison 1.49b.  */
 
-/* Skeleton output parser for Bison,
-   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software
-   Foundation, Inc.
+/* Skeleton parser for Yacc-like parsing with Bison,
+   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -25,10 +23,8 @@
    This special exception was added by the Free Software Foundation
    in version 1.24 of Bison.  */
 
-/* This is the parser code that is written into each bison parser when
-   the %semantic_parser declaration is not specified in the grammar.
-   It was written by Richard Stallman by simplifying the original so
-   called ``semantic'' parser.  */
+/* Written by Richard Stallman by simplifying the original so called
+   ``semantic'' parser.  */
 
 /* All symbols defined below should begin with yy or YY, to avoid
    infringing on user name space.  This should be done even for local
@@ -236,8 +232,8 @@ typedef union {
   char *string;
   associativity assoc;
 } yystype;
-/* Line 272 of /usr/local/share/bison/yacc.c.  */
-#line 241 "parse-gram.c"
+/* Line 187 of /home/lrde/prof/akim/src/bison/data/yacc.c.  */
+#line 237 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
 #endif
@@ -257,8 +253,8 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 292 of /usr/local/share/bison/yacc.c.  */
-#line 262 "parse-gram.c"
+/* Line 207 of /home/lrde/prof/akim/src/bison/data/yacc.c.  */
+#line 258 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
 
@@ -1520,8 +1516,8 @@ yyreduce:
 
     }
 
-/* Line 1040 of /usr/local/share/bison/yacc.c.  */
-#line 1525 "parse-gram.c"
+/* Line 955 of /home/lrde/prof/akim/src/bison/data/yacc.c.  */
+#line 1521 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
