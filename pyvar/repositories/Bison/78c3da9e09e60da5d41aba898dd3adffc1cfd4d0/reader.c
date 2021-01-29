@@ -469,8 +469,6 @@ packgram (void)
 void
 reader (void)
 {
-  gram_control_t gram_control;
-
   /* Initialize the symbol table.  */
   symbols_new ();
 
@@ -500,7 +498,7 @@ reader (void)
   gram__flex_debug = trace_flag & trace_scan;
   gram_debug = trace_flag & trace_parse;
   scanner_initialize ();
-  gram_parse (&gram_control);
+  gram_parse ();
 
   /* If something went wrong during the parsing, don't try to
      continue.  */
