@@ -668,9 +668,9 @@ do {								\
 `------------------------------------------------*/
 
 ]b4_c_function_def([yy_reduce_print], [static void],
-                   [[YYSTYPE *yyvsp], [yyvsvp]],
-   b4_location_if([[[YYLTYPE *yylsp], [yyvlvp]],])
-                   [[int yyrule],     [yyrule]]
+                   [[YYSTYPE *yyvsp], [yyvsp]],
+    b4_location_if([[[YYLTYPE *yylsp], [yylsp]],])
+		   [[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,])
                    b4_parse_param)[
 {
   int yynrhs = yyr2[yyrule];
@@ -690,10 +690,10 @@ do {								\
     }
 }
 
-# define YY_REDUCE_PRINT(Args)					\
-do {								\
-  if (yydebug)							\
-    yy_reduce_print (yyvsp, ]b4_location_if([yylsp, ])[Args);	\
+# define YY_REDUCE_PRINT(Rule)		\
+do {					\
+  if (yydebug)				\
+    yy_reduce_print (yyvsp, ]b4_location_if([yylsp, ])[Rule]b4_user_args[); \
 } while (/*CONSTCOND*/ 0)
 
 /* Nonzero means print parse trace.  It is left uninitialized so that
@@ -703,7 +703,7 @@ int yydebug;
 # define YYDPRINTF(Args)
 # define YY_SYMBOL_PRINT(Title, Type, Value, Location)
 # define YY_STACK_PRINT(Bottom, Top)
-# define YY_REDUCE_PRINT(Args)
+# define YY_REDUCE_PRINT(Rule)
 #endif /* !YYDEBUG */
 
 
@@ -1261,7 +1261,7 @@ yyreduce:
 ]b4_location_if(
 [[  /* Default location. */
   YYLLOC_DEFAULT (yyloc, yylsp - yylen, yylen);]])[
-  YY_REDUCE_PRINT ((yyn]b4_user_args[));
+  YY_REDUCE_PRINT (yyn);
   switch (yyn)
     {
       ]b4_actions[
