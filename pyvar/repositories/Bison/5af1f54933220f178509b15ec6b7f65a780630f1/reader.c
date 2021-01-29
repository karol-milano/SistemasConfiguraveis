@@ -1975,7 +1975,7 @@ reader (void)
   /* Write closing delimiters for actions and guards.  */
   output_trailers ();
   if (locations_flag)
-    obstack_grow_literal_string (&table_obstack, "#define YYLSP_NEEDED\n\n");
+    obstack_grow_literal_string (&table_obstack, "#define YYLSP_NEEDED 1\n\n");
   /* Assign the symbols their symbol numbers.  Write #defines for the
      token symbols into FDEFINES if requested.  */
   packsymbols ();
