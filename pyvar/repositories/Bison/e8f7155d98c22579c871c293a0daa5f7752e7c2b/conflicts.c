@@ -303,16 +303,19 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
               break;
 
             case right_assoc:
+              register_assoc (i, redrule->prec->number);
               log_resolution (redrule, i, right_resolution);
               flush_reduce (lookahead_tokens, i);
               break;
 
             case left_assoc:
+              register_assoc (i, redrule->prec->number);
               log_resolution (redrule, i, left_resolution);
               flush_shift (s, i);
               break;
 
             case non_assoc:
+              register_assoc (i, redrule->prec->number);
               log_resolution (redrule, i, nonassoc_resolution);
               flush_shift (s, i);
               flush_reduce (lookahead_tokens, i);
