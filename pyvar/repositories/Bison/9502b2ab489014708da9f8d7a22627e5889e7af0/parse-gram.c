@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.0.4.38-1047-dirty.  */
+/* A Bison parser, made by GNU Bison 3.0.5.23-f58b-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.0.4.38-1047-dirty"
+#define YYBISON_VERSION "3.0.5.23-f58b-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -2608,13 +2608,13 @@ yyreduce:
 
   case 89:
 #line 617 "src/parse-gram.y" /* yacc.c:1648  */
-    { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref), false); }
+    { grammar_current_rule_action_append ((yyvsp[-1].code), (yylsp[-1]), (yyvsp[0].named_ref)); }
 #line 2613 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
   case 90:
 #line 619 "src/parse-gram.y" /* yacc.c:1648  */
-    { grammar_current_rule_action_append ((yyvsp[0].code), (yylsp[0]), NULL, true); }
+    { grammar_current_rule_predicate_append ((yyvsp[0].code), (yylsp[0])); }
 #line 2619 "src/parse-gram.c" /* yacc.c:1648  */
     break;
 
