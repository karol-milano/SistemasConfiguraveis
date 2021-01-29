@@ -2353,7 +2353,7 @@ yyrecoverSyntaxError (yyGLRStack* yystackp]b4_user_formals[)
     yycompressStack (yystackp);
   }
 
-  /* Now pop stack until we find a state that shifts the error token.  */
+  /* Pop stack until we find a state that shifts the error token.  */
   yystackp->yyerrState = 3;
   while (yystackp->yytops.yystates[0] != YY_NULLPTR)
     {
