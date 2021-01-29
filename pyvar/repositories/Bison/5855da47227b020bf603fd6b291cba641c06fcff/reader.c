@@ -710,6 +710,7 @@ reader (const char *gram)
   symbols_new ();
 
   gram_scanner_open (gram);
+  parser_init ();
   gram_parse ();
   gram_scanner_close ();
 
