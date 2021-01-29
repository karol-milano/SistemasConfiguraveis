@@ -20,6 +20,7 @@
 
 #include "system.h"
 #include "getargs.h"
+#include "symtab.h"
 #include "gram.h"
 #include "reader.h"
 #include "closure.h"
@@ -61,7 +62,7 @@ print_closure (const char *title, short *array, size_t size)
       short *rp;
       fprintf (stderr, "  %2d: .", array[i]);
       for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
-	fprintf (stderr, " %s", tags[*rp]);
+	fprintf (stderr, " %s", symbols[*rp]->tag);
       fprintf (stderr, "  (rule %d)\n", -*rp - 1);
     }
   fputs ("\n\n", stderr);
@@ -76,10 +77,11 @@ print_firsts (void)
   fprintf (stderr, "FIRSTS\n");
   for (i = ntokens; i < nsyms; i++)
     {
-      fprintf (stderr, "\t%s firsts\n", tags[i]);
+      fprintf (stderr, "\t%s firsts\n", symbols[i]->tag);
       for (j = 0; j < nvars; j++)
 	if (BITISSET (FIRSTS (i), j))
-	  fprintf (stderr, "\t\t%d (%s)\n", j + ntokens, tags[j + ntokens]);
+	  fprintf (stderr, "\t\t%d (%s)\n",
+		   j + ntokens, symbols[j + ntokens]->tag);
     }
   fprintf (stderr, "\n\n");
 }
@@ -95,14 +97,14 @@ print_fderives (void)
 
   for (i = ntokens; i < nsyms; i++)
     {
-      fprintf (stderr, "\t%s derives\n", tags[i]);
+      fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
       for (j = 0; j <= nrules; j++)
 	if (BITISSET (FDERIVES (i), j))
 	  {
 	    short *rhsp;
 	    fprintf (stderr, "\t\t%d:", j - 1);
 	    for (rhsp = &ritem[rule_table[j].rhs]; *rhsp >= 0; ++rhsp)
-	      fprintf (stderr, " %s", tags[*rhsp]);
+	      fprintf (stderr, " %s", symbols[*rhsp]->tag);
 	    fputc ('\n', stderr);
 	  }
     }
