@@ -56,7 +56,7 @@ print_core (struct obstack *oout, state *s)
     {
       closure (sitems, snritems);
       sitems = itemset;
-      snritems = nritemset;
+      snritems = nitemset;
     }
 
   obstack_fgrow1 (oout, "%d", s->number);
