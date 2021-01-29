@@ -1963,9 +1963,8 @@ yyerrlab:
           goto yyexhaustedlab;
       }]])[
     }
-
-]b4_locations_if([[  yyerror_range[1] = yylloc;]])[
-
+]b4_locations_if([[
+  yyerror_range[1] = yylloc;]])[
   if (yyerrstatus == 3)
     {
       /* If just tried and failed to reuse lookahead token after an
