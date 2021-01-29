@@ -2041,4 +2041,6 @@ reader (void)
   symbols_output ();
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
+  /* Output the headers. */
+  symbols_output ();
 }
