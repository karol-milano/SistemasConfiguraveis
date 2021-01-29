@@ -318,7 +318,7 @@ type_names_output (FILE *out)
   fputs ("m4_define([b4_type_names],\n[", out);
   for (i = 0; i < nsyms; /* nothing */)
     {
-      // The index of the first symbol of the current type-name.
+      /* The index of the first symbol of the current type-name.  */
       int i0 = i;
       fputs (i ? ",\n[" : "[", out);
       for (; i < nsyms && syms[i]->type_name == syms[i0]->type_name; ++i)
@@ -415,16 +415,16 @@ prepare_symbol_definitions (void)
                       i, Entry, Suffix);                        \
       key = obstack_finish0 (&format_obstack);
 
-      // Whether the symbol has an identifier.
+      /* Whether the symbol has an identifier.  */
       value = symbol_id_get (sym);
       SET_KEY("has_id");
       MUSCLE_INSERT_INT (key, !!value);
 
-      // Its identifier.
+      /* Its identifier.  */
       SET_KEY("id");
       MUSCLE_INSERT_STRING (key, value ? value : "");
 
-      // Its tag.  Typically for documentation purpose.
+      /* Its tag.  Typically for documentation purpose.  */
       SET_KEY("tag");
       MUSCLE_INSERT_STRING (key, sym->tag);
 
@@ -533,7 +533,7 @@ muscles_output (FILE *out)
   symbol_numbers_output (out);
   type_names_output (out);
   user_actions_output (out);
-  // Must be last.
+  /* Must be last.  */
   muscles_m4_output (out);
 }
 
