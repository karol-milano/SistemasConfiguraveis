@@ -712,18 +712,19 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 
 #define YYRECOVERING()  (!!yyerrstatus)
 
-#define YYBACKUP(Token, Value)					\
-do								\
-  if (yychar == YYEMPTY && yylen == 1)				\
-    {								\
-      yychar = (Token);						\
-      yylval = (Value);						\
-      YYPOPSTACK (1);						\]b4_lac_if([[
-      YY_LAC_DISCARD ("YYBACKUP");				\]])[
-      goto yybackup;						\
-    }								\
-  else								\
-    {								\
+#define YYBACKUP(Token, Value)                                  \
+do                                                              \
+  if (yychar == YYEMPTY)                                        \
+    {                                                           \
+      yychar = (Token);                                         \
+      yylval = (Value);                                         \
+      YYPOPSTACK (yylen);                                       \
+      yystate = *yyssp;                                         \]b4_lac_if([[
+      YY_LAC_DISCARD ("YYBACKUP");                              \]])[
+      goto yybackup;                                            \
+    }                                                           \
+  else                                                          \
+    {                                                           \
       yyerror (]b4_yyerror_args[YY_("syntax error: cannot back up")); \
       YYERROR;							\
     }								\
