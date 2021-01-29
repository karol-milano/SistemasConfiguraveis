@@ -21,6 +21,7 @@
 
 #include "system.h"
 #include "getargs.h"
+#include "symtab.h"
 #include "types.h"
 #include "reader.h"
 #include "gram.h"
@@ -38,13 +39,13 @@ print_derives (void)
   for (i = ntokens; i < nsyms; i++)
     {
       short *sp;
-      fprintf (stderr, "\t%s derives\n", tags[i]);
+      fprintf (stderr, "\t%s derives\n", symbols[i]->tag);
       for (sp = derives[i]; *sp > 0; sp++)
 	{
 	  short *rhsp;
 	  fprintf (stderr, "\t\t%d:", *sp);
 	  for (rhsp = &ritem[rule_table[*sp].rhs]; *rhsp >= 0; ++rhsp)
-	    fprintf (stderr, " %s", tags[*rhsp]);
+	    fprintf (stderr, " %s", symbols[*rhsp]->tag);
 	  fprintf (stderr, " (rule %d)\n", -*rhsp - 1);
 	}
     }
