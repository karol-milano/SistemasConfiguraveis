@@ -326,9 +326,9 @@ grammar_rules_never_reduced_report (const char *message)
 void
 grammar_free (void)
 {
-  XFREE (ritem);
+  free (ritem);
   free (rules);
-  XFREE (token_translations);
+  free (token_translations);
   /* Free the symbol table data structure.  */
   symbols_free ();
   free_merger_functions ();
