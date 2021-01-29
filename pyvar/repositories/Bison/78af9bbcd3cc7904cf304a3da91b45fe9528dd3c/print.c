@@ -318,7 +318,7 @@ print_results (void)
     {
       int i;
 
-      /* We used to use just .out if spec_name_prefix (-p) was used, but
+      /* We used to use just .out if SPEC_NAME_PREFIX (-p) was used, but
 	 that conflicts with Posix.  */
       FILE *out = xfopen (spec_verbose_file, "w");
 
