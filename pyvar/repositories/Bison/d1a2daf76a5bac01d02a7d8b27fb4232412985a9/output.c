@@ -1105,16 +1105,6 @@ output (void)
 {
   obstack_init (&output_obstack);
 
-#if 0
-  /* If using a simple parser the definition of YYSTYPE are put into
-     TABLE_OBSTACK.  */
-  if (!semantic_parser)
-    {
-      size_t size = obstack_object_size (&attrs_obstack);
-      obstack_grow (&table_obstack, obstack_finish (&attrs_obstack), size);
-    }
-#endif
-
   /* reader_output_yylsp (&table_obstack); */
   free_itemsets ();
 
@@ -1129,6 +1119,8 @@ output (void)
 
   /* if (!no_parser_flag) */
   prepare ();
+  /* Copy definitions in directive.  */
+  macro_insert ("definitions", obstack_finish (&attrs_obstack));
   output_parser ();
   output_program ();
 
