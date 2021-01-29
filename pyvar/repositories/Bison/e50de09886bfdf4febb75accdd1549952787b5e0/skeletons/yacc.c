@@ -716,7 +716,6 @@ enum { YYENOMEM = -2 };
 #define yyerrok         (yyerrstatus = 0)
 #define yyclearin       (yychar = YYEMPTY)
 #define YYEMPTY         (-2)
-#define YYEOF           0
 
 #define YYACCEPT        goto yyacceptlab
 #define YYABORT         goto yyabortlab
@@ -1760,9 +1759,9 @@ yyread_pushed_token:]])[
       yychar = ]b4_lex[;]])[
     }
 
-  if (yychar <= YYEOF)
+  if (yychar <= ]b4_symbol(0, [id])[)
     {
-      yychar = YYEOF;
+      yychar = ]b4_symbol(0, [id])[;
       yytoken = ]b4_symbol_prefix[YYEOF;
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
@@ -1957,10 +1956,10 @@ yyerrlab:
       /* If just tried and failed to reuse lookahead token after an
          error, discard it.  */
 
-      if (yychar <= YYEOF)
+      if (yychar <= ]b4_symbol(0, [id])[)
         {
           /* Return failure if at end of input.  */
-          if (yychar == YYEOF)
+          if (yychar == ]b4_symbol(0, [id])[)
             YYABORT;
         }
       else
