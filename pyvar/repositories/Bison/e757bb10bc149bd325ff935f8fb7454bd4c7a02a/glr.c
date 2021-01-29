@@ -1916,7 +1916,13 @@ yyrecoverSyntaxError (yyGLRStack* yystack,
       yyposn = yystack.yytops.yystates[0]->yyposn;
     }
  yyDone:
-  ;
+  /* On YYABORT, free the lookahead. */
+  if (yystack.yyerrflag == 1 && yytoken != YYEMPTY)
+    {
+      YY_SYMBOL_PRINT ("Error: discarding lookahead",
+                       yytoken, yylvalp, yyllocp);
+      yydestruct (yytoken, yylvalp]b4_location_if([, yyllocp])[);
+    }
 
   yyfreeGLRStack (&yystack);
   return yystack.yyerrflag;
