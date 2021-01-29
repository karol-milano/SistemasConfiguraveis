@@ -639,6 +639,39 @@ symbol_destructors_output (FILE *out)
 }
 
 
+/*-------------------------------------.
+| Output the symbol printers to OOUT.  |
+`-------------------------------------*/
+
+static void
+symbol_printers_output (FILE *out)
+{
+  int i;
+  int first = 1;
+
+  fputs ("m4_define([b4_symbol_printers], \n[", out);
+  for (i = 0; i < nsyms; ++i)
+    if (symbols[i]->destructor)
+      {
+	symbol_t *symbol = symbols[i];
+
+	/* Filename, lineno,
+	   Symbol-name, Symbol-number,
+	   destructor, typename. */
+	fprintf (out, "%s[[[%s]], [[%d]], [[%s]], [[%d]], [[%s]], [[%s]]]",
+		 first ? "" : ",\n",
+		 infile, symbol->printer_location.first_line,
+		 symbol_tag_get (symbol),
+		 symbol->number,
+		 symbol->printer,
+		 symbol->type_name);
+
+	first = 0;
+      }
+  fputs ("])\n\n", out);
+}
+
+
 static void
 save_column (int symbol, int default_state)
 {
@@ -1053,6 +1086,7 @@ output_skeleton (void)
   actions_output (out);
   token_definitions_output (out);
   symbol_destructors_output (out);
+  symbol_printers_output (out);
 
   muscles_m4_output (out);
 
