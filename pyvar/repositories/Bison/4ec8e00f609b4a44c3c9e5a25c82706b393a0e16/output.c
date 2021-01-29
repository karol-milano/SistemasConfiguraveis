@@ -197,6 +197,11 @@ output_gram (void)
 
     XFREE (yyrhs);
   }
+  
+#if 0
+  if (!semantic_parser)
+    obstack_sgrow (&table_obstack, "\n#endif\n");
+#endif
 }
 
 
