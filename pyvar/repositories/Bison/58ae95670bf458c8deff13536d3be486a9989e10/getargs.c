@@ -686,8 +686,8 @@ getargs (int argc, char *argv[])
         defines_flag = true;
         if (optarg)
           {
-            free (spec_defines_file);
-            spec_defines_file = xstrdup (AS_FILE_NAME (optarg));
+            free (spec_header_file);
+            spec_header_file = xstrdup (AS_FILE_NAME (optarg));
           }
         break;
 
