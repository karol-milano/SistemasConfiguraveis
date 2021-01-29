@@ -32,10 +32,8 @@
 #include "alloc.h"
 #include "complain.h"
 #include "reduce.h"
-
-extern char **tags;		/* reader.c */
-static int statisticsflag;	/* XXXXXXX */
-extern int fixed_outfiles;
+#include "reader.h"
+#include "getargs.h"
 
 typedef unsigned *BSet;
 typedef short *rule;
@@ -545,8 +543,8 @@ reduce_grammar (void)
       dump_grammar ();
     }
 #endif
-  statisticsflag = FALSE;	/* someday getopts should handle this */
-  if (statisticsflag == TRUE)
+
+  if (statisticsflag)
     fprintf (stderr, _("reduced %s defines %d terminal%s, %d nonterminal%s\
 , and %d production%s.\n"),
 	     infile,
