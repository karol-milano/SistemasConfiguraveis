@@ -3057,7 +3057,7 @@ add_param (param_type type, char *decl, location loc)
       --p;
     p[1] = '\0';
     ++decl;
-  while (c_isspace ((unsigned char) *decl))
+    while (c_isspace ((unsigned char) *decl))
       ++decl;
   }
 
