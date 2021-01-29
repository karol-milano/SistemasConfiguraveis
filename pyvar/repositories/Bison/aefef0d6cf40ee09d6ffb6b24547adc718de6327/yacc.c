@@ -693,9 +693,9 @@ do {								\
 
 ]b4_c_function_def([yy_reduce_print], [static void],
 		   [[YYSTYPE *yyvsp], [yyvsp]],
-    b4_locations_if([[[YYLTYPE *yylsp], [yylsp]],])
-		   [[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,])
-		   b4_parse_param)[
+    b4_locations_if([[[YYLTYPE *yylsp], [yylsp]],
+		   ])[[int yyrule], [yyrule]]m4_ifset([b4_parse_param], [,
+		   ])b4_parse_param)[
 {
   int yynrhs = yyr2[yyrule];
   int yyi;
