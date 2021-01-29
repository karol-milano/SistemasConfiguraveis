@@ -75,7 +75,7 @@ print_firsts (void)
 {
   symbol_number i, j;
 
-  fprintf (stderr, "FIRSTS\n");
+  fputs ("FIRSTS\n", stderr);
   for (i = ntokens; i < nsyms; i++)
     {
       bitset_iterator iter;
@@ -86,7 +86,7 @@ print_firsts (void)
 		   symbols[j + ntokens]->tag);
 	}
     }
-  fprintf (stderr, "\n\n");
+  fputs ("\n\n", stderr);
 }
 
 
@@ -96,7 +96,7 @@ print_fderives (void)
   int i;
   rule_number r;
 
-  fprintf (stderr, "FDERIVES\n");
+  fputs ("FDERIVES\n", stderr);
   for (i = ntokens; i < nsyms; i++)
     {
       bitset_iterator iter;
@@ -107,7 +107,7 @@ print_fderives (void)
 	  rule_rhs_print (&rules[r], stderr);
 	}
     }
-  fprintf (stderr, "\n\n");
+  fputs ("\n\n", stderr);
 }
 
 /*------------------------------------------------------------------.
