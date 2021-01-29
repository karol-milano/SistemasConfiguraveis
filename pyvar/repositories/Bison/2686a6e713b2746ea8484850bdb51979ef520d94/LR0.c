@@ -519,7 +519,7 @@ augment_automaton (void)
   register core *statep;
   register shifts *sp;
   register shifts *sp2;
-  register shifts *sp1;
+  register shifts *sp1 = NULL;
 
   sp = first_shift;
 
