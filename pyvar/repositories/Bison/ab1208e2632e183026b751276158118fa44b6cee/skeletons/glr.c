@@ -2590,7 +2590,7 @@ b4_dollar_popdef])[]dnl
               YY_SYMBOL_PRINT ("shifting", yytoken_to_shift, &yylval, &yylloc);
               yyglrShift (&yystack, yys, yyaction, yyposn,
                           &yylval]b4_locations_if([, &yylloc])[);
-              YY_DPRINTF ((stderr, "Stack %ld now in state #%d\n",
+              YY_DPRINTF ((stderr, "Stack %ld now in state %d\n",
                            YY_CAST (long, yys),
                            yystack.yytops.yystates[yys]->yylrState));
             }
