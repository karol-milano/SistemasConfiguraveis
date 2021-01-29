@@ -1871,12 +1871,3 @@ reader (void)
   /* The grammar as a symbol_list is no longer needed. */
   LIST_FREE (symbol_list, grammar);
 }
-
-void
-grammar_free (void)
-{
-  XFREE (ritem);
-  free (rules + 1);
-  /* Free the symbol table data structure.  */
-  symbols_free ();
-}
