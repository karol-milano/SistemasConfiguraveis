@@ -525,13 +525,14 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 
 #define YYPACT_NINF ]b4_pact_ninf[
 
-#define yyis_pact_ninf(yystate) \
+#define yypact_value_is_default(yystate) \
   ]b4_table_value_equals([[pact]], [[yystate]], [b4_pact_ninf])[
 
 #define YYTABLE_NINF ]b4_table_ninf[
 
-#define yyis_table_ninf(yytable_value) \
-  ]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[
+#define yytable_value_is_error(yytable_value) \
+  (]b4_table_value_equals([[table]], [[yytable_value]], [b4_table_ninf])[ \
+  || ]b4_table_value_equals([[table]], [[yytable_value]], [[0]])[)
 
 ]b4_parser_tables_define[
 
@@ -870,7 +871,7 @@ yysyntax_error (char *yyresult, int yystate, int yytoken)
 
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
 	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
-	    && !yyis_table_ninf (yytable[yyx + yyn]))
+	    && !yytable_value_is_error (yytable[yyx + yyn]))
 	  {
 	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
 	      {
@@ -1279,7 +1280,7 @@ yybackup:
 
   /* First try to decide what to do without reference to lookahead token.  */
   yyn = yypact[yystate];
-  if (yyis_pact_ninf (yyn))
+  if (yypact_value_is_default (yyn))
     goto yydefault;
 
   /* Not known => get a lookahead token if don't already have one.  */
@@ -1329,7 +1330,7 @@ yyread_pushed_token:]])[
   yyn = yytable[yyn];
   if (yyn <= 0)
     {
-      if (yyn == 0 || yyis_table_ninf (yyn))
+      if (yytable_value_is_error (yyn))
 	goto yyerrlab;
       yyn = -yyn;
       goto yyreduce;
@@ -1513,7 +1514,7 @@ yyerrlab1:
   for (;;)
     {
       yyn = yypact[yystate];
-      if (!yyis_pact_ninf (yyn))
+      if (!yypact_value_is_default (yyn))
 	{
 	  yyn += YYTERROR;
 	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
