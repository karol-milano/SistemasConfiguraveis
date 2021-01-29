@@ -2119,6 +2119,8 @@ yypcontext_expected_tokens (const yyGLRStack* yystackp,
               yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
           }
     }
+  if (yyarg && yycount == 0 && 0 < yyargn)
+    yyarg[0] = ]b4_symbol(-2, kind)[;
   return yycount;
 }]])[
 
