@@ -1391,7 +1391,7 @@ yybackup:
 	pv->yyval = yyval;
 	]b4_locations_if([pv->yyloc = yyloc;])[
 	goto yypushreturn;
-gottoken:])
+gottoken:])[
       YYDPRINTF ((stderr, "Reading a token: "));
       ]b4_push_if([], [yychar = YYLEX;])[
     }
