@@ -167,8 +167,16 @@ output_token_translations (void)
 static void
 output_gram (void)
 {
-  output_table_data (&output_obstack, rrhs,
-		     0, 1, nrules + 1);
+  {
+    int i;
+    short *values = XCALLOC (short, nrules + 1);
+    for (i = 0; i < nrules + 1; ++i)
+      values[i] = rule_table[i].rhs;
+    output_table_data (&output_obstack, values,
+		       0, 1, nrules + 1);
+    XFREE (values);
+  }
+
   muscle_insert ("prhs", obstack_finish (&output_obstack));
 
   {
@@ -279,22 +287,27 @@ output_rule_data (void)
   muscle_insert ("toknum", obstack_finish (&output_obstack));
 
   /* Output YYR1. */
-  output_table_data (&output_obstack, rlhs,
-		     0, 1, nrules + 1);
-  muscle_insert ("r1", obstack_finish (&output_obstack));
-  XFREE (rlhs + 1);
+  {
+    short *values = XCALLOC (short, nrules + 1);
+    for (i = 0; i < nrules + 1; ++i)
+      values[i] = rule_table[i].lhs;
+    output_table_data (&output_obstack, values,
+		       0, 1, nrules + 1);
+    muscle_insert ("r1", obstack_finish (&output_obstack));
+    XFREE (values);
+  }
 
   /* Output YYR2. */
   short_tab = XMALLOC (short, nrules + 1);
   for (i = 1; i < nrules; i++)
-    short_tab[i] = rrhs[i + 1] - rrhs[i] - 1;
-  short_tab[nrules] = nitems - rrhs[nrules] - 1;
+    short_tab[i] = rule_table[i + 1].rhs - rule_table[i].rhs - 1;
+  short_tab[nrules] =  nitems - rule_table[nrules].rhs - 1;
   output_table_data (&output_obstack, short_tab,
 		     0, 1, nrules + 1);
   muscle_insert ("r2", obstack_finish (&output_obstack));
   XFREE (short_tab);
 
-  XFREE (rrhs + 1);
+  XFREE (rule_table + 1);
 }
 
 /*------------------------------------------------------------------.
