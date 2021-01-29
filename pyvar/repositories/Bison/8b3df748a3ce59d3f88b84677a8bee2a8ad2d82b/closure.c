@@ -19,6 +19,7 @@
    02111-1307, USA.  */
 
 #include "system.h"
+#include "quotearg.h"
 #include "bitset.h"
 #include "bitsetv.h"
 #include "getargs.h"
@@ -57,7 +58,8 @@ print_closure (const char *title, short *array, size_t size)
       short *rp;
       fprintf (stderr, "  %2d: .", array[i]);
       for (rp = &ritem[array[i]]; *rp >= 0; ++rp)
-	fprintf (stderr, " %s", symbols[*rp]->tag);
+	fprintf (stderr, " %s",
+		 quotearg_style (escape_quoting_style, symbols[*rp]->tag));
       fprintf (stderr, "  (rule %d)\n", -*rp - 1);
     }
   fputs ("\n\n", stderr);
@@ -72,11 +74,14 @@ print_firsts (void)
   fprintf (stderr, "FIRSTS\n");
   for (i = ntokens; i < nsyms; i++)
     {
-      fprintf (stderr, "\t%s firsts\n", symbols[i]->tag);
+      fprintf (stderr, "\t%s firsts\n",
+	       quotearg_style (escape_quoting_style, symbols[i]->tag));
       for (j = 0; j < nvars; j++)
 	if (bitset_test (FIRSTS (i), j))
 	  fprintf (stderr, "\t\t%d (%s)\n",
-		   j + ntokens, symbols[j + ntokens]->tag);
+		   j + ntokens,
+		   quotearg_style (escape_quoting_style,
+				   symbols[j + ntokens]->tag));
     }
   fprintf (stderr, "\n\n");
 }
@@ -90,14 +95,17 @@ print_fderives (void)
   fprintf (stderr, "FDERIVES\n");
   for (i = ntokens; i < nsyms; i++)
     {
-      fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
+      fprintf (stderr, "\t%s derives\n",
+	       quotearg_style (escape_quoting_style, symbols[i]->tag));
       for (j = 0; j < nrules + 1; j++)
 	if (bitset_test (FDERIVES (i), j))
 	  {
 	    short *rhsp;
 	    fprintf (stderr, "\t\t%d:", j - 1);
 	    for (rhsp = rules[j].rhs; *rhsp >= 0; ++rhsp)
-	      fprintf (stderr, " %s", symbols[*rhsp]->tag);
+	      fprintf (stderr, " %s",
+		       quotearg_style (escape_quoting_style,
+				       symbols[*rhsp]->tag));
 	    fputc ('\n', stderr);
 	  }
     }
