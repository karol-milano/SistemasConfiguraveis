@@ -900,7 +900,6 @@ enum { YYENOMEM = -2 };
 #define yyerrok         (yyerrstatus = 0)
 #define yyclearin       (yychar = YYEMPTY)
 #define YYEMPTY         (-2)
-#define YYEOF           0
 
 #define YYACCEPT        goto yyacceptlab
 #define YYABORT         goto yyabortlab
@@ -1950,9 +1949,9 @@ yybackup:
       yychar = yylex (&yylval, &yylloc);
     }
 
-  if (yychar <= YYEOF)
+  if (yychar <= GRAM_EOF)
     {
-      yychar = YYEOF;
+      yychar = GRAM_EOF;
       yytoken = YYSYMBOL_YYEOF;
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
@@ -2643,10 +2642,10 @@ yyerrlab:
       /* If just tried and failed to reuse lookahead token after an
          error, discard it.  */
 
-      if (yychar <= YYEOF)
+      if (yychar <= GRAM_EOF)
         {
           /* Return failure if at end of input.  */
-          if (yychar == YYEOF)
+          if (yychar == GRAM_EOF)
             YYABORT;
         }
       else
