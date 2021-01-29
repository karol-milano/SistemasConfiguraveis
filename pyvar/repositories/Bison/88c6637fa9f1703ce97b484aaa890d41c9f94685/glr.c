@@ -889,9 +889,9 @@ b4_syncline([@oline@], [@ofile@])
 static void
 yyuserMerge (int yyn, YYSTYPE* yy0, YYSTYPE* yy1)
 {
-  /* `Use' the arguments.  */
-  (void) yy0;
-  (void) yy1;
+  /* Suppress unused-variable warnings.  */
+  yy0 = yy0;
+  yy1 = yy1;
 
   switch (yyn)
     {
@@ -1633,9 +1633,9 @@ static void
 yyreportAmbiguity (yySemanticOption* yyx0, yySemanticOption* yyx1,
 		   yyGLRStack* yystack]b4_pure_formals[)
 {
-  /* `Unused' warnings.  */
-  (void) yyx0;
-  (void) yyx1;
+  /* Suppress unused-variable warnings.  */
+  yyx0 = yyx0;
+  yyx1 = yyx1;
 
 #if YYDEBUG
   YYFPUTS ("Ambiguity detected.\nOption 1,\n", stderr);
@@ -1847,9 +1847,9 @@ static void
 yyreportSyntaxError (yyGLRStack* yystack,
 		     YYSTYPE* yylvalp, YYLTYPE* yyllocp]b4_user_formals[)
 {
-  /* `Unused' warnings. */
-  (void) yylvalp;
-  (void) yyllocp;
+  /* Suppress unused-variable warnings.  */
+  yylvalp = yylvalp;
+  yyllocp = yyllocp;
 
   if (yystack->yyerrState == 0)
     {
