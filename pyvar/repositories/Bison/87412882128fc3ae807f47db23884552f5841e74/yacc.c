@@ -525,8 +525,14 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 
 #define YYPACT_NINF ]b4_pact_ninf[
 
+#define yyis_pact_ninf(yystate) \
+  ]b4_table_value_equals([[pact]], [[yystate]], [b4_pact_ninf])[
+
 #define YYTABLE_NINF ]b4_table_ninf[
 
+#define yyis_table_ninf(yytable_value) \
+  ]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[
+
 ]b4_parser_tables_define[
 
 #define yyerrok		(yyerrstatus = 0)
@@ -848,7 +854,8 @@ yysyntax_error (char *yyresult, int yystate, int yytoken)
       char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
 
       /* Start YYX at -YYN if negative to avoid negative indexes in
-	 YYCHECK.  */
+	 YYCHECK.  In other words, skip the first -YYN actions for this
+	 state because they are default actions.  */
       int yyxbegin = yyn < 0 ? -yyn : 0;
 
       /* Stay within bounds of both yycheck and yytname.  */
@@ -1271,7 +1278,7 @@ yybackup:
 
   /* First try to decide what to do without reference to lookahead token.  */
   yyn = yypact[yystate];
-  if (yyn == YYPACT_NINF)
+  if (yyis_pact_ninf (yyn))
     goto yydefault;
 
   /* Not known => get a lookahead token if don't already have one.  */
@@ -1321,7 +1328,7 @@ yyread_pushed_token:]])[
   yyn = yytable[yyn];
   if (yyn <= 0)
     {
-      if (yyn == 0 || yyn == YYTABLE_NINF)
+      if (yyn == 0 || yyis_table_ninf (yyn))
 	goto yyerrlab;
       yyn = -yyn;
       goto yyreduce;
@@ -1505,7 +1512,7 @@ yyerrlab1:
   for (;;)
     {
       yyn = yypact[yystate];
-      if (yyn != YYPACT_NINF)
+      if (!yyis_pact_ninf (yyn))
 	{
 	  yyn += YYTERROR;
 	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
