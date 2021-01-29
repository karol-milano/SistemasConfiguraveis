@@ -159,3 +159,14 @@ grammar_dump (FILE *out, const char *title)
     }
   fprintf (out, "\n\n");
 }
+
+
+void
+grammar_free (void)
+{
+  XFREE (ritem);
+  free (rules + 1);
+  XFREE (token_translations);
+  /* Free the symbol table data structure.  */
+  symbols_free ();
+}
