@@ -252,7 +252,7 @@ open_files (void)
   if (verbose_flag)
     /* We used to use just .out if spec_name_prefix (-p) was used, but
        that conflicts with Posix.  */
-    foutput = xfopen (stringappend (base_name, EXT_OUTPUT), "w");
+    foutput = xfopen (stringappend (short_base_name, EXT_OUTPUT), "w");
 
   attrsfile = stringappend (short_base_name, EXT_STYPE_H);
 
