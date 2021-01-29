@@ -204,7 +204,7 @@ output_gram (void)
     yyrhs = XMALLOC (short, yyrhs_size);
 
     for (sp = ritem + 1, i = 1; *sp; ++sp, ++i)
-      yyrhs[i] = *sp > 0 ? *sp : 0;
+      yyrhs[i] = *sp >= 0 ? *sp : 0;
 
     output_table_data (&format_obstack, yyrhs,
 		       ritem[0], 1, yyrhs_size);
