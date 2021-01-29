@@ -135,7 +135,7 @@ m4_changecom()
 m4_divert(0)dnl
 @output @output_parser_name@
 b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
-             [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004])[
+             [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005])[
 
 /* As a special exception, when this file is copied by Bison into a
    Bison output file, you may use that output file without restriction.
@@ -1296,9 +1296,6 @@ yyacceptlab:
 | yyabortlab -- YYABORT comes here.  |
 `-----------------------------------*/
 yyabortlab:
-  yydestruct (_("Error: discarding lookahead"),
-              yytoken, &yylval]b4_location_if([, &yylloc])[);
-  yychar = YYEMPTY;
   yyresult = 1;
   goto yyreturn;
 
@@ -1308,13 +1305,14 @@ yyabortlab:
 `----------------------------------------------*/
 yyoverflowlab:
   yyerror (]b4_yyerror_args[_("parser stack overflow"));
-  yydestruct (_("Error: discarding lookahead"),
-	      yytoken, &yylval]b4_location_if([, &yylloc])[);
   yyresult = 2;
   /* Fall through.  */
 #endif
 
 yyreturn:
+  if (yychar != YYEOF && yychar != YYEMPTY)
+     yydestruct (_("Error: discarding lookahead"),
+		 yytoken, &yylval]b4_location_if([, &yylloc])[);
   if (yyssp != yyss)
     for (;;)
       {
@@ -1337,7 +1335,7 @@ b4_epilogue
 m4_if(b4_defines_flag, 0, [],
 [@output @output_header_name@
 b4_copyright([Skeleton parser for Yacc-like parsing with Bison],
-             [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004])
+             [1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005])
 
 /* As a special exception, when this file is copied by Bison into a
    Bison output file, you may use that output file without restriction.
