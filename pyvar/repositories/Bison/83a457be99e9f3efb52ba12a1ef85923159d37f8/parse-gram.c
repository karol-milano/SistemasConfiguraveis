@@ -1263,7 +1263,7 @@ yyreduce:
 
   case 7:
 #line 178 "parse-gram.y"
-    { debug_flag = 1; }
+    { debug_flag = true; }
     break;
 
   case 8:
@@ -1273,12 +1273,12 @@ yyreduce:
 
   case 9:
 #line 180 "parse-gram.y"
-    { defines_flag = 1; }
+    { defines_flag = true; }
     break;
 
   case 10:
 #line 181 "parse-gram.y"
-    { error_verbose = 1; }
+    { error_verbose = true; }
     break;
 
   case 11:
@@ -1304,7 +1304,7 @@ yyreduce:
 
   case 15:
 #line 187 "parse-gram.y"
-    { locations_flag = 1; }
+    { locations_flag = true; }
     break;
 
   case 16:
@@ -1314,7 +1314,7 @@ yyreduce:
 
   case 17:
 #line 189 "parse-gram.y"
-    { no_lines_flag = 1; }
+    { no_lines_flag = true; }
     break;
 
   case 18:
@@ -1344,7 +1344,7 @@ yyreduce:
 
   case 23:
 #line 195 "parse-gram.y"
-    { token_table_flag = 1; }
+    { token_table_flag = true; }
     break;
 
   case 24:
@@ -1354,7 +1354,7 @@ yyreduce:
 
   case 25:
 #line 197 "parse-gram.y"
-    { yacc_flag = 1; }
+    { yacc_flag = true; }
     break;
 
   case 29:
@@ -1367,7 +1367,7 @@ yyreduce:
   case 30:
 #line 209 "parse-gram.y"
     {
-      typed = 1;
+      typed = true;
       MUSCLE_INSERT_INT ("stype_line", yylsp[0].start.line);
       muscle_insert ("stype", yyvsp[0].chars);
     }
