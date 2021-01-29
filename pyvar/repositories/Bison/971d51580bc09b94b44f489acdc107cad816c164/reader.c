@@ -1904,11 +1904,6 @@ symbols_output (void)
     obstack_free (&tokendefs, NULL);
   }
 
-#if 0
-  if (!no_parser_flag)
-    output_token_defines (&table_obstack);
-#endif
-
   if (defines_flag)
     {
       output_token_defines (&defines_obstack);
