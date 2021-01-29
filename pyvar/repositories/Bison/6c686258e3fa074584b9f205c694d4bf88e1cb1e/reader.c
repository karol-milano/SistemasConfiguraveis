@@ -2043,10 +2043,6 @@ reader (void)
      TABLE_OBSTACK and FDEFINES file.  Also notice any %token, %left,
      etc. found there.  */
   read_declarations ();
-  /* Start writing the guard and action files, if they are needed.  */
-#if 0
-  output_headers ();
-#endif
   /* Read in the grammar, build grammar in list form.  Write out
      guards and actions.  */
   readgram ();
@@ -2060,7 +2056,6 @@ reader (void)
 #endif
   /* Write closing delimiters for actions and guards.  */
 #if 0
-  output_trailers (); 
   if (locations_flag)
     obstack_sgrow (&table_obstack, "#define YYLSP_NEEDED 1\n\n");
 #endif
