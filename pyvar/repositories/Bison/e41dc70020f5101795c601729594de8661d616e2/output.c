@@ -225,9 +225,16 @@ output_rule_data (void)
   int j;
   short *short_tab = NULL;
 
-  output_table_data (&output_obstack, rline,
-		     0, 1, nrules + 1);
-  muscle_insert ("rline", obstack_finish (&output_obstack));
+  {
+    short *values = XCALLOC (short, nrules + 1);
+    for (i = 0; i < nrules + 1; ++i)
+      values[i] = rule_table[i].line;
+    output_table_data (&output_obstack, values,
+		       0, 1, nrules + 1);
+    muscle_insert ("rline", obstack_finish (&output_obstack));
+    XFREE (values);
+  }
+
 
   j = 0;
   for (i = 0; i < nsyms; i++)
