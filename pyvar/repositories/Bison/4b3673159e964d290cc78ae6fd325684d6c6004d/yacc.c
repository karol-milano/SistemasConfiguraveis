@@ -36,10 +36,10 @@ m4_define_default([b4_stack_depth_init],  [200])
 ## ------------------------ ##
 
 
-# b4_pure_if(IF-TRUE, IF-FALSE)
-# -----------------------------
+# b4_yacc_pure_if(IF-TRUE, IF-FALSE)
+# ----------------------------------
 # Expand IF-TRUE, if %pure-parser and %parse-param, IF-FALSE otherwise.
-m4_define([b4_Pure_if],
+m4_define([b4_yacc_pure_if],
 [b4_pure_if([m4_ifset([b4_parse_param],
                       [$1], [$2])],
             [$2])])
@@ -49,7 +49,7 @@ m4_define([b4_Pure_if],
 # ---------------
 # Arguments passed to yyerror: user args plus yylloc.
 m4_define([b4_yyerror_args],
-[b4_Pure_if([b4_location_if([&yylloc, ])])dnl
+[b4_yacc_pure_if([b4_location_if([&yylloc, ])])dnl
 m4_ifset([b4_parse_param], [b4_c_args(b4_parse_param), ])])
 
 
@@ -628,15 +628,15 @@ do {						\
     YYFPRINTF Args;				\
 } while (/*CONSTCOND*/ 0)
 
-# define YY_SYMBOL_PRINT(Title, Type, Value, Location)		\
-do {								\
-  if (yydebug)							\
-    {								\
-      YYFPRINTF (stderr, "%s ", Title);				\
-      yysymprint (stderr,					\
-                  Type, Value]b4_location_if([, Location])[);	\
-      YYFPRINTF (stderr, "\n");					\
-    }								\
+# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
+do {									  \
+  if (yydebug)								  \
+    {									  \
+      YYFPRINTF (stderr, "%s ", Title);					  \
+      yysymprint (stderr,						  \
+                  Type, Value]b4_location_if([, Location])[]b4_user_args[); \
+      YYFPRINTF (stderr, "\n");						  \
+    }									  \
 } while (/*CONSTCOND*/ 0)
 
 /*------------------------------------------------------------------.
@@ -1346,7 +1346,8 @@ yyerrlab:
         }
       else
 	{
-	  yydestruct ("Error: discarding", yytoken, &yylval]b4_location_if([, &yylloc])[);
+	  yydestruct ("Error: discarding",
+                      yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
 	  yychar = YYEMPTY;
 	}
     }
@@ -1400,7 +1401,8 @@ yyerrlab1:
 	YYABORT;
 
 ]b4_location_if([[      yyerror_range[0] = *yylsp;]])[
-      yydestruct ("Error: popping", yystos[yystate], yyvsp]b4_location_if([, yylsp])[);
+      yydestruct ("Error: popping",
+                  yystos[yystate], yyvsp]b4_location_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK;
       yystate = *yyssp;
       YY_STACK_PRINT (yyss, yyssp);
@@ -1451,11 +1453,11 @@ yyexhaustedlab:
 yyreturn:
   if (yychar != YYEOF && yychar != YYEMPTY)
      yydestruct ("Cleanup: discarding lookahead",
-		 yytoken, &yylval]b4_location_if([, &yylloc])[);
+		 yytoken, &yylval]b4_location_if([, &yylloc])[]b4_user_args[);
   while (yyssp != yyss)
     {
       yydestruct ("Cleanup: popping",
-		  yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[);
+		  yystos[*yyssp], yyvsp]b4_location_if([, yylsp])[]b4_user_args[);
       YYPOPSTACK;
     }
 #ifndef yyoverflow
