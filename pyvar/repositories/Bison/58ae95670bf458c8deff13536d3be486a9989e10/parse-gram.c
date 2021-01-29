@@ -2348,7 +2348,7 @@ yyreduce:
 #line 313 "src/parse-gram.y" /* yacc.c:1652  */
     {
       defines_flag = true;
-      spec_defines_file = xstrdup ((yyvsp[0].STRING));
+      spec_header_file = xstrdup ((yyvsp[0].STRING));
     }
 #line 2354 "src/parse-gram.c" /* yacc.c:1652  */
     break;
