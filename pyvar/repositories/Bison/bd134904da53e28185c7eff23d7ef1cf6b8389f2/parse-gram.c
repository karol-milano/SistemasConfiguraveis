@@ -1,7 +1,7 @@
 /* A Bison parser, made by GNU Bison 2.0a.  */
 
 /* Skeleton parser for Yacc-like parsing with Bison,
-   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
+   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.
 
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
@@ -1990,9 +1990,6 @@ yyacceptlab:
 | yyabortlab -- YYABORT comes here.  |
 `-----------------------------------*/
 yyabortlab:
-  yydestruct (_("Error: discarding lookahead"),
-              yytoken, &yylval, &yylloc);
-  yychar = YYEMPTY;
   yyresult = 1;
   goto yyreturn;
 
@@ -2002,13 +1999,14 @@ yyabortlab:
 `----------------------------------------------*/
 yyoverflowlab:
   yyerror (_("parser stack overflow"));
-  yydestruct (_("Error: discarding lookahead"),
-	      yytoken, &yylval, &yylloc);
   yyresult = 2;
   /* Fall through.  */
 #endif
 
 yyreturn:
+  if (yychar != YYEOF && yychar != YYEMPTY)
+     yydestruct (_("Error: discarding lookahead"),
+		 yytoken, &yylval, &yylloc);
   if (yyssp != yyss)
     for (;;)
       {
