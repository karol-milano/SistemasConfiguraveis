@@ -276,11 +276,13 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
            The precedence of shifting is that of token i.  */
         if (symbols[i]->prec < redprec)
           {
+            register_precedence (redrule->prec->number, i);
             log_resolution (redrule, i, reduce_resolution);
             flush_shift (s, i);
           }
         else if (symbols[i]->prec > redprec)
           {
+            register_precedence (i, redrule->prec->number);
             log_resolution (redrule, i, shift_resolution);
             flush_reduce (lookahead_tokens, i);
           }
