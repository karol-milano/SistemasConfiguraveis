@@ -92,3 +92,26 @@ muscle_find (const char *key)
   muscle_entry_t *result = hash_lookup (muscle_table, &pair);
   return result ? result->value : NULL;
 }
+
+
+/* Output the definition of all the current muscles into a list of
+   m4_defines.  */
+
+static void
+muscle_m4_output (muscle_entry_t *entry, FILE *out)
+{
+  fprintf (out, "m4_define([b4_%s],\n", entry->key);
+  fprintf (out, "          [[%s]])\n\n\n", entry->value);
+}
+
+
+/* Output the definition of all the current muscles into a list of
+   m4_defines.  */
+
+void
+muscles_m4_output (FILE *out)
+{
+  hash_do_for_each (muscle_table,
+		    (Hash_processor) muscle_m4_output,
+		    out);
+}
