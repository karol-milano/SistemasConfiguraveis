@@ -373,41 +373,70 @@ token_definitions_output (FILE *out)
 }
 
 
-/*----------------------------------------------------.
-| Output the symbol destructors and printers to OUT.  |
-`----------------------------------------------------*/
+/*---------------------------------------.
+| Output the symbol destructors to OUT.  |
+`---------------------------------------*/
 
 static void
-symbol_code_props_output (FILE *out, char const *what,
-                          code_props (*get)(symbol *))
+symbol_destructors_output (FILE *out)
 {
   int i;
   char const *sep = "";
 
-  fputs ("m4_define([b4_symbol_", out);
-  fputs (what, out);
-  fputs ("], \n[", out);
+  fputs ("m4_define([b4_symbol_destructors], \n[", out);
   for (i = 0; i < nsyms; ++i)
-    {
-      symbol *sym = symbols[i];
-      char const *code = code_props_code_get ((*get) (sym));
-      if (code)
-        {
-          location loc = code_props_location_get ((*get) (sym));
-          /* Filename, lineno,
-             Symbol-name, Symbol-number,
-             code, optional typename.  */
-          fprintf (out, "%s[", sep);
-          sep = ",\n";
-          escaped_output (out, loc.start.file);
-          fprintf (out, ", %d, ", loc.start.line);
-          escaped_output (out, sym->tag);
-          fprintf (out, ", %d, [[%s]]", sym->number, code);
-          if (sym->type_name)
-            fprintf (out, ", [[%s]]", sym->type_name);
-          fputc (']', out);
-        }
-    }
+    if (symbol_destructor_get (symbols[i]))
+      {
+	symbol *sym = symbols[i];
+
+	/* Filename, lineno,
+	   Symbol-name, Symbol-number,
+	   destructor, optional typename.  */
+	fprintf (out, "%s[", sep);
+	sep = ",\n";
+	escaped_output (out, symbol_destructor_location_get (sym).start.file);
+	fprintf (out, ", %d, ",
+		 symbol_destructor_location_get (sym).start.line);
+	escaped_output (out, sym->tag);
+	fprintf (out, ", %d, [[%s]]", sym->number,
+		 symbol_destructor_get (sym));
+	if (sym->type_name)
+	  fprintf (out, ", [[%s]]", sym->type_name);
+	fputc (']', out);
+      }
+  fputs ("])\n\n", out);
+}
+
+
+/*------------------------------------.
+| Output the symbol printers to OUT.  |
+`------------------------------------*/
+
+static void
+symbol_printers_output (FILE *out)
+{
+  int i;
+  char const *sep = "";
+
+  fputs ("m4_define([b4_symbol_printers], \n[", out);
+  for (i = 0; i < nsyms; ++i)
+    if (symbol_printer_get (symbols[i]))
+      {
+	symbol *sym = symbols[i];
+
+	/* Filename, lineno,
+	   Symbol-name, Symbol-number,
+	   printer, optional typename.  */
+	fprintf (out, "%s[", sep);
+	sep = ",\n";
+	escaped_output (out, symbol_printer_location_get (sym).start.file);
+	fprintf (out, ", %d, ", symbol_printer_location_get (sym).start.line);
+	escaped_output (out, sym->tag);
+	fprintf (out, ", %d, [[%s]]", sym->number, symbol_printer_get (sym));
+	if (sym->type_name)
+	  fprintf (out, ", [[%s]]", sym->type_name);
+	fputc (']', out);
+      }
   fputs ("])\n\n", out);
 }
 
@@ -532,8 +561,8 @@ output_skeleton (void)
   user_actions_output (out);
   merger_output (out);
   token_definitions_output (out);
-  symbol_code_props_output (out, "destructors", &symbol_destructor_get);
-  symbol_code_props_output (out, "printers", &symbol_printer_get);
+  symbol_destructors_output (out);
+  symbol_printers_output (out);
 
   muscles_m4_output (out);
 
