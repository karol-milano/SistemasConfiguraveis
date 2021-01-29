@@ -193,7 +193,7 @@ output_gram (void)
     int i;
     short *values = XCALLOC (short, nrules + 1);
     for (i = 0; i < nrules + 1; ++i)
-      values[i] = rules[i].rhs;
+      values[i] = rules[i].rhs - ritem;
     output_table_data (&format_obstack, values,
 		       0, 1, nrules + 1);
     XFREE (values);
@@ -311,7 +311,7 @@ output_rule_data (void)
   short_tab = XMALLOC (short, nrules + 1);
   for (i = 1; i < nrules; i++)
     short_tab[i] = rules[i + 1].rhs - rules[i].rhs - 1;
-  short_tab[nrules] =  nritems - rules[nrules].rhs - 1;
+  short_tab[nrules] =  nritems - (rules[nrules].rhs - ritem) - 1;
   output_table_data (&format_obstack, short_tab,
 		     0, 1, nrules + 1);
   muscle_insert ("r2", obstack_finish (&format_obstack));
