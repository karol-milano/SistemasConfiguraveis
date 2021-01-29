@@ -536,9 +536,6 @@ output_skeleton (void)
   symbol_code_props_output (out, "printers", &symbol_printer_get);
 
   muscles_m4_output (out);
-
-  fputs ("m4_wrap([m4_divert_pop(0)])\n", out);
-  fputs ("m4_divert_push(0)dnl\n", out);
   xfclose (out);
 
   /* Read and process m4's output.  */
