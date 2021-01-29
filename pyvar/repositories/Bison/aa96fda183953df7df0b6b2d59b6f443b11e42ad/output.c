@@ -192,7 +192,7 @@ output_gram (void)
   {
     int i;
     short *values = XCALLOC (short, nrules + 1);
-    for (i = 0; i < nrules + 1; ++i)
+    for (i = 1; i < nrules + 1; ++i)
       values[i] = rules[i].rhs - ritem;
     output_table_data (&format_obstack, values,
 		       0, 1, nrules + 1);
@@ -246,7 +246,7 @@ output_rule_data (void)
 
   {
     short *values = XCALLOC (short, nrules + 1);
-    for (i = 0; i < nrules + 1; ++i)
+    for (i = 1; i < nrules + 1; ++i)
       values[i] = rules[i].line;
     output_table_data (&format_obstack, values,
 		       0, 1, nrules + 1);
@@ -299,7 +299,7 @@ output_rule_data (void)
   /* Output YYR1. */
   {
     short *values = XCALLOC (short, nrules + 1);
-    for (i = 0; i < nrules + 1; ++i)
+    for (i = 1; i < nrules + 1; ++i)
       values[i] = rules[i].lhs;
     output_table_data (&format_obstack, values,
 		       0, 1, nrules + 1);
