@@ -294,7 +294,7 @@ output_rule_data (void)
   short_tab = XMALLOC (short, nrules + 1);
   for (i = 1; i < nrules; i++)
     short_tab[i] = rule_table[i + 1].rhs - rule_table[i].rhs - 1;
-  short_tab[nrules] =  nitems - rule_table[nrules].rhs - 1;
+  short_tab[nrules] =  nritems - rule_table[nrules].rhs - 1;
   output_table_data (&format_obstack, short_tab,
 		     0, 1, nrules + 1);
   muscle_insert ("r2", obstack_finish (&format_obstack));
