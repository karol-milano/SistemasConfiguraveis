@@ -215,10 +215,9 @@ file_name_split (const char *file_name,
   if (*ext)
     {
       size_t baselen = *ext - *base;
-      size_t dottablen = 4;
+      size_t dottablen = sizeof (TAB_EXT) - 1;
       if (dottablen < baselen
-          && (strncmp (*ext - dottablen, ".tab", dottablen) == 0
-              || strncmp (*ext - dottablen, "_tab", dottablen) == 0))
+          && STRPREFIX_LIT (TAB_EXT, *ext - dottablen))
         *tab = *ext - dottablen;
     }
 }
