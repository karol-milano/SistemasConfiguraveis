@@ -269,7 +269,6 @@ reduce_grammar_tables (void)
       {
 	length = rule_rhs_length (&rules[r]);
 	nritems -= length + 1;
-	nitems -= length + 1;
       }
   }
 }
@@ -383,8 +382,8 @@ dump_grammar (FILE *out)
 
   fprintf (out, "REDUCED GRAMMAR\n\n");
   fprintf (out,
-	   "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nitems = %d\n\n",
-	   ntokens, nvars, nsyms, nrules, nitems);
+	   "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nritems = %d\n\n",
+	   ntokens, nvars, nsyms, nrules, nritems);
   fprintf (out, "Variables\n---------\n\n");
   fprintf (out, "Value  Sprec  Sassoc  Tag\n");
   for (i = ntokens; i < nsyms; i++)
