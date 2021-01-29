@@ -414,14 +414,14 @@ static const ]b4_int_type_for([b4_stos])[ yystos[] =
 
 #ifndef YYLLOC_DEFAULT
 # define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN)			\
-  (yyCurrent).first_line   = YYRHSLOC(yyRhs,1).first_line;	\
-  (yyCurrent).first_column = YYRHSLOC(yyRhs,1).first_column;	\
-  (yyCurrent).last_line    = YYRHSLOC(yyRhs,YYN).last_line;	\
-  (yyCurrent).last_column  = YYRHSLOC(yyRhs,YYN).last_column;
+   ((yyCurrent).first_line = YYRHSLOC(yyRhs, 1).first_line,	\
+    (yyCurrent).first_column = YYRHSLOC(yyRhs, 1).first_column,	\
+    (yyCurrent).last_line = YYRHSLOC(yyRhs, YYN).last_line,	\
+    (yyCurrent).last_column  = YYRHSLOC(yyRhs, YYN).last_column)
 #endif
 ]],[
 #ifndef YYLLOC_DEFAULT
-# define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN)
+# define YYLLOC_DEFAULT(yyCurrent, yyRhs, YYN) ((void) 0)
 #endif
 ])[
 
