@@ -606,6 +606,33 @@ token_definitions_output (FILE *out)
 }
 
 
+/*----------------------------------------.
+| Output the symbol destructors to OOUT.  |
+`----------------------------------------*/
+
+static void
+symbol_destructors_output (FILE *out)
+{
+  int i;
+  int first = 1;
+
+  fputs ("m4_define([b4_symbol_destructors], \n[", out);
+  for (i = 0; i < nsyms; ++i)
+    if (symbols[i]->destructor)
+      {
+	symbol_t *symbol = symbols[i];
+
+	/* Symbol-number, destructor. */
+	fprintf (out, "%s[[[%d]], [[%s]], [[%s]]]",
+		 first ? "" : ",\n",
+		 symbol->number, symbol->destructor, symbol->type_name);
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
@@ -1019,6 +1046,7 @@ output_skeleton (void)
 
   actions_output (out);
   token_definitions_output (out);
+  symbol_destructors_output (out);
 
   muscles_m4_output (out);
 
