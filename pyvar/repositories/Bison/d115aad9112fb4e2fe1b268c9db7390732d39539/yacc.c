@@ -646,11 +646,12 @@ static const ]b4_int_type_for([b4_toknum])[ yytoknum[] =
 
 #define YYBACKUP(Token, Value)                                  \
 do                                                              \
-  if (yychar == YYEMPTY && yylen == 1)                          \
+  if (yychar == YYEMPTY)                                        \
     {                                                           \
       yychar = (Token);                                         \
       yylval = (Value);                                         \
-      YYPOPSTACK (1);                                           \]b4_lac_if([[
+      YYPOPSTACK (yylen);                                       \
+      yystate = *yyssp;                                         \]b4_lac_if([[
       YY_LAC_DISCARD ("YYBACKUP");                              \]])[
       goto yybackup;                                            \
     }                                                           \
