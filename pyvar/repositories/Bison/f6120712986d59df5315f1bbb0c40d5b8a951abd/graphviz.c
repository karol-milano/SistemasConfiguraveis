@@ -178,8 +178,8 @@ output_red (state const *s, reductions const *reds, FILE *fout)
 
       bool defaulted = default_reduction && default_reduction == reds->rules[j];
 
-      /* Build the lookahead tokens lists, one for enabled transitions and one
-         for disabled transistions. */
+      /* Build the lookahead tokens lists, one for enabled transitions
+         and one for disabled transitions. */
       bool firstd = true;
       bool firste = true;
       rule_number ruleno = reds->rules[j]->number;
