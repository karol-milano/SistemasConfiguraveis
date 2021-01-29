@@ -1125,8 +1125,7 @@ static void
 yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
 #else
 static void
-yy_reduce_print (yyvsp, yylsp, yyrule
-		   )
+yy_reduce_print (yyvsp, yylsp, yyrule)
     YYSTYPE *yyvsp;
     YYLTYPE *yylsp;
     int yyrule;
@@ -1570,7 +1569,7 @@ YYLTYPE yylloc;
   yylloc.start.column = yylloc.end.column = 0;
 }
 /* Line 1078 of yacc.c.  */
-#line 1574 "parse-gram.c"
+#line 1573 "parse-gram.c"
   yylsp[0] = yylloc;
   goto yysetstate;
 
@@ -2156,7 +2155,7 @@ yyreduce:
 
 
 /* Line 1267 of yacc.c.  */
-#line 2160 "parse-gram.c"
+#line 2159 "parse-gram.c"
       default: break;
     }
   YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);
@@ -2371,7 +2370,8 @@ yyreturn:
   if (yymsg != yymsgbuf)
     YYSTACK_FREE (yymsg);
 #endif
-  return yyresult;
+  /* Make sure YYID is used.  */
+  return YYID (yyresult);
 }
 
 
