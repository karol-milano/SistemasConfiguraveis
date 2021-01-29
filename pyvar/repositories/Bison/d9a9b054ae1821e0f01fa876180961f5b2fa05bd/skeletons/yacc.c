@@ -1158,6 +1158,8 @@ yypcontext_expected_tokens (const yypcontext_t *yyctx,
               yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
           }
     }]])[
+  if (yyarg && yycount == 0 && 0 < yyargn)
+    yyarg[0] = ]b4_symbol(-2, kind)[;
   return yycount;
 }
 
