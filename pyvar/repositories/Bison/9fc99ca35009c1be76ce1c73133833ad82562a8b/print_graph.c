@@ -55,7 +55,7 @@ print_core (struct obstack *oout, state *s)
       snritems = nitemset;
     }
 
-  obstack_printf (oout, "%d\\n", s->number);
+  obstack_printf (oout, "state %d\\n", s->number);
   for (i = 0; i < snritems; i++)
     {
       item_number *sp;
