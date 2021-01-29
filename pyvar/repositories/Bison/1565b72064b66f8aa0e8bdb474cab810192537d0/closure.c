@@ -22,6 +22,7 @@
 #include "quotearg.h"
 #include "bitset.h"
 #include "bitsetv.h"
+#include "bitsetv-print.h"
 #include "getargs.h"
 #include "symtab.h"
 #include "gram.h"
@@ -78,8 +79,7 @@ print_firsts (void)
 	       quotearg_style (escape_quoting_style, symbols[i]->tag));
       for (j = 0; j < nvars; j++)
 	if (bitset_test (FIRSTS (i), j))
-	  fprintf (stderr, "\t\t%d (%s)\n",
-		   j + ntokens,
+	  fprintf (stderr, "\t\t%s\n",
 		   quotearg_style (escape_quoting_style,
 				   symbols[j + ntokens]->tag));
     }
@@ -111,54 +111,6 @@ print_fderives (void)
     }
   fprintf (stderr, "\n\n");
 }
-
-/*--------------------------------------------------------.
-| Display the MATRIX array of SIZE bitsets of size SIZE.  |
-`--------------------------------------------------------*/
-
-static void
-bitmatrix_print (const char *title, bitsetv matrix)
-{
-  size_t i, j;
-  size_t size = bitset_size (matrix[0]);
-
-  /* Title. */
-  fprintf (stderr, "%s BEGIN\n", title);
-
-  /* Column numbers. */
-  fputs ("   ", stderr);
-  for (i = 0; i < size; ++i)
-    putc (i / 10 ? '0' + i / 10 : ' ', stderr);
-  putc ('\n', stderr);
-  fputs ("   ", stderr);
-  for (i = 0; i < size; ++i)
-    fprintf (stderr, "%d", i % 10);
-  putc ('\n', stderr);
-
-  /* Bar. */
-  fputs ("  .", stderr);
-  for (i = 0; i < size; ++i)
-    putc ('-', stderr);
-  fputs (".\n", stderr);
-
-  /* Contents. */
-  for (i = 0; i < size; ++i)
-    {
-      fprintf (stderr, "%2d|", i);
-      for (j = 0; j < size; ++j)
-	fputs (bitset_test (matrix[i], j) ? "1" : " ", stderr);
-      fputs ("|\n", stderr);
-    }
-
-  /* Bar. */
-  fputs ("  `", stderr);
-  for (i = 0; i < size; ++i)
-    putc ('-', stderr);
-  fputs ("'\n", stderr);
-
-  /* End title. */
-  fprintf (stderr, "%s END\n\n", title);
-}
 
 /*------------------------------------------------------------------.
 | Set FIRSTS to be an NVARS array of NVARS bitsets indicating which |
@@ -187,10 +139,10 @@ set_firsts (void)
       }
 
   if (trace_flag)
-    bitmatrix_print ("RTC: Input", firsts);
+    bitsetv_matrix_dump (stderr, "RTC: Firsts Input", firsts);
   bitsetv_reflexive_transitive_closure (firsts);
   if (trace_flag)
-    bitmatrix_print ("RTC: Output", firsts);
+    bitsetv_matrix_dump (stderr, "RTC: Firsts Output", firsts);
 
   if (trace_flag)
     print_firsts ();
@@ -226,6 +178,7 @@ set_fderives (void)
 
   bitsetv_free (firsts);
 }
+
 
 
 void
