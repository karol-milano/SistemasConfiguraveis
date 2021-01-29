@@ -2008,22 +2008,26 @@ reader (void)
   /* Read the declaration section.  Copy %{ ... %} groups to
      TABLE_OBSTACK and FDEFINES file.  Also notice any %token, %left,
      etc. found there.  */
-  /* obstack_1grow (&table_obstack, '\n'); */
-
   read_declarations ();
   /* Start writing the guard and action files, if they are needed.  */
-  /* output_headers (); */
+#if 0
+  output_headers ();
+#endif
   /* Read in the grammar, build grammar in list form.  Write out
      guards and actions.  */
   readgram ();
   /* Now we know whether we need the line-number stack.  If we do,
      write its type into the .tab.h file.  */
-  /* if (defines_flag)
-     reader_output_yylsp (&defines_obstack); */
+#if 0
+  if (defines_flag)
+    reader_output_yylsp (&defines_obstack);
+#endif
   /* Write closing delimiters for actions and guards.  */
-  /* output_trailers (); */
-  /* if (locations_flag)
-     obstack_sgrow (&table_obstack, "#define YYLSP_NEEDED 1\n\n"); */
+#if 0
+  output_trailers (); 
+  if (locations_flag)
+    obstack_sgrow (&table_obstack, "#define YYLSP_NEEDED 1\n\n");
+#endif
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
