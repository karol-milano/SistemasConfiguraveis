@@ -710,24 +710,20 @@ packgram (void)
 `------------------------------------------------------------------*/
 
 void
-reader (void)
+reader (const char *gram)
 {
   /* Set up symbol_table, semantic_type_table, and the built-in
      symbols.  */
   symbols_new ();
 
-  gram_in = xfopen (grammar_file, "r");
-
-  gram__flex_debug = trace_flag & trace_scan;
-  gram_debug = trace_flag & trace_parse;
-  gram_scanner_initialize ();
+  gram_scanner_open (gram);
   gram_parse ();
+  gram_scanner_close ();
+
   prepare_percent_define_front_end_variables ();
 
   if (complaint_status  < status_complaint)
     check_and_convert_grammar ();
-
-  xfclose (gram_in);
 }
 
 static void
