@@ -1,9 +1,9 @@
-/* A Bison parser, made by GNU Bison 3.4.92.  */
+/* A Bison parser, made by GNU Bison 3.5.22-948cd-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
-   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software
-   Foundation, Inc.
+   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
+   Inc.
 
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -48,7 +48,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.4.92"
+#define YYBISON_VERSION "3.5.22-948cd-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1169,7 +1169,7 @@ yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
     {
       YYFPRINTF (stderr, "   $%d = ", yyi + 1);
       yy_symbol_print (stderr,
-                       yystos[yyssp[yyi + 1 - yynrhs]],
+                       yystos[+yyssp[yyi + 1 - yynrhs]],
                        &yyvsp[(yyi + 1) - (yynrhs)]
                        , &(yylsp[(yyi + 1) - (yynrhs)])                       );
       YYFPRINTF (stderr, "\n");
@@ -1363,12 +1363,12 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
     }
   while (1)
     {
-      int yyrule = yypact[*yyesp];
+      int yyrule = yypact[+*yyesp];
       if (yypact_value_is_default (yyrule)
           || (yyrule += yytoken) < 0 || YYLAST < yyrule
           || yycheck[yyrule] != yytoken)
         {
-          yyrule = yydefact[*yyesp];
+          yyrule = yydefact[+*yyesp];
           if (yyrule == 0)
             {
               YYDPRINTF ((stderr, " Err\n"));
@@ -1584,7 +1584,7 @@ yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
   */
   if (yytoken != YYEMPTY)
     {
-      int yyn = yypact[*yyssp];
+      int yyn = yypact[+*yyssp];
       YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
       yysize = yysize0;
       YYDPRINTF ((stderr, "Constructing syntax error message\n"));
@@ -2825,7 +2825,7 @@ yyreturn:
   while (yyssp != yyss)
     {
       yydestruct ("Cleanup: popping",
-                  yystos[*yyssp], yyvsp, yylsp);
+                  yystos[+*yyssp], yyvsp, yylsp);
       YYPOPSTACK (1);
     }
 #ifndef yyoverflow
