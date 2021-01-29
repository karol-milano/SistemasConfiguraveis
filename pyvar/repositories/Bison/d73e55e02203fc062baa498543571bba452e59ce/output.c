@@ -287,7 +287,7 @@ prepare_states (void)
 | Compare two symbols by type-name, and then by number.  |
 `-------------------------------------------------------*/
 
-int
+static int
 symbol_type_name_cmp (const symbol **lhs, const symbol **rhs)
 {
   int res = UNIQSTR_CMP((*lhs)->type_name, (*rhs)->type_name);
@@ -302,7 +302,7 @@ symbol_type_name_cmp (const symbol **lhs, const symbol **rhs)
 `----------------------------------------------------------------*/
 
 static symbol **
-symbols_by_type_name ()
+symbols_by_type_name (void)
 {
   typedef int (*qcmp_type) (const void *, const void *);
   symbol **res = xmemdup (symbols, nsyms * sizeof *res);
@@ -396,12 +396,12 @@ merger_output (FILE *out)
 }
 
 
-/*---------------------------------------.
-| Output the symbol definitions to OUT.  |
-`---------------------------------------*/
+/*---------------------------------------------.
+| Prepare the muscles for symbol definitions.  |
+`---------------------------------------------*/
 
 static void
-symbol_definitions_output (FILE *out)
+prepare_symbol_definitions (void)
 {
   int i;
   for (i = 0; i < nsyms; ++i)
@@ -596,7 +596,6 @@ muscles_output (FILE *out)
   merger_output (out);
   symbol_code_props_output (out, "destructors", &symbol_destructor_get);
   symbol_code_props_output (out, "printers", &symbol_printer_get);
-  symbol_definitions_output (out);
   symbol_numbers_output (out);
   token_definitions_output (out);
   type_names_output (out);
@@ -794,6 +793,7 @@ output (void)
   prepare_rules ();
   prepare_states ();
   prepare_actions ();
+  prepare_symbol_definitions ();
 
   prepare ();
 
