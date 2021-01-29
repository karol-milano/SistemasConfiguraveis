@@ -2029,7 +2029,7 @@ yyreduce:
 
 /* Line 1457 of yacc.c  */
 #line 257 "parse-gram.y"
-    { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
+    { language_argmatch ((yyvsp[(2) - (2)].chars), 1, (yylsp[(1) - (2)])); }
 
 /* Line 1457 of yacc.c  */
 #line 2036 "../../../src/parse-gram.c"
@@ -2181,7 +2181,7 @@ yyreduce:
           skeleton_user = uniqstr_new (skeleton_build);
           free (skeleton_build);
         }
-      skeleton_arg (skeleton_user, 1, &(yylsp[(1) - (2)]));
+      skeleton_arg (skeleton_user, 1, (yylsp[(1) - (2)]));
     }
 
 /* Line 1457 of yacc.c  */
