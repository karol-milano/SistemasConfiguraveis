@@ -614,7 +614,7 @@ prepare (void)
   /* Find the right skeleton file.  */
   if (!skeleton)
     {
-      if (glr_parser)
+      if (glr_parser || nondeterministic_parser)
 	skeleton = "glr.c";
       else
 	skeleton = "yacc.c";
