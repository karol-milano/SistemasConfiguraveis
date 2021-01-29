@@ -190,8 +190,10 @@ output_gram (void)
     XFREE (yyrhs);
   }
 
-  /* if (!semantic_parser && !no_parser_flag)
-     obstack_sgrow (&table_obstack, "\n#endif\n"); */
+#if 0
+  if (!semantic_parser && !no_parser_flag)
+    obstack_sgrow (&table_obstack, "\n#endif\n");
+#endif
 }
 
 
@@ -938,12 +940,10 @@ output_actions (void)
 
   sort_actions ();
   pack_table ();
-  /* FIXME: See if this is useful. */
-  /* obstack_1grow (&table_obstack, '\n'); */
+
   output_base ();
   output_table ();
-  /* FIXME: See if this is useful. */
-  /* obstack_1grow (&table_obstack, '\n'); */
+
   output_check ();
 }
 
