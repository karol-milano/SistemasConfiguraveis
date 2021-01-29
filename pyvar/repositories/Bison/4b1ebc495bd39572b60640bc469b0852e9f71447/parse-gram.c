@@ -1,5 +1,5 @@
 
-/* A Bison parser, made by GNU Bison 2.3b.21-d67c5-dirty.  */
+/* A Bison parser, made by GNU Bison 2.4.4-738cd.  */
 
 /* Skeleton implementation for Bison's Yacc-like parsers in C
    
@@ -46,7 +46,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.3b.21-d67c5-dirty"
+#define YYBISON_VERSION "2.4.4-738cd"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -1994,7 +1994,7 @@ yyreduce:
 
 /* Line 1455 of yacc.c  */
 #line 257 "parse-gram.y"
-    { language_argmatch ((yyvsp[(2) - (2)].chars), 1, &(yylsp[(1) - (2)])); }
+    { language_argmatch ((yyvsp[(2) - (2)].chars), grammar_prio, &(yylsp[(1) - (2)])); }
     break;
 
   case 19:
@@ -2110,7 +2110,7 @@ yyreduce:
           skeleton_user = uniqstr_new (skeleton_build);
           free (skeleton_build);
         }
-      skeleton_arg (skeleton_user, 1, &(yylsp[(1) - (2)]));
+      skeleton_arg (skeleton_user, grammar_prio, &(yylsp[(1) - (2)]));
     }
     break;
 
