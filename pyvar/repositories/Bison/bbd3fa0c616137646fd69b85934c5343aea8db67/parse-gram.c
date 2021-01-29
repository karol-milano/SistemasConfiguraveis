@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 1.875e.  */
+/* A Bison parser, made by GNU Bison 1.875f.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
@@ -734,22 +734,25 @@ while (0)
    If N is 0, then set CURRENT to the empty location which ends
    the previous symbol: RHS[0] (always defined).  */
 
+#define YYRHSLOC(Rhs, K) ((Rhs)[K])
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(Current, Rhs, N)				     \
-do {									     \
-  if (N)								     \
-    {									     \
-      (Current).first_line   = (Rhs)[1].first_line;			     \
-      (Current).first_column = (Rhs)[1].first_column;			     \
-      (Current).last_line    = (Rhs)[N].last_line;			     \
-      (Current).last_column  = (Rhs)[N].last_column;			     \
-    }									     \
-  else									     \
-    {									     \
-      (Current).first_line   = (Current).last_line   = (Rhs)[0].last_line;   \
-      (Current).first_column = (Current).last_column = (Rhs)[0].last_column; \
-    }									     \
-} while(0)
+# define YYLLOC_DEFAULT(Current, Rhs, N)				\
+    do									\
+      if (N)								\
+	{								\
+	  (Current).first_line   = YYRHSLOC(Rhs, 1).first_line;		\
+	  (Current).first_column = YYRHSLOC(Rhs, 1).first_column;	\
+	  (Current).last_line    = YYRHSLOC(Rhs, N).last_line;		\
+	  (Current).last_column  = YYRHSLOC(Rhs, N).last_column;	\
+	}								\
+      else								\
+	{								\
+	  (Current).first_line   = (Current).last_line   =		\
+	    YYRHSLOC(Rhs, 0).last_line;					\
+	  (Current).first_column = (Current).last_column =		\
+	    YYRHSLOC(Rhs, 0).last_column;				\
+	}								\
+    while (0)
 #endif
 
 
@@ -1153,8 +1156,8 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 848 of yacc.c.  */
-#line 1158 "parse-gram.c"
+/* Line 851 of yacc.c.  */
+#line 1161 "parse-gram.c"
   yyvsp[0] = yylval;
     yylsp[0] = yylloc;
 
@@ -1740,8 +1743,8 @@ yyreduce:
 
     }
 
-/* Line 1043 of yacc.c.  */
-#line 1745 "parse-gram.c"
+/* Line 1046 of yacc.c.  */
+#line 1748 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
