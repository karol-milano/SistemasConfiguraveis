@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.5.4.236-8d75.  */
+/* A Bison parser, made by GNU Bison 3.5.90.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.5.4.236-8d75"
+#define YYBISON_VERSION "3.5.90"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -643,7 +643,7 @@ yysymbol_name (yysymbol_kind_t yysymbol)
 {
   static const char *const yy_sname[] =
   {
-  N_("end of file"), "error", N_("invalid token"), N_("string"),
+  N_("end of file"), N_("error"), N_("invalid token"), N_("string"),
   N_("translatable string"), "%token", "%nterm", "%type", "%destructor",
   "%printer", "%left", "%right", "%nonassoc", "%precedence", "%prec",
   "%dprec", "%merge", "%code", "%default-prec", "%define", "%defines",
@@ -670,7 +670,7 @@ yysymbol_name (yysymbol_kind_t yysymbol)
      internationalizable.  */
   static yytype_int8 yytranslatable[] =
   {
-       0,     0,     0,     1,     1,     0,     0,     0,     0,     0,
+       1,     1,     1,     1,     1,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
        0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
@@ -2619,7 +2619,6 @@ yyerrlab:
   /* Make sure we have latest lookahead translation.  See comments at
      user semantic actions for why this is necessary.  */
   yytoken = yychar == GRAM_EMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
-
   /* If not already recovering from an error, report this error.  */
   if (!yyerrstatus)
     {
@@ -2684,6 +2683,7 @@ yyerrorlab:
 yyerrlab1:
   yyerrstatus = 3;      /* Each real token shifted decrements this.  */
 
+  // Pop stack until we find a state that shifts the error token.
   for (;;)
     {
       yyn = yypact[yystate];
