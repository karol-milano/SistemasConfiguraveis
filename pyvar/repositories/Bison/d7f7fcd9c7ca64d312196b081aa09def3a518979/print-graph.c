@@ -84,7 +84,7 @@ print_core (struct obstack *oout, state *s)
           obstack_1grow (oout, ' ');
         }
 
-      obstack_1grow (oout, '.');
+      obstack_sgrow (oout, "•");
 
       if (0 <= *r->rhs)
         for (item_number const *sp = sp1; 0 <= *sp; ++sp)
