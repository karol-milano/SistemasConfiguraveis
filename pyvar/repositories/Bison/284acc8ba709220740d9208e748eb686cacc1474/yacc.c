@@ -537,19 +537,13 @@ do {						\
     YYFPRINTF Args;				\
 } while (0)
 
-# define YYDSYMPRINT(Args)			\
-do {						\
-  if (yydebug)					\
-    yysymprint Args;				\
-} while (0)
-
-# define YYDSYMPRINTF(Title, Token, Value, Location)		\
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
 do {								\
   if (yydebug)							\
     {								\
       YYFPRINTF (stderr, "%s ", Title);				\
       yysymprint (stderr, 					\
-                  Token, Value]b4_location_if([, Location])[);	\
+                  Type, Value]b4_location_if([, Location])[);	\
       YYFPRINTF (stderr, "\n");					\
     }								\
 } while (0)
@@ -604,8 +598,7 @@ do {					\
 int yydebug;
 #else /* !YYDEBUG */
 # define YYDPRINTF(Args)
-# define YYDSYMPRINT(Args)
-# define YYDSYMPRINTF(Title, Token, Value, Location)
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
 # define YY_REDUCE_PRINT(Rule)
 #endif /* !YYDEBUG */
@@ -932,7 +925,7 @@ yybackup:
   else
     {
       yytoken = YYTRANSLATE (yychar);
-      YYDSYMPRINTF ("Next token is", yytoken, &yylval, &yylloc);
+      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
     }
 
   /* If the proper action on seeing token YYTOKEN is to reduce or to
@@ -1121,13 +1114,14 @@ yyerrlab:
 		 YYPOPSTACK;
 		 if (yyssp == yyss)
 		   YYABORT;
-		 YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
+		 YY_SYMBOL_PRINT ("Error: popping",
+	                          yystos[*yyssp], yyvsp, yylsp);
 		 yydestruct (yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
 	       }
         }
       else
 	{
-	  YYDSYMPRINTF ("Error: discarding", yytoken, &yylval, &yylloc);
+	  YY_SYMBOL_PRINT ("Error: discarding", yytoken, &yylval, &yylloc);
 	  yydestruct (yytoken, &yylval]b4_location_if([, &yylloc])[);
 	  yychar = YYEMPTY;
 ]b4_location_if([	  *++yylerrsp = yylloc;])[
@@ -1184,7 +1178,7 @@ yyerrlab1:
       if (yyssp == yyss)
 	YYABORT;
 
-      YYDSYMPRINTF ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
+      YY_SYMBOL_PRINT ("Error: popping", yystos[*yyssp], yyvsp, yylsp);
       yydestruct (yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
       YYPOPSTACK;
       yystate = *yyssp;
