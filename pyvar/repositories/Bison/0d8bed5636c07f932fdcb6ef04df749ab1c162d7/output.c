@@ -568,6 +568,7 @@ void
 token_definitions_output (FILE *out)
 {
   int i;
+  int first = 1;
   for (i = 0; i < ntokens; ++i)
     {
       bucket *symbol = symbols[i];
@@ -594,12 +595,13 @@ token_definitions_output (FILE *out)
       if (strchr (symbol->tag, '.') || strchr (symbol->tag, '$'))
 	continue;
 
-      fprintf (out, "# define %s\t%d\n",
-	       symbol->tag, number);
+      fprintf (out, "%s  [[[%s]], [%d]]",
+	       first ? "" : ",\n", symbol->tag, number);
       if (semantic_parser)
 	/* FIXME: This is probably wrong, and should be just as
 	   above. --akim.  */
 	fprintf (out, "# define T%s\t%d\n", symbol->tag, symbol->value);
+      first = 0;
     }
 }
 
@@ -988,9 +990,9 @@ output_skeleton (void)
   guards_output (out);
   fputs ("]])\n\n", out);
 
-  fputs ("m4_define([b4_tokendef], \n[[", out);
+  fputs ("m4_define([b4_tokens], \n[", out);
   token_definitions_output (out);
-  fputs ("]])\n\n", out);
+  fputs ("])\n\n", out);
 
   muscles_m4_output (out);
 
