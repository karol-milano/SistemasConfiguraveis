@@ -195,19 +195,16 @@ output_gram (void)
   muscle_insert ("prhs", obstack_finish (&format_obstack));
 
   {
-    size_t yyrhs_size = 1;
-    short *yyrhs, *sp;
+    short *yyrhs;
     int i;
 
-    for (sp = ritem + 1; *sp; sp++)
-      ++yyrhs_size;
-    yyrhs = XMALLOC (short, yyrhs_size);
+    yyrhs = XMALLOC (short, nritems);
 
-    for (sp = ritem + 1, i = 1; *sp; ++sp, ++i)
-      yyrhs[i] = *sp >= 0 ? *sp : 0;
+    for (i = 1; i < nritems; ++i)
+      yyrhs[i] = ritem[i] >= 0 ? ritem[i] : -1;
 
     output_table_data (&format_obstack, yyrhs,
-		       ritem[0], 1, yyrhs_size);
+		       ritem[0], 1, nritems);
     muscle_insert ("rhs", obstack_finish (&format_obstack));
 
     XFREE (yyrhs);
