@@ -2349,7 +2349,7 @@ yyreduce:
 #line 439 "src/parse-gram.y" /* yacc.c:1669  */
     {
       union_seen = true;
-      muscle_code_grow ("stype", (yyvsp[0].chars), (yylsp[0]));
+      muscle_code_grow ("union_members", (yyvsp[0].chars), (yylsp[0]));
       code_scanner_last_string_free ();
     }
 #line 2356 "src/parse-gram.c" /* yacc.c:1669  */
