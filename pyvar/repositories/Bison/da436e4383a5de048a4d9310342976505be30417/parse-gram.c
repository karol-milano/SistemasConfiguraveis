@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 1.875f.  */
+/* A Bison parser, made by GNU Bison 2.0.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
@@ -291,14 +291,10 @@ typedef struct YYLTYPE
 
 # ifdef YYSTACK_USE_ALLOCA
 #  if YYSTACK_USE_ALLOCA
-#   define YYSTACK_ALLOC alloca
-#  endif
-# else
-#  if defined (alloca) || defined (_ALLOCA_H)
-#   define YYSTACK_ALLOC alloca
-#  else
 #   ifdef __GNUC__
 #    define YYSTACK_ALLOC __builtin_alloca
+#   else
+#    define YYSTACK_ALLOC alloca
 #   endif
 #  endif
 # endif
@@ -739,17 +735,17 @@ while (0)
     do									\
       if (N)								\
 	{								\
-	  (Current).first_line   = YYRHSLOC(Rhs, 1).first_line;		\
-	  (Current).first_column = YYRHSLOC(Rhs, 1).first_column;	\
-	  (Current).last_line    = YYRHSLOC(Rhs, N).last_line;		\
-	  (Current).last_column  = YYRHSLOC(Rhs, N).last_column;	\
+	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
+	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
+	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
+	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
 	}								\
       else								\
 	{								\
 	  (Current).first_line   = (Current).last_line   =		\
-	    YYRHSLOC(Rhs, 0).last_line;					\
+	    YYRHSLOC (Rhs, 0).last_line;				\
 	  (Current).first_column = (Current).last_column =		\
-	    YYRHSLOC(Rhs, 0).last_column;				\
+	    YYRHSLOC (Rhs, 0).last_column;				\
 	}								\
     while (0)
 #endif
@@ -884,10 +880,6 @@ int yydebug;
    SIZE_MAX < YYSTACK_BYTES (YYMAXDEPTH)
    evaluated with infinite-precision integer arithmetic.  */
 
-#if defined (YYMAXDEPTH) && YYMAXDEPTH == 0
-# undef YYMAXDEPTH
-#endif
-
 #ifndef YYMAXDEPTH
 # define YYMAXDEPTH 10000
 #endif
@@ -1155,8 +1147,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 850 of yacc.c.  */
-#line 1160 "parse-gram.c"
+/* Line 842 of yacc.c.  */
+#line 1152 "parse-gram.c"
   yyvsp[0] = yylval;
     yylsp[0] = yylloc;
 
@@ -1742,8 +1734,8 @@ yyreduce:
 
     }
 
-/* Line 1045 of yacc.c.  */
-#line 1747 "parse-gram.c"
+/* Line 1037 of yacc.c.  */
+#line 1739 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
