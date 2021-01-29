@@ -2044,6 +2044,7 @@ yyerrorlab:
      label yyerrorlab therefore never appears in user code.  */
   if (0)
     YYERROR;
+  ++yynerrs;
 
   /* Do not reclaim the symbols of the rule whose action triggered
      this YYERROR.  */
