@@ -222,7 +222,7 @@ output_stos (void)
   int i;
   short *values = (short *) alloca (sizeof (short) * nstates);
   for (i = 0; i < nstates; ++i)
-    values[i] = state_table[i]->accessing_symbol;
+    values[i] = states[i]->accessing_symbol;
   output_table_data (&format_obstack, values,
 		     0, 1, nstates);
   muscle_insert ("stos", obstack_finish (&format_obstack));
@@ -362,7 +362,7 @@ action_row (state_t *state)
       if (!shift_state)
 	continue;
 
-      symbol = state_table[shift_state]->accessing_symbol;
+      symbol = states[shift_state]->accessing_symbol;
 
       if (ISVAR (symbol))
 	break;
@@ -486,7 +486,7 @@ token_actions (void)
   actrow = XCALLOC (short, ntokens);
   for (i = 0; i < nstates; ++i)
     {
-      yydefact[i] = action_row (state_table[i]);
+      yydefact[i] = action_row (states[i]);
       save_row (i);
     }
 
@@ -904,12 +904,12 @@ output_actions (void)
 
   for (i = 0; i < nstates; ++i)
     {
-      free (state_table[i]->shifts);
-      XFREE (state_table[i]->reductions);
-      free (state_table[i]->errs);
-      free (state_table[i]);
+      free (states[i]->shifts);
+      XFREE (states[i]->reductions);
+      free (states[i]->errs);
+      free (states[i]);
     }
-  XFREE (state_table);
+  XFREE (states);
 }
 
 
