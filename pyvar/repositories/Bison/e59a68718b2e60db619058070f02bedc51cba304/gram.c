@@ -329,9 +329,9 @@ grammar_rules_never_reduced_report (const char *message)
 void
 grammar_free (void)
 {
-  free (ritem);
+  XFREE (ritem);
   free (rules);
-  free (token_translations);
+  XFREE (token_translations);
   /* Free the symbol table data structure.  */
   symbols_free ();
   free_merger_functions ();
