@@ -630,7 +630,8 @@ check_and_convert_grammar (void)
   symbols_pack ();
 
   /* Convert the grammar into the format described in gram.h.  */
-  packgram ();
+  if (!complaint_issued)
+    packgram ();
 
   /* The grammar as a symbol_list is no longer needed. */
   LIST_FREE (symbol_list, grammar);
