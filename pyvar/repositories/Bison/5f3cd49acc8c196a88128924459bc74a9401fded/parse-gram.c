@@ -1960,6 +1960,17 @@ yybackup:
       yytoken = YYSYMBOL_YYEOF;
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
+  else if (yychar == GRAM_ERRCODE)
+    {
+      /* The scanner already issued an error message, process directly
+         to error recovery.  But do not keep the error token as
+         lookahead, it is too special and may lead us to an endless
+         loop in error recovery. */
+      yychar = GRAM_UNDEF;
+      yytoken = YYSYMBOL_YYERRCODE;
+      yyerror_range[1] = yylloc;
+      goto yyerrlab1;
+    }
   else
     {
       yytoken = YYTRANSLATE (yychar);
@@ -2640,7 +2651,6 @@ yyerrlab:
     }
 
   yyerror_range[1] = yylloc;
-
   if (yyerrstatus == 3)
     {
       /* If just tried and failed to reuse lookahead token after an
