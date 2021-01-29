@@ -1171,11 +1171,9 @@ YYLTYPE yylloc;
   yylloc.start.line   = yylloc.end.line   = 1;
   yylloc.start.column = yylloc.end.column = 0;
 }
-/* Line 869 of yacc.c.  */
+/* Line 870 of yacc.c.  */
 #line 1176 "parse-gram.c"
-  yyvsp[0] = yylval;
-    yylsp[0] = yylloc;
-
+  yylsp[0] = yylloc;
   goto yysetstate;
 
 /*------------------------------------------------------------.
@@ -1756,8 +1754,8 @@ yyreduce:
       default: break;
     }
 
-/* Line 1065 of yacc.c.  */
-#line 1761 "parse-gram.c"
+/* Line 1066 of yacc.c.  */
+#line 1759 "parse-gram.c"
 
   yyvsp -= yylen;
   yyssp -= yylen;
