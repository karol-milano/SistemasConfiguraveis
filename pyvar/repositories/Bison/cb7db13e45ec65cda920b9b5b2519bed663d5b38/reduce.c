@@ -142,12 +142,13 @@ reduce_grammar (void)
 	   tags[start_symbol]);
 
   reduce_grammar_tables();
-  /* if (verboseflag) {
-     fprintf(foutput, "REDUCED GRAMMAR\n\n");
-     dump_grammar();
-     }
-     */
-
+  /*
+  if (verboseflag)
+    {
+      fprintf(foutput, "REDUCED GRAMMAR\n\n");
+      dump_grammar();
+    }
+  */
   /**/ statisticsflag = FALSE; /* someday getopts should handle this */
   if (statisticsflag == TRUE)
     fprintf(stderr,
