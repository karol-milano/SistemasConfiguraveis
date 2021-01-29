@@ -205,7 +205,7 @@ file_name_split (const char *file_name,
   *base = last_component (file_name);
 
   /* Look for the extension, i.e., look for the last dot. */
-  *ext = strrchr (*base, '.');
+  *ext = mbsrchr (*base, '.');
   *tab = NULL;
 
   /* If there is an extension, check if there is a `.tab' part right
