@@ -2073,7 +2073,6 @@ reader (void)
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
-  symbols_output ();
   /* Convert the grammar into the format described in gram.h.  */
   packgram ();
   /* Output the headers. */
