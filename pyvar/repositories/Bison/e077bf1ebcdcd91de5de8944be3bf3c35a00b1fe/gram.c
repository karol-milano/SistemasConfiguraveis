@@ -67,7 +67,8 @@ item_print (item_number *item, rule const *previous_rule, FILE *out)
 
   for (item_number *sp = r->rhs; sp < item; sp++)
     fprintf (out, " %s", symbols[*sp]->tag);
-  fputs (" .", out);
+  putc (' ', out);
+  print_dot (out);
   if (0 <= *r->rhs)
     for (item_number *sp = item; 0 <= *sp; ++sp)
       fprintf (out, " %s", symbols[*sp]->tag);
