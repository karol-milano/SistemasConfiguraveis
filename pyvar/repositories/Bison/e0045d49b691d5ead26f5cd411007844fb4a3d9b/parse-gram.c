@@ -2273,6 +2273,6 @@ gram_error (location const *loc, char const *msg)
 char const *
 token_name (int type)
 {
-  return yytname[type];
+  return yytname[YYTRANSLATE (type)];
 }
 
