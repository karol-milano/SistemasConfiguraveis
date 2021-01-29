@@ -755,8 +755,8 @@ enum { YYENOMEM = -2 };
   while (0)
 
 /* Backward compatibility with an undocumented macro.
-   Use ]b4_symbol(1, id)[ or ]b4_symbol(2, id)[. */
-#define YYERRCODE ]b4_symbol(2, id)[
+   Use ]b4_symbol(error, id)[ or ]b4_symbol(undef, id)[. */
+#define YYERRCODE ]b4_symbol(undef, id)[
 ]b4_locations_if([[
 ]b4_yylloc_default_define[
 #define YYRHSLOC(Rhs, K) ((Rhs)[K])
@@ -1165,7 +1165,7 @@ yypcontext_expected_tokens (const yypcontext_t *yyctx,
   for (yyx = 0; yyx < YYNTOKENS; ++yyx)
     {
       yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
-      if (yysym != ]b4_symbol(1, kind)[ && yysym != ]b4_symbol_prefix[YYUNDEF)
+      if (yysym != ]b4_symbol(error, kind)[ && yysym != ]b4_symbol_prefix[YYUNDEF)
         switch (yy_lac (]b4_push_if([[yyps->yyesa, &yyps->yyes, &yyps->yyes_capacity, yyps->yyssp, yysym]],
                                     [[yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym]])[))
           {
@@ -1194,7 +1194,7 @@ yypcontext_expected_tokens (const yypcontext_t *yyctx,
       int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
       int yyx;
       for (yyx = yyxbegin; yyx < yyxend; ++yyx)
-        if (yycheck[yyx + yyn] == yyx && yyx != ]b4_symbol(1, kind)[
+        if (yycheck[yyx + yyn] == yyx && yyx != ]b4_symbol(error, kind)[
             && !yytable_value_is_error (yytable[yyx + yyn]))
           {
             if (!yyarg)
@@ -1820,20 +1820,20 @@ yyread_pushed_token:]])[
       yychar = ]b4_lex[;]])[
     }
 
-  if (yychar <= ]b4_symbol(0, [id])[)
+  if (yychar <= ]b4_symbol(eof, [id])[)
     {
-      yychar = ]b4_symbol(0, [id])[;
-      yytoken = ]b4_symbol(0, [kind])[;
+      yychar = ]b4_symbol(eof, [id])[;
+      yytoken = ]b4_symbol(eof, [kind])[;
       YYDPRINTF ((stderr, "Now at end of input.\n"));
     }
-  else if (yychar == ]b4_symbol(1, [id])[)
+  else if (yychar == ]b4_symbol(error, [id])[)
     {
       /* The scanner already issued an error message, process directly
          to error recovery.  But do not keep the error token as
          lookahead, it is too special and may lead us to an endless
          loop in error recovery. */
-      yychar = ]b4_symbol(2, [id])[;
-      yytoken = ]b4_symbol(1, [kind])[;]b4_locations_if([[
+      yychar = ]b4_symbol(undef, [id])[;
+      yytoken = ]b4_symbol(error, [kind])[;]b4_locations_if([[
       yyerror_range[1] = yylloc;]])[
       goto yyerrlab1;
     }
@@ -2026,10 +2026,10 @@ yyerrlab:
       /* If just tried and failed to reuse lookahead token after an
          error, discard it.  */
 
-      if (yychar <= ]b4_symbol(0, [id])[)
+      if (yychar <= ]b4_symbol(eof, [id])[)
         {
           /* Return failure if at end of input.  */
-          if (yychar == ]b4_symbol(0, [id])[)
+          if (yychar == ]b4_symbol(eof, [id])[)
             YYABORT;
         }
       else
@@ -2076,8 +2076,8 @@ yyerrlab1:
       yyn = yypact[yystate];
       if (!yypact_value_is_default (yyn))
         {
-          yyn += ]b4_symbol(1, kind)[;
-          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == ]b4_symbol(1, kind)[)
+          yyn += ]b4_symbol(error, kind)[;
+          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == ]b4_symbol(error, kind)[)
             {
               yyn = yytable[yyn];
               if (0 < yyn)
