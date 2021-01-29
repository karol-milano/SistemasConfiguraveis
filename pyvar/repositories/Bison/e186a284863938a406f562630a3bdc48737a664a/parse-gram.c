@@ -1994,7 +1994,10 @@ yyreduce:
 
 /* Line 1455 of yacc.c  */
 #line 257 "parse-gram.y"
-    { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, &(yylsp[(1) - (2)])); }
+    { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, (yylsp[(1) - (2)])); }
+
+/* Line 1457 of yacc.c  */
+#line 2036 "../../../src/parse-gram.c"
     break;
 
   case 19:
@@ -2110,7 +2113,7 @@ yyreduce:
           skeleton_user = uniqstr_new (skeleton_build);
           free (skeleton_build);
         }
-      skeleton_arg (skeleton_user, grammar_prio, &(yylsp[(1) - (2)]));
+      skeleton_arg (skeleton_user, grammar_prio, (yylsp[(1) - (2)]));
     }
     break;
 
