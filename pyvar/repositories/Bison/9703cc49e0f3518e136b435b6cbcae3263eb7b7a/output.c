@@ -200,7 +200,11 @@ output_gram (void)
 static void
 output_stos (void)
 {
-  output_table_data (&output_obstack, accessing_symbol,
+  int i;
+  short *values = (short *) alloca (sizeof (short) * nstates);
+  for (i = 0; i < nstates; ++i)
+    values[i] = state_table[i].accessing_symbol;
+  output_table_data (&output_obstack, values,
 		     0, 1, nstates);
   muscle_insert ("stos", obstack_finish (&output_obstack));
 }
@@ -389,7 +393,7 @@ action_row (int state)
 	  if (!shift_state)
 	    continue;
 
-	  symbol = accessing_symbol[shift_state];
+	  symbol = state_table[shift_state].accessing_symbol;
 
 	  if (ISVAR (symbol))
 	    break;
@@ -931,7 +935,6 @@ output_actions (void)
   XFREE (lookaheads);
   XFREE (LA);
   XFREE (LAruleno);
-  XFREE (accessing_symbol);
 
   goto_actions ();
   XFREE (goto_map + ntokens);
@@ -945,6 +948,7 @@ output_actions (void)
   output_table ();
 
   output_check ();
+  XFREE (state_table);
 }
 
 
@@ -1030,9 +1034,6 @@ static void
 free_itemsets (void)
 {
   core *cp, *cptmp;
-
-  XFREE (state_table);
-
   for (cp = first_state; cp; cp = cptmp)
     {
       cptmp = cp->next;
