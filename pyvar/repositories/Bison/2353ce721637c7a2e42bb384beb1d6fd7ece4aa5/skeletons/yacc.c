@@ -1114,8 +1114,8 @@ yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
   int yytoken;]b4_locations_if([[
   YYLTYPE *yylloc;]])[]b4_lac_if([[
   yy_state_t *yyesa;
-  yy_state_t **yyes_p;
-  YYPTRDIFF_T *yyes_capacity_p;]])[
+  yy_state_t **yyes;
+  YYPTRDIFF_T *yyes_capacity;]])[
 } yyparse_context_t;
 
 /* Put in YYARG at most YYARGN of the expected tokens given the
@@ -1134,7 +1134,7 @@ yyexpected_tokens (const yyparse_context_t *yyctx,
     if (yyx != YYTERROR && yyx != YYUNDEFTOK)
       {
         {
-          int yy_lac_status = yy_lac (yyctx->yyesa, yyctx->yyes_p, yyctx->yyes_capacity_p,
+          int yy_lac_status = yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity,
                                       yyctx->yyssp, yyx);
           if (yy_lac_status == 2)
             return -2;
