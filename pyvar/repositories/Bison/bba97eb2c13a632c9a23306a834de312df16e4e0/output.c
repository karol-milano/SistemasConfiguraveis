@@ -300,7 +300,7 @@ output_rule_data (void)
   {
     short *values = XCALLOC (short, nrules + 1);
     for (i = 1; i < nrules + 1; ++i)
-      values[i] = rules[i].lhs;
+      values[i] = rules[i].lhs->number;
     output_table_data (&format_obstack, values,
 		       0, 1, nrules + 1);
     muscle_insert ("r1", obstack_finish (&format_obstack));
