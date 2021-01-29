@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.4.1.120-890ab.  */
+/* A Bison parser, made by GNU Bison 2.4.1.122-1fa3-dirty.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -45,7 +45,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.4.1.120-890ab"
+#define YYBISON_VERSION "2.4.1.122-1fa3-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -823,8 +823,7 @@ static const yytype_int16 yypgoto[] =
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
-   number is the opposite.  If zero, do what YYDEFACT says.
-   If YYTABLE_NINF, syntax error.  */
+   number is the opposite.  If zero or YYTABLE_NINF, syntax error.  */
 #define YYTABLE_NINF -107
 static const yytype_int16 yytable[] =
 {
@@ -846,11 +845,12 @@ static const yytype_int16 yytable[] =
       44,    39,   129,    40,    41,    95,   104,   114,   141,    42
 };
 
-#define yyis_pact_ninf(yystate) \
+#define yypact_value_is_default(yystate) \
   ((yystate) == (-60))
 
-#define yyis_table_ninf(yytable_value) \
-  YYID (0)
+#define yytable_value_is_error(yytable_value) \
+  (YYID (0) \
+  || ((yytable_value) == (0)))
 
 static const yytype_uint8 yycheck[] =
 {
@@ -1476,7 +1476,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
-	    && !yyis_table_ninf (yytable[yyx + yyn]))
+	    && !yytable_value_is_error (yytable[yyx + yyn]))
 	  {
 	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 	      {
@@ -1810,7 +1810,7 @@ yybackup:
 
   /* First try to decide what to do without reference to lookahead token.  */
   yyn = yypact[yystate];
-  if (yyis_pact_ninf (yyn))
+  if (yypact_value_is_default (yyn))
     goto yydefault;
 
   /* Not known => get a lookahead token if don't already have one.  */
@@ -1841,7 +1841,7 @@ yybackup:
   yyn = yytable[yyn];
   if (yyn <= 0)
     {
-      if (yyn == 0 || yyis_table_ninf (yyn))
+      if (yytable_value_is_error (yyn))
 	goto yyerrlab;
       yyn = -yyn;
       goto yyreduce;
@@ -2782,7 +2782,7 @@ yyerrlab1:
   for (;;)
     {
       yyn = yypact[yystate];
-      if (!yyis_pact_ninf (yyn))
+      if (!yypact_value_is_default (yyn))
 	{
 	  yyn += YYTERROR;
 	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
