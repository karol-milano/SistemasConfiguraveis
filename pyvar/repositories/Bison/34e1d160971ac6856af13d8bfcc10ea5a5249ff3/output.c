@@ -432,7 +432,7 @@ symbol_printers_output (FILE *out)
 
   fputs ("m4_define([b4_symbol_printers], \n[", out);
   for (i = 0; i < nsyms; ++i)
-    if (symbols[i]->destructor)
+    if (symbols[i]->printer)
       {
 	symbol *sym = symbols[i];
 
