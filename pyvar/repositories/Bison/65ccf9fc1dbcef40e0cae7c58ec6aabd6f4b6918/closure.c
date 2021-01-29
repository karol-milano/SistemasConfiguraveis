@@ -27,7 +27,6 @@
 #include "reader.h"
 #include "closure.h"
 #include "derives.h"
-#include "warshall.h"
 
 /* NITEMSET is the size of the array ITEMSET.  */
 short *itemset;
@@ -104,6 +103,54 @@ print_fderives (void)
     }
   fprintf (stderr, "\n\n");
 }
+
+/*--------------------------------------------------------.
+| Display the MATRIX array of SIZE bitsets of size SIZE.  |
+`--------------------------------------------------------*/
+
+static void
+bitmatrix_print (const char *title, bitsetv matrix)
+{
+  size_t i, j;
+  size_t size = bitset_size (matrix[0]);
+
+  /* Title. */
+  fprintf (stderr, "%s BEGIN\n", title);
+
+  /* Column numbers. */
+  fputs ("   ", stderr);
+  for (i = 0; i < size; ++i)
+    putc (i / 10 ? '0' + i / 10 : ' ', stderr);
+  putc ('\n', stderr);
+  fputs ("   ", stderr);
+  for (i = 0; i < size; ++i)
+    fprintf (stderr, "%d", i % 10);
+  putc ('\n', stderr);
+
+  /* Bar. */
+  fputs ("  .", stderr);
+  for (i = 0; i < size; ++i)
+    putc ('-', stderr);
+  fputs (".\n", stderr);
+
+  /* Contents. */
+  for (i = 0; i < size; ++i)
+    {
+      fprintf (stderr, "%2d|", i);
+      for (j = 0; j < size; ++j)
+	fputs (bitset_test (matrix[i], j) ? "1" : " ", stderr);
+      fputs ("|\n", stderr);
+    }
+
+  /* Bar. */
+  fputs ("  `", stderr);
+  for (i = 0; i < size; ++i)
+    putc ('-', stderr);
+  fputs ("'\n", stderr);
+
+  /* End title. */
+  fprintf (stderr, "%s END\n\n", title);
+}
 
 /*------------------------------------------------------------------.
 | Set FIRSTS to be an NVARS array of NVARS bitsets indicating which |
@@ -131,7 +178,11 @@ set_firsts (void)
 	  bitset_set (FIRSTS (i), symbol - ntokens);
       }
 
-  RTC (firsts);
+  if (trace_flag)
+    bitmatrix_print ("RTC: Input", firsts);
+  bitsetv_reflexive_transitive_closure (firsts);
+  if (trace_flag)
+    bitmatrix_print ("RTC: Output", firsts);
 
   if (trace_flag)
     print_firsts ();
