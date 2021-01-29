@@ -232,7 +232,7 @@ open_files (void)
 
       static char FIXED_NAME_BASE[] = "y.y";
 
-      name_base = fixed_outfiles ? FIXED_NAME_BASE : infile;
+      name_base = yaccflag ? FIXED_NAME_BASE : infile;
 
       /* BASE_LENGTH gets length of NAME_BASE, sans ".y" suffix if any.  */
 
