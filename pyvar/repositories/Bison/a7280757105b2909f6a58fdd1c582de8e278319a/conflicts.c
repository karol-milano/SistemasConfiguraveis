@@ -104,7 +104,7 @@ log_resolution (rule *r, symbol_number token,
         case shift_resolution:
           obstack_printf (&solved_conflicts_obstack,
                           " (%s < %s)",
-                          r->prec->tag,
+                          r->prec->symbol->tag,
                           symbols[token]->tag);
           break;
 
@@ -112,7 +112,7 @@ log_resolution (rule *r, symbol_number token,
           obstack_printf (&solved_conflicts_obstack,
                           " (%s < %s)",
                           symbols[token]->tag,
-                          r->prec->tag);
+                          r->prec->symbol->tag);
           break;
 
         case left_resolution:
@@ -176,7 +176,7 @@ log_resolution (rule *r, symbol_number token,
         case shift_resolution:
           obstack_printf (&solved_conflicts_xml_obstack,
                           "%s &lt; %s",
-                          xml_escape_n (0, r->prec->tag),
+                          xml_escape_n (0, r->prec->symbol->tag),
                           xml_escape_n (1, symbols[token]->tag));
           break;
 
@@ -184,7 +184,7 @@ log_resolution (rule *r, symbol_number token,
           obstack_printf (&solved_conflicts_xml_obstack,
                           "%s &lt; %s",
                           xml_escape_n (0, symbols[token]->tag),
-                          xml_escape_n (1, r->prec->tag));
+                          xml_escape_n (1, r->prec->symbol->tag));
           break;
 
         case left_resolution:
@@ -269,18 +269,18 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
   for (i = 0; i < ntokens; i++)
     if (bitset_test (lookahead_tokens, i)
         && bitset_test (lookahead_set, i)
-        && symbols[i]->prec)
+        && symbols[i]->content->prec)
       {
         /* Shift-reduce conflict occurs for token number i
            and it has a precedence.
            The precedence of shifting is that of token i.  */
-        if (symbols[i]->prec < redprec)
+        if (symbols[i]->content->prec < redprec)
           {
             register_precedence (redrule->prec->number, i);
             log_resolution (redrule, i, reduce_resolution);
             flush_shift (s, i);
           }
-        else if (symbols[i]->prec > redprec)
+        else if (symbols[i]->content->prec > redprec)
           {
             register_precedence (i, redrule->prec->number);
             log_resolution (redrule, i, shift_resolution);
@@ -294,7 +294,7 @@ resolve_sr_conflict (state *s, int ruleno, symbol **errors, int *nerrs)
              For right associativity, keep only the shift.
              For nonassociativity, keep neither.  */
 
-          switch (symbols[i]->assoc)
+          switch (symbols[i]->content->assoc)
             {
             case undef_assoc:
               abort ();
