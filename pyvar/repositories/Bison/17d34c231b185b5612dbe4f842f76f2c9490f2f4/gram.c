@@ -259,12 +259,11 @@ grammar_dump (FILE *out, const char *title)
            "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nritems = %d\n\n",
            ntokens, nvars, nsyms, nrules, nritems);
 
-
-  fprintf (out, "Variables\n---------\n\n");
+  fprintf (out, "Tokens\n------\n\n");
   {
     fprintf (out, "Value  Sprec  Sassoc  Tag\n");
 
-    for (symbol_number i = ntokens; i < nsyms; i++)
+    for (symbol_number i = 0; i < ntokens; i++)
       fprintf (out, "%5d  %5d   %5d  %s\n",
                i,
                symbols[i]->content->prec, symbols[i]->content->assoc,
@@ -272,6 +271,16 @@ grammar_dump (FILE *out, const char *title)
     fprintf (out, "\n\n");
   }
 
+  fprintf (out, "Non terminals\n-------------\n\n");
+  {
+    fprintf (out, "Value  Tag\n");
+
+    for (symbol_number i = ntokens; i < nsyms; i++)
+      fprintf (out, "%5d  %s\n",
+               i, symbols[i]->tag);
+    fprintf (out, "\n\n");
+  }
+
   fprintf (out, "Rules\n-----\n\n");
   {
     fprintf (out,
