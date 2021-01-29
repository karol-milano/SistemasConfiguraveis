@@ -236,7 +236,7 @@ typedef union {
   char *string;
   associativity assoc;
 } yystype;
-/* Line 272 of /home/cs/hilfingr/work/grammars/glr2/install/share/bison/yacc.c.  */
+/* Line 272 of /home/lrde/prof/akim/src/bison/data/yacc.c.  */
 #line 241 "parse-gram.c"
 # define YYSTYPE yystype
 # define YYSTYPE_IS_TRIVIAL 1
@@ -257,7 +257,7 @@ typedef struct yyltype
 /* Copy the second part of user declarations.  */
 
 
-/* Line 292 of /home/cs/hilfingr/work/grammars/glr2/install/share/bison/yacc.c.  */
+/* Line 292 of /home/lrde/prof/akim/src/bison/data/yacc.c.  */
 #line 262 "parse-gram.c"
 
 #if ! defined (yyoverflow) || YYERROR_VERBOSE
@@ -1520,7 +1520,7 @@ yyreduce:
 
     }
 
-/* Line 1040 of /home/cs/hilfingr/work/grammars/glr2/install/share/bison/yacc.c.  */
+/* Line 1040 of /home/lrde/prof/akim/src/bison/data/yacc.c.  */
 #line 1525 "parse-gram.c"
 
   yyvsp -= yylen;
@@ -1748,6 +1748,10 @@ static void
 yydestruct (int yytype,
 	    YYSTYPE yyvalue, YYLTYPE yylocation)
 {
+  /* Pacify ``unused variable'' warnings.  */
+  (void) yyvalue;
+  (void) yylocation;
+
   switch (yytype)
     {
       default:
@@ -1765,6 +1769,10 @@ static void
 yysymprint (FILE* yyout, int yytype,
 	    YYSTYPE yyvalue, YYLTYPE yylocation)
 {
+  /* Pacify ``unused variable'' warnings.  */
+  (void) yyvalue;
+  (void) yylocation;
+
   if (yytype < YYNTOKENS)
     {
       YYFPRINTF (yyout, "token %s (", yytname[yytype]);
