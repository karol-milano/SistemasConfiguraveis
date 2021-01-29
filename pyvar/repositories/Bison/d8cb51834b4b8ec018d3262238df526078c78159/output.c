@@ -1095,7 +1095,9 @@ output (void)
 {
   obstack_init (&output_obstack);
 
-  /* reader_output_yylsp (&table_obstack); */
+#if 0
+  reader_output_yylsp (&table_obstack); */
+#endif
   free_itemsets ();
 
   output_token_translations ();
@@ -1106,8 +1108,10 @@ output (void)
     output_stos ();
   output_rule_data ();
   output_actions ();
-
-  /* if (!no_parser_flag) */
+  
+#if 0
+  if (!no_parser_flag) */
+#endif
   prepare ();
   /* Copy definitions in directive.  */
   macro_insert ("definitions", obstack_finish (&attrs_obstack));
