@@ -410,7 +410,7 @@ look_ahead_tokens_print (FILE *out)
 {
   state_number i;
   int j, k;
-  fprintf (out, "Look-ahead tokens: BEGIN\n");
+  fputs ("Look-ahead tokens: BEGIN\n", out);
   for (i = 0; i < nstates; ++i)
     {
       reductions *reds = states[i]->reductions;
@@ -434,7 +434,7 @@ look_ahead_tokens_print (FILE *out)
 		     reds->rules[j]->number);
 	  };
     }
-  fprintf (out, "Look-ahead tokens: END\n");
+  fputs ("Look-ahead tokens: END\n", out);
 }
 
 void
