@@ -410,7 +410,7 @@ look_ahead_tokens_print (FILE *out)
 {
   state_number i;
   int j, k;
-  fputs ("Look-ahead tokens: BEGIN\n", out);
+  fprintf (out, "Look-ahead tokens: BEGIN\n");
   for (i = 0; i < nstates; ++i)
     {
       reductions *reds = states[i]->reductions;
@@ -434,7 +434,7 @@ look_ahead_tokens_print (FILE *out)
 		     reds->rules[j]->number);
 	  };
     }
-  fputs ("Look-ahead tokens: END\n", out);
+  fprintf (out, "Look-ahead tokens: END\n");
 }
 
 void
