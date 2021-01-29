@@ -1,4 +1,4 @@
-/* A Bison parser, made by GNU Bison 2.7.1021-bb417-dirty.  */
+/* A Bison parser, made by GNU Bison 2.7.1067-29fb-dirty.  */
 
 /* Bison implementation for Yacc-like parsers in C
 
@@ -44,7 +44,7 @@
 #define YYBISON 1
 
 /* Bison version.  */
-#define YYBISON_VERSION "2.7.1021-bb417-dirty"
+#define YYBISON_VERSION "2.7.1067-29fb-dirty"
 
 /* Skeleton name.  */
 #define YYSKELETON_NAME "yacc.c"
@@ -113,7 +113,7 @@
 static YYLTYPE lloc_default (YYLTYPE const *, int);
 
 #define YY_LOCATION_PRINT(File, Loc) \
-          location_print (File, Loc)
+          location_print (Loc, File)
 
 static void version_check (location const *loc, char const *version);
 
@@ -2528,18 +2528,18 @@ yyreduce:
   case 70:
 #line 541 "src/parse-gram.y" /* yacc.c:1669  */
     {
-       current_type = (yyvsp[0].uniqstr);
-       tag_seen = true;
-     }
+      current_type = (yyvsp[0].uniqstr);
+      tag_seen = true;
+    }
 #line 2535 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
   case 71:
 #line 546 "src/parse-gram.y" /* yacc.c:1669  */
     {
-       symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
-       symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
-     }
+      symbol_class_set ((yyvsp[0].symbol), current_class, (yylsp[0]), true);
+      symbol_type_set ((yyvsp[0].symbol), current_type, (yylsp[0]));
+    }
 #line 2544 "src/parse-gram.c" /* yacc.c:1669  */
     break;
 
