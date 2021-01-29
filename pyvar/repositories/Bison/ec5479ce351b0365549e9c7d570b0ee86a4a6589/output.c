@@ -390,7 +390,7 @@ symbol_destructors_output (FILE *out)
 
   fputs ("m4_define([b4_symbol_destructors], \n[", out);
   for (i = 0; i < nsyms; ++i)
-    if (symbols[i]->destructor)
+    if (symbol_destructor_get (symbols[i]))
       {
 	symbol *sym = symbols[i];
 
@@ -399,10 +399,12 @@ symbol_destructors_output (FILE *out)
 	   destructor, optional typename.  */
 	fprintf (out, "%s[", sep);
 	sep = ",\n";
-	escaped_output (out, sym->destructor_location.start.file);
-	fprintf (out, ", %d, ", sym->destructor_location.start.line);
+	escaped_output (out, symbol_destructor_location_get (sym).start.file);
+	fprintf (out, ", %d, ",
+		 symbol_destructor_location_get (sym).start.line);
 	escaped_output (out, sym->tag);
-	fprintf (out, ", %d, [[%s]]", sym->number, sym->destructor);
+	fprintf (out, ", %d, [[%s]]", sym->number,
+		 symbol_destructor_get (sym));
 	if (sym->type_name)
 	  fprintf (out, ", [[%s]]", sym->type_name);
 	fputc (']', out);
@@ -423,7 +425,7 @@ symbol_printers_output (FILE *out)
 
   fputs ("m4_define([b4_symbol_printers], \n[", out);
   for (i = 0; i < nsyms; ++i)
-    if (symbols[i]->printer)
+    if (symbol_printer_get (symbols[i]))
       {
 	symbol *sym = symbols[i];
 
@@ -432,10 +434,10 @@ symbol_printers_output (FILE *out)
 	   printer, optional typename.  */
 	fprintf (out, "%s[", sep);
 	sep = ",\n";
-	escaped_output (out, sym->printer_location.start.file);
-	fprintf (out, ", %d, ", sym->printer_location.start.line);
+	escaped_output (out, symbol_printer_location_get (sym).start.file);
+	fprintf (out, ", %d, ", symbol_printer_location_get (sym).start.line);
 	escaped_output (out, sym->tag);
-	fprintf (out, ", %d, [[%s]]", sym->number, sym->printer);
+	fprintf (out, ", %d, [[%s]]", sym->number, symbol_printer_get (sym));
 	if (sym->type_name)
 	  fprintf (out, ", [[%s]]", sym->type_name);
 	fputc (']', out);
