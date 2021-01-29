@@ -1,5 +1,5 @@
 /* Grammar reduction for Bison.
-   Copyright 1988, 1989, 2000, 2001  Free Software Foundation, Inc.
+   Copyright (C) 1988, 1989, 2000, 2001, 2002  Free Software Foundation, Inc.
 
    This file is part of Bison, the GNU Compiler Compiler.
 
@@ -26,6 +26,7 @@
    user's parser.  */
 
 #include "system.h"
+#include "quotearg.h"
 #include "getargs.h"
 #include "files.h"
 #include "symtab.h"
@@ -343,7 +344,8 @@ reduce_output (FILE *out)
       int i;
       fprintf (out, "%s\n\n", _("Useless nonterminals:"));
       for (i = 0; i < nuseless_nonterminals; ++i)
-	fprintf (out, "   %s\n", symbols[nsyms + i]->tag);
+	fprintf (out, "   %s\n", quotearg_style (escape_quoting_style,
+						 symbols[nsyms + i]->tag));
       fputs ("\n\n", out);
     }
 
@@ -356,7 +358,8 @@ reduce_output (FILE *out)
 	  if (!b)
 	    fprintf (out, "%s\n\n", _("Terminals which are not used:"));
 	  b = TRUE;
-	  fprintf (out, "   %s\n", symbols[i]->tag);
+	  fprintf (out, "   %s\n", quotearg_style (escape_quoting_style,
+						   symbols[i]->tag));
 	}
     if (b)
       fputs ("\n\n", out);
@@ -370,9 +373,11 @@ reduce_output (FILE *out)
 	{
 	  rule r;
 	  fprintf (out, "#%-4d  ", rules[i].user_number - 1);
-	  fprintf (out, "%s:", rules[i].lhs->tag);
+	  fprintf (out, "%s:", quotearg_style (escape_quoting_style,
+					       rules[i].lhs->tag));
 	  for (r = rules[i].rhs; *r >= 0; r++)
-	    fprintf (out, " %s", symbols[*r]->tag);
+	    fprintf (out, " %s", quotearg_style (escape_quoting_style,
+						 symbols[*r]->tag));
 	  fputs (";\n", out);
 	}
       fputs ("\n\n", out);
@@ -394,7 +399,8 @@ dump_grammar (FILE *out)
   for (i = ntokens; i < nsyms; i++)
     fprintf (out, "%5d  %5d   %5d  %s\n",
 	     i,
-	     symbols[i]->prec, symbols[i]->assoc, symbols[i]->tag);
+	     symbols[i]->prec, symbols[i]->assoc,
+	     quotearg_style (escape_quoting_style, symbols[i]->tag));
   fprintf (out, "\n\n");
   fprintf (out, "Rules\n-----\n\n");
   fprintf (out, "Num (Prec, Assoc, Useful, Ritem Range) Lhs -> Rhs (Ritem range) [Num]\n");
@@ -418,9 +424,11 @@ dump_grammar (FILE *out)
   fprintf (out, "Rules interpreted\n-----------------\n\n");
   for (i = 1; i < nrules + nuseless_productions + 1; i++)
     {
-      fprintf (out, "%-5d  %s :", i, rules[i].lhs->tag);
+      fprintf (out, "%-5d  %s :",
+	       i, quotearg_style (escape_quoting_style, rules[i].lhs->tag));
       for (r = rules[i].rhs; *r >= 0; r++)
-	fprintf (out, " %s", symbols[*r]->tag);
+	fprintf (out, " %s",
+		 quotearg_style (escape_quoting_style, symbols[*r]->tag));
       fputc ('\n', out);
     }
   fprintf (out, "\n\n");
@@ -484,7 +492,7 @@ reduce_grammar (void)
 
   if (!bitset_test (N, start_symbol - ntokens))
     fatal (_("Start symbol %s does not derive any sentence"),
-	   symbols[start_symbol]->tag);
+	   quotearg_style (escape_quoting_style, symbols[start_symbol]->tag));
 
   if (nuseless_productions > 0)
     reduce_grammar_tables ();
