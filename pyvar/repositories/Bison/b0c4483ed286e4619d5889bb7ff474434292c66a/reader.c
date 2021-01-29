@@ -2031,12 +2031,11 @@ reader (void)
   readgram ();
   /* Some C code is given at the end of the grammar file. */
   read_additionnal_code ();
+
   /* Now we know whether we need the line-number stack.  If we do,
-     write its type into the .tab.h file.  */
-#if 0
-  if (defines_flag)
-    reader_output_yylsp (&defines_obstack);
-#endif
+     write its type into the .tab.h file.
+     This is no longer need with header skeleton.  */
+
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
