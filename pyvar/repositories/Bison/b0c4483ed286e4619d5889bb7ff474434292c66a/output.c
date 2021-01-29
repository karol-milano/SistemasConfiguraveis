@@ -1087,9 +1087,6 @@ output (void)
 {
   obstack_init (&output_obstack);
 
-#if 0
-  reader_output_yylsp (&table_obstack); */
-#endif
   free_itemsets ();
 
   output_token_translations ();
