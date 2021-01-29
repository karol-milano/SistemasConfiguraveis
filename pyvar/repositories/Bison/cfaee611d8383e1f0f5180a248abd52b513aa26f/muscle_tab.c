@@ -97,11 +97,12 @@ muscle_find (const char *key)
 /* Output the definition of all the current muscles into a list of
    m4_defines.  */
 
-static void
+static int
 muscle_m4_output (muscle_entry_t *entry, FILE *out)
 {
   fprintf (out, "m4_define([b4_%s],\n", entry->key);
   fprintf (out, "          [[%s]])\n\n\n", entry->value);
+  return 1;
 }
 
 
