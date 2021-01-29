@@ -43,6 +43,7 @@ symbol_number_t *token_translations = NULL;
 
 int max_user_token_number = 256;
 
+int glr_parser = 0;
 int pure_parser = 0;
 
 
@@ -249,4 +250,5 @@ grammar_free (void)
   XFREE (token_translations);
   /* Free the symbol table data structure.  */
   symbols_free ();
+  free_merger_functions ();
 }
