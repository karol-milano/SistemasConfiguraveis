@@ -153,12 +153,20 @@ tr (char *s, char from, char to)
 static void
 compute_exts_from_gf (const char *ext)
 {
-  src_extension = xstrdup (ext);
-  header_extension = xstrdup (ext);
-  tr (src_extension, 'y', 'c');
-  tr (src_extension, 'Y', 'C');
-  tr (header_extension, 'y', 'h');
-  tr (header_extension, 'Y', 'H');
+  if (strcmp (ext, ".y") == 0)
+    {
+      src_extension = xstrdup (language->src_extension);
+      header_extension = xstrdup (language->header_extension);
+    }
+  else
+    {
+      src_extension = xstrdup (ext);
+      header_extension = xstrdup (ext);
+      tr (src_extension, 'y', 'c');
+      tr (src_extension, 'Y', 'C');
+      tr (header_extension, 'y', 'h');
+      tr (header_extension, 'Y', 'H');
+    }
 }
 
 /* Compute extensions from the given c source file extension.  */
@@ -281,7 +289,10 @@ compute_file_name_parts (void)
 	    xstrndup (base, (strlen (base) - (ext ? strlen (ext) : 0)));
 	}
 
-      all_but_ext = concat2 (all_but_tab_ext, TAB_EXT);
+      if (language->add_tab)
+        all_but_ext = concat2 (all_but_tab_ext, TAB_EXT);
+      else
+        all_but_ext = xstrdup (all_but_tab_ext);
 
       /* Compute the extensions from the grammar file name.  */
       if (ext && !yacc_flag)
