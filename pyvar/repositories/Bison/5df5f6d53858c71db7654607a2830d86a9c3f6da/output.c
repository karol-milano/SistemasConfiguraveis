@@ -208,6 +208,7 @@ Name (struct obstack *oout,						\
 }
 
 GENERATE_OUTPUT_TABLE(output_int_table, int)
+GENERATE_OUTPUT_TABLE(output_unsigned_int_table, unsigned int)
 GENERATE_OUTPUT_TABLE(output_short_table, short)
 GENERATE_OUTPUT_TABLE(output_token_number_table, token_number_t)
 GENERATE_OUTPUT_TABLE(output_item_number_table, item_number_t)
@@ -284,17 +285,17 @@ static void
 prepare_rules (void)
 {
   long int max;
-  item_number_t *rhsp;
   int r;
-  int i = 0;
+  unsigned int i = 0;
   item_number_t *rhs = XMALLOC (item_number_t, nritems);
-  short *prhs = XMALLOC (short, nrules + 1);
+  unsigned int *prhs = XMALLOC (unsigned int, nrules + 1);
+  unsigned int *rline = XMALLOC (unsigned int, nrules + 1);
   token_number_t *r1 = XMALLOC (token_number_t, nrules + 1);
-  short *r2 = XMALLOC (short, nrules + 1);
-  short *rline = XMALLOC (short, nrules + 1);
+  unsigned int *r2 = XMALLOC (unsigned int, nrules + 1);
 
   for (r = 1; r < nrules + 1; ++r)
     {
+      item_number_t *rhsp;
       /* Index of rule R in RHS. */
       prhs[r] = i;
       /* RHS of the rule R. */
@@ -311,24 +312,29 @@ prepare_rules (void)
     }
   assert (i == nritems);
 
-  max = output_int_table (&format_obstack, rhs, ritem[0], 1, nritems);
+  max = output_item_number_table (&format_obstack, rhs, ritem[0], 1, nritems);
   muscle_insert ("rhs", obstack_finish (&format_obstack));
-  MUSCLE_INSERT_LONG_INT ("rhs_number_max", max);
+  MUSCLE_INSERT_LONG_INT ("rhs_max", max);
 
-  output_short_table (&format_obstack, prhs, 0, 1, nrules + 1);
+  max = output_unsigned_int_table (&format_obstack, prhs, 0, 1, nrules + 1);
   muscle_insert ("prhs", obstack_finish (&format_obstack));
+  MUSCLE_INSERT_LONG_INT ("prhs_max", max);
 
-  output_short_table (&format_obstack, rline, 0, 1, nrules + 1);
+  max = output_unsigned_int_table (&format_obstack, rline, 0, 1, nrules + 1);
   muscle_insert ("rline", obstack_finish (&format_obstack));
+  MUSCLE_INSERT_LONG_INT ("rline_max", max);
 
   output_token_number_table (&format_obstack, r1, 0, 1, nrules + 1);
   muscle_insert ("r1", obstack_finish (&format_obstack));
 
-  output_short_table (&format_obstack, r2, 0, 1, nrules + 1);
+  max = output_unsigned_int_table (&format_obstack, r2, 0, 1, nrules + 1);
   muscle_insert ("r2", obstack_finish (&format_obstack));
+  MUSCLE_INSERT_LONG_INT ("r2_max", max);
 
   free (rhs);
   free (prhs);
+  free (rline);
+  free (r1);
   free (r2);
 }
 
