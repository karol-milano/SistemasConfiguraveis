@@ -973,7 +973,7 @@ yydestroyGLRState (char const *yymsg, yyGLRState *yys]b4_user_formals[)
 	{
 	  YYFPRINTF (stderr, "%s unresolved ", yymsg);
 	  yy_symbol_print (stderr, yystos[yys->yylrState],
-			   &yys->yysemantics.yysval]b4_location_if([, &yys->yyloc])[]b4_user_args[);
+			   NULL]b4_location_if([, &yys->yyloc])[]b4_user_args[);
 	  YYFPRINTF (stderr, "\n");
 	}
 #endif
