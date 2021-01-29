@@ -578,19 +578,19 @@ static const ]b4_int_type_for([b4_pgoto])[ yypgoto[] =
 
 /* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
    positive, shift that token.  If negative, reduce the rule which
-   number is the opposite.  If zero, do what YYDEFACT says.
-   If YYTABLE_NINF, syntax error.  */
+   number is the opposite.  If zero or YYTABLE_NINF, syntax error.  */
 #define YYTABLE_NINF ]b4_table_ninf[
 static const ]b4_int_type_for([b4_table])[ yytable[] =
 {
   ]b4_table[
 };
 
-#define yyis_pact_ninf(yystate) \
+#define yypact_value_is_default(yystate) \
   ]b4_table_value_equals([[pact]], [[yystate]], [b4_pact_ninf])[
 
-#define yyis_table_ninf(yytable_value) \
-  ]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[
+#define yytable_value_is_error(yytable_value) \
+  (]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[ \
+  || ]b4_table_value_equals([[table]], [[yytable_value]], [[0]])[)
 
 static const ]b4_int_type_for([b4_check])[ yycheck[] =
 {
@@ -954,7 +954,7 @@ yysyntax_error (char *yyresult, int yystate, int yychar)
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
-	    && !yyis_table_ninf (yytable[yyx + yyn]))
+	    && !yytable_value_is_error (yytable[yyx + yyn]))
 	  {
 	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 	      {
@@ -1355,7 +1355,7 @@ yybackup:
 
   /* First try to decide what to do without reference to lookahead token.  */
   yyn = yypact[yystate];
-  if (yyis_pact_ninf (yyn))
+  if (yypact_value_is_default (yyn))
     goto yydefault;
 
   /* Not known => get a lookahead token if don't already have one.  */
@@ -1405,7 +1405,7 @@ yyread_pushed_token:]])[
   yyn = yytable[yyn];
   if (yyn <= 0)
     {
-      if (yyn == 0 || yyis_table_ninf (yyn))
+      if (yytable_value_is_error (yyn))
 	goto yyerrlab;
       yyn = -yyn;
       goto yyreduce;
@@ -1589,7 +1589,7 @@ yyerrlab1:
   for (;;)
     {
       yyn = yypact[yystate];
-      if (!yyis_pact_ninf (yyn))
+      if (!yypact_value_is_default (yyn))
 	{
 	  yyn += YYTERROR;
 	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
