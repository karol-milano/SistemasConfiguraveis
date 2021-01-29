@@ -21,8 +21,9 @@
 
 #include "system.h"
 #include "quotearg.h"
-#include "gram.h"
 #include "symtab.h"
+#include "gram.h"
+#include "reduce.h"
 #include "reader.h"
 
 /* comments for these variables are in gram.h  */
@@ -102,3 +103,61 @@ ritem_longest_rhs (void)
 
   return max;
 }
+
+
+/*-------------------.
+| Dump the grammar.  |
+`-------------------*/
+
+void
+grammar_dump (FILE *out, const char *title)
+{
+  int i;
+  item_number_t *r;
+
+  fprintf (out, "%s\n\n", title);
+  fprintf (out,
+	   "ntokens = %d, nvars = %d, nsyms = %d, nrules = %d, nritems = %d\n\n",
+	   ntokens, nvars, nsyms, nrules, nritems);
+  fprintf (out, "Variables\n---------\n\n");
+  fprintf (out, "Value  Sprec  Sassoc  Tag\n");
+  for (i = ntokens; i < nsyms; i++)
+    fprintf (out, "%5d  %5d   %5d  %s\n",
+	     i,
+	     symbols[i]->prec, symbols[i]->assoc,
+	     quotearg_style (escape_quoting_style, symbols[i]->tag));
+  fprintf (out, "\n\n");
+  fprintf (out, "Rules\n-----\n\n");
+  fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
+  for (i = 1; i < nrules + nuseless_productions + 1; i++)
+    {
+      int rhs_count = 0;
+      /* Find the last RHS index in ritems. */
+      for (r = rules[i].rhs; *r >= 0; ++r)
+	++rhs_count;
+      fprintf (out, "%3d (%2d, %2d, %2d, %2d-%2d)   %2d ->",
+	       i - 1,
+	       rules[i].prec ? rules[i].prec->prec : 0,
+	       rules[i].prec ? rules[i].prec->assoc : 0,
+	       rules[i].useful,
+	       rules[i].rhs - ritem,
+	       rules[i].rhs - ritem + rhs_count - 1,
+	       rules[i].lhs->number);
+      /* Dumped the RHS. */
+      for (r = rules[i].rhs; *r >= 0; r++)
+	fprintf (out, " %3d", *r);
+      fprintf (out, "  [%d]\n", -(*r) - 1);
+    }
+  fprintf (out, "\n\n");
+  fprintf (out, "Rules interpreted\n-----------------\n\n");
+  for (i = 1; i < nrules + nuseless_productions + 1; i++)
+    {
+      fprintf (out, "%-5d  %s :",
+	       i, quotearg_style (escape_quoting_style, rules[i].lhs->tag));
+      for (r = rules[i].rhs; *r >= 0; r++)
+	fprintf (out, " %s",
+		 quotearg_style (escape_quoting_style, symbols[*r]->tag));
+      fputc ('\n', out);
+    }
+  fprintf (out, "\n\n");
+}
