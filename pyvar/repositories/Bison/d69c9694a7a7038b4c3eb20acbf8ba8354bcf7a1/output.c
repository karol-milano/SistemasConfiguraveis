@@ -143,6 +143,7 @@ prepare_symbols (void)
   MUSCLE_INSERT_BOOL ("token_table", token_table_flag);
   MUSCLE_INSERT_INT ("tokens_number", ntokens);
   MUSCLE_INSERT_INT ("nterms_number", nvars);
+  MUSCLE_INSERT_INT ("symbols_number", nsyms);
   MUSCLE_INSERT_INT ("undef_token_number", undeftoken->number);
   MUSCLE_INSERT_INT ("user_token_number_max", max_user_token_number);
 
@@ -283,26 +284,17 @@ prepare_states (void)
 
 
 
-/*-----------------------------------------------.
-| For each symbol type, its tags and type name.  |
-`-----------------------------------------------*/
+/*-------------------------------------.
+| The list of all the symbol numbers.  |
+`-------------------------------------*/
 
 static void
-type_names_output (FILE *out)
+symbol_numbers_output (FILE *out)
 {
   int i;
-
-  fputs ("m4_define([b4_type_names],\n[", out);
+  fputs ("m4_define([b4_symbol_numbers],\n[", out);
   for (i = 0; i < nsyms; ++i)
-    {
-      symbol *sym = symbols[i];
-      /* Symbol-name, Symbol-number, optional typename.  */
-      fprintf (out, "%s[", i ? ",\n" : "");
-      escaped_output (out, sym->tag);
-      fprintf (out, ", %d, [[%s]]]",
-               sym->number,
-               sym->type_name ? sym->type_name : "");
-    }
+    fprintf (out, "%s[%d]", i ? ", " : "", i);
   fputs ("])\n\n", out);
 }
 
@@ -351,6 +343,42 @@ merger_output (FILE *out)
   fputs ("]])\n\n", out);
 }
 
+
+/*---------------------------------------.
+| Output the symbol definitions to OUT.  |
+`---------------------------------------*/
+
+static void
+symbol_definitions_output (FILE *out)
+{
+  int i;
+  for (i = 0; i < nsyms; ++i)
+    {
+      symbol *sym = symbols[i];
+      const char *key;
+
+#define SET_KEY(Entry)                                                  \
+      obstack_fgrow2 (&format_obstack, "symbol(%d, %s)", i, Entry);     \
+      obstack_1grow (&format_obstack, 0);                               \
+      key = obstack_finish (&format_obstack);
+
+      SET_KEY("tag");
+      MUSCLE_INSERT_STRING (key, sym->tag);
+
+      SET_KEY("user_number");
+      MUSCLE_INSERT_INT (key, sym->user_token_number);
+
+      SET_KEY("number");
+      MUSCLE_INSERT_INT (key, sym->number);
+
+      SET_KEY("type_name");
+      MUSCLE_INSERT_STRING (key, sym->type_name ? sym->type_name : "");
+
+#undef SET_KEY
+    }
+}
+
+
 /*--------------------------------------.
 | Output the tokens definition to OUT.  |
 `--------------------------------------*/
@@ -496,12 +524,13 @@ muscles_output (FILE *out)
 {
   fputs ("m4_init()\n", out);
 
-  type_names_output (out);
-  user_actions_output (out);
   merger_output (out);
-  token_definitions_output (out);
   symbol_code_props_output (out, "destructors", &symbol_destructor_get);
   symbol_code_props_output (out, "printers", &symbol_printer_get);
+  symbol_definitions_output (out);
+  symbol_numbers_output (out);
+  token_definitions_output (out);
+  user_actions_output (out);
 
   muscles_m4_output (out);
 }
