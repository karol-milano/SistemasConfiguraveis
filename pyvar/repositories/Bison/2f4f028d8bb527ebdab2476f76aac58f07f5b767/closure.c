@@ -75,7 +75,7 @@ print_firsts (void)
 {
   symbol_number i, j;
 
-  fputs ("FIRSTS\n", stderr);
+  fprintf (stderr, "FIRSTS\n");
   for (i = ntokens; i < nsyms; i++)
     {
       bitset_iterator iter;
@@ -86,7 +86,7 @@ print_firsts (void)
 		   symbols[j + ntokens]->tag);
 	}
     }
-  fputs ("\n\n", stderr);
+  fprintf (stderr, "\n\n");
 }
 
 
@@ -96,7 +96,7 @@ print_fderives (void)
   int i;
   rule_number r;
 
-  fputs ("FDERIVES\n", stderr);
+  fprintf (stderr, "FDERIVES\n");
   for (i = ntokens; i < nsyms; i++)
     {
       bitset_iterator iter;
@@ -107,7 +107,7 @@ print_fderives (void)
 	  rule_rhs_print (&rules[r], stderr);
 	}
     }
-  fputs ("\n\n", stderr);
+  fprintf (stderr, "\n\n");
 }
 
 /*------------------------------------------------------------------.
