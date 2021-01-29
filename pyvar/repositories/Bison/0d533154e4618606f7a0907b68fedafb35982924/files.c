@@ -361,8 +361,10 @@ openfiles (void)
 
 
 
-/* open the output files needed only for the semantic parser.
-This is done when %semantic_parser is seen in the declarations section.  */
+/*--------------------------------------------------------------------.
+| Open the output files needed only for the semantic parser.  This    |
+| is done when %semantic_parser is seen in the declarations section.  |
+`--------------------------------------------------------------------*/
 
 void
 open_extra_files (void)
