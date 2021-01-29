@@ -28,6 +28,7 @@
 #include "system.h"
 #include "getargs.h"
 #include "files.h"
+#include "symtab.h"
 #include "gram.h"
 #include "complain.h"
 #include "reduce.h"
@@ -353,26 +354,13 @@ nonterminals_reduce (void)
 
   /* Shuffle elements of tables indexed by symbol number.  */
   {
-    short *sassoc_sorted = XMALLOC (short, nvars) - ntokens;
-    short *sprec_sorted  = XMALLOC (short, nvars) - ntokens;
-    char **tags_sorted   = XMALLOC (char *, nvars) - ntokens;
+    bucket **symbols_sorted = XMALLOC (bucket *, nvars) - ntokens;
 
     for (i = ntokens; i < nsyms; i++)
-      {
-	n = nontermmap[i];
-	sassoc_sorted[n] = sassoc[i];
-	sprec_sorted[n]  = sprec[i];
-	tags_sorted[n]   = tags[i];
-      }
+      symbols_sorted[nontermmap[i]] = symbols[i];
     for (i = ntokens; i < nsyms; i++)
-      {
-	sassoc[i] = sassoc_sorted[i];
-	sprec[i]  = sprec_sorted[i];
-	tags[i]   = tags_sorted[i];
-      }
-    free (sassoc_sorted + ntokens);
-    free (sprec_sorted + ntokens);
-    free (tags_sorted + ntokens);
+      symbols[i] = symbols_sorted[i];
+    free (symbols_sorted + ntokens);
   }
 
   /* Replace all symbol numbers in valid data structures.  */
@@ -410,7 +398,7 @@ reduce_output (FILE *out)
       int i;
       fprintf (out, "%s\n\n", _("Useless nonterminals:"));
       for (i = 0; i < nuseless_nonterminals; ++i)
-	fprintf (out, "   %s\n", tags[nsyms + i]);
+	fprintf (out, "   %s\n", symbols[nsyms + i]->tag);
       fputs ("\n\n", out);
     }
 
@@ -423,7 +411,7 @@ reduce_output (FILE *out)
 	  if (!b)
 	    fprintf (out, "%s\n\n", _("Terminals which are not used:"));
 	  b = TRUE;
-	  fprintf (out, "   %s\n", tags[i]);
+	  fprintf (out, "   %s\n", symbols[i]->tag);
 	}
     if (b)
       fputs ("\n\n", out);
@@ -438,9 +426,9 @@ reduce_output (FILE *out)
 	  {
 	    rule r;
 	    fprintf (out, "#%-4d  ", i - 1);
-	    fprintf (out, "%s:", tags[rule_table[i].lhs]);
+	    fprintf (out, "%s:", symbols[rule_table[i].lhs]->tag);
 	    for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
-	      fprintf (out, " %s", tags[*r]);
+	      fprintf (out, " %s", symbols[*r]->tag);
 	    fputs (";\n", out);
 	  }
       fputs ("\n\n", out);
@@ -460,7 +448,9 @@ dump_grammar (FILE *out)
   fprintf (out, "Variables\n---------\n\n");
   fprintf (out, "Value  Sprec  Sassoc  Tag\n");
   for (i = ntokens; i < nsyms; i++)
-    fprintf (out, "%5d  %5d   %5d  %s\n", i, sprec[i], sassoc[i], tags[i]);
+    fprintf (out, "%5d  %5d   %5d  %s\n",
+	     i,
+	     symbols[i]->prec, symbols[i]->assoc, symbols[i]->tag);
   fprintf (out, "\n\n");
   fprintf (out, "Rules\n-----\n\n");
   fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
@@ -484,9 +474,9 @@ dump_grammar (FILE *out)
   fprintf (out, "Rules interpreted\n-----------------\n\n");
   for (i = 1; i <= nrules; i++)
     {
-      fprintf (out, "%-5d  %s :", i, tags[rule_table[i].lhs]);
+      fprintf (out, "%-5d  %s :", i, symbols[rule_table[i].lhs]->tag);
       for (r = &ritem[rule_table[i].rhs]; *r >= 0; r++)
-	fprintf (out, " %s", tags[*r]);
+	fprintf (out, " %s", symbols[*r]->tag);
       fputc ('\n', out);
     }
   fprintf (out, "\n\n");
@@ -551,7 +541,7 @@ reduce_grammar (void)
 
   if (!BITISSET (N, start_symbol - ntokens))
     fatal (_("Start symbol %s does not derive any sentence"),
-	   tags[start_symbol]);
+	   symbols[start_symbol]->tag);
 
   reduce_grammar_tables ();
   if (nuseless_nonterminals > 0)
