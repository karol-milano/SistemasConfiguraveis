@@ -1867,4 +1867,7 @@ reader (void)
 
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
+
+  /* The grammar as a symbol_list is no longer needed. */
+  LIST_FREE (symbol_list, grammar);
 }
