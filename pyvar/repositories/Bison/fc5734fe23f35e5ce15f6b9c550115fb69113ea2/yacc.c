@@ -650,7 +650,7 @@ b4_c_function([yyreport_parse_error],
 	      [[int],     [yystate]],
 	      [[int],     [yychar]],
 	      [[YYSTYPE], [yyvalue]]b4_location_if([,
-	      [[YYLTYPE], [yylocation]]]))
+	      [[YYLTYPE], [yylloc]]]))
 [{
 #if YYERROR_VERBOSE
   int yyn = yypact[yystate];
@@ -705,7 +705,7 @@ b4_c_function([yyreport_parse_error],
   (void) yystate;
   (void) yychar;
   (void) yyvalue;
-  ]b4_location_if([(void) yylocation;])[
+  ]b4_location_if([(void) yylloc;])[
 }]
 
 
