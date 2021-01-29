@@ -504,45 +504,6 @@ token_definitions_output (FILE *out)
 }
 
 
-/*---------------------------------------------------.
-| Output the symbol destructors or printers to OUT.  |
-`---------------------------------------------------*/
-
-static void
-symbol_code_props_output (FILE *out, char const *what,
-                          code_props const *(*get)(symbol const *))
-{
-  int i;
-  char const *sep = "";
-
-  fputs ("m4_define([b4_symbol_", out);
-  fputs (what, out);
-  fputs ("], \n[", out);
-  for (i = 0; i < nsyms; ++i)
-    {
-      symbol *sym = symbols[i];
-      char const *code = (*get) (sym)->code;
-      if (code)
-        {
-          location loc = (*get) (sym)->location;
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
-  fputs ("])\n\n", out);
-}
-
-
 static void
 prepare_actions (void)
 {
@@ -600,8 +561,6 @@ muscles_output (FILE *out)
 {
   fputs ("m4_init()\n", out);
   merger_output (out);
-  symbol_code_props_output (out, "destructors", &symbol_destructor_get);
-  symbol_code_props_output (out, "printers", &symbol_printer_get);
   symbol_numbers_output (out);
   token_definitions_output (out);
   type_names_output (out);
