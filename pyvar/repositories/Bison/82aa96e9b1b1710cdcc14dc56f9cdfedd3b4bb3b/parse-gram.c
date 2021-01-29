@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 3.6.90.  */
+/* A Bison parser, made by GNU Bison 3.7.12-658d-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -49,7 +49,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "3.6.90"
+#define YYBISON_VERSION "3.7.12-658d-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -2339,13 +2339,13 @@ yyreduce:
 
   case 67: /* token_decls: "<tag>" token_decl.1  */
     {
-      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yykind_80), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.token_decls) = symbol_list_type_set ((yyvsp[0].yykind_80), (yyvsp[-1].TAG));
     }
     break;
 
   case 68: /* token_decls: token_decls "<tag>" token_decl.1  */
     {
-      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yykind_80), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.token_decls) = symbol_list_append ((yyvsp[-2].token_decls), symbol_list_type_set ((yyvsp[0].yykind_80), (yyvsp[-1].TAG)));
     }
     break;
 
@@ -2396,13 +2396,13 @@ yyreduce:
 
   case 78: /* token_decls_for_prec: "<tag>" token_decl_for_prec.1  */
     {
-      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yykind_85), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.token_decls_for_prec) = symbol_list_type_set ((yyvsp[0].yykind_85), (yyvsp[-1].TAG));
     }
     break;
 
   case 79: /* token_decls_for_prec: token_decls_for_prec "<tag>" token_decl_for_prec.1  */
     {
-      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yykind_85), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.token_decls_for_prec) = symbol_list_append ((yyvsp[-2].token_decls_for_prec), symbol_list_type_set ((yyvsp[0].yykind_85), (yyvsp[-1].TAG)));
     }
     break;
 
@@ -2431,13 +2431,13 @@ yyreduce:
 
   case 85: /* symbol_decls: "<tag>" symbol_decl.1  */
     {
-      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yykind_88), (yyvsp[-1].TAG), (yylsp[-1]));
+      (yyval.symbol_decls) = symbol_list_type_set ((yyvsp[0].yykind_88), (yyvsp[-1].TAG));
     }
     break;
 
   case 86: /* symbol_decls: symbol_decls "<tag>" symbol_decl.1  */
     {
-      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yykind_88), (yyvsp[-1].TAG), (yylsp[-1])));
+      (yyval.symbol_decls) = symbol_list_append ((yyvsp[-2].symbol_decls), symbol_list_type_set ((yyvsp[0].yykind_88), (yyvsp[-1].TAG)));
     }
     break;
 
