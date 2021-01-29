@@ -462,6 +462,23 @@ prepare_actions (void)
 				    0, 1, conflict_list_cnt);
 }
 
+/*--------------------------------------------.
+| Output the definitions of all the muscles.  |
+`--------------------------------------------*/
+
+static void
+muscles_output (FILE *out)
+{
+  fputs ("m4_init()\n", out);
+
+  user_actions_output (out);
+  merger_output (out);
+  token_definitions_output (out);
+  symbol_code_props_output (out, "destructors", &symbol_destructor_get);
+  symbol_code_props_output (out, "printers", &symbol_printer_get);
+
+  muscles_m4_output (out);
+}
 
 /*---------------------------.
 | Call the skeleton parser.  |
@@ -563,17 +580,7 @@ output_skeleton (void)
   if (! out)
     error (EXIT_FAILURE, get_errno (),
 	   "fdopen");
-
-  /* Output the definitions of all the muscles.  */
-  fputs ("m4_init()\n", out);
-
-  user_actions_output (out);
-  merger_output (out);
-  token_definitions_output (out);
-  symbol_code_props_output (out, "destructors", &symbol_destructor_get);
-  symbol_code_props_output (out, "printers", &symbol_printer_get);
-
-  muscles_m4_output (out);
+  muscles_output (out);
   xfclose (out);
 
   /* Read and process m4's output.  */
