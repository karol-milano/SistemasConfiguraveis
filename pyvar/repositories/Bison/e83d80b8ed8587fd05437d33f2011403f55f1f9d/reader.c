@@ -437,14 +437,12 @@ copy_definition (void)
   /* -1 while reading a character if prev char was %. */
   int after_percent;
 
-#if 0
   if (!no_lines_flag)
     {
       obstack_fgrow2 (&attrs_obstack, muscle_find ("linef"),
 		      lineno, quotearg_style (c_quoting_style,
 					      muscle_find("filename")));
     }
-#endif
 
   after_percent = 0;
 
