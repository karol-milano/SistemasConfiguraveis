@@ -1140,7 +1140,7 @@ prepare (void)
 
   /* Find the right skeleton file.  */
   if (!skeleton)
-    skeleton = "bison.simple";
+    skeleton = "yacc.c";
 
   /* Parse the skeleton file and output the needed parsers.  */
   muscle_insert ("skeleton", skeleton);
