@@ -92,7 +92,7 @@ goto_print (goto_number i, FILE *out)
   const state_number dst = to_state[i];
   symbol_number var = states[dst]->accessing_symbol;
   fprintf (out,
-           "goto[%ld] = (%d, %s, %d)", i, src, symbols[var]->tag, dst);
+           "goto[%zu] = (%d, %s, %d)", i, src, symbols[var]->tag, dst);
 }
 
 void
